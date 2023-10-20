#include <iostream>
#include <string>

#include "item.h"
#include "list"
using namespace std;
void menu() {
  cout << "1.Cadastrar produto \n";
  cout << "2. Buscar produto\n";
  cout << "3. Buscar por nome do clinete \n";
  cout << "4. Buscar por CPF \n";
  cout << "5. Alterar informacoes\n";
  cout << "6. Listar produtos\n";
  cout << "S. Exit\n";
}

void listarProdutos(Item* item) {
  cout << "Produto encontrado!\n";
  cout << "____________________\n";
  cout << "Produto: " << item->produtoNome << endl;
  cout << "Cliente: " << item->clienteNome << endl;
  cout << "CPF: " << item->clienteCPF << endl;
  cout << "quantidade: " << item->quantidade << endl;
}

void alterarProduto(Item* item) {
  cout << "Produto encontrado!\n";
  cout << "novo cliente: ";
  cin >> item->clienteNome;
  cout << "novo CPF: ";
  cin >> item->clienteCPF;
  cout << "quantidade: ";
  cin >> item->quantidade;
}

int main() {
  list<Item> itemList;  // create a list to store items

  char opcao;
  do {
    menu();
    cin >> opcao;

    Item newItem;  // declare the variable outside of the if block

    if (opcao == '1') {
      cout << "item: ";
      cin >> newItem.produtoNome;
      cout << "Cliente: ";
      cin >> newItem.clienteNome;
      cout << "CPF: ";
      cin >> newItem.clienteCPF;
      cout << "quantidade: ";
      cin >> newItem.quantidade;

      itemList.push_back(newItem);  // add new item to the end of the list

    } else if (opcao == '2') {
      string nomeProduto;
      cout << "Produto: ";
      cin >> nomeProduto;

      bool encontrado = false;
      for (auto item = itemList.begin(); item != itemList.end(); item++) {
        if (item->produtoNome == nomeProduto) {
          listarProdutos(&(*item));
          encontrado = true;
          break;
        }
      }

      if (!encontrado) {
        cout << "Produto nao encontrado.\n";
      }
    } else if (opcao == '3') {
      string clienteNome;
      cout << "Cliente: ";
      cin >> clienteNome;

      bool encontrado = false;
      for (auto it = itemList.begin(); it != itemList.end(); it++) {
        if (it->clienteNome == clienteNome) {
          listarProdutos(&(*it));
          encontrado = true;
          break;
        }
      }

      if (!encontrado) {
        cout << "Produto nao encontrado.\n";
      }
    } else if (opcao == '4') {
      string clienteCPF;
      cout << "CPF: ";
      cin >> clienteCPF;

      bool encontrado = false;
      for (auto it = itemList.begin(); it != itemList.end(); it++) {
        if (it->clienteCPF == clienteCPF) {
          listarProdutos(&(*it));
          encontrado = true;
          break;
        }
      }

      if (!encontrado) {
        cout << "Produto nao encontrado.\n";
      }
    } else if (opcao == '5') {
      char subopcao;
      cout << "1. Produto\n";
      cout << "2.cliente\n";
      cin >> subopcao;

      if (subopcao == '1') {
        string nomeProduto;
        cout << "Produto: ";
        cin >> nomeProduto;

        bool encontrado = false;
        for (auto item = itemList.begin(); item != itemList.end(); item++) {
          if (item->produtoNome == nomeProduto) {
            alterarProduto(&(*item));
            encontrado = true;
            break;
          }
        }

        if (!encontrado) {
          cout << "Produto nao encontrado.\n";
        }
      } else if (subopcao == '2') {
        string clienteNome;
        cout << "Cliente: ";
        cin >> clienteNome;

        bool encontrado = false;
        for (auto it = itemList.begin(); it != itemList.end(); it++) {
          if (it->clienteNome == clienteNome) {
            cout << "Produto encontrado!\n";
            cout << " novo cliente: ";
            cin >> it->clienteNome;
            encontrado = true;
            break;
          }
        }

        if (!encontrado) {
          cout << "Produto nao encontrado.\n";
        }
      }
    } else if (opcao == '6') {
      for (auto item = itemList.begin(); item != itemList.end(); item++) {
        listarProdutos(&(*item));
      }
    }
  } while (opcao != 'S' && opcao != 's');

  return 0;
}
