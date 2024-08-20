#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct{
	int dia;
	int mes;
	int ano;
	
}Data;

// struct conta 
typedef struct{
	char filename[30];
	char tconta[20];
	int agencia;
	int numconta;
	float lim;
	Data datven;
	char nomcli[100];
	char cpf[12];
	Data datnasc;
	char tel[15];
	char end[100];
	char cep[10];
	char local[50];
	int numcasa;
	char bairro[50];
	char cidade[50];
	char estado[20];
	float saldo;
	int sencli;
	char Atv[100];
}Conta;

typedef struct{
	char filename[30];
	int codfun;
	char cargo[30];
	char nomfun[100];
	char CPF[12];
	Data datnasc;
	char tel[15];
	char end[100];
	char CEP[10];
	char local[50];
	int numcasa;
	char bairro[50];
	char cidade[50];
	char estado[20];
	int senfun;
}FunC;


// Declaração das funções
void nomB();
void limparBuffer();
void ultimoNum(int *ultimonum);
void atualizarnum(int ultimonum);
void adicionarnum(int *ultimonum);
void ultimoNum1(int *ultimonum1);
void atualizarnum1(int ultimonum1);
void adicionarnum1(int *ultimonum1);
void admsen(int *sen3);
void Cconta(int *ultimonum, int *opcao5);
void cadfun();
void compsencli(int numConta, int sen, int *aut);
void clisen(int *numConta);
void compsenfun(int codfun, int sen, int *aut);
void func(int *codfun);
void consuCo();
void consuF();
void consuCl();
void altCo();
void altF();
void altCl();
void saldo(int *numConta);
void dep(int *numConta);
void saque(int *numConta);
void extrato(int *numConta);
void consuLi(int *numConta);
void ence();
void abrirNoExcel(const char *nomeArquivo);
void gerre();
void altD(int *opcao3);
void cons(int *opcao2);
void abcon(int *opcao1);
void menfun(int *opcao0, int cod);
void menclin(int *opcao6, int num);
void menP(int *opcao);


#endif
