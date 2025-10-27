#include"reply.h"

static char*copystr3(const char*s){
	//to create a new memory location for the string and assign the pointer to it
	size_t n=strlen(s)+1;
	char*p=malloc(n);
	if(!p)exit(1);
	memcpy(p,s,n);
	return p;
}

Reply*create_reply(char*username,char*content){
	//to create a new reply
	Reply*r=malloc(sizeof(Reply));
	if(!r){
		printf("memory allocation failed");
		exit(1);
	}
	
	r->username=copystr3(username);
	r->content=copystr3(content);
	r->prev=NULL;
	r->next=NULL;
	return r;
}

