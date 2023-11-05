#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 101


typedef struct Node {
    char str[MAX_STRING_LENGTH];
    struct Node *prev;
} Node;

Node* inserir(Node *head, char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->str, str, MAX_STRING_LENGTH);
    newNode->prev = head;
    return newNode;
}

Node* desfazer(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *prevHead = head->prev;
    free(head);
    return prevHead;
}

int main() {
    
    Node *alteracoes = NULL;
    char comando[MAX_STRING_LENGTH];

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "inserir") == 0) {
            
            char str[MAX_STRING_LENGTH];
            scanf(" %[^\n]", str);
            
            alteracoes = inserir(alteracoes, str);
            
        } else if (strcmp(comando, "desfazer") == 0) {
            
            if (alteracoes == NULL) {
                printf("NULL\n");
            } else {
                printf("%s\n", alteracoes->str);
                alteracoes = desfazer(alteracoes);
            }
            
        }
        
    }

    while (alteracoes != NULL) {
        Node *temp = alteracoes;
        alteracoes = alteracoes->prev;
        free(temp);
    }

    return 0;
}
