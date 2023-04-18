/*
**============================================================================
** UC: 21093 - Programação por Objectos - 03
** e-fólio A  2022-23 (efolioGlobal.cpp)
**
** Aluno: 2100927 - Ivo Baptista
** Name        : EfolioG.cpp
** Author      : Ivo Baptista
** Version     : 1.1
** Copyright   : Your copyright notice
** Description : Atividades Imersivas in C++, Ansi-style
** ===========================================================================
*/

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <list>
#include "produto.h"
#include "campanha.h"
#include "loja.h"

int main(int argc, char **argv) {
/************************************************************
            abre ficheiro produtos.csv
************************************************************/
    const std::string kProdutosFilename{"produtos.csv"};
    std::ifstream in_produtos;
    in_produtos.open(kProdutosFilename);
    std::string line;
    std::getline(in_produtos, line);
/************************************************************
    leitura de objeto produto com ponteiro
    inteligentes 
************************************************************/
    std::list<std::shared_ptr<Produto>> list_de_produtos;
    while(!in_produtos.eof()) {
        auto produto = std::make_shared<ProdutoDeLoja>();
        produto->Ler(in_produtos);
        list_de_produtos.push_back(produto); 
    }
/************************************************************
        abre ficheiro descontos.csv
************************************************************/
    const std::string kDescontosFilename{"descontos.csv"};
    std::ifstream in_descontos;
    in_descontos.open(kDescontosFilename);
    std::getline(in_descontos, line);
/************************************************************
     leitura de objeto campanha com ponteiros 
     inteligentes 
************************************************************/
    std::list<std::shared_ptr<Campanha>> list_de_campanhas;
    while(!in_descontos.eof()) {
        auto campanha = std::make_shared<CampanhaAtiva>();
        campanha->Ler(in_descontos);
        list_de_campanhas.push_back(campanha); 
    }
/************************************************************
         mostra na tela a lista de produtos 
************************************************************/
    std::cout << "Produtos" << std::endl;
    std::cout << "========" << std::endl;
    for(auto produto : list_de_produtos) {
        produto->Escrever();
        std::cout << std::endl;
    }
    std::cout << std::endl
              << std::endl
              << std::endl;
/************************************************************
         mostra na tela a lista de capanhas 
************************************************************/
    std::cout << "Campanhas" << std::endl;
    std::cout << "=========" << std::endl;
    for(auto campanha : list_de_campanhas) {
        campanha->Escrever();
        std::cout << std::endl;
    }
    std::cout << std::endl
              << std::endl
              << std::endl;
 /************************************************************
  Carrega os fichiero lidos com os operadores no objeto loja
************************************************************/
    std::cout << "Loja" << std::endl;
    std::cout << "====" << std::endl;
    Loja loja;
    loja = loja + list_de_produtos;
    loja = loja + list_de_campanhas;
    loja.Escrever();


    return EXIT_SUCCESS;
}
