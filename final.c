#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
// typedef struct Books {
//    char  title[50];
//    char  author[50];
//    char  subject[100];
//    int   book_id;
// } Book;

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
   if(argc < 2)
   {
       printf("No file name was entered\n\n");
       return 0;
   }
   char const* const fileName = argv[1]; /* should check that argc > 1 */
   FILE* file = fopen(fileName, "r"); /* should check the result */
   char line[256];

   while (fgets(line, sizeof(line), file)) {
     /* note that fgets don't strip the terminating \n, checking its
        presence would allow to handle lines longer that sizeof(line) */
    //printf("%s", line); 

    char** tokens;

    tokens = str_split(line, ',');

    Record r;

    if (tokens)
    {
        //r = (Record *) malloc(sizeof(Record));
        r.uid1 = atoi(*tokens);
        r.uid2 = atoi(*tokens + 1);

        //printf("%d %d\n", r.uid1, r.uid2);

        int i;
        for (i = 0; *(tokens + i); i++)
        {
            //printf("id=[%s]\n", *(tokens + i));
            free(*(tokens + i));
        }
        //printf("\n");
        free(tokens);
    }

   }

   fclose(file);

   return 0;

}
