#include "../include/Inventory.hpp"

Product *Inventory::searchByID(int id)
{
    auto it = map_inventory.find(id);
    if (it != map_inventory.end()) {
        return it->second;
    }
    return nullptr;
}
std::vector<Product*> Inventory::searchByName(const std::string& name)
{
    //// ---------- are the products unique?
    // for (Product& prod : inventory) {
    //     if (prod.name.find(name) != std::string::npos) {
    //         return &prod;
    //     }
    // }

    std::vector<Product*> res;
    for (Product& prod : inventory) {
        if (prod.name.find(name) != std::string::npos) {
            res.push_back(&prod);
        }
    }
    return res;
}

void Inventory::addProduct(const Product &prod)
{
    inventory.push_back(prod);
    map_inventory[prod.id] = &inventory.back();
}

bool Inventory::editProduct(int id, int quantity, double price)
{
    Product *prod = searchByID(id);
    if (prod)
    {
        prod->quantity = quantity;
        prod->price = price;
    }
}

bool Inventory::deleteProduct(int id)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if (it->id == id)
        {
            map_inventory.erase(id);
            inventory.erase(it);
            return true;
        }
    }
    return false;
}
