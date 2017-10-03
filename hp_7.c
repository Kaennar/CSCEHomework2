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
  int i = -1;
  pid_t pid = 0; 
  int len = strlen(str);
  while (i < len){
    if (pid == 0){
      pid = fork();
      i += 1;       
    }else{
      break;
    }
  }
  // We get a double at the end so we kill that one :)
  if (pid != 0 && i == len){
    kill(pid,SIGTERM);  
  }
  // Wait for the children to finish
  while(wait(NULL) > 0);
  write(1,&str[i],1);   
  if (i == 0){
    write(1,"\n",1);
  }
  kill(pid,SIGTERM);  

}

