#include <stdio.h>
#include <string.h>
#include <locale.h>
#define Loop 1000

struct Cadastro{
	char Nome[50];
	char Vacina[20];
	char Data[11];
	char CPF[20];
	int Nlote;
};

struct Cadastro Dados[Loop];

	void cadastro(i){
	printf("|Código: %d \n", i);
	printf("|Nome: %s \n",Dados[i].Nome);
	printf("|CPF: %s \n",Dados[i].CPF);
	printf("|Vacina: %s \n",Dados[i].Vacina);
	printf("|Data: %s \n",Dados[i].Data);
	printf("|Lote: %d \n",Dados[i].Nlote);
	printf("==================================\n");	
}
    void cadastramento(i){
	printf("Informe o Nome da pessoa:  \n");
	gets(Dados[i].Nome);
	fflush(stdin);
	printf("Informe o CPF da pessoa: \n");
	gets(Dados[i].CPF);
	fflush(stdin);
	printf("Informe a Vacina Aplicada: \n");
	gets(Dados[i].Vacina);
	fflush(stdin);
	printf("Informe a Data da Vacina: \n");
	gets(Dados[i].Data);								
	fflush(stdin);
	printf("Informe o numero do Lote: \n");
	scanf("%d", &Dados[i].Nlote);					
	fflush(stdin);
}
void head(){
	printf("|<<<<<CONTROLE DE VACINAÇÂO>>>>>>|\n\n");
}
void menu(){
	printf("|     1 - Cadastrar Vacina       |\n");
	printf("|     2 - Listar Aplicações      |\n");
	printf("|     3 - Consultar por CPF      |\n");
	printf("|     4 - Sair                   |\n");
	printf("Digite um Número: ");
}
void clean(){
	fflush(stdin);//limpar buffer do teclado
	system("cls");//limpar o sistema
}

int main() {
	setlocale(LC_ALL, "Portuguese");	
	char CPFC[20];
	int  i=0,c,d,Menu,CPFcompare,Admin;		

	while(i<Loop){
		head();
		menu();//chamando procedimento Menu
		scanf("%d", &Menu);
		clean();	
		
		switch (Menu)
		{
			case 1:
				head();
				printf("Bem Vindo(a) ao Cadastramento de Vacinas\n");
				cadastramento(i);//chamando o procedimento que faz o cadastramento 
				system("cls");
				printf("Cadastramento Feito com Sucesso!\n Aqui estão as informações \n\n");
				cadastro(i);//chamando a função	que apresenta o cadastro
				system("pause");	
				clean();//procedimento de Limpeza
				break;
			case 2:
				head();
				if(i == 0){
					printf("Não há Pacientes Cadastrados.\n");
				}else{
					printf("Aqui está a Lista de Aplicações\n \n");
				fflush(stdin);
				for (c=0; c<i ;c++)
				{	
					cadastro(c); //chamando sub-rotina	
				}	
				}
				
				i= i-1; //Isso e pra Nao bugar o Codigo quando vira o loop ja que nao adicionou vacina
				system("pause");
				clean();
				break;
			case 3:
				head();
				printf("Digite o CPF Que deseja Consultar\n\n");
				scanf("%s", &CPFC);
				for (d=0; d<i;d++){
					CPFcompare = strcmp(Dados[d].CPF,CPFC);
					if(CPFcompare==0)
					{	
						cadastro(d);//chamando sub-rotina
						d = Loop;//pro loop nao continuar rodando quando achar o valor
					}
				}
				if(CPFcompare != 0){
				printf("CPF nao encontrado.\n");
				}
				i= i-1; //Isso e pra Nao bugar o Codigo quando vira o loop ja que nao adicionou vacina
				system("pause");
				clean();
				break;
				
			case 4:
				printf("Encerrando...");
				return 0;
				break;
				
			case 100://criei essa função pra testar varias consultas ao mesmo tempo e nao ter que ficar digitando de 1 & 1 e um pouco bugado so funciona uma vez
				
				printf("Cadastrar Várias Pessoas\n");
				fflush(stdin);
				printf("Insira a quantidade de Pessoas que deseja cadastrar:");
				scanf("%d", &Admin);
				fflush(stdin);
				
				for(i;i<Admin;i++)
				{	
					cadastramento(i);
				}
				i=Admin-1;//isso aqui e pq ele sempre cria um a mais no vetor dai tem que compensar pq nao conta com o 0 la em cima
				system("pause");
				clean();
				break;	
			default:	
				printf("Digite um número correspondente ao Menu.\nDigite 100-Cadastrar Várias Pessoas\n");
				i=i-1;
				break;
		
		}
	i= i+1;	
		
	}
		
	return 0;
}
