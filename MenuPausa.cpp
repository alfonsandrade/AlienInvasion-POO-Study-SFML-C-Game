#include "MenuPausa.h"

#include "GerenciadorTelas.h"

namespace Jogo {
    namespace Menu {
        MenuPausa::MenuPausa(Gerenciador::GerenciadorGrafico& gg) : Menu{ gg } {
            gb.adicionarBotao(new Botao({ 200.0f, 100.0f }, { 100, 50 }, "Continuar jogo", [this] {setCodigoRetorno(sairMenuPausa); }));
            gb.adicionarBotao(new Botao({ 200.0f, 180.0f }, { 100, 50 }, "Salvar jogo", [this] {setCodigoRetorno(salvarJogo); }));
            gb.adicionarBotao(new Botao({ 200.0f, 250.0f }, { 100, 50 }, "Menu principal", [this] {setCodigoRetorno(irMenuPrincipal); }));
        }
    }
}