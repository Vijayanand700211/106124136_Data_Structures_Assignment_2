#ifndef POST_H
#define POST_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Comment;

typedef struct Post{
	char*username;
	char*caption;
	struct Comment*comments;
	struct Post*prev;
	struct Post*next;
}Post;

Post*create_post(char*username,char*caption);
#endif

