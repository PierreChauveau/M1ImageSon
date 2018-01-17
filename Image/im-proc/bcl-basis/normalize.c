#include <stdlib.h>
#include <stdio.h>

#include <bcl.h>

float maxF(unsigned short *a, unsigned int size){
  unsigned short max = a[0];
  for(unsigned int i = 1; i < size; i++)
    if(a[i] > max) max = a[i];
  return (float)max;
}

float minF(unsigned short *a, unsigned int size){
  unsigned short min = a[0];
  for(unsigned int i = 1; i < size; i++)
    if(a[i] < min) min = a[i];
  return (float)min;
}


void
process(unsigned short min, unsigned short max, char* ims, char* imd){
  pnm imageini = pnm_load(ims);
  unsigned int width = pnm_get_width(imageini);
  unsigned int height = pnm_get_height(imageini);
  pnm imageres = pnm_new(width, height, PnmRawPpm);

  
  unsigned short *r = (unsigned short *) malloc(width*height*sizeof(unsigned short));
  unsigned short *g = (unsigned short *) malloc(width*height*sizeof(unsigned short));
  unsigned short *b = (unsigned short *) malloc(width*height*sizeof(unsigned short));
  pnm_get_channel(imageini, r, 0);
  pnm_get_channel(imageini, g, 1);
  pnm_get_channel(imageini, b, 2);
  float minR = minF(r, width+height);
  float maxR = maxF(r, width+height);
  float minG = minF(g, width+height);
  float maxG = maxF(g, width+height);
  float minB = minF(b, width+height);
  float maxB = maxF(b, width+height);
  
  float val0, val1, val2, norm0, norm1, norm2;
    
  for(unsigned int x = 0; x < width; x++){
    for(unsigned int y = 0; y < height; y++){
      val0 = (float)pnm_get_component(imageini, x, y, 0);
      val1 = (float)pnm_get_component(imageini, x, y, 1);
      val2 = (float)pnm_get_component(imageini, x, y, 2);
      
      norm0 = ((max-min)/(maxR-minR))*val0 + (min*maxR-max*minR) / (maxR-minR);
      norm1 = ((max-min)/(maxG-minG))*val1 + (min*maxG-max*minG) / (maxG-minG);
      norm2 = ((max-min)/(maxB-minB))*val2 + (min*maxB-max*minB) / (maxB-minB);
      
      pnm_set_component(imageres, x, y, 0, (unsigned short)norm0);
      pnm_set_component(imageres, x, y, 1, (unsigned short)norm1);
      pnm_set_component(imageres, x, y, 2, (unsigned short)norm2);
    }
  }

  
  pnm_save(imageres, PnmRawPpm, imd);
  printf("Down\n");
}



void 
usage (char *s)
{
  fprintf(stderr,"Usage: %s %s", s, "<min> <max> <ims> <imd>\n");
  exit(EXIT_FAILURE);
}

#define PARAM 4
int 
main(int argc, char *argv[])
{
  if (argc != PARAM+1) usage(argv[0]);

  unsigned short min = atoi(argv[1]);
  unsigned short max = atoi(argv[2]);
  
  process(min, max, argv[3], argv[4]);
  
  return EXIT_SUCCESS;
}
