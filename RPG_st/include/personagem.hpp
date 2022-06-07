#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <iostream>
#include <string>

class Personagem{
    private:
        std::string m_nome; //!Nome do seu personagem na partida
        int m_pontos; //!Pontuação do jogador
    public:
        /**
         * @brief Setter que recebe o nome do personagem que está jogando
         * @param, o nome do personagem
         */
        void set_nome(std::string);
        /**
         * @brief Getter que retorna o nome do personagem
         * 
         * @return , uma string com o valor de m_nome 
         */
        std::string get_nome();
};

#endif