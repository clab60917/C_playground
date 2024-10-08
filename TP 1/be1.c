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
  unsigned char r, g, b; // UNSIGNED => ça peut contenir que des valeurs positives
} pixel;

typedef struct image
{
  int width;
  int height;
  struct pixel *data;
} image;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  QUESTION 1
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
  img->data = (pixel *)malloc(w * h * sizeof(pixel)); // ATTENTION ici pixel * != * pixel    // sert à convertir le type d'une variable (ou d'un pointeur) en un autre type. => "Cette mémoire que j'ai allouée va être utilisée pour stocker des éléments de type pixel. ON STOCKE UN TABLEAU DE PIXELS"

  if (img->data == NULL)
  {
    free(img);
    return NULL;
  }
  // Là on remplit les pixels de couleur avec du bleu uniquement
  // Il faut initialiser chaque pixel en bleu => donc on passe par les pointeurs
  for (int i = 0; i < w * h; i++)
  { // ici la boucle parcours tous les pixels de l'image // i est l'index qui parcours chaque pixel de l'image img->data. Chaque pixel est stocké séparément dans le tableau img->data. DOnc doit le faire pour tous.
    img->data[i].r = 0;
    img->data[i].g = 0;
    img->data[i].b = 255;
  }
  return img;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// QUESTION 2

// Écrit un entier (4 octets) dans un fichier binaire. Un entier => 32 bits
void fwrite_int(int data, FILE *f)
{
  fputc((data >> 0) & 0xFF, f);
  fputc((data >> 8) & 0xFF, f);  // Deuxième octet. => on decale de 8 bits à droite. OxFF sert de masque pour cacher les autres bits. 1 octet = 8 bits donc logique
  fputc((data >> 16) & 0xFF, f); // Troisième octet
  fputc((data >> 24) & 0xFF, f); // Octet de poids fort
}

/* Écrit un octet dans un fichier binaire */
void fwrite_byte(unsigned char data, FILE *f)
{
  fputc(data, f);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// QUESTION 3
/// @param filename
/// @param img
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
  pixel *pix;      // pix c'est le pointeur qui va aller faire tous les pixels dans le tableau
  pix = img->data; // pointe vers le début du tableau de pixels

  for (int x = 0; x < img->width; x++)
  { // on se definit les axes
    for (int y = 0; y < img->height; y++)
    {
      fwrite_byte(pix->b, fd);
      fwrite_byte(pix->g, fd);
      fwrite_byte(pix->r, fd);
      pix++; // Passe au pixel d'après
    }
  }
  fclose(fd);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// QUESTION 4
/* Colore le pixel aux coordonnées (x,y) avec la couleur color. */
void draw_pixel1(int x, int y, int color, image *img)
{
  if (x >= 0 && x < img->width && y >= 0 && y < img->height) // verif si le pixel est dans les bornes de l'image données
  {
    int index = (y * img->width) + x; // on calcule ou est situé le pixel dans l'image
    img->data[index].r = (color >> 16) & 0xFF;
    img->data[index].g = (color >> 8) & 0xFF;
    img->data[index].b = color & 0xFF;
  }
  else
  {
    printf("On écrit pas en dehors oh eh");
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// QUESTION 5
void draw_pixel2(int x, int y, int color, image *img)
{

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// QUESTION 6
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
  // Definition de la taille de l'image
  int x;
  int y;
  int width = 100;
  int height = 100;
  // là ici on cree une image vide
  image *img = empty_image(width, height);
  if (img != NULL) // si l'image a bien été créée
  {
    for (x = 0; x < img->width; x++)
    {
      for (y = 0; y < img->height; y++)
      {
        draw_pixel1(50, 50, 0x00FF00, img);
        draw_pixel1(25, 25, 0x00FF00, img);
        // draw_pixel1(2000, 2000, 0x00FF00, img);
      }
    }
  }
  write_image("output1.bmp", img);

  free(img->data);
  free(img);

  return 0;
}
