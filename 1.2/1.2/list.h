#pragma once
#include <iostream>
#include <initializer_list>

template <class T>
class list 
{
private:
    struct Node 
    {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    list() : head(nullptr), tail(nullptr), size(0) {}

    list(std::initializer_list<T> values) : list() {
        for (const auto& value : values) {
            push_back(value);
            size++;
        }
    }

    ~list()
    {
        clear();
    }

    list& operator=(const list& other) 
    {
        if (this != &other) 
        {
            clear();
            std::cout << other.size;
        }
        size = other.size;
        return *this;
    }

    void push_back(const T& value) 
    {
        Node* newNode = new Node(value);

        if (head == nullptr) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void push_front(const T& value) 
    {
        Node* newNode = new Node(value);

        if (head == nullptr) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        size++;
    }

    void pop_back() 
    {
        if (tail == nullptr) 
        {
            return;
        }

        if (head == tail) 
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else 
        {
            Node* prevNode = tail->prev;
            prevNode->next = nullptr;
            delete tail;
            tail = prevNode;
        }

        size--;
    }

    void pop_front() 
    {
        if (head == nullptr) 
        {
            return;
        }

        if (head == tail) 
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else 
        {
            Node* nextNode = head->next;
            nextNode->prev = nullptr;
            delete head;
            head = nextNode;
        }

        size--;
    }

    void clear() 
    {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int length() const
    {
        return size;
    }

    
    void print() const 
    {
        for (const auto& element : *this) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    class Iterator {
    private:
        Node* currentNode;

    public:
        Iterator(Node* node) : currentNode(node) {}

        Iterator& operator++() 
        {
            if (currentNode != nullptr) {
                currentNode = currentNode->next;
            }
            return *this;
        }

        T& operator*() const 
        {
            return currentNode->data;
        }

        bool operator!=(const Iterator& other) const 
        {
            return currentNode != other.currentNode;
        }
    };

    Iterator begin() const 
    {
        return Iterator(head);
    }

    Iterator end() const 
    {
        return Iterator(nullptr);
    }
};
