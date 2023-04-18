#pragma once
#include <string>
#include <fstream>

/************************************************************
            definiçao de classe Produto
************************************************************/
class Produto {
    public:
/************************************************************
  declaramos metodo ler recebendo um stream como parametro
************************************************************/
        void Ler(std::istream &is);
/************************************************************
           declaramos metodo escrever sem parametro
************************************************************/
        virtual void Escrever();

        const std::string GetNome();
        void SetNome(const std::string &nome);

        const std::string GetDescricao();
        void SetDescricao(const std::string &descricao);

        const float GetPreco();
        void SetPreco(float preco);

    private:
        std::string nome_;
        std::string descricao_;
        float preco_{0.0};
};
