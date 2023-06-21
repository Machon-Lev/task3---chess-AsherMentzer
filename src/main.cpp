// Chess 
#include "Chess.h"
#include "Board.h"

int main()
{
	string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
//	string board = "##########K###############################R#############r#r#####";
	Chess a(board);
	Board gameBoard(board);
	int codeResponse = 0;
	string res = a.getInput();
	while (res != "exit")
	{
		/* 
		codeResponse value : 
		Illegal movements : 
		11 - there is not piece at the source  
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination 
		21 - illegal movement of that piece 
		31 - this movement will cause you checkmate

		legal movements : 
		41 - the last movement was legal and cause check 
		42 - the last movement was legal, next turn 
		*/
		int src_row = res[0] - 'a';
		int src_col = res[1] - '0' - 1;
		int dst_row = res[2] - 'a';
		int dst_col = res[3] - '0' - 1;
		codeResponse = gameBoard.do_command(Location(src_row,src_col), Location(dst_row, dst_col));
		a.setCodeResponse(codeResponse);
		res = a.getInput(); 
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}
