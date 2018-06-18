#include  <iostream>
#include "MACON.h"
#include "Dominios.hpp"
#include "Entidades.hpp"
#include "MAUSR.h"
#include "MAAUT.h"
#include"ListaUSR.h"

using namespace std;

void MaCon:: menuEscolha()
{
    ResultadoUSR resultado;
    ListaUSR lista;

    Usuario usu_1;
    Email email1;
    Senha senha1;
    Nome  nome1;
    Sobrenome sobrenome1;
    email1.setEmail("joaolucascruz411@gmail");
    senha1.setSenha("Piccolo1");
    nome1.setNome("Joao");
    sobrenome1.setSobreNome("Cruz");

    Usuario usu_2;
    Email email2;
    Senha senha2;
    Nome  nome2;
    Sobrenome sobrenome2;
    email2.setEmail("barbosa@gmail");
    senha2.setSenha("Piccolo2");
    nome2.setNome("Matheus");
    sobrenome2.setSobreNome("Barboso");


    Usuario usu_3;
    Email email3;
    Senha senha3;
    Nome  nome3;
    Sobrenome sobrenome3;
    email3.setEmail("burro@gmail");
    senha3.setSenha("Piccolo3");
    nome3.setNome("Pedro");
    sobrenome3.setSobreNome("Trouxa");

    usu_1.usuarioL.setEmail(email1);
    usu_1.usuarioL.setSenha(senha1);
    usu_1.usuarioL.setNome(nome1);
    usu_1.usuarioL.setSobrenome(sobrenome1);

    usu_2.usuarioL.setEmail(email2);
    usu_2.usuarioL.setSenha(senha2);
    usu_2.usuarioL.setNome(nome2);
    usu_2.usuarioL.setSobrenome(sobrenome2);

    usu_3.usuarioL.setEmail(email3);
    usu_3.usuarioL.setSenha(senha3);
    usu_3.usuarioL.setNome(nome3);
    usu_3.usuarioL.setSobrenome(sobrenome3);


    resultado = lista.incluir(usu_1,1);
    resultado = lista.incluir(usu_2,1);
    resultado = lista.incluir(usu_3,1);

    int opcao;
    int tipoUsr=0;
    Nome nome;

    while(opcao != 4){

        if(tipoUsr == LEITOR )
        {
            nome = (usuario.usuarioL).getNome();
            cout<<"Logado como: "<<nome.getNome()<<endl;
            cout<<"permiss�o: Leitor"<<endl;
        }

        if(tipoUsr == DESENVOLVEDOR)
        {
            nome = (usuario.usuarioD).getNome();
            cout<<"Logado como: "<<nome.getNome()<<endl;
            cout<<"permiss�o: Desenvolvedor"<<endl;
        }
        if(tipoUsr == ADMINISTRADOR)
        {
            nome = (usuario.usuarioA).getNome();
            cout<<"Logado como: "<<nome.getNome()<<endl;
            cout<<"permiss�o: Administrador"<<endl;
        }
        cout<<"Bem vindo � lista de vocabul�rio controlado, escolha a a��o que deseja realizar"<<endl;
        cout<<"1.Login"<<endl;
        cout<<"2.Gerir/criar conta"<<endl;
        cout<<"3.Acesso ao vocabulario"<<endl;
        cout<<"4.Sair"<<endl;
        cout<<">>"<<endl;
        cin >> opcao;
        if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4)
        {
            cout<<"op��o inv�lida, escolha uma op��o mostrada"<<endl;
        }
        if(opcao == 1)
        {
            IaAut *log = new MAAUT();
            tipoUsr = log->logar(&usuario, &lista);
            opcao = 0;
        }
        if(opcao== 2)
        {
            IaUsr *conta = new MaUsr();
            conta->opcoesDeUsuario(&usuario,&tipoUsr,&lista);
        }
    }
}
