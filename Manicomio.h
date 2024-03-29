#pragma once
#include "Fase.h"
#include "Frida.h"
#include"../Json/json.hpp"

namespace InvasaoAlienigena {
    namespace Fase {
        class Manicomio : public Fase {
        public:
            Manicomio(Gerenciador::GerenciadorGrafico& gg, Entidades::Desenhaveis::Kahlo* jogador1 = nullptr, Entidades::Desenhaveis::Frida* jogador2 = nullptr);
            nlohmann::json paraJSON() override;
            void carregar(const std::string& caminho) override;
            void inicializar() override;
           
        };
    }
}
