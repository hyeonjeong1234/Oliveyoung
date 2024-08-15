#ifndef STORE_H
#define STORE_H
#include "ProductManager.h"
#include "ClientManager.h"
#include "CategoryManager.h"
#include <unordered_map>
#include <vector>
#include <string>

struct PurchaseRecord {
    int clientId;
    std::string clientName;
    int productId;
    std::string productName;
};
class Store
{
public:
    Store(ClientManager& cm, ProductManager& pm, CategoryManager& catm);
    
    //void addProduct(int productId, int stock);
    void updateStock(int productId, int newStock);
    //void setProductAvailability(int productId, bool available);
    void sellProduct(int clientId, int productId);
    void displayPurchaseHistory() const;
    ~Store();

private:

    ClientManager& clientManager;
    ProductManager& productManager;
    CategoryManager& categoryManager;
    //unordered_map<int, int> mStockMap; // ��ǰ id -> ���
    //unordered_map<int, bool> mAvailabilityMap; // ��ǰ id -> �Ǹſ���
    vector< PurchaseRecord> purchaseHistory; // ���ų���
};


#endif // STORE_H
