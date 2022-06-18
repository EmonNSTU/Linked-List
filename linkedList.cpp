#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *link;

};

void insertFront(Node *header, int data);
void insertLast(Node *header, int data);
void insertAt(Node *header, int data, int index);
void insertBeforeValue(Node *header, int data, int value);
void printList(Node *header);

int indexOfValue(Node *header, int value);
int valueOfIndex(Node *header, int index);

int main(){

    Node *header = (Node *) malloc(sizeof(Node));

    if(header == NULL){
        cout<<"Memory Not Available!"<<endl;
        return 0;
    }

    header->data = INT_MAX;
    header->link = NULL;

    insertLast(header, 10);
    insertLast(header, 10);
    insertLast(header, 50);
    insertAt(header,20,1);
    insertAt(header,15,3);
    insertAt(header,5,0);
    insertBeforeValue(header, 35, 15);
    insertBeforeValue(header, 33, 20);

    printList(header);

    cout<<indexOfValue(header, 5)<<endl;
    cout<<indexOfValue(header, 50)<<endl;

    cout<<valueOfIndex(header, 0)<<endl;
    cout<<valueOfIndex(header, 7)<<endl;
    cout<<valueOfIndex(header, 10)<<endl;

}

void insertFront(Node *header, int data){

    Node *node = (Node *) malloc(sizeof(Node));

    if(node == NULL){
        cout<<"Memory Not Available!"<<endl;
    }
    else{
        node->data = data;
        node->link = header->link;
        header->link = node;
    }

}

void insertLast(Node *header, int data){

    Node *ptr = header;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }

    Node *node = (Node *) malloc(sizeof(Node));

    if(node == NULL){
        cout<<"Memory Not Available!"<<endl;
    }
    else{
        node->data = data;
        node->link = ptr->link;
        ptr->link = node;
    }

}

void insertAt(Node *header, int data, int index){

    Node *ptr = header;
    int i = 0;

    while(i < index && ptr->link != NULL){
        i++;
        ptr = ptr->link;
    }

    if(i != index){
        cout<<"Out of Bound Index!"<<endl;
    }
    else if(ptr->link == NULL){
        cout<<"Out of Bound Index!"<<endl;
    }
    else{

        Node *node = (Node *) malloc(sizeof(Node));

        if(node == NULL){
            cout<<"Memory Not Available!"<<endl;
        }
        else{
            node->data = data;
            node->link = ptr->link;
            ptr->link = node;
        }

    }

}

void insertBeforeValue(Node *header, int data, int value){

    Node *ptr = header;
    Node *t;

    while(ptr->data != value && ptr->link != NULL){
        t = ptr;
        ptr = ptr->link;

        if(ptr->data == value) break;
    }

    if(ptr->link == NULL){
        cout<<"Value Not Found!"<<endl;
    }
    else{

       Node *node = (Node *) malloc(sizeof(Node));

       if(node == NULL){
           cout<<"Memory Not Available!"<<endl;
       }
       else{
           node->data = data;
           node->link = t->link;
           t->link = node;
       }
    }

}

void printList(Node *header){

    Node *ptr = header;

    do{
        ptr = ptr->link;
        cout<<ptr->data<<"\t";
    }
    while(ptr->link != NULL);
    cout<<endl;
}

int indexOfValue(Node *header, int value){

    Node *ptr = header->link;
    int index = 0;

    while(ptr->data != value && ptr->link != NULL){
        index++;
        ptr = ptr->link;
    }

    if(ptr->link == NULL && ptr->data != value){
        cout<<"Value not Found!"<<endl;
        return -1;
    }
    else{
        return index;
    }

}

int valueOfIndex(Node *header, int index){

    Node *ptr = header;

    while(index > -1 && ptr->link != NULL){
        index--;
        ptr = ptr->link;
    }

    if(ptr->link == NULL && index > -1){
        cout<<"Index Out of bound!"<<endl;
        return INT_MIN;
    }
    else{
        return ptr->data;
    }

}
