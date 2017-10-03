// Title :: String Inverter
// Author :: Nicholas Hemstreet
//
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#define STD_OUT 1

int string_invert();
void print_reverse(int i, char* str);
int main(){
  // At somepoint there will get opt crap here
  
  string_invert();
}

void delay(int milliseconds){
  clock_t start_time = clock();
  while (clock() < start_time + milliseconds);
}
int string_invert(){
  printf("Please Enter A Word (<100 char)to be reversed:: ");
  char str[100];
  scanf("%s",&str);
  printf("\n"); 
  // Invert the string
  print_reverse(0,str);
  
}

void print_reverse(int i, char* str){
  pid_t pid = fork();
  if (pid == 0 && i < strlen(str)){
    // Recurse
    print_reverse(i+1,str);
    while (wait(NULL) > 0);
    write(1,&str[i],1);
    if (i == 0) {
      write(1,"\n",1);
      kill(pid,SIGTERM);
      return;
    }
    // Wait for our children to die like the devils they are
  }else if (pid == 0 ){
    kill(pid,SIGTERM);
  }else if (i >= strlen(str)){
    kill(pid,SIGTERM);
  }else{
    return;
  }
}

