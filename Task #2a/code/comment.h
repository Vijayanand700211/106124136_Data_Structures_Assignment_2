#ifndef COMMENT_H
#define COMMENT_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Reply;

typedef struct Comment{
	char*username;
	char*content;
	struct Reply*replies;
	struct Comment*prev;
	struct Comment*next;
}Comment;

Comment*create_comment(char*username,char*content);
#endif

