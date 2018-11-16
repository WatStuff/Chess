#include<iostream>
#include<functions.h>
using namespace std;

char board[][8] ={	{'t','h','b','k','q','b','h','t'},
			{'p','p','p','p','p','p','p','p'},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{'P','P','P','P','P','P','P','P'},
			{'T','H','B','K','Q','B','H','T'}};
			



int main()
{
	int player = 1;
	int start[2];
	char st_aux;
	int end[2];
	player = 1;
	bool rslt;
	while(1==1)
	{	
		current_board(player);
		cout<<endl<<"\t\t\t\t\t     ---------"<<endl;
		cout<<"\t\t\t\t\t     |player"<<player<<"|"<<endl;
		cout<<"\t\t\t\t\t     ---------"<<endl;
		cout<<endl<<"write the start position: ";
		cin>>st_aux;
		cin>>start[0];
		start[1] = ch(st_aux);
		if(start[1]==8){continue;}
		start[0] = 7 - (start[0]-1);
		cout<<board[start[0]][start[1]];
		cout<<endl<<"write the end position: ";
		cin>>st_aux;
		end[1] = ch(st_aux);
		cin>>end[0];
		end[0] = 7 - (end[0]-1);
		cout<<board[end[0]][end[1]];
		if(check_if_av(start,end)==true)
		{
			rslt = manager(start,end,player);
			if(rslt==false){continue;}
		}
		else{continue;}


		if(player==1){player = 2;continue;}
		if(player==2){player = 1;continue;}
	}


	return 0;
}
