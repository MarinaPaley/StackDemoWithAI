#include "Stack.h"

Stack::Node::Node(int data, Node* next, Node* previous)
    : data{ data }, next{ next }, previous{ previous }
{
}

Stack::Node* Stack::Node::read(std::istream& is)
{
    int data;
    return is >> data ? new Node(data) : nullptr;
}

Stack::Stack()
    : head{nullptr}, tail{nullptr}
{
}

Stack::Stack(std::initializer_list<int> list)
    : Stack()
{
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        Push(*it);
    }
}

Stack::Stack(const Stack& other)
    : Stack()
{
    auto current = other.tail;
    while (current != nullptr)
    {
        Push(current->data);
        current = current->previous;
    }
}

Stack::Stack(Stack&& other) noexcept
{
    head = other.head;
    tail = other.tail;

    other.head = nullptr;
    other.tail = nullptr;
}

Stack& Stack::operator=(const Stack& other)
{
    if (this == &other)
    {
        return *this;
    }

    Stack temp(other);
    std::swap(head, temp.head);
    std::swap(tail, temp.tail);

    return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    head = other.head;
    tail = other.tail;

    other.head = nullptr;
    other.tail = nullptr;

    return *this;
}

Stack::~Stack()
{
    while (!IsEmpty())
    {
        Pop();
    }
}

void Stack::Push(Stack::Node* node)
{
    if (IsEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head->previous = node;
        head = node;
    }
}

void Stack::Push(int data)
{
    Push(new Node(data));
}

void Stack::Pop()
{
    if (IsEmpty())
    {
        return;
    }

    auto temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->previous = nullptr;
    }
    else
    {
        tail = nullptr;
    }

    delete temp;
}

int Stack::Peek() const
{
    if (IsEmpty())
    {
        std::logic_error("Stack is empty");
    }

    return head->data;
}

bool Stack::IsEmpty() const noexcept
{
    return nullptr == head;
}

std::string Stack::ToString() const
{
    std::ostringstream buffer{};
    buffer << *this;
    return buffer.str();
}

std::ostream& operator<<(std::ostream& os, const Stack& stack)
{
    auto current = stack.head;
    while (current != nullptr)
    {
        os << *current << " ";
        current = current->next;
    }

    return os;
}

std::istream& operator>>(std::istream& is, Stack& stack)
{
    Stack::Node* node = nullptr;
    while ((node = Stack::Node::read(is)) != nullptr)
    {
        stack.Push(node);
    }

    return is;
}
