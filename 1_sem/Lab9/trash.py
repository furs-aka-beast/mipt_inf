import pygame
pygame.init()
font=pygame.font.Font(None, 52)
screen = pygame.display.set_mode((500, 500))
def write (string):
    text2 = font.render(string, True, (255,255,255))
 
    screen.blit(text2, (10, 50))
write("pivo")
pygame.display.update()
 
while 1:
    for i in pygame.event.get():
        if i.type == pygame.QUIT:
            sys.exit()