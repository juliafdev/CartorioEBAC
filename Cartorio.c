#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuida das string

int registro() 	//Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informações dos usuários
	scanf("%s", cpf); //%s referece à string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da variável
	fclose(file); //Fecha o aqrquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}

}

int main()
 	{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrados\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if (comparacao == 0)
	{


		for(laco=1;laco=1;)
		{
	
			system("cls");
			
    		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
  	
			printf("### Cartório da EBAC ###\n\n"); //início do menu
			printf("Escolha a opção desejada do menu:\n\n"); 
			printf("\t1 - Registrar novos\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção:"); //Fim do menu
    
   			scanf("%d", &opcao); //Armazenando a escolha do usuário
    
    		system("cls"); //Responsável por limpar a tela
    	
    		switch (opcao) //Inicio da seleção do menu
    		{
    			case 1:
    			registro(); //Chamada de funções
    			break;
    		
    			case 2:
    			consulta();
    			break;
    		
    			case 3:
    			deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
			} //Fim da seleção
		} 	
	}
	else
		printf("Senha incorreta!");

}
	
