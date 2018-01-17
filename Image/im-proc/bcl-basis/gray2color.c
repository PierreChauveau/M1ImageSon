#include <stdlib.h>
#include <stdio.h>

#include <bcl.h>


void
process(char* ims0, char* ims1, char* ims2, char* imd){
  pnm imageR = pnm_load(ims0);
  pnm imageG = pnm_load(ims1);
  pnm imageB = pnm_load(ims2);
  
  unsigned int width = pnm_get_width(imageR);
  unsigned int height = pnm_get_height(imageR);
  
  pnm imageres = pnm_new(width, height, PnmRawPpm);
  unsigned short val;
  
  for(unsigned int x = 0; x < width; x++){
    for(unsigned int y = 0; y < height; y++){
      val = pnm_get_component(imageR, x, y, 0);
      pnm_set_component(imageres, x, y, 0, val);

      val = pnm_get_component(imageG, x, y, 0);
      pnm_set_component(imageres, x, y, 1, val);

      val = pnm_get_component(imageB, x, y, 0);
      pnm_set_component(imageres, x, y, 2, val);
      
    }
  }

  
  pnm_save(imageres, PnmRawPpm, imd);
  printf("Down\n");
}



void 
usage (char *s)
{
  fprintf(stderr,"Usage: %s %s", s, "<ims0> <ims1> <ims2> <imd>\n");
  exit(EXIT_FAILURE);
}

#define PARAM 4
int 
main(int argc, char *argv[])
{
  if (argc != PARAM+1) usage(argv[0]);

  process(argv[1], argv[2], argv[3], argv[4]);
  
  return EXIT_SUCCESS;
}
