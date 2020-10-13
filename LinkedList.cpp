/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    Node* next;
} Node;

Node* createNode(int val) {
    Node* node = new Node();
    node->data = val;
    node->next = nullptr;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " " ;
        head = head -> next;
    }
    cout << endl;
}
Node* insertAtEnd(Node* head, int val) {
    if(head == nullptr) {
        return createNode(val);
    }
    Node* node = createNode(val);
    Node* tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = node;
    return head;
}

Node* insertAtBegin(Node* head, int val) {
    if(head == nullptr) {
        return createNode(val);
    }
    
    Node* node = createNode(val);
    node->next = head;
    head = node;
    return head;
}

Node* deleteBegin(Node* head) {
    if(head == nullptr)
        return nullptr;
        
    Node* tmp = head;
    head = head->next;
    delete(tmp);
    return head;
}

Node* deleteEnd(Node* head) {
    if(head == nullptr) 
        return nullptr;
    Node* tmp = head;
    Node* prev = nullptr;
    while(tmp->next != nullptr) {
        prev = tmp;
        tmp = tmp->next;
    }
    if(prev != nullptr) {
        prev->next = nullptr;
    }
    delete(tmp);

    return head;
}

Node* deleteAll(Node* head, int val) {
    if(head == nullptr)
        return nullptr;
    Node* tmp = head;
    Node* prev = nullptr;
    
    while(tmp != nullptr) {
        if(tmp->data == val) {
            if(prev != nullptr) {
                prev->next = tmp->next;
                delete(tmp);
                tmp = prev->next;
            } else {
                head = tmp->next;
                delete(tmp);
                tmp = head;
            }
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    return head;   
}

Node* reverseList(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
        
    Node* prev = nullptr;
    Node* cur = head;
    
    while(cur != nullptr) {
        Node* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    
    head = prev;
    return head;
}

Node* reverseListRecursive (Node* prev, Node*cur) {
    if(cur == nullptr)
        return prev;
        
    Node* tmp = cur->next;
    cur->next = prev;
    return(reverseListRecursive(cur, tmp));
}

int getSize(Node* head) {
    int count = 0;
    while(head != nullptr) {
        count++;
        head = head->next;
    }
    cout << "count : " << count << endl;
    return count;
}
  
int main() 
{ 
    //Node* head = createNode(1);
    Node* head = nullptr;
    for(int i = 2; i < 8; i++) {
        head = insertAtEnd(head, i);
    }
    printList(head);
    for(int i = 1; i > -1; i--) {
        head = insertAtBegin(head, i);
    }
    head = insertAtBegin(head, 1);
    head = insertAtBegin(head, 1);
    head = insertAtEnd(head, 4);
    head = insertAtBegin(head, 5);
    printList(head);
    head = deleteBegin(head);
    printList(head);
    head = deleteEnd(head);
    printList(head);
    head = deleteAll(head, 3);
    printList(head);
    head = deleteAll(head, 1);
    printList(head);
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 6);
    printList(head);
    head = deleteAll(head, 6);
    printList(head);
    head = reverseList(head);
    printList(head);
    head = reverseListRecursive(nullptr, head);
    printList(head);
    int size = getSize(head);
    for(int i = 0; i < size ; i++)
         head = deleteEnd(head);
    printList(head);
    head = reverseListRecursive(nullptr, head);
    printList(head);
    return 0; 
}
