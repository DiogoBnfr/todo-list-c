#include <stdio.h>
#define DEFAULT_FILE_PATH "todoist.txt"

void
clear_input_buffer ()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void
add_task ()
{ 
  FILE *fp;
  fp = fopen (DEFAULT_FILE_PATH, "a");

  if (!fp) 
    {
      printf ("File opening/creation failed\n");
      return;
    }

  printf ("New task: ");
  char buffer[256];
  fflush (stdin);
  fgets (buffer, 256, stdin);

  int fputs_status = fputs (buffer, fp);
  if (fputs_status == EOF)
    {
      perror("fputs ()");
    }

  fclose (fp);
}

void
delete_task ()
{
  FILE *fp, *temp;
  fp = fopen (DEFAULT_FILE_PATH, "r");
  temp = fopen ("temp.txt", "w");

  int target_line;
  printf ("insert the number of the task you want to delete: ");
  scanf ("%d", &target_line);

  char ch;
  int current_line = 1;
  while ((ch = getc (fp)) != EOF) {
    if (current_line != target_line)
      {
	fputc (ch, temp);
      }
    if (ch == '\n')
      {
	++current_line;
      }
  }

  fclose (fp);
  fclose (temp);

  remove (DEFAULT_FILE_PATH);
  rename ("temp.txt", DEFAULT_FILE_PATH);
}

void
print_tasks () 
{ 
  FILE *fp;
  fp = fopen (DEFAULT_FILE_PATH, "r");
  
  if (!fp)
    {
      perror ("failed to open file");
      return;
    }

  char buffer[256];
  int count = 0;
  while (fgets (buffer, 256, fp))
    {
      printf ("%i: %s", ++count, buffer);
    }

  fclose (fp);
}
