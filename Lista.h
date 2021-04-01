#pragma once

namespace Jogo {
    namespace Lista {
        template <typename TF>
        class Lista {
        private:

            template <typename TE>
            class ElementoLista {
            private:
                TE info;
                ElementoLista* ant;
                ElementoLista* prox;

            public:
                ElementoLista(TE Info = nullptr, ElementoLista* Ant = nullptr, ElementoLista* Prox = nullptr);
                ~ElementoLista();

                TE getInfo() const;
                void setInfo(TE Info);

                ElementoLista* getAnt() const;
                void setAnt(ElementoLista* Ant);

                ElementoLista* getProx() const;
                void setProx(ElementoLista* Prox);

                void remover();
            };

            ElementoLista<TF>* inicio;
            ElementoLista<TF>* fim;
            ElementoLista<TF>* atual;

        public:

            Lista();
            ~Lista();

            void inserir(TF info);
            void esvaziar();

            TF voltarInicio(); //retorna para o in�cio e retorna o primeiro elemento da lista
            TF irProximo(); //vai para o pr�ximo elemento da lista e retorna o pr�ximo
            void removerPrimeiro(TF elemento);

        };
    }
}

#include "ListaImplementacao.h"