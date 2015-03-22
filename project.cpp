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
 				if(subtemp == targetWordComma){
 					subtemp = replaceWordComma;
 				}
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
 	string targetPhraseComma = targetPhrase+",";
 	string targetPhrasePeriod = targetPhrase+".";
 	string replacePhraseComma = replacePhrase+",";
 	string replacePhrasePeriod = replacePhrase+",";
 	
 	for(int x = 0; x < letter.size(); x++){
	 	string temp = letter[x];
	 	string subtemp;
	 	string subtempComma = subtemp+",";
	 	string subtempPeriod = subtemp+".";	 	
	 	string subLine = temp;
	 	
	 	int end = targetPhrase.size();
	 	int end2 = targetPhraseComma.size();
	 	int remainder;
	 	for(int i = 0; i<temp.size();i++){
	 		subtemp = temp.substr(i,end+i);
	 		remainder = temp.size()-(end+i);
	 		if(subtemp == targetPhrase){
	 			subLine.replace(subLine.begin()+i,subLine.end()-remainder, targetPhrase);
	 			//cout<<temp.substr(0,i-1)<<endl;
	 			cout<<subLine<<endl;
	 			break;
	 		}
	 		if(subtempComma == targetPhraseComma){
	 			subLine = temp.substr(0,i-1) + replacePhraseComma + temp.substr(end2+i,temp.size());
	 			break;
	 		}
	 		if(subtempPeriod == targetPhrasePeriod){
	 			subLine = temp.substr(0,i-1) + replacePhrasePeriod + temp.substr(end2+i,temp.size());
	 			break;
	 		}
 		}
 		newLetter.push_back(subLine);
 	}
 	letter = newLetter;
 }
 
 
 
 /*Gets each phrase from the Adjective List and places it into a vector*/ 
 vector<string> getPhrase(){
	int phraseCounter = 0;
	vector<string> phrase;
 	ifstream phraseFile;
 	phraseFile.open("AdjectiveList1.txt");
 	string line;
 	while(getline(phraseFile, line)){
 		istringstream iss(line);
 		phrase.push_back(line);
 	}
 	phraseFile.close();
 	return phrase;
 }
 
 
 /*Main Code to run System*/
 int main(int argc, char** argv){
 	
 	vector<string> letter;
 	vector<string> phraseList;
 	vector<string> adjList;
 	string temp;
 	int nameReplace = 0;
 	int wordReplace = 0;
 	int phraseReplace = 0;
 	int hideMessage = 0;
 	string choice;
 	/*Gets SystemTime and creates Srand function*/
	time_t t;
	time(&t);
	srand((unsigned int) t);

 	/*Choice of Action*/
 	while(true){
	 	cout<<"Please choose what you want to replace or do: name, adjective, phrase, hide"<<endl;
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
	 	}else if(choice == "hide"){
	 		hideMessage = 1;
	 		break;
	 	}else{
	 		cout<<"That is not the correct choice, Try again"<<endl;
	 	}
 	}
 	
	/*Converts Textfile to a Vector*/
 	ifstream file;
 	string line;
 	file.open("Mercurial1.txt");
 	while(getline(file,line)){
 		letter.push_back(line);
 		//cout<<line<<endl;
 	}
 	cout<<endl;
 	file.close();
 	
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
			cout<<letter[i]<<endl;
		} 
	 	cout<<endl;
 	}
 	
 	
 	
 	/*Adjective Replacement*/
 	if(wordReplace != 0){
	 	ifstream Adjfile;
	 	Adjfile.open("AdjectiveList2.txt");
	 	while(!Adjfile.eof()){
	 		Adjfile >> temp;
	 		adjList.push_back(temp);
	 	}
	 	Adjfile.close();	
	 		
 		string targetWord;
 		string replaceWord;
 		/*Random Number*/
 		int totalAdj = adjList.size()-1;
 		int RandomNum = rand() % totalAdj;
 		cout<<"Please input the word you want to replace"<<endl;
 		cin >> targetWord;
 		replaceWord = adjList[RandomNum];
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
 		vector<string> phrase = getPhrase();
 		string targetPhrase;
 		string replacePhrase;
 		int totalAdj = phrase.size()-1;
 		int randNum = rand() % totalAdj;
 		cout<<"Please input the Phrase you want to replace."<<endl;
 		cin >> targetPhrase;
 		replacePhrase = phrase[randNum];
 		cout<<"The replacement Phrase is: "<<replacePhrase<<endl;
		phraseChange(letter, targetPhrase, replacePhrase); 	
 		/*Print Out New Letter
 		for(int i = 0; i < letter.size(); i++){
			cout<<letter[i]<<endl;
		} 
	 	cout<<endl;*/
 	}
 	
 	
 	
 	
 	
 	
 	
 	
 			
 	return 0;
 }
