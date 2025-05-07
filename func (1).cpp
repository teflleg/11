#include "func.hpp"
#include <iostream>

void AddBack(Node* sent,int data){
    Node* p= new Node;
    p->data=data;
    p->next=sent;
    p->prev=sent->prev;
    sent->prev->next=p;
    sent->prev=p;
}

bool IsPrime(int x){ 
    if(x==1) return false;
    int sq=sqrt(x);
    int d=2;
    while(d<=sq){
        if(x%d==0) return false;
        d++;
    }
    return true;
}



void DoublePrime(Node* sent){
    Node* p=sent->next;
    while(p!=sent){
        if(IsPrime(p->data)){
            Node* q=new Node;
            q->data=p->data;
            q->prev=p;
            q->next=p->next;
            p->next->prev=q;
            p->next=q;
            p=p->next;
        }
        p=p->next;
    }
}
void Print(Node* sent){
    Node* p=sent->next;
    while(p!=sent){
        std::cout<<p->data<<' ';
        p=p->next;
    }
}

void RemoveMultiple15(Node* sent){
    Node* p=sent->next;
    while(p!=sent){
        if(p->data % 15 == 0){
            Node* tmp=p;
            p->prev->next=p->next;
            p->next->prev=p->prev;
            p=p->prev;
            delete tmp;
        }
        p=p->next;
    }
}


bool isIncreasing(Node* sent){
    Node* p = sent->next;
    while(p!=sent && p->next != sent){
        if(p->data > p->next->data) return false;
        p=p->next;
    }
    return true;
    
}

bool isDecreasing(Node* sent){
    Node* p = sent->next;
    while(p!=sent && p->next != sent){
        if(p->data < p->next->data) return false;
        p=p->next;
    }
    return true;
    
}

int FirstDigit(int x){
    while (x > 9) x /= 10;
    return x;
}

void SortDecreasing(Node* sent){
    if (sent->next == sent) {
        return; 
    }
    bool swapped;
    do {
        swapped = false;
        Node* p = sent->next;
        Node* q = sent;
        while (p != sent && p->next != sent) {
            if (FirstDigit(p->data) < FirstDigit(p->next->data)) {
                Node* nextNode = p->next;
                p->next = nextNode->next;
                nextNode->next->prev = p;
                nextNode->prev = p->prev;
                p->prev->next = nextNode;
                nextNode->next = p;
                p->prev = nextNode;
                swapped = true;
            } else {
                q = p;
                p = p->next;
            }
        }
    } while (swapped);
}

void Clear(Node* sent) {
    Node* p=sent->next;
    while(p!=sent){
        Node* tmp=p->next;
        p=p->next;
        delete tmp;
    }
}

