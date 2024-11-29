/* Hashim Sobhi */
/*  11/28/2024  */
/* Soccer Game  */

#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

/********** Point Class **********/
class Point {
private:
    int x;
    int y;

public:
    Point();
    Point(int a);
    Point(int a, int b);
    int getX();
    void setX(int a);
    int getY();
    void setY(int b);
    ~Point();
};

/********** Line Class **********/
class Line {
private:
    Point start;
    Point end;

public:
    Line();
    Line(int x1, int y1, int x2, int y2);
    ~Line();
	void setLine(int x1, int y1, int x2, int y2);
    void draw();
};

/********** Rect Class **********/
class Rect {
private:
    Point tl;
    Point br;

public:
    Rect();
    Rect(int x1, int y1, int x2, int y2);
    ~Rect();
    void draw();
};

/********** Circle Class **********/
class Circle {
private:
    int rad;

public:
	Point c;
    Circle();
    Circle(int x, int y, int r);
    ~Circle();
    void draw();
};

/********** Picture Class **********/
class Picture {
private:
    int lNUM;
    int rNUM;
    int cNUM;
    Line* pLines;
    Rect* pRectangles;
    Circle* pCircles;

public:
    Picture();
    Picture(int l, int r, int c, Line* pl, Rect* pr, Circle* pc);
    ~Picture();
    void paint();
};

void ball(int x, int y, Circle& c); // set ball position
void player(int px1, int py1, Line* lines, Circle* head, int n); //set player position
void goalCelebration(int &px1, int &py1, Line* lines_Player, Circle* circles_Player, int &a, int i);
/********** Main Function **********/
int main() {
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "D:/BGI/");

    // set playground
	Line lines_playGround[1] = { Line(325, 250, 325, 450) }; // middle line
    Rect rects_playGround[6] = {
        Rect(50, 250, 600, 450), //inner border
        Rect(45, 245, 605, 455), //outer border
        Rect(50, 300, 100, 400), // 18 area
        Rect(550, 300, 600, 400), // 18 area
        Rect(50, 320, 75, 380),  // goalkeeper box
        Rect(575, 320, 600, 380) // goalkeeper box
    };
    Circle circles_playGround[1] = { Circle(325, 350, 30) }; //middle circle

    // paint the playground
    Picture playGround(1, 6, 1, lines_playGround, rects_playGround, circles_playGround);
    playGround.paint();
	
	// set Player1
	int px1 = 300;
	int py1 = 350;
	
	Line lines_Player[5] = { 
		Line(px1, py1, px1, py1+20), // mid line
		Line(px1-10, py1+15, px1, py1+5), //left hand
		Line(px1, py1+5, px1+10, py1+15), //right hand
		Line(px1-10, py1+30, px1, py1+20), //left leg
		Line(px1, py1+20, px1+10, py1+30) //right leg
	}; 
    Circle circles_Player[1] = { Circle(px1, py1-10, 8) }; //head
	
    // paint the Player
    Picture Player1(5, 0, 1, lines_Player, NULL, circles_Player);
    Player1.paint();
	
	// set Player2
	int px2 = 360;
	int py2 = 350;
	
	Line lines_Player2[5] = { 
		Line(px2, py2, px2, py2+20), // mid line
		Line(px2-10, py2+15, px2, py2+5), //left hand
		Line(px2, py2+5, px2+10, py2+15), //right hand
		Line(px2-10, py2+30, px2, py2+20), //left leg
		Line(px2, py2+20, px2+10, py2+30) //right leg
	}; 
    Circle circles_Player2[1] = { Circle(px2, py2-10, 8) }; //head
	
    // paint the Player
    Picture Player2(5, 0, 1, lines_Player2, NULL, circles_Player2);
    Player2.paint();
	
	
	
	// set ball
	int bx = 325;
	int by = 350;
	Circle b(bx,by,5); // the ball
	
	
	int goals1 = 0;
	int goals2 = 0;
	char ch,ch1,ch2;
	int n = 1; // who have ball? 1 or 2
	
	while(1){
		cleardevice();
		//paint
		setcolor(GREEN);
		playGround.paint();
		player(px1,py1, lines_Player,circles_Player,1);
		Player1.paint();
		player(px2,py2, lines_Player2,circles_Player2,2);
		Player2.paint();
		if(n == 1){
			if(ch1 == 75) bx = px1-17;
			if(ch1 == 77) bx = px1+17;
			by = py1+25;
		}
		else if(n == 2){
			if(ch1 == 'a') bx = px2-17;
			if(ch1 == 'd') bx = px2+17;
			by = py2+25;
		}
		
		ball(bx, by, b);
		b.draw();
		// show scores
		gotoxy(20,14);
		cout << goals1;
		gotoxy(60,14);
		cout << goals2;
		
		// take the input from keyboard  the arrows for player 1, 'w''s''d''a' for player two, Esc to Exit and 'c' for shooting
		ch = getch();
		if(ch == 0){ // for arrows
			ch = getch();
			ch2 = ch;
			if(ch == 72){ // up
				if(by > 250) py1-=5;
			}
			else if(ch == 80){ //down
				if(by < 450) py1+=5;
			}
			else if(ch == 77){ //right
				if(bx < 600) px1+=5;
				ch1 = ch;
			}
			else if(ch == 75){ //left
				if(bx > 50) px1-=5;
				ch1 = ch;
			}
		}
		else if(ch == 'c'){
			if(ch2 == 72 || ch2 == 'w'){
				while(by >250){
					by-=5;
					ball(bx, by, b);
					cleardevice();
					setcolor(GREEN);
					playGround.paint();
					setcolor(WHITE);
					Player1.paint();
					setcolor(BROWN);
					Player2.paint();
					setcolor(BLUE);
					b.draw();
					gotoxy(20,14);
					cout << goals1;
					gotoxy(60,14);
					cout << goals2;
					delay(20);
				}
			}
			else if(ch2 == 80 || ch2 == 's'){
				while(by < 450){
					by+=5;
					ball(bx, by, b);
					cleardevice();
					setcolor(GREEN);
					playGround.paint();
					setcolor(WHITE);
					Player1.paint();
					setcolor(BROWN);
					Player2.paint();
					setcolor(BLUE);
					b.draw();
					gotoxy(20,14);
					cout << goals1;
					gotoxy(60,14);
					cout << goals2;
					delay(20);
				
				}
			}
			else if(ch2 == 77 || ch2 == 'd'){
				while(bx < 600){
					bx+=5;
					ball(bx, by, b);
					cleardevice();
					setcolor(GREEN);
					playGround.paint();
					setcolor(WHITE);
					Player1.paint();
					setcolor(BROWN);
					Player2.paint();
					setcolor(BLUE);
					b.draw();
					gotoxy(20,14);
					cout << goals1;
					gotoxy(60,14);
					cout << goals2;
					delay(20);
				}
			}
			else if(ch2 == 75 || ch2 == 'a'){
				while(bx > 50){
					bx-=5;
					ball(bx, by, b);
					cleardevice();
					setcolor(GREEN);
					playGround.paint();
					setcolor(WHITE);
					Player1.paint();
					setcolor(BROWN);
					Player2.paint();
					setcolor(BLUE);
					b.draw();
					gotoxy(20,14);
					cout << goals1;
					gotoxy(60,14);
					cout << goals2;
					delay(20);
				}
			}
			
		}
		else if(ch == 27) break; //press Esc to exit
		else if(ch == 'w'){// up
			if(by > 250) py2-=5;
			ch2 = ch;
		}
		else if(ch == 's'){// down
			if(by < 450) py2+=5;
			ch2 = ch;
		}
		else if(ch == 'd'){// right
			if(by < 600) px2+=5;
			ch1 = ch;
			ch2 = ch;
		}
		else if(ch == 'a'){// left
			if(by > 50) px2-=5;
			ch1 = ch;
			ch2 = ch;
		}
		if(n == 1 && px2 >= bx-2 && px2 <= bx+2 && py2 <= py1+5 && py2 >= py1-5){// Player 2 takes the ball from the other player
			n = 2;
			if(ch1 == 'a') bx = px2-17;
			if(ch1 == 'd') bx = px2+17;
			by = py2+25;
		}
		if(n == 2 && px1 >= bx-2 && px1 <= bx+2 && py1 <= py2+5 && py1 >= py2-5){//Player 1 takes the ball from the other player
			n = 1;
			if(ch1 == 75) bx = px1-17;
			if(ch1 == 77) bx = px1+17;
			by = py1+25;
		}
		
		if(bx>=600 && by >= 330 && by <= 370){ // goal for player 1
			goals1++;
			
			
			px1 = 300;
			px2 = 360;
		    py1 = 350;
		    py2 = 350;
			n = 2;
			bx = px2-17;
			ball(bx, by, b);
			cleardevice();
			setcolor(GREEN);
			playGround.paint();
			setcolor(WHITE);
			Player1.paint();
			setcolor(BROWN);
			Player2.paint();
			setcolor(BLUE);
			b.draw();
			gotoxy(35,12);
			cout << "goalll!!!!!!";
			gotoxy(20,14);
			cout << goals1;
			gotoxy(60,14);
			cout << goals2;
			
			int a = 0;
			int i = 0;
			int f = 1;
			while(i++ < 80){
				if(i < 20 || (i > 40 && i < 60)) f = 1;
				else f = 2;
				goalCelebration(px1, py1, lines_Player, circles_Player, a, f);
				ball(bx, by, b);
				cleardevice();
				setcolor(GREEN);
				playGround.paint();
				setcolor(WHITE);
				Player1.paint();
				setcolor(BROWN);
				Player2.paint();
				setcolor(BLUE);
				b.draw();
				gotoxy(35,12);
				cout << "goalll!!!!!!";
				gotoxy(20,14);
				cout << goals1;
				gotoxy(60,14);
				cout << goals2;
				delay(80);
			}
			while(getch()!= 13);
			px1 = 300;
			px2 = 360;
		    py1 = 350;
		    py2 = 350;
			n = 2;
			bx = px2-17;
		}
		else if(bx>=600){ //out
			gotoxy(35,12);
			cout << "out!!!!!!";
			px1 = 300;
			px2 = 360;
		    py1 = 350;
		    py2 = 350;
			if(n == 1) {
				n = 2;
				bx = px2-17;
			}
			else if(n == 2){
				n = 1;
				bx = px1+17;
			}
			while(getch()!= 13);
		}
		if(bx <= 50 && by >= 330 && by <= 370){	// goal for player 2
			goals2++;
			gotoxy(35,12);
			cout << "goallll!!!!!!";
			px1 = 300;
			px2 = 360;
		    py1 = 350;
		    py2 = 350;
			n = 1;
			bx = px1+17;
			
			ball(bx, by, b);
			cleardevice();
			setcolor(GREEN);
			playGround.paint();
			setcolor(WHITE);
			Player1.paint();
			setcolor(BROWN);
			Player2.paint();
			setcolor(BLUE);
			b.draw();
			gotoxy(35,12);
			cout << "goalll!!!!!!";
			gotoxy(20,14);
			cout << goals1;
			gotoxy(60,14);
			cout << goals2;
			
			int a = 0;
			int i = 0;
			int f = 1;
			while(i++ < 80){
				if(i < 20 || (i > 40 && i < 60)) f = 1;
				else f = 2;
				goalCelebration(px2, py2, lines_Player2, circles_Player2, a, f);
				ball(bx, by, b);
				cleardevice();
				setcolor(GREEN);
				playGround.paint();
				setcolor(WHITE);
				Player1.paint();
				setcolor(BROWN);
				Player2.paint();
				setcolor(BLUE);
				b.draw();
				gotoxy(35,12);
				cout << "goalll!!!!!!";
				gotoxy(20,14);
				cout << goals1;
				gotoxy(60,14);
				cout << goals2;
				delay(80);
			}
			while(getch()!= 13);
			px1 = 300;
			px2 = 360;
		    py1 = 350;
		    py2 = 350;
			n = 1;
			bx = px1+17;
		}
		else if(bx <= 50){ // out
			gotoxy(35,12);
			cout << "out!!!!!";
			px1 = 300;
			px2 = 360;
		    py1 = 350;
		    py2 = 350;
			if(n == 1) {
				n = 2;
				bx = px2-17;
			}
			else if(n == 2){
				n = 1;
				bx = px1+17;
			}
			while(getch()!= 13);
		}
		if(by <= 250 || by >= 450){ //out
			gotoxy(35,12);
			cout << "out!!!!!";
			px1 = 300;
			px2 = 360;
		    py1 = 350;
		    py2 = 350;
			if(n == 1) {
				n = 2;
				bx = px2-17;
			}
			else if(n == 2){
				n = 1;
				bx = px1+17;
			}
			while(getch()!= 13);
		}
	}
	
    closegraph();
    return 0;
}



/********** Point Implementation **********/
Point::Point() : x(0), y(0) {
    cout << "Default Point constructor invoked ==> " << this << endl;
}

Point::Point(int a) : x(a), y(a) {
    cout << "Parameterized Point constructor (1) invoked ==> " << this << endl;
}

Point::Point(int a, int b) : x(a), y(b) {
    //cout << "Parameterized Point constructor (2) invoked ==> " << this << endl;
}

Point::~Point() {
    //cout << "Point destructor ==> " << this << endl;
}

int Point::getX() {
    return x;
}

void Point::setX(int a) {
    x = a;
}

int Point::getY() {
    return y;
}

void Point::setY(int b) {
    y = b;
}

/********** Line Implementation **********/
Line::Line() : start(), end() {
    cout << "Default Line constructor invoked ==> " << this << endl;
}

Line::Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {
    cout << "Parameterized Line constructor invoked ==> " << this << endl;
}

Line::~Line() {
    //cout << "Line destructor invoked ==> " << this << endl;
}

void Line::setLine(int x1, int y1, int x2, int y2){
	start.setX(x1);
	start.setY(y1);
	end.setX(x2);
	end.setY(y2);
}

void Line::draw() {
    line(start.getX(), start.getY(), end.getX(), end.getY());
}

/********** Rect Implementation **********/
Rect::Rect() : tl(), br() {
    cout << "Default Rect constructor invoked ==> " << this << endl;
}

Rect::Rect(int x1, int y1, int x2, int y2) : tl(x1, y1), br(x2, y2) {
    cout << "Parameterized Rect constructor invoked ==> " << this << endl;
}

Rect::~Rect() {
    //cout << "Rect destructor invoked ==> " << this << endl;
}

void Rect::draw() {
    rectangle(tl.getX(), tl.getY(), br.getX(), br.getY());
}

/********** Circle Implementation **********/
Circle::Circle() : c(), rad(0) {
    cout << "Default Circle constructor invoked ==> " << this << endl;
}

Circle::Circle(int x, int y, int r) : c(x, y), rad(r) {
    cout << "Parameterized Circle constructor invoked ==> " << this << endl;
}

Circle::~Circle() {
    //cout << "Circle destructor invoked ==> " << this << endl;
}

void Circle::draw() {
    circle(c.getX(), c.getY(), rad);
}

/********** Picture Implementation **********/
Picture::Picture() : lNUM(0), rNUM(0), cNUM(0), pLines(NULL), pRectangles(NULL), pCircles(NULL) {
    cout << "Default Picture constructor invoked ==> " << this << endl;
}

Picture::Picture(int l, int r, int c, Line* pl, Rect* pr, Circle* pc)
    : lNUM(l), rNUM(r), cNUM(c), pLines(pl), pRectangles(pr), pCircles(pc) {
    cout << "Parameterized Picture constructor invoked ==> " << this << endl;
}

Picture::~Picture() {
    //cout << "Picture destructor invoked ==> " << this << endl;
}

void Picture::paint() {
	int i;
    for (i = 0; i < lNUM; i++) {
        pLines[i].draw();
    }
    for (i = 0; i < rNUM; i++) {
        pRectangles[i].draw();
    }
    for (i = 0; i < cNUM; i++) {
        pCircles[i].draw();
    }
}

/********************************************************/

void ball(int x, int y, Circle& b){ //set ball position
	setcolor(BLUE);
	b.c.setX(x);
	b.c.setY(y);
}

void player(int px1, int py1, Line* lines, Circle* head, int n){ //set player position
	if(n == 1)
		setcolor(WHITE);
	else setcolor(BROWN);
	lines[0].setLine(px1, py1, px1, py1+20);        // mid line
	lines[1].setLine(px1-10, py1+15, px1, py1+5);   //left hand
	lines[2].setLine(px1, py1+5, px1+10, py1+15);   //right hand
	lines[3].setLine(px1-10, py1+30, px1, py1+20);  //left leg
	lines[4].setLine(px1, py1+20, px1+10, py1+30);  //right leg
	
	head->c.setX(px1);
	head->c.setY(py1-10);
}

void goalCelebration(int &px1, int &py1, Line* lines, Circle* head, int &a, int f){
	if(f == 1){
		py1--;
		a++;
	}
	else{
		py1++;
		a--;
	}
	
	
	lines[0].setLine(px1, py1, px1, py1+20);        // mid line
	lines[1].setLine(px1-10, py1+15-a, px1, py1+5);   //left hand
	lines[2].setLine(px1, py1+5, px1+10, py1+15-a);   //right hand
	lines[3].setLine(px1-10, py1+30, px1, py1+20);  //left leg
	lines[4].setLine(px1, py1+20, px1+10, py1+30);  //right leg
	
	head->c.setX(px1);
	head->c.setY(py1-10);
}
