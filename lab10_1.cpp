#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    string grade[9] = {"A","B+","B","C+","C","D+","D","F","W"};
    srand(time(0));
    int i = rand() % 9 + 0;
    int p = 0;
    string x;
    cout << "Press Enter 3 times to reveal your future.";
    while(p<3){
    	cin.get();
    	p++;
	}
   
   
    cout << "You will get " << grade[i] << " in this 261102.";
    return 0;
}


