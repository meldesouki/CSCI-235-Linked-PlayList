/***********
Name: Merna Eldesouki
Assignment: CSCI 235, Fall 2018, Project 2
Date: September 25,2018
Description: This file creates a class Song. It stores details of a song such as title, artist, and album
***********/

#include "Song.h"

Song::Song(){} //default constructor

Song::Song(const std::string& title, const std::string& author, const std::string& album){ //parameterized constructor

	title_ = title;
	author_ = author;
	album_ = album;
}

//Setter functions
void Song::setTitle(std::string title){

	title_ = title;
}

void Song::setAuthor(std::string author){

	author_ = author;
}

void Song::setAlbum(std::string album){
	
	album_ = album;
}

//Accessor functions
std::string Song::getTitle() const{

	return title_;
}

std::string Song::getAuthor() const{

	return author_;
}

std::string Song::getAlbum() const{

	return album_;
}

//Overloaded operator which checks if one song is a duplicate of another
bool operator==(const Song& lhs, const Song& rhs){

	return ((lhs.getTitle() == rhs.getTitle()) && (lhs.getAuthor() == rhs.getAuthor()) && (lhs.getAlbum() == rhs.getAlbum()));
}
/* SONG_H_ */			