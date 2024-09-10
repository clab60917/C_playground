// Allocation dynamique => permet de faire des images de taille w * h. Pas oublier que avec RGB c'est w * h * 3.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

typedef struct image
{
    unsigned int width;
    unsigned int height;
    pixel *data;
} image;

image *empty_image(int w, int h)
{

    image *img = (image *)malloc(sizeof(image));

    img->width = w;
    img->height = h;

    img->data = (pixel *)malloc(w * h * sizeof(pixel));

    for (int i = 0; i < w * h; i++)
    {
        img->data[i].r = 0;   // Rouge = 0
        img->data[i].g = 0;   // Vert = 0
        img->data[i].b = 255; // Bleu = 255
    }

    return img;
}
