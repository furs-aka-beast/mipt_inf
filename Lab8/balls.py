import pygame
from pygame.draw import *
from random import randint
pygame.init()

FPS = 1 #число новых кругов в секунду
number_of_balls=1
points=0
x_res,y_res=1200,700
screen = pygame.display.set_mode((x_res,y_res))
'''создаем массив цветов шарика в формате pygame.color'''
RED = (255, 0, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)
GREEN = (0, 255, 0)
MAGENTA = (255, 0, 255)
CYAN = (0, 255, 255)
BLACK = (0, 0, 0)
COLORS = [RED, BLUE, YELLOW, GREEN, MAGENTA, CYAN]

def click(event ,x,y,r,points):
    '''увеличивает счетчик попаданий и выводит его в случае попадания точки в круг, возвращает счетчик
    на вход принимает event щелчка и характеристики круга в формате :коорд х, коорд у, радиус, а также текущее число попаданий'''
    if(((event.pos[0]-x)**2+(event.pos[1]-y)**2)<r**2):
        points += 1
        print(points)
    return points


    

def new_ball():
    '''рисует новый круг cо случайными координатом цертра(в пределах окна) и случайным радиусом, случайного цыета'''
    x = randint(0, x_res)
    y = randint(0, y_res)
    r = randint(10, 100)
    color = COLORS[randint(0, 5)]
    circle(screen, color, (x, y), r)
    return (x,y,r)

pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True
        elif event.type == pygame.MOUSEBUTTONDOWN:
            points=click(event,x,y,r,points)
    (x,y,r)=new_ball() #рисуем новый шар и сохранием его координаты
    pygame.display.update()
    screen.fill(BLACK)

pygame.quit()