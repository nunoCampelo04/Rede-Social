#include "post.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CriarPostUser(struct Post* post)
{	
	char ficheiroPosts[100];
	sprintf(ficheiroPosts, "data/Post.txt");

	char novoPost[100000];
		
	FILE* fp = fopen(ficheiroPosts, "a");
	
	if(fp != NULL)
	{
		sprintf(novoPost, "%s|%s|%s", post->utilizador, post->data, post->texto);
		
		fprintf(fp, "%s\n", novoPost);
	
		fclose(fp);
	}
}

void CriarPost(char* utilizadorSessao)
{ 
	struct Post post;
	
	post.utilizador = (char*) malloc(sizeof(char) * strlen(utilizadorSessao));
	
	strcpy(post.utilizador, utilizadorSessao);
	
	char data[20];
	char texto[150];
	
	post.data = (char*) malloc(20 * sizeof(char));
	post.texto = (char*) malloc(150 * sizeof(char));

	printf("Digite a data/hora do post:\n");
	
	scanf(" %[^\n]", &data);
	
	strcpy(post.data, data);
	
	printf("Digite o texto do post:\n");
	
	scanf(" %[^\n]", &texto); // para ler texto com espaços e ignorar o enter do scanf anterior.
	
	strcpy(post.texto, texto);
	
	CriarPostUser(&post);
	
	free(post.utilizador);
	free(post.data);
	free(post.texto);
}

void ConsultarPosts(char* utilizadorSessao)
{
    char filename[100];
	sprintf(filename, "data/Post.txt");
	FILE* fp = fopen(filename, "r");
	
	char post[150];
	char utilizador[50];
	char data[20];
	char line[500];
	
	while(fgets(line, sizeof (line), fp) != NULL)
	{
		sscanf(line, "%[^|]|%[^|]|%[^\n]", utilizador, data, post);
	
		if(strcmp(utilizadorSessao, utilizador) != 0)
		{	
			printf("Utilizador: %s\n", utilizador);
			printf("Data/Hora: %s\n", data);
			printf("Post: %s\n", post);
			printf("\n");
		}
	}
	
	fclose(fp);
}


