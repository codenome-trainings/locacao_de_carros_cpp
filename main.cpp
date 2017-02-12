#include <iostream>
#include <stdio_ext.h>
#include <string.h>

using namespace std;

#define MAX_CLIENTES 100
#define MAX_CARROS 100


typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Cliente {
    int id;
    string nome;
    Data dataDeNascimento;
    string cpf;
} Cliente;
int qtd_id_cliente = 20151328;

typedef struct Carro {
    int id;
    string nome;
    string modelo;
    Data ano;
    double valor;
    bool status = false; //Esta Alugado?
} Carro;
int qtd_id_carro = 20151428;

Cliente clientes[MAX_CLIENTES];
int qtd_clientes = 0;

Carro carros[MAX_CARROS];
int qtd_carros = 0;


void menu();
void menuCliente();
void menuAluguel();
void cadastrarCliente();
void buscarCliente();
void listarClientes();
void contaIdCliente();
void contaQtdDeClientes();
void localizaCliente(int i);
void buscaPorIdCliente();
void buscaPorCpfDoCliente();
void menuCarro();
void cadastrarCarro();
void contaIdDosCarros();
void contaQtdDosCarros();
void listaCarros();
void buscarCarro();

void localizaCarro(int i);

int main() {
    menu();
    return 0;
}

void menu() {
    cout << "---------------------------------" << endl;
    cout << "----------MENU PRINCIPAL---------" << endl;
    cout << "---------------------------------" << endl;

    char escolha = ' ';
    cout << "1. Cliente" << endl;
    cout << "2. Carro" << endl;
    cout << "0. Sair" << endl;
    cout << "Digite uma opção: ";
    cin >> escolha;
    switch (escolha) {
        case '0':
            return;
        case '1':
            menuCliente();
            break;
        case '2':
            menuCarro();
            break;
        default:
            cout << "Opção inválida! Tente novamente...";
    }
    menu();
}

void menuCliente() {
    char escolha = ' ';

    cout << "---------------------------------" << endl;
    cout << "---------MENU DE CLIENTES--------" << endl;
    cout << "---------------------------------" << endl;

    cout << "1. Cadastrar cliente" << endl;
    cout << "2. Buscar cliente" << endl;
    cout << "3. Listar Cliente" << endl;
    cout << "0. Voltar" << endl;
    cout << "Digite uma opção: ";
    cin >> escolha;

    switch (escolha) {
        case '0':
            menu();
            break;
        case '1':
            cadastrarCliente();
            break;
        case '2':
            buscarCliente();
            break;
        case '3':
            listarClientes();
            break;
    }
}

void listarClientes() {
    cout << "----------------------------------" << endl;
    cout << "---------LISTA DE CLIENTES--------" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < qtd_clientes; i++) {
        cout << "ID:" << clientes[i].id << endl;
        cout << "NOME: " << clientes[i].nome << endl;
        cout << "DATA DE NASCIMENTO: "
             << clientes[i].dataDeNascimento.dia
             << "/" << clientes[i].dataDeNascimento.mes
             << "/" << clientes[i].dataDeNascimento.ano
             << endl;
        cout << "CPF: " << clientes[i].cpf<< endl;

        cout << endl;
        cout << "---" << endl;
        cout << endl;
    }
    cout << "Clientes listados com sucesso!" << endl;
    cout << "Pressione qualquer tecla para continuar...";
    __fpurge(stdin);
    getchar();
    menuCliente();

}

void buscarCliente() {

    char escolha = ' ';


    cout << "Método de busca de um cliente: [1] ID | [0]CPF - _ ";
    cin >> escolha;

    if (escolha == '1') {
        buscaPorIdCliente();
    } else if (escolha == '0'){
        buscaPorCpfDoCliente();
    } else {
        cout << "Opção inválida! Tente novamente ..." << endl;
        buscarCliente();
    }

}

void buscaPorCpfDoCliente() {

    bool encontrou = false;
    string cpf_cliente;

    __fpurge(stdin);
    cout << "CPF do cliente: ";
    getline(cin, cpf_cliente);

    for (int i = 0; i < qtd_clientes; ++i) {

        if(clientes[i].cpf == cpf_cliente) {
            cout << endl;
            cout << endl;
            cout << "Cliente encontrado com sucesso!" << endl;
            localizaCliente(i);
            encontrou = true;
            break;
        }
    }

    if (encontrou == false) {
        cout << "Cliente não encontrado!" << endl;
    }
}

void buscaPorIdCliente() {

    bool encontrou = false;
    int id_cliente = 0;

    cout << "ID do cliente: ";
    cin >> id_cliente;

    for (int i = 0; i < qtd_clientes; ++i) {
        if(id_cliente == clientes[i].id) {
            cout << endl;
            cout << endl;
            cout << "Cliente encontrado com sucesso!" << endl;
            localizaCliente(i);
            encontrou = true;
            break;
        }
    }

    if (encontrou == false) {
        cout << "Cliente não encontrado!" << endl;
    }
}

void localizaCliente(int i) {
    cout << endl;
    cout << endl;
    cout << "ID:" << clientes[i].id << endl;
    cout << "NOME: " << clientes[i].nome << endl;
    cout << "DATA DE NASCIMENTO: "
         << clientes[i].dataDeNascimento.dia
         << "/" << clientes[i].dataDeNascimento.mes
         << "/" << clientes[i].dataDeNascimento.ano
         << endl;
    cout << "CPF: " << clientes[i].cpf<< endl;

    cout << endl;
    cout << "---" << endl;
    cout << endl;

    __fpurge(stdin);
    cout << "Consulta verificada. Pressione qualquer para continuar...";
    getchar();

}

void cadastrarCliente() {

    Cliente cliente;

    __fpurge(stdin);
    cout << "NOME: ";
    getline(cin, cliente.nome);

    __fpurge(stdin);
    cout << "Data de Nascimento" << endl;

    cout << "DIA: ";
    cin >> cliente.dataDeNascimento.dia;

    __fpurge(stdin);
    cout << "MÊS: ";
    cin >> cliente.dataDeNascimento.mes;

    __fpurge(stdin);
    cout << "ANO: ";
    cin >> cliente.dataDeNascimento.ano;

    __fpurge(stdin);
    cout << "CPF: ";
    getline(cin, cliente.cpf);

    cliente.id = qtd_id_cliente;
    contaIdCliente();

    clientes[qtd_clientes] = cliente;
    contaQtdDeClientes();

    __fpurge(stdin);
    cout << "Cliente cadastrado com sucesso!" << endl;
    cout << "Deseja cadastrar mais um cliente? [1] SIM | [0] NÃO - _ ";

    bool escolha;
    cin >> escolha;

    if (escolha == true) cadastrarCliente();
    else menuCliente();

    cout << "Pressione qualquer tecla para voltar ao menu de cliente.";
    getchar();
}

void contaQtdDeClientes() {
    qtd_clientes++;
}

void contaIdCliente() {
    qtd_id_cliente++;
}

void menuCarro() {

    char escolha = ' ';

    cout << "-------------------------------" << endl;
    cout << "---------MENU DE CARRO---------" << endl;
    cout << "-------------------------------" << endl;

    cout << "1. Cadastrar carro" << endl;
    cout << "2. Buscar carro" << endl;
    cout << "3. Listar carros" << endl;
    cout << "0. Voltar" << endl;
    cout << "Digite uma opção: ";
    cin >> escolha;

    switch (escolha) {
        case '0':
            menu();
            break;
        case '1':
            cadastrarCarro();
            break;
        case '2':
            buscarCarro();
            break;
        case '3':
            listaCarros();
            break;
    }

}

void buscarCarro() {
    bool encontrou = false;
    int id_carro = 0;

    cout << "ID do carro: ";
    cin >> id_carro;

    for (int i = 0; i < qtd_carros; ++i) {
        if(id_carro == carros[i].id) {
            cout << endl;
            cout << endl;
            cout << "Carro encontrado com sucesso!" << endl;
            localizaCarro(i);
            encontrou = true;
            break;
        }
    }

    if (encontrou == false) {

        cout << "Carro não encontrado! Acho que você deve ter errado alguma coisa. Tente novamente ..." << endl;
        cout << "Deseja buscar novamente? [1] SIM | [2] NÃO - _ " << endl;

        char escolha = ' ';
        __fpurge(stdin);
        cout << "Digite uma opção: ";
        cin >> escolha;

        if(escolha == '1') {
            buscarCarro();
        } else {
            menuCarro();
        }
    }
}

void localizaCarro(int i) {
    cout << "ID:" << carros[i].id << endl;
    cout << "NOME: " << carros[i].nome << endl;
    cout << "ANO: " << carros[i].ano.ano << endl;
    cout << "VALOR: R$ " << carros[i].valor << endl;
    cout << endl;
    cout << "---" << endl;
    cout << endl;
}

void listaCarros() {
    cout << "----------------------------------" << endl;
    cout << "----------LISTA DE CARROS---------" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < qtd_carros; i++) {
        cout << "ID:" << carros[i].id << endl;
        cout << "NOME: " << carros[i].nome << endl;
        cout << "ANO: " << carros[i].ano.ano << endl;
        cout << "VALOR: R$ " << carros[i].valor << endl;
        cout << endl;
        cout << "---" << endl;
        cout << endl;
    }

    cout << "Carros listados com sucesso!" << endl;
    cout << "Pressione qualquer tecla para continuar...";
    __fpurge(stdin);
    getchar();
    menuCarro();

}

void cadastrarCarro() {


    Carro carro;

    __fpurge(stdin);
    cout << "NOME: ";
    getline(cin, carro.nome);

    __fpurge(stdin);
    cout << "MARCA: ";
    getline(cin, carro.modelo);

    cout << "ANO: ";
    cin >> carro.ano.ano;

    cout << "VALOR: ";
    cin >> carro.valor;

    carro.id = qtd_id_carro;
    contaIdDosCarros();

    carros[qtd_carros] = carro;
    contaQtdDosCarros();

    __fpurge(stdin);
    cout << "Carro cadastrado com sucesso!" << endl;
    cout << "Deseja cadastrar mais um Carro? [1] SIM | [0] NÃO - ";

    int escolha;
    cin >> escolha;

    if (escolha == 1) {
        cadastrarCarro();
    } else {
        __fpurge(stdin);
        cout << "Pressione qualquer tecla para voltar ao menu de carro.";
        getchar();
        menuCarro();
    }

}

void contaQtdDosCarros() {
    qtd_carros++;
}

void contaIdDosCarros() {
    qtd_id_carro++;
}

void menuAluguel() {

}