#ifndef PLATFORM_H
#define PLATFORM_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"post.h"
#include"comment.h"
#include"reply.h"

typedef struct Platform{
	Post*posts;
	Post*last_viewed_post;
}Platform;

extern Platform platform;

Platform*create_platform(void);
bool add_post(char*username,char*caption);
bool delete_post(int n);
Post*view_post(int n);
Post*current_post(void);
Post*next_post(void);
Post*previous_post(void);
bool add_comment(char*username,char*content);
bool delete_comment(int n);
Comment*view_comments(void);
bool add_reply(char*username,char*content,int n);
bool delete_reply(int n,int m);
#endif

