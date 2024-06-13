#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Product.hpp"
#include <vector>
#include <unordered_map>

class Inventory
{
    private:
        std::vector<Product> inventory;
        std::unordered_map<int, Product*> map_inventory;

    public:
        Inventory();
        ~Inventory();

        void    addProduct(const Product &prod);
        bool    editProduct(int id, int quantity, double price);
        bool    deleteProduct(int id);

        Product                 *searchByID(int id);
        std::vector<Product*>   searchByName(const std::string& name);

};

#endif