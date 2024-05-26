#include <iostream>
using namespace std;


//Aryo Tegar Sukarno
//2311102018
//IF-11-A


struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* back;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(string data) {
        Node* temp = new Node();
        temp->data = data;
        temp->next = nullptr;

        if (isEmpty()) {
            front = temp;
            back = temp;
        } else {
            back->next = temp;
            back = temp;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                back = nullptr;
            }
        }
    }

    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void viewQueue() {
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". " << current->data << endl;
            current = current->next;
            index++;
        }
        if (isEmpty()) {
            cout << "(kosong)" << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue("Aryo");
    q.enqueue("Lexxy");
    q.viewQueue();
    cout << "Jumlah antrian = " << q.countQueue() << endl;

    q.dequeue();
    q.viewQueue();
    cout << "Jumlah antrian = " << q.countQueue() << endl;

    q.clearQueue();
    q.viewQueue();
    cout << "Jumlah antrian = " << q.countQueue() << endl;

    return 0;
}