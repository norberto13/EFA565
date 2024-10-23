#include <iostream>
#include <string>
using namespace std;

class Veiculo {
private:
    string matricula;
    double quilometragem; // Quilometragem total
    double capacidadeDeposito; // Capacidade total do dep�sito
    double litrosNoDeposito; // Litros de combust�vel atualmente no dep�sito
    double consumoPor100km; // Consumo m�dio aos 100 km
    int contadorViagens; // Contador de viagens realizadas

public:
    // Construtor
    Veiculo(string m, double km, double capacidade, double litros, double consumo)
        : matricula(m), quilometragem(km), capacidadeDeposito(capacidade), litrosNoDeposito(litros), consumoPor100km(consumo), contadorViagens(0) {}

    // M�todo para determinar quantos km � poss�vel percorrer com o combust�vel atual
    double calcularAutonomia() const {
        return (litrosNoDeposito / consumoPor100km) * 100;
    }

    // M�todo para registar uma viagem de K quil�metros
    bool registrarViagem(double kmViagem) {
        double combustivelNecessario = (kmViagem / 100) * consumoPor100km;
        if (combustivelNecessario > litrosNoDeposito) {
            cout << "Combust�vel insuficiente para a viagem." << endl;
            return false;
        }
        litrosNoDeposito -= combustivelNecessario;
        quilometragem += kmViagem;
        contadorViagens++;
        return true;
    }

    // M�todo para determinar se o ve�culo entrou na reserva
    bool emReserva() const {
        return litrosNoDeposito <= 10;
    }

    // M�todo para calcular o valor total gasto em combust�vel
    double calcularGastoTotal(double precoPorLitro) const {
        double litrosConsumidos = capacidadeDeposito - litrosNoDeposito;
        return litrosConsumidos * precoPorLitro;
    }

    // M�todo para calcular o custo m�dio por quil�metro
    double calcularCustoPorKm(double precoPorLitro) const {
        return (precoPorLitro * consumoPor100km) / 100;
    }

    // M�todo para abastecer o ve�culo
    void abastecer(double litros) {
        if (litros <= 0) {
            cout << "Quantidade inv�lida de litros." << endl;
            return;
        }
        double espacoDisponivel = capacidadeDeposito - litrosNoDeposito;
        if (litros > espacoDisponivel) {
            litrosNoDeposito = capacidadeDeposito;
            cout << "Dep�sito cheio. N�o foi poss�vel abastecer completamente." << endl;
        } else {
            litrosNoDeposito += litros;
            cout << "Abastecimento realizado com sucesso." << endl;
        }
    }

    // M�todo para exibir informa��es do ve�culo (opcional)
    void exibirInformacoes() const {
        cout << "Matr�cula: " << matricula << endl;
        cout << "Quilometragem total: " << quilometragem << " km" << endl;
        cout << "Capacidade do dep�sito: " << capacidadeDeposito << " litros" << endl;
        cout << "Litros no dep�sito: " << litrosNoDeposito << " litros" << endl;
        cout << "Consumo m�dio: " << consumoPor100km << " litros/100 km" << endl;
        cout << "Viagens realizadas: " << contadorViagens << endl;
    }
};

int main() {
    // Criando um objeto da classe Veiculo
    Veiculo carro("ABC-1234", 50000, 60, 30, 8); // Matricula, Quilometragem, Capacidade, Litros no Dep�sito, Consumo

    carro.exibirInformacoes();

    cout << "\nAutonomia: " << carro.calcularAutonomia() << " km" << endl;

    if (carro.registrarViagem(200)) {
        cout << "\nViagem de 200 km registrada com sucesso." << endl;
    }

    cout << "O ve�culo est� em reserva? " << (carro.emReserva() ? "Sim" : "N�o") << endl;

    double precoCombustivel = 1.5; // Exemplo de pre�o por litro
    cout << "\nCusto total gasto em combust�vel: " << carro.calcularGastoTotal(precoCombustivel) << " euros" << endl;
    cout << "Custo m�dio por km: " << carro.calcularCustoPorKm(precoCombustivel) << " euros/km" << endl;

    carro.abastecer(20); // Tenta abastecer 20 litros
    carro.exibirInformacoes();

    return 0;
}
