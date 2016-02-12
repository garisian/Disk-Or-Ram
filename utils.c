#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"


int open_csv(FILE *file_stream, char *file_name)
{
  file_stream = fopen(file_name,"r");
  if(file_stream == NULL)
  {
    printf("\nFailed to open .csv file\n");
    return -1;
  }
  return 0;
} 
