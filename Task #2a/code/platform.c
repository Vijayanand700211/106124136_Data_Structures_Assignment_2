#include"platform.h"

Platform platform={NULL,NULL};

static void free_replies(Reply*r){
	//delete all replies
	while(r){
		Reply*t=r;
		r=r->next;
		free(t->username);
		free(t->content);
		free(t);
	}
}

static void free_comments(Comment*c){
	//delete all comments
	while(c){
		Comment*t=c;
		c=c->next;
		free_replies(t->replies);
		free(t->username);
		free(t->content);
		free(t);
	}
}

Platform*create_platform(void){
	//create a new platform 
	//also only one platform can be created. It is taken care by the extern keyword in the header file
	platform.posts=NULL;
	platform.last_viewed_post=NULL;
	return &platform;
}

bool add_post(char*username,char*caption){
	//add new post to end of list
	Post*p=create_post(username,caption);
	if(!platform.posts){
		platform.posts=p;
		platform.last_viewed_post=p;
		return true;
	}

	Post*q=platform.posts;
	while(q->next)q=q->next;
	q->next=p;
	p->prev=q;
	return true;
}


static Post*get_post_from_end(int n){
	//nth from the end
	if(n<=0)return NULL;
	Post*p=platform.posts;
	if(!p)return NULL;
	while(p->next)p=p->next;
	int i=1;
	while(p&&i<n){
		p=p->prev;
		i++;
	}
	return p;
}

bool delete_post(int n){
	//delete post by number
	Post*p=get_post_from_end(n);
	if(!p)return false;
	if(p->prev)p->prev->next=p->next;
	else platform.posts=p->next;
	if(p->next)p->next->prev=p->prev;


	
	free_comments(p->comments);
	free(p->username);
	free(p->caption);
	free(p);
	if(platform.last_viewed_post==p){
		platform.last_viewed_post=platform.posts;
	}
	return true;
}

Post*view_post(int n){
	//show a post by number
	Post*p=get_post_from_end(n);
	if(!p){
		printf("Post does not exist.\n");
		return NULL;
	}
	platform.last_viewed_post=p;
	printf("%s %s\n",p->username,p->caption);
	return p;
}

Post*current_post(void){
	if(!platform.last_viewed_post){
		printf("No posts yet.\n");
		return NULL;
	}
	printf("%s %s\n",platform.last_viewed_post->username,platform.last_viewed_post->caption);
	return platform.last_viewed_post;
}

Post*next_post(void){
	//goto olderpost
	if(!platform.last_viewed_post){
		printf("Next post does not exist.\n");
		return NULL;
	}

	if(!platform.last_viewed_post->prev){
		printf("%s %s\n",platform.last_viewed_post->username,platform.last_viewed_post->caption);
		return platform.last_viewed_post;
	}
	platform.last_viewed_post=platform.last_viewed_post->prev;
	printf("%s %s\n",platform.last_viewed_post->username,platform.last_viewed_post->caption);
	return platform.last_viewed_post;
}

Post*previous_post(void){
	//goto newer post
	if(!platform.last_viewed_post){
		printf("Previous post does not exist.\n");
		return NULL;
	}

	if(!platform.last_viewed_post->next){
		printf("%s %s\n",platform.last_viewed_post->username,platform.last_viewed_post->caption);
		return platform.last_viewed_post;
	}

	platform.last_viewed_post=platform.last_viewed_post->next;
	printf("%s %s\n",platform.last_viewed_post->username,platform.last_viewed_post->caption);
	return platform.last_viewed_post;
}


bool add_comment(char*username,char*content){
	//add comments
	if(!platform.last_viewed_post){
		printf("No post selected.\n");
		return false;
	}
	Comment*c=create_comment(username,content);
	if(!platform.last_viewed_post->comments){
		platform.last_viewed_post->comments=c;
		return true;
	}


	Comment*t=platform.last_viewed_post->comments;
	while(t->next)t=t->next;
	t->next=c;
	c->prev=t;
	return true;
}

static Comment*get_comment_from_end(Post*p,int n){
	//nth comment from end
	if(!p||n<=0||!p->comments)return NULL;
	Comment*c=p->comments;
	while(c->next)c=c->next;
	int i=1;
	while(c&&i<n){
		c=c->prev;
		i++;
	}
	return c;
}

bool delete_comment(int n){
	// to delete a comment by number
	if(!platform.last_viewed_post)return false;
	Comment*c=get_comment_from_end(platform.last_viewed_post,n);
	if(!c)return false;
	if(c->prev)c->prev->next=c->next;
	else{
		 platform.last_viewed_post->comments=c->next;
	}
	if(c->next)c->next->prev=c->prev;


	free_replies(c->replies);
	free(c->username);
	free(c->content);
	free(c);
	return true;
}

Comment*view_comments(void){
	//show all comments and replies for current post
	if(!platform.last_viewed_post){
		printf("No post selected.\n");
		return NULL;
	}

	Comment*c=platform.last_viewed_post->comments;

	while(c){
		printf("%s %s\n",c->username,c->content);
		Reply*r=c->replies;
		while(r){
			printf("%s %s\n",r->username,r->content);
			r=r->next;
		}
		c=c->next;
		if(c)printf("\n");
	}
	return platform.last_viewed_post->comments;
}

bool add_reply(char*username,char*content,int n){
	//reply to nth comment
	if(!platform.last_viewed_post)return false;
	Comment*c=get_comment_from_end(platform.last_viewed_post,n);
	if(!c)return false;
	Reply*r=create_reply(username,content);
	if(!c->replies){
		c->replies=r;
		return true;
	}

	Reply*t=c->replies;
	while(t->next)t=t->next;
	t->next=r;
	r->prev=t;
	return true;
}

static Reply*get_reply_from_end(Comment*c,int m){
	//nth reply from end
	if(!c||m<=0||!c->replies)return NULL;
	Reply*r=c->replies;
	while(r->next)r=r->next;
	int i=1;
	while(r&&i<m){
		r=r->prev;
		i++;
	}
	return r;
}

bool delete_reply(int n,int m){
	if(!platform.last_viewed_post)return false;
	Comment*c=get_comment_from_end(platform.last_viewed_post,n);
	if(!c)return false;
	Reply*r=get_reply_from_end(c,m);
	if(!r)return false;
	if(r->prev)r->prev->next=r->next;
	else c->replies=r->next;
	if(r->next)r->next->prev=r->prev;

	free(r->username);
	free(r->content);
	free(r);
	return true;
}

