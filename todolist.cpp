#include <iostream>
#include <vector>
#include <string>
using namespace std;

int optionlistsize; 
int option;
vector <string> tasks;

void add(vector<string>& tasks) { //vector(vartype) variable
	string task;
	cout << "Enter task to add: ";
	cin.ignore();
	getline(cin, task);
	tasks.push_back(task); //vectorname.pushback(variable)
	cout << "Task added successfully! \n";
	
}

void view(vector<string>& tasks) { //the ampersand means it's passed by reference and not by value, it prevents making copies all throughout the program
	if (tasks.empty()) {
		cout << "List is empty." << endl;
		return;
	} else {
	
	
	cout << "Your tasks: " << endl;
	for (size_t i = 0; i < tasks.size(); i++) {
		cout << "[" << i + 1 << "] " << tasks[i] << endl;
		}
	}
}

void del(vector<string>& tasks) {
	if (tasks.empty()) {
		cout << "No tasks to delete." << endl;
		
	} 
	view(tasks);
	int index; 
	cout << "Enter the task number to delete: ";
	cin >> index;
	
	if(index < 1 || index > tasks.size()) {
		cout << "Invalid task number." << endl;
		return;
	} else {
		tasks.erase(tasks.begin() + (index - 1)); 
		cout << "Task Deleted successfully.";
		return;
	}
}



int main() {
	vector<string> tasks;
	
	while (true) {
	string optionlist[] = {"View", "Add", "Delete"};
	optionlistsize = sizeof(optionlist)/sizeof(optionlist[1]);
	
	cout << "Hello, welcome to the to-do list app." << endl << endl;
	
	for (int i = 0; i < optionlistsize; i++) {
		cout << "[" << i + 1  << "] " << optionlist[i] << endl; 
	}
	
	cout << "Choose an option: ";
	cin >> option; 

	
	
	switch (option) { 
	
		case 1: 
			view(tasks);
			break;
			
		case 2: 
			add(tasks);
			break;
			
		case 3: 
			del(tasks);
			break;
			
		default:
			break;
	}
	
		}
}



