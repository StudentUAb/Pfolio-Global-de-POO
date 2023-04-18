#include <iostream>
#include <string>
#include <sstream>
#include "produto.h"

const std::string Produto::GetNome() {
    return nome_;
}

void Produto::SetNome(const std::string &nome) {
    nome_ = nome;
}

const std::string Produto::GetDescricao() {
    return descricao_;
}

void Produto::SetDescricao(const std::string &descricao) {
    descricao_ = descricao;
}

const float Produto::GetPreco() {
    return preco_;
}

void Produto::SetPreco(float preco) {
    preco_ = preco;
}
/************************************************************
       metodo ler recebendo um stream como parametro
************************************************************/
void Produto::Ler(std::istream &in) {
    constexpr char kCommaDelimiter{','};
    std::string line;

    std::getline(in, line);

    std::stringstream ss{line};
    std::string token;

    if(std::getline(ss, token, kCommaDelimiter)) {
        SetNome(token);
    }

    if(std::getline(ss, token, kCommaDelimiter)) {
        SetDescricao(token);
    }

    if(std::getline(ss, token, kCommaDelimiter)) {
        SetPreco(std::stof(token));
    }
}
/************************************************************
           metodo escrever sem parametro
************************************************************/
void Produto::Escrever() {
    std::cout << GetNome() << "; "
              << GetDescricao() << "; "
              << GetPreco();
}

