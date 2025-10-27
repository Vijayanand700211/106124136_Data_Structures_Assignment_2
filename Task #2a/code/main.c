#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"platform.h"

int main(void){
	create_platform();
	char cmd[64];
	while(scanf("%63s",cmd)==1){

		if(strcmp(cmd,"create_platform")==0){
			create_platform();
			printf("Platform created\n");
		}

		else if(strcmp(cmd,"add_post")==0){
			char u[256],c[1024];
			scanf("%255s",u);
			scanf("%1023s",c);
			add_post(u,c);
		}

		else if(strcmp(cmd,"delete_post")==0){
			int n;
			scanf("%d",&n);
			if(!delete_post(n))printf("Post deletion failed\n");
		}

		else if(strcmp(cmd,"view_post")==0){
			int n;
			scanf("%d",&n);
			view_post(n);
		}

		else if(strcmp(cmd,"current_post")==0){
			current_post();
		}

		else if(strcmp(cmd,"next_post")==0){
			next_post();
		}

		else if(strcmp(cmd,"previous_post")==0){
			previous_post();
		}

		else if(strcmp(cmd,"add_comment")==0){
			char u[256],c[1024];
			scanf("%255s",u);
			scanf("%1023s",c);
			add_comment(u,c);
		}

		else if(strcmp(cmd,"delete_comment")==0){
			int n;
			scanf("%d",&n);
			if(!delete_comment(n))printf("Comment deletion failed\n");
		}

		else if(strcmp(cmd,"view_comments")==0){
			view_comments();
		}

		else if(strcmp(cmd,"view_all_comments")==0){
			view_comments();
		}

		else if(strcmp(cmd,"add_reply")==0){
			char u[256],c[1024];
			int n;
			scanf("%255s",u);
			scanf("%1023s",c);
			scanf("%d",&n);
			add_reply(u,c,n);
		}

		else if(strcmp(cmd,"delete_reply")==0){
			int n,m;
			scanf("%d%d",&n,&m);
			if(!delete_reply(n,m))printf("Reply deletion failed\n");
		}
		
		else{
			printf("Unknown command\n");
		}
	}
	return 0;
}

