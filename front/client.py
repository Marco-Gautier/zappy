import re
import random

from draw import draw_text
import pygame

def random_color():
    return pygame.Color(random.randint(0, 0xFF), random.randint(0, 0xFF), random.randint(0, 0xFF))

def hex_to_rgb(hex):
    hex = str(hex)
    hex = hex.lstrip('#')
    hlen = len(hex)
    print(hex)
    tmp = tuple(int(hex[i:i+int(hlen/3)], 16) for i in range(0, hlen, int(hlen/3)))
    print(tmp)
    return tmp

""" Represent a AI client """
class Client:

    """ Constructor """
    def __init__(self, input):
        self.id = int(re.search(r"^#([1-9]+\d*)$", input[1]).groups()[0])
        self.x = int(input[2])
        self.y = int(input[3])
        self.direction = int(input[4])
        self.level = int(input[5])
        self.team_name = input[6]
        self.color = random_color()
        # print(pygame.Color.normalize(self.color))

    def draw_interface(self, window, font, y):
        text = f"#{self.id} {self.x} {self.y} {self.direction} {self.level} {self.team_name}"
        draw_text(window, font, text, 1700, y, self.color)
