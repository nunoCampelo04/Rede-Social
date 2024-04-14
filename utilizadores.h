#ifndef _UTILIZADORES_H_
#define _UTILIZADORES_H_

struct Utilizador
{
	char* username;
	char* password;
	char* dataNascimento;
	char* email;
};

int CriarFicheiroUser(struct Utilizador* u);
int CriarConta();
int AutenticarUser(char* name, char* pass);


#endif // _UTILIZADORES_H_

