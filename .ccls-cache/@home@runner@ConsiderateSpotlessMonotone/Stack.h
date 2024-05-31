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

        Node(int data, Node* next = nullptr, Node* previous = nullptr);

        // @NOTE: не хорошо, что в *.h, но быстрого исправления не нашлось
        friend std::ostream& operator<<(std::ostream& os, const Node& node)
        {
            return os << node.data;
        }

        static Node* read(std::istream& is);
    };

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

    void Push(int data);
    void Pop();
    int Peek() const;

    bool IsEmpty() const noexcept;
    std::string ToString() const;

    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
    friend std::istream& operator>>(std::istream& is, Stack& stack);
};
