#include <stdio.h>
#include "todo_handler.h"

int 
main (void)
{
  int in;
  do
    {
      printf 
	("select:\n\t1:print tasks\n\t2:add task\n\t3:delete task\n\t0:exit\n");
      scanf ("%d", &in);
      clear_input_buffer ();
      
      switch (in)
	{
	case 1:
	  print_tasks ();
	  break;
	case 2:
	  add_task ();	  
	  break;
	case 3:
	  delete_task ();
	  break;
	case 0:
	  return 0;
	default:
	  printf ("please choose a valid action\n");
	  break;
	}
    }
  while (in != 0);

  return 0;
}
