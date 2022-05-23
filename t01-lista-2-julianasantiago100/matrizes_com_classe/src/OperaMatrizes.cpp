#include "OperaMatrizes.hpp"

void OperaMatrizes::function_mue(int n,Matriz *m){
    for(int i = 0; i < m->get_linhas_e_colunas().first; i++){ //linha
        for(int y = 0; y < m->get_linhas_e_colunas().second; y++){ //coluna
            m->set_vetor_matriz_lugar_especificado(i,y,(m->get_valor_matriz(i,y) * n));
        }
    }
}

void OperaMatrizes::set_par_matriz(Matriz *m, bool primeira_ou_segunda){ //* Conto de dois em dois
    if(primeira_ou_segunda){ //<! É o início de um cálculo
        this->m_add.first = m;
    }else{
        this->m_add.second = m;
    }
}

void OperaMatrizes::function_add(){
    for(int i = 0; i < this->m_add.first->get_linhas_e_colunas().first; i++){ //*Até a quantidade de linhas da primeira matriz
        for(int y = 0; y < this->m_add.second->get_linhas_e_colunas().second;y++){ //*Até a quantidade de colunas da primeira matriz
            this->m_add.second->set_vetor_matriz_lugar_especificado(i,y,this->m_add.first->get_valor_matriz(i,y) + this->m_add.second->get_valor_matriz(i,y)); //*Seta na posição da segunda matriz, a soma entre os valores que estão nessa posição na matriz 1 e na matriz 2
        }
    }
}

bool OperaMatrizes::function_dot(){
    //Multiplica-se cada linha da primeira matriz por cada coluna da segunda matriz
   std::vector<std::vector<int>> resultado_dot;
    int i_final = 0, y_final = 0, soma_multiplicacao= 0,flag = 0, coluna;
    if(this->m_add.first->get_linhas_e_colunas().second == this->m_add.second->get_linhas_e_colunas().first){
        //Meu resultado tem o número de linhas da primeira matriz
        resultado_dot.resize(this->m_add.first->get_linhas_e_colunas().first);
        
        
        for(int i =  0; i < this->m_add.first->get_linhas_e_colunas().first ; i++){
            coluna = 0;
            //meu resultado tem o número de colunas da segunda matriz
            resultado_dot[i].resize(this->m_add.second->get_linhas_e_colunas().second); 
            while(flag < this->m_add.second->get_linhas_e_colunas().second){ //de acordo com a quantidade de colunas da segunda matriz
                for(int y = 0; y < this->m_add.second->get_linhas_e_colunas().second; y++){ //roda pelas minhas colunas da segunda matriz -> UMA DE CADA VEZ
                    soma_multiplicacao += (this->m_add.first->get_valor_matriz(i,y) * this->m_add.second->get_valor_matriz(y,coluna));
                }
                resultado_dot[i_final][y_final] = soma_multiplicacao;
                y_final++;
                coluna++;
                flag++;
                soma_multiplicacao = 0;
            }
            flag = 0;
            i_final++;
            y_final = 0;
        }
        /* Adiciono na segunda matriz o resultado do cálculo (que está em resultado_dot), por conta das considerações
        * gerais do programa. Esta lógica sempre considera a última matriz inserida pelo usuário, como a ma-
        * triz que possui os resultados no final da compilação. Manteremos assim.
        */
        for(int i = 0; i < this->m_add.first->get_linhas_e_colunas().first; i++){
            for(int y = 0; y < this->m_add.first->get_linhas_e_colunas().second; y++){
                this->m_add.second->set_vetor_matriz_lugar_especificado(i,y, resultado_dot[i][y]); //this->m_add.first->get_valor_matriz(i,y)
            }
            resultado_dot[i].clear();
        }
        resultado_dot.clear();
        return true;
    }else{
        return false;
    }
}

bool OperaMatrizes::function_mul(){
    /*Confere se as matrizes possuem as mesmas dimensões */
    if((this->m_add.first->get_linhas_e_colunas().first == this->m_add.second->get_linhas_e_colunas().first) && (this->m_add.first->get_linhas_e_colunas().second == this->m_add.second->get_linhas_e_colunas().second)){
        for(int i = 0; i < this->m_add.second->get_linhas_e_colunas().first; i++){
            for(int y = 0; y < this->m_add.second->get_linhas_e_colunas().second; y++){
                this->m_add.second->set_vetor_matriz_lugar_especificado(i,y,(this->m_add.first->get_valor_matriz(i,y)*(this->m_add.second->get_valor_matriz(i,y))));
            }
        }
        return true;
    }else{
        return false;
    }
}