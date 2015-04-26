This is a Python program that reads the output file from the main program and output a video. This program uses PyGame. 

The program saves each "frame" of the video. To download the video to your computer use ffmpeg.

Create a directory frames (in the videocreator directory) :

$mkdir frames

Uncomment the line in the corresponding file in the python file.

Go in the ffmpeg folder and run:

$./ffmpeg -framerate 2 -i '[Your-path-to-the-project]/videocreator/frames/screenshot%d.bmp' gameoflife.mp4
