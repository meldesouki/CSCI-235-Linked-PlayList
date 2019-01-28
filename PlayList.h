/*************
Name: Merna Eldesouki
Assignment: CSCI 235, Fall 2018, Project 3
Date: October 17,2018
Description: This file creates a Playlist class where the playlist is a linked chain. It inherits from LinkedSet.
***********/


#ifndef PLAYLIST_
#define PLAYLIST_

#include "Song.h"
#include "Node.h"
#include "LinkedSet.h"

class PlayList : public LinkedSet<Song>{

public:

	PlayList(); //default constructor
	PlayList(const Song& a_song); //parameterized constructor
	PlayList(const PlayList& a_play_list); // copy constructor
	~PlayList(); // Destructor
	
	/** Adds a song to the playlist
	@pre The song is not already a part of the playlist
	@param new_song The song that would be added
	@post The song would be added to the playlist*/
	bool add(const Song& new_song) override;
	
	/** Removes a song from the playlist
	@param a_song The song that would be removed
	@post The song would be removed to the playlist*/
	bool remove(const Song& a_song) override;
	
	/** Displays all of the songs currently in the playlist
	@post All the songs in the playlist should be printed on screen*/
	void displayPlayList();
	
	/** Puts the playlist into a loop **/
	void loop();    
    
    /**Stops the loop **/
    void unloop();

private:

	// private data member
	Node<Song>* tail_ptr_; // Pointer to last node
	
	//private member functions
	Node<Song>* getPointerToLastNode() const; //Returns a pointer to the last node in the chain
	Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const; //Returns a pointer to the desired node
};
#endif
/*PLAYLIST_H*/