#pragma once
#include "Vetor2D.h"
#include "Ids.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

namespace Jogo {
    namespace Tile {
        class Tile {

        private:
            const Ids::Ids id;
            const char* caminho;
            Vetor2F tamanho;

        public:
            Tile(const Ids::Ids ID = Ids::semID, const char* caminhoArquivo = nullptr, Vetor2F Tamanho = { 32.0f, 32.0f });
            virtual ~Tile();
            virtual void inicializar(Gerenciador::GerenciadorGrafico& gg, Gerenciador::GerenciadorEventos& ge);
            void desenhar(Gerenciador::GerenciadorGrafico& gg, const Vetor2F posicao) const;
            const Ids::Ids getId() const;
            virtual void colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2U posicao);

        };
    }
}