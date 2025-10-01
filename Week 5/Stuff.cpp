#include <iostream>
#include "Stuff.h"
void showMenu(){
    std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n";
}
int addSelf(int a){
    return a + a;
}
int subtSelf(int a){
    return a - a;
}
int mulSelf(int a){
    return a*a;
}
int divSelf(int a){
    return a/a;
}