#include <iostream>
#include <string>
#include <sstream>
#include "campanha.h"

const std::string Campanha::GetTitulo() {
    return titulo_;
}

void Campanha::SetTitulo(const std::string &titulo) {
    titulo_ = titulo;
}

const float Campanha::GetDesconto() {
    return desconto_;
}

void Campanha::SetDesconto(float desconto) {
    desconto_ = desconto;
}

/************************************************************
       metodo ler recebendo um stream como parametro
************************************************************/
void Campanha::Ler(std::istream &in) {
    constexpr char kCommaDelimiter{','};
    std::string line;

    std::getline(in, line);

    std::stringstream ss{line};
    std::string token;

    if(std::getline(ss, token, kCommaDelimiter)) {
        SetTitulo(token);
    }

    if(std::getline(ss, token, kCommaDelimiter)) {
        SetDesconto(std::stof(token));
    }
}
/************************************************************
           metodo escrever sem parametro
************************************************************/
void Campanha::Escrever() {
    std::cout << GetTitulo() << "; "
              << GetDesconto();
}

