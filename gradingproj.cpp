#include <iostream> 
#include <math.h>
using namespace std;

//func for computing the midterm grade;

struct scoremidterm {
	double cs = .60;
	double lq = .65;
	double attendance = .05;
	double sw = .15;
	double assignments = .15;
	double ME = .40; 
	double outof; 
	double** lqArr;
	
};

//prototyping
void printMTGradingInfo(scoremidterm* s);
void lqCalculations(scoremidterm* s);


	int choice1;
	int choice2;
	scoremidterm s;
	int lqAmount;

int main() {
		
do {

	cout << "Select one: " << endl; 
	
	cout << "1. Default grading \n    Class Standing = 60% \n    Exam = 40%" << endl;
	cout << "2. Custom Grading" << endl << endl;
	
	cout << "Insert choice: " ;
	cin >> choice1;
	cout << endl;
	
	if (choice1 <= 2) {
		if (choice1 == 1) {
			cout << "Default grade" << endl;
			cout << "Press [1] for Midterm Grade and Press [2] for Final Grade: ";
			cin >> choice2;
			cout << endl;
			
			if (choice2 == 1) {
				printMTGradingInfo(&s); 
				lqCalculations(&s);
				
			}
		} else {
			cout << "none default" << endl;
		}
	} else {
		cout << "invalid";
		
	}
	
	return 0;
} while (choice1); }

void printMTGradingInfo(scoremidterm* s) {
	
	//CONVERTED!!!
	cout << "Class Standing = 60% of the midterm grade.\n"
		 << " - Long Quiz: 65%\n"
		 << " - Attendance: 5%\n"
		 << " - Seatwork: 15%\n"
		 << " - Assignments: 15%\n"
		 << "Exam = 40%" << endl;
	cout << "Please input your scores. Make sure you insert the HPS!" << endl << endl;
	
	system ("pause"); 
}

void lqCalculations(scoremidterm* s) {

	//inputting longquizzes	
	cout << "Enter the number of Long Quizzes you have: "; cin >> lqAmount;
	
	s -> lqArr = new double*[lqAmount];
	for (int i = 0; i < lqAmount; i++) {
		s -> lqArr[i] = new double[2];
	}
	
	cout << "\nEnter the scores of your long quizzes then the HPS: " << endl;
	for (int i = 0; i < lqAmount; i++) {
		cout << "Long quiz " << i+1 << " : "; 
		cin >> s->lqArr[i][0];  } 
		
		cout << endl;
		
	cout << "Highest Possible Score: " << endl;
		for (int i = 0; i < lqAmount; i++) {
		cout << "Long Quiz " << i+1 << " : ";  cin >> s->lqArr[i][1]; }
		
	//calculate the grade
	
	double lqAverage = 0; 
		double HPS = 0;
	
	for (int i = 0; i < lqAmount; i++) {
		lqAverage += (s->lqArr[i][0]); 
		HPS += (s->lqArr[i][1]);
	}
	
	double div = lqAverage;
	div = (div/HPS) * 100;
	double converted = div * s-> lq;
}
	

	



