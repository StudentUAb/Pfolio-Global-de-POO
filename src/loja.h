#pragma once
#include <memory>
#include <list>
#include "campanha.h"
#include "produto.h"

/************************************************************
  lista de objestos produtodeloja que tem stock diponivel
************************************************************/
class ProdutoDeLoja : public Produto {
    public:
        void SetStock(int stock);
        int GetStock();

        void Escrever() override;

    private:
        int stock_{0};
};

/************************************************************
  lista de objestos campanhaativa verifica se ta ativa ou nao
************************************************************/
class CampanhaAtiva : public Campanha {
    public:
        void SetAtiva(bool ativa);
        bool GetAtiva();

        void Escrever() override;

    private:
        bool ativa_{false};
};

/************************************************************
            definiçao de classe Loja
************************************************************/
class Loja {
    public:
        ~Loja();

/************************************************************
              definição de operadores 
************************************************************/
        Loja operator+(std::list<std::shared_ptr<Produto>> &other);
        Loja operator+(std::list<std::shared_ptr<Campanha>> &other);

        void Escrever();

    private:
/************************************************************
     definição de listas com ponteiros inteligentes 
************************************************************/
        std::list<std::shared_ptr<Produto>> produtos_;
        std::list<std::shared_ptr<Campanha>> campanhas_;
};

