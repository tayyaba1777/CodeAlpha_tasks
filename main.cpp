#include <iostream>
using namespace std;
int main(){
	
int x = 10;
void*ptr = &x;
cout<<*(int*)ptr; // type casting 
	return 0;
}
