// Centralisation de notes et de remarques :

image* empty_image(int w, int h) {
    image* img = (image*)malloc(sizeof(image));  // Alloue de la mémoire pour la structure
    img->width = w;
    img->height = h;
    img->data = (pixel*)malloc(w * h * sizeof(pixel));  // Alloue la mémoire pour les pixels

    // Remplir tous les pixels avec du bleu
    for (int i = 0; i < w * h; i++) {
        img->data[i].r = 0;
        img->data[i].g = 0;
        img->data[i].b = 255;
    }

    return img;  // Retourne le pointeur vers la structure allouée
}

/////////////////////////////////////////////////////////////////////////////////////
