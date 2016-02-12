#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "structures.h"
#include "utils.h" 

int main()
{
  FILE *file_stream;
  char *line, buffer[1024];
  int successful_open = open_csv(file_stream,"g_plusAnonymized.csv");
  if(successful_open == -1)
  {
    printf("\nTerminating program due to csv error\n");
    exit(1);
  }
  int counter=1;
  
 FILE  *file_stream2 = fopen("g_plusAnonymized.csv","r");

 /* line = fgets(buffer,sizeof(buffer),file_stream2);
  printf(line); 
*/
  struct Record_list list_of_records;
  while((line=fgets(buffer,sizeof(1),file_stream2))!=NULL)
  {
      struct Record current_item;

      /*current_item.uid1 = first;
      current_item.uin2 = second;
      list_of_records.next;*/
    
	
  }

  printf("Hello world\n");
  return 0;
}
