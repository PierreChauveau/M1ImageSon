#include <stdlib.h>
#include <stdio.h>

#include <bcl.h>

void
process(unsigned int i, unsigned int j, unsigned int rows, unsigned int cols, char* imagesrc, char* imagedst){
  pnm imageini = pnm_load(imagesrc);
  pnm imageres = pnm_new(cols, rows, PnmRawPpm);
  unsigned short val;
  
  for(unsigned int x = 0; x < rows; x++){
    for(unsigned int y = 0; y < cols; y++){
      for(unsigned int k = 0; k < 3; k++){
	val = pnm_get_component(imageini, i+x, j+y, k);
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
  fprintf(stderr,"Usage: %s %s", s, "<i> <j> <rows> <cols> <ims> <imd>\n");
  exit(EXIT_FAILURE);
}

#define PARAM 6
int 
main(int argc, char *argv[])
{
  if (argc != PARAM+1) usage(argv[0]);

  unsigned int i = atoi(argv[1]);
  unsigned int j = atoi(argv[2]);
  unsigned int rows = atoi(argv[3]);
  unsigned int cols = atoi(argv[4]);

  process(i, j, rows, cols, argv[5], argv[6]);
  
  return EXIT_SUCCESS;
}
