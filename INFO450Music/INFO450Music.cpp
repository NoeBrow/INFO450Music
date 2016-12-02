// INFO450Music.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class node
{
public:	
	char artist[50];//same as int data
	char song[50];//same as int data
	node *next;
	node(char a[50], char s[50]);
	friend class PLayList;

};
node::node(char a[50], char s[50])
{
	artist[50] = a[50];
	song[50] = s[50];

	next = NULL;
}

class PlayList
{
	node *head;
	node *tail;
public:
	PlayList();
	void playSong(); 
    int deleteSong(char i); 
	void skipSong();
	void display();//same as show list
};
PlayList::PlayList()
{
	head = NULL;
	tail = NULL;
}
void PlayList::display()
{
	char userinput;
	cout << "Welcome to your NoelleP3" << endl;
	while (userinput != 'D' || userinput != 'd')
	{
		cout << "If you want to play your song input P" << endl;
		cout << "If you need to skip the song playing press S" << endl;
		cout << "If you want to delete your song press D" << endl;
		cout << "If you want to exit press Q" << endl;
		cin >> userinput;
		
		if (userinput == 'P' || userinput == 'p')
		{
			playSong();
		}
		else if (userinput == 'S' || userinput == 's')
		{
			skipSong();
		}
		else if (userinput == 'D' || userinput == 'd')
		{
			deleteSong();
		}
		else if (userinput == 'Q' || userinput == 'q')
		{
			cout << "thanks for listening" << endl;
			break;
		}
	}

}
void PlayList::playSong()
{
	node *ptr;
	ptr = head;
	if (ptr == NULL)
	{
		cout << "You have no songs" << endl;
		return;
	}
	cout << "The artist is" << ptr->artist[50] << "Title is" << head->song[50] << endl;
	ptr = ptr->next;
	display();
}

void PlayList::skipSong()
{//similar to insert after
	node *ptr;
	
	while (ptr != NULL)
	{
		{
			
			if (tail == ptr->next)
			{tail = ptr; }
			node *skip = ptr->next;
			ptr->next = (ptr->next)->next;
		}
		ptr = ptr->next;
	}
	// if skip user can enter a number n and the song will skip n amount of songs
	display();
}

int PlayList::deleteSong(char i)
{
	char i;
	node *ptr = head;
	if (ptr == NULL)
	{
		cout << "list is empty" << endl;
	}
	if (head->song == "i")
	{
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
			head = head->next;
		delete ptr;
		return 0;
	}
	while (ptr != NULL)
	{
		if (ptr->next && (ptr->next)->song == "i")
		{
			if (tail == ptr->next)
			{
				tail = ptr;
			}
			node *tbd = ptr->next;
			ptr->next = (ptr->next)->next;
			delete tbd;
			return 0;
		}
		ptr = ptr->next;
	}
	display();
}

int main()
{
	char file[100];

	cout << "Please enter your full file name path" << endl;
	ifstream filename(file);
	gets_s(file);
	while (!filename.eof())
	{
		node *ptr;
		char artist[50];
		char song[50];
		filename.getline(artist,50, ',');
		filename.getline(song, 50 );
		ptr = new node(artist, song);
	}
	PlayList *mylist = new PlayList();
	mylist->display();
    return 0;
}

