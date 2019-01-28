/*************
Name: Merna Eldesouki
Assignment: CSCI 235, Fall 2018, Project 3
Date: October 17,2018
Description: This file creates a Playlist class where the playlist is a linked chain. It inherits from LinkedSet.
***********/


#include "PlayList.h"
#include <iostream>

PlayList::PlayList() : tail_ptr_(nullptr){} //default constructor

PlayList::PlayList(const Song& a_song){ //parameterized constructor

	tail_ptr_ = nullptr;
	add(a_song);

}
PlayList::PlayList(const PlayList& a_play_list):LinkedSet(a_play_list){ //copy constructor

	if(!isEmpty()){	
		
		//sets the tail ptr to the correct node in the copied class
		tail_ptr_ = getPointerToLastNode();  
	}
	else { 

		tail_ptr_ = nullptr;
	}
}

PlayList :: ~PlayList(){ //destructor
	
	unloop();
	delete tail_ptr_;
	tail_ptr_ = nullptr;
	clear();
}

//Precondition: The song to be added is not already part of the playlist
//Postcondition: The song is added
//Return: true if add is successful and false if not
bool PlayList :: add(const Song& new_song) {

	if(!contains(new_song)){

		Node<Song>* next_node_ptr = new Node<Song>();
		next_node_ptr -> setItem(new_song);
		
		if (head_ptr_ == nullptr){ //if the chain is empty then tail and head would point to the same node

       		head_ptr_ = next_node_ptr;
			tail_ptr_= next_node_ptr;		
       	}

       else{
		
			tail_ptr_->setNext(next_node_ptr); //connects node to chain
			tail_ptr_= next_node_ptr;
       }
       
       //tail_ptr_= next_node_ptr;
       
       item_count_++;
       return true;
    }
    
    else{
    	return false;
    }
} //end add

//Precondition: Playlist is not empty and the song to be deleted is part of the chain
//Postcondition: Song is removed without ruining order
//Return true is successful, false if not
bool PlayList :: remove(const Song& a_song) {
	
	Node<Song>* previous_ptr = nullptr;
	Node<Song>* target_ptr = getPointerTo(a_song, previous_ptr);
	bool can_be_removed = ((!isEmpty()) && (target_ptr != nullptr));

	if (can_be_removed){

		if (target_ptr == head_ptr_){

			LinkedSet :: remove(a_song); //if its the first song then don't worry about tail ptr
		}

		else {

			target_ptr -> setItem(previous_ptr->getItem()); //Move the items in the chain to preserve order

			if (target_ptr != tail_ptr_){ //meaning the middle of the chain

				//Delete node
				Node<Song>* ptr_to_delete = target_ptr;
				target_ptr = target_ptr -> getNext();
				previous_ptr-> setNext(target_ptr); //setting the previous ptr to point to the next node

				//Deallocationg memory
				ptr_to_delete ->setNext(nullptr);
				delete ptr_to_delete;
				ptr_to_delete = nullptr;
			}

			else{ //Last song

				target_ptr-> setItem(previous_ptr->getItem());

				//Deallocationg memory
				previous_ptr -> setNext(nullptr);
				delete target_ptr;
				target_ptr = nullptr;
			}
			item_count_--;
		}
	}
	return can_be_removed;
} //end remove

//Precondition: There is at least one node in the chain
//Postcondition: Playlist is displayed
void PlayList::displayPlayList(){

	for (int i = 0; i < getCurrentSize(); i++){

		std::cout << "* Title: " << toVector()[i].getTitle() << " * " 
		<< "Author: " << toVector()[i].getAuthor() << " * "
		<< "Album: " <<  toVector()[i].getAlbum() <<" *" << std::endl;
	}

	std::cout << "End of playlist" << std::endl;
} //end displayPlaylist


//Puts the playlist in a loop
void PlayList :: loop(){

	tail_ptr_ = head_ptr_;
} //end loop

//Stops the loop
void PlayList :: unloop(){

	tail_ptr_ = getPointerToLastNode();
} //end unloop
		
//Precondition: The playlist is not empty and the song is in the chain
//Postcondition: Pointer to the desired node is retrieved
//Return: target_ptr Pointer to the node the program is looking for
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const{

	Node<Song>* target_ptr = LinkedSet :: getPointerTo(target);
	
	//Must be more than one node or else previous ptr can't point to anything (since there would be no nodes before the first one)
	if ((item_count_ > 1) && (target_ptr!= nullptr)){ //Meaning there is more than one node and the node we want is in the chain

		previous_ptr = head_ptr_; //That way it would start from the beginning (setting up for iteration)
		Node<Song>* ptr_of_next = previous_ptr; //Looks ahead to see if we're at the ptr of the node right before target
		bool found = false;
		while (ptr_of_next != target_ptr && !found){
			
			ptr_of_next = ptr_of_next ->getNext(); //move to next node
			
			if (ptr_of_next == target_ptr){
				found = true;
			}

			else{
				previous_ptr = previous_ptr->getNext();
			}	
		}
	}

	return target_ptr;
} //end getPointerTo

//Precondition: There is at least one node in the chain
//Postcondition: Pointer to the last node is retrieved
//Return: ptr_to_last Pointer to the last node in the chain
Node<Song>* PlayList :: getPointerToLastNode() const {

	Node<Song>* ptr_to_last = head_ptr_;
	Node<Song>* look_ahead = ptr_to_last;
	
	if (!isEmpty()){

		for (int i = 0; i < item_count_; i++){

			look_ahead = look_ahead -> getNext();
		
			if(look_ahead == nullptr){

				break;
			}
		
			else{
			
				ptr_to_last = ptr_to_last->getNext(); 
			}	
		}
	}
	return ptr_to_last;
} //end getPointerToLastNode

//end Playlist.cpp