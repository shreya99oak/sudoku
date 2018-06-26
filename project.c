#include<stdio.h>
#include<string.h>
//#include<graphics.h>
//#include<X11/Xlib.h>
#include<ncurses.h>


#define N 9
#define UNASSIGNED 0

void level_1(int);
void level_2(int);
void level_3(int);

void func(char[9][9], char[9][9]);
void error(char [9][9], char [9][9]);
void print_grid(char [N][N],char [N][N]);
int solve(char [N][N]);
int find_unassigned(char [N][N], int *, int *);
int is_safe_num(char [N][N], int, int, int);
int is_exist_box(char [N][N], int , int, int );

int is_exist_col(char [N][N], int , int );
int is_exist_row(char [N][N], int , int );

int data(int,char[9][9],char[9][9]);

void main()
{

        initscr();
        cbreak();
        //noecho();
        keypad(stdscr, TRUE);
        //keypad(stdscr, TRUE);
        start_color();
        printw("---SUDOKU GAME---");
        attron(A_STANDOUT);
        attron(A_BOLD);
        int beep(void);
        flash();
        char level;
       WINDOW * win = newwin(100, 100, 0, 0);
       printw("\n INSTRUCTIONS:\n 1)insert any number from 1-9 inplace of the 0. Do not change any other number! \n 2) To submit the sudoku press 'z' several times\n 3)To end the game press 'ctrl+z' ");
       printw("\nENTER LEVEL \n[Press 1 for level 1 or Press 2 for level 2 or press 3 for level 3]\n");
       scanw("%c",&level);
       int n= (int)(level);
       if(level=='1')
       {
                //delwin( win);
                level_1(n);
        
       }
       else if(level=='2')
       {
                level_2(n);
       }
       else
       {
                level_3(n);
       }
        getch();  
 
 
endwin();
 }
     


void level_1(int n)
{
        
        
        WINDOW * subwin = newwin(100, 100, 0, 0);
        initscr();
        cbreak();
        //noecho();
        keypad(stdscr, TRUE);
        wborder(subwin, 0, 0, 0, 0, 0, 0, 0, 0);
        
        start_color();
        printw("---SUDOKU GAME: LEVEL EASY ---"); 
        attron(A_STANDOUT);
        attron(A_BOLD);


wmove(stdscr, 10, 10);     
printw("0 0 8 9 0 0 0 0 1");

wmove(stdscr, 11, 10);
printw("7 0 0 1 0 3 0 9 8");

wmove(stdscr, 12, 10);
printw("0 0 3 0 0 0 0 6 0");
refresh();
wmove(stdscr, 13, 10);

printw("0 0 0 0 4 8 1 0 0");
refresh();
wmove(stdscr, 14, 10);
printw("0 1 7 0 0 0 6 4 0");
refresh();
wmove(stdscr, 15, 10);
printw("0 0 5 2 1 0 0 0 0");
refresh();
wmove(stdscr, 16, 10);
printw("0 2 0 0 0 0 8 0 0");
refresh();
wmove(stdscr, 17, 10);
printw("6 8 0 5 0 1 0 0 7");
refresh();
wmove(stdscr, 18, 10);
printw("5 0 0 0 0 6 3 0 0");
refresh();
move(10,10);

  /*int secondsLeft=600;
  curs_set(0);
  do {
    printw("%d", secondsLeft);
    refresh();
    erase();
    secondsLeft--;
    napms(1000);
  } while (secondsLeft > 0);*/

char b[9][9]={'0','0','8','9','0','0','0','0','1',
	      '7','0','0','1','0','3','0','9','8',
	      '0','0','3','0','0','0','0','6','0',
	      '0','0','0','0','4','8','1','0','0',
	      '0','1','7','0','0','0','6','4','0',
	      '0','0','5','2','1','0','0','0','0',
	      '0','2','0','0','0','0','8','0','0',
	      '6','8','0','5','0','1','0','0','7',
	      '5','0','0','0','0','6','3','0','0'};
	     
char a[9][9]= {'0','0','8','9','0','0','0','0','1',
	      '7','0','0','1','0','3','0','9','8',
	      '0','0','3','0','0','0','0','6','0',
	      '0','0','0','0','4','8','1','0','0',
	      '0','1','7','0','0','0','6','4','0',
	      '0','0','5','2','1','0','0','0','0',
	      '0','2','0','0','0','0','8','0','0',
	      '6','8','0','5','0','1','0','0','7',
	      '5','0','0','0','0','6','3','0','0'};
	      
	 
	 
data(n,a,b);
      
         
 
 getch();  
 
 
endwin();


}


int data(int n,char a[9][9],char b[9][9])
{
        keypad(stdscr, TRUE);
        int x=10;
        int y=10;
        int i=0;
        int j=0;
               

        char ch;
        while((ch = getch()) != 'z')  /*error*/
        {
                move(y,x);
                char ch=getch();
                if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9')
                        {
                                b[i][j]=ch;
                        }
                switch(getch()){
                
                case KEY_UP:
                        {
                        wmove(stdscr,y-1,x);
                        y=y-1;
                        
                        char ch=getch();
                        if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9')
                        {
                                i=i+1;
                                b[i][j]=ch;
                        }
                        
                        break;
                        }
                        
                        
                case KEY_DOWN:
                        {wmove(stdscr,y+1,x);
                        y=y+1;
                        
                        char ch=getch();
                        if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9')
                        {
                                i=i-1;
                                b[i][j]=ch;
                        }
                        break;}
                        
                case KEY_LEFT:
                        {wmove(stdscr,y,x-2);
                        x=x-2;
                        char ch=getch();
                        if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9')
                        {
                                j=j-1;
                                b[i][j]=ch;
                                
                        
                        
                        }
                        break;
                        }
                        
                case KEY_RIGHT:
                        {
                        wmove(stdscr,y,x+2);
                        x=x+2;
                        
                        char ch=getch();
                        if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9')
                        {
                                j=j+1;
                                b[i][j]=ch;
                      
                        
                        }
                        break;
                        }
                        
              
                }

                
        }//end of while
         
         
        func(a,b);    
             


}





void level_2(int n)
{
        
        
        WINDOW * subwin = newwin(100, 100, 0, 0);
        initscr();
        cbreak();
        //noecho();
        keypad(stdscr, TRUE);
        wborder(subwin, 0, 0, 0, 0, 0, 0, 0, 0);
        
        start_color();
        printw("---SUDOKU GAME: LEVEL MEDIUM---");
        attron(A_STANDOUT);
        attron(A_BOLD);


wmove(stdscr, 10, 10);
printw("0 5 8 0 0 0 0 0 0");
refresh();
wmove(stdscr, 11, 10);
printw("4 3 9 0 7 0 0 0 0");
refresh();
wmove(stdscr, 12, 10);
printw("6 0 0 0 2 3 0 0 0");
refresh();
wmove(stdscr, 13, 10);
printw("9 0 2 0 0 1 0 3 7");
refresh();
wmove(stdscr, 14, 10);
printw("0 0 0 0 6 0 0 0 0");
refresh();
wmove(stdscr, 15, 10);
printw("0 4 0 7 0 0 2 0 9");
refresh();
wmove(stdscr, 16, 10);
printw("0 0 0 3 8 0 0 0 2");
refresh();
wmove(stdscr, 17, 10);
printw("0 0 0 0 4 0 3 8 1");
refresh();
wmove(stdscr,18,10);
printw("0 0 0 0 0 0 7 5 0");
refresh();


char b[9][9]={'0','5','8','0','0','0','0','0','0',
              '4','3','9','0','7','0','0','0','0',
              '6','0','0','0','2','3','0','0','0',
              '9','0','2','0','0','1','0','3','0',
              '0','0','0','0','6','0','0','0','0',
              '0','4','0','7','0','0','2','0','9',
              '0','0','0','3','8','0','0','0','2',
              '0','0','0','0','4','0','3','8','1',
              '0','0','0','0','0','0','7','5','0'};


char a[9][9]={'0','5','8','0','0','0','0','0','0',
              '4','3','9','0','7','0','0','0','0',
              '6','0','0','0','2','3','0','0','0',
              '9','0','2','0','0','1','0','3','0',
              '0','0','0','0','6','0','0','0','0',
              '0','4','0','7','0','0','2','0','9',
              '0','0','0','3','8','0','0','0','2',
              '0','0','0','0','4','0','3','8','1',
              '0','0','0','0','0','0','7','5','0'};
              
data(n,a,b);


         
 
 getch();  
 
 
endwin();


}




void level_3(int n)
{
        
        
        WINDOW * subwin = newwin(100, 100, 0, 0);
        initscr();
        cbreak();
        //noecho();
        keypad(stdscr, TRUE);
        wborder(subwin, 0, 0, 0, 0, 0, 0, 0, 0);
        
        start_color();
        printw("---SUDOKU GAME: LEVEL HARD---");
        attron(A_STANDOUT);
        attron(A_BOLD);


wmove(stdscr, 10, 10);
printw("0 6 0 1 0 4 0 5 0");
refresh();
wmove(stdscr, 11, 10);
printw("0 0 8 3 0 5 6 0 0");
refresh();
wmove(stdscr, 12, 10);
printw("2 0 0 0 0 0 0 0 1");
refresh();
wmove(stdscr, 13, 10);
printw("8 0 0 4 0 7 0 0 6");
refresh();
wmove(stdscr, 14, 10);
printw("0 0 6 0 0 0 3 0 0");
refresh();
wmove(stdscr, 15, 10);
printw("7 0 0 9 0 1 0 0 4");
refresh();
wmove(stdscr, 16, 10);
printw("5 0 0 0 0 0 0 0 2");
refresh();
wmove(stdscr, 17, 10);
printw("0 0 7 2 0 6 9 0 0");
refresh();
wmove(stdscr, 18, 10);
printw("0 4 0 5 0 8 0 7 0");
refresh();

char b[9][9]={ '0','6','0','1','0','4','0','5','0',
	  '0','0','8','3','0','5','6','0','0',
	  '2','0','0','0','0','0','0','0','1',
	  '8','0','0','4','0','7','0','0','6',
	  '0','0','6','0','0','0','3','0','0',
	  '7','0','0','9','0','1','0','0','4',
	  '5','0','0','0','0','0','0','0','2',
	  '0','0','7','2','0','6','9','0','0',
	  '0','4','0','5','0','8','0','7','0'
	};
	
char a[9][9]= { '0','6','0','1','0','4','0','5','0',
	  '0','0','8','3','0','5','6','0','0',
	  '2','0','0','0','0','0','0','0','1',
	  '8','0','0','4','0','7','0','0','6',
	  '0','0','6','0','0','0','3','0','0',
	  '7','0','0','9','0','1','0','0','4',
	  '5','0','0','0','0','0','0','0','2',
	  '0','0','7','2','0','6','9','0','0',
	  '0','4','0','5','0','8','0','7','0'
	};
	
	 
	 
	 
data(n,a,b);



 
 getch();  
 
 
endwin();


}



int is_exist_row(char a[N][N], int row, int num){
	for (int col = 0; col < 9; col++) {
		if (a[row][col] == num) {
			return 1;
		}
	}
	return 0;
}

int is_exist_col(char a[N][N], int col, int num) {
	for (int row = 0; row < 9; row++) {
		if (a[row][col] == num) {
			return 1;
		}
	}
	return 0;
}

int is_exist_box(char a[N][N], int startRow, int startCol, int num) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (a[row + startRow][col + startCol] == num) {
				return 1;
			} 
		}
	}
	return 0;
}

int is_safe_num(char a[N][N], int row, int col, int num) {
	return !is_exist_row(a, row, num) 
			&& !is_exist_col(a, col, num) 
			&& !is_exist_box(a, row - (row % 3), col - (col %3), num);
}

int find_unassigned(char a[N][N], int *row, int *col) {
	for (*row = 0; *row < N; (*row)++) {
		for (*col = 0; *col < N; (*col)++) {
			if (a[*row][*col] == 0) {
				return 1;
			}
		}
	}
	return 0;
}

int solve(char a[N][N]) {
	
	int row = 0;
	int col = 0;
	
	if (!find_unassigned(a, &row, &col)){
		return 1;
	}
	
	for (int num = 1; num <= N; num++ ) {
		
		if (is_safe_num(a, row, col, num)) {
			a[row][col] = num;
			
			if (solve(a)) {
				return 1;
			}
			
			a[row][col] = UNASSIGNED;
		}
	}
	
	return 0;
}

void print_grid(char a[N][N],char b[N][N]) 
{
	for (int row = 0; row < N; row++) 
	{
		for (int col = 0; col < N; col++) 
		{
			a[row][col]=a[row][col]+48;       //Converting all the elements of a to  characters
			
		}
		
	}
	int m=30;
	int i,j=0;
	for(i=0;i<N;i++)                                  // To print the solved sudoku on the output window
	{
	        wmove(stdscr,m,10);
	        printw("%c %c %c %c %c %c %c %c %c",a[i][j],a[i][j+1],a[i][j+2],a[i][j+3],a[i][j+4],a[i][j+5],a[i][j+6],a[i][j+7],a[i][j+8]);
	        refresh();
	        m++;
	}
	
	wmove(stdscr,m++,10);
	/* After this, a function should be called passing a and b as the parameter ,which will check each and every element of a and b and
	   display the no of the number of errors on the screen*/ 
	error(a,b);  
	
	


}

void func(char a[9][9], char b[9][9])                 //this function will be called after the user presses z 
				//a is the question of sudoku and b is the  solution of sudoku entered by user
{
	int i=0,j=0;
	

	for (i=0;i<9;i++)
{
	for(j=0;j<9;j++)        
{
	a[i][j]=a[i][j]-48;         // converting all the elements of sudoku to integers
}
}
	if (solve(a)) {
		print_grid(a,b);
	} else {
		printf("no solution");
	}
	
	
}



void error(char a[9][9], char b[9][9])
{
        int count=0;
        
        for( int m=0;m<9;m++)
        {
        
                for(int n=0;n<9;n++)
                {
                        if(a[m][n]==b[m][n])
                                count++;
                                
                                             
                }
        
        }
        
        
        if(count==81)
                printw("\n\nATTEMPT SUCCESSFUL!!");
                
        else
                {printw("\n\nATTEMPT FAILED:(\n");
                printw("NO. OF ERRORS:  %d\n",81-count);
                beep();}
          
        printw("TO TRY ANOTHER LEVEL PRESS 0 FOLLOWED BY THE LEVEL NO.\n ELSE PRESS ctrl+z TO EXIT THE GAME\n");
        if(getch()=='0')
                clear();
        char l;
        scanw("%c",l);
        
       if(l=='1')
       {
                //delwin( win);
                level_1(l);
        
       }
       else if(l=='2')
       {
                level_2(l);
       }
       else
       {
                level_3(l);
       }
        
        

}
















