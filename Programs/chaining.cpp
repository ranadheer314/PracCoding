#include<iostream>
#include<time.h>
#include<vector>
#define size 15
using namespace std;
/*class Hashing {
public:

    int Hash_fun(int key,int siz) {
        return key%siz;
    }
};*/
class linkedlist {
public:
    int data;
    linkedlist* addr;
    linkedlist(int val) {
        data = val;
        addr = NULL;
    }
};

void insert(int dat, linkedlist* root) {
    linkedlist* temp = root;
    while (!temp) {
        temp = temp->addr;
    }
    linkedlist *newJ = new linkedlist(dat);
    temp->addr = newJ;
}

int Hash_fun(int key, int siz) {
    return key % siz;
}

int main() {
    int A[] = {22,78,98,54,51,21,4,55,6,52,3,2,5,4,5,2,8,4,5,2,5,56,5,62,1,56,2,2,62}; //Keys to be inserted
    int n = sizeof(A) / sizeof(A[0]);
    linkedlist* HashTable[size];
    for (int i = 0; i < size; i++) {
        HashTable[i] = NULL;
    }
    int p;
    for (int i = 0; i < n; i++) {
        p=Hash_fun(A[i], size);
        linkedlist* addr = HashTable[p];
        if (addr == NULL) {
            linkedlist* first=new linkedlist(A[i]);
            HashTable[p]=first;
        }
        else {
            insert(A[i], addr);
        }
    }
    for (int i = 0; i < size; i++) {
        if(HashTable[i]!=NULL)
            cout<<HashTable[i]->data<<"\t";
    }


    return 0;
}
