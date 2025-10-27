#include"post.h"

static char*copystr(const char*s){
	//to create a new memory location for the string and assign the pointer to it
	size_t n=strlen(s)+1;
	char*p=malloc(n);
	if(!p)exit(1);
	memcpy(p,s,n);
	return p;
}

Post*create_post(char*username,char*caption){
	//to create a new post
	Post*p=malloc(sizeof(Post));
	if(!p){
		printf("memory allocation failed");
		exit(1);
	}
	
	p->username=copystr(username);
	p->caption=copystr(caption);
	p->comments=NULL;
	p->prev=NULL;
	p->next=NULL;
	return p;
}

