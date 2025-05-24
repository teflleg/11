#include "func.hpp"

int main(){
    Node* sent= new Node;
    sent->next=sent;
    sent->prev=sent;
    
    AddBack(sent,3);
    AddBack(sent,7);
    AddBack(sent,75);
    if(isIncreasing(sent) || isDecreasing(sent)){
        RemoveMultiple15(sent);
        DoublePrime(sent);
    }
    else
        SortDecreasing(sent);
    Print(sent);
    Clear(sent);
    delete sent;
    return 0;
}

