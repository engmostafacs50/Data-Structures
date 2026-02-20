#pragma once
#include <iostream>
#include<exception>
#include<cassert>
using namespace std;
template<typename T>
class SinglyLinkedList
{
private:
    int length;
    struct Node
    {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr)  {}
    };

    Node* head;
    Node* tail;
    void print_helper(Node* node)
    {
        if (node == nullptr)
            return; 
        cout << node->data << " "; 
        print_helper(node->next);
    }
    void reverse_print_helper(Node* node)
    {
        if (node == nullptr)
            return;

        reverse_print_helper(node->next);
        cout << node->data << " ";
    }

public:
    SinglyLinkedList() :head(nullptr), tail(nullptr) ,length(0) {}

    void insert_front(T number)
    {
        length++; 
        Node* node = new Node(number);       
        if (head == nullptr) {
            head = tail = node;
        }
        else {
            node->next = head;
            head = node;
        }
    }
    void insert_end(T number)
    {
        length++;
        Node* node = new Node(number); 
        if (head == nullptr)
        {
            tail = head = node; 
        }
        else
        {
            tail->next = node; 
            tail = node; 
        }
    }
    void checking_data_integrity()
    {
        if (length == 0)
        {
            assert(head == nullptr);
            assert(tail == nullptr);
        }
        else
        {
            if (length == 1)
            {
                assert(head == tail);
            }
            else
            {
                assert(head != tail);
            }
            assert(!tail->next); 
        }
    }
    //void print1()
    //{
    //    Node* temp = head;

    //    while (temp != nullptr)
    //    {
    //        cout << temp->data << " ";
    //        temp = temp->next;
    //    }
    //}
    //void print2()
    //{
    //    for (Node* temp = head; temp != nullptr; temp = temp->next)
    //    {
    //        cout << temp->data << " ";
    //    }
    //    cout << endl;
    //}
    void print()
    {
        print_helper(head);
    }
    void reverse_print()
    {
        reverse_print_helper(head);
    }
    bool find(T number)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == number)
            {
                return true; 
            }
            temp = temp->next;
        }
        return false; 
    }
    T get_nt(int n)
    {
        Node* temp = head;

        for (int i = 1; i < n; i++)
        {
            if (temp == nullptr)
                throw out_of_range("Index out of range");

            temp = temp->next;
        }

        if (temp == nullptr)
            throw out_of_range("Index out of range");

        return temp->data;
    }
};