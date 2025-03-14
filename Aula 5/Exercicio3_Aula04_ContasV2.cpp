#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int max_contas = 10;
    int numContas = 0;
    int opcao;
    double saldos[max_contas];

    while(true)
    {
        cout << "\n#### Menu Bancário ####\n";
        cout << "\n1. Cadastrar Conta\n";
        cout << "2. Depositar\n";
        cout << "3. Sacar\n";
        cout << "4. Consultar Saldos\n";
        cout << "5. Remover Conta\n"; // Adicionado opção para remover conta
        cout << "6. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        if (opcao==6) // Sair
        {
            break;
        }
        switch (opcao)
        {
            case 1: // Cadastrar Conta
            {
                if (numContas < max_contas) {
                    saldos[numContas] = 0.0;
                    numContas++;
                    cout << "\nConta Nro: " << numContas << " cadastrada com sucesso.\n";
                } else {
                    cout << "\nLimite de " << max_contas << " contas atingido.\n";
                }
                break;
            }
            case 2: // Depositar
            {
                int numeroConta;
                double valor;
                cout << "\nDigite o número da conta: ";
                cin >> numeroConta;
                if (numeroConta >= 1 && numeroConta <= numContas) {
                    cout << "Digite o valor a depositar: ";
                    cin >> valor;
                    saldos[numeroConta - 1] += valor;
                    cout << "\nDepósito realizado com sucesso.\n";
                } else {
                    cout << "\nConta não encontrada.\n";
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                break;
            }
            case 3: // Sacar
            {
                int numeroConta;
                double valor;
                cout << "\nDigite o número da conta: ";
                cin >> numeroConta;
                if (numeroConta >= 1 && numeroConta <= numContas) {
                    cout << "Digite o valor a sacar: ";
                    cin >> valor;
                    if (saldos[numeroConta - 1] >= valor) {
                        saldos[numeroConta - 1] -= valor;
                        cout << "Saque realizado com sucesso.\n";
                    } else {
                        cout << "Saldo insuficiente.\n";
                    }
                } else {
                    cout << "Conta não encontrada.\n";
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                break;
            }
            case 4: // Consultar Saldos
            {
                int numeroConta;
                cout << "\nDigite o número da conta (ou -1 para todos): ";
                cin >> numeroConta;
                if (numeroConta == -1) {
                    cout << "Saldos de todas as contas:\n";
                    for (int i = 0; i < numContas; i++) {
                        cout << "Conta " << i + 1 << ": R$ " << saldos[i] << "\n";
                    }
                } else if (numeroConta >= 1 && numeroConta <= numContas) {
                    cout << "Saldo da conta " << numeroConta << ": R$ " << saldos[numeroConta - 1] << "\n";
                } else {
                    cout << "Conta não encontrada.\n";
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                break;
            }
            case 5: // Remover Conta
            {
                int numeroConta;
                cout << "\nDigite o número da conta a remover: ";
                cin >> numeroConta;
                if (numeroConta >= 1 && numeroConta <= numContas) {
                    // Desloca as contas subsequentes uma posição para trás
                    for (int i = numeroConta - 1; i < numContas - 1; i++) {
                        saldos[i] = saldos[i + 1];
                    }
                    numContas--;
                    cout << "Conta removida com sucesso.\n";
                } else {
                    cout << "Conta não encontrada.\n";
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                break;
            }
            default:
            {
                cout << "Opção inválida.\n";
                cin.clear();
                cin.ignore(100,'\n');
                break;
            }
        }
        system("pause");
        system("cls");
    }
    system("cls");
    return 0;
}