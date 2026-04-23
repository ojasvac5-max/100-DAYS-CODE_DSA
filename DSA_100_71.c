#include <stdio.h>
#include <string.h>

#define SIZE 100
#define EMPTY -1

int table[SIZE];
int m; 
int hash(int key) {
    return key % m;
}

void insert(int key) {
    int h = hash(key);

    for(int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if(table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }

    printf("Hash table full\n");
}

void search(int key) {
    int h = hash(key);

    for(int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if(table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if(table[index] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);  
    scanf("%d", &q);   

    for(int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    while(q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0) {
            insert(key);
        }
        else if(strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}