#ifndef _POST_H_
#define _POST_H_

struct Post //definir a struct como post 
{
	char* utilizador;
	char* data;
	char* texto;
};

//void CriarPost();
void CriarPostUser(struct Post* post);
void CriarPost(char* utilizadorSessao);
void ConsultarPosts(char* utilizadorSessao);

#endif 
