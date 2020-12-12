int printf(char const *format, ...);

void empty(int* c){
    if(5>3){
        int a = (int) (5 > 5/2) || (5 >= 100) && (5 < 99);
        printf("%d", a);
    }

    if(4<3){
        int a = (int) (5 > 5/2) || (5 >= 100) && (5 < 99);
        printf("%d", a);
    }

    while(4<3){
        printf("%d", (5 > 5/2) || (5 >= 100) && (5 < 99));
    }
}

int main(){
    int a;
    empty(&a);
}