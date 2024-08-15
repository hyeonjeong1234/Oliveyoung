// Store.cpp
#include "Store.h"
#include <iostream>

Store::Store(ClientManager& cm, ProductManager& pm, CategoryManager& cmg)
    : clientManager(cm), productManager(pm), categoryManager(cmg) {}

Store::~Store() {}

void Store::sellProduct(int clientId, int productId) {
    // Get client and product information
    Client* client = clientManager.searchClient(clientId);
    Product* product = productManager.searchProduct(productId);

    if (client && product && product->getQuantity() > 0) {
        // Record the purchase
        PurchaseRecord record;
        record.clientId = clientId;
        record.clientName = client->getName();
        record.productId = productId;
        record.productName = product->getName();
        purchaseHistory.push_back(record);

        // Update product stock
        product->setQuantity(product->getQuantity() - 1);
        std::cout << "���� �Ϸ�: " << client->getName() << "���� " << product->getName() << "��(��) �����ϼ̽��ϴ�." << std::endl;
    }
    else {
        std::cerr << "������ �� �����ϴ�. �� �Ǵ� ��ǰ�� ��ȿ���� �ʰų� ��� �����մϴ�." << std::endl;
    }
}

void Store::updateStock(int productId, int newStock) {
    Product* product = productManager.searchProduct(productId);
    if (product) {
        product->setQuantity(newStock);
        std::cout << "��ǰ ID " << productId << "�� ��� " << newStock << "�� ������Ʈ�Ǿ����ϴ�." << std::endl;
    }
    else {
        std::cerr << "��ȿ���� ���� ��ǰ ID�Դϴ�." << std::endl;
    }
}

void Store::displayPurchaseHistory() const {
    if (purchaseHistory.empty()) {
        std::cout << "���� ������ �����ϴ�." << std::endl;
        return;
    }

    std::cout << "���� ����:" << std::endl;
    for (const auto& record : purchaseHistory) {
        std::cout << "�� ID: " << record.clientId
            << ", �� �̸�: " << record.clientName
            << ", ��ǰ ID: " << record.productId
            << ", ��ǰ �̸�: " << record.productName << std::endl;
    }
}
