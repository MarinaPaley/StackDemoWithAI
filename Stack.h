#pragma once

#include <iostream>
#include <sstream>

class Stack final
{
    struct Node final
    {
        int data;
        Node* next;
        Node* previous;

        Node(const int data, Node* next = nullptr, Node* previous = nullptr);

        Node* clone() const;

        friend std::ostream& operator<<(std::ostream& os, const Node& node);

        static Node* read(std::istream& is);
    };

    // @NOTE: дублирование для того, чтобы разрешить видимость private nested struct во внешнем контексте
    friend std::ostream& operator<<(std::ostream& os, const Stack::Node& node);

    Node* head;
    Node* tail;

    void Push(Node* node);

public:
    Stack();
    Stack(std::initializer_list<int> list);
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;

    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;

    ~Stack();

    void Push(const int data);
    void Pop();
    int Peek() const;

    bool IsEmpty() const noexcept;
    std::string ToString() const;

    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
    friend std::istream& operator>>(std::istream& is, Stack& stack);
};
