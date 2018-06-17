#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include <iostream>
#include "Dominios.hpp"
#include "Entidades.hpp"
#include "MACON.h"
#include "ListaUSR.h"


using namespace std;
/*------------------------Interface de apresenta��o de autentica��o------------------------------*/
class IaAut
{
public:

    virtual int logar (Usuario *, ListaUSR *) = 0;

};

/*-------------------------Interface de servi�o de autentica��o----------------------------------*/

class IsAut
{
public:

    virtual bool autenticar (Usuario **, int tipoUsr,ListaUSR **) throw (runtime_error) = 0;

};

/*-----------------------Interface de apresenta��o de gest�o de usuario---------------------------*/

class IaUsr
{
public:

    //virtual void criarConta(int) = 0;
    virtual void opcoesDeUsuario(Usuario*, int *)=0;
    //virtual void deletarUsuario(Usuario*, int*);
    //virtual void editarDados(Usuario*, int*);
};

/*----------------------Interface de servi�o de gest�o de usuario---------------------------------*/

class IsUsr
{

 public:

  virtual void editarDados(Usuario**, int**) throw (runtime_error) =0;
  virtual void deletarUsuario(Usuario**, int**) throw (runtime_error) = 0;
  virtual void criarConta() throw (runtime_error) = 0;

};
#endif // INTERFACES_H_INCLUDED
