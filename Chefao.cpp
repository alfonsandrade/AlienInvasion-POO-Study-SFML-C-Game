#include "Chefao.h"

#include <iostream>

namespace Jogo {
    namespace Desenhaveis {
        Chefao::Chefao(Vetor::Vetor2F pos /*= {0.0f, 0.0f}*/, Vetor::Vetor2F vel /*= {0.0f, 0.0f}*/) :
            Colidivel(pos, vel, Ids::vilao, "inimigo2.png") {

        }

        Chefao::Chefao(nlohmann::json fonte) : Chefao({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        Chefao::~Chefao() {

        }

        void Chefao::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void Chefao::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {

            if (idOutro == Ids::heroi) {
                std::cout << "nhac nhac nham nham heroi gostoso" << std::endl;

            }
            else if (idOutro == Ids::vilao) {

                Vetor::Vetor2F distancia = posicao - posicaoOutro;

                posicao += distancia * (1 / 2);



                std::cout << "po desculpa ai cumpadi" << std::endl;
                v.x *= -1;
                v.y *= -1;
            }
            else if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara)
            {
                Vetor::Vetor2F distancia = posicao - posicaoOutro;

                posicao += distancia * (1 / 2);

                std::cout << "po desculpa ai cumpadi" << std::endl;
                v.x *= -1;
            }
            else if (idOutro == Ids::parede_up)
            {
                Vetor::Vetor2F distancia = posicao - posicaoOutro;

                posicao -= distancia * (1 / 2);

                std::cout << "po desculpa ai cumpadi" << std::endl;
                v.x *= -1;
            }
            else if (idOutro == Ids::parede_clara)
            {

            }
        }
    }
}