#include <stdlib.h>
#include <stdio.h>

#include <bcl.h>

#define nbchannels 3

void
process(unsigned short num, char* imagesrc, char* imagedst){
  pnm imageini = pnm_load(imagesrc);
  unsigned int width = pnm_get_width(imageini);
  unsigned int height = pnm_get_height(imageini);
  pnm imageres = pnm_new(width, height, PnmRawPpm);
  unsigned short val;
  
  for(unsigned int x = 0; x < width; x++){
    for(unsigned int y = 0; y < height; y++){
      val = pnm_get_component(imageini, x, y, num);
      for(int k = 0; k < nbchannels; k++){
	pnm_set_component(imageres, x, y, k, val);
      }
    }
  }

  
  pnm_save(imageres, PnmRawPpm, imagedst);
  printf("Down\n");
}



void 
usage (char *s)
{
  fprintf(stderr,"Usage: %s %s", s, "<num> <ims> <imd>\n");
  exit(EXIT_FAILURE);
}

#define PARAM 3
int 
main(int argc, char *argv[])
{
  if (argc != PARAM+1) usage(argv[0]);

  unsigned short num = atoi(argv[1]);

  process(num, argv[2], argv[3]);
  
  return EXIT_SUCCESS;
}
