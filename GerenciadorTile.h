#pragma once
#include "Tile.h"
#include "TileMap.h"
#include "Vetor2D.h"
#include "Ids.h"

#include <vector>

namespace Jogo {
    namespace Gerenciador {
        class GerenciadorEventos;
        class GerenciadorGrafico;
        class GerenciadorColisoes;

        class GerenciadorTiles {

        public:
            typedef struct idpostam {
                const Ids::Ids id;
                const Vetor2F posicao;
                const Vetor2F tamanho;
            } IdPosicaoTamanho;


        private:
            std::vector<Tile::Tile*> tiles;
            Vetor2F dimensoesTiles;
            const char* caminho;
            Tile::TileMap tileMap;

        public:
            GerenciadorTiles(std::vector<Tile::Tile*> Tiles = {}, Vetor2F dimensoes = { 0.0f, 0.0f }, const char* caminhoArquivo = nullptr);
            ~GerenciadorTiles();
            void inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge);
            void desenhar(GerenciadorGrafico& g) const;
            std::vector<IdPosicaoTamanho> checarColisoes(const Ids::Ids id, Vetor2F posicao, Vetor2F tamanho);

        private:
            const Vetor2F converterCoordenadasMapaParaTela(const Vetor2U pos) const;
        };
        using IdPosicaoTamanho = GerenciadorTiles::IdPosicaoTamanho;
    }
}
