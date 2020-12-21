int printf(char const *format, ...);

const int a1 = 4 + 5;
int b = a1 + 3;
float c = (float) (5>3);

void empty(int* c){
    if(5>3){
        int a = 4 + 3 / 5;
        printf("%d\n", a);
    }
    b = b + 1;
    printf("%d\n", b);

    b++;
    int* d;
    d = &b;
    b = b+1;
    printf(" d= %d\n", *d);
    printf(" b= %d\n", b);

    if(4<3){
        int a = (int) (5 > 5/2) || (5 >= 100) && (5 < 99);
        printf("%d\n", a);
    }

    while(4<3){
        printf("%d\n", (5 > 5/2) || (5 >= 100) && (5 < 99));
    }
}

int main(){
    int a;
    empty(&a);
}