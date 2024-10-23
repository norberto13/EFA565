#include <iostream>
#include <string>
using namespace std;

class Veiculo {
private:
    string matricula;
    double quilometragem; // Quilometragem total
    double capacidadeDeposito; // Capacidade total do depósito
    double litrosNoDeposito; // Litros de combustível atualmente no depósito
    double consumoPor100km; // Consumo médio aos 100 km
    int contadorViagens; // Contador de viagens realizadas

public:
    // Construtor
    Veiculo(string m, double km, double capacidade, double litros, double consumo)
        : matricula(m), quilometragem(km), capacidadeDeposito(capacidade), litrosNoDeposito(litros), consumoPor100km(consumo), contadorViagens(0) {}

    // Método para determinar quantos km é possível percorrer com o combustível atual
    double calcularAutonomia() const {
        return (litrosNoDeposito / consumoPor100km) * 100;
    }

    // Método para registar uma viagem de K quilómetros
    bool registrarViagem(double kmViagem) {
        double combustivelNecessario = (kmViagem / 100) * consumoPor100km;
        if (combustivelNecessario > litrosNoDeposito) {
            cout << "Combustível insuficiente para a viagem." << endl;
            return false;
        }
        litrosNoDeposito -= combustivelNecessario;
        quilometragem += kmViagem;
        contadorViagens++;
        return true;
    }

    // Método para determinar se o veículo entrou na reserva
    bool emReserva() const {
        return litrosNoDeposito <= 10;
    }

    // Método para calcular o valor total gasto em combustível
    double calcularGastoTotal(double precoPorLitro) const {
        double litrosConsumidos = capacidadeDeposito - litrosNoDeposito;
        return litrosConsumidos * precoPorLitro;
    }

    // Método para calcular o custo médio por quilómetro
    double calcularCustoPorKm(double precoPorLitro) const {
        return (precoPorLitro * consumoPor100km) / 100;
    }

    // Método para abastecer o veículo
    void abastecer(double litros) {
        if (litros <= 0) {
            cout << "Quantidade inválida de litros." << endl;
            return;
        }
        double espacoDisponivel = capacidadeDeposito - litrosNoDeposito;
        if (litros > espacoDisponivel) {
            litrosNoDeposito = capacidadeDeposito;
            cout << "Depósito cheio. Não foi possível abastecer completamente." << endl;
        } else {
            litrosNoDeposito += litros;
            cout << "Abastecimento realizado com sucesso." << endl;
        }
    }

    // Método para exibir informações do veículo (opcional)
    void exibirInformacoes() const {
        cout << "Matrícula: " << matricula << endl;
        cout << "Quilometragem total: " << quilometragem << " km" << endl;
        cout << "Capacidade do depósito: " << capacidadeDeposito << " litros" << endl;
        cout << "Litros no depósito: " << litrosNoDeposito << " litros" << endl;
        cout << "Consumo médio: " << consumoPor100km << " litros/100 km" << endl;
        cout << "Viagens realizadas: " << contadorViagens << endl;
    }
};

int main() {
    // Criando um objeto da classe Veiculo
    Veiculo carro("ABC-1234", 50000, 60, 30, 8); // Matricula, Quilometragem, Capacidade, Litros no Depósito, Consumo

    carro.exibirInformacoes();

    cout << "\nAutonomia: " << carro.calcularAutonomia() << " km" << endl;

    if (carro.registrarViagem(200)) {
        cout << "\nViagem de 200 km registrada com sucesso." << endl;
    }

    cout << "O veículo está em reserva? " << (carro.emReserva() ? "Sim" : "Não") << endl;

    double precoCombustivel = 1.5; // Exemplo de preço por litro
    cout << "\nCusto total gasto em combustível: " << carro.calcularGastoTotal(precoCombustivel) << " euros" << endl;
    cout << "Custo médio por km: " << carro.calcularCustoPorKm(precoCombustivel) << " euros/km" << endl;

    carro.abastecer(20); // Tenta abastecer 20 litros
    carro.exibirInformacoes();

    return 0;
}
