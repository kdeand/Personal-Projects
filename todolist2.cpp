#include <iostream>
#include <vector>

using namespace std;
int choice;
char ans;

int choiceArrSize;
int index;
string task;
vector<string> tasklist;

//prototyping
void add (vector<string>& task);
void del (vector<string>& task);
void view (vector<string>& task);


int main() {
	
	do {

	string choiceArr[] = {"Add", "Delete", "View", "Exit"};
	choiceArrSize = sizeof(choiceArr)/sizeof(choiceArr[1]);
	
	cout << "Please choose an option." << endl;
	for (int i = 0; i < choiceArrSize; i++) {
		 cout << i + 1 <<". " << choiceArr[i] << endl;
	}
	
	cout << "Your choice (1-4): ";
	cin >> choice;
	
	switch (choice) {
		case 1: 
			add(tasklist); 
			break;
		case 2: 
			del(tasklist);
			break;
		case 3: 
			view(tasklist);
			break;
		case 4: 
			cout << "Thank you!";
			return 0;
			break;
		default: 
			break;
	} 
	
	cout << "Press y to continue: ";
	cin >> ans;
		}
	while (ans == 'y'|| 'Y');
	
}

void add (vector<string>& tasklist) {
	cout << "Add your task: " << endl;
	cin.ignore();
	getline(cin, task);
	tasklist.push_back(task);
	cout << "Task added successfully!"; 
}

void view (vector<string>& tasklist) {
	
	if (tasklist.empty()) {
		cout << "No tasks here...";
	} else {

	for(size_t i = 0; i < tasklist.size(); i++){
		cout << i + 1 << ". " << tasklist[i] << endl;
	} }
}

void del  (vector<string>& tasklist){
	cout << "Delete your task number: " << endl;
	cin >> index;
	
	if (index < 1 || index > tasklist.size() ) {
		cout << "Invalid.";
		return;
	} else {
		tasklist.erase(tasklist.begin() + (index - 1) );
		cout << "Task erased.";
		return;
	}
}


