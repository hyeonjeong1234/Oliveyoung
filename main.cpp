#include "ClientManager.h"
#include "ProductManager.h"
#include "CategoryManager.h"
#include "Store.h"
#include <iostream>
#include <limits> 

using namespace std;

void displayRoleMenu();
void handleClientActions(ClientManager& clientManager, ProductManager& productManager, CategoryManager& categoryManager, Store& store);
void handleManagerActions(ClientManager& clientManager, ProductManager& productManager, CategoryManager& categoryManager, Store& store);
int getValidatedInput();

int main() {
    ClientManager clientManager;
    CategoryManager categoryManager;
    ProductManager productManager(categoryManager);
    Store store(clientManager, productManager, categoryManager);

    bool running = true;

    while (running) {
        displayRoleMenu();
        int roleChoice = getValidatedInput();

        switch (roleChoice) {
        case 1: // Customer
            handleClientActions(clientManager, productManager, categoryManager, store);
            break;
        case 2: // Manager
            handleManagerActions(clientManager, productManager, categoryManager, store);
            break;
        case 3: // Exit
            running = false;
            break;
        default:
            cerr << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << endl;
            break;
        }
    }

    return 0;
}

void displayRoleMenu() {
    cout << "\nMenu:\n";
    cout << "1. ��\n";
    cout << "2. ������\n";
    cout << "3. ����\n";
    cout << "�������ּ���: ";
}

int getValidatedInput() {
    int input;
    while (!(cin >> input)) {
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cerr << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any remaining input
    return input;
}

void handleClientActions(ClientManager& clientManager, ProductManager& productManager, CategoryManager& categoryManager, Store& store) {
    int choice;
    cout << "\n�� �޴�:\n";
    cout << "1. ī�װ��� ��ǰ ����\n";
    cout << "2. ��� ��ǰ ����\n";
    cout << "3. ī�װ� ����\n";
    cout << "4. ��ǰ ����\n";
    cout << "5. ���� �޴��� ���ư���\n";
    cout << "�������ּ���: ";
    choice = getValidatedInput();

    cin.ignore();

    switch (choice) {
    case 1: {
        string categoryName;
        cout << "ī�װ� �̸��� �Է����ּ���: ";
        getline(cin, categoryName);
        Category* category = categoryManager.getCategory(categoryName);
        if (category) {
            category->displayProducts();
        }
        else {
            cerr << "ī�װ��� ã�� �� �����ϴ�." << endl;
        }
        break;
    }
    case 2:
        productManager.displayProducts();
        break;
    case 3:
        categoryManager.displayCategories();
        break;
    case 4: {
        int clientId, productId;
        cout << "�� ID�� �Է����ּ���: ";
        clientId = getValidatedInput();
        cout << "������ ��ǰ ID�� �Է����ּ���: ";
        productId = getValidatedInput();
        store.sellProduct(clientId, productId);
        break;
    }
    case 5:
        break;
    default:
        cerr << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << endl;
        break;
    }
}

void handleManagerActions(ClientManager& clientManager, ProductManager& productManager, CategoryManager& categoryManager, Store& store) {
    int choice;
    cout << "\n������ �޴�:\n";
    cout << "1. �� ����\n";
    cout << "2. ��ǰ ����\n";
    cout << "3. ī�װ� ����\n";
    cout << "4. ��� ����\n";
    cout << "5. �Ǹ� ���� ����\n";
    cout << "6. ���� �޴��� ���ư���\n";
    cout << "�������ּ���: ";
    choice = getValidatedInput();

    cin.ignore();

    switch (choice) {
    case 1:
        // �� ����
        int clientChoice;
        cout << "\n�� ���� �޴�:\n";
        cout << "1. �� �߰�\n";
        cout << "2. �� ����\n";
        cout << "3. �� ��� ����\n";
        cout << "4. ������ �޴��� ���ư���\n";
        cout << "�������ּ���: ";
        clientChoice = getValidatedInput();

        switch (clientChoice) {
        case 1: {
            string name, phone;
            cout << "�� �̸��� �Է����ּ���: ";
            getline(cin, name);
            cout << "�� ��ȭ��ȣ�� �Է����ּ���: ";
            getline(cin, phone);
            clientManager.addClient(name, phone);
            break;
        }
        case 2: {
            int id;
            cout << "������ �� ID�� �Է����ּ���: ";
            id = getValidatedInput();
            clientManager.deleteClient(id);
            break;
        }
        case 3:
            clientManager.displayClient();
            break;
        case 4:
            break;
        default:
            cerr << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << endl;
            break;
        }
        break;

    case 2:
        // ��ǰ ����
        int productChoice;
        cout << "\n��ǰ ���� �޴�:\n";
        cout << "1. ��ǰ �߰�\n";
        cout << "2. ��ǰ ����\n";
        cout << "3. ��ǰ ��� ����\n";
        cout << "4. ������ �޴��� ���ư���\n";
        cout << "�������ּ���: ";
        productChoice = getValidatedInput();

        cin.ignore();

        switch (productChoice) {
        case 1: {
            string categoryName, name;
            int price, quantity;
            cout << "��ǰ �̸��� �Է����ּ���: ";
            getline(cin, name);
            cout << "��ǰ ������ �Է����ּ���: ";
            price = getValidatedInput();
            cout << "��ǰ ������ �Է����ּ���: ";
            quantity = getValidatedInput();
            cin.ignore();
            cout << "ī�װ� �̸��� �Է����ּ���: ";
            getline(cin, categoryName);
            productManager.addProduct(categoryName, name, price, quantity);
            break;
        }
        case 2: {
            int id;
            cout << "������ ��ǰ ID�� �Է����ּ���: ";
            id = getValidatedInput();
            productManager.deleteProduct(id);
            break;
        }
        case 3:
            productManager.displayProducts();
            break;
        case 4:
            break;
        default:
            cerr << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << endl;
            break;
        }
        break;

    case 3:
        // ī�װ� ����
        int categoryChoice;
        cout << "\nī�װ� ���� �޴�:\n";
        cout << "1. ī�װ� �߰�\n";
        cout << "2. ī�װ� ����\n";
        cout << "3. ī�װ� ��� ����\n";
        cout << "4. ������ �޴��� ���ư���\n";
        cout << "�������ּ���: ";
        categoryChoice = getValidatedInput();

        cin.ignore();

        switch (categoryChoice) {
        case 1: {
            string name;
            cout << "ī�װ� �̸��� �Է����ּ���: ";
            getline(cin, name);
            categoryManager.addCategory(name);
            break;
        }
        case 2: {
            string name;
            cout << "������ ī�װ� �̸��� �Է����ּ���: ";
            getline(cin, name);
            categoryManager.deleteCategory(name);
            break;
        }
        case 3:
            categoryManager.displayCategories();
            break;
        case 4:
            break;
        default:
            cerr << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << endl;
            break;
        }
        break;

    case 4: {
        // ��� ����
        int productId, stock;
        cout << "��� ������ ��ǰ ID�� �Է����ּ���: ";
        productId = getValidatedInput();
        cout << "���ο� ��� ������ �Է����ּ���: ";
        stock = getValidatedInput();
        store.updateStock(productId, stock);
        break;
    }

    case 5:
        // �Ǹ� ���� ����
        store.displayPurchaseHistory();
        break;

    case 6:
        break;

    default:
        cerr << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << endl;
        break;
    }
}
