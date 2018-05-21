#include <iostream>
#include "Dominios.hpp"
#include "Dominios.cpp"
#include "Entidades.hpp"
#include "interfaces.h"
#include "MAAUT.h"
#include "MSAUT.cpp"


using namespace std;



int MAAUT :: logar(Administrador *usuario)
{

    Email emailLido;
    Senha senhaLida;
    Nome teste;
    Administrador usuarioS;

    string email;
    string senha;

    int tipoUsr =0;
    bool logado=false;
    bool emailVal=false;
    bool senhaVal=false;

    cout<<"Para efetuar o login, selecione o tipo de usu�rio, digite  o email e a senha: \n"<<endl;
    while(!logado)
    {
          while(tipoUsr!= ADM && tipoUsr!= DESENVOL && tipoUsr!= LEITOR )
          {
              cout<<"1. LEITOR"<<endl;
              cout<<"2. DESENVOLVEDor"<<endl;
              cout<<"3.ADMINISTRADOR \n"<<endl;
              cout <<">> ";
              cin >> tipoUsr;

              if(tipoUsr!= ADM && tipoUsr!= DESENVOL && tipoUsr!= LEITOR )
                    cout<<"Tipo de usu�rio n�o reconhecido, por favor selecione novamente:" <<endl;
          }

          try
          {
              if(!emailVal)
              {
                    cout<<"Email: ";
                    cin >> email;
                    cout<<email<<endl;
                    emailLido.setEmail(email);
                    emailVal=true;
              }

              if(!senhaVal)
              {
                   cout<<"Senha: ";
                   cin >> senha;
                   senhaLida.setSenha(senha);
                   senhaVal=true;
              }

          }

          catch (invalid_argument)
          {
              if(emailVal==false)
                    cout<<"Formato de email inv�lido, por favor tente novamente: "<<endl;

              if(senhaVal == false && emailVal==true)
                    cout << "Formato de senha inv�lido, por favor digite novamente: " <<endl;
          }

          if(senhaVal==true && emailVal==true)
          {
                usuario->setEmail(emailLido);
                usuario->setSenha(senhaLida);
                usuarioS.setEmail(emailLido);
                usuarioS.setSenha(senhaLida);
                IsAut *aut = new MsAut();
                try
                {
                    logado = aut->autenticar(&usuario,tipoUsr);
                    if(logado==false )
                    {
                        tipoUsr = 0;
                        senhaVal = false;
                        emailVal = false;
                        cout<<"Usu�rio e senha n�o encontrados, tente novamente."<<endl;
                    }
                }
                catch(runtime_error &exp)
                {
                    cout<<"Ocorreu um erro de sistema no acesso aos dados,";
                    cout<<"Ligue para (61) 99990-8742 se o problema insistir."<<endl;
                    tipoUsr = 0;
                    senhaVal = false;
                    emailVal = false;
                    logado =1;
                }
          }
    }

    return(tipoUsr);
}
