/*
Author : Arjun S R
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
permute_string(char* starter,char* remain)
{
  size_t r_len=( (remain == NULL)?0: strlen(remain));
  //  size_t s_len=strlen(starter);
  char* n_starter=NULL;
  char* n_remain=NULL;
  size_t n_starts=0;
  size_t cur_alloc_size=0;
  
  if ( r_len != 0){
    //  fprintf(stdout,"STARTER : %s\nREMAIN : %s\n",starter,remain);
    for(int i=0;i<r_len;i++){
      n_starter=(char*)malloc(cur_alloc_size=(starter == NULL)? 2: (strlen(starter)) + 1 );
      bzero(n_starter,cur_alloc_size+1);
      if (starter){
	strncpy(n_starter,starter,cur_alloc_size);
      }
      strncat(n_starter, remain+i,1);
      
      n_remain=(char*)malloc(r_len);
      bzero(n_remain,r_len);
      strncpy(n_remain, remain+i+1 ,r_len -i-1);
      strncat(n_remain,remain, i );
      
      // fprintf(stdout,"starter:%s remain:%s\n",n_starter,n_remain); 
      permute_string(n_starter,n_remain);
      n_starts++;
      
      free(n_starter);
      free(n_remain);
    }
  }
  else {
    fprintf(stdout,"%s\n",starter);
  }
  //fprintf(stdout,"Made %d starters\n",n_starts);
  
}

int
main(int argc,char* argv[])
{
  if ( argc > 10 ){
    fprintf(stderr,"%s <string-to-be-permuted>[MAX 10 ARGS]\n",argv[0]);
    exit(EXIT_FAILURE);
  }
  for(int i=1;i<argc;i++){
    permute_string(NULL,argv[i]);
  }
  return 0;
}

