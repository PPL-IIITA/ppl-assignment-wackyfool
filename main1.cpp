#include <iostream>
#include <fstream>
#include <string>
#include "boys.cpp"
#include "girls.cpp"

using namespace std;


int main ()
{
	boys b[30];
	girls g[30];
	fstream fb;
	fstream fg,fo,l;
	fb.open("boys.txt");
	fg.open("girls.txt");
	fo.open("final.txt",ios::out);
	l.open("log.txt",ios::out);
	string b1,b2,b3;
	int b4,b5,b6;

	string g1,g2,g3;
	int g4,g5,g6;
	
	int x=0;
	while(!fg.eof())
	{
		fg>>g1>>g2>>g3>>g4>>g5>>g6;
		if(fg.eof())
			break;
		g[x].girls1(g1,g2,g3,g4,g5,g6);
		x++;
	}	
	int y=0;
	while(!fb.eof())
	{
		fb >>b1>>b2>>b3>>b4>>b5>>b6;
		if(fb.eof())
			break;
		b[y].boys1(b1,b2,b3,b4,b5,b6);
		y++;
	}
	
	for(int i=0;i<x;i++)
	{
		l<<"Checking status of "<<g[i].name<<endl;
		if(g[i].status=="committed")
			l<<g[i].name<<" is already committed"<<endl;
		if(g[i].status=="single")
		for(int j=0; j<y;j++)
		{
			l<<"Checking "<<g[i].name<<" with "<<b[i].name<<endl;
			if(b[j].status=="committed")
				continue;
			if(g[i].budget <= b[j].budget)
			{	
				l<<g[i].name<<" is now in a relationship with "<<b[i].name<<endl;
				g[i].status="committed";
				b[j].status="committed";
				fo<<g[i].name<<" is in a relationship with "<<b[j].name<<endl;
				break;
			}
			if(g[i].status=="single")
				l<<g[i].name<<" is still single. Tough Luck! "<<endl;
		}
	}	

	fb.close();
	fg.close();
	fo.close();
	l.close();
	return 0;
}
