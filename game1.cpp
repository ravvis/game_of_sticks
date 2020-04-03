#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int v;
	int d;
	int i;
} node;

node minimax(int n, int depth, bool ismax, int alpha, int beta){
   node g,j,k;
   j.v=0;
   j.d=0;
   j.i=0;

    
	if(n==1){
        if(ismax)
        {
             g.v = -10;
             g.d = depth;
             g.i = 0;
             return g;
        }
        else
         {
             g.v = 10;
             g.d = depth;
             g.i =0;
             return g;
        }
    }
    int i,max_m,max_d;

    if(ismax)
    {  int m =999;
       int mx=-999;
       int bestval = INT_MIN;
        for(i=1;i<4;i++)
        {  if(n-i>=1)
            {
            j= minimax(n-i,depth+1,!ismax, alpha, beta);
            bestval = max(bestval, j.v);
            alpha = max(bestval, alpha);
            if(beta <= alpha)
            	break;
            if(j.v>=mx)
            {  if(j.v==mx)
                { if(j.d<m && j.v!=0)
                    {
                    g.v=j.v;
                    g.d=j.d;
                    g.i = i;
                    }
                }
               else
                    {
                    mx=j.v;
                    g.v=j.v;
                    g.d=j.d;
                    g.i = i;
                    }
            }
           }
        }

     return g;
    }
    else
    {
        int m =-999;
       int mx=999;
       int bestval = INT_MAX;
        for(i=1;i<4;i++)
        { if(n-i>=1)
            {
            j= minimax(n-i,depth+1,!ismax, alpha, beta);
            bestval = min( bestval, j.v) ;
            beta = min( beta, bestval);
            if(beta <= alpha)
                break;
            if(j.v<=mx && j.v!=0)
            {  if(j.v==mx)
                { if(j.d<m)
                    {
                    g.v=j.v;
                    g.d=j.d;
                    g.i = i;
                    }
                }
               else
                   {
                    mx=j.v;
                    g.v=j.v;
                    g.d=j.d;
                    g.i = i;
                    }
            }
           }
        }

     return g;
    }
}

int main(){
	
	cout << "\n1. AI vs You?\n2. AI vs AI\n";
	int c;
	
	cin >> c;
	int n;
	cout << "choose 14, 21, 52 ..\n";
	cin >> n;
	bool bot1 = true;
	switch(c){
		case 1 :
			
			while(n > 0){
				if(n == 1){
					if(bot1){
						cout << "bot1 lost\n";
						return 0;
					}
					else{
						cout << "bot2 lost\n";
						return 0;
					}
				}
				if(bot1){
					node p;
					p = minimax(n, 0, true, INT_MIN, INT_MAX);
					cout << "choosing " << p.i << " sticks\n";
					n = n - p.i;
					cout << " n left : " << n << endl; 
				}
				else{
					int choice;
					cout << "enter a number between 1-3\n";
					cin >> choice;
					while(choice > 3 || choice < 1){
						cout << "you can only choose a number between 1-3\n";
						cin >> choice;
					}
					cout << "choosing " << choice << " sticks\n";
					n = n - choice;
					cout << " n left : " << n << endl; 
				}
				bot1 = !bot1;
			}
			break;
		case 2:
			bot1 = true;
			while(n > 0){
				if(n == 1){
					if(bot1){
						cout << "bot1 lost\n";
						return 0;
					}
					else{
						cout << "bot2 lost\n";
						return 0;
					}
				}
				if(bot1){
					node p;
					p = minimax(n, 0, true, INT_MIN, INT_MAX);
					cout << "choosing " << p.i << " sticks\n";
					n = n - p.i;
					cout << " n left : " << n << endl; 
				}
				else{
					node p;
					p = minimax(n, 0, true, INT_MIN, INT_MAX);
					cout << "choosing " << p.i << " sticks\n";
					n = n - p.i;
					cout << " n left : " << n << endl; 
				}
				bot1 = !bot1;
			}
			break;			
			
	} 
	
}
