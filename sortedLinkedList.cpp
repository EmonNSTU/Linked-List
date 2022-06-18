#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *link;

};

void insertValue(Node *head, int value);
void printLL(Node *head);

int main(){

    Node *head = (Node *) malloc(sizeof(Node));

    if(head == NULL){
        cout<<"Memory not available!"<<endl;
        return 0;
    }

    head->data = INT_MIN;
    head->link = NULL;

    int a, n;

    cout<<"Enter Number of element: ";
    cin>>a;

    srand(time(0));

    while(a--){

        //cin>>n;
        n = rand()%100;
        insertValue(head, n);

    }

    printLL(head);

    return 0;

}

void insertValue(Node *head, int value){

    Node *ptr = head;
    Node *pre;

    while(ptr->data < value && ptr->link != NULL){
        pre = ptr;
        ptr = ptr->link;

        if(ptr->data >= value) break;
    }

    Node *node = (Node *) malloc(sizeof(Node));

    if(node == NULL){
        cout<<"Memory Not Available!"<<endl;
    }
    else{

        if(ptr->link == NULL && ptr->data < value){
            node->data = value;
            node->link = ptr->link;
            ptr->link = node;
        }
        else{
            node->data = value;
            node->link = pre->link;
            pre->link = node;
        }

    }

}

void printLL(Node *head){

    Node *ptr = head;

    do{
        ptr = ptr->link;
        cout<<ptr->data<<"\t";
    }
    while(ptr->link != NULL);
    cout<<endl;

}
