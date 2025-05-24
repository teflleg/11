#pragma once

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void AddBack(Node* sent,int data);
void Print(Node* sent);
void DoublePrime(Node* sent);
bool IsPrime(int x);
void RemoveMultiple15(Node* sent);
bool isIncreasing(Node* sent);
bool isDecreasing(Node* sent);
void SortDecreasing(Node* sent);
int FirstDigit(int x);
void Clear(Node* sent);
