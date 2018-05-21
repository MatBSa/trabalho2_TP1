#include "Entidades.hpp"

#include<iostream>



void Leitor::nomeVsSenha(Nome nome,Senha senha) throw (invalid_argument)
{
    bool nomeNaSenha;

    string name = nome.getNome();
    string password = senha.getSenha();

    nomeNaSenha = findName(password,name);
    //cout << name<<endl;
   // cout << password<<endl;
    if(nomeNaSenha==true)
    {
        throw invalid_argument("\nA senha cont�m o nome\n");

    }
}

 //Esse m�todo tem que sair daqui e ir para as entidades de usu�rio.
 bool Leitor::findName(string senha, string nomeS){

     const int tamNome = 20;
     const int tamSenha = 8;

     char compara[tamNome];
     int i=0,j=0;

     for(i=0;i<8;i++)
     {
     if(senha[i] == nomeS[0])                //Se alguma letra da senha � igual � primeira letra do nome
         {                                   //As pr�ximas letras em sequ�ncia s�o comparaas, at� ser encontrada uma diferen�a
                                             //Ou at� todos os demais caracteres terem sido comparados em sequ�ncia
             while(senha[i+j] == nomeS[j] || i+j <tamSenha){
                 compara[j]= nomeS[j];       // Os caracteres iguais s�o armazenaos
                 j=j+1;

             }
             if(compara==nomeS) // Se o conjunto de caracteres iguais em sequ�ncia conseguir formar o nome
                 return(true);  // Significa que a senha cont�m o nome.
             else
                 j=0;
         }
     }
     return (false);
 }
