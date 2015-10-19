#/!usr/bin/python
# Filename : mousegame.py

from pygame import *

ballpic = image.load('ball.png')

done = False

ballx = 0	# Ball position variables
bally = 0
ballxmove = 1
ballymove = 1

init()		# Start pygame
screen = display.set_mode((640, 480)	# Our window size
display.set_caption('Ball Game')	# Window title

while done == False:
	screen.fill(0)			# Fill screen with black (color 0)
	screen.blit(ballpic, (ballx, bally))	# Draw ball
	display.update()

	time.delay(1)		# Slow it down

	ballx = ballx + ballxmove	# Update ballposition
	bally = bally + ballymove	# Update y pos

	if ballx > 600:		# ball reached screen edge?
		ballxmove = -1
	if ballx < 0:
		ballxmove = 1
	if bally > 440:
		ballymove = -1
	if bally < 0:
		ballymove = 1

	for e in event.get():	# Check if ESC key is hit
		if e.type == KEYUP:
			if e.key = KEY_ESCAPE:
				done = True








