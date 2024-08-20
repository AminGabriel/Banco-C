#include "biblioteca.c"
#include "funcoes.h"

int Consen = 0;

//Funcao do nome do banco
void nomB() {
    printf("                   * ######      ##    ##   ##   #####    #####            ##   ##     ##     ####     ##  ##     ##    ######   #######  ###### *\n");
    printf("                   *  ##  ##    ####   ###  ##  ##   ##  ##   ##           ### ###    ####     ##      ##  ##    ####    ##  ##   ##  ##   ##  ## *\n");
    printf("                   *  ##  ##   ##  ##  #### ##  ##       ##   ##           #######   ##  ##    ##      ##  ##   ##  ##   ##  ##   ##       ##  ## *\n");
    printf("                   *  #####    ######  ## ####  ##       ##   ##           ## # ##   ######    ##      ##  ##   ######   ##  ##   ####     ##### *\n");
    printf("                   *  ##  ##   ##  ##  ##  ###  ##       ##   ##           ##   ##   ##  ##    ##      ##  ##   ##  ##   ##  ##   ##       #### *\n");
    printf("                   *  ##  ##   ##  ##  ##   ##  ##   ##  ##   ##           ##   ##   ##  ##    ## ##    ####    ##  ##   ##  ##   ##  ##   ## ## *\n");
    printf("                   * ######    ##  ##  ##   ##   #####    #####            ##   ##   ##  ##   ######     ##     ##  ##  ######   #######  ###  ## *\n");
}

// Funcao de limpeza de buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void ultimoNum(int *ultimonum){

    FILE *arquivo = fopen("Ultimo_num_conta.txt", "r");
	*ultimonum = 0;
	
	if(arquivo != NULL){
		fscanf(arquivo, "%d", ultimonum);
		fclose(arquivo);
	}else{
		printf("Erro ao criar o arquivo");
		getchar();
		getchar();
	}
}

void atualizarnum(int ultimonum){
	FILE *arquivo = fopen("Ultimo_num_conta.txt", "w");
	if(arquivo != NULL){
		fprintf(arquivo, "%d", ultimonum);
		fclose(arquivo);
	}else{
		printf("Erro ao abrir o arquivo\n");
	}
}

void adicionarnum(int *ultimonum){
	*ultimonum += 1;
	atualizarnum(*ultimonum);
}


void ultimoNum1(int *ultimonum1){

    FILE *arquivo = fopen("Ultimo_num_cod.txt", "r");
	*ultimonum1 = 0;
	
	if(arquivo != NULL){
		fscanf(arquivo, "%d", ultimonum1);
		fclose(arquivo);
	}else{
		printf("Erro ao criar o arquivo");
		getchar();
	}
}


void atualizarnum1(int ultimonum1){
	FILE *arquivo = fopen("Ultimo_num_cod.txt", "w");
	if(arquivo != NULL){
		fprintf(arquivo, "%d", ultimonum1);
		fclose(arquivo);
	}else{
		printf("Erro ao abrir o arquivo\n");
		getchar();
	}
}

void adicionarnum1(int *ultimonum1){
	*ultimonum1 += 1;
	atualizarnum1(*ultimonum1);
}

//Funcao de teste de senha adm
void admsen(int *sen3){
	system("cls");
	nomB();
	int admsen = 9876;
	printf("Digite a senha do administrador: ");
	scanf("%d", sen3);
	if(*sen3 == admsen){
		*sen3 = 1;
	}else{
		*sen3 = 0;
	}
}

//criacao de conta
void Cconta(int *ultimonum, int *opcao5){
	Conta conta;
	
	adicionarnum(ultimonum);
	conta.numconta = *ultimonum;
	conta.saldo = 0.0;

	system("cls");
	nomB();
	
	if(*opcao5 == 1){
		strcpy(conta.tconta, "Conta corrente");
	}else if(*opcao5 == 2){
		strcpy(conta.tconta, "Conta poupanca");
	}
	
	strcpy(conta.Atv, "Criacao de conta");
	
	printf("Numero da conta: %d\n", conta.numconta);
	
	printf("Digite a agencia: ");
	scanf("%d", &conta.agencia);
	limparBuffer();
	
	if(*opcao5 == 1){
		printf("Digite o limite da conta: ");
	    scanf("%f", &conta.lim);
	    limparBuffer();
	
	    printf("Digite a data de vencimento(dia/mes/ano): ");
	    scanf("%d %d %d", &conta.datven.dia, &conta.datven.mes, &conta.datven.ano);
	    limparBuffer();
	}else if(*opcao5 == 2){
        conta.datven.dia = 0;
        conta.datven.mes = 0;
        conta.datven.ano = 0;
    }
	
	printf("Digite o nome do cliente: ");
    fgets(conta.nomcli, sizeof(conta.nomcli), stdin);
    conta.nomcli[strcspn(conta.nomcli, "\n")] = '\0';
    
    printf("Digite o cpf do cliente: ");
    fgets(conta.cpf, sizeof(conta.cpf), stdin);
    conta.cpf[strcspn(conta.cpf, "\n")] = '\0';
    
    printf("Digite a data de nascimento do cliente(dia/mes/ano): ");
    scanf("%d %d %d", &conta.datnasc.dia, &conta.datnasc.mes, &conta.datnasc.ano);
    limparBuffer();
    
    printf("Digite o telefone do cliente: ");
    fgets(conta.tel, sizeof(conta.tel), stdin);
    conta.tel[strcspn(conta.tel, "\n")] = '\0';
    
    printf("Digite o endereco do cliente: ");
    fgets(conta.end, sizeof(conta.end), stdin);
    conta.end[strcspn(conta.end, "\n")] = '\0';
    
    printf("Digite o CEP do cliente: ");
    fgets(conta.cep, sizeof(conta.cep), stdin);  
    conta.cep[strcspn(conta.cep, "\n")] = '\0';
    
    printf("Digite o local do cliente: ");
    fgets(conta.local, sizeof(conta.local), stdin);
    conta.local[strcspn(conta.local, "\n")] = '\0';
    
    printf("Digite o numero da casa do cliente: ");
    scanf("%d", &conta.numcasa);
    limparBuffer();
    
    printf("Digite o bairro do cliente: ");
    fgets(conta.bairro, sizeof(conta.bairro), stdin);
    conta.bairro[strcspn(conta.bairro, "\n")] = '\0';
    
    printf("Digite a cidade do cliente: ");
    fgets(conta.cidade, sizeof(conta.cidade), stdin);
    conta.cidade[strcspn(conta.cidade, "\n")] = '\0';
    
    printf("Digite o estado do cliente: ");
    fgets(conta.estado, sizeof(conta.estado), stdin);
    conta.estado[strcspn(conta.estado, "\n")] = '\0';
    
    printf("Digite a senha do cliente: ");
    scanf("%d", &conta.sencli);
    limparBuffer();
   
    snprintf(conta.filename, sizeof(conta.filename), "conta_%d.dat", conta.numconta);
    
    FILE *arquivo = fopen(conta.filename, "wb");
    
    if(arquivo == NULL){
    	printf("Erro ao abrir o arquivo\n");
    	getchar();
    	getchar();
    	return;
	}
	
	fwrite(&conta, sizeof(Conta), 1, arquivo);
	
	fclose(arquivo);
}


// Funcao cadastro do funcionario
void cadfun(){
	int ultimonum1;
	FunC func;
	ultimoNum1(&ultimonum1);
	adicionarnum1(&ultimonum1);
	func.codfun = ultimonum1;
	
	system("cls");
	nomB();
	
	sprintf(func.filename, "codigo_%d.dat", func.codfun);
	printf("Codigo do funcionario: %d\n", func.codfun);
	
	printf("Digite o cargo do funcionario: ");
	limparBuffer();
	fgets(func.cargo, sizeof(func.cargo), stdin);
	func.cargo[strcspn(func.cargo, "\n")] = '\0';
	
	printf("Digite o nome do funcionario: ");
    fgets(func.nomfun, sizeof(func.nomfun), stdin);
    func.nomfun[strcspn(func.nomfun, "\n")] = '\0';
    
    printf("Digite o CPF do funcionario: ");
    fgets(func.CPF, sizeof(func.CPF), stdin);
    func.CPF[strcspn(func.CPF, "\n")] = '\0';
    
    printf("Digite a data de nascimento do funcionario(dia/mes/ano): ");
	scanf("%d %d %d", &func.datnasc.dia, &func.datnasc.mes, &func.datnasc.ano);
	limparBuffer();
	
	printf("Digite o telefone do funcionario: ");
    fgets(func.tel, sizeof(func.tel), stdin);
    func.tel[strcspn(func.tel, "\n")] = '\0';
    
    printf("Digite o endereco do funcionario: ");
    fgets(func.end, sizeof(func.end), stdin);
    func.end[strcspn(func.end, "\n")] = '\0';
	
	printf("Digite o CEP do funcionario: ");
    fgets(func.CEP, sizeof(func.CEP), stdin);
    func.CEP[strcspn(func.CEP, "\n")] = '\0';
    
    printf("Digite o local do funcionario: ");
    fgets(func.local, sizeof(func.local), stdin);
    func.local[strcspn(func.local, "\n")] = '\0';
    
    printf("Digite o numero da casa do funcionario: ");
	scanf("%d", &func.numcasa);
	limparBuffer();
	
	printf("Digite o bairro do funcionario: ");
    fgets(func.bairro, sizeof(func.bairro), stdin);
    func.bairro[strcspn(func.bairro, "\n")] = '\0';
    
    printf("Digite a cidade do funcionario: ");
    fgets(func.cidade, sizeof(func.cidade), stdin);
    func.cidade[strcspn(func.cidade, "\n")] = '\0';
    
    printf("Digite o estado do funcionario: ");
    fgets(func.estado, sizeof(func.estado), stdin);
    func.estado[strcspn(func.estado, "\n")] = '\0';
    
    printf("Digite a senha do funcionario: ");
    scanf("%d", &func.senfun);
    limparBuffer();
    
    FILE *arquivo = fopen(func.filename, "wb");
    
    if(arquivo == NULL){
    	printf("Erro ao abrir o arquivo\n");
    	return;
	}
	
	fwrite(&func, sizeof(FunC), 1, arquivo);
	
	fclose(arquivo);
}

void compsencli(int numConta, int sen, int *aut){
	char filename[30];
	sprintf(filename, "conta_%d.dat", numConta);
	FILE *arquivo = fopen(filename, "rb");
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo\n");
		getchar();
		*aut = 0;
		return;
	}
	
	Conta conta;
	
	// Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
	
	if(fread(&conta, sizeof(Conta), 1, arquivo) !=1){
		printf("Erro ao ler o arquivo");
		fclose(arquivo);
		getchar();
		*aut = 0;
		return;
	}
	
	fclose(arquivo);
    
    if (strcmp(conta.Atv, "Conta encerrada") == 0) {
        *aut = 0;
        return;
    } else {
        if (sen == conta.sencli) {
            *aut = 1;
        } else {
            *aut = 0;
        }
    }
}

//Funcao de teste de senha do cliente
void clisen(int *numConta){
	system("cls");
	nomB();
	
	if(*numConta == 0){
		printf("Digite o numero da conta: ");
	    scanf("%d", numConta);
	    limparBuffer();
	}
	int clisen2;
	printf("Digite a senha: ");
	scanf("%d", &clisen2);
	compsencli(*numConta,clisen2, &Consen);
}

void compsenfun(int codfun, int sen, int *aut){
	char filename[30];
	sprintf(filename, "codigo_%d.dat", codfun);
	FILE *arquivo = fopen(filename, "rb");
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo\n");
		getchar();
		*aut = 0;
		return;
	}
	
	FunC func;
	if(fread(&func, sizeof(FunC), 1, arquivo) !=1){
		printf("Erro ao ler o arquivo");
		fclose(arquivo);
		getchar();
		*aut = 0;
		return;
	}
	
	fclose(arquivo);
	if(sen == func.senfun){
		*aut = 1;
	}else{
		*aut = 0;
	}
}

// Funcao de teste de senha do funcionario
void func(int *codfun){
	system("cls");
	nomB();
    
    if(*codfun == 0){
    	printf("Digite o codigo do funcionario: ");
	    scanf("%d", codfun);
	    limparBuffer();
	}
	int funsen;
	printf("Digite a senha: ");
	scanf("%d", &funsen);
	compsenfun(*codfun, funsen,&Consen);
}

void consuCo() {
    int numConta;
    
    system("cls");
    nomB();
    
    printf("Digite o numero da conta: ");
    scanf("%d", &numConta);
    limparBuffer();
    
    char filename[30];
    sprintf(filename, "conta_%d.dat", numConta);
    
    FILE *arquivo = fopen(filename, "rb"); // Abrindo o arquivo no modo leitura binária
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        return;
    }
    
    Conta conta; // Variável para armazenar os dados da conta
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro (saldo)
    fseek(arquivo, -deslocamento, SEEK_END);
    
    // Lendo a primeira linha (tipo de conta, nome do cliente, CPF, etc.)
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao ler os dados da conta\n");
        getchar();
        getchar();
        fclose(arquivo);
        return;
    }
    
    fclose(arquivo);
    
    if (strcmp(conta.Atv, "Conta encerrada") == 0) {
        printf("Conta encerrada\n");
        getchar();
        return;
    }
    
    // Imprimindo os outros dados da conta
    printf("Saldo da conta: %f\n", conta.saldo);
    printf("Tipo de conta: %s\n", conta.tconta);
    printf("Nome do cliente: %s\n", conta.nomcli);
    printf("CPF do cliente: %s\n", conta.cpf);
    if(strcmp(conta.tconta, "Conta corrente") == 0){
        printf("Limite: %f\n", conta.lim);
        printf("Data de vencimento: %d/%d/%d\n", conta.datven.dia, conta.datven.mes, conta.datven.ano);
    }
    getchar();
}

// Consulta funcionario
void consuF() {
    int numCod;
    
    system("cls");
    nomB();
    
    printf("Digite o codigo do funcionario: ");
    scanf("%d", &numCod);
    limparBuffer();
    
    char filename[30];
    sprintf(filename, "codigo_%d.dat", numCod);
    
    FILE *arquivo = fopen(filename, "rb"); // Abrindo o arquivo no modo leitura binária
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        return;
    }
    
    FunC func; // Variável para armazenar os dados do funcionário
    
//    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro (saldo)
    fseek(arquivo, -deslocamento, SEEK_END);
    
    // Retroceder para o início do arquivo para ler a primeira linha
//    fseek(arquivo, 0, SEEK_SET);
    
    // Lendo a primeira linha do arquivo
    if (fread(&func, sizeof(FunC), 1, arquivo) != 1) {
        printf("Erro ao ler os dados do funcionario\n");
        getchar();
        fclose(arquivo);
        return;    
    }
    
    printf("Codigo do funcionario: %d\n", func.codfun);
    printf("Cargo: %s\n", func.cargo);
    printf("Nome do funcionario: %s\n", func.nomfun);
    printf("CPF do funcionario: %s\n", func.CPF);
    printf("Data de nascimento: %d/%d/%d\n", func.datnasc.dia, func.datnasc.mes, func.datnasc.ano);
    printf("Telefone: %s\n", func.tel);
    printf("Endereco: %s\n", func.end);
    printf("Numero da casa: %d\n", func.numcasa);
    printf("CEP: %s\n", func.CEP);
    printf("Bairro: %s\n", func.bairro);
    printf("Cidade: %s\n", func.cidade);
    printf("Estado: %s\n", func.estado);
    
    getchar();
    getchar();
    fclose(arquivo);
}

// Consulta cliente
void consuCl(){  
	int numConta;
	
	system("cls");
	nomB();
	
	printf("Digite o numero da conta: ");
	scanf("%d", &numConta);
	limparBuffer();
	
	char filename[30];
	sprintf(filename, "conta_%d.dat", numConta);
	
    FILE *arquivo = fopen(filename, "rb"); // Abrindo o arquivo no modo leitura binária
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        return;
    }
    
    Conta conta; // Variável para armazenar os dados da conta lida do arquivo
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Lendo uma única conta do arquivo
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao ler a conta do arquivo\n");
        getchar();
        fclose(arquivo);
        return;
    }
    
    fclose(arquivo); 
    
    if (strcmp(conta.Atv, "Conta encerrada") == 0) {
        printf("Conta encerrada\n");
        getchar();
        return;
    }
    
    // Imprimindo os dados da conta lida
    printf("Nome do cliente: %s\n", conta.nomcli);
    printf("CPF do cliente: %s\n", conta.cpf);
    printf("Data de nascimento: %d/%d/%d\n",conta.datnasc.dia, conta.datnasc.mes, conta.datnasc.ano );
    printf("Telefone: %s\n", conta.tel);
    printf("Endereco: %s\n", conta.end);
    printf("Numero da casa: %d\n", conta.numcasa);
    printf("CEP: %s\n", conta.cep);
    printf("Bairro: %s\n", conta.bairro);
    printf("Cidade: %s\n", conta.cidade);
    printf("Estado: %s\n", conta.estado);
    
    getchar();
}

// Alteracao da conta
void altCo(){
	int numConta;
	
	system("cls");
	nomB();
	
    printf("Digite o numero da conta: ");
    scanf("%d", &numConta);
    limparBuffer();
    
    char filename[30];
    sprintf(filename, "conta_%d.dat", numConta);
    
    FILE *arquivo = fopen(filename, "rb+");
    
//    FILE *arquivo = fopen(filename, "ab+"); // Abrindo o arquivo no modo leitura e escrita binária
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        return;
    }
    
    Conta conta; // Variável para armazenar os dados da conta lida do arquivo
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Lendo uma única conta do arquivo
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao ler a conta do arquivo\n");
        getchar();
        fclose(arquivo);
        return;
    }
    
    char choice;
    
    if (strcmp(conta.Atv, "Conta encerrada") == 0){
		printf("Conta encerrada");
		getchar();
		return;
	}else{
        printf("Tipo de conta: %s\n", conta.tconta);
        printf("Deseja alterar o tipo de conta? (s/n): ");
        scanf(" %c", &choice);
        limparBuffer();
        if (choice == 's' || choice == 'S') {
            if(strcmp(conta.tconta, "Conta corrente") == 0){
        	    strcpy(conta.tconta, "Conta poupanca");
		    }else if(strcmp(conta.tconta, "Conta poupanca") == 0){
			    strcpy(conta.tconta, "Conta corrente");
		    }
        }
    
        if (strcmp(conta.tconta, "Conta corrente") == 0) {
            printf("Limite: %f\n", conta.lim);
            printf("Deseja alterar o limite? (s/n): ");
            scanf(" %c", &choice);
            limparBuffer();
            if (choice == 's' || choice == 'S') {
                printf("Digite o novo limite: ");
                scanf("%f", &conta.lim);
                limparBuffer();
            }
        
            printf("Data de vencimento: %d/%d/%d\n", conta.datven.dia, conta.datven.mes, conta.datven.ano);
            printf("Deseja alterar a data de vencimento? (s/n): ");
            scanf(" %c", &choice);
            limparBuffer();
            if (choice == 's' || choice == 'S') {
                printf("Digite a nova data de vencimento (dia/mes/ano): ");
                scanf("%d %d %d", &conta.datven.dia, &conta.datven.mes, &conta.datven.ano);
                limparBuffer();
            }
        }
    
        strcpy(conta.Atv, "Alteracao de dados");
    
        fseek(arquivo, 0, SEEK_END);
    
        // Escrevendo a conta alterada no arquivo
        if (fwrite(&conta, sizeof(Conta), 1, arquivo) != 1) {
            printf("Erro ao escrever a conta no arquivo\n");
            getchar();
            fclose(arquivo);
            return;
        }
    
        printf("Dados alterados com sucesso!\n");
        getchar();
        fclose(arquivo);
	}
    fclose(arquivo);
} 
// Alteracao do funcionario
void altF(){
	int numCod;
	
	system("cls");
	nomB();
	
    printf("Digite o codigo do funcionario: ");
    scanf("%d", &numCod);
    limparBuffer();
    
    char filename[30];
    sprintf(filename, "codigo_%d.dat", numCod);
    
    FILE *arquivo = fopen(filename, "rb+");
    
//    FILE *arquivo = fopen(filename, "ab+"); // Abrindo o arquivo no modo leitura e escrita binária
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        return;
    }
    
    FunC func; // Variável para armazenar os dados da conta lida do arquivo
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(FunC);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Lendo uma única conta do arquivo
    if (fread(&func, sizeof(FunC), 1, arquivo) != 1) {
        printf("Erro ao ler a conta do arquivo\n");
        getchar();
        fclose(arquivo);
        return;
    }
    
    // Exemplo de edição de campo
    char choice;
    
    printf("Cargo do funcionario: %s\n", func.cargo);
    printf("Deseja alterar o cargo do funcionario? (s/n): ");
    scanf(" %c", &choice);
    limparBuffer();
    if (choice == 's' || choice == 'S') {
        printf("Digite o novo cargo do funcionario: ");
        fgets(func.cargo, sizeof(func.cargo), stdin);
        size_t len = strlen(func.cargo);
        if (len > 0 && func.cargo[len - 1] == '\n') {
            func.cargo[len - 1] = '\0';
        }
    }
    
    printf("Telefone do funcionario: %s\n", func.tel);
    printf("Deseja alterar o telefone do funcionario? (s/n): ");
    scanf(" %c", &choice);
    limparBuffer();
    if (choice == 's' || choice == 'S') {
        printf("Digite o novo telefone do funcionario: ");
        fgets(func.tel, sizeof(func.tel), stdin);
        size_t len = strlen(func.tel);
        if (len > 0 && func.tel[len - 1] == '\n') {
            func.tel[len - 1] = '\0';
        }
    }
    
    printf("Endereco: %s\n", func.end);
    printf("Deseja alterar o endereco? (s/n): ");
    scanf(" %c", &choice);
    limparBuffer();
    if (choice == 's' || choice == 'S') {
        printf("Digite o novo endereco: ");
        fgets(func.end, sizeof(func.end), stdin);
        size_t len = strlen(func.end);
        if (len > 0 && func.end[len - 1] == '\n') {
            func.end[len - 1] = '\0';
        }
    }
    
    printf("Numero da casa: %d\n", func.numcasa);
    printf("Deseja alterar o numero da casa? (s/n): ");
    scanf(" %c", &choice);
    limparBuffer();
    if (choice == 's' || choice == 'S') {
        printf("Digite o novo numero da casa: ");
        scanf("%d", &func.numcasa);
        limparBuffer();
    }
    
    printf("CEP: %s\n", func.CEP);
    printf("Deseja alterar o CEP? (s/n): ");
    scanf(" %c", &choice);
    limparBuffer();
    if (choice == 's' || choice == 'S') {
        printf("Digite o novo CEP: ");
        fgets(func.CEP, sizeof(func.CEP), stdin);
        size_t len = strlen(func.CEP);
        if (len > 0 && func.CEP[len - 1] == '\n') {
            func.CEP[len - 1] = '\0';
        }
    }
    
    printf("Bairro: %s\n", func.bairro);
    printf("Deseja alterar o bairro? (s/n): ");
    scanf(" %c", &choice);
    limparBuffer();
    if (choice == 's' || choice == 'S') {
        printf("Digite o novo bairro: ");
        fgets(func.bairro, sizeof(func.bairro), stdin);
        size_t len = strlen(func.bairro);
        if (len > 0 && func.bairro[len - 1] == '\n') {
            func.bairro[len - 1] = '\0';
        }
    }
    
    printf("Cidade: %s\n", func.cidade);
    printf("Deseja alterar a cidade? (s/n): ");
    scanf(" %c", &choice);
    limparBuffer();
    if (choice == 's' || choice == 'S') {
        printf("Digite a nova cidade: ");
        fgets(func.cidade, sizeof(func.cidade), stdin);
        size_t len = strlen(func.cidade);
        if (len > 0 && func.cidade[len - 1] == '\n') {
            func.cidade[len - 1] = '\0';
        }
    }
    
    printf("Estado: %s\n", func.estado);
    printf("Deseja alterar o estado? (s/n): ");
    scanf(" %c", &choice);
    limparBuffer();
    if (choice == 's' || choice == 'S') {
        printf("Digite o novo estado: ");
        fgets(func.estado, sizeof(func.estado), stdin);
        size_t len = strlen(func.estado);
        if (len > 0 && func.estado[len - 1] == '\n') {
            func.estado[len - 1] = '\0';
        }
    }

    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Escrevendo a conta alterada no arquivo
    if (fwrite(&func, sizeof(FunC), 1, arquivo) != 1) {
        printf("Erro ao escrever o codigo no arquivo\n");
        getchar();
        fclose(arquivo);
        return;
    }
    
    printf("Dados alterados com sucesso!\n");
    getchar();
    fclose(arquivo);
}
// Alteracao do cliente
void altCl(){
	int numConta;
	
	system("cls");
	nomB();
	
    printf("Digite o numero da conta: ");
    scanf("%d", &numConta);
    limparBuffer();
    
    char filename[30];
    sprintf(filename, "conta_%d.dat", numConta);

    FILE *arquivo = fopen(filename, "rb+");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        return;
    }
    
    Conta conta; // Variável para armazenar os dados da conta lida do arquivo
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Lendo uma única conta do arquivo
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao ler a conta do arquivo\n");
        getchar();
        fclose(arquivo);
        return;
    }
    
    char choice;
    
    if(strcmp(conta.Atv, "Conta encerrada") == 0){
		printf("Conta encerrada");
		getchar();
		return;
	}else{

        printf("Telefone: %s\n", conta.tel);
        printf("Deseja alterar o telefone? (s/n): ");
        scanf(" %c", &choice);
        limparBuffer();
        if (choice == 's' || choice == 'S') {
            printf("Digite o novo telefone: ");
            fgets(conta.tel, sizeof(conta.tel), stdin);
            size_t len = strlen(conta.tel);
            if (len > 0 && conta.tel[len - 1] == '\n') {
                conta.tel[len - 1] = '\0';
            }
        }
    
        printf("Endereco: %s\n", conta.end);
        printf("Deseja alterar o endereco? (s/n): ");
        scanf(" %c", &choice);
        limparBuffer();
        if (choice == 's' || choice == 'S') {
            printf("Digite o novo endereco: ");
            fgets(conta.end, sizeof(conta.end), stdin);
            size_t len = strlen(conta.end);
            if (len > 0 && conta.end[len - 1] == '\n') {
                conta.end[len - 1] = '\0';
            }
        }
    
        printf("Numero da casa: %d\n", conta.numcasa);
        printf("Deseja alterar o numero da casa? (s/n): ");
        scanf(" %c", &choice);
        limparBuffer();
        if (choice == 's' || choice == 'S') {
            printf("Digite o novo numero da casa: ");
            scanf("%d", &conta.numcasa);
            limparBuffer();
        }
    
        printf("CEP: %s\n", conta.cep);
        printf("Deseja alterar o CEP? (s/n): ");
        scanf(" %c", &choice);
        limparBuffer();
        if (choice == 's' || choice == 'S') {
            printf("Digite o novo CEP: ");
            fgets(conta.cep, sizeof(conta.cep), stdin);
            size_t len = strlen(conta.cep);
            if (len > 0 && conta.cep[len - 1] == '\n') {
                conta.cep[len - 1] = '\0';
            }
        }
    
        printf("Bairro: %s\n", conta.bairro);
        printf("Deseja alterar o bairro? (s/n): ");
        scanf(" %c", &choice);
        limparBuffer();
        if (choice == 's' || choice == 'S') {
            printf("Digite o novo bairro: ");
            fgets(conta.bairro, sizeof(conta.bairro), stdin);
            size_t len = strlen(conta.bairro);
            if (len > 0 && conta.bairro[len - 1] == '\n') {
                conta.bairro[len - 1] = '\0';
            }
        }
    
        printf("Cidade: %s\n", conta.cidade);
        printf("Deseja alterar a cidade? (s/n): ");
        scanf(" %c", &choice);
        limparBuffer();
        if (choice == 's' || choice == 'S') {
            printf("Digite a nova cidade: ");
            fgets(conta.cidade, sizeof(conta.cidade), stdin);
            size_t len = strlen(conta.cidade);
            if (len > 0 && conta.cidade[len - 1] == '\n') {
                conta.cidade[len - 1] = '\0';
            }
        }
    
        printf("Estado: %s\n", conta.estado);
        printf("Deseja alterar o estado? (s/n): ");
        scanf(" %c", &choice);
        limparBuffer();
        if (choice == 's' || choice == 'S') {
            printf("Digite o novo estado: ");
            fgets(conta.estado, sizeof(conta.estado), stdin);
            size_t len = strlen(conta.estado);
            if (len > 0 && conta.estado[len - 1] == '\n') {
                conta.estado[len - 1] = '\0';
            }
        }

        fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
        // Escrevendo a conta alterada no arquivo
        if (fwrite(&conta, sizeof(Conta), 1, arquivo) != 1) {
            printf("Erro ao escrever a conta no arquivo\n");
            getchar();
            fclose(arquivo);
            return;
        }
     
        printf("Dados alterados com sucesso!\n");
        getchar();
	}
    fclose(arquivo);
}

void saldo(int *numConta){
	system("cls");
	nomB();
	
	char filename[30];
	sprintf(filename, "conta_%d.dat", *numConta);
	
    FILE *arquivo = fopen(filename, "rb+"); // Abrindo o arquivo no modo leitura binária
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        getchar();
        return;
    }
    
    Conta conta; // Variável para armazenar os dados da conta lida do arquivo
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Lendo uma única conta do arquivo
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao ler a conta do arquivo\n");
        getchar();
        getchar();
        fclose(arquivo);
        return;
    }
    
    // Imprimindo os dados da conta lida
    printf("Saldo da conta: %f\n", conta.saldo);
    getchar();
    getchar();
    fclose(arquivo);
}

void dep(int *numConta) {
    float dep;
    
    system("cls"); // Limpa a tela (para Windows)
    nomB(); // Função que realiza alguma operação não especificada
    
    char filename[30];
    sprintf(filename, "conta_%d.dat", *numConta);
    
    FILE *arquivo = fopen(filename, "rb+"); // Abrindo o arquivo no modo de leitura e escrita
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        return;
    }
    
    Conta conta; // Variável para armazenar os dados da conta
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Lendo o último registro (última conta no arquivo)
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao ler a conta do arquivo\n");
        getchar();
        fclose(arquivo);
        return;
    }
    
    // Solicitar o valor do depósito
    printf("Saldo atual da conta: %f\n", conta.saldo);
    printf("Digite o valor do depósito: ");
    scanf("%f", &dep);
    
    // Adicionar o depósito ao saldo atual
    conta.saldo += dep;
    
    
    sprintf(conta.Atv, "Deposito: %2.f", dep);
    
    // Escrever o novo registro no final do arquivo
    fseek(arquivo, 0, SEEK_END);
    if (fwrite(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao escrever o depósito no arquivo\n");
        getchar();
    } else {
        printf("Depósito realizado com sucesso!\n");
        printf("Novo saldo: %f\n", conta.saldo);
    }
    
    getchar(); // Aguarda o usuário pressionar Enter para continuar
    fclose(arquivo); // Fecha o arquivo
}

void saque(int *numConta) {
    float saq;
    
    system("cls"); // Limpa a tela (para Windows)
    nomB(); 
    
    char filename[30];
    sprintf(filename, "conta_%d.dat", *numConta);
    
    FILE *arquivo = fopen(filename, "rb+"); // Abrindo o arquivo no modo de leitura e escrita
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        return;
    }
    
    Conta conta; // Variável para armazenar os dados da conta
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Lendo o último registro (última conta no arquivo)
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao ler a conta do arquivo\n");
        getchar();
        fclose(arquivo);
        return;
    }
    
    // Solicitar o valor do saque
    printf("Saldo atual da conta: %f\n", conta.saldo);
    printf("Digite o valor do saque: ");
    scanf("%f", &saq);
    
    sprintf(conta.Atv, "Saque: %2.f", saq);
    
    // Verificar o tipo de conta e realizar o saque
    if (strcmp(conta.tconta, "Conta corrente") == 0) {
        if (saq <= conta.saldo) {
            conta.saldo -= saq;
        } else {
            float dif = saq - conta.saldo;
            if (dif <= conta.lim) {
                conta.saldo -= saq;
                conta.lim -= dif;
            } else {
                printf("Saldo indisponível\n");
                getchar();
            }
        }
    } else if (strcmp(conta.tconta, "Conta poupanca") == 0) {
        if (saq <= conta.saldo) {
            conta.saldo -= saq;
        } else {
            printf("Saldo indisponível\n");
            getchar();
        }
    }
    
    // Escrever o novo registro no final do arquivo
    fseek(arquivo, 0, SEEK_END);
    if (fwrite(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao escrever o saque no arquivo\n");
        getchar();
    } else {
        printf("Saque realizado com sucesso!\n");
        printf("Novo saldo: %f\n", conta.saldo);
    }
    
    getchar(); // Aguarda o usuário pressionar Enter para continuar
    fclose(arquivo); // Fecha o arquivo
}

void extrato(int *numConta) {
    // Criar o nome do arquivo .dat baseado no número da conta
    char filename[30];
    sprintf(filename, "conta_%d.dat", *numConta);
    
    // Abrir o arquivo no modo leitura binária
    FILE *arquivo = fopen(filename, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        return;
    }
    
    // Criar nome do arquivo CSV
    char extrato_csv[50];
    sprintf(extrato_csv, "extrato.csv");
    
    // Abrir o arquivo CSV para escrita
    FILE *arquivo_csv = fopen(extrato_csv, "w");
    if (arquivo_csv == NULL) {
        printf("Erro ao criar o arquivo de extrato.\n");
        fclose(arquivo);
        return;
    }
    
    Conta conta;
    
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    long deslocamento = sizeof(Conta);
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Escrever cabeçalho no arquivo CSV
    fprintf(arquivo_csv, "Agencia;Numero da Conta;Nome do Cliente;CPF;CEP;Tipo de Conta;Atividade;Saldo;Limite;Data de vencimento\n");
    
    // Lê o primeiro registro para escrever a linha de detalhes
    if (fread(&conta, sizeof(Conta), 1, arquivo) == 1) {
        fprintf(arquivo_csv, "%d;%d;%s;%s;%s;", conta.agencia, conta.numconta, conta.nomcli, conta.cpf, conta.cep);
    }
    
    fseek(arquivo, 0, SEEK_SET);
    
    if(fread(&conta, sizeof(Conta), 1, arquivo) == 1){
    	// Escrever primeira linha com todos os dados da conta
        if (strcmp(conta.tconta, "Conta poupanca") == 0) {
            fprintf(arquivo_csv, "%s;%s;%.2f;\n", conta.tconta, conta.Atv, conta.saldo);
        } else if (strcmp(conta.tconta, "Conta corrente") == 0) {
            fprintf(arquivo_csv, "%s;%s;%.2f;%.2f;%02d/%02d/%04d\n", conta.tconta, conta.Atv, conta.saldo, conta.lim, conta.datven.dia, conta.datven.mes, conta.datven.ano);
        }
	}
	
	fseek(arquivo, sizeof(Conta), SEEK_SET);
	
	while(fread(&conta, sizeof(Conta), 1, arquivo) == 1){
		
    	// Escrever primeira linha com todos os dados da conta
        if (strcmp(conta.tconta, "Conta poupanca") == 0) {
            fprintf(arquivo_csv, ";;;;;%s;%s;%.2f;;\n", conta.tconta, conta.Atv, conta.saldo);
        } else if (strcmp(conta.tconta, "Conta corrente") == 0) {
            fprintf(arquivo_csv, ";;;;;%s;%s;%.2f;%.2f;\"%02d/%02d/%04d\"\n", conta.tconta, conta.Atv, conta.saldo, conta.lim, conta.datven.dia, conta.datven.mes, conta.datven.ano);
        }
	}
    
    fclose(arquivo);
    fclose(arquivo_csv);
    
    system("start excel extrato.csv");
    
    
    printf("Extrato criado e aberto com sucesso: %s\n", extrato_csv);
}

void consuLi(int *numConta){
	system("cls");
	nomB();
	
	char filename[30];
	sprintf(filename, "conta_%d.dat", *numConta);
	
    FILE *arquivo = fopen(filename, "rb"); // Abrindo o arquivo no modo leitura binária
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        getchar();
        return;
    }
    
    Conta conta; // Variável para armazenar os dados da conta lida do arquivo
    
    
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Lendo uma única conta do arquivo
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao ler a conta do arquivo\n");
        getchar();
        fclose(arquivo);
        return;
    }
    
    // Imprimindo os dados da conta lida
    if (strcmp(conta.tconta, "Conta corrente") == 0) {
    	printf("Limite disponivel: %f\n", conta.lim);
    	getchar();
	}else{
		printf("Limite indisponivel");
		getchar();
	}
    fclose(arquivo);
}

//Menu de exclusao
void ence(){
    int numConta;
    
    system("cls"); // Limpa a tela (para Windows)
    nomB();
	
	printf("Digite o numero da conta: ");
    scanf("%d", &numConta);
    limparBuffer(); 
    
    char filename[30];
    sprintf(filename, "conta_%d.dat", numConta);
    
    FILE *arquivo = fopen(filename, "rb+"); // Abrindo o arquivo no modo de leitura e escrita
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        return;
    }
    
    Conta conta; // Variável para armazenar os dados da conta
    
    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    
    // Calcular o deslocamento necessário para retroceder até o início do último registro
    long deslocamento = sizeof(Conta);
    
    // Retroceder para o início do último registro
    fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
    
    // Lendo o último registro (última conta no arquivo)
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1) {
        printf("Erro ao ler a conta do arquivo\n");
        getchar();
        fclose(arquivo);
        return;
    }
    
    char choice;
    
    if(strcmp(conta.Atv, "Conta encerrada") == 0){
    	printf("Esta conta ja foi encerrada");
    	fclose(arquivo); // Fecha o arquivo
        getchar(); // Aguarda o usuário pressionar Enter para continuar
	}else{
        printf("Deseja encerrar a conta? (s/n): ");
        scanf(" %c", &choice);
        limparBuffer();
        if (choice == 's' || choice == 'S') {
            strcpy(conta.Atv, "Conta encerrada");
    
            // Escrever o novo registro no final do arquivo
            fseek(arquivo, 0, SEEK_END);
            if (fwrite(&conta, sizeof(Conta), 1, arquivo) != 1) {
            printf("Erro ao encerrar a conta\n");
            getchar();
            } else {
            printf("Conta encerrada com sucesso!\n");
            }
        }
        fclose(arquivo); // Fecha o arquivo
        getchar(); // Aguarda o usuário pressionar Enter para continuar
	}
}

void gerre(){
    FILE *relatorio_csv = fopen("relatorio-geral.csv", "w");
    if (relatorio_csv == NULL) {
        printf("Erro ao criar o arquivo de relatorio geral.\n");
        getchar();
        getchar();
        return;
    }
    
    // Iterar sobre os arquivos de conta
    for (int numConta = 1; numConta <= max_con; numConta++) {
        char filename[30];
        sprintf(filename, "conta_%d.dat", numConta);
        
        // Abrir o arquivo no modo leitura binária
        FILE *arquivo = fopen(filename, "rb");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo %s.\n", filename);
            continue; // Pular para o próximo arquivo se não puder ser aberto
        }
        
        Conta conta;
        
        fseek(arquivo, 0, SEEK_END);
        long tamanhoArquivo = ftell(arquivo);
        long deslocamento = sizeof(Conta);
        fseek(arquivo, tamanhoArquivo - deslocamento, SEEK_SET);
        
    
        // Escrever cabeçalho no arquivo CSV
        fprintf(relatorio_csv, "Agencia;Numero da Conta;Nome do Cliente;CPF;CEP;Tipo de Conta;Atividade;Saldo;Limite;Data de vencimento\n");
    
        // Lê o primeiro registro para escrever a linha de detalhes
        if (fread(&conta, sizeof(Conta), 1, arquivo) == 1) {
            fprintf(relatorio_csv, "%d;%d;%s;%s;%s;", conta.agencia, conta.numconta, conta.nomcli, conta.cpf, conta.cep);
        }
    
        fseek(arquivo, 0, SEEK_SET);
    
        if(fread(&conta, sizeof(Conta), 1, arquivo) == 1){
    	    // Escrever primeira linha com todos os dados da conta
            if (strcmp(conta.tconta, "Conta poupanca") == 0) {
                fprintf(relatorio_csv, "%s;%s;%.2f;\n", conta.tconta, conta.Atv, conta.saldo);
            } else if (strcmp(conta.tconta, "Conta corrente") == 0) {
                fprintf(relatorio_csv, "%s;%s;%.2f;%.2f;%02d/%02d/%04d\n", conta.tconta, conta.Atv, conta.saldo, conta.lim, conta.datven.dia, conta.datven.mes, conta.datven.ano);
            }
	    }
	
	    fseek(arquivo, sizeof(Conta), SEEK_SET);
	
	    while(fread(&conta, sizeof(Conta), 1, arquivo) == 1){
		
    	    // Escrever primeira linha com todos os dados da conta
            if (strcmp(conta.tconta, "Conta poupanca") == 0) {
                fprintf(relatorio_csv, ";;;;;%s;%s;%.2f;;\n", conta.tconta, conta.Atv, conta.saldo);
            } else if (strcmp(conta.tconta, "Conta corrente") == 0) {
                fprintf(relatorio_csv, ";;;;;%s;%s;%.2f;%.2f;\"%02d/%02d/%04d\"\n", conta.tconta, conta.Atv, conta.saldo, conta.lim, conta.datven.dia, conta.datven.mes, conta.datven.ano);
            }
        }
        
        fprintf(relatorio_csv, "\n\n");
        
        fclose(arquivo);
    }
    
    fclose(relatorio_csv);
    
    system("start excel relatorio-geral.csv");
    
    printf("Relatorio geral criado com sucesso: relatorio-geral.csv\n");
	getchar();
	getchar();
}

// Funcao menu de alteracao
void altD(int *opcao3){
	do{
		system("cls");
		nomB();
		printf("MENU DE ALTERACAO\n");
		printf("1-Alterar conta\n");
		printf("2-Alterar funcionario\n");
		printf("3-Alterar cliente\n");
		printf("4-Voltar\n");
		scanf("%d", opcao3);
		// switch case para as opcoes do menu
		switch(*opcao3){
			case 1:{
			    Consen = 0;// Inicializa a variavel que indica se a senha esta correta
                admsen(&Consen); // Chama a função de senha do administrador

                if (Consen) {
                    altCo();
                } else {
                    printf("Senha incorreta! Acesso negado.\n");
                    getchar(); // Pausa para permitir que o usuario veja a mensagem
                    getchar(); // Pausa adicional para permitir que o usuario veja a mensagem
                }
				break;
			}
			case 2:{
			    Consen = 0;// Inicializa a variavel que indica se a senha esta correta
                admsen(&Consen); // Chama a função de senha do administrador

                if (Consen) {
                    altF();
                } else {
                    printf("Senha incorreta! Acesso negado.\n");
                    getchar(); // Pausa para permitir que o usuario veja a mensagem
                    getchar(); // Pausa adicional para permitir que o usuario veja a mensagem
                }
				break;
			}
			case 3:{
			    Consen = 0;// Inicializa a variavel que indica se a senha esta correta
                admsen(&Consen); // Chama a função de senha do administrador

                if (Consen) {
                    altCl();
                } else {
                    printf("Senha incorreta! Acesso negado.\n");
                    getchar(); // Pausa para permitir que o usuario veja a mensagem
                    getchar(); // Pausa adicional para permitir que o usuario veja a mensagem
                }
				break;
			}
			case 4:
			    break;
			default:
			    printf("Numero incorreto");
			    getchar();
			    getchar();
			    break;
		}
	}while(*opcao3!=4);
}
// Menu de consulta
void cons(int *opcao2){
	
	do{
		system("cls");
		nomB();
		printf("MENU DE CONSULTA\n");
		printf("1-Consultar conta\n");
		printf("2-Consultar funcionario\n");
		printf("3-consultar cliente\n");
		printf("4-Sair\n");
		scanf("%d", opcao2);
		
		switch(*opcao2){
			case 1:
				consuCo();
				break;
			case 2:
				consuF();
				break;
			case 3:
				consuCl();
				break;
			case 4:
				break;
				
			default:
				printf("Numero invalido");
				getchar();
				getchar();
				break;
		}
	}while(*opcao2!=4);
}
//abertura de conta
void abcon(int *opcao1){
	int ultimonum;
	
	ultimoNum(&ultimonum);
	do{
		system("cls");
		nomB();
		printf("ABERTURA DE CONTA\n");
		printf("1-Conta corrente\n");
	    printf("2-Conta poupanca\n");
	    printf("3-Voltar\n");
	    scanf("%d", opcao1);
	    
	    
	    switch(*opcao1){
	    	case 1:
	    		Cconta(&ultimonum, opcao1);
	    		break;
	    	case 2:
	    		Cconta(&ultimonum, opcao1);
	    		break;
	    	case 3:
				break;
			default:
				printf("Numero invalido");
				getchar();
	        	getchar();
				break;
				
		}
			
	}while(*opcao1!=3);
}
// menu do funcionario
void menfun(int *opcao0, int cod){
	
	do{
		system("cls");
		nomB();
		printf("MENU DO FUNCIONARIO\n");
		printf("1-Abertura de conta\n");
		printf("2-Encerramento de conta\n");
		printf("3-Consultar dados\n");
		printf("4-Alterar dados\n");
		printf("5-Cadastro de funcionarios\n");
		printf("6-Gerar relatorios\n");
		printf("7-Sair\n");
		scanf("%d", opcao0);
		
		switch(*opcao0){
			case 1:
			    abcon(opcao0);    
			    break;
			case 2:{
			    Consen = 0;// Inicializa a variavel que indica se a senha esta correta
                admsen(&Consen); // Chama a função de senha do administrador

                if (Consen) {
                    ence();
                } else {
                    printf("Senha incorreta! Acesso negado.\n");
                    getchar(); // Pausa para permitir que o usuario veja a mensagem
                    getchar(); // Pausa adicional para permitir que o usuario veja a mensagem
                }
				break;
			}
			case 3:
				cons(opcao0);
				break;
			case 4:
				altD(opcao0);
				break;
			case 5:{
			    Consen = 0;// Inicializa a variavel que indica se a senha esta correta
                admsen(&Consen); // Chama a função de senha do administrador

                if (Consen) {
                    cadfun();
                } else {
                    printf("Senha incorreta! Acesso negado.\n");
                    getchar(); // Pausa para permitir que o usuario veja a mensagem
                    getchar(); // Pausa adicional para permitir que o usuario veja a mensagem
                }
				break;
			}
			case 6:{
				
				Consen = 0;// Inicializa a variavel que indica se a senha esta correta
            
				func(&cod); 
				 
			    // manda o numero da conta nessa parte
				 
                if (Consen) {
                    gerre();
                } else {
                    printf("Senha incorreta! Acesso negado.\n");
                    getchar(); // Pausa para permitir que o usuario veja a mensagem
                    getchar();
			    }
				break;
			}
			case 7:
				
				break;
			default:
				printf("Numero invalido");
				getchar();
		        getchar();
				break;
	 	
		}
	}while(*opcao0 !=7);
}

void menclin(int *opcao6, int num){
	
	do{
		system("cls");
		nomB();
		printf("MENU DO CLIENTE\n");
		printf("1-Saldo\n");
		printf("2-Deposito\n");
		printf("3-Saque\n");
		printf("4-Extrato\n");
		printf("5-Consultar limite\n");
		printf("6-Sair\n");
		scanf("%d", opcao6);
		
		switch(*opcao6){
			case 1:
				Consen = 0;
				clisen(&num);
				
				if(Consen){
					saldo(&num);
				}else{
					printf("Acesso negado\n");
					getchar();
				}
				break;	
			case 2:
			    dep(&num);
				break;
			case 3:
			    Consen = 0;
				clisen(&num);
				
				if(Consen){
					saque(&num);
				}else{
					printf("Acesso negado\n");
					getchar();
				}
				break;
			case 4: 
				Consen = 0;
				clisen(&num);
				
				if(Consen){
					extrato(&num);
				}else{
					printf("Acesso negado\n");
					getchar();
				}
				break;
			case 5:
				Consen = 0;
				clisen(&num);
				
				if(Consen){
					consuLi(&num);
				}else{
					printf("Acesso negado\n");
					getchar();
				}
				break;
			case 6:
				break;
			default:
				printf("Opcao invalida\n");
				getchar();
				break;
		}
		
	}while(*opcao6 !=6);
}

// Funcao do menu principal
void menP(int *opcao){
	int num;
	int cod;
	do{
		system("cls");
		nomB();
		printf("MENU PRINCIPAL\n");
	    printf("1-Funcionario\n");
	    printf("2-Cliente\n");
        printf("3-Sair do programa\n");
	    scanf("%d", opcao);
	
	    //switch case das opcoes 
    	switch(*opcao){
		    case 1:{
		    	Consen = 0;// Inicializa a variavel que indica se a senha esta correta
                cod = 0;
                
				func(&cod); 
				 
			    // manda o numero da conta nessa parte
				 
                if (Consen) {
                    menfun(opcao, cod);
                } else {
                    printf("Senha incorreta! Acesso negado.\n");
                    getchar(); // Pausa para permitir que o usuario veja a mensagem
                    getchar(); // Pausa adicional para permitir que o usuario veja a mensagem
                }
                break;
			}
		    case 2:{
		    	Consen = 0;// Inicializa a variavel que indica se a senha esta correta
                num = 0;
                
				clisen(&num); 
				 
			    // manda o numero da conta nessa parte
				 
                if (Consen) {
                    menclin(opcao, num);
                } else {
                    printf("Senha incorreta! Acesso negado.\n");
                    getchar(); // Pausa para permitir que o usuario veja a mensagem
                    getchar(); // Pausa adicional para permitir que o usuario veja a mensagem
                }
                break;
		    }
		    case 3:
		        break;
		
		    default:
			    printf("Opcao invalida");
			    getchar();
		        getchar();
		        break;
	    } 
	}while(*opcao!=3);
}
