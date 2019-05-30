import re

from draw import draw_text

""" Represent a AI client """
class Client:

    """ Constructor """
    def __init__(self, input):
        self.id = int(re.search(r"^#([1-9]+\d*)$", input[1]).groups()[0])
        self.pos_x = int(input[2])
        self.pos_y = int(input[3])
        self.direction = int(input[4])
        self.level = int(input[5])
        self.team_name = input[6]

    def draw_interface(self, window, font, y):
        text = f"#{self.id} {self.pos_x} {self.pos_y} {self.direction} {self.level} {self.team_name}"
        draw_text(window, font, text, 1700, y)
