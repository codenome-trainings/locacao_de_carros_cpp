#include <iostream>
#include <stdio_ext.h>

using namespace std;

#define MAX_CLIENTES 100
#define MAX_CARROS 100
#define MAX_ALUGUEL 100


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

typedef struct Aluguel {
    int id;
    Cliente cliente;
    Carro carro;
} Aluguel;
int qtd_id_aluguel = 20151528;


Cliente clientes[MAX_CLIENTES];
int qtd_clientes = 0;

Carro carros[MAX_CARROS];
int qtd_carros = 0;

Aluguel alugueis[MAX_ALUGUEL];
int qtd_alugueis = 0;

Cliente *ponteiro_cliente;
Carro *ponteiro_carro;


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
void alugaCarro();
void armazenaClienteNoPonteiro(int i);
void buscaClienteParaLocarUmCarro();
void buscaCarroParaSerAlugado();
void armazenaPonteiroDoCarro(int i);

void contaIdAluguel();

void contaQtdDeAlgueis();

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
        default:
            cout << "Opção inválida! Tente novamente ..." << endl;
    }
    menuCliente();
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

    armazenaClienteNoPonteiro(i);

}

void armazenaClienteNoPonteiro(int i) {
    ponteiro_cliente = &clientes[i];
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

    __fpurge(stdin);
    cout << "Pressione qualquer tecla para voltar ao menu de cliente.";
    getchar();
    menuCliente();
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
        default:
            cout << "Opção inválida! Tente novamente..." << endl;
    }
    menuCarro();
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
    if(carros[i].status == true) {
        cout << "STATUS: Alugado" << endl;
    } else {
        cout << "STATUS: Livre para locação" << endl;
    }
    cout << endl;
    cout << "---" << endl;
    cout << endl;

    __fpurge(stdin);
    cout << "Consulta verificada. Pressione qualquer para continuar...";
    getchar();

    armazenaPonteiroDoCarro(i);
}

void armazenaPonteiroDoCarro(int i) {
    ponteiro_carro = &carros[i];
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
        if(carros[i].status == true) {
            cout << "STATUS: Alugado" << endl;
        } else {
            cout << "STATUS: Livre para locação" << endl;
        }
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

    if (escolha == 1) cadastrarCarro();

    __fpurge(stdin);
    cout << "Pressione qualquer tecla para voltar ao menu de carro.";
    getchar();
    menuCarro();

}

void contaQtdDosCarros() {
    qtd_carros++;
}

void contaIdDosCarros() {
    qtd_id_carro++;
}

void menuAluguel() {

    char escolha = ' ';

    cout << "--------------------------------" << endl;
    cout << "---------MENU DE ALUGUEL--------" << endl;
    cout << "--------------------------------" << endl;

    cout << "1. Alugar um carro" << endl;
    cout << "2. Dar baixa em um carro" << endl;
    cout << "3. Ver todos os clientes com carros alugados" << endl;
    cout << "0. Voltar" << endl;
    cout << "Digite uma opção: ";
    __fpurge(stdin);
    cin >> escolha;

    switch (escolha) {
        case '0':
            menu();
            break;
        case '1':
            alugaCarro();
            break;
        case '2':
//            baixaEmCarro();
            break;
        case '3':
            relatorioDeClientesComCarrosAlugados();
            break;
        case '4':
            listarCarrosAlugados();
            break;
        default:
            cout << "Opção inválida! Tente novamente ..." << endl;
    }
    menuAluguel();
}

void alugaCarro() {

    Aluguel aluguel;

    /*
     * Função que busca cliente e carro para serem armazenadas em um ponteiro que
     * armazena temporariamente os valores de carro e cliente.
     */
    buscaClienteParaLocarUmCarro();
    buscaCarroParaSerAlugado();

    aluguel.id = qtd_id_aluguel;
    contaIdAluguel();

    //Trata Cliente
    aluguel.cliente.id = ponteiro_cliente->id;
    aluguel.cliente.nome = ponteiro_cliente->nome;
    aluguel.cliente.cpf = ponteiro_cliente->cpf;
    aluguel.cliente.dataDeNascimento.dia = ponteiro_cliente->dataDeNascimento.dia;
    aluguel.cliente.dataDeNascimento.mes = ponteiro_cliente->dataDeNascimento.mes;
    aluguel.cliente.dataDeNascimento.ano = ponteiro_cliente->dataDeNascimento.ano;

    //Trata Alguel
    aluguel.carro.id = ponteiro_carro->id;
    aluguel.carro.nome = ponteiro_carro->nome;
    aluguel.carro.ano = ponteiro_carro->ano;
    aluguel.carro.modelo = ponteiro_carro->modelo;
    aluguel.carro.valor = ponteiro_carro->valor;

    ponteiro_carro->status = true;

    alugueis[qtd_alugueis] = aluguel;
    contaQtdDeAlgueis();

    __fpurge(stdin);
    cout << "Aluguel cadastrado com sucesso!" << endl;
    cout << "Deseja cadastrar mais um Alguel? [1] SIM | [0] NÃO - _ ";

    bool escolha;
    cin >> escolha;

    if (escolha == true) alugaCarro();

    __fpurge(stdin);
    cout << "Pressione qualquer tecla para voltar ao menu de aluguel.";
    getchar();
    menuAluguel();
}

void contaQtdDeAlgueis() {
    qtd_alugueis++;
}

void contaIdAluguel() {
    qtd_id_aluguel++;
}

void buscaCarroParaSerAlugado() {
    char done = ' ';

    do {

        bool escolha = true;

        buscarCarro();
        __fpurge(stdin);
        cout << "Deseja usar este carro para ser alugado? [1] SIM | [0] NÃO (Buscar outro cliente): ";
        cin >> escolha;

        if (escolha == true) {
            done = 'a';
        } else {
            alugaCarro();
        }

    } while (done == ' ');
}

void buscaClienteParaLocarUmCarro() {

    char done = ' ';

    do {

        bool escolha = true;

        buscarCliente();
        __fpurge(stdin);
        cout << "Deseja usar este cliente para locar um carro? [1] SIM | [0] NÃO (Buscar outro cliente): ";
        cin >> escolha;

        if (escolha == true) {
            done = 'a';
        } else {
            alugaCarro();
        }

    } while (done == ' ');

}

