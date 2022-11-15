import pygame
from pygame.draw import *
from random import randint
pygame.init()

FPS = 60 #число новых кругов в секунду
number_of_balls=4 #число обычных шаров
points=0 #счетчик очков
base_points_multiplier=100 #базовый множитель начисления очков
x_res,y_res=1920/1.25, 1080/1.25
res=[x_res,y_res]
sp_mult=0.01 #множитель скорости
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

class ball:
    '''хранит координаты шаров, пересчитывает их при переходе на следующий кадр, pos=[x,y] и spd=[Vx,Vy], где V - изменение координаты за кадр'''
    def __init__(self):
        self.r=randint(y_res//100,y_res//8) #радиус
        self.pos=[randint(self.r, int(x_res-self.r)),randint(self.r, int(y_res-self.r))] #координата
        self.spd=[randint(-int(x_res*sp_mult), int(x_res*sp_mult)),randint(-int(y_res*sp_mult), int(y_res*sp_mult))] # скррости
        self.color=COLORS[randint(0,len(COLORS)-1)] # цвет
    def new_frame(self): #рисуем новый кадр
        pygame.draw.circle(screen, self.color,self.pos,self.r)
        for i in range(2):
            self.pos[i]+=self.spd[i]
            if(self.pos[i]<self.r or self.pos[i]>res[i]-self.r):
                self.spd[i]=-self.spd[i]
                self.pos[i]+=self.spd[i]


def click_check(event, balls,add):
    '''увеличивает счетчик попаданий и выводит его в случае попадания точки в круг, возвращает счетчик
    на вход принимает event щелчка, массив кругов, множитель начисления быллов, начисляемые баллы обартно пропорциональны радиусу окружности'''
    global points
    for i in range(len(balls)):
        x=balls[i].pos[0]
        y=balls[i].pos[1]
        if(((event.pos[0]-x)**2+(event.pos[1]-y)**2)<balls[i].r**2):
            points += add/balls[i].r

def create_balls(n):
    '''создает шары, n - количество'''
    balls=[]
    for i in range(n):
        balls.append(ball())
    return balls
    
def draw_balls(balls):
    '''рисует шары из массива'''
    for i in range(len(balls)):
        balls[i].new_frame()

def gravitation(balls,a):
    '''меняет скорость шаров из переданного массива, а - ускорение'''
    for i in range(len(balls)):
        balls[i].spd[1]+=a

balls=create_balls(number_of_balls)
gravity_balls=create_balls(int(number_of_balls/2))
pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True
        elif event.type == pygame.MOUSEBUTTONDOWN:
            click_check(event,balls,base_points_multiplier)
            click_check(event,gravity_balls,2*base_points_multiplier)
            print(points)
    draw_balls(balls) #рисуем шары
    gravitation(gravity_balls,2)
    draw_balls(gravity_balls)
    pygame.display.update()
    screen.fill(BLACK)

pygame.quit()