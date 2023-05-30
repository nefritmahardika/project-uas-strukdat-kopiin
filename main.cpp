#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk pesanan biji kopi
struct Order {
    string coffeeType;
    int quantity;
};

// Node untuk linked list
struct Node {
    Order order;
    Node* next;
};

// Linked list untuk menyimpan daftar pesanan
class OrderList {
private:
    Node* head;
public:
    OrderList() : head(nullptr) {}

    void addOrder(Order newOrder) {
        Node* newNode = new Node;
        newNode->order = newOrder;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Pesanan ditambahkan: " << newOrder.coffeeType << " (" << newOrder.quantity << ")\n";
    }

    void displayOrders() {
        if (head == nullptr) {
            cout << "Tidak ada pesanan.\n";
        } else {
            Node* temp = head;
            cout << "Daftar Pesanan:\n";
            while (temp != nullptr) {
                cout << "Jenis kopi: " << temp->order.coffeeType << ", Jumlah: " << temp->order.quantity << endl;
                temp = temp->next;
            }
        }
    }
};

// Queue untuk antrian pesanan
class OrderQueue {
private:
    Node* front;
    Node* rear;
public:
    OrderQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(Order newOrder) {
        Node* newNode = new Node;
        newNode->order = newOrder;
        newNode->next = nullptr;

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Pesanan ditambahkan ke antrian: " << newOrder.coffeeType << " (" << newOrder.quantity << ")\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Antrian pesanan kosong.\n";
        } else {
            Node* temp = front;
            front = front->next;
            cout << "Pesanan diambil dari antrian: " << temp->order.coffeeType << " (" << temp->order.quantity << ")\n";
            delete temp;
        }
    }
};

// Stack untuk tumpukan pesanan
class OrderStack {
private:
    Node* top;
public:
    OrderStack() : top(nullptr) {}

    void push(Order newOrder) {
        Node* newNode = new Node;
        newNode->order = newOrder;
        newNode->next = top;
        top = newNode;

        cout << "Pesanan ditambahkan ke tumpukan: " << newOrder.coffeeType << " (" << newOrder.quantity << ")\n";
    }

    void pop() {
        if (top == nullptr) {
            cout << "Tumpukan pesanan kosong.\n";
        } else {
            Node* temp = top;
            top = top->next;
            cout << "Pesanan diambil dari tumpukan: " << temp->order.coffeeType << " (" << temp->order.quantity << ")\n";
            delete temp;
        }
    }
};

int main() {
    OrderList orderList;
    OrderQueue orderQueue;
    OrderStack orderStack;

    // Menambahkan pesanan
    Order order1 = { "Arabica", 2 };
    orderList.addOrder(order1);
    orderQueue.enqueue(order1);
    orderStack.push(order1);

    Order order2 = { "Robusta", 3 };
    orderList.addOrder(order2);
    orderQueue.enqueue(order2);
    orderStack.push(order2);

    // Menampilkan pesanan
    orderList.displayOrders();

    // Mengambil pesanan dari antrian
    orderQueue.dequeue();

    // Mengambil pesanan dari tumpukan
