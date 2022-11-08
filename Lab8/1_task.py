import pygame
from pygame.draw import *

pygame.init()

FPS = 30
screen = pygame.display.set_mode((500, 500))
pygame.Surface.fill(screen, (255,255,255))
circle(screen,(255,255,0), (250,250),200)
rect(screen, (0, 0, 0), (125, 300, 250, 30))
circle(screen,(255,0,0), (160,160),45)
circle(screen,(255,0,0), (340,160),35)
circle(screen,(0,0,0), (160,160),20)
circle(screen,(0,0,0), (340,160),20)
polygon(screen, (0, 0, 0), [(200,130), (200+1*10,130-3*10),
                               (200-1*150+10,130-1/3*150-30), (200-1*150,130-1/3*150)])
polygon(screen, (0, 0, 0), [(500-200,130), (500-(200+1*10),(130-3*10)),
                               (500-(200-1*150+10),(130-1/3*150-30)), (500-(200-1*150),(130-1/3*150))])
pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True

pygame.quit()