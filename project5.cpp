//Project 5
//Six functions relating to ciphers
//first function clean_string gets rid of all non alphabetical characters in a string
//second function create_encoding takes a string and encodes it with every letter except q, no repeating letters
//third function encode_digraph takes a two letter key and two encoded strings, returns the encoding of the two letter key
//fourth function decode_digraph takes a two letter key and two encoded strings and decodes the two letter key
//fifth function encode takes a message and two encoded strings. Separates the message into two characters each and calls encode digraph and returns the encoded message
//sixth function decode takes a message and two encoded strings. Separates message into two chracter groups and calls decode and returns the decoded message

#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include "proj05_functions.h"

string clean_string(string s){
   string new_string = ""; //initalize empty string
    for(int i = 0; i < s.size(); i++){ //go through each letter in string and chck if its alphabetical
        if (isalpha(s[i])){
        new_string.push_back(tolower(s[i])); //add to empty string
        
        }
    
    } 
    return new_string;
} 


string create_encoding(string key){
    string const alp = "abcdefghijklmnoprstuvwxyz"; // init const
    string no = "q"; //used to cut q out of the key
    while (key.size() < 25){ //while there are less than 25 characters
        for(int i= 0; i <= alp.size()-1; i++){ //go through and add alphabetical characters to key
            key.push_back(alp[i]);
           
        }
        for ( std::string::size_type i = 0; i < key.size(); i++ ){ // check for duplicates or q and erase them
            if (key[i] == no[0]){
                key.erase(i,1);
            }
        std::string::size_type j = i + 1;
        while ( j < key.size() ){
            if ( key[i] == key[j] ){
                key.erase( j, 1 );
            }
            else{
                ++j;
            }
        }
        
    }
    }
    
  
    return key;
}

string encode_digraph(string dg, string block1, string block2){
    //initialize variables to find position of each letter
    int row;
    int row1;
    int row2;
    int row3;
    int col;
    int col1;
    int col2;
    int col3;
    string letter;
    string letter2;
    string const alp = "abcdefghijklmnoprstuvwxyz"; //init constant
    for(int i = 0; i<= alp.size()-1;i++){ //go through each i in alp to check if it is equal to the first letter of dg
        
        if (dg[0] == alp[i]){ //if it is equal get the row and col values for that letter
            
            row1 = i/5;
            col1 = i % 5;
            
        }
    }
    for(int i1 = 0; i1<= alp.size()-1;i1++){ //repeat process for second letter in dg
        if (dg[1] == alp[i1]){
            row2 = i1/5;
            col2 = i1 % 5;
            
            
        }
    }
    for(int i2= 0; i2<= block1.size()-1;i2++){ //find the letters that corespond with the row and col in block1 
        row = i2/5;
        col = i2 % 5;
        if (row == row1 and col2 == col){
            letter = block1[i2];
        }
    }
    for(int i3= 0; i3<= block2.size()-1;i3++){ //find the letter that corresponds with the row and col in block 2
        row3 = i3/5;
        col3 = i3 % 5;
        if (row2 == row3 and col3 == col1){
            letter2 = block2[i3];
        }
       
    }
    
    
    return letter + letter2; //returns the concantanted letters

}

string decode_digraph(string dg, string block1, string block2){
    string const alp = "abcdefghijklmnoprstuvwxyz"; //init constant
    //initialize variables for row col values for each letter
    int row;
    int col;
    int row1;
    int col1;
    string ch1;
    string ch2; 
    int index;
    int index1;
    for (int i=0; i<= block1.size()-1; i++){ //find the row col value that corresponds with the first letter of dg in block1
        if(dg[0] == block1[i]){
            row = i/5;
            col = i % 5;
        }
    }
    for (int i1=0; i1<= block2.size()-1;i1++){ //find the row col value that corresponds with the second letter of dg in block2
        if(dg[1] == block2[i1]){
            row1 = i1/5;
            col1 = i1 % 5;
        }
    }
    for(int i2 =0;i2<= alp.size()-1; i2++){ //find the index by using the opposite row and column
        index = row * 5 + col1;
        index1 = row1 * 5 +col;
        if(index == i2){ //find the index corresponding the the index in the alphabet
            ch1 = alp[i2];
        }
        if(index1 == i2){ 
            ch2 = alp[i2];
        }
    }
    return ch1 + ch2;
}

string encode(string msg, string key1, string key2){ 
    string final = "";  //initialize empty string
    string word;
    string word1;
    string checkedmsg;
    string encodedword;
    string keyword;
    checkedmsg = clean_string(msg); //clean the msg
    if(checkedmsg.size()-1 % 2 == 0){ //if it has an odd number of characters add x to the end
        checkedmsg = checkedmsg + 'x';
    }
    for(int i = 0; i<= checkedmsg.size()-1; i= i+2){ //separate every two letters 
        int i2 = i +1;
        word1 = checkedmsg[i];
        word = checkedmsg[i2]; 
        keyword = word1 + word ;
        key1 = create_encoding(key1); 
        key2 = create_encoding(key2);
        encodedword = encode_digraph(keyword, key1, key2); //encode every two
        final = final + encodedword; //add to final string
    }
    
    return final;
    
}

string decode(string msg, string key1, string key2){ 
    string final = ""; //initialize empty string
    string word;
    string word1;
    string checkedmsg;
    string decodedword;
    string keyword;
    checkedmsg = clean_string(msg); //clean the string
    if(checkedmsg.size()-1 % 2 == 0){ //if there is an odd number of characters add an x to the end
        checkedmsg = checkedmsg + 'x';
    }
    for(int i = 0; i<= checkedmsg.size()-1; i= i+2){ //separate into groups of two and call decode_digraph function
        int i2 = i +1;
        word1 = checkedmsg[i];
        word = checkedmsg[i2]; 
        keyword = word1 + word ;
        key1 = create_encoding(key1);
        key2 = create_encoding(key2);
        decodedword = decode_digraph(keyword, key1, key2);
        final = final + decodedword; //add to the final string
    }
    
    return final;
}

