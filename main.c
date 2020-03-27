#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <locale.h>
#include<conio.h>
#include <mysql.h>


                                                        //Indice de blocos de programacao
                                                        //-------------------------------
                                                        // Linhas 27 a 114    - Variaveis
                                                        // Linhas 116 a 166   - Intro
                                                        // Linhas 168 a 301   - Usuario / Senha (Acesso ao sistema)
                                                        // Linhas 302 a 344   - Captura de dados "Data" e "Unidade"
                                                        // Linhas 347 a 368   - Tela de entrada
                                                        // Linhas 370 a 524   - Cadastro Cliente
                                                        // Linhas 526 a 1141  - Vendas
                                                        // Linhas 1144 a 2920 - Gerencia
                                                        // Linhas 2922 a 3278 - Estoque
                                                        // Linhas 3279 a 3467 - Cadastro Produtos
                                                        // Linhas 3468 a 3706 - Elogios / Reclamacoes


int main()
{

    //Variavies Usuario / Senha
    char usuario [50];
    int IDUsuario;
    char senha [50];
    int IDSomaTotal;

    //Variaveis Tela de entrada
    int Opcao;

    //Variavel conexao
    MYSQL conexao;

    //Variaveis Tela Cadastro de Clientes
    int res;
    char nome[50];
    char endereco[50];
    char telefone[50];
    int cadastroEscolha;
    char telefoneBusca[50];
    MYSQL_RES *resp;
    MYSQL_ROW linhas;
    MYSQL_FIELD *campos;
    int conta;

    //Variavel de Busca SQL
    char query[1000];

    //Variaveis tela Venda
    float valorConvertido;
    int venda;
    int produto;
    float valor;
    char valorBanco [50];
    float valorSomaTotal = 0;
    float valorSomaPedido = 0;
    char data [50];
    int continuaVenda;
    char valorTotalTemp[50];
    float promocaovenda;
    char promocaotelavenda [50] = "Promocao";

    //Variavies gerencia

    int escolhaPromocao;
    char promocao [50];
    char unidadegerencia [50];
    int finalCancelamento = 1;
    int contadorGerencia;
    char unidade [50];
    char unidade_Freguesia [9] = "Freguesia";
    char unidade_Lapa [4] = "Lapa";
    char unidade_Marques [7] = "Marques";
    char dataGerencia [50];
    char dataGerencia1 [50];
    int fechaBalanco;
    int contador;
    float soma;
    int gerencia;
    int gerenciarSenha;
    char tipoSenha[50];
    int IDSenha;
    char usuarioGerencia[50];
    int cancelarVenda;
    int escolha_Cancelarvenda;
    int unidades;
    int finaliza;

    //Variaveis Estoque
    char item [50];
    char quantidade [50];
    int estoque;
    int escolha_estoque;
    int identificador_id;
    int continua_estoque;

    //Variaveis Cadastro de Produtos
    int cadastrodeProdutos;
    int idcadastroprodutos;
    char produtoCadastroProduto [50];
    int continua_cadprod;
    int produtoID;

    //Variaveis Reclamacoes / Elogios

    int Elrecl;
    char nomeCliente [50];
    char telefoneCliente [50];
    char texto[50];
    char trtOcorrencia[50] = "Pendente";
    char tipoElogio[50] = "Elogio_Opiniao";
    char tipoReclamacao[50] = "Reclamacao";
    int IDocorrencia;
    char pizzaiolo [50];

//Intro-----------------------------------------------------------------------------------------------------------------------------------------------
int animacao = 0;

 printf("\n\n\n\n\n");
 printf("\t\t\t     ___           ___           ___           ___\n");
 printf("\t\t\t    /\\__\\         /\\__\\         /\\  \\         /\\  \\ \n");
 printf("\t\t\t   /:/ _/_       /:/ _/_       /::\\  \\       /::\\  \\ \n");
 printf("\t\t\t  /:/ /\\  \\     /:/ /\\  \\     /:/\\:\\  \\     /:/\\:\\__\\ \n");
 printf("\t\t\t /:/ /::\\  \\   /:/ /::\\  \\   /:/ /::\\  \\   /:/ /:/  /\n");
 printf("\t\t\t/:/_/:/\\:\\__\\ /:/__\\/\\:\\__\\ /:/_/:/\\:\\__\\ /:/_/:/  / \n");
 printf("\t\t\t\\:\\/:/ /:/  / \\:\\  \\ /:/  / \\:\\/:/  \\/__/ \\:\\/:/  / \n");
 printf("\t\t\t \\::/ /:/  /   \\:\\  /:/  /   \\::/__/       \\::/__/  \n");
 printf("\t\t\t  \\/_/:/  /     \\:\\/:/  /     \\:\\  \\        \\:\\  \\   \n");
 printf("\t\t\t    /:/  /       \\::/  /       \\:\\__\\        \\:\\__\\  \n");
 printf("\t\t\t    \\/__/         \\/__/         \\/__/         \\/__/\n");

// Animacao----------------------------------------------------------------------------------------------------------------------------------------------
Sleep(0700);
printf("\n");
for (animacao;animacao==0; animacao++){printf("\t\t\t-->");Sleep(0300);}
for (animacao;animacao==1; animacao++){printf("\r\t\t\tSi-->");Sleep(0300);}
for (animacao;animacao==2; animacao++){printf("\r\t\t\tSist-->");Sleep(0300);}
for (animacao;animacao==3; animacao++){printf("\r\t\t\tSistem-->");Sleep(0300);}
for (animacao;animacao==4; animacao++){printf("\r\t\t\tSistema --> ");Sleep(0300);}
for (animacao;animacao==5; animacao++){printf("\r\t\t\tSistema de-->");Sleep(0300);}
for (animacao;animacao==6; animacao++){printf("\r\t\t\tSistema de Ge-->");Sleep(0300);}
for (animacao;animacao==7; animacao++){printf("\r\t\t\tSistema de Gere-->");Sleep(0300);}
for (animacao;animacao==8; animacao++){printf("\r\t\t\tSistema de Gerenc-->");Sleep(0300);}
for (animacao;animacao==9; animacao++){printf("\r\t\t\tSistema de Gerencia-->");Sleep(0300);}
for (animacao;animacao==10; animacao++){printf("\r\t\t\tSistema de Gerenciame-->");Sleep(0300);}
for (animacao;animacao==11; animacao++){printf("\r\t\t\tSistema de Gerenciament-->");Sleep(0300);}
for (animacao;animacao==12; animacao++){printf("\r\t\t\tSistema de Gerenciamento -->");Sleep(0300);}
for (animacao;animacao==13; animacao++){printf("\r\t\t\tSistema de Gerenciamento e -->");Sleep(0300);}
for (animacao;animacao==14; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Ad-->");Sleep(0300);}
for (animacao;animacao==15; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Admi-->");Sleep(0300);}
for (animacao;animacao==16; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Admini-->");Sleep(0300);}
for (animacao;animacao==17; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administ-->");Sleep(0300);}
for (animacao;animacao==18; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administra-->");Sleep(0300);}
for (animacao;animacao==19; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administraçã-->", setlocale (LC_ALL, ""));Sleep(0300);}
for (animacao;animacao==20; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administração -->", setlocale (LC_ALL, ""));Sleep(0300);}
for (animacao;animacao==21; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administração de-->", setlocale (LC_ALL, ""));Sleep(0300);}
for (animacao;animacao==22; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administração de Pi-->", setlocale (LC_ALL, ""));Sleep(0300);}
for (animacao;animacao==23; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administração de Pizz-->", setlocale (LC_ALL, ""));Sleep(0300);}
for (animacao;animacao==24; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administração de Pizzar-->", setlocale (LC_ALL, ""));Sleep(0300);}
for (animacao;animacao==25; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administração de Pizzarias-->", setlocale (LC_ALL, ""));Sleep(0300);}
for (animacao;animacao==26; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administração de Pizzarias --", setlocale (LC_ALL, ""));Sleep(0300);}
for (animacao;animacao==26; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administração de Pizzarias  -", setlocale (LC_ALL, ""));Sleep(0300);}
for (animacao;animacao==27; animacao++){printf("\r\t\t\tSistema de Gerenciamento e Administração de Pizzarias   \n\n\n\n\n\n\n\n\n\n\n  ", setlocale (LC_ALL, ""));Sleep(0300);}

 system("pause");
 system("cls");

 //Usuario / Senha+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Usuario--------------------------------------------------------------------------------------------------------------------------------------

 do{
printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("----------------------", setlocale(LC_ALL,""));
        printf("\n\tLogin\n", setlocale(LC_ALL,""));
        printf("----------------------\n\n", setlocale(LC_ALL,""));
        printf("Usuário: ", setlocale (LC_ALL, ""));;
        gets(usuario);

char usuarioGerenciatemp [8] = "Gerencia";
char usuarioEstoqueTemp [7] = "Estoque";
char usuarioOperacionalTemp [11] = "Operacional";

if (strncmp(usuario, usuarioGerenciatemp, 8)==0){

        //usuario = 71;
        IDUsuario = 1;

}else if (strncmp(usuario, usuarioEstoqueTemp, 7)==0){

        //usuario = 72;
        IDUsuario = 2;

}else if (strncmp(usuario, usuarioOperacionalTemp, 11)==0){

        //usuario = 73;
        IDUsuario = 3;
}
mysql_init(&conexao);

        sprintf(query,"SELECT Usuario FROM senhas WHERE usuario = '%i' && ID = '%i';", usuario, IDUsuario );
       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
          if (mysql_query(&conexao,query))
          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);

                  printf("\n");
                  linhas=mysql_fetch_row(resp);
              }
              mysql_free_result(resp);
           }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }

        system("cls");

}while (linhas == NULL );
//Senha---------------------------------------------------------------------------------------------------------------------------------

contadorGerencia = 0;
do{
printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("----------------------", setlocale(LC_ALL,""));
        printf("\n\tLogin\n", setlocale(LC_ALL,""));
        printf("----------------------\n\n", setlocale(LC_ALL,""));
        contadorGerencia++;
        printf("Digite a senha: ");
        //scanf("%s", &senha);
        senha[0] = getch();
        printf ("*");
        senha[1] = getch();
        printf ("*");
        senha[2] = getch();
        printf ("*");
        senha[3] = getch();
        printf ("*");
        senha[4] = getch();
        printf ("*");
        senha[5] = getch();
        printf ("*");

mysql_init(&conexao);

        sprintf(query,"SELECT Senha FROM senhas WHERE senha = '%s' && ID = '%i';", senha, IDUsuario );
       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);

                  printf("\n");

                  linhas=mysql_fetch_row(resp);
              }
              mysql_free_result(resp);
            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }
        system("cls");

        if (contadorGerencia>3){

            break;
        }


}while (linhas == NULL );

if (contadorGerencia >3){

   exit(EXIT_SUCCESS);
}
// Capturar data para vendas--------------------------------------------------------------------------------------------------------------------------------------

    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

    printf("\nEntre com a data de hoje: ");

    scanf("%s",&data);
    getchar();
    int escolhaUnidade;
    printf("\nEm qual unidade esta operando?: ");

    gets(unidade);

if (strncmp(unidade, unidade_Freguesia, 9)==0){

IDSomaTotal = 1;
}else if (strncmp(unidade, unidade_Lapa, 4)==0){

IDSomaTotal = 2;
}else if (strncmp(unidade, unidade_Marques, 7)==0){

IDSomaTotal = 3;
}
system("cls");

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    while(1){//Chamada de repeticao do programa

    //Tela de entrada---------------------------------------------------------------------------------------------------------------
    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
    printf("------------------------------------------------\n");
    printf("Digite o número, referente a atividade desejada.  \n", setlocale (LC_ALL, "") );
    printf("------------------------------------------------\n");
    printf("\n1 - Cadastro de Clientes\n2 - Pedido\n3 - Gerência\n4 - Estoque\n5 - Cadastro de Produtos\n6 - Canal com Cliente\n ", setlocale (LC_ALL, "") );
    scanf("%i", &Opcao);
    getchar();
    system("cls");

    //Resetando valores para comando while
     continua_cadprod = 1;
     continua_estoque = 1;

    switch (Opcao)//Resposta de solitacao para int Opcao
    {

//Cadastro Cliente tela Principal---------------------------------------------------------------------------------------------------------------------------------
    case 1:

//Tela selecao de opcoes para Cadastro
    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

    printf("\n------------------------------------------------\n");
    printf("Digite o número, referente a atividade desejada.\n", setlocale (LC_ALL, "") );
    printf("------------------------------------------------\n");
    printf("\n1 - Cadastro de Cliente\n2 - Consulta de Cliente\n3 - Exclusão de Cliente\n", setlocale (LC_ALL, "") );
    scanf("%i", &cadastroEscolha);
    getchar();
    system("cls");
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Resposta de solitacao para int cadastroEscolha
        switch (cadastroEscolha){

//Cadastrar cliente------------------------------------------------------------------------------------------------------------------------------------

        case 1:

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("------------------------------------", setlocale(LC_ALL,""));
        printf("\n\tCadastro de Clientes\n", setlocale(LC_ALL,""));
        printf("------------------------------------\n\n", setlocale(LC_ALL,""));

        printf("Digite o nome: ");
        gets(nome);

        printf("Digite o telefone: ");
        gets(telefone);

        printf("Digite o endereco: ");
        gets(endereco);

        mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"INSERT INTO cadastro_cliente (Nome,Telefone, Endereco) values ('%s','%s','%s');", nome, telefone, endereco );

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }
        system ("pause");
        system("cls");
        break;

//Consulta de clientes--------------------------------------------------------------------------------------------------------------------------------------------------
        case 2:

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("------------------------------------", setlocale(LC_ALL,""));
        printf("\n\tConsulta de Clientes\n", setlocale(LC_ALL,""));
        printf("------------------------------------\n\n", setlocale(LC_ALL,""));
        printf("Digite o telefone, para localizar o cliente: ");
        scanf("%s", &telefoneBusca);
        mysql_init(&conexao);

        sprintf(query,"SELECT ID, Nome, Telefone, Endereco FROM cadastro_cliente WHERE Telefone = '%s';", telefoneBusca );
       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);

                 printf("\n");

                  while ((linhas=mysql_fetch_row(resp)) != NULL)
                  {
                     for (conta=0;conta<mysql_num_fields(resp);conta++)
                        printf("%s\t\n",linhas[conta]);
                     printf("\n");
                  }
              }
             mysql_free_result(resp);

            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }
        system ("pause");
        system("cls");
        break;
//Excluir cliente-------------------------------------------------------------------------------------------------------------------------------------
        case 3:

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("------------------------------------", setlocale(LC_ALL,""));
        printf("\n\tExclusão de Clientes\n", setlocale(LC_ALL,""));
        printf("------------------------------------\n\n", setlocale(LC_ALL,""));
        printf("Digite o telefone, para localizar e excluir dados: ");
        scanf("%s", &telefoneBusca);
        mysql_init(&conexao);

         if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");
            sprintf(query,"DELETE FROM cadastro_cliente WHERE Telefone = '%s';", telefoneBusca);

              res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }
        system ("pause");
        system("cls");
        break;
          }
break;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //Vendas-------------------------------------------------------------------------------------------------------------------------------------------------
   case 2:
    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

   printf("\n**************************************************************************************************************\n");
   printf("Promocao do dia: ", setlocale (LC_ALL, ""));

    mysql_init(&conexao);

                    sprintf(query,"SELECT Texto FROM promocao WHERE Data = '%s' && Unidade = '%s';", data, unidade);

                   if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
                   {

                      if (mysql_query(&conexao,query))
                         printf("Erro: %s\n",mysql_error(&conexao));
                      else
                      {
                         resp = mysql_store_result(&conexao);
                        if (resp)
                        {
                           /*campos = mysql_fetch_fields(resp);
                           for (conta=0;conta<mysql_num_fields(resp);conta++) {
                              printf("%s",(campos[conta]).name);
                              if (mysql_num_fields(resp)>1)
                                  printf("\t");
                              }*/

                              while ((linhas=mysql_fetch_row(resp)) != NULL)
                              {
                                 for (conta=0;conta<mysql_num_fields(resp);conta++)
                                    printf("%s",linhas[conta]);
                              }
                          }
                          mysql_free_result(resp);
                        }
                        mysql_close(&conexao);
                   }
                   else
                   {
                      printf("Conexao Falhou\n");
                      if (mysql_errno(&conexao))
                         printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                   }

  printf("\n**************************************************************************************************************\n");

   printf("------------------------------------------------\n");
   printf("Digite o número, referente a atividade desejada.\n", setlocale (LC_ALL, "") );
   printf("------------------------------------------------\n");
   printf("\n1 - Venda Presencial\n2 - Venda para Entrega\n3 - Sair\n", setlocale (LC_ALL, "") );
   scanf("%i", &venda);
   getchar();
   system("cls");

    switch (venda){
//Venda Presencial----------------------------------------------------------------------------------------------------------------------------------------------
        case 1:

        while(2){

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("\n-------------------------------------------------------------------\n");
        printf("Escolha o código a ser inserido, de acordo com o produto escolhido\n", setlocale (LC_ALL, "") );
        printf("-------------------------------------------------------------------\n");

//Conexao com banco de dados de produtos cadastrados----------------------------------------------------------------------------------------------------------------------------

        mysql_init(&conexao);

            sprintf(query,"SELECT ID, valor, Produto FROM cadastro_produtos WHERE Unidade = '%s';", unidade);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                  /* campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/
                      printf("ID     Valor    Produto");

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            printf("%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }
//Fim da conexao-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        printf("\n\nDigite o código: ");
        scanf("%i",&produto);
        getchar();

        char Nome_produto [50];
        //printf("%.2f", valorSomaTotal);
        //system("pause");

//Captando valor do produto no banco---------------------------------------------------------------------------------------------------------------
 mysql_init(&conexao);

            sprintf(query,"SELECT valor FROM cadastro_produtos WHERE ID = %i;",produto);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   /*campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(valorBanco,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

valor = atof(valorBanco);
sprintf(valorBanco, "%.2f", valor);
valorSomaPedido= valorSomaPedido + valor;

// Conecta banco de dados para verificar string promocao-----------------------------------------------------------------------------------------------------

  mysql_init(&conexao);

            sprintf(query,"SELECT Produto FROM cadastro_produtos WHERE ID = %i;",produto);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   /*campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(Nome_produto,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }
//Verifica promocao e efetua calculo-------------------------------------------------------------------------------------------------------------
if (strncmp(Nome_produto, promocaotelavenda, 8)==0){
system("cls");
        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("\nEntre com o valor a ser deduzido(Promoção): ");
        scanf("%f", &promocaovenda);

 valorSomaPedido= valorSomaPedido - promocaovenda;
 valor = promocaovenda;
 sprintf(valorBanco, "%.2f", valor);

}else{}


//----------------------------------------------------------------------
// Conectando no banco para pegar um valor para atribuir a variavel-----------------------------------------------------------------------------------------

        mysql_init(&conexao);

            sprintf(query,"SELECT ID, Produto FROM cadastro_produtos WHERE ID = %i;",produto);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   /*campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(Nome_produto,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

//Conectando banco estoque paar atualizar quantidades produtos-----------------------------------------------------

            sprintf(query,"SELECT quantidade FROM item WHERE ID = '%i';",produto);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                  /* campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(valorTotalTemp,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

valorSomaTotal = atof(valorTotalTemp);
valorSomaTotal = valorSomaTotal - 1;

sprintf(valorTotalTemp,"%.0f", valorSomaTotal);

valorSomaTotal = 0;

//Atualizar quantidade no banco de dados estoque---------------------------------------------------------

mysql_init(&conexao);

             if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
            {
                printf("conectado com sucesso!\n");

                sprintf(query,"UPDATE item SET quantidade = '%s' WHERE ID = '%i';", valorTotalTemp,produto);
                  res = mysql_query(&conexao,query);
                if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

            mysql_close(&conexao);
            }
            else
            {
            printf("Falha de conexao\n");
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
            }
 //--------------------------------------------
        mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"INSERT INTO vendas (Produto,Valor,Data,Unidade,Nome_produto) values ('%i','%s','%s','%s','%s');", produto, valorBanco, data, unidade,Nome_produto);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }
        mysql_init(&conexao);

          if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"INSERT INTO vendasbd (Produto,Valor,Data,Unidade,Nome_produto) values ('%i','%s','%s','%s','%s');", produto, valorBanco, data, unidade,Nome_produto);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }

        system("cls");
//Escolha para continuar a inserir produtos no Pedido-----------------------------------------------------------------------------------------------------------------------------
       printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("------------------");
        printf("\nDeseja continuar?\n1 para sim\n2 para não\n", setlocale (LC_ALL, "") );
        printf("------------------\n");
        scanf("%i", &continuaVenda);
        getchar();

        if (continuaVenda!=1){
        system("cls");
        break;

        }else{}
        system("cls");

        }

//Nota com o pedido----------------------------------------------------------------------------------------------------------------------------------------------------------------
        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("----------------");
        printf("\nPedido Efetuado\n", setlocale (LC_ALL, "") );
        printf("----------------\n");

        mysql_init(&conexao);

            sprintf(query,"SELECT Valor, Nome_produto FROM vendas;");

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }
                      printf("\n");

                      while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            printf("%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

           printf("\nR$%.2f\n\n", valorSomaPedido);

   system ("pause");
   //Deletando dados temporarios------------------------------------------------------------------------------------------------------------------------------------------------------

           mysql_init(&conexao);

                 if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
                {
                    printf("conectado com sucesso!\n");

                    sprintf(query,"DELETE FROM vendas;");

                      res = mysql_query(&conexao,query);
                    if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                    else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

                mysql_close(&conexao);
                }
                else
                {
                printf("Falha de conexao\n");
                printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                }

                system("cls");

//Capta e Guarda valor total de vendas--------------------------------------------------------------------------------------------------------------------------------------------------------

             mysql_init(&conexao);

            sprintf(query,"SELECT Valor FROM SomaValorTotal WHERE ID = '%i';",IDSomaTotal);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                  /* campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(valorTotalTemp,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }
valorSomaTotal = atof(valorTotalTemp);

//--------------------------------------------
   valorSomaTotal= valorSomaPedido + valorSomaTotal;
   valorSomaPedido = 0;
   char valorSomaTotalTemp [50];
   sprintf(valorSomaTotalTemp, "%.2f", valorSomaTotal);
   valorSomaTotal = 0;
//--------------------------------------------------------
     mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"UPDATE SomaValorTotal SET Valor = '%s' WHERE ID = '%i';",  valorSomaTotalTemp, IDSomaTotal);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }

        system("cls");
        break;
//Venda Entrega----------------------------------------------------------------------------------------------------------------------------------------------
        case 2:

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("\n----------------------------------------------\n");
        printf("Entre com o telefone, para localizar o cliente \n", setlocale (LC_ALL, "") );
        printf("----------------------------------------------\n");

        scanf("%s", &telefoneBusca);
        mysql_init(&conexao);

mysql_init(&conexao);

        sprintf(query,"SELECT Telefone FROM cadastro_cliente WHERE Telefone = '%s';", telefoneBusca );
       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);

                  printf("\n");

                  linhas=mysql_fetch_row(resp);
              }
              mysql_free_result(resp);
            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }

if (linhas == NULL){
    printf("*********************************\n", setlocale (LC_ALL, ""));
    printf("*Telefone não localizado.       *\n", setlocale (LC_ALL, ""));
    printf("*Efetue o  cadastro do cliente, *\n", setlocale (LC_ALL, ""));
    printf("*para dar continuidade ao pedido*\n", setlocale (LC_ALL, ""));
    printf("*********************************\n\n\n\n\n\n", setlocale (LC_ALL, ""));
    system("pause");
    system("cls");
    break;

}else

sprintf(query,"SELECT Nome, Telefone, Endereco FROM cadastro_cliente WHERE Telefone = '%s';", telefoneBusca );
       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);

                 printf("\n");

                  while ((linhas=mysql_fetch_row(resp)) != NULL)
                  {
                     for (conta=0;conta<mysql_num_fields(resp);conta++)
                        printf("%s\t\n",linhas[conta]);
                     printf("\n");
                  }
              }
             mysql_free_result(resp);

            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }

       system("pause");
       system("cls");

 while(2){

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("\n-------------------------------------------------------------------\n");
        printf("Escolha o código a ser inserido, de acordo com o produto escolhido\n", setlocale (LC_ALL, "") );
        printf("-------------------------------------------------------------------\n");

//Conexao com banco de dados de produtos cadastrados----------------------------------------------------------------------------------------------------------------------------

        mysql_init(&conexao);

            sprintf(query,"SELECT ID, valor, Produto FROM cadastro_produtos WHERE Unidade = '%s';", unidade);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                  /* campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/
                      printf("ID     Valor    Produto");

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            printf("%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }
//Fim da conexao-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        printf("\n\nDigite o código: ");
        scanf("%i",&produto);
        getchar();

        char Nome_produto [50];
        //printf("%.2f", valorSomaTotal);
        //system("pause");

//Captando valor do produto no banco---------------------------------------------------------------------------------------------------------------
 mysql_init(&conexao);

            sprintf(query,"SELECT valor FROM cadastro_produtos WHERE ID = %i;",produto);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   /*campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(valorBanco,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

valor = atof(valorBanco);
sprintf(valorBanco, "%.2f", valor);
valorSomaPedido= valorSomaPedido + valor;

// Conecta banco de dados para verificar string promocao-----------------------------------------------------------------------------------------------------

  mysql_init(&conexao);

            sprintf(query,"SELECT Produto FROM cadastro_produtos WHERE ID = %i;",produto);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   /*campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(Nome_produto,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }
//Verifica promocao e efetua calculo-------------------------------------------------------------------------------------------------------------
if (strncmp(Nome_produto, promocaotelavenda, 8)==0){
system("cls");
        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("\nEntre com o valor a ser deduzido(Promoção): ");
        scanf("%f", &promocaovenda);

 valorSomaPedido= valorSomaPedido - promocaovenda;
 valor = promocaovenda;
 sprintf(valorBanco, "%.2f", valor);

}else{}


//----------------------------------------------------------------------
// Conectando no banco para pegar um valor para atribuir a variavel-----------------------------------------------------------------------------------------

        mysql_init(&conexao);

            sprintf(query,"SELECT ID, Produto FROM cadastro_produtos WHERE ID = %i;",produto);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   /*campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(Nome_produto,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

//Conectando banco estoque paar atualizar quantidades produtos-----------------------------------------------------

            sprintf(query,"SELECT quantidade FROM item WHERE ID = '%i';",produto);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                  /* campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(valorTotalTemp,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

valorSomaTotal = atof(valorTotalTemp);
valorSomaTotal = valorSomaTotal - 1;

sprintf(valorTotalTemp,"%.0f", valorSomaTotal);

valorSomaTotal = 0;

//Atualizar quantidade no banco de dados estoque---------------------------------------------------------

mysql_init(&conexao);

             if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
            {
                printf("conectado com sucesso!\n");

                sprintf(query,"UPDATE item SET quantidade = '%s' WHERE ID = '%i';", valorTotalTemp,produto);
                  res = mysql_query(&conexao,query);
                if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

            mysql_close(&conexao);
            }
            else
            {
            printf("Falha de conexao\n");
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
            }
 //--------------------------------------------
        mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"INSERT INTO vendas (Produto,Valor,Data,Unidade,Nome_produto) values ('%i','%s','%s','%s','%s');", produto, valorBanco, data, unidade,Nome_produto);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }
        mysql_init(&conexao);

          if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"INSERT INTO vendasbd (Produto,Valor,Data,Unidade,Nome_produto) values ('%i','%s','%s','%s','%s');", produto, valorBanco, data, unidade,Nome_produto);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }

        system("cls");
//Escolha para continuar a inserir produtos no Pedido-----------------------------------------------------------------------------------------------------------------------------
       printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("------------------");
        printf("\nDeseja continuar?\n1 para sim\n2 para não\n", setlocale (LC_ALL, "") );
        printf("------------------\n");
        scanf("%i", &continuaVenda);
        getchar();

        if (continuaVenda!=1){
        system("cls");
        break;

        }else{}
        system("cls");

        }

//Nota com o pedido----------------------------------------------------------------------------------------------------------------------------------------------------------------
        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("----------------");
        printf("\nPedido Efetuado\n", setlocale (LC_ALL, "") );
        printf("----------------\n");

       sprintf(query,"SELECT Nome, Telefone, Endereco FROM cadastro_cliente WHERE Telefone = '%s';", telefoneBusca );
       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);

                 printf("\n");

                  while ((linhas=mysql_fetch_row(resp)) != NULL)
                  {
                     for (conta=0;conta<mysql_num_fields(resp);conta++)
                        printf("%s\t\n",linhas[conta]);
                     printf("\n");
                  }
              }
             mysql_free_result(resp);

            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }

       printf("\n");

        mysql_init(&conexao);

            sprintf(query,"SELECT Valor, Nome_produto FROM vendas;");

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }
                      printf("\n");

                      while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            printf("%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

           printf("\nR$%.2f\n\n", valorSomaPedido);

   system ("pause");
   //Deletando dados temporarios------------------------------------------------------------------------------------------------------------------------------------------------------

           mysql_init(&conexao);

                 if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
                {
                    printf("conectado com sucesso!\n");

                    sprintf(query,"DELETE FROM vendas;");

                      res = mysql_query(&conexao,query);
                    if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                    else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

                mysql_close(&conexao);
                }
                else
                {
                printf("Falha de conexao\n");
                printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                }

                system("cls");

//Capta e Guarda valor total de vendas--------------------------------------------------------------------------------------------------------------------------------------------------------

             mysql_init(&conexao);

            sprintf(query,"SELECT Valor FROM SomaValorTotal WHERE ID = '%i';",IDSomaTotal);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                  /* campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(valorTotalTemp,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }
valorSomaTotal = atof(valorTotalTemp);

//--------------------------------------------
   valorSomaTotal= valorSomaPedido + valorSomaTotal;
   valorSomaPedido = 0;
   //char valorSomaTotalTemp [50];
   sprintf(valorSomaTotalTemp, "%.2f", valorSomaTotal);
   valorSomaTotal = 0;
//--------------------------------------------------------
     mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"UPDATE SomaValorTotal SET Valor = '%s' WHERE ID = '%i';",  valorSomaTotalTemp, IDSomaTotal);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }
   }
system("cls");
break;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    case 3:

//Acesso Usuario Gerencia--------------------------------------------------------------------------------------------------------------------------------------


//Senha---------------------------------------------------------------------------------------------------------------------------------
contadorGerencia = 0;
do{
printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("----------------------", setlocale(LC_ALL,""));
        printf("\n\tLogin\n", setlocale(LC_ALL,""));
        printf("----------------------\n\n", setlocale(LC_ALL,""));
        contadorGerencia++;
        printf("Digite a senha: ");
        //scanf("%s", &senha);
        senha[0] = getch();
        printf ("*");
        senha[1] = getch();
        printf ("*");
        senha[2] = getch();
        printf ("*");
        senha[3] = getch();
        printf ("*");
        senha[4] = getch();
        printf ("*");
        senha[5] = getch();
        printf ("*");

mysql_init(&conexao);

        sprintf(query,"SELECT Senha FROM senhas WHERE senha = '%s' && ID = 1;", senha, IDUsuario );
       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);

                  printf("\n");

                  linhas=mysql_fetch_row(resp);
              }
              mysql_free_result(resp);
            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }
        system("cls");

        if (contadorGerencia>3){

            break;
        }
}while (linhas == NULL );

if (contadorGerencia >3){

   break;
}
//Gerencia-------------------------------------------------------------------------------------------------------------------------------------------
    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

    printf("-------------------------\n");
    printf("Escolha a opção desejada\n", setlocale (LC_ALL, "") );
    printf("-------------------------\n");
    printf("1 - Unidades\n2 - Cancelar Venda\n3 - Senhas\n4 - Promoção\n5 - Sair\n", setlocale (LC_ALL, ""));
    scanf("%i", &gerencia);
    getchar();

    system("cls");

    switch(gerencia){
//Unidades-------------------------------------------------------------------------------------------------------------------------------------------
    case 1:

//Unidades -----------------------------------------------------------------------------------------------------------------------------------------

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("******************************************\n");
        printf("O sistema irá filtrar os dados, de acordo\n", setlocale (LC_ALL, "") );
        printf("com a data ou periodo informado.\n");
        printf("******************************************\n\n");

        printf("-----------------------------");
        printf("\nEntre com o nome da unidade.\n");
        printf("-----------------------------\n\n");

        gets(unidadegerencia);

        printf("-------------------------------------");
        printf("\nEntre com a data ou periodo desejado.\n");
        printf("-------------------------------------\n\n");

        printf("Data inicial:");
        gets (dataGerencia);

        printf("\nData final:");
       gets(dataGerencia1);

        system ("cls");

    //Conexao com banco de dados de produtos cadastrados----------------------------------------------------------------------------------------------------------------------------
        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

//Conexao com o banco de dados de vendasbd------------------------------------------------------------------------------------

        mysql_init(&conexao);

        sprintf(query,"SELECT Valor, Data, Produto, Nome_Produto FROM vendasbd WHERE Data BETWEEN '%s' AND '%s' && Unidade = '%s' ORDER BY Data;", dataGerencia, dataGerencia1, unidadegerencia);
        //sprintf(query,"SELECT ID, Valor, Produto FROM produto WHERE Data = '%s';", dataGerencia);

       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
         printf("------------\n", setlocale(LC_ALL,""));
         printf("Venda Geral\n", setlocale(LC_ALL,""));
         printf("------------\n", setlocale(LC_ALL,""));

          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);
               //for (conta=0;conta<mysql_num_fields(resp);conta++) {
               //   printf("%s",(campos[conta]).name);
              //    if (mysql_num_fields(resp)>1)
               //       printf("\t");
              //    }

                  printf("\n");
                  printf("Valor   Produto         ID      Produto\n");

                  while ((linhas=mysql_fetch_row(resp)) != NULL)
                  {
                     for (conta=0;conta<mysql_num_fields(resp);conta++)
                        printf("%s\t",linhas[conta]);
                     printf("\n");
                  }
              }
              mysql_free_result(resp);
            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }printf("\n");

//Fim da conexao-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//Contador do numero de vendas---------------------------------------------------------------------------------------------------------------------------------

       mysql_init(&conexao);
       printf("\nQuantidade de vendas (Geral): ");
       sprintf(query,"SELECT COUNT(Valor) FROM vendasbd WHERE Data BETWEEN '%s' AND '%s' && Unidade = '%s' ORDER BY Data;", dataGerencia, dataGerencia1, unidadegerencia);

        if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {

          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);
               for (conta=0;conta<mysql_num_fields(resp);conta++) {
                  printf("%s",(campos[conta]).name);
                  if (mysql_num_fields(resp)>1)
                      printf("\t");
                  }
                  printf("\n");

                  while ((linhas=mysql_fetch_row(resp)) != NULL)
                  {
                     for (conta=0;conta<mysql_num_fields(resp);conta++)
                        printf("%s\t",linhas[conta]);
                     printf("\n");
                  }
              }
              mysql_free_result(resp);
            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }
        //system("calc");

//Verificar numero de vendas porr produto-------------------------------------------------------------------------------------------------------------------------------

printf("------------------------------------------------------");
printf("\nDeseja verificar quantidade de vendas por produto?:\n1 para sim\n2 para não\n", setlocale (LC_ALL, "") );
printf("------------------------------------------------------\n");
        scanf("%i", &fechaBalanco);
        getchar();

        if (fechaBalanco==1){

        fechaBalanco = NULL;

        system("cls");

//Conexao com banco de dados de produtos cadastrados----------------------------------------------------------------------------------------------------------------------------
      do{
printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

            printf("\n\nLegenda de Produtos\n", setlocale(LC_ALL,""));
            printf("-------------------------\n", setlocale(LC_ALL,""));

            mysql_init(&conexao);

                sprintf(query,"SELECT ID, Produto FROM cadastro_produtos WHERE Unidade = '%s';", unidadegerencia);

               if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
               {

                  if (mysql_query(&conexao,query))
                     printf("Erro: %s\n",mysql_error(&conexao));
                  else
                  {
                     resp = mysql_store_result(&conexao);
                    if (resp)
                    {
                       campos = mysql_fetch_fields(resp);
                       for (conta=0;conta<mysql_num_fields(resp);conta++) {
                          printf("%s",(campos[conta]).name);
                          if (mysql_num_fields(resp)>1)
                              printf("\t");
                          }
                          printf("\n");

                          while ((linhas=mysql_fetch_row(resp)) != NULL)
                          {
                             for (conta=0;conta<mysql_num_fields(resp);conta++)
                                printf("%s\t",linhas[conta]);
                             printf("\n");
                          }
                      }
                      mysql_free_result(resp);
                    }
                    mysql_close(&conexao);
               }
               else
               {
                  printf("Conexao Falhou\n");
                  if (mysql_errno(&conexao))
                     printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
               }printf("\n");
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
        char produtochar [50];
        printf("\nDigite o código do produto: ", setlocale(LC_ALL,""));
        scanf("%i", &produto);
        getchar();

        sprintf(produtochar, "%i", produto);

        mysql_init(&conexao);
       printf("\nQuantidade de vendas: ");
       sprintf(query,"SELECT COUNT(Valor) FROM vendasbd WHERE Data BETWEEN '%s' AND '%s' && Produto = '%s' && Unidade = '%s';", dataGerencia, dataGerencia1, produtochar, unidadegerencia);

        if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {

          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);
               for (conta=0;conta<mysql_num_fields(resp);conta++) {
                  printf("%s",(campos[conta]).name);
                  if (mysql_num_fields(resp)>1)
                      printf("\t");
                  }
                  printf("\n");

                  while ((linhas=mysql_fetch_row(resp)) != NULL)
                  {
                     for (conta=0;conta<mysql_num_fields(resp);conta++)
                        printf("%s\t",linhas[conta]);
                     printf("\n");
                  }
              }
              mysql_free_result(resp);
            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }

       printf("------------------------------------------------------");
       printf("\nDeseja continuar a verificar a quantidade de vendas?:\n1 para sim\n2 para não\n", setlocale (LC_ALL, "") );
       printf("------------------------------------------------------");
       scanf("%i", &finaliza);

       if(finaliza == 1){

        system("cls");

       }

       }while (finaliza == 1 );
       }else{ }
        fechaBalanco = NULL;

//Calcular Valor total-------------------------------------------------------------------------------------------------------------------------------------
system("cls");
printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        if ( strcmp (data, dataGerencia)==0 && strcmp (unidade, unidadegerencia)==0){
//Conexao banco de dados para levantar valor com caixa aberto.------------------------------------------------

    mysql_init(&conexao);

            sprintf(query,"SELECT Valor FROM SomaValorTotal WHERE ID = '%i';",IDSomaTotal);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(valorTotalTemp,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

//-----------------------------------------------------------------------
        printf("\nTotal de vendas (Caixa Aberto)\n");

        printf("R$ %s", valorTotalTemp);

//Busca valor total de vendas no Banco de dados-----------------------------------------------------------------------------------------------------------------
printf("\nTotal de vendas (Caixa fechado)\n");

        mysql_init(&conexao);
                    sprintf(query,"SELECT Data, Valor FROM resultados_de_venda WHERE Data BETWEEN '%s' AND '%s' && Unidade = '%s';", dataGerencia, dataGerencia1, unidadegerencia);
                   // sprintf(query,"SELECT Valor FROM resultados_de_venda WHERE Data = '%s';", dataGerencia);

                   if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
                   {

                      if (mysql_query(&conexao,query))
                         printf("Erro: %s\n",mysql_error(&conexao));
                      else
                      {
                         resp = mysql_store_result(&conexao);
                        if (resp)
                        {

                        while ((linhas=mysql_fetch_row(resp)) != NULL)
                              {
                                 for (conta=0;conta<mysql_num_fields(resp);conta++)
                                    printf("%s\t",linhas[conta]);
                                 printf("\n");
                              }
                          }
                          mysql_free_result(resp);
                        }
                        mysql_close(&conexao);
                   }
                   else
                   {
                      printf("Conexao Falhou\n");
                      if (mysql_errno(&conexao))
                         printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                   }
//Armazenamento de dados do balanco-----------------------------------------------------------------------------------------------------------------------------------------
        printf("------------------------------------------------------");
        printf("\nDeseja fechar o caixa?:\n1 para sim\n2 para não\n", setlocale (LC_ALL, "") );
        printf("------------------------------------------------------\n");
        scanf("%i", &fechaBalanco);
        getchar();

        if (fechaBalanco!=1){
        system("cls");
        fechaBalanco = NULL;
        break;

        }else{ }
        fechaBalanco = NULL;

        printf("%s", valorTotalTemp);

        mysql_init(&conexao);

            if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
            {
                printf("conectado com sucesso!\n");

                sprintf(query,"INSERT INTO resultados_de_venda (Data,Valor,Unidade) values ('%s','%s','%s');",  dataGerencia, valorTotalTemp, unidadegerencia);

                res = mysql_query(&conexao,query);
                if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

            mysql_close(&conexao);
            }
            else
            {
            printf("Falha de conexao\n");
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
            }

            system("cls");

//Zera valor de vendas total no banco de dados-----------------------------------------------------------------------------------------------------------------
        char zeravalorTotalTemp [50] = "0";

        mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"UPDATE SomaValorTotal SET Valor = '%s' WHERE ID = '%i';",  zeravalorTotalTemp, IDSomaTotal);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }

system ("pause");
        system("cls");

//---------------------------------------------------------------------
            break;
        }else
//Busca valor total de vendas no Banco de dados-----------------------------------------------------------------------------------------------------------------
        printf("\nTotal de vendas");

        mysql_init(&conexao);

                    sprintf(query,"SELECT Data, Valor FROM resultados_de_venda WHERE Data BETWEEN '%s' AND '%s' && Unidade = '%s';", dataGerencia, dataGerencia1, unidadegerencia);

                   if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
                   {

                      if (mysql_query(&conexao,query))
                         printf("Erro: %s\n",mysql_error(&conexao));
                      else
                      {
                         resp = mysql_store_result(&conexao);
                        if (resp)
                        {
                          /* campos = mysql_fetch_fields(resp);
                           for (conta=0;conta<mysql_num_fields(resp);conta++) {
                              printf("%s",(campos[conta]).name);
                              if (mysql_num_fields(resp)>1)
                                  printf("\t");
                              }*/

                              printf("\n");

                              while ((linhas=mysql_fetch_row(resp)) != NULL)
                              {
                                 for (conta=0;conta<mysql_num_fields(resp);conta++)
                                    printf("%s\t",linhas[conta]);
                                 printf("\n");
                              }
                          }
                          mysql_free_result(resp);
                        }
                        mysql_close(&conexao);
                   }
                   else
                   {
                      printf("Conexao Falhou\n");
                      if (mysql_errno(&conexao))
                         printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                   }
//Fim-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                  system("pause");
                  system("cls");
        break;

//Cancelar Venda-------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case 2:

    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
    printf("-------------------------------------\n");
    printf("Entre com a data que deseja consultar");
    printf("\n-------------------------------------\n");

    scanf("%s", &dataGerencia);
    getchar();
    system("cls");

for(;finalCancelamento == 1;){

    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
    printf("-------------------------------------\n");
    printf("Entre com a data que deseja consultar");
    printf("\n-------------------------------------\n");

//Consulta dados do banco

        mysql_init(&conexao);

        sprintf(query,"SELECT ID, Produto, Valor, Data FROM vendasbd WHERE Data = '%s' && Unidade = '%s';", dataGerencia, unidade);

       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {

         printf("Venda Geral\n", setlocale(LC_ALL,""));

          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);


                  printf("\n");
                  printf("ID    Produto   Valor     Data\n");

                  while ((linhas=mysql_fetch_row(resp)) != NULL)
                  {
                     for (conta=0;conta<mysql_num_fields(resp);conta++)
                        printf("%s\t",linhas[conta]);
                     printf("\n");
                  }
              }
              mysql_free_result(resp);
            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }printf("\n");


        printf("--------------------------------");
        printf("\nDeseja efetuar o cancelamento?\n1 para sim\n2 para não\n", setlocale (LC_ALL, "") );
        printf("--------------------------------\n");
        scanf("%i", &escolha_Cancelarvenda);
        getchar();

        if (escolha_Cancelarvenda!=1){
        system("cls");
        break;

        }else{ }
        printf("\n");

//Levanta dados para efetuar procedimento de cancelamento de venda ---------------------------------------------------------------------------

            printf("--------------------------------------------\n");
            printf("Entre com o número de identificação da venda\n", setlocale(LC_ALL,""));
            printf("--------------------------------------------\n");
            scanf("%i",&cancelarVenda);
            getchar();

//Captar valor bd vendabd---------------------------------------------------------------------------------------------------------------

mysql_init(&conexao);

            sprintf(query,"SELECT valor FROM vendasbd WHERE ID = %i;",cancelarVenda);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   /*campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(valorBanco,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

valor = atof(valorBanco);

//CApta valor no bd somavalortotal, faz o calculo e atualiza------------------------------------------------------------------------------------------
            mysql_init(&conexao);

            sprintf(query,"SELECT Valor FROM SomaValorTotal WHERE ID = '%i';",IDSomaTotal);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                  /* campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t");
                      }*/

                      printf("\n");
                     while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            //guardando resultado da query em um char
                            sprintf(valorTotalTemp,"%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }
valorSomaTotal = atof(valorTotalTemp);

//--------------------------------------------
   valorSomaTotal= valorSomaTotal - valor;
   valorSomaPedido = 0;
   char valorCancelado [50];
   sprintf(valorCancelado, "%.2f", valorSomaTotal);
   valorSomaTotal = 0;
   valor = 0;
//--------------------------------------------------------
     mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"UPDATE SomaValorTotal SET Valor = '%s' WHERE ID = '%i';",  valorCancelado, IDSomaTotal);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }

        system("cls");

//-----------------------------------------------------------------------

               mysql_init(&conexao);

             if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
            {
                printf("conectado com sucesso!\n");

                sprintf(query,"DELETE FROM vendasbd WHERE ID = '%i';", cancelarVenda);

                  res = mysql_query(&conexao,query);
                if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

            mysql_close(&conexao);
            }
            else
            {
            printf("Falha de conexao\n");
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
            }


            system("cls");

    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

            printf("\n----------------\n");
            printf("Pedido cancelado\n", setlocale(LC_ALL,""));
            printf("----------------\n\n\n");

            printf("------------------------------------");
            printf("\nDeseja cancelar mais alguma venda?\n1 para sim\n2 para não\n", setlocale (LC_ALL, "") );
            printf("------------------------------------\n");
            scanf("%i", &finalCancelamento);
            getchar();

            system("cls");

    }
break;
//Alterar Senhas-------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case 3:

printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

            printf("-----------------------------------------");
            printf("\nQual o tipo de senha que deseja alterar?\n-----------------------------------------\n1 - Gerencial\n2 - Operacional\n3 - Estoque\n4 - Sair\n");
            scanf("%i",&IDSenha);

            if (IDSenha > 3){

                system("cls");
                break;
            }

            //printf("%i",IDSenha);

            printf("\nDigite a Senha: ");
            scanf("%s",&tipoSenha);
            getchar();

             mysql_init(&conexao);

                 if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
                {
                    printf("conectado com sucesso!\n");

                    sprintf(query,"UPDATE senhas SET Senha = '%s' WHERE ID = '%i';",  tipoSenha, IDSenha);

                      res = mysql_query(&conexao,query);
                    if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                    else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

                mysql_close(&conexao);
                }
                else
                {
                printf("Falha de conexao\n");
                printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                }
                system ("pause");
                system("cls");
                break;
//Promocao---------------------------------------------------------------------------------------------------------------------------
        case 4:

    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

    printf("------------------------\n");
    printf("Escolha a opção desejada", setlocale (LC_ALL, "") );
    printf("\n------------------------\n");

    printf("\n1 - Cadastrar promoção\n2 - Consultar promoções\n", setlocale (LC_ALL, "") );
    scanf("%i", &escolhaPromocao);
    getchar();

    system ("cls");

    if(escolhaPromocao == 1){

    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

    printf("------------------------------------------------\n");
    printf("Deseja inserir uma promoção para a data de hoje?", setlocale (LC_ALL, "") );
    printf("\n------------------------------------------------\n");

    printf("\n1 - Sim\n2 - Não\n");
    scanf("%i", &escolhaPromocao);
    getchar();

        if (escolhaPromocao!=1){
        system("cls");
        break;

        }else{ }

    printf("------------------------------------------------------\n");
    printf("Informe, em poucas palavras, a promoção a ser aplicada", setlocale (LC_ALL, "") );
    printf("\n------------------------------------------------------\n\n");

    gets(promocao);
    char dataPromocao [50];
    dataPromocao [0] = data [0];
    dataPromocao [1] = data [1];
    dataPromocao [2] = data [2];
    dataPromocao [3] = data [3];
    dataPromocao [4] = data [4];
    dataPromocao [5] = data [5];
    dataPromocao [6] = data [6];
    dataPromocao [7] = data [7];
    dataPromocao [8] = data [8];
    dataPromocao [9] = data [9];

         mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"INSERT INTO promocao (Data,Unidade,Texto) values ('%s','%s','%s');", dataPromocao, unidade,promocao);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }
        escolha_estoque = 0;
        system ("cls");

        break;
    }else if (escolhaPromocao == 2){

    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

    printf("--------------------------------------\n");
    printf("Informe a data (ou intervalo de datas)\nque deseja consultar a promoção.", setlocale (LC_ALL, "") );
    printf("\n--------------------------------------\n");

    printf("\nData inicial:");
    scanf("%s", &dataGerencia);
    getchar();

    printf("\nData Final:");
    scanf("%s", &dataGerencia1);
    getchar();

     mysql_init(&conexao);

                    sprintf(query,"SELECT Data, Texto FROM promocao WHERE Data BETWEEN '%s' AND '%s' && Unidade = '%s';", dataGerencia, dataGerencia1, unidade);

                   if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
                   {

                      if (mysql_query(&conexao,query))
                         printf("Erro: %s\n",mysql_error(&conexao));
                      else
                      {
                         resp = mysql_store_result(&conexao);
                        if (resp)
                        {
                           /*campos = mysql_fetch_fields(resp);
                           for (conta=0;conta<mysql_num_fields(resp);conta++) {
                              printf("%s",(campos[conta]).name);
                              if (mysql_num_fields(resp)>1)
                                  printf("\t");
                              }*/

                              printf("\n");

                              while ((linhas=mysql_fetch_row(resp)) != NULL)
                              {
                                 for (conta=0;conta<mysql_num_fields(resp);conta++)
                                    printf("%s\t",linhas[conta]);
                                 printf("\n");
                              }
                          }
                          mysql_free_result(resp);
                        }
                        mysql_close(&conexao);
                   }
                   else
                   {
                      printf("Conexao Falhou\n");
                      if (mysql_errno(&conexao))
                         printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                   }

    }
    system("\n\n\n\npause");
    system("cls");
    break;
//Sair--------------------------------------------------------------------------------------------------------------------------------------------
        case 5:

            break;
    }
break;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Usuario Acesso Estoque--------------------------------------------------------------------------------------------------------------------------------------

    case 4:
//Senha---------------------------------------------------------------------------------------------------------------------------------
contadorGerencia = 0;
do{
printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("----------------------", setlocale(LC_ALL,""));
        printf("\n\tLogin\n", setlocale(LC_ALL,""));
        printf("----------------------\n\n", setlocale(LC_ALL,""));
        contadorGerencia++;
        printf("Digite a senha: ");
        //scanf("%s", &senha);
        senha[0] = getch();
        printf ("*");
        senha[1] = getch();
        printf ("*");
        senha[2] = getch();
        printf ("*");
        senha[3] = getch();
        printf ("*");
        senha[4] = getch();
        printf ("*");
        senha[5] = getch();
        printf ("*");

mysql_init(&conexao);

        sprintf(query,"SELECT Senha FROM senhas WHERE senha = '%s' && ID = 3;", senha, IDUsuario );
       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);

                  printf("\n");

                  linhas=mysql_fetch_row(resp);
              }
              mysql_free_result(resp);
            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }
        system("cls");

        if (contadorGerencia>3){

            break;
        }

}while (linhas == NULL );

if (contadorGerencia >3){

   break;
}
//Estoque-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    while(continua_estoque != 0){
    printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
    printf(" __  __                   _ _\n");
    printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
    printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
    printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
    printf("\n------------------------------------------------\n");
    printf("Digite o número, referente a atividade desejada.\n", setlocale (LC_ALL, "") );
    printf("------------------------------------------------\n");
    printf("\n1 - Consultar\n2 - Inserir\n3 - Alterar\n4 - Retirar\n5 - Sair\n", setlocale (LC_ALL, "") );
    scanf("%i", &estoque);
    getchar();
    system("cls");

    switch (estoque){
//Consultar--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case 1:
        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("-------------------------", setlocale(LC_ALL,""));
        printf("\n\tConsulta\n", setlocale(LC_ALL,""));
        printf("-------------------------\n\n", setlocale(LC_ALL,""));
        mysql_init(&conexao);

            sprintf(query,"SELECT ID, quantidade, item FROM item WHERE Unidade = '%s';", unidade);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t\t");
                      }

                      printf("\n");

                      while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            printf("%s\t\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }
        system("pause");
        system("cls");
        break;
//Inserir--------------------------------------------------------------------------------------------------------------------------------------------------
        case 2:

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("-------------------------", setlocale(LC_ALL,""));
        printf("\n\tInserir\n", setlocale(LC_ALL,""));
        printf("-------------------------\n\n", setlocale(LC_ALL,""));

        printf("Digite o nome do produto: ", setlocale(LC_ALL,""));
        gets(item);

        printf("\nDigite a quantidade do produto: ", setlocale(LC_ALL,""));
        scanf("%s",&quantidade);
        getchar();

        printf("\nDigite o ID para o produto: ", setlocale(LC_ALL,""));
        scanf("%i",&identificador_id);
        getchar();



        mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"INSERT INTO item (item,quantidade,Unidade, ID) values ('%s','%s','%s','%i');", item, quantidade,unidade, identificador_id);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }
        escolha_estoque = 0;
        system ("cls");

        break;
//Alterar-------------------------------------------------------------------------------------------------------------------------------------------------------
        case 3:

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("-------------------------", setlocale(LC_ALL,""));
        printf("\n\tAlterar\n", setlocale(LC_ALL,""));
        printf("-------------------------\n\n", setlocale(LC_ALL,""));

        mysql_init(&conexao);

            sprintf(query,"SELECT ID, quantidade, item FROM item WHERE Unidade = '%s';", unidade);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t\t");
                      }

                      printf("\n");

                      while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            printf("%s\t\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

//-------------

        printf("\nEntre com o número de identificação:\t", setlocale(LC_ALL,""));
        scanf("%i",&identificador_id);
        getchar();

        printf("Entre com a quantidade:\t", setlocale(LC_ALL,""));
        scanf("%s",&quantidade);
        getchar();

          mysql_init(&conexao);

             if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
            {
                printf("conectado com sucesso!\n");

                sprintf(query,"UPDATE item SET quantidade = '%s' WHERE ID = '%i';", quantidade,identificador_id);
                  res = mysql_query(&conexao,query);
                if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

            mysql_close(&conexao);
            }
            else
            {
            printf("Falha de conexao\n");
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
            }
            system ("pause");
            system("cls");

    break;
//Retirar--------------------------------------------------------------------------------------------------------------------------------------------------------------
        case 4:

            printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
            printf(" __  __                   _ _\n");
            printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
            printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
            printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
            printf("-------------------------", setlocale(LC_ALL,""));
            printf("\n\tRetirar\n", setlocale(LC_ALL,""));
            printf("-------------------------\n\n", setlocale(LC_ALL,""));

             mysql_init(&conexao);

            sprintf(query,"SELECT ID, quantidade, item FROM item WHERE Unidade = '%s';", unidade);

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {

              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                   campos = mysql_fetch_fields(resp);
                   for (conta=0;conta<mysql_num_fields(resp);conta++) {
                      printf("%s",(campos[conta]).name);
                      if (mysql_num_fields(resp)>1)
                          printf("\t\t");
                      }

                      printf("\n");

                      while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            printf("%s\t\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }

            //------------------

            printf("\nEntre com o número de identificação:\t", setlocale(LC_ALL,""));
            scanf("%i",&identificador_id);
            getchar();

               mysql_init(&conexao);

             if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
            {
                printf("conectado com sucesso!\n");
                sprintf(query,"DELETE FROM item WHERE ID = '%i';", identificador_id);

                  res = mysql_query(&conexao,query);
                if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

            mysql_close(&conexao);
            }
            else
            {
            printf("Falha de conexao\n");
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
            }
            system ("pause");
            system("cls");
            escolha_estoque = 0;
            break;
//Sair--------------------------------------------------------------------------------------------------------------------------------------------------------
        case 5:
            continua_estoque = 0;
            break;
    }
    }
    system ("cls");
    break;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Cadastro de Produtos------------------------------------------------------------------------------------------------------------------------------------------------------------
    case 5:
//Senha
contadorGerencia = 0;
do{
printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
printf(" __  __                   _ _\n");
printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("----------------------", setlocale(LC_ALL,""));
        printf("\n\tLogin\n", setlocale(LC_ALL,""));
        printf("----------------------\n\n", setlocale(LC_ALL,""));
        contadorGerencia++;
        printf("Digite a senha: ");
        //scanf("%s", &senha);
        senha[0] = getch();
        printf ("*");
        senha[1] = getch();
        printf ("*");
        senha[2] = getch();
        printf ("*");
        senha[3] = getch();
        printf ("*");
        senha[4] = getch();
        printf ("*");
        senha[5] = getch();
        printf ("*");

mysql_init(&conexao);

        sprintf(query,"SELECT Senha FROM senhas WHERE senha = '%s' && ID = 1;", senha, IDUsuario );
       if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
       {
          if (mysql_query(&conexao,query))
             printf("Erro: %s\n",mysql_error(&conexao));
          else
          {
             resp = mysql_store_result(&conexao);
            if (resp)
            {
               campos = mysql_fetch_fields(resp);

                  printf("\n");

                  linhas=mysql_fetch_row(resp);
              }
              mysql_free_result(resp);
            }
            mysql_close(&conexao);
       }
       else
       {
          printf("Conexao Falhou\n");
          if (mysql_errno(&conexao))
             printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }
        system("cls");

        if (contadorGerencia>3){

            break;
        }
}while (linhas == NULL );

if (contadorGerencia >3){

   break;
}
//------------------------------------------------
        while(continua_cadprod != 0){
        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");

        printf("-------------------------", setlocale(LC_ALL,""));
        printf("\n   Cadastro de Produtos\n", setlocale(LC_ALL,""));
        printf("-------------------------\n\n", setlocale(LC_ALL,""));

        printf("Escolha a opção desejada\n\n1 - Consultar Produtos\n2 - Inserir Produtos\n3 - Inserir Valor\n4 - Sair\n", setlocale(LC_ALL,""));
        scanf("%i",&cadastrodeProdutos);
        getchar();

        system ("cls");

        switch(cadastrodeProdutos){
//Consultar Produtos --------------------------------------------------------------------------------------------------------------------------------------------------------------
        case 1:
        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("--------------------------", setlocale(LC_ALL,""));
        printf("\n\tConsultar\n", setlocale(LC_ALL,""));
        printf("--------------------------\n\n", setlocale(LC_ALL,""));

            mysql_init(&conexao);

            sprintf(query,"SELECT ID, Unidade, Produto FROM cadastro_produtos ORDER BY unidade;");

           if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
           {
              if (mysql_query(&conexao,query))
                 printf("Erro: %s\n",mysql_error(&conexao));
              else
              {
                 resp = mysql_store_result(&conexao);
                if (resp)
                {
                printf("ID      Unidade         Produto");

                      printf("\n");

                      while ((linhas=mysql_fetch_row(resp)) != NULL)
                      {
                         for (conta=0;conta<mysql_num_fields(resp);conta++)
                            printf("%s\t",linhas[conta]);
                         printf("\n");
                      }
                  }
                  mysql_free_result(resp);
                }
                mysql_close(&conexao);
           }
           else
           {
              printf("Conexao Falhou\n");
              if (mysql_errno(&conexao))
                 printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
           }
            system ("pause");
            system("cls");
            break;
//Inserir Produtos-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case 2:

        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
         printf("--------------------------", setlocale(LC_ALL,""));
        printf("\n\tInserir Produto\n", setlocale(LC_ALL,""));
        printf("--------------------------\n\n", setlocale(LC_ALL,""));


        printf("Digite o nome do produto: ", setlocale(LC_ALL,""));
        gets(produtoCadastroProduto);
        printf("Digite o ID para o produto: ", setlocale(LC_ALL,""));
        scanf("%i",&produtoID);


        mysql_init(&conexao);

        if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
        {
            printf("conectado com sucesso!\n");

            sprintf(query,"INSERT INTO cadastro_produtos (ID, Produto, Unidade) values ('%i','%s','%s');", produtoID, produtoCadastroProduto, unidade);

        res = mysql_query(&conexao,query);
            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
        }
        else
        {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        }
        system("pause");
        system("cls");
        break;
//Sair------------------------------------------------------------------------------------------------------------------------------------------------
        case 3:
        printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
        printf(" __  __                   _ _\n");
        printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
        printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
        printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
        printf("--------------------------", setlocale(LC_ALL,""));
        printf("\n\tInserir Valor\n", setlocale(LC_ALL,""));
        printf("--------------------------\n\n", setlocale(LC_ALL,""));

            printf("\nEntre com o número de identificação: ", setlocale(LC_ALL,""));
            scanf("%i",&identificador_id);
            getchar();

            printf("Entre com o valor: ", setlocale(LC_ALL,""));
            scanf("%s",&quantidade);
            getchar();

              mysql_init(&conexao);

                 if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
                {
                    printf("conectado com sucesso!\n");

                    sprintf(query,"UPDATE cadastro_produtos SET valor = '%s' WHERE ID = '%i';", quantidade,identificador_id);
                      res = mysql_query(&conexao,query);
                    if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                    else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

                mysql_close(&conexao);
                }
                else
                {
                printf("Falha de conexao\n");
                printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                }
                system ("pause");
                system("cls");
 break;
//Sair-----------------------------------------------------------------------------------------------------------------------------------

          case 4:

        continua_cadprod = 0;
            break;
        }
        //break;
        }
break;
//Regisrto de reclamacoes / elogios+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
          case 6:

            printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
            printf(" __  __                   _ _\n");
            printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
            printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
            printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
            printf("-------------------------\n");
            printf("Escolha a opção desejada\n", setlocale (LC_ALL, "") );
            printf("-------------------------\n");
            printf("\n1 - Elogios e opiniões\n2 - Reclamações\n3 - Consulta\n4 - Tratar ocorrência\n5 - Sair\n", setlocale(LC_ALL,""));
            scanf("%i",&Elrecl);
            getchar();
            system("cls");

//Elogios e opinoes----------------------------------------------------------------------------------------------------------------------------------------------
            if(Elrecl == 1){
            printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
            printf(" __  __                   _ _\n");
            printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
            printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
            printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
            printf("-------------------\n");
            printf("Elogios e opiniões\n", setlocale (LC_ALL, "") );
            printf("-------------------\n");

            printf("Entre com o nome do pizzaiolo: ", setlocale(LC_ALL,""));
            gets(pizzaiolo);
            printf("\n");
            printf("Entre com o nome do cliente: ", setlocale(LC_ALL,""));
            gets(nomeCliente);
            printf("\n");
            printf("Entre com o telefone do cliente: ", setlocale(LC_ALL,""));
            gets(telefoneCliente);
            printf("\n");
            printf("Resuma, em poucas palavras, a informação prestada pelo cliente\n\n", setlocale(LC_ALL,""));
            gets(texto);

                mysql_init(&conexao);

                if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
                {
                    printf("conectado com sucesso!\n");

                     sprintf(query,"INSERT INTO elogio_reclamacao (Unidade,Data,Tipo, Nome, Telefone, Texto, Resolucao, Pizzaiolo) values ('Unidade: %s','%s','Tipo: %s','Nome: %s','Telefone: %s','Informacao: %s','Status: %s','Pizzaiolo: %s');",unidade, data, tipoElogio, nomeCliente, telefoneCliente, texto, trtOcorrencia, pizzaiolo);

                res = mysql_query(&conexao,query);
                    if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                    else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

                mysql_close(&conexao);
                }
                else
                {
                printf("Falha de conexao\n");
                printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                }
                system ("pause");
                system("cls");
                break;
//Reclamacoes----------------------------------------------------------------------------------------------------------------------------------------------
            }else if(Elrecl == 2){
            printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
            printf(" __  __                   _ _\n");
            printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
            printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
            printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
            printf("------------\n");
            printf("Reclamações\n", setlocale (LC_ALL, "") );
            printf("------------\n");

            printf("Entre com o nome do pizzaiolo: ", setlocale(LC_ALL,""));
            gets(pizzaiolo);
            printf("\n");
            printf("Entre com o nome do cliente: ", setlocale(LC_ALL,""));
            gets(nomeCliente);
            printf("\n");
            printf("Entre com o telefone do cliente: ", setlocale(LC_ALL,""));
            gets(telefoneCliente);
            printf("\n");
            printf("Resuma, em poucas palavras, a informação prestada pelo cliente\n\n", setlocale(LC_ALL,""));
            gets(texto);

             mysql_init(&conexao);

                if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
                {
                    printf("conectado com sucesso!\n");

                    sprintf(query,"INSERT INTO elogio_reclamacao (Unidade,Data,Tipo, Nome, Telefone, Texto, Resolucao, Pizzaiolo) values ('Unidade: %s','%s','Tipo: %s','Nome: %s','Telefone: %s','Informacao: %s','Status: %s','Pizzaiolo: %s');",unidade, data, tipoReclamacao, nomeCliente, telefoneCliente, texto, trtOcorrencia, pizzaiolo);

                res = mysql_query(&conexao,query);
                    if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                    else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
               mysql_close(&conexao);
                }
                else
                {
                printf("Falha de conexao\n");
                printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                }
                system ("pause");
                system("cls");
                break;

//Consulta----------------------------------------------------------------------------------------------------------------------------------------------
            }else if(Elrecl == 3){
            printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
            printf(" __  __                   _ _\n");
            printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
            printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
            printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
            printf("-------------------------\n");
            printf("\tConsulta\n", setlocale (LC_ALL, "") );
            printf("-------------------------\n");

                mysql_init(&conexao);

                sprintf(query,"SELECT ID, Data, Unidade, Pizzaiolo, Tipo, Resolucao, Nome, Telefone, Texto FROM elogio_reclamacao ORDER BY Data;");
               if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
               {
                  if (mysql_query(&conexao,query))
                     printf("Erro: %s\n",mysql_error(&conexao));
                  else
                  {
                     resp = mysql_store_result(&conexao);
                    if (resp)
                    {
                       campos = mysql_fetch_fields(resp);
                          printf("\n");
                          while ((linhas=mysql_fetch_row(resp)) != NULL)
                          {
                             for (conta=0;conta<mysql_num_fields(resp);conta++)

                                    printf("%s\t\n",linhas[conta]);

                                  printf("------------------------------------------------");

                             printf("\n");
                          }
                      }
                      mysql_free_result(resp);
                   }
                    mysql_close(&conexao);
              }
               else
               {
                  printf("Conexao Falhou\n");
                  if (mysql_errno(&conexao))
                     printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
               }
                system ("pause");
                system("cls");
                break;
//Tratar Ocorrencia----------------------------------------------------------------------------------------------------------------------------------------------

            }else if(Elrecl == 4){
            printf("(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)(___)___)(___)(___)(___)(___)(___)(___)(___)\n\n");
            printf(" __  __                   _ _\n");
            printf("|  \\/  |__ _ _ _  _____ _| (_)\n");
            printf("| |\\/| / _` | ' \\|_ / _` | | |\n");
            printf("|_|  |_\\__,_|_||_/__\\__,_|_|_|\n\n");
            printf("------------------\n");
            printf("Tratar ocorrência\n", setlocale (LC_ALL, "") );
            printf("------------------\n");

            printf("Entre com o ID da ocorrência:  ", setlocale(LC_ALL,""));
            scanf("%i",&IDocorrencia);
            getchar();

                mysql_init(&conexao);

                    sprintf(query,"SELECT Unidade, Pizzaiolo, Data, Tipo, Resolucao, Nome, Telefone, Texto FROM elogio_reclamacao WHERE ID = '%i';", IDocorrencia);
                   if (mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0))
                   {
                      if (mysql_query(&conexao,query))
                         printf("Erro: %s\n",mysql_error(&conexao));
                      else
                      {
                         resp = mysql_store_result(&conexao);
                        if (resp)
                        {
                           campos = mysql_fetch_fields(resp);
                              printf("\n");
                             while ((linhas=mysql_fetch_row(resp)) != NULL)
                              {
                                 for (conta=0;conta<mysql_num_fields(resp);conta++)
                                    printf("%s\t\n",linhas[conta]);
                                 printf("\n");
                              }
                          }
                          mysql_free_result(resp);
                       }
                        mysql_close(&conexao);
                  }
                   else
                   {
                      printf("Conexao Falhou\n");
                      if (mysql_errno(&conexao))
                         printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                   }

                    printf("\n\nA ocorrência foi tratada com sucesso?:\n1 para sim\n2 para não\n", setlocale (LC_ALL, "") );
                    scanf("%i", &fechaBalanco);
                    getchar();

                    if (fechaBalanco!=1){

                    system("pause");
                    system("cls");
                    break;

                    }else{
                    char trtOcorrencia[50] = "Status: Resolvido";

                    mysql_init(&conexao);

                         if ( mysql_real_connect(&conexao, "localhost", "root", "", "db_PIM", 0, NULL, 0) )
                        {
                            printf("conectado com sucesso!\n");

                            sprintf(query,"UPDATE elogio_reclamacao SET Resolucao = '%s' WHERE ID = '%i';",  trtOcorrencia, IDocorrencia);

                              res = mysql_query(&conexao,query);
                            if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
                            else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

                        mysql_close(&conexao);
                        }
                        else
                        {
                        printf("Falha de conexao\n");
                        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                        }
                    }
                    char trtOcorrencia[50] = "Pendente";
                    system("cls");
                    break;
//Sair----------------------------------------------------------------------------------------------------------------------------------------------
            }else break;
    }
    }
    return 0;
}
