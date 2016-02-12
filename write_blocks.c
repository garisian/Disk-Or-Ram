#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct record {
     int uid1;
     int uid2;
  } Record;

/* String splitting function from http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c */
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

 
int main(int argc, char* argv[]) {

   // Check to see if there are enough arguments for a fileName and a BufferSize.
   // If there is, assign them to their variables respectively
   if(argc < 3)
   {
       printf("Indicate an input filename and block size\n\n");
       return 0;
   }
   char * fileName = argv[1]; 
   char * bufferSize = argv[2];
   int linesPerBlock = atoi(bufferSize)/sizeof(Record);

   // This is where the program will store the line it reads 
   char line[256];

   //printf("%lu\n",sizeof(Record));

   // The following are the variables that indicate which csv file is going to be read from and 
   // the name of the file descriptor that opens it
   char * resultFile = "records.dat";
   FILE * readingDescriptor;
   FILE * writingDescriptor;

   // flag to check if file is written to. Used for edge case for last line in file
   int wroteFile = 0;

   // Checks if the file being read/written to can be open. If not return an error message.
   if (!(readingDescriptor= fopen ( fileName , "r" )))	
   {
	printf ("Could not open file \"%s\" for reading \n", fileName);
	return (-1);
   }
   if(!(writingDescriptor = fopen( resultFile , "w" )))
   {
	printf ("Could not open file \"%s\" for reading \n", resultFile);
	return (-1);       
   }
   
   Record * buffer = (Record *) calloc(linesPerBlock, sizeof(Record));
 
   
   int counter = linesPerBlock; //4
   int linesInBuffer = 0;
   while(fgets(line, sizeof(line), readingDescriptor) != NULL)
   {
       if(counter == 0)
       {
           fwrite(buffer, sizeof(Record), linesPerBlock, writingDescriptor);
  	   memset(buffer,'\0',sizeof(buffer));
           counter = linesPerBlock;
           linesInBuffer = 0;
       }
       char** tokens;
       tokens = str_split(line, ',');
       Record r;
       // If "line" is not an empty string
       if(tokens)
       {
           // Here we make a new record and associate the integers to its relative variables
           r.uid1 = atoi(*tokens);
           r.uid2 = atoi(*(tokens + 1));
       }
       buffer[linesInBuffer] = r;
       linesInBuffer++;
       counter--;
   }
   
   fwrite(buffer, sizeof(Record), linesPerBlock, writingDescriptor);
   memset(buffer,'\0',sizeof(buffer));
   counter = linesPerBlock;
 /*
 
        fgets(line, sizeof(line), readingDescriptor);
        char** tokens;
        tokens = str_split(line, ',');
        Record r;
        // If "line" is not an empty string
        if(tokens)
        {
            // Here we make a new record and associate the integers to its relative variables
            r.uid1 = atoi(*tokens);
            r.uid2 = atoi(*(tokens + 1));
        }
        buffer[i] = r;
	//printf("%d___%d\n", buffer[i].uid1, buffer[i].uid2);


*/

//*****************READING FROM BINARY. WE NEED. NO DELETE*************
/*
	//fflush(writingDescriptor);
	fclose(writingDescriptor);
	fclose(readingDescriptor);
	memset(buffer,'\0',sizeof(buffer));

        int result;
	FILE * read_dat = fopen("records.dat", "rb");
	while( result = fread(buffer,sizeof(Record),linesPerBlock, read_dat))
        {
		int ii;
		for(ii = 0;ii<linesPerBlock;ii++)
		{
		  printf("%d GHGHGHGH %d\n",buffer[ii].uid1, buffer[ii].uid2);

		}
        }

	
*/
 	
	memset(buffer,'\0',sizeof(buffer));

/*
   while (fgets(line, sizeof(line), readingDescriptor)) {
        
        // Since we know the line is in either "__,__" or "" format, we can split the 
        // elements using the subfunction str_split to manipulate the numbers
        char** tokens;
        tokens = str_split(line, ',');
        Record r;
        // If "line" is not an empty string
        if(tokens)
        {
            // Here we make a new record and associate the integers to its relative variables
            r.uid1 = atoi(*tokens);
            r.uid2 = atoi(*tokens + 1);
            printf("%d___%d\n",r.uid1, r.uid2);
        }
      
   }*/
}











