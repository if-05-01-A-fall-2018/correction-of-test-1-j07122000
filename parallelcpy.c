#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char * arguments[256];
char * pointer;

int main (int argc, char const * argv[]){
  char input[256];
  char * save;							
  // gets(input);
  sprintf(input, "ls && df && ps && pwd");				//veränderung
  char*div = "&& ";

  pointer = strtok(input, div);							//veränderung
  while(pointer != NULL){		

    printf("============%s===========\n", pointer);
															//rm ~ 10 line
    arguments[0] = pointer;									//veränderung
    arguments[1] = NULL;									//veränderung
    int pid = fork();
    if(pid == 0)
    {
      int return_value = execvp(arguments[0], arguments);		//delete ifs 
    }
    else{
      int status;
      waitpid(-1, &status, 0);
    }
    pointer = strtok(0, div);						//veränderung
  }
  printf("done");
  return 0;
}
