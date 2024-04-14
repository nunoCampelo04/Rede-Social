#include "utilizadores.h"
#include <stdio.h>
#include <string.h>

int CriarFicheiroUser(struct Utilizador* u)	
{
	char filename[100];
	sprintf(filename, "data/user_%s.fcp", u->username);
	FILE* fp = fopen(filename, "r");
	
	if(fp != NULL)
	{
		printf("Utilizador ja existe");
		fclose(fp);
		return 1;
	}
	
	fp = fopen(filename, "w");
	
	if(fp == NULL)
	{
		printf("Impossivel criar utilizador");
		return 2;
	}
	
	fprintf(fp, "%s\n", u->password);
	fprintf(fp, "%s\n", u->email);
	fprintf(fp, "%s\n", u->dataNascimento);
	
	fclose(fp);
	
	return 0;
}

int CriarConta()
{
		struct Utilizador sUtilizador;
		
		char username[200];
		char password[200];
		char email[200];
		char dataNascimento[200];
		
		printf("Escreva o seu username:\n");
		scanf("%s", &username);
		
		printf("Escreva a sua password:\n");
		scanf("%s", &password);
		
		printf("Escreva o seu endereco de e-mail:\n");
		scanf("%s", &email);
		
		printf("Escreva a sua data de nascimento:\n");
		scanf("%s", &dataNascimento); 
	
		printf("\n");
		
		sUtilizador.username = username;
		sUtilizador.password = password;
		sUtilizador.email = email;
		sUtilizador.dataNascimento = dataNascimento;
		
		//FILE* fp;
		
		//fprintf();
		//TODO: Guardar dados da conta no ficheiro utilizadores.txt
		
		if(CriarFicheiroUser(&sUtilizador) == 0)
			printf("Conta criada: %s\n", sUtilizador.username);
		
		printf("\n");
		
		return 0;
}

int AutenticarUser(char* name, char* pass)
{
	char filename[100];
	sprintf(filename, "data/user_%s.fcp", name);
	FILE* fp = fopen(filename, "r");
	
	int res = 0;
		
	if(fp == NULL)
	{
		printf("Utilizador nao encontrado\n");
		//return 1;
		res = 1;
	}
	
	if (res == 0)
	{
		char line[200];
	
		fgets(line, sizeof(line), fp);
		char password[200];
		sscanf(line, "%s\n", &password); // %s vai pegar na password que está no ficheiro, retira o enter, e põe na password, praa depois comparar com a pass
		
		if(strcmp(pass, password) != 0)
		{
			printf("palavra passe incorreta\n");
			res = 2;
		}
	}
	
	fclose(fp);
	
	return res;
}

