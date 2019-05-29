import re

from network_utils import send, recv

""" Return (width, height) """
def command_msz(sockfd):
    send(sockfd, "msz")
    tmp = recv(sockfd)
    return tuple(map(int, re.search(r"^msz ([1-9]\d*) ([1-9]\d*)$", tmp).groups()))

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
