import re

from network_utils import send, recv

""" Return (width, height) """
def command_msz(sockfd):
    send(sockfd, "msz")
    tmp = recv(sockfd)
    return tuple(map(int, re.search(r"^msz (\d+) (\d+)$", tmp).groups()))

""" Return ["team_name", "team_name", ...] """
def command_tna(sockfd):
    send(sockfd, "tna")
    teams = []
    for team in recv(sockfd).split('\n'):
        tmp = re.search(r"^tna (\S+)$", team)
        if tmp == None:
            break
        token = tmp.groups()
        teams.append(token[0])
    return teams

""" Return (player_number, x, y, dir) """
def command_ppo(input):
    input = ' '.join(input)
    if input is None or input == ["ko\n"]:
        return
    return tuple(map(int, re.search(r"^ppo (\d+) (\d+) (\d+) (1|2|3|4)$", input).groups()))

""" Return (food, stones1, stones2, ..., stones6) """
def command_pin(input):
    input = ' '.join(input)
    if input is None or input == ["ko\n"]:
        return
    return tuple(map(int, re.search(r"^pin (\d+) (\d+) (\d+) (\d+) (\d+) (\d+) (\d+) (\d+)$", input).groups()))
