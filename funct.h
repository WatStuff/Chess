bool shall_I_attack(char piece, int player)
{
	int pyr;
	if(piece==' '){return true;}
	else
	{
		if(piece==toupper(piece)){pyr = 1;}
		else{pyr = 2;}
		if(pyr == player){return false;}
		else{return true;}
	}
}





bool look_for_check(int row, int column,int player,char enemy)
{
	if(shall_I_attack(board[row][column],player)==true)		///está ocupada por un enemigo
		{
			if(board[row][column]=='q' || board[row][column]== 'Q' || board[row][column]==enemy || board[row][column]==toupper(enemy))
			{
				cout<<"take care with "<<board[row][column]<<" in ";
				switch(column)
					{
							case 0:
								cout<<" A ";break;
							case 1:
								cout<<" B ";break;
							case 2:
								cout<<" C ";break;
							case 3:
								cout<<" D ";break;
							case 4:
								cout<<" E ";break;
							case 5:
								cout<<" F ";break;
							case 6:
								cout<<" G ";break;
							case 7:
								cout<<" H ";break;
					}
				cout<<8-row<<endl;
				return true;
			}
		}
	return false;
}

bool check_lines(int start[], int player)
{	
	bool danger = false;
	int row;
	int column;
			///cuadrante I
		row = start[0]-1;
		column = start[1]+1;
		while(row>=0 && column<8)
		{
			if(look_for_check(row,column,player,'b')==true){danger = true; break;}
			row--;
			column++;	
		}


			///cuadrante II

		row = start[0]-1;
		column = start[1]-1;
		while(row>=0 && column>=0)
		{
			if(look_for_check(row,column,player,'b')==true){danger = true; break;}

			row--;
			column--;
		}	 



			///cuadrante III

		row = start[0]+1;
		column = start[1]-1;
		while(row<8 && column>=0)
		{
			if(look_for_check(row,column,player,'b')==true){danger = true; break;}
			row++;
			column--;	
		}
	



		///cuadrante IV

		row = start[0]+1;
		column = start[1]+1;
		while(row<8 && column<8)
		{
			if(look_for_check(row,column,player,'b')==true){danger = true; break;}
			row++;
			column++;	
		}

	

		row = start[0];
		column = start[1] + 1;
		
		while(column<8)
		{
			if(look_for_check(row,column,player,'t')==true){danger = true; break;}
			column++;	
		}
		

	///cuadrante2
	

		row = start[0]-1;
		column = start[1];
		while(row>=0)
		{
			if(look_for_check(row,column,player,'t')==true){danger = true; break;}	
			row--;	
		}
		


	///cuadrante3
	

		row = start[0];
		column = start[1]-1;
		while(column>=0)	
		{
			if(look_for_check(row,column,player,'t')==true){danger = true; break;}		
			column--;	
		}	



	///cuadrante4


		row = start[0]+1;
		column = start[1];
		while(row<8)
		{
			if(look_for_check(row,column,player,'t')==true){danger = true; break;}	
			row++;
		}
		


return danger;
}

bool warning(int row_,int column_,int player)
{
	int place[2];
	place[0] = row_;
	place[1] = column_;
	bool danger_1;
	///lineal movement
	if(check_lines(place,player)==true){danger_1 = true;}
	///inmediate movement
	///horse mv
	return danger_1;
}


int iter(int row, int column, int start[],int end[],int player)
{
	if(board[row][column]==' ')						///la casilla recorrida está libre
	{
		if(row==end[0] && column==end[1])				///en este la casilla recorrida coincide con la elegida
		{
			board[end[0]][end[1]] = board[start[0]][start[1]];
			board[start[0]][start[1]] = ' ';
			return 1;
		}
	}

	else									///la casilla recorrida está ocupada
	{
		if(shall_I_attack(board[row][column],player)==true)		///está ocupada por un enemigo
		{
			if(row==end[0] && column==end[1])                               ///en este la casilla recorrida coincide con la elegi$
			{
				board[end[0]][end[1]] = board[start[0]][start[1]];
				board[start[0]][start[1]] = ' ';
				return 1;
			}
			
		}
		else{return 2;}

	}
return 3;
}

bool check_if_av(int start[],int end[])
{
		if(start[0]>=0 && start[0]<8 && start[1]>=0 && start[1]<8 && end[0]>=0 && end[0]<8 && end[1]>=0 && end[1]<8){return true;}
		else{return false;}
	
}

int quadrant(int start[],int end[])			///here is returned the quadrant or axe where is placed the destination
{
		if(end[0]<start[0] && end[1]>start[1]){return 1;}	///x>0 ^ y>0
		if(end[0]<start[0] && end[1]<start[1]){return 2;}	///x<0 ^ y>0
		if(end[0]>start[0] && end[1]<start[1]){return 3;}	///x<0 ^ y<0
		if(end[0]>start[0] && end[1]>start[1]){return 4;}	///x>0 ^ y<0
		if(end[0]==start[0] && end[1]>start[1]){return 5;}	///x>0 ^ y=0
		if(end[0]<start[0] && end[1]==start[1]){return 6;}	///x=0 ^ y>0
		if(end[0]==start[0] && end[1]<start[1]){return 7;}	///x<0 ^ y=0
		if(end[0]>start[0] && end[1]==start[1]){return 8;}	///x=0 ^ y<0
}

/***
void current_board1()
{
	for(int f_1 = 0; f_1<8; f_1++)
	{
		cout<<"\t\t\t\t\t ";
		for(int p_1 = 0; p_1<17;p_1++){cout<<"-";}
		cout<<endl<<"\t\t\t\t\t"<<8-f_1<<"|";
		for(int c_1 = 0; c_1<8; c_1++)
		{
			cout<<board[f_1][c_1]<<"|";
		}
	cout<<endl;
	}
	cout<<"\t\t\t\t\t ";
	for(int p_1 = 0; p_1<17;p_1++){cout<<"-";}
	cout<<endl;
	cout<<"\t\t\t\t\t  A B C D E F G H"<<endl;
}***/


void current_board(int player)
{	
	if(player==1)
	{
		for(int f_1 = 0; f_1<8; f_1++)
		{
			cout<<"\t\t\t\t\t ";
			for(int p_1 = 0; p_1<17;p_1++){cout<<"-";}
			cout<<endl<<"\t\t\t\t\t"<<8-f_1<<"|";
			for(int c_1 = 0; c_1<8; c_1++)
			{
				cout<<board[f_1][c_1]<<"|";
			}
		cout<<endl;
		}
		cout<<"\t\t\t\t\t ";
		for(int p_1 = 0; p_1<17;p_1++){cout<<"-";}
		cout<<endl;
		cout<<"\t\t\t\t\t  A B C D E F G H"<<endl;	
			
	}
	
	if(player==2)
	{
		for(int f_1 = 7; f_1>=0; f_1--)
		{
			cout<<"\t\t\t\t\t ";
			for(int p_1 = 0; p_1<17;p_1++){cout<<"-";}
			cout<<endl<<"\t\t\t\t\t"<<8-f_1<<"|";
			for(int c_1 = 7; c_1>=0; c_1--)
			{
				cout<<board[f_1][c_1]<<"|";
			}
		cout<<endl;
		}
		cout<<"\t\t\t\t\t ";
		for(int p_1 = 0; p_1<17;p_1++){cout<<"-";}
		cout<<endl;
		cout<<"\t\t\t\t\t  H G F E D C B A"<<endl;
	}

}


bool bishop(int start[], int end[], int player)
{
	if((player==1 && board[start[0]][start[1]]=='b') || (player==2 && board[start[0]][start[1]]=='B')){return false;}
	int row;
	int column;

	if(quadrant(start,end)==1)			///cuadrante I
	{
		row = start[0]-1;
		column = start[1]+1;
		while(row>=0 && column<8)
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){return false;}
			row--;
			column++;	
		}
	}

	if(quadrant(start,end)==2)			///cuadrante II
	{
		row = start[0]-1;
		column = start[1]-1;
		while(row>=0 && column>=0)
		{
			if(iter(row,column,start,end,player)==1){return true;}
			if(iter(row,column,start,end,player)==2){return false;}
			row--;
			column--;
		}	 
	}


	if(quadrant(start,end)==3)			///cuadrante III
	{
		row = start[0]+1;
		column = start[1]-1;
		while(row<8 && column>=0)
		{
			if(iter(row,column,start,end,player)==1){return true;}
			if(iter(row,column,start,end,player)==2){return false;}
			row++;
			column--;	
		}
	}



	if(quadrant(start,end)==4)			///cuadrante IV
	{
		row = start[0]+1;
		column = start[1]+1;
		while(row<8 && column<8)
		{
			if(iter(row,column,start,end,player)==1){return true;}
			if(iter(row,column,start,end,player)==2){return false;}
			row++;
			column++;	
		}
	}

return false;
}

 bool pawn_iter(int start[],int end[], int front, int inc,int player)
{	
	int row = start[0];
	int column = start[1];
	row = row + inc;

	
	if(end[0]==row && end[1]==column && board[row][column]==' ')	///peon avanza 1
	{
		board[row][column] = board[start[0]][start[1]];
		board[start[0]][start[1]] = ' ';
		return true;
	}
	if(shall_I_attack(board[row][column],player)==false){cout<<board[row][column]<<endl;return false;}
	column--;

	
	
	if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true && board[row][column]!=' ')
	{
		board[row][column] = board[start[0]][start[1]];
		board[start[0]][start[1]] = ' ';
		return true;
	}			
	column = column + 2;

	
	if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true && board[row][column]!=' ')
	{
		board[row][column] = board[start[0]][start[1]];
		board[start[0]][start[1]] = ' ';
		return true;
	}
	column--;
	cout<<row<<endl;
	if(row==front)
	{
		row = row + inc;
		if(end[0]==row && end[1]==column && board[row][column]==' ')
		{
			board[row][column] = board[start[0]][start[1]];
			board[start[0]][start[1]] = ' ';
			return true;
		}
	}
}


bool tower(int start[], int end[], int player)
{
	if((player==1 && board[start[0]][start[1]]=='t') || (player==2 && board[start[0]][start[1]]=='T')){return false;}
	int row;
	int column;
	///cuadrante1

	if(quadrant(start,end)==5)
	{
		row = start[0];
		column = start[1] + 1;
		
		while(column<8)
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){return false;}
			column++;	
		}
		
	}
	///cuadrante2
	
	if(quadrant(start,end)==6)
	{
		row = start[0]-1;
		column = start[1];
		while(row>=0)
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){break;}
			row--;	
		}
		
	}

	///cuadrante3
	
	if(quadrant(start,end)==7)
	{	row = start[0];
		column = start[1]-1;
		while(column>=0)	
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){break;}
			column--;	
		}	

	}

	///cuadrante4

	if(quadrant(start,end)==8)
	{	row = start[0]+1;
		column = start[1];
		while(row<8)
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){break;}
			row++;	
		}
		
	}
	return false;
}



bool horse(int start[], int end[], int player)
{
	if((player==1 && board[start[0]][start[1]]=='h') || (player==2 && board[start[0]][start[1]]=='H')){return false;}
	int row = start[0];
	int column = start[1];
	if(quadrant(start,end)==1)
	{
			row--;
			column = column + 2;
			if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true)
			{
				board[row][column] = board[start[0]][start[1]];
				board[start[0]][start[1]] = ' ';
				return true;
			}
		
			row--;
			column--;
			if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true)
			{
				board[row][column] = board[start[0]][start[1]];
				board[start[0]][start[1]] = ' ';
				return true;
			}			
	}

	if(quadrant(start,end)==2)
	{
			row--;
			column = column - 2;
			if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true)
			{
				board[row][column] = board[start[0]][start[1]];
				board[start[0]][start[1]] = ' ';
				return true;
			}
			column++;
			row--;
			if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true)
			{
				board[row][column] = board[start[0]][start[1]];
				board[start[0]][start[1]] = ' ';
				return true;
			}			
	}

	if(quadrant(start,end)==3)
	{
			row++;
			column = column - 2;
			if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true)
			{
				board[row][column] = board[start[0]][start[1]];
				board[start[0]][start[1]] = ' ';
				return true;
			}
		
			row++;
			column++;
			if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true)
			{
				board[row][column] = board[start[0]][start[1]];
				board[start[0]][start[1]] = ' ';
				return true;
			}			
	}

	if(quadrant(start,end)==4)
	{
			row++;
			column = column + 2;
			if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true)
			{
				board[row][column] = board[start[0]][start[1]];
				board[start[0]][start[1]] = ' ';
				return true;
			}
		
			row++;
			column--;
			if(end[0]==row && end[1]==column && shall_I_attack(board[end[0]][end[1]],player)==true)
			{
				board[row][column] = board[start[0]][start[1]];
				board[start[0]][start[1]] = ' ';
				return true;
			}			
	}



}


bool king(int start[], int end[], int player)
{
	if((player==1 && board[start[0]][start[1]]=='k') || (player==2 && board[start[0]][start[1]]=='K')){return false;}
	int row_ = start[0];
	int column_ = start[1];
	column_++;
	if(end[0]==row_ && end[1]==column_)
	{
			if(shall_I_attack(board[row_][column_],player)==true)
			{
				if(warning(row_,column_,player)==false){board[row_][column_] = board[start[0]][start[1]]; board[start[0]][start[1]] = ' ';return true;}
			}
	}
///	if(warning(row_,column_,player)==false && shall_I_attack(board[row_][column_],player)==true && end[0]==row_ && end[1]==column_)
	///	{board[row_][column_] = board[start[0]][start[1]]; board[start[0]][start[1]] = ' ';return true;}
	
	row_--;
	
	if(end[0]==row_ && end[1]==column_)
	{
			if(shall_I_attack(board[row_][column_],player)==true)
			{
				if(warning(row_,column_,player)==false){board[row_][column_] = board[start[0]][start[1]]; board[start[0]][start[1]] = ' ';return true;}
			}
	}
	
	column_--;
	
	if(end[0]==row_ && end[1]==column_)
	{
			if(shall_I_attack(board[row_][column_],player)==true)
			{
				if(warning(row_,column_,player)==false){board[row_][column_] = board[start[0]][start[1]]; board[start[0]][start[1]] = ' ';return true;}
			}
	}
	
	column_--;
	
	if(end[0]==row_ && end[1]==column_)
	{
			if(shall_I_attack(board[row_][column_],player)==true)
			{
				if(warning(row_,column_,player)==false){board[row_][column_] = board[start[0]][start[1]]; board[start[0]][start[1]] = ' ';return true;}
			}
	}
	
	row_++;
	
	if(end[0]==row_ && end[1]==column_)
	{
			if(shall_I_attack(board[row_][column_],player)==true)
			{
				if(warning(row_,column_,player)==false){board[row_][column_] = board[start[0]][start[1]]; board[start[0]][start[1]] = ' ';return true;}
			}
	}
	
	row_++;
	
	if(end[0]==row_ && end[1]==column_)
	{
			if(shall_I_attack(board[row_][column_],player)==true)
			{
				if(warning(row_,column_,player)==false){board[row_][column_] = board[start[0]][start[1]]; board[start[0]][start[1]] = ' ';return true;}
			}
	}
	
	column_++;
	
	if(end[0]==row_ && end[1]==column_)
	{
			if(shall_I_attack(board[row_][column_],player)==true)
			{
				if(warning(row_,column_,player)==false){board[row_][column_] = board[start[0]][start[1]]; board[start[0]][start[1]] = ' ';return true;}
			}
	}
	
	column_++;
	
	if(end[0]==row_ && end[1]==column_)
	{
			if(shall_I_attack(board[row_][column_],player)==true)
			{
				if(warning(row_,column_,player)==false){board[row_][column_] = board[start[0]][start[1]]; board[start[0]][start[1]] = ' ';return true;}
			}
	}
}


bool queen(int start[], int end[], int player)
{
	if((player==1 && board[start[0]][start[1]]=='q') || (player==2 && board[start[0]][start[1]]=='Q')){return false;}

	int row;
	int column;
	
	if(quadrant(start,end)==1)			///cuadrante I
	{
		row = start[0]-1;
		column = start[1]+1;
		while(row>=0 && column<8)
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){break;}
			row--;
			column++;	
		}
	}

	if(quadrant(start,end)==2)			///cuadrante II
	{
		row = start[0]-1;
		column = start[1]-1;
		while(row>=0 && column>=0)
		{
			if(iter(row,column,start,end,player)==1){return true;}
			if(iter(row,column,start,end,player)==2){break;}
			row--;
			column--;
		}	 
	}


	if(quadrant(start,end)==3)			///cuadrante III
	{
		row = start[0]+1;
		column = start[1]-1;
		while(row<8 && column>=0)
		{
			if(iter(row,column,start,end,player)==1){return true;}
			if(iter(row,column,start,end,player)==2){break;}
			row++;
			column--;	
		}
	}



	if(quadrant(start,end)==4)			///cuadrante IV
	{
		row = start[0]+1;
		column = start[1]+1;
		while(row<8 && column<8)
		{
			if(iter(row,column,start,end,player)==1){return true;}
			if(iter(row,column,start,end,player)==2){break;}
			row++;
			column++;	
		}
	}

	if(quadrant(start,end)==5)
	{
		row = start[0];
		column = start[1] + 1;
		
		while(column<8)
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){break;}
			column++;	
		}
		
	}
	///cuadrante2
	
	if(quadrant(start,end)==6)
	{
		row = start[0]-1;
		column = start[1];
		while(row>=0)
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){break;}
			row--;	
		}
		
	}

	///cuadrante3
	
	if(quadrant(start,end)==7)
	{	row = start[0];
		column = start[1]-1;
		while(column>=0)	
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){break;}
			column--;	
		}	

	}

	///cuadrante4

	if(quadrant(start,end)==8)
	{	row = start[0]+1;
		column = start[1];
		while(row<8)
		{
			if(iter(row,column,start,end,player)==1){return true;}		
			if(iter(row,column,start,end,player)==2){break;}
			row++;	
		}
		
	}

return false;
}


bool pawn(int start[], int end[], int player)
{
	if((player==1 && board[start[0]][start[1]]=='p') || (player==2 && board[start[0]][start[1]]=='P')){return false;}
	cout<<"pawn";
///int row = start[0];
///	int column = start[1];
	if(player==2)
	{
		return pawn_iter(start,end,2,1,2);	
	}
	if(player==1)
	{
		return pawn_iter(start,end,5,-1,1);	
	}
	return false;
}


bool manager(int start[], int end[], int player)
{
	char current_piece = board[start[0]][start[1]];
	cout<<current_piece<<endl;
	switch(toupper(current_piece))
	{
			case 'P':
				return pawn(start, end, player);
			case 'H':
				return horse(start, end, player);
			case 'B':
				return bishop(start, end, player);
			case 'T':
				return tower(start, end, player);
			case 'K':
				return king(start, end, player);
			case 'Q':
				return queen(start, end, player);
			default:
				return false;
	}
}

int ch(char c)
{
		switch(toupper(c))
		{
				case 'A':
					return 0;
				case 'B':
					return 1;
				case 'C':
					return 2;
				case 'D':
					return 3;
				case 'E':
					return 4;
				case 'F':
					return 5;
				case 'G':
					return 6;
				case 'H':
					return 7;
		default:
			cout<<"The is no more than 8 columns"<<endl;
			return 8;
		}
}
