#pragma once
#include "Fase.h"
#include"../Json/json.hpp"

namespace Jogo {
    namespace Fase {
        class FaseFinal : public Fase {
        public:
            FaseFinal(Gerenciador::GerenciadorGrafico& gg, Entidades::Desenhaveis::Heroi* jogador1 = nullptr, Entidades::Desenhaveis::Heroi* jogador2 = nullptr);
            nlohmann::json paraJSON() override;
            void carregar(const std::string& caminho) override;
            void inicializar() override;
        };
    }
}
