ray1: main.c stb_image_write.h
	gcc -g -Wall -std=gnu99 -o ray1 main.c -lm

.PHONY: clean
clean:
	rm -f ray1 checkerboard.png diff.png gradient.png