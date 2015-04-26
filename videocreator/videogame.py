#with help from http://trevorappleton.blogspot.co.uk/2013/07/python-game-of-life.html

import os
import pygame, sys
from pygame.locals import *
import pygame
import random
import numpy


#Number of frames per second
FPS = 2

CELLSIZE = 10

with open("../build/src/output.txt", 'r') as file:
    [ITER, CELLHEIGHT, CELLWIDTH]= [int(x) for x in file.readline().split()]
    array = [[int(x) for x in line.split()] for line in file]

def getnewgrid(i):
    gridDict = {}
    for x in range (CELLHEIGHT):
        for y in range (CELLWIDTH):
            gridDict[x,y] = array[x+i*CELLHEIGHT][y]
    print(gridDict[0,0],gridDict[1,1])
    return gridDict

WINDOWWIDTH = CELLSIZE*CELLWIDTH
WINDOWHEIGHT = CELLSIZE*CELLHEIGHT


# set up the colours
BLACK =    (0,  0,  0)
WHITE =    (255,255,255)
DARKGRAY = (40, 40, 40)
DARKGRAY = (40, 40, 40)
PINK = (255,182,193)

#Draws the grid lines
def drawGrid():
    for x in range(0, WINDOWWIDTH, CELLSIZE): # draw vertical lines
        pygame.draw.line(DISPLAYSURF, DARKGRAY, (x,0),(x,WINDOWHEIGHT))
    for y in range (0, WINDOWHEIGHT, CELLSIZE): # draw horizontal lines
        pygame.draw.line(DISPLAYSURF, DARKGRAY, (0,y), (WINDOWWIDTH, y))

def blankGrid():
    gridDict = {}
    for y in range (CELLHEIGHT):
        for x in range (CELLWIDTH):
            gridDict[x,y] = 0
    return gridDict
def startingGridRandom(lifeDict):
    for item in lifeDict:
        lifeDict[item] = random.randint(0,1)
    return lifeDict
def colourGrid(item, lifeDict):
    x=item[0]
    y=item[1]
    y = y * CELLSIZE # translates array into grid size
    x = x * CELLSIZE # translates array into grid size
    if lifeDict[item] ==0:
        pygame.draw.rect(DISPLAYSURF, BLACK, (x, y, CELLSIZE, CELLSIZE))
    if lifeDict[item] == 1:
        pygame.draw.rect(DISPLAYSURF, PINK, (x, y, CELLSIZE, CELLSIZE))
    return None

tab=[]
for l in range(ITER):
    tab.append("./frames/screenshot"+str(l)+".bmp")

def main():
    pygame.init()
    pygame.display.Info()
    global DISPLAYSURF
    FPSCLOCK = pygame.time.Clock()
    DISPLAYSURF = pygame.display.set_mode((WINDOWWIDTH,WINDOWHEIGHT), RESIZABLE)#size of window
    pygame.display.set_caption('Conway\'s Game of Life')#name of window
    DISPLAYSURF.fill(WHITE) #fills the screen white
    lifeDict=getnewgrid(0)
    for item in lifeDict:
        colourGrid(item, lifeDict)
    drawGrid()
    pygame.display.update()
    pygame.image.save(DISPLAYSURF,tab[0])
#main game loop
    for i in range(ITER-1):
        pygame.display.update()
        lifeDict = getnewgrid(i+1)
        for item in lifeDict:
            colourGrid(item, lifeDict)
        drawGrid()
        pygame.display.update()
        pygame.image.save(DISPLAYSURF,tab[i+1])
        FPSCLOCK.tick(FPS)
    pygame.display.flip()


if __name__=='__main__':
    main()







