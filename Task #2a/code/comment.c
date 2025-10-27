#include"comment.h"

static char*copystr2(const char*s){
	//to create a new memory location for the string and assign the pointer to it
	size_t n=strlen(s)+1;
	char*p=malloc(n);
	if(!p)exit(1);
	memcpy(p,s,n);
	return p;
}

Comment*create_comment(char*username,char*content){
	//to create a new comment
	Comment*c=malloc(sizeof(Comment));
	if(!c){
		printf("memory allocation failed");
		exit(1);
	}
	
	c->username=copystr2(username);
	c->content=copystr2(content);
	c->replies=NULL;
	c->prev=NULL;
	c->next=NULL;
	return c;
}

