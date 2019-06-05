import pygame

def draw_text(window, font, text, x, y, color = (255, 255, 0)):
    label = font.render(text, True, color)
    window.blit(label, (x, y))

def draw_interface(window, font, teams_name, width, height):
    pygame.draw.line(window, 0xFFFFFF, (400, 0), (400, 1080))
    draw_text(window, font, f"Width:  {width}", 100, 50)
    draw_text(window, font, f"Height: {height}", 100, 150)
    draw_text(window, font, f" Team Names:", 100, 250)
    i = 250
    for team in teams_name:
        draw_text(window, font, team, 280, i)
        i += 30
    pygame.draw.line(window, 0xFFFFFF, (1520, 0), (1520, 1080))
    draw_text(window, font, "Clients:", 1600, 50)

def draw_client_interface(window, font, clients):
    y = 250
    for client in clients:
        client.draw_interface(window, font, y)
        y += 50

def draw_client(window, width, height, clients):
    TILE_SIZE = (1080 - 20 - 20 - 100) / height
    for client in clients:
        x = client.x * TILE_SIZE + 1920 / 2 - width / 2 * TILE_SIZE + TILE_SIZE * 0.2
        y = client.y * TILE_SIZE + 1080 / 2 - height / 2 * TILE_SIZE + TILE_SIZE * 0.2
        pygame.draw.rect(window, client.color, pygame.Rect(x, y, TILE_SIZE * 0.6, TILE_SIZE * 0.6))

def draw_map(window, width, height):
    TILE_SIZE = (1080 - 20 - 20 - 100) / height
    for i in range(width):
        for j in range(height):
            x = i * TILE_SIZE + 1920 / 2 - width / 2 * TILE_SIZE
            y = j * TILE_SIZE + 1080 / 2 - height / 2 * TILE_SIZE
            pygame.draw.rect(window, 0x808080, pygame.Rect(x, y, TILE_SIZE, TILE_SIZE), 4)
