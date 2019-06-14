import re
import random

from draw import draw_text
from network_utils import send
import pygame

def random_color():
    return pygame.Color(random.randint(0, 0xFF), random.randint(0, 0xFF), random.randint(0, 0xFF))

""" Represent a AI client """
class Client:

    """ Constructor """
    def __init__(self, input):
        self.id = int(re.search(r"^#(\d+)$", input[1]).groups()[0])
        self.x = int(input[2])
        self.y = int(input[3])
        self.direction = int(input[4])
        self.level = int(input[5])
        self.team_name = input[6]
        self.color = random_color()

    def draw_interface(self, window, font, y):
        text = f"#{self.id} {self.x} {self.y} {self.direction} {self.level} {self.team_name}"
        draw_text(window, font, text, 1700, y, self.color)

    def update(self, x, y, direction):
        self.x = x
        self.y = y
        self.direction = direction

    def request_position(self, sockfd):
        send(sockfd, f"ppo {self.id}")
