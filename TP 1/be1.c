// Allocation dynamique => permet de faire des images de taille w * h. Pas oublier que avec RGB c'est w * h * 3.
// image => c'est la structure d'une image, avec sa taille, couleur et tout
// img => c'est le pointeur qui indique où dans la mémoire est stockée l'image

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI (acos(-1))

typedef struct pixel
{
  unsigned char r, g, b;
} pixel;

typedef struct image
{
  int width;
  int height;
  struct pixel *data;
} image;

////////////////////////////////////////////////////////////////// QUESTION 1
image *empty_image(int w, int h)
{
  image *img = (image *)malloc(sizeof(image));
  if (img == NULL)
  {
    printf("Allocation de l'image à échoué");
    return NULL;
  }
  img->height = h; // Ici c'est pour dire "img" accède au membre "height" de la structure "image"
  img->width = w;
  img->data = (image *)malloc(w * h * sizeof(pixel));
}

/* Écrit un entier (4 octets) dans un fichier binaire */
void fwrite_int(int data, FILE *out)
{
}

/* Écrit un octet dans un fichier binaire */
void fwrite_byte(unsigned char data, FILE *out)
{
}

void write_image(char *filename, image *img)
{
  FILE *fd = fopen(filename, "wb");

  fwrite_byte('B', fd); // BMP magic number
  fwrite_byte('M', fd);
  fwrite_int(14 + 40 + 3 * img->width * img->height, fd); // taille du fichier (en octets)
  fwrite_int(0, fd);                                      // application qui a créé l'image
  fwrite_int(14 + 40, fd);                                // taille des en-têtes

  fwrite_int(40, fd);             // taill de cet en-tête
  fwrite_int(img->width, fd);     // largeur de l'image
  fwrite_int(img->height, fd);    // hauteur de l'image
  fwrite_int(1 + (24 << 16), fd); // plans et bits pas pixel
  fwrite_int(0, fd);              // compression
  fwrite_int(0, fd);              // taille de l'image (redondant, 0 fonctionne bien)
  fwrite_int(0, fd);              // résolution horizontale
  fwrite_int(0, fd);              // résolution verticale
  fwrite_int(0, fd);              // nombre de couleurs dans la palette (inutilisé)
  fwrite_int(0, fd);              // nombre de couleurs importantes (inutilisé)

  // TODO : écrire chacun des pixels de l'image
  fclose(fd);
}

/* Colore le pixel aux coordonnées (x,y) avec la couleur color. */
void draw_pixel(int x, int y, int color, image *img)
{
}

/* Remplit le rectangle dont le coin en bas à gauche est (x1,y1) et le coin en
   haut à droite est (x2,y2) avec la couleur bgcolor. */
void draw_rectangle(int x1, int y1, int x2, int y2, int bgcolor, image *img)
{
}

/* Remplit le disque de centre (xc,yc) et de rayon radius avec la couleur
   color. */
void draw_circle(int xc, int yc, int color, int radius, image *img)
{
}

int max(int a, int b)
{
  return (a < b) ? b : a;
}

/* Dessine une ligne du point (xfrom,yfrom) au point (xto,yto), de couleur color
   et d'épaisseur width. Ignorez l'épaisseur dans un premier temps. */
void draw_line(int xfrom, int yfrom, int xto, int yto, int color, int width, image *img)
{
}

/* Dessine un arc de cercle de centre (xc,yc), de rayon radius, depuis l'angle
   anglefrom jusqu'à angleto, de couleur color et d'épaisseur width. Ignorez
   l'épaisseur dans un premier temps. */
void draw_arc(int xc, int yc, int color, int radius, int anglefrom, int angleto, int width, image *img)
{
}

struct face_description
{
  int skin_color; // la couleur du visage

  int eye_bg_color; // la couleur du fond des yeux
  int eye_fg_color; // la couleur de la pupille

  int eyebrow_color; // la couleur des sourcils
  int eyebrow_width; // l'épaisseur des sourcils

  int nose_color; // la couleur du nez
  int nose_size;  // la taille du nez

  int mouth_color; // la couleur de la bouche
  int mouth_width; // l'épaisseur de la bouche

  int mask;              // présence du masque (0 ou 1)
  int mask_bg_color;     // la couleur du masque
  int mask_border_color; // la couleur de la bordure du masque
  int mask_link_color;   // la couleur des liens du masque
};

/* Dessine un visage. Ignorez le paramètre face_description pour le moment. */
void draw_face(int x, int y, struct face_description *f, image *img)
{

  // visage
  draw_circle(x, y, 0xffff00, 40, img);

  // oeil droit
  draw_circle(x + 20, y + 10, 0xffffff, 10, img);
  draw_arc(x + 20, y + 10, 0x000000, 10, 0, 360, 1, img);
  draw_circle(x + 20, y + 5, 0x0000ff, 3, img);

  // oeil gauche
  draw_circle(x - 20, y + 10, 0xffffff, 10, img);
  draw_arc(x - 20, y + 10, 0x000000, 10, 0, 360, 1, img);
  draw_circle(x - 20, y + 5, 0x0000ff, 3, img);

  // sourcils
  draw_arc(x + 20, y + 10, 0x000000, 15, 45, 135, 3, img);
  draw_arc(x - 20, y + 10, 0x000000, 15, 45, 135, 3, img);

  // nez
  draw_circle(x, y - 5, 0x00fff0, 7, img);

  // bouche
  draw_arc(x, y - 10, 0xff0000, 20, 215, 325, 3, img);

  // bords du masque
  draw_rectangle(x - 21, y - 26, x + 21, y - 4, 0x000000, img);
  // masque
  draw_rectangle(x - 20, y - 25, x + 20, y - 5, 0xffffff, img);
  // liens du masque
  draw_line(x - 20, y - 5, x - 38, y + 5, 0x000000, 1, img);
  draw_line(x - 20, y - 25, x - 35, y - 15, 0x000000, 1, img);
  draw_line(x + 20, y - 5, x + 38, y + 5, 0x000000, 1, img);
  draw_line(x + 20, y - 25, x + 35, y - 15, 0x000000, 1, img);
}

/* Retourne une description de visage par défaut. */
struct face_description *default_face()
{
  return NULL;
}

struct face_description *read_face(char *file)
{
  return NULL;
}

int main()
{

  printf("Hello !\n");

  return 0;
}
