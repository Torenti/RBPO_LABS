#include <iostream>
#include <initializer_list>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template<class T>
class QueueBasedOnUnidirectionalLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    unsigned size;

public:
    QueueBasedOnUnidirectionalLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Конструктор копирования
    QueueBasedOnUnidirectionalLinkedList(const QueueBasedOnUnidirectionalLinkedList<T>& other) {
        head = nullptr;
        tail = nullptr;
        size = 0;

        Node<T>* curr = other.head;
        while (curr != nullptr) {
            Push(curr->data);
            curr = curr->next;
        }
    }

    // Конструктор перемещения
    QueueBasedOnUnidirectionalLinkedList(QueueBasedOnUnidirectionalLinkedList<T>&& other) noexcept {
        head = other.head;
        tail = other.tail;
        size = other.size;

        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    // Конструктор, принимающий на вход initializer_list
    QueueBasedOnUnidirectionalLinkedList(initializer_list<T> ilist) : head(nullptr), tail(nullptr), size(0) {
        for (const T& value : ilist) {
            Push(value);
        }
    }

    ~QueueBasedOnUnidirectionalLinkedList() {
        while (!IsEmpty()) {
            T element;
            Pop(element);
        }
    }

    unsigned GetSize() const {
        return size;
    }

    void InsertAt(const T& value, unsigned index) {
        if (index < 0 || index > size) {
            return;
        }

        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else if (index == size) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            Node<T>* curr = head;
            for (unsigned i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }

        size++;
    }

    T RemoveAt(unsigned index) {
        if (IsEmpty() || index < 0 || index >= size) {
            return T();
        }

        Node<T>* curr = head;

        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else if (index == 0) {
            head = head->next;
        }
        else if (index == size - 1) {
            while (curr->next != tail) {
                curr = curr->next;
            }
            tail = curr;
            curr->next = nullptr;
        }
        else {
            for (unsigned i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            Node<T>* temp = curr->next;
            curr->next = temp->next;
            temp->next = nullptr;
            return temp->data;
        }

        T value = curr->data;
        delete curr;
        size--;

        return value;
    }

    QueueBasedOnUnidirectionalLinkedList& operator=(const QueueBasedOnUnidirectionalLinkedList& other) {
        if (this != &other) {
            while (!IsEmpty()) {
                T element;
                Pop(element);
            }

            Node<T>* curr = other.head;
            while (curr != nullptr) {
                Push(curr->data);
                curr = curr->next;
            }
        }
        return *this;
    }

    QueueBasedOnUnidirectionalLinkedList& operator=(QueueBasedOnUnidirectionalLinkedList&& other) noexcept {
        if (this != &other) {
            while (!IsEmpty()) {
                T element;
                Pop(element);
            }

            head = other.head;
            tail = other.tail;
            size = other.size;

            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }
        return *this;
    }

    QueueBasedOnUnidirectionalLinkedList& operator=(initializer_list<T> ilist) {
        while (!IsEmpty()) {
            T element;
            Pop(element);
        }

        for (const T& value : ilist) {
            Push(value);
        }

        return *this;
    }

    bool Push(const T& element) {
        Node<T>* newNode = new Node<T>(element);

        if (IsEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
        return true;
    }

    bool Pop(T& element) {
        if (IsEmpty()) {
            return false;
        }

        element = head->data;

        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }

        size--;
        return true;
    }

    bool Peek(T& element) {
        if (IsEmpty()) {
            return false;
        }

        element = head->data;
        return true;
    }

    friend ostream& operator<<(ostream& os, const QueueBasedOnUnidirectionalLinkedList& queue) {
        Node<T>* curr = queue.head;
        while (curr != nullptr) {
            os << curr->data << " ";
            curr = curr->next;
        }
        return os;
    }

    bool IsEmpty() const {
        return size == 0;
    }
};

int main() {
    QueueBasedOnUnidirectionalLinkedList<int> queue;
    queue.Push(423);
    queue.Push(32);
    queue.Push(423);
    queue.Push(312);
    queue.Push(33);

    cout <<"Size - " << queue.GetSize() << endl;
    cout <<"Queue - " << queue << endl;

    int removedElement;
    if (queue.Pop(removedElement)) {
        cout << "Popped: " << removedElement << endl;
    }

    cout << "Size - " << queue.GetSize() << endl;
    cout << "Queue - " << queue << endl;

    int frontElement;
    if (queue.Peek(frontElement)) {
        cout << "Peek: " << frontElement << endl;
    }

    return 0;
}