#include <iostream>
#include <string>
#include <vector>

// Struktur data untuk pesanan biji kopi
struct Order {
    std::string coffeeType;
    int quantity;
};

// Kelas untuk mengelola pesanan
class OrderManager {
private:
    std::vector<Order> orders;

public:
    void addOrder(const Order& newOrder) {
        orders.push_back(newOrder);
        std::cout << "Pesanan ditambahkan: " << newOrder.coffeeType << " (" << newOrder.quantity << ")\n";
    }

    void removeOrder(const Order& orderToRemove) {
        for (auto it = orders.begin(); it != orders.end(); ++it) {
            if (it->coffeeType == orderToRemove.coffeeType && it->quantity == orderToRemove.quantity) {
                orders.erase(it);
                std::cout << "Pesanan dihapus: " << orderToRemove.coffeeType << " (" << orderToRemove.quantity << ")\n";
                return;
            }
        }
        std::cout << "Pesanan tidak ditemukan.\n";
    }

    void displayOrders() {
        if (orders.empty()) {
            std::cout << "Tidak ada pesanan.\n";
        } else {
            std::cout << "Daftar Pesanan:\n";
            for (const auto& order : orders) {
                std::cout << "Jenis kopi: " << order.coffeeType << ", Jumlah: " << order.quantity << std::endl;
            }
        }
    }
};

// Kelas untuk menampilkan menu utama
class Menu {
private:
    OrderManager orderManager;

public:
    void displayMainMenu() {
        int choice;
        do {
            std::cout << "SELAMAT DATANG DI KOPI.IN ADA YANG BISA SAYA BANTU? :)\n";
            std::cout << "1. Tambah Pesanan\n";
            std::cout << "2. Hapus Pesanan\n";
            std::cout << "3. Tampilkan Pesanan\n";
            std::cout << "0. Keluar\n";
            std::cout << "Pilihan Anda: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addOrder();
                    break;
                case 2:
                    removeOrder();
                    break;
                case 3:
                    displayOrders();
                    break;
                case 0:
                    std::cout << "Terima kasih!\n";
                    break;
                default:
                    std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                    break;
            }
            std::cout << std::endl;
        } while (choice != 0);
    }

    void addOrder() {
        std::string coffeeType;
        int quantity;

        std::cout << "Jenis kopi: ";
        std::cin >> coffeeType;
        std::cout << "Jumlah: ";
        std::cin >> quantity;

        Order newOrder = { coffeeType, quantity };
        orderManager.addOrder(newOrder);
    }

    void removeOrder() {
        std::string coffeeType;
        int quantity;

        std::cout << "Jenis kopi: ";
        std::cin >> coffeeType;
        std::cout << "Jumlah: ";
        std::cin >> quantity;

        Order orderToRemove = { coffeeType, quantity };
        orderManager.removeOrder(orderToRemove);
    }

    void displayOrders() {
        orderManager.displayOrders();
    }
};

int main() {
    Menu menu;
    menu.displayMainMenu();

    return 0;
}
