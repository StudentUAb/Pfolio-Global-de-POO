#pragma once
#include <string>
#include <vector>
#include <fstream>

/************************************************************
            definiçao de classe Campanha
************************************************************/
class Campanha {
    public:

/************************************************************
  declaramos metodo ler recebendo um stream como parametro
************************************************************/
        void Ler(std::istream &is);

/************************************************************
           declaramos metodo escrever sem parametro
************************************************************/
        virtual void Escrever();

        const std::string GetTitulo();
        void SetTitulo(const std::string &titulo);

        const float GetDesconto();
        void SetDesconto(float desconto);

    private:
        std::string titulo_;
        float desconto_{0.0};
};

