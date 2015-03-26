 /*
 * Group Members: Shawn Fong, Kevin Leung, Jigar Bhalodia
 * Discrete Computer Project 1
 * Due: March 26th, 2015
 */
 
 
 #include <iostream>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <fstream>
 #include <sstream>
 #include <fstream>
 #include <queue>
 #include <deque>

 using namespace std;
 
 
 /*Linear Search and Replacement of Names*/
 void nameChange(vector<string> &letter, string targetFirst, string replaceFirst, string targetLast, string replaceLast){
 	vector<string> newLetter;
 	string targetFirstComma = targetFirst+",";
 	string replaceFirstComma = replaceFirst+",";
 	string targetFirstApos = targetFirst+"’s"; //LOL why is it ’ ... what key is that??? 
 	string replaceFirstApos = replaceFirst+"’s";
 	int professorCheck = 0;
 	/*Parse Through the letter*/
 	for(int x = 0; x < letter.size(); x++){ //loops through each line of the letter 
 		string temp = letter[x];
 		string subtemp;
 		string subPrevious;
 		string subPhrase = "";
 		istringstream iss(temp);
 		/*Runs through each word of each line*/
 		do{
 			iss >> subtemp;
 			/*Error Handling for Professor's Name*/
 			if(subtemp == "Sincerely,"){ 
 				professorCheck = 1;
 			}
 			/*Replacement of First Name*/
 			if(subtemp == targetFirst || subtemp == targetFirstComma){
 				/*Avoid replacing Professors First name*/
 				if(subtemp != "Kevin" && subtemp != targetFirstComma){
 					subtemp = replaceFirst;
 				}
 				/*replace when the name comes before a comma*/
 				if(subtemp == targetFirstComma){
 					subtemp = replaceFirstComma;
 				}
 				/*Replaces a Kevin incase the student shares the same name as the professor*/
 				if(subtemp == "Kevin" && professorCheck == 0){
 					subtemp = replaceFirst;
 				}
 			/*replaces a students last name if they share the same last name as the professor without changing the professors name*/	
 			}else if(subtemp == targetLast && professorCheck == 0){
 				subtemp = replaceLast;
 			/*replaces if a "’s" comes after the name*/	
 			}else if(subtemp == targetFirstApos){
 				subtemp = replaceFirstApos;
 			}
 			/*Fixes an error of repeating*/
 			if(subtemp != subPrevious){
 				subPhrase = subPhrase + " " + subtemp;
			}
 			subPrevious = subtemp;
 		}while(iss);
		newLetter.push_back(subPhrase); 		
 	}
 	letter = newLetter;
 }
 
 void wordChange(vector<string> &letter, string targetWord, string replaceWord){
 	vector<string> newLetter;
 	string targetWordComma = targetWord+",";
 	string replaceWordComma = replaceWord+",";
 	string targetWordPeriod = targetWord+".";
 	string replaceWordPeriod = replaceWord+".";
 	
 	for(int x= 0; x<letter.size(); x++){
	 	string temp = letter[x];
	 	string subtemp;
	 	string subPrevious;
	 	string subPhrase = "";
	 	
	 	
 		istringstream iss(temp);
 			/*Runs through each word of each line*/
 			do{
 				iss >> subtemp;
 				if(subtemp == targetWord){
 					subtemp = replaceWord;
 				}
 				/*If target word is before a comma*/
 				if(subtemp == targetWordComma){
 					subtemp = replaceWordComma;
 				}
 				/*If target word is before a period (end of sentence)*/
 				if(subtemp == targetWordPeriod){
 					subtemp = replaceWordPeriod;
 				}
 				/*Error Handling for duplicate*/
 				if(subtemp != subPrevious){
 				subPhrase = subPhrase + " " + subtemp;
				}
 				subPrevious = subtemp;
 			}while(iss);
 			newLetter.push_back(subPhrase);				
 	}
 	letter = newLetter;		
 }
 
 
void phraseChange(vector<string> &letter, string targetPhrase, string replacePhrase){
 	vector<string> newLetter;
 	bool candidate;
 	int hitCounter;
 	int phraseMatches;
 	string line;
 	string replaceLine;
 	string before;
 	string remaining;
 	int start;
 	int finish;
 	int index;
 	
 	hitCounter = 0;
 	phraseMatches = 0;

 	for(int k = 0; k < letter.size(); k++) {	//loop through the lines within the vector
 		line = letter[k];		//set variable line to be a string of the line entry

	 	for(int i = 0; i < line.length(); i++){		//interate through the string, or current line
	 		if(line[i] == targetPhrase[0]) {		//compare the character to the first letter in the target
	 			candidate = true;					//first character matches --> candidate
	 			hitCounter++;						//increment hit counter if match

	 			for (int j = 1; j < targetPhrase.length(); j++) {	//if camdidate, check remaining characters
	 				index = i + j;
	 				if (line[index] == targetPhrase[j]) {		
	 					candidate = true;		
	 					hitCounter++;		//increment hit counter
	 					if (hitCounter == targetPhrase.length()) {		//check if hit counter has reached target phrase length
	 						hitCounter = 0;		//reset hit counter
	 						phraseMatches++;	//increment phrase match

	 						// Target Phrase Identified! -- Replace with Replacement Phrase!
	 						start = i + targetPhrase.length(); // index after target phrase
	 						finish = line.length();				// index of end of line
	 						if(i == 0) {	//phrase is at the beginning of a line
	 							replaceLine = replacePhrase + line.substr(start, finish);
	 						} else {		//phrase is in the middle of a line
	 							replaceLine = line.substr(0, i-1) + " " + replacePhrase + line.substr(start, finish);
	 						}

	 						letter[k] = replaceLine;	//replace line within original letter.
	 						// Replacement complete

	 						candidate = false;
	 						break;		//break from loop, check remaining text file
	 					} else {}
	 				} else {		//if no match, break from candidate and check remaining string
	 					candidate = false;
	 					hitCounter = 0;
	 					break;
	 				}
	 			}

	 		} else {
	 			candidate = false;
	 		}
		} 
	}
	cout <<endl;
	cout << "Phrase matches found and replaced: " << phraseMatches;
 }
 
 
 /*Gets each word from the Adjective List and places it into a vector then sends one back randomly*/  
 string getWord(){
 	/*Gets SystemTime and creates Srand function*/
	time_t t;
	time(&t);
	srand((unsigned int) t);
 	
 	/*Parses through text file of single word Adjectives*/
 	string temp;
 	vector<string> adjList;
 	ifstream Adjfile;
 	Adjfile.open("AdjectiveList2.txt");
 	while(!Adjfile.eof()){
 		Adjfile >> temp;
 		adjList.push_back(temp);
 	}
 	Adjfile.close();
 	
 	/*Random Number*/
 	int totalAdj = adjList.size()-1;
 	int RandomNum = rand() % totalAdj;
 	
 	/*Returns a random cell of a vector containing all the Adjectives*/
 	return adjList[RandomNum];
 }
 
 
 /*Gets each phrase from the Adjective List and places it into a vector then sends one back randomly */ 
 string getPhrase(){
	/*Gets SystemTime and creates Srand function*/
	time_t t;
	time(&t);
	srand((unsigned int) t);
	
	vector<string> phrase;
 	ifstream phraseFile;
 	phraseFile.open("AdjectiveList1.txt");
 	string line;
 	while(getline(phraseFile, line)){
 		phrase.push_back(line);
 	}
 	phraseFile.close();
 	
 	/*Random Number*/
 	int totalAdj = phrase.size()-1;
 	int randNum = rand() % totalAdj;
 	
 	return phrase[randNum];
 }
 
 string file_name; //Set as a Global Variable
 /*Gets text file in a vector line by line*/
 vector<string> getTextLine(){
 	vector<string> letter;
 	cout<<"Please input the text file you want to read: "<<endl;
 	cin >> file_name;
 	ifstream file;
 	string line;
 	file.open(file_name.c_str());
 	while(getline(file,line)){
 		letter.push_back(line);
 		cout<<line<<endl;
 	}
 	cout<<endl;
 	file.close();
 	
 	return letter;
 }
 
 //Create a textfile vector. Reads a char at a time and pushes it into vector. The vector will be referenced.
//Parameter: textfile_char vector to push chars from textfile into.
//           file_name string passed in from the user.
void read_textfile_by_char(vector<char> &textfile_char, string file_name){

  //create a fstream operator
  std::fstream textfile;
  //open the file with file_name
  textfile.open( file_name.c_str() );

  //char from textfile will be read into chararc
  char charac;
  while(textfile.get(charac))
  {
    textfile_char.push_back(charac);
  }
  //test
  cout<<textfile_char.size()<<"\n";
}
                        
void create_character_queue(queue<char> &decode_phrase, queue<int> &binary){
//read the binary queue and convert the binary into integers and then integers into charactes using ascii table
	int bsize = binary.size();
	//test
	cout<<binary.size()<<"\n";
	int bit_count = 0;
	int integer = 0;
	for(int i = 0; i < bsize; i++){
		bit_count++;
		int f = binary.front();
		binary.pop();
		
		if(bit_count==1 && f == 1){
			integer+=16;
		}	
		else if(bit_count==2 && f == 1){
			integer+=8;
		}	
		else if(bit_count==3 && f == 1){
			integer+=4;
		}	
		else if(bit_count==4 && f == 1){
			integer+=2;
		}	
		else if(bit_count==5 && f == 1){
			integer+=1;
		}	
		
		if(bit_count == 5){
			integer+=97;
			//convert space to ascii value
			if(integer == 123){
				integer = 32;
			}
			char a = char(integer);
			decode_phrase.push(a);
			bit_count=0;
			integer=0;	
		}
	}





}


//prints out the decoded message
void decode() {

// Create the textfile vector from the user given filename	
	//Declare the textfile vector to be used to push the textfile chars.
	std::vector<char> textfile_char;

	//declare string for the file_name to be received from user.
	string file_name;

	//ask user for the name of textfile
	cout<<"Please enter the name if textfile containing the letter:"<<"\n";
	//synchronize the buffer.
	cin.sync();
	//get the name of textfile from user's command line
	getline(std::cin, file_name);

	//Create textfile vector using read_textfile_by_char() function.
	read_textfile_by_char(textfile_char, file_name);
	
	queue<int> binary;
	vector<char>::iterator it;
	int space_counter = 0;
	
//read the textfile_char vector and determine the binary code from spaces.
	for(it = textfile_char.begin(); it != textfile_char.end(); it++){
		//when 3 spaces detected, break;
		if(*it == ' ' && *(it+1) == ' ' && *(it+2) == ' '){
			break; 	
		}
		//when 2 spaces detected, input 1 into the binary queue
		else if(*it == ' ' && *(it+1) == ' '){
			binary.push(1);
			it++;
		}
		//when 1 space detected, input 0 into the binary queue
		else if(*it == ' '){
			binary.push(0);
		}
	}
	
	//test
	int binary_size = binary.size();

//Conver the binary queue into characters using integers;
	//declare queue into which the the encoding phrase will be inputted.
	queue<char> decode_phrase;
	create_character_queue(decode_phrase, binary);
	
//print the decode_phrase
//test
	int b_size = decode_phrase.size();
	for(int s = 0; s < b_size; s++){
		cout<<decode_phrase.front();
		decode_phrase.pop();
	}
}

 
 void create_binary_queue(string encode_phrase, queue<int> &binary){
  int integer;
  for(int i = 0; i < encode_phrase.size(); i++){
    //Convert each character to integer using ascii table
    integer = encode_phrase[i] - '0';

    //Convert everything between range of 0 to 31 so they can be represented within 5 bit binary values.
    //If the integer is between 49 and 75 convert the integer value from 0 to 25
    if(integer > 48 && integer < 75){
      //a = 49 
      integer-=49; 
    }
    //A-Z range from 17 to 42
    else if(integer > 16 && integer < 43){ 
      //A = 17
      integer-=17;
    }
    //-16 is space 
    else if(integer == -16){
      integer=26;
    }
    else {
      cout<<"Inputted invalid character space. Please input anything between a to a, A to Z, and <space> ranges."<<"\n";
    }
   
    //Convert the integer into a binary
    if(integer >= 16){
      binary.push(1);
      integer-=16;
    }
    else { 
      binary.push(0);
    }   
    if(integer >= 8){
      binary.push(1);
      integer-=8;
    } 
    else {
      binary.push(0);
    } 
    if(integer >= 4){
      binary.push(1);
      integer-=4;
    }
    else {
      binary.push(0);
    }
    if(integer >= 2){
      binary.push(1);
      integer-=2;
    } 
    else {
      binary.push(0);
    }
    if(integer == 1){
      binary.push(1);
    }
    else {
     binary.push(0);
    }
  }
  cout<<binary.size()<<"\n";
}


void encode(){
  
  //Declare the textfile vector to be used to push the textfile chars.
  std::vector<char> textfile_char;  
  
  //declare string for the file_name to be received from user.
  string file_name;
 
 //ask user for the name of textfile 
  cout<<"Please enter the name if textfile containing the letter:"<<"\n";
  //synchronize the buffer. 
  cin.sync();
  //get the name of textfile from user's command line
  getline(std::cin, file_name);

  //Create textfile vector using read_textfile_by_char() function.
  read_textfile_by_char(textfile_char, file_name);

// read the phrase to be encoded
 
  //declare string into which the the encoding phrase will be inputted. 
  string encode_phrase;

  //Prompt the user to enter the phrase 
  cout<<"Please enter the phrase to be encoded here:"<<"\n";
  //synchronize the buffer.
  cin.sync();
  //get the phrase into the phrase string
  getline(std::cin, encode_phrase);
  
// convert the phrase to 5bit binary

  //create an int queue for binarys
  queue<int> binary;

  //call this function to create binary of the phrase string
  create_binary_queue(encode_phrase, binary);

//Insert spaces into the textfile
  //need an interator to interate through the vector
  vector<char>::iterator it;
  //counter to count how many spaces encountered
  int space_counter = 0;
  int binary_size=binary.size();
    for(it = textfile_char.begin(); it != textfile_char.end(); it++){
      if(*it == ' '){
        space_counter++;
        int y = binary.front();
        binary.pop();
        if( y == 1){
          int forward = distance(textfile_char.begin(), it);
          textfile_char.insert(textfile_char.begin()+forward, ' ');
          it++;
        }
        if( space_counter > binary_size ){
          int forward = distance(textfile_char.begin(), it);
	  textfile_char.insert(textfile_char.begin()+forward, ' ');
	  textfile_char.insert(textfile_char.begin()+forward, ' ');
          break;
        }
      }  
    }
    
  
  //Print the textfile_char
  for(int r = 0; r <= textfile_char.size(); r++){
     cout<<textfile_char[r];
  }

 //////if prompted by user save the textfile_char into a file
  ofstream fout;
  string outfile;
  cout<<"Please enter the output file name: ";
  cin.sync();
  getline(cin, outfile);

  fout.open( outfile.c_str() );
  for(int o = 0; o < textfile_char.size(); o++){
    fout << textfile_char[o];	
  } 

  fout.close();

}
 
 
 
 
 void saveFile(vector<string> &letter){
 	/*Clears original file*/
 	ofstream ofs;
 	ofs.open(file_name.c_str(), ofstream::out | ofstream::trunc);
 	ofs.close();
 	
 	ofstream saveFile;
 	saveFile.open(file_name.c_str());
 	for(int x=0; x < letter.size(); x++){
 		saveFile << letter[x]+"\n";
 	}
 	saveFile.close();
 }
 
 /*Main Code to run System*/
 int main(int argc, char** argv){
 	
 vector<string> letter = getTextLine();
 	
 	
while(true){
 	


 	int nameReplace = 0;
 	int wordReplace = 0;
 	int phraseReplace = 0;
 	int hiddenMessage = 0;
 	string choice;
 	


 	/*Choice of Action*/
 	while(true){
		 	cout<<"Please choose what you want to replace or do: name, adjective, phrase, hidden"<<endl;
		 	cin >> choice;
		 	if(choice == "name"){
		 		nameReplace = 1;
		 		break;
		 	}else if(choice == "adjective"){
		 		wordReplace = 1;
		 		break;
		 	}else if(choice == "phrase"){
		 		phraseReplace = 1;
		 		break;
		 	}else if(choice == "hidden"){
		 		hiddenMessage = 1;
		 		break;
		 	}else{
		 		cout<<"That is not the correct choice, Try again"<<endl;
		 	}
	 	}
	 	

	 	
	 	/*Name Replacement*/
	 	if(nameReplace!=0){
		 	
		 	string targetFirst;
		 	string targetLast;
		 	string replaceFirst;
		 	string replaceLast;
		 	
		 	cout<<"Please input the FIRST name you want to replace"<<endl;
		 	cin >> targetFirst;
		 	cout<<"Please input the LAST name you want to replace"<<endl;
		 	cin >> targetLast;
		 	cout<<"Please input the new First name"<<endl;
		 	cin >> replaceFirst;
		 	cout<<"Please input the new Last name"<<endl;
		 	cin >> replaceLast;
		 	nameChange(letter, targetFirst, replaceFirst, targetLast, replaceLast);
	
			/*New List*/
			for(int i = 0; i < letter.size(); i++){
			getPhrase();	cout<<letter[i]<<endl;
			} 
		 	cout<<endl;
	 	}
	 	
	 	
	 	
	 	/*Adjective Replacement*/
	 	if(wordReplace != 0){
	 		string targetWord;
	 		string replaceWord = getWord();
	 		cout<<"Please input the word you want to replace"<<endl;
	 		cin >> targetWord;
	 		cout<<"The replacement word is "<<replaceWord<<endl;
	 		wordChange(letter, targetWord, replaceWord);
	 		
	 		/*Print Out New Letter*/
	 		for(int i = 0; i < letter.size(); i++){
				cout<<letter[i]<<endl;
			} 
		 	cout<<endl;
	 	}
	 	
	 	
	 	
	 	/*Phrase Replacement*/
	 	if(phraseReplace != 0){
	 		string targetPhrase;
	 		string replacePhrase;
	 		cout<<"Please input the Phrase you want to replace."<<endl;
	 		cin.ignore(); //ignores spaces
	 		getline(cin, targetPhrase); //gets target phrase to replace
	 		replacePhrase = getPhrase();
	 		cout<<"The replacement Phrase is: "<<replacePhrase<<endl;
			phraseChange(letter, targetPhrase, replacePhrase); 	
	 		
	 		/*Print Out New Letter*/
	 		for(int i = 0; i < letter.size(); i++){
				cout<<letter[i]<<endl;
			} 
		 	cout<<endl;
	 	}
	 	
	 	
	 	/*Hidden Message Encode/Decode*/
	 	if(hiddenMessage != 0){
	 		string ende;
	 		while(true){
		 		cout<<"Do you want to 'encode' or 'decode' a message?"<<endl;
		 		cin >> ende;
		 		if(ende == "encode"){
		 			encode();
		 			break;
		 		}else if(ende == "decode"){
		 			decode();
		 			break;
		 		}else{
		 			cout<<"Thats not a correct input, try again"<<endl;
		 		}
	 		}
	 		
	 		
	 		/*Print Out New Letter*/
	 		for(int i = 0; i < letter.size(); i++){
				cout<<letter[i]<<endl;
			} 
		 	cout<<endl;
	 	}
	 	
	 	/*Option to save the file*/
	 	string save;
	 	cout<<"Would you like to save the file? (y/n)"<<endl;
	 	cin >> save;
	 	while(true){
		 	if(save == "y"){
		 		saveFile(letter);
		 		break;
		 	}else if(save == "n"){
		 		//dont save
		 		break;
		 	}else{
		 		cout<<"Please input 'y' or 'n'"<<endl;
		 	}
	 	}
	 
	 /*Continues the program or exits*/
	 cout<<"Do you want to edit more? (y/n)"<<endl;
	 string continueProgram;
	 cin >> continueProgram;
	 while(true){
	 	if(continueProgram == "y"){
	 		break;
	 	}else if(continueProgram == "n"){
	 		exit(0);
	 	}else{
	 		cout<<"That is not a valid input, try again."<<endl;
	 	}
	 }
	}
 	return 0;
 }
