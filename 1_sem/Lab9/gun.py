import math
from random import choice
from random import randint

import pygame


FPS = 30

RED = 0xFF0000
BLUE = 0x0000FF
YELLOW = 0xFFC91F
GREEN = 0x00FF00
MAGENTA = 0xFF03B8
CYAN = 0x00FFCC
BLACK = (0, 0, 0)
WHITE = 0xFFFFFF
GREY = 0x7D7D7D
GAME_COLORS = [RED, BLUE, YELLOW, GREEN, MAGENTA, CYAN]

WIDTH = 800
HEIGHT = 600
g=1
k=0.7 #трение

class Ball:
    def __init__(self, screen: pygame.Surface, x=40, y=450):
        """ Конструктор класса ball

        Args:
        x - начальное положение мяча по горизонтали
        y - начальное положение мяча по вертикали
        """
        self.screen = screen
        self.x = x
        self.y = y
        self.r = 10
        self.vx = 0
        self.vy = 0
        self.color = choice(GAME_COLORS)
        self.live = 30

    def move(self):
        """Переместить мяч по прошествии единицы времени.

        Метод описывает перемещение мяча за один кадр перерисовки. То есть, обновляет значения
        self.x и self.y с учетом скоростей self.vx и self.vy, силы гравитации, действующей на мяч,
        и стен по краям окна (размер окна 800х600).
        """
        if(self.x>WIDTH):
            self.vx=-self.vx*k
            self.vy=self.vy*k
            self.x+=self.vx*(1-k)
        if(self.y>(HEIGHT-10)):
            self.vy=-self.vy*k
            self.vx=self.vx*k
            self.y-=self.vy*(1-k)
        self.x += self.vx
        self.y -= self.vy
        self.vy -=g

    def draw(self):
        pygame.draw.circle(
            self.screen,
            self.color,
            (self.x, self.y),
            self.r
        )

    def hittest(self, obj):
        """Функция проверяет сталкивалкивается ли данный обьект с целью, описываемой в обьекте obj.

        Args:
            obj: Обьект, с которым проверяется столкновение.
        Returns:
            Возвращает True в случае столкновения мяча и цели. В противном случае возвращает False.
        """
        if (((self.x-obj.x)**2+(self.y-obj.y)**2)<=(self.r+obj.r)**2):
            return True
        else: return False


class Gun:
    def __init__(self, screen):
        self.screen = screen
        self.f2_power = 10
        self.f2_on = 0
        self.an = 1
        self.x=20
        self.y=450
        self.color = GREY

    def fire2_start(self, event):
        self.f2_on = 1

    def fire2_end(self, event):
        """Выстрел мячом.

        Происходит при отпускании кнопки мыши.
        Начальные значения компонент скорости мяча vx и vy зависят от положения мыши.
        """
        global balls, bullet
        bullet += 1
        new_ball = Ball(self.screen)
        new_ball.r = 15
        self.an = math.atan2((event.pos[1]-new_ball.y), (event.pos[0]-new_ball.x))
        new_ball.vx = self.f2_power * math.cos(self.an)
        new_ball.vy = - self.f2_power * math.sin(self.an)
        balls.append(new_ball)
        self.f2_on = 0
        self.f2_power = 10

    def targetting(self, event):
        """Прицеливание. Зависит от положения мыши."""
        if (event and (event.pos[0]-20)!=0):
            self.an = math.atan((event.pos[1]-450) / (event.pos[0]-20))
        if self.f2_on:
            self.color = RED
        else:
            self.color = GREY

    def draw(self):
        pygame.draw.line(screen, self.color, (self.x,self.y), (self.x+self.f2_power * math.cos(self.an),self.y+ self.f2_power * math.sin(self.an)), width=6)

    def power_up(self):
        if self.f2_on:
            if self.f2_power < 100:
                self.f2_power += 1
            self.color = RED
        else:
            self.color = GREY


class Target:
    def __init__(self):
        self.points = 0
        self.live = 1
        self.x = randint(600, 780)
        self.y = randint(300, 550)
        self.r = randint(10, 50)
        self.vx = randint(-5, 5)
        self.vy = randint(-5, 5)
        self.color = choice(GAME_COLORS)

    def move(self):
        """Переместить мишень по прошествии единицы времени.

        Метод описывает перемещение мяча за один кадр перерисовки. То есть, обновляет значения
        self.x и self.y с учетом скоростей self.vx и self.vy, силы гравитации, действующей на мяч,
        и стен по краям окна (размер окна 800х600).
        """
        if(self.x>WIDTH or self.x<0):
            self.vx=-self.vx
            self.vy=self.vy
            self.x+=self.vx
        if(self.y>(HEIGHT-10) or self.y<0):
            self.vy=-self.vy
            self.vx=self.vx
            self.y-=self.vy
        self.x += self.vx
        self.y -= self.vy


    def hit(self, points=1):
        """Попадание шарика в цель."""
        self.points += points

    def draw(self):
        pygame.draw.circle(screen, BLACK, (self.x,self.y), self.r+1)
        pygame.draw.circle(screen, self.color, (self.x,self.y), self.r)

    def new_target(self):
        self.live = 1
        self.x = randint(600, 780)
        self.y = randint(300, 550)
        self.r = randint(10, 50)
        self.color = choice(GAME_COLORS)


def write (string: str,x: int, y: int):
    text2 = font.render(string, True, BLACK)
 
    screen.blit(text2, (x, y))

pygame.init()
font=pygame.font.Font(None, 40)
screen = pygame.display.set_mode((WIDTH, HEIGHT))
bullet = 0
balls = []

clock = pygame.time.Clock()
gun = Gun(screen)
target1 = Target()
target2 = Target()
finished = False

while not finished:
    screen.fill(WHITE)
    gun.draw()
    target1.draw()
    target2.draw()
    target1.move()
    target2.move()
    for b in balls:
        b.draw()
    write(str(target1.points+target2.points),10,10)
    pygame.display.update()

    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True
        elif event.type == pygame.MOUSEBUTTONDOWN:
            gun.fire2_start(event)
        elif event.type == pygame.MOUSEBUTTONUP:
            gun.fire2_end(event)
        elif event.type == pygame.MOUSEMOTION:
            gun.targetting(event)

    for b in balls:
        b.move()
        for target in [target1,target2]:
            if b.hittest(target):
                target.hit()
                for i in range(FPS):
                    screen.fill(WHITE)
                    gun.draw()
                    target1.draw()
                    target2.draw()
                    target1.move()
                    target2.move()
                    for b in balls:
                        b.move()
                        b.draw()
                    write("Вы уничтожили цель за "+ str(bullet)+" выстрелов", 100,HEIGHT/2)
                    write(str(target.points),10,10)
                    pygame.display.update()
                    for event in pygame.event.get():
                        if event.type == pygame.QUIT:
                            finished = True
                        elif event.type == pygame.MOUSEMOTION:
                            gun.targetting(event)
                    clock.tick(FPS)
                target.new_target()
                bullet=0
    gun.power_up()

pygame.quit()
