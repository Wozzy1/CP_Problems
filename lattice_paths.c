#include <stdio.h>


typedef struct {
    int explore;
    int layer;
    int dist;
} node;

void BFS(node* v) {
    v->explore = 1;
    v->layer = 0;
    
}

int main(void) {


    return 0;
}