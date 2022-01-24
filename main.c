#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

/**
 * Creates checkerboard.png file
 * 
 * @param width width of image
 * @param height height of image
 * @param chan channels per pixel
 */
void checkerboard(int width, int height, int chan){
    //vars
    int arrLen = width*height*chan;
    unsigned char* image = (unsigned char*) malloc(arrLen*sizeof(int));
    int alternator = 1;

    //loop for every pixel
    for(int i = 0; i < width*height; i++){
        //convert index to actual index of pixel in array
        int pix = i*chan;

        //print correct pixel based on alternator
        if (alternator)
        {
            //place red pixel
            image[pix] = 255;
            image[pix+1] = 0;
            image[pix+2] = 0;
        } else {
            //place blue pixel
            image[pix] = 0;
            image[pix+1] = 0;
            image[pix+2] = 255;
        }

        //swap alternator every 64 pixels, ignore swap every 64 rows
        if((i+1) % 64 == 0 && (i+1) % (width*64) != 0){
            alternator = 1 - alternator;
        }
    }

    //write checkerboard image
    stbi_write_png("checkerboard.png", width, height, chan, image, width*chan);

    //free memory image is stored in
    free(image);

    return;
}

/**
 * Creates gradient.png file
 * 
 * @param width width of image
 * @param height height of image
 * @param chan channels per pixel
 */
void gradient(int width, int height, int chan){
    //vars
    int arrLen = width*height*chan;
    unsigned char* image = (unsigned char*) malloc(arrLen*sizeof(int));
    int blue = 128;

    //loop for every row
    for(int y = 0; y < width; y++){
        //loop for every column
        for(int x = 0; x < height; x++){
            //find color of each pix
            int red = x/2;
            int green = y/2;

            //find location of pix in image array
            int pix = (x + (width * y)) * 3;

            //print pixes to array
            image[pix] = red;
            image[pix+1] = green;
            image[pix+2] = blue;
       }
    }

    //write gradient image
    stbi_write_png("gradient.png", width, height, chan, image, width*chan);

    //free memory image is stored in
    free(image);

    return;
}

int main(int argc, const char* argv[]){
    //call functions to print images
    checkerboard(512, 512, 3);    
    gradient(512, 512, 3);

    return 0;
}