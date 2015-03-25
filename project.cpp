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
 
 /*Gets text file in a vector line by line*/
 vector<string> getTextLine(){
 	vector<string> letter;
 	ifstream file;
 	string line;
 	file.open("Mercurial1.txt");
 	while(getline(file,line)){
 		letter.push_back(line);
 		cout<<line<<endl;
 	}
 	cout<<endl;
 	file.close();
 	
 	return letter;
 }
 
/*ENCODE AND DECODE HERE JIGAR*/
 
 void saveFile(){
 }
 
 /*Main Code to run System*/
 int main(int argc, char** argv){
 	
 	vector<string> letter = getTextLine();

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
	 			//encode();
	 			break;
	 		}else if(ende == "decode"){
	 			//decode();
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
 	
 	
 	string save;
 	cout<<"Would you like to save the file? (y/n)"<<endl;
 	cin >> save;
 	while(true){
	 	if(save == "y"){
	 		//save file
	 		break;
	 	}else if(save == "n"){
	 		//dont save
	 		break;
	 	}else{
	 		cout<<"Please input 'y' or 'n'"<<endl;
	 	}
 	}
 	
 	
 	return 0;
 }
