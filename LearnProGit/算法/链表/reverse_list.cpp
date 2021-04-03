//
//  reverse_list.cpp
//  LearnProGit
//
//  Created by 熊康 on 2021/4/3.
//

#include <stdio.h>

Node* reverseList(Node *head, int k)
{
    if (head == nullptr) {
        return head;
    }
    
    int cnt = 0;
    Node *pre, *cur, *first;
    first = cur = head;
    pre = nullptr;

    while (cnt < k && cur != nullptr) {
        Node *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
        cnt++;
    }
    
    Node *res = pre;

    while (cur != nullptr) {
        cnt = 0;
        pre = nullptr;

        Node *tmp = cur;
        while (cnt < k && cur != nullptr) {
            Node *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            cnt++;
        }

        first->next = pre;
        first = tmp;
    }
    
    return res;
}

Node* creatList(int listLen) {
    Node *head = new Node();
    head->val = 1;
    Node *cur = head;

    for (int i = 1; i < listLen; i++) {
        Node *tmp = new Node();
        tmp->val = i + 1;
        cur->next = tmp;
        cur = cur->next;
    }
    cur->next = nullptr;
    
    return  head;;
}

void printList(Node *head) {
    Node *cur = head;
    while(cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void reverseListTest()
{
    Node *head = creatList(20);
    std::cout << "before:  ";
    printList(head);
    
    Node *reverseHead = reverseList(head, 5);
    std::cout << "after :  ";
    printList(reverseHead);
}

