#define IN 1
#define OUT 0
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char wordbuf[50];
int idx = 0;
int words[25];

void add_word(){

    words[idx]++;
    wordbuf[0] = wordbuf[idx];
    idx=0;
}


void count_words(void){
    
    //memset(wordbuf, 0, sizeof(wordbuf));

    long nc, nl, nw;
    int c, state = OUT;
    nc = nl = nw = 0;
    
    memset(words, 0, sizeof(words));

    while ((c = getchar()) != EOF){
        ++nc;

        if (isalpha(c) || c == '-') { wordbuf[idx++] = c; }
        if(c == '\n') { ++ nl; }
        if(isspace(c)) { state = OUT; }
        else if (state == OUT) {
            state = IN;
            if(nw > 0) { add_word(); }
            ++nw;
        }
    } 

    if(idx > 0) {
            ++idx;
            add_word();
        }
    
    printf("%ld chars, %ld words, and %ld lines \n", nc, nw, nl);
}

int main(int agrc, const char * argv[]){

    count_words();

    return 0;
}
