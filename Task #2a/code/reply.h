#ifndef REPLY_H
#define REPLY_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Reply{
	char*username;
	char*content;
	struct Reply*prev;
	struct Reply*next;
}Reply;

Reply*create_reply(char*username,char*content);
#endif

