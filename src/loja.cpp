#include <fstream>
#include <string>
#include "loja.h"
#include <iostream>

/************************************************************
  lista de objestos produtodeloja que tem stock diponivel
************************************************************/
void ProdutoDeLoja::SetStock(int stock) {
    stock_ = stock;
}

/************************************************************
  lista de objestos produtodeloja que tem stock diponivel
************************************************************/
int ProdutoDeLoja::GetStock() {
    return stock_;
}

void ProdutoDeLoja::Escrever() {
    Produto::Escrever();
    std::cout << "; "
              << GetStock();
}

/************************************************************
  lista de objestos campanhaativa verifica se ta ativa ou nao
************************************************************/
void CampanhaAtiva::SetAtiva(bool ativa) {
    ativa_ = ativa;
}

/************************************************************
  lista de objestos campanhaativa verifica se ta ativa ou nao
************************************************************/
bool CampanhaAtiva::GetAtiva() {
    return ativa_;
}

void CampanhaAtiva::Escrever() {
    Campanha::Escrever();
    std::cout << "; "
              << (GetAtiva() ? "ATIVA" : "NÃO ATIVA");
}

Loja::~Loja() {
    while(!produtos_.empty()) {
        produtos_.pop_back();
    }

    while(!campanhas_.empty()) {
        campanhas_.pop_back();
    }
}

/************************************************************
              definição de operadores 
************************************************************/
Loja Loja::operator+(std::list<std::shared_ptr<Produto>> &other) {
    produtos_.insert(std::end(produtos_)
                   , std::begin(other)
                   , std::end(other));
    return *this;
}

/************************************************************
              definição de operadores 
************************************************************/
Loja Loja::operator+(std::list<std::shared_ptr<Campanha>> &other) {
    campanhas_.insert(std::end(campanhas_)
                    , std::begin(other)
                    , std::end(other));
    return *this;
}

/************************************************************
            metodo escrever no objeto loja 
************************************************************/
void Loja::Escrever() {
    std::cout << "Produtos em Stock da Loja" << std::endl;
    std::cout << "===========================" << std::endl;
    for(auto produto : produtos_) {
        (static_cast<ProdutoDeLoja *>(produto.get()))->Escrever();
        std::cout << std::endl;
    }
    std::cout << "===========================" << std::endl << std::endl;

    std::cout << std::endl
              << std::endl
              << std::endl;

    std::cout << "Campanhas da Loja" << std::endl;
    std::cout << "=================" << std::endl;
    for(auto campanha : campanhas_) {
        (static_cast<CampanhaAtiva *>(campanha.get()))->Escrever();
        std::cout << std::endl;
    }
    std::cout << "===========================" << std::endl << std::endl;
}