#include <iostream>
#include <stdio.h>
#include <string.h>
#include "utilizadores.h"
#include "post.h"

char utilizadorSessao[50];

int MenuOperacoes(){
	
	bool sair = false;	
	while (!sair){
		
		int opcao;
		opcao = 0;
		
		printf("Escolha uma opcao:\n");
				
		printf("     1 Criar post\n");
		printf("     2. Consultar publicacoes\n");
		printf("     3. Logout\n");
		
		scanf("%d", &opcao);
		
		system("clear||cls");
		switch (opcao)
		{	
			case 1: 
				CriarPost(utilizadorSessao);
				system("clear||cls");
				break;
			case 2:
				ConsultarPosts(utilizadorSessao);
				break;
			case 3: system("clear||cls");
				return 3;
			default :
			printf("Opcao Invalida");	
	    }		
	}
}
void Login()
{	
	char username[200];
	char password[200];

	printf("Username:\n");
	scanf("%s", &username);
	
	printf("Password:\n");
	scanf("%s", &password);		
	
	if(AutenticarUser(username, password) == 0)
	{
		printf("\nLogin efetuado com sucesso!\n\n");
	
		int opcao;
		opcao = 0;
		
		strcpy(utilizadorSessao, username);
		
		while(opcao != 3)
		{
			opcao = MenuOperacoes();		                           
		}
	}
	else
	{
		printf("Erro no login\n");
	}	
}

void AcessoAnonimo()
{
       printf("==============================================================================\n");
       printf("||                     Menu BeSocial - Utilizador anonimo                  ||\n");
       printf("=============================================================================\n");
       printf("|| Opcoes:                                                                 ||\n");
       printf("||-------------------------------------------------------------------------||\n");
       printf("||        1: Ver publicacoes                                               ||\n");
       printf("||-------------------------------------------------------------------------||\n");
       printf("||        2: Sair                                                          ||\n");
       printf("=============================================================================\n\n");            
	
}

int estatisticas = 0;

int MenuPrincipal()
{
	bool sair = false;	
	while (!sair)
	{
		int opcao;
		printf("==================================================================================\n");
	    printf("||                                Bem vindo a BeSocial !                        ||\n");
	    printf("==================================================================================\n");
	    printf("|| Opcao:                                                            	  	||\n");
	    printf("||------------------------------------------------------------------------------||\n");
	    printf("||        1 ---> Login				                                ||\n");
	    printf("||------------------------------------------------------------------------------||\n");
	    printf("||        2 ---> Registo			                                ||\n");
	    printf("||------------------------------------------------------------------------------||\n");
	    printf("||        3 ---> Modo Anonimo                              			||\n");
	    printf("||------------------------------------------------------------------------------||\n");
	    printf("||        4 ---> Sair                                                           ||\n");
	    printf("==================================================================================\n");
		if(estatisticas == 1)
			printf("     5. Estatisticas\n");
		
		scanf("%d", &opcao);
		
		/* usar o switch case */
		system("clear||cls");
		switch (opcao)
		{
			case 1 :
			   Login();
			   system("clear||cls");
			   break;
			case 2 :
			   CriarConta();
			   system("clear||cls");
			   break;
			case 3 :
			   AcessoAnonimo();
			   system("clear||cls");
			   break;
			case 4:
				sair = true;
				break;
			default :
			   printf("Opcao Invalida");	
	    }
	}
}

int main(int argc, char** argv) { //o argc serve para ver o nº de argumentos e o agrv é a lista de parâmetros 
	
	for(int i = 0; i < argc; ++i)
	{
		if(strcmp(argv[i], "--stats") == 0)
			estatisticas = 1;
	}
	MenuPrincipal();
	return 0; 
}
