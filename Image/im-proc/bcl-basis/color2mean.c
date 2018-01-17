#include <stdlib.h>
#include <stdio.h>

#include <bcl.h>


void
process(char* ims, char* imd){
  pnm imageini = pnm_load(ims);
  
  unsigned int width = pnm_get_width(imageini);
  unsigned int height = pnm_get_height(imageini);
  
  pnm imageres = pnm_new(width, height, PnmRawPpm);
  
  unsigned short val;
  unsigned short val0;
  unsigned short val1;
  unsigned short val2;
   
  for(unsigned int x = 0; x < width; x++){
    for(unsigned int y = 0; y < height; y++){
      val0 = pnm_get_component(imageini, x, y, 0);
      val1 = pnm_get_component(imageini, x, y, 1);
      val2 = pnm_get_component(imageini, x, y, 2);
      val = (val0 + val1 + val2)/3;
      pnm_set_component(imageres, x, y, 0, val);
      pnm_set_component(imageres, x, y, 1, val);
      pnm_set_component(imageres, x, y, 2, val);
    }
  }

  
  pnm_save(imageres, PnmRawPpm, imd);
  printf("Down\n");
}



void 
usage (char *s)
{
  fprintf(stderr,"Usage: %s %s", s, "<ims> <imd>\n");
  exit(EXIT_FAILURE);
}

#define PARAM 2
int 
main(int argc, char *argv[])
{
  if (argc != PARAM+1) usage(argv[0]);

  process(argv[1], argv[2]);
  
  return EXIT_SUCCESS;
}
