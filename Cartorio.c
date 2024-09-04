#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

int registro()
{
	char cpf[40], nome[40], sobrenome[40], cargo[40], arquivo[40];
	
	printf("\nDigite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file; //Cria arquivo
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
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
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40], conteudo[200];
	
	printf("\nDigite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	else{
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s\n\n", conteudo);
		}
	}
	fclose(file);
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
        printf("Usuário não encontrado!\n");
        system("pause");
    }
    else
    {
        fclose(file);  // Fechar o arquivo antes de remover
        if (remove(cpf) == 0)  // Verificar se o arquivo foi removido com sucesso
        {
            printf("Usuário removido com sucesso!\n");
        }
        else
        {
            printf("Erro ao tentar remover o usuário!\n");
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
		
		printf("\n### Cartório da EBAC ###\n\n"); // Início do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");
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
			default:
				printf("Valor inválido\n");
				system("pause");
		}
	}
}
