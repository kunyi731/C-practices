#include <stdio.h>


static FILE *open_file ( char *file, char *mode )
{
  FILE *fp = fopen ( file, mode );

  if ( fp == NULL ) {
    perror ( "Unable to open file" );
    exit ( EXIT_FAILURE );
  }

  return fp;
}

int main (int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s filename\n", argv[0]);
  }
  else
  {
    FILE *fp;
    char temp;
    int byte_count = 0;

    //argv[1] is the file to open, test whether it exists
    fp = open_file(argv[1], "r");
    
    do
    {
      fread(&temp, 1, 1, fp); 
    } while (temp)

    printf("File size is %d bytes\n", byte_count);
  }
}
