#pragma once
#include "Obstaculo.h"
#include "Ids.h"

namespace InvasaoAlienigena {
	namespace Obstaculo {
		class BuracoInfinito : public Obstaculo {
		private:
			Vetor::Vetor2F ajustes;

		public:
			BuracoInfinito(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
			BuracoInfinito(nlohmann::json fonte);
			~BuracoInfinito();
			void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
			void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
		};
	}
}

