#include "FaseExemplo.h"

#include "Tile.h"
#include "Vilao.h"

#include <fstream>

namespace exercicio {
    FaseExemplo::FaseExemplo(GerenciadorGrafico& gg, Heroi* jogador1/* = nullptr*/) : Fase{ gg,
    new GerenciadorTiles{
      {
       //new Tile(Ids::heroi, "boneco.png"),
        new Tile(Ids::armadilha_direita, "armadilha_direita.png"),
        new Tile(Ids::armadilha_esquerda,"armadilha_esquerda.png"),
        new Tile(Ids::espinho,"espinho.png"),
        new Tile(Ids::espinho_direita,"espinho_direita.png"),
        new Tile(Ids::espinho_esquerda,"espinho_esquerda.png"),
        new Tile(Ids::teste_fundo2,"teste_fundo2.png"),
        new Tile(Ids::parede_up, "parede_up.png"),
        new Tile(Ids::espinho_fundo,"espinho_fundo2.png"),
        new Tile(Ids::esquerda2,"esquerda2.png"),
        new Tile(Ids::fundo,"fundo.png"),
        new Tile(Ids::fundo1,"fundo1.png"),
        
        new Tile(Ids::parede_clara,"parede_clara.png"),
        new Tile(Ids::parede_up,"parede_clara.png"),
        // new Tile(Ids::personagem,"personagem.png"),
        new Tile(Ids::porta,"porta.png"),
        new Tile(Ids::prisao,"prisao.png"),
       // new Tile(Ids::teste,"teste.png"),
        new Tile(Ids::teste_fundo,"teste_fundo.png"),
        new Tile(Ids::espinho_fundo,"espinho_fundo.png"),
        new Tile(Ids::teste_chama,"teste_chama.png"),
        new Tile(Ids::teste_fundo2,"teste_fundo2.png"),
        new Tile(Ids::espinho_fundo2,"espinho_fundo2.png"),
        new Tile(Ids::esquerda2,"esquerda2.png"),
      },
      {32.0f, 32.0f}, "../TileMap/TileMap.json"
    }
    , jogador1 } {

    }

    nlohmann::json FaseExemplo::paraJSON() {
        nlohmann::json json;

        json["amigos"] = listaAmigos.paraJSON();

        return json;

    }

    void FaseExemplo::carregar(const std::string& caminho) {
        std::ifstream arquivo(caminho);
        if (arquivo.fail()) throw "arquivo nao encontrado!";
        nlohmann::json j;
        arquivo >> j;

        for (nlohmann::json amigo : j["amigos"]) {
            switch (static_cast<int> (amigo["id"]))
            {
            case Ids::heroi:
                if (jogador1) {
                    jogador1->inicializarComJSON(amigo);
                    listaAmigos.inserir(jogador1);
                }
                break;
            case Ids::vilao:
                listaAmigos.inserir(new Vilao(amigo));
                break;
            default:
                break;
            }
        }

        listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
    }

    void FaseExemplo::inicializar() {
        if (jogador1) listaAmigos.inserir(jogador1);

        listaAmigos.inserir(new Vilao(Vetor2F(40.0f, 50.0f), Vetor2F(0, 10)));
        listaAmigos.inserir(new Vilao(Vetor2F(40.0f, 100.0f), Vetor2F(0, -10)));
        listaAmigos.inserir(new Vilao(Vetor2F(80.0f, 50.0f), Vetor2F(0, -10)));
        listaAmigos.inserir(new Vilao(Vetor2F(80.0f, 100.0f), Vetor2F(0, 10)));

        listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

    }

}