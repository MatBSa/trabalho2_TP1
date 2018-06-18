#ifndef MACON_H_INCLUDED
#define MACON_H_INCLUDED

#include "Dominios.hpp"
#include "Entidades.hpp"

class Usuario
/// Classe que armazena os dados de um usuario,
/// Podendo ser um Leitor, um Desenvolvedor ou
/// Um Administrador. Dependendo do tipo de usu�rio
/// Os dados s�o armazenados em um atributo diferente
{
public:

    Leitor usuarioL;
    Desenvolvedor usuarioD;
    Administrador usuarioA;

};

class MaCon
/// Classe de apresenta��o da uniade de controle do sistema
/// Esta deve necessariamente ser instanciada na implementa��o
/// Do sistema para que o usu�rio possa deciir a pr�xima a��o do sistema.
{

private:

    const static int ADMINISTRADOR = 3;
    const static int DESENVOLVEDOR = 2;
    const static int LEITOR = 1;

    Usuario usuario;

public:

    void menuEscolha();
/// Este M�todo apresenta ao usu�rio suas possibilidades de escolha
/// Sobre o que o sistema deve fazer em seguida. Este metodo tambem
/// coleta esta escolha e invoca o metodo necessario para realizar a
/// escolha feita.

};

#endif // MACON_H_INCLUDED
