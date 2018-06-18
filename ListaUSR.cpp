#include "ListaUSR.h"

ResultadoUSR ListaUSR::incluir (Usuario usuario,int tipoUsr)
{

    ResultadoUSR resultado;
    string email;
    switch(tipoUsr)
    {
        case LEITOR:
            email = usuario.usuarioL.getEmail().getEmail();
            for(list<Usuario>::iterator elemento = lista.begin(); elemento != lista.end(); elemento++)
            {
                // A falha ocorre caso esse Email j� esteja cadastrado como Leitor
                if(elemento->usuarioL.getEmail().getEmail()== email)
                {
                    resultado.setResultado(ResultadoUSR::FALHA);
                    return(resultado);
                }
            }
        break;
        case DESENVOLVEDOR:
            email = usuario.usuarioD.getEmail().getEmail();
            // A falha ocorre caso esse Email j� esteja cadastrado como Desenvolvedor
            for(list<Usuario>::iterator elemento = lista.begin(); elemento != lista.end(); elemento++)
            {
                if(elemento->usuarioD.getEmail().getEmail()== email)
                {
                    resultado.setResultado(ResultadoUSR::FALHA);
                    return(resultado);
                }
            }
        break;
        case ADMINISTRADOR:
            email = usuario.usuarioA.getEmail().getEmail();
            // A falha ocorre caso esse Email j� esteja cadastrado como Administrador
            for(list<Usuario>::iterator elemento = lista.begin(); elemento != lista.end(); elemento++)
            {
                if(elemento->usuarioA.getEmail().getEmail()== email)
                {
                    resultado.setResultado(ResultadoUSR::FALHA);
                    return(resultado);
                }
            }
        break;
    }
    lista.push_back(usuario);
    resultado.setResultado(ResultadoUSR::SUCESSO);
    return(resultado);
}

ResultadoUSR ListaUSR::pesquisar(Usuario usuario,int tipoUsr)
{
    ResultadoUSR resultado;

    resultado.setResultado(ResultadoUSR::FALHA);
    string email;
    string senha;

    switch(tipoUsr)
    {
        case LEITOR:
            email = (usuario).usuarioL.getEmail().getEmail();
            senha = (usuario).usuarioL.getSenha().getSenha();
        break;
        case DESENVOLVEDOR:
            email = (usuario).usuarioD.getEmail().getEmail();
            senha = (usuario).usuarioD.getSenha().getSenha();
        break;
        case ADMINISTRADOR:
            email = (usuario).usuarioA.getEmail().getEmail();
            senha = (usuario).usuarioA.getSenha().getSenha();
        break;
    }

    for(list<Usuario>::iterator elemento = lista.begin(); elemento != lista.end(); elemento++)
    {

            switch(tipoUsr)
            {
                case LEITOR:
                    if(elemento->usuarioL.getEmail().getEmail() == email && elemento->usuarioL.getSenha().getSenha()==senha)
                    {
                        resultado.setResultado(ResultadoUSR::SUCESSO);
                        (usuario).usuarioL.setNome(elemento->usuarioL.getNome());
                        (usuario).usuarioL.setSobrenome(elemento->usuarioL.getSobrenome());
                    }
                break;
                case DESENVOLVEDOR:
                    if(elemento->usuarioD.getEmail().getEmail() == email && elemento->usuarioD.getSenha().getSenha()==senha)
                    {
                        resultado.setResultado(ResultadoUSR::SUCESSO);
                        (usuario).usuarioL.setNome(elemento->usuarioD.getNome());
                        (usuario).usuarioD.setSobrenome(elemento->usuarioD.getSobrenome());
                        (usuario).usuarioD.setData(elemento->usuarioD.getData());
                    }
                break;
                case ADMINISTRADOR:
                    if(elemento->usuarioA.getEmail().getEmail() == email && elemento->usuarioA.getSenha().getSenha()==senha)
                    {
                        resultado.setResultado(ResultadoUSR::SUCESSO);
                        (usuario).usuarioA.setNome(elemento->usuarioD.getNome());
                        (usuario).usuarioA.setSobrenome(elemento->usuarioA.getSobrenome());
                        (usuario).usuarioA.setData(elemento->usuarioA.getData());
                        (usuario).usuarioA.setTelefone(elemento->usuarioA.getTelefone());
                        (usuario).usuarioA.setEndereco(elemento->usuarioA.getEndereco());
                    }
                break;
            }
    }
    // coment
   resultado.setUsuario(usuario);
   return(resultado);
}

ResultadoUSR ListaUSR:: substituir(Usuario usuario, int tipoUsr)
{
    ResultadoUSR resultado;

    switch(tipoUsr)
    {

        case LEITOR:

            for(list<Usuario>::iterator elemento = lista.begin(); elemento != lista.end(); elemento++)
            {

                if(elemento->usuarioL.getEmail().getEmail()== usuario.usuarioL.getEmail().getEmail())
                {
                    resultado.setUsuario(usuario);
                    elemento->usuarioL.setNome(usuario.usuarioL.getNome());
                    elemento->usuarioL.setSobrenome(usuario.usuarioL.getSobrenome());
                    elemento->usuarioL.setSenha(usuario.usuarioL.getSenha());
                    elemento->usuarioL.setEmail(usuario.usuarioL.getEmail());
                }
            }

        break;
        case DESENVOLVEDOR:

            for(list<Usuario>::iterator elemento = lista.begin(); elemento != lista.end(); elemento++)
            {

                if(elemento->usuarioD.getEmail().getEmail()== usuario.usuarioD.getEmail().getEmail())
                {
                    resultado.setUsuario(usuario);
                    elemento->usuarioD.setNome(usuario.usuarioD.getNome());
                    elemento->usuarioD.setSobrenome(usuario.usuarioD.getSobrenome());
                    elemento->usuarioD.setData(usuario.usuarioD.getData());
                    elemento->usuarioD.setSenha(usuario.usuarioD.getSenha());
                    elemento->usuarioD.setEmail(usuario.usuarioD.getEmail());
                }
            }

        break;
        case ADMINISTRADOR:

            for(list<Usuario>::iterator elemento = lista.begin(); elemento != lista.end(); elemento++)
            {

                if(elemento->usuarioD.getEmail().getEmail()== usuario.usuarioD.getEmail().getEmail())
                {
                    resultado.setUsuario(usuario);
                    elemento->usuarioA.setNome(usuario.usuarioA.getNome());
                    elemento->usuarioA.setSobrenome(usuario.usuarioA.getSobrenome());
                    elemento->usuarioA.setData(usuario.usuarioA.getData());
                    elemento->usuarioA.setSenha(usuario.usuarioA.getSenha());
                    elemento->usuarioA.setEmail(usuario.usuarioA.getEmail());
                }
            }

        break;
    }
    return(resultado);
}

bool ListaUSR:: vazia()
{
    if(lista.empty()==true)
        return (true);

    return(false);
}


