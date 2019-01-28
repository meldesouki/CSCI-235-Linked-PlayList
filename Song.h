/***********
Name: Merna Eldesouki
Assignment: CSCI 235, Fall 2018, Project 2
Date: September 25,2018
Description: This file creates a class Song. It stores details of a song such as title, artist, and album
***********/

#ifndef SONG_H 
#define SONG_H

#include <string>

class Song {

public:

	Song(); //default constructor

	Song(const std::string& title, const std::string& author = "", const std::string& album = ""); //parameterized constructor

	/* Sets the title of a song
	@post The song now has a title
	@param title The song's title */
	void setTitle(std::string title); 

	/* Sets the author of a song
	@post The song now has an author
	@param author The author of a song */
	void setAuthor(std::string author);

	/* Sets the album name of a song
	@post The song now has an album name
	@param album The album the song belongs to */
	void setAlbum(std::string album);

	/* Gets the current song's title
	@return Current song's title */
	std::string getTitle() const;

	/*Get the current song's author
	@return Current song's author */
	std::string getAuthor() const;

	/* Gets the current song's album name
	@return Current song's album name */
	std::string getAlbum() const;

	/* Compares two songs to see if they are the same song
	@param lhs The first song that will be compared
		rhs The second song which will be compared to the first song
	@return True if the two songs are in fact the same song */
	friend bool operator==(const Song& lhs, const Song& rhs);

private:

	std::string title_; //current song title

	std::string author_; //current song author

	std::string album_;	//current song album name
};

#endif /* SONG_H_ */