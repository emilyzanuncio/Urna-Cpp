#include <stdio.h>
#include <iostream>
#include <locale.h>
#define C 100

using namespace std;

//------------- VARIÁVEIS GERAIS -------------
int opcao,n,CadastroCompleto,VotacaoCompleta;
char E;                                                         // Usada para perguntas de sim e não,

//---------- VARIÁVEIS PARA A SENHA ----------
int senha, sen,prv;

// --- VARIÁVEIS PARA O CADASTRO DOS CANDIDATOS ---
char C1[C], C2[C], C3[C], C4[C];                                // Nome dos Candidatos
char P1[C], P2[C], P3[C], P4[C];                                // Partido dos Candidatos
int N1, N2, N3, N4;                                             // Número dos Candidatos
int i,corrigirCadastro,correcao;                                //Usada no For que transfoÚrma pontos em espaços, corrigir cadastro, correcao finalizada ou não

//--------- VARIÁVEIS PARA A VOTAÇÃO ---------
int voto,linha,ConfirmarVoto;                                   // Opção de voto, variável usada no for dos gráficos de linha, variável de confirmação do voto
float vnulos,vbrancos,vc1,vc2,vc3,vc4,VotosValidos,vtotal;      // Votos nulos, brancos e por candidato, votos validos e votos totais
float pvnulos,pvbrancos,pvc1, pvc2, pvc3, pvc4;                 // Porcentagem de votos nulos, brancos e por candidato
char Cont,CV;                                                   // Finalizar ou continuar votação, corrigir voto (sim ou não)


int main()
{
    setlocale(LC_ALL, "pt-BR");
    //------------------------------------------------------------
    // Inicialização e definição de uma senha para o administrador
    //------------------------------------------------------------
    cout<<"---------------- URNA ELETRÔNICA ----------------\n";
    cout<<"Antes de receber acesso ao menu, defina uma senha numérica para o administrador:\n";
    cin>>senha;

    //------------------------------------------------------------
    // Menu principal
    //------------------------------------------------------------
    while(n!=1)
    {

        prv=1;

        cout<<"\n-------------------- MENU --------------------\n";
        cout<<"| 1 - Cadastro/Visualização de candidatos    |\n";
        cout<<"| 2 - Modo de votação                        |\n";
        cout<<"| 3 - Resultados da votação                  |\n";
        cout<<"| 4 - Sair                                   |\n";
        cout<<"----------------------------------------------\n";
        cout<<"Seleciona uma opção:\n";
        cin>>opcao;
        switch(opcao)
        {
        //------------------------------------------------------------
        // 1 - CADASTRO/VISUALIZAÇÃO DE CANDIDATOS
        //------------------------------------------------------------
        case 1:
            //------------------------------------------------------------
            // Insira a senha do administrador para ter acesso à esta seção
            //------------------------------------------------------------
            cout<<"Insira a senha do administrador:\n";
            cin>>sen;
            while(sen!=senha)
            {
                cout<<"Senha incorreta. Tente novamente:\n";
                cin>>sen;
            }
            if(sen==senha)
            {
                if(CadastroCompleto==1)
                {
                    cout<<"\n----- CANDIDATOS  CADASTRADOS -----\n\n";

                    cout<<"--------- CANDIDATO(A) 01 ---------\n";
                    cout<<"- Nome: "<<C1<<"\n";
                    cout<<"- Partido: "<<P1<<"\n";
                    cout<<"- Número: "<<N1<<"\n\n";

                    cout<<"--------- CANDIDATO(A) 02 ---------\n";
                    cout<<"- Nome: "<<C2<<"\n";
                    cout<<"- Partido: "<<P2<<"\n";
                    cout<<"- Número: "<<N2<<"\n\n";

                    cout<<"--------- CANDIDATO(A) 03 ---------\n";
                    cout<<"- Nome: "<<C3<<"\n";
                    cout<<"- Partido: "<<P3<<"\n";
                    cout<<"- Número: "<<N3<<"\n\n";

                    cout<<"--------- CANDIDATO(A) 04 ---------\n";
                    cout<<"- Nome: "<<C4<<"\n";
                    cout<<"- Partido: "<<P4<<"\n";
                    cout<<"- Número: "<<N4<<"\n\n";
                    cout<<"-----------------------------------\n\n";
                }
                else if(CadastroCompleto!=1)
                {
                    //------------------------------------------------------------
                    // Cadastro dos candidatos
                    //------------------------------------------------------------
                        cout<<"----- CADASTRO DE CANDIDATOS: INSTRUÇÕES -----\n\n";
                        cout<<"- Use um ponto no lugar do espaço entre nomes. Outros símbolos não serão considerados.\n";
                        cout<<"- Os números devem estar entre 10 e 99. Números abaixo de 10 ou acima de 99 não serão aceitos.\n";

                        //------------------------------------------------------------
                        // Cadastro - Candidato 01
                        //------------------------------------------------------------
                            cout<<"\n---> CANDIDATO(A) 01:\n";
                            cout<<"Nome: ";
                            cin>>C1;
                            cout<<"Partido: ";
                            cin>>P1;
                            cout<<"Número: ";
                            cin>>N1;
                            while(N1<=9 || N1>=100)
                            {
                                cout<<"Número inválido, insira novamente:\n";
                                cin>>N1;
                            }
                            //------------------------
                            // Substituir . por espaço
                            //------------------------
                            for(i=0;i<=100;i++)
                            {
                                if(C1[i]=='.')
                                {
                                    C1[i]=' ';
                                }
                            }
                            //------------------------
                            // Corrigir dados
                            //------------------------
                            cout<<"Deseja corrigir algum dado do candidato?\n";
                            cout<<"S - Sim | N - Não\n";
                            cin>>E;
                            if(E=='S' || E=='s')
                            {
                                while(correcao!=1)
                                {
                                    cout<<"Selecione uma das opções abaixo:\n";
                                    cout<<"--------------------------------\n";
                                    cout<<"1 - Corrigir nome\n";
                                    cout<<"2 - Corrigir partido\n";
                                    cout<<"3 - Corrigir número\n";
                                    cout<<"--------------------------------\n";
                                    cin>>corrigirCadastro;

                                    switch(corrigirCadastro)
                                    {
                                    case 1:
                                        cout<<"Nome: ";
                                        cin>>C1;
                                        break;
                                    case 2:
                                        cout<<"Partido: ";
                                        cin>>P1;
                                        break;
                                    case 3:
                                        cout<<"Número: ";
                                        cin>>N1;
                                        break;
                                    default:
                                        cout<<"Opção inválida, insira novamente.\n";
                                        cin>>corrigirCadastro;
                                        break;
                                    }
                                    cout<<"\nDeseja corrigir mais alguma coisa?\n";
                                    cout<<"S - Sim | N - Não\n";
                                    cin>>E;
                                    if(E=='N' || E=='n')
                                    {
                                        correcao=1;
                                    }
                                } // Fim do While
                            } // Fim da resposta Sim

                        //------------------------------------------------------------
                        // Cadastro - Candidato 02
                        //------------------------------------------------------------
                            cout<<"\n---> CANDIDATO(A) 02:\n";
                            cout<<"Nome: ";
                            cin>>C2;
                            cout<<"Partido: ";
                            cin>>P2;
                            cout<<"Número: ";
                            cin>>N2;
                            while(N2<=9 || N2>=100)
                            {
                                cout<<"Número inválido, insira novamente:\n";
                                cin>>N2;
                            }
                            //------------------------
                            // Substituir . por espaço
                            //------------------------
                            for(i=0;i<=100;i++)
                            {
                                if(C2[i]=='.')
                                {
                                    C2[i]=' ';
                                }
                            }
                            //------------------------
                            // Corrigir dados
                            //------------------------
                            cout<<"Deseja corrigir algum dado do candidato?\n";
                            cout<<"S - Sim | N - Não\n";
                            cin>>E;
                            if(E=='S' || E=='s')
                            {
                                correcao=0;
                                while(correcao!=1)
                                {
                                    cout<<"Selecione uma das opções abaixo:\n";
                                    cout<<"--------------------------------\n";
                                    cout<<"1 - Corrigir nome\n";
                                    cout<<"2 - Corrigir partido\n";
                                    cout<<"3 - Corrigir número\n";
                                    cout<<"--------------------------------\n";
                                    cin>>corrigirCadastro;

                                    switch(corrigirCadastro)
                                    {
                                    case 1:
                                        cout<<"Nome: ";
                                        cin>>C2;
                                        break;
                                    case 2:
                                        cout<<"Partido: ";
                                        cin>>P2;
                                        break;
                                    case 3:
                                        cout<<"Número: ";
                                        cin>>N2;
                                        break;
                                    default:
                                        cout<<"Opção inválida, insira novamente.\n";
                                        cin>>corrigirCadastro;
                                        break;
                                    }
                                    cout<<"\nDeseja corrigir mais alguma coisa?\n";
                                    cout<<"S - Sim | N - Não\n";
                                    cin>>E;
                                    if(E=='N' || E=='n')
                                    {
                                        correcao=1;
                                    }
                                } // Fim do While
                            } // Fim da resposta Sim

                        //------------------------------------------------------------
                        // Cadastro - Candidato 03
                        //------------------------------------------------------------
                            cout<<"\n---> CANDIDATO(A) 03:\n";
                            cout<<"Nome: ";
                            cin>>C3;
                            cout<<"Partido: ";
                            cin>>P3;
                            cout<<"Número: ";
                            cin>>N3;
                            while(N3<=9 || N3>=100)
                            {
                                cout<<"Número inválido, insira novamente:\n";
                                cin>>N3;
                            }
                            //------------------------
                            // Substituir . por espaço
                            //------------------------
                            for(i=0;i<=100;i++)
                            {
                                if(C3[i]=='.')
                                {
                                    C3[i]=' ';
                                }
                            }
                            //------------------------
                            // Corrigir dados
                            //------------------------
                            cout<<"Deseja corrigir algum dado do candidato?\n";
                            cout<<"S - Sim | N - Não\n";
                            cin>>E;
                            if(E=='S' || E=='s')
                            {
                                correcao=0;
                                while(correcao!=1)
                                {
                                    cout<<"Selecione uma das opções abaixo:\n";
                                    cout<<"--------------------------------\n";
                                    cout<<"1 - Corrigir nome\n";
                                    cout<<"2 - Corrigir partido\n";
                                    cout<<"3 - Corrigir número\n";
                                    cout<<"--------------------------------\n";
                                    cin>>corrigirCadastro;

                                    switch(corrigirCadastro)
                                    {
                                    case 1:
                                        cout<<"Nome: ";
                                        cin>>C3;
                                        break;
                                    case 2:
                                        cout<<"Partido: ";
                                        cin>>P3;
                                        break;
                                    case 3:
                                        cout<<"Número: ";
                                        cin>>N3;
                                        break;
                                    default:
                                        cout<<"Opção inválida, insira novamente.\n";
                                        cin>>corrigirCadastro;
                                        break;
                                    }
                                    cout<<"\nDeseja corrigir mais alguma coisa?\n";
                                    cout<<"S - Sim | N - Não\n";
                                    cin>>E;
                                    if(E=='N' || E=='n')
                                    {
                                        correcao=1;
                                    }
                                } // Fim do While
                            } // Fim da resposta Sim

                        //------------------------------------------------------------
                        // Cadastro - Candidato 04
                        //------------------------------------------------------------
                            cout<<"\n---> CANDIDATO(A) 04:\n";
                            cout<<"Nome: ";
                            cin>>C4;
                            cout<<"Partido: ";
                            cin>>P4;
                            cout<<"Número: ";
                            cin>>N4;
                            while(N4<=9 || N4>=100)
                            {
                                cout<<"Número inválido, insira novamente:\n";
                                cin>>N4;
                            }
                            //------------------------
                            // Substituir . por espaço
                            //------------------------
                            for(i=0;i<=100;i++)
                            {
                                if(C4[i]=='.')
                                {
                                    C4[i]=' ';
                                }
                            }
                            //------------------------
                            // Corrigir dados
                            //------------------------
                            cout<<"Deseja corrigir algum dado do candidato?\n";
                            cout<<"S - Sim | N - Não\n";
                            cin>>E;
                            if(E=='S' || E=='s')
                            {
                                correcao=0;
                                while(correcao!=1)
                                {
                                    cout<<"Selecione uma das opções abaixo:\n";
                                    cout<<"--------------------------------\n";
                                    cout<<"1 - Corrigir nome\n";
                                    cout<<"2 - Corrigir partido\n";
                                    cout<<"3 - Corrigir número\n";
                                    cout<<"--------------------------------\n";
                                    cin>>corrigirCadastro;

                                    switch(corrigirCadastro)
                                    {
                                    case 1:
                                        cout<<"Nome: ";
                                        cin>>C4;
                                        break;
                                    case 2:
                                        cout<<"Partido: ";
                                        cin>>P4;
                                        break;
                                    case 3:
                                        cout<<"Número: ";
                                        cin>>N4;
                                        break;
                                    default:
                                        cout<<"Opção inválida, insira novamente.\n";
                                        cin>>corrigirCadastro;
                                        break;
                                    }
                                    cout<<"\nDeseja corrigir mais alguma coisa?\n";
                                    cout<<"S - Sim | N - Não\n";
                                    cin>>E;
                                    if(E=='N' || E=='n')
                                    {
                                        correcao=1;
                                    }
                                } // Fim do While
                            } // Fim da resposta Sim
                        //------------------------------------------------------------
                            cout<<"\n-------- CADASTRO FINALIZADO COM SUCESSO --------\n";
                            CadastroCompleto = 1;
                        //------------------------------------------------------------
                }
            }
            break;

        //------------------------------------------------------------
        // 2- MODO DE VOTAÇÃO
        //------------------------------------------------------------
        case 2:
            if(CadastroCompleto==0)
            {
                cout<<"Cadastro incompleto.\n";
                cout<<"Redirecionando ao menu...\n\n";
            }
            else
            {
                if(VotacaoCompleta==1)
                {
                    cout<<"O processo de votação foi finalizado. Para ver os resultados, selecione a opção '3 - Resultados da votação' no menu.\n";
                }
                while(VotacaoCompleta!=1)
                {
                    cout<<"--------------- MODO DE VOTAÇÃO ---------------\n";

                    cout<<"--------- CANDIDATO(A) 01 ---------\n";
                    cout<<"- Nome: "<<C1<<"\n";
                    cout<<"- Partido: "<<P1<<"\n";
                    cout<<"- Número: "<<N1<<"\n\n";

                    cout<<"--------- CANDIDATO(A) 02 ---------\n";
                    cout<<"- Nome: "<<C2<<"\n";
                    cout<<"- Partido: "<<P2<<"\n";
                    cout<<"- Número: "<<N2<<"\n\n";

                    cout<<"--------- CANDIDATO(A) 03 ---------\n";
                    cout<<"- Nome: "<<C3<<"\n";
                    cout<<"- Partido: "<<P3<<"\n";
                    cout<<"- Número: "<<N3<<"\n\n";

                    cout<<"--------- CANDIDATO(A) 04 ---------\n";
                    cout<<"- Nome: "<<C4<<"\n";
                    cout<<"- Partido: "<<P4<<"\n";
                    cout<<"- Número: "<<N4<<"\n\n";
                    cout<<"-----------------------------------\n\n";

                    cout<<"Selecione um candidato:\n";
                    cin>>voto;

                    //------------------------
                    // Voto de 10 a 99
                    //------------------------
                    while(voto<=9 && voto!=0|| voto>=100)
                    {
                        cout<<"Número inválidos, insira novamente.\n";
                        cin>>voto;
                    }

                    //------------------------
                    // Confirmar voto?
                    //------------------------
                    while(ConfirmarVoto!=1)
                    {
                        cout<<"Candidato selecionado:"<<voto<<" | Confirmar voto?\n";
                        cout<<"S - Sim | N - Não\n";
                        cin>>CV;
                        if(CV=='N' || CV=='n')
                        {
                            cout<<"Insira o voto novamente: \n";
                            cin>>voto;

                            //------------------------
                            // Voto de 10 a 99
                            //------------------------
                            while(voto<=9 && voto!=0|| voto>=100)
                            {
                                cout<<"Número inválidos, insira novamente.\n";
                                cin>>voto;
                            }
                        }
                        else if(CV=='S' || CV=='s')
                        {
                            ConfirmarVoto=1;
                        }
                    }
                    ConfirmarVoto=0;

                    //------------------------------------------------------------
                    // Contagem dos votos
                    //------------------------------------------------------------
                    if(voto==N1)
                    {
                        vc1++;
                    }
                    else if(voto==N2)
                    {
                        vc2++;
                    }
                    else if(voto==N3)
                    {
                        vc3++;
                    }
                    else if(voto==N4)
                    {
                        vc4++;
                    }
                    else if(voto==0)
                    {
                        vbrancos++;
                    }
                    else
                    {
                        vnulos++;
                    }
                    //------------------------------------------------------------
                    // Novo voto ou finalizar votação
                    //------------------------------------------------------------
                    cout<<"N - Adicionar novo voto\n";
                    cin>>Cont;

                    if(Cont=='x' || Cont=='X') // Finalizar votação
                    {
                        cout<<"\nDeseja finalizar a votação?\n";
                        cout<<"S - Sim | N - Não\n";
                        cin>>E;
                        if(E=='S' || E=='s') // Sim
                        {
                            cout<<"Insira a senha do administrador para finalizar a votação:\n";
                            cin>>sen;
                                if(sen!=senha)
                                {
                                    cout<<"Senha incorreta, insira novamente:\n";
                                }
                                else
                                {
                                    cout<<"Senha correta, finalizando votação...\n";

                                    //------------------------------------------------------------
                                    cout<<"Votação finalizada com sucesso.\nPara visualizar os resultados, selecione a opção '3 - Resultados da Votação' no menu.\n";
                                    VotacaoCompleta=1;
                                    //------------------------------------------------------------
                                }
                        }
                        else if(E=='N' || E=='n') // Não
                        {
                            cout<<"Redirecionando...\n";
                        }
                    }
                    else if(Cont=='n' || Cont=='N') // Adicionar novo voto
                    {
                        cout<<"\n";
                    }
                    else
                    {
                        cout<<"Opção inválida, insira novamente:\n";
                    }
                }

                //------------------------------------------------------------
                // Cálculo da qtd de votos válidos, totais e das porcentagens
                //------------------------------------------------------------
                VotosValidos = vc1+vc2+vc3+vc4;                          // Votos válidos
                vtotal = VotosValidos+vnulos+vbrancos;                   // Votos totais
                pvc1 = (vc1*100)/vtotal;                                 // % de votos do candidato 01
                pvc2 = (vc2*100)/vtotal;                                 // % de votos do candidato 02
                pvc3 = (vc3*100)/vtotal;                                 // % de votos do candidato 03
                pvc4 = (vc4*100)/vtotal;                                 // % de votos do candidato 04
                pvnulos = (vnulos*100)/vtotal;                           // % de votos nulos
                pvbrancos = (vbrancos*100)/vtotal;                       // % de votos brancos
            }

            break;

        //------------------------------------------------------------
        // 3 - RESULTADOS DA VOTAÇÃO
        //------------------------------------------------------------
        case 3:
            if(VotacaoCompleta!=1)
            {
                cout<<"Votação incompleta.\n";
                cout<<"Redirecionando ao menu...\n\n";
            }
            else
            {
                //------------------------------------------------------------
                // Resultados gerais
                //------------------------------------------------------------
                cout<<"----------- RESULTADOS DA VOTAÇÃO -----------\n\n";

                cout<<"------------- RESULTADOS GERAIS -------------\n";
                cout<<"- Quantidade total de votos: "<<vtotal<<"\n";
                cout<<"- Quantidade total de votos válidos: "<<VotosValidos<<"\n\n";

                cout<<"----------- VOTOS NULOS E BRANCOS -----------\n";
                cout<<"- Quantidade total de votos nulos: "<<vnulos<<"\n";
                cout<<"- Quantidade total de votos brancos: "<<vbrancos<<"\n";
                cout<<"- Percentual de votos nulos: "<<pvnulos<<"%\n";
                cout<<"- Percentual de votos brancos: "<<pvbrancos<<"%\n\n";

                cout<<"-------------- CANDIDATO(A) 01 --------------\n";
                cout<<C1<<", partido "<<P1<<" - "<<N1<<"\n";
                cout<<"- Quantidade de votos recebidos: "<<vc1<<"\n";
                cout<<"- Percentual de votos: "<<pvc1<<"%\n\n";

                cout<<"-------------- CANDIDATO(A) 02 --------------\n";
                cout<<C2<<", "<<P2<<" - "<<N2<<"\n";
                cout<<"- Quantidade de votos recebidos: "<<vc2<<"\n";
                cout<<"- Percentual de votos: "<<pvc2<<"%\n\n";

                cout<<"-------------- CANDIDATO(A) 03 --------------\n";
                cout<<C3<<", "<<P3<<" - "<<N3<<"\n";
                cout<<"- Quantidade de votos recebidos: "<<vc3<<"\n";
                cout<<"- Percentual de votos: "<<pvc3<<"%\n\n";

                cout<<"-------------- CANDIDATO(A) 04 --------------\n";
                cout<<C4<<", "<<P4<<" - "<<N4<<"\n";
                cout<<"- Quantidade de votos recebidos: "<<vc4<<"\n";
                cout<<"- Percentual de votos: "<<pvc4<<"%\n\n";

                cout<<"----------------------------------------------\n\n\n";

                //------------------------------------------------------------
                // Gráfico de linhas
                //------------------------------------------------------------

                cout<<"------------- GRÁFICO DE LINHAS -------------\n\n";
                    //------------------------------------------------------------
                    // Candidato 01
                    //------------------------------------------------------------
                    cout<<C1<<"\n\n";
                    for(linha=1;linha<=vc1;linha++)
                    {
                        cout<<"#";
                    }
                    cout<<vc1<<"\n\n";

                    //------------------------------------------------------------
                    // Candidato 02
                    //------------------------------------------------------------
                    cout<<C2<<"\n\n";
                    for(linha=1;linha<=vc2;linha++)
                    {
                        cout<<"#";
                    }
                    cout<<vc2<<"\n\n";

                    //------------------------------------------------------------
                    // Candidato 03
                    //------------------------------------------------------------
                    cout<<C3<<"\n\n";
                    for(linha=1;linha<=vc3;linha++)
                    {
                        cout<<"#";
                    }
                    cout<<vc3<<"\n\n";

                    //------------------------------------------------------------
                    // Candidato 04
                    //------------------------------------------------------------
                    cout<<C4<<"\n\n";
                    for(linha=1;linha<=vc4;linha++)
                    {
                        cout<<"#";
                    }
                    cout<<vc4<<"\n\n";

                    //------------------------------------------------------------
                    // Nulos
                    //------------------------------------------------------------
                    cout<<"Nulos\n\n";
                    for(linha=1;linha<=vnulos;linha++)
                    {
                        cout<<"#";
                    }
                    cout<<vnulos<<"\n\n";

                    //------------------------------------------------------------
                    // Brancos
                    //------------------------------------------------------------
                    cout<<"Brancos\n\n";
                    for(linha=1;linha<=vbrancos;linha++)
                    {
                        cout<<"#";
                    }
                    cout<<vbrancos<<"\n\n";
            }
            break;

        //------------------------------------------------------------
        // 4 - SAIR
        //------------------------------------------------------------
        case 4:
            cout<<"Deseja finalizar o programa?\n";
            cout<<"S - Sim | N - Não\n";
            cin>>E;
            if(E=='S' || E=='s')
            {
                cout<<"Programa finalizado.\n";
                n=1;
            }
            else if(E=='N' || 'n')
            {
                cout<<"Redirecionando de volta ao menu...\n\n";
            }

            break;

        default:
            cout<<"Opção inválida. Selecione novamente:\n";
            break;
        }
    }
}
