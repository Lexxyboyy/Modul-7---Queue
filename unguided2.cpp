#include <iostream>
using namespace std;


//Aryo Tegar Sukarno
//2311102018
//IF-11-A


struct Student {
    string nama;
    string NIM;
    Student* next;
};

class Queue {
private:
    Student* front;
    Student* back;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(string nama, string NIM) {
        Student* temp = new Student();
        temp->nama = nama;
        temp->NIM = NIM;
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
            Student* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                back = nullptr;
            }
        }
    }

    int countQueue() {
        int count = 0;
        Student* current = front;
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
        cout << "Data antrian mahasiswa:" << endl;
        Student* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Nama: " << current->nama << ", NIM: " << current->NIM << endl;
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
    q.enqueue("Aryo", "2311102018");
    q.enqueue("Lexxy", "2311107271");
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