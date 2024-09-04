#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//Fun��o para registrar um novo usu�rio
int registro()
{
	char cpf[40], nome[40], sobrenome[40], cargo[40], arquivo[40];
	
	printf("\nDigite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	//Copia o CPF para a vari�vel 'arquivo', que ser� usada como nome do arquivo
	strcpy(arquivo, cpf);
	
	//Cria um novo arquivo com o nome do CPF e escreve o CPF nele
	FILE *file; //Cria arquivo
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	//Adiciona uma v�rgula ao arquivo para separar o CPF dos outros dados
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	//Solicita o nome do usu�rio e escreve no arquivo
	printf("\nDigite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("\nDigite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("\nDigite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	//Pausa o sistema ap�s a finaliza��o do registro
	system("pause");
}

//Fun��o para consultar um usu�rio cadastrado
int consulta()
{
	char cpf[40], conteudo[200];
	
	printf("\nDigite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	//Abre o arquivo correspondente ao CPF informado
	FILE *file;
	file = fopen(cpf, "r");
	
	//Verifica se o arquivo existe
	if (file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	else{
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s\n\n", conteudo);
		}
	}
	fclose(file);
	system("pause");
}

//Fun��o para deletar um usu�rio cadastrado
int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
        printf("Usu�rio n�o encontrado!\n");
        system("pause");
    }
    else
    {
        fclose(file);  // Fechar o arquivo antes de remover
        if (remove(cpf) == 0)  // Verificar se o arquivo foi removido com sucesso
        {
            printf("Usu�rio removido com sucesso!\n");
        }
        else
        {
            printf("Erro ao tentar remover o usu�rio!\n");
        }
        system("pause");
    }
}


int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao, continuar = 1;
	
	while (continuar)
	{
		system("cls");
		
		printf("\n### Cart�rio da EBAC ###\n\n"); // In�cio do Menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
				registro();
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
				printf("Valor inv�lido\n");
				system("pause");
		}
	}
}
