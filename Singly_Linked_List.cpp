#include <iostream>
using namespace std;
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList
{
    Node *head = nullptr;
public:
    void insert_at_head(int data)
    {
        Node *tmp = new Node(data);
        if (head == NULL)
            head = tmp;
        else
        {
            tmp->next = head;
            head = tmp;
        }
    }

    void delete_node()
    {
        Node *tmp = head;
        if (head != NULL)
        {
            head = head->next;
            delete tmp;
        }
        else
            cout << "\nList is already deleted!" << endl;
    }
    void display_list()
    {
        Node *tmp = head;
        cout << "\tList: ";
        if (tmp == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        while (tmp != nullptr)
        {
            cout << tmp->data;
            if (tmp->next != nullptr)
            {
                cout << " -> ";
            }
            tmp = tmp->next; // Move to the next node
        }
        cout << " -> nullptr" << endl;
    }
};
int main()
{
    SinglyLinkedList s;
    s.insert_at_head(20);
    s.insert_at_head(30);
    s.insert_at_head(40);
    s.insert_at_head(50);
    s.display_list();
    s.delete_node();
    s.delete_node();
    s.delete_node();
    s.delete_node();
    s.display_list();
    return 0;
}
