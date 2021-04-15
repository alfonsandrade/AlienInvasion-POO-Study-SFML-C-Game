#pragma once
#include "Colidivel.h"
#include "Ids.h"

namespace Jogo {
    namespace Desenhaveis {
        class Alien : public Colidivel {
        private:
            Vetor::Vetor2F ajustes;
        public:

            Alien(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
            Alien(nlohmann::json fonte);
            ~Alien();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);

        };
    }
}
