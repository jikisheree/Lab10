#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

string cards[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardscores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	return rand() % 13 + 1;
}

int calScore(int x,int y,int z){
	if (x > 10) x = 0;
	if (y > 10) y = 0;
	if (z > 10) z = 0;
	return (x + y + z) % 10;
}

int findYugiAction(int s){	
	if(s == 9) return 2;
	else if(s < 6) return 1;
	else{
		if((rand() % 100) < 69) return 1;
		else return 2;
	}
}

void checkWinner(int p, int y){
	cout << "\n---------------------------------\n";
	if (p == y) cout << "|             Draw!!!           |";
	else if (p > y) cout << "|         Player wins!!!        |";
	else if (p < y) cout << "|          Yugi wins!!!         |";
	cout << "\n---------------------------------\n";
}

int main(){
	srand(time(0));
	int pyscore, yugiscore, pyact, yugiact;
	int pycards[3] = {drawCard(), drawCard(), 0};
	int yugicards[3] = {drawCard(), drawCard(), 0};
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cards[pycards[0]] << " " << cards[pycards[1]] << "\n";
	pyscore = calScore(pycards[0],pycards[1],pycards[2]);
	cout << "Your score: " << pyscore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> pyact;
	}while(pyact != 1 && pyact != 2 );
	if(pyact == 1){
	
		cout << "Player draws the 3rd card!!!" << "\n";
		pycards[2] = drawCard();
		cout << "Your 3rd card: " << cards[pycards[2]] << "\n";
		pyscore = calScore(pycards[0], pycards[1], pycards[2]);
		cout << "Your new score: " << pyscore << "\n";
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cards[yugicards[0]] << " " << cards[yugicards[1]] << "\n";
	yugiscore = calScore(yugicards[0], yugicards[1], yugicards[2]);
	cout << "Yugi's score: " << yugiscore << "\n";
	yugiact = findYugiAction(yugiscore);
	if(yugiact == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		yugicards[2] = drawCard();
		cout << "Yugi's 3rd card: " << cards[yugicards[2]] << "\n";
		yugiscore = calScore(yugicards[0], yugicards[1], yugicards[2]);
		cout << "Yugi's new score: " << yugiscore << "\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	checkWinner(pyscore,yugiscore);
}
