#include <iostream> 
#include <math.h>
using namespace std;


//Lconverted for long quiz
//atnd for attendance
//sConverted for seatworks

//func for computing the midterm grade;

struct scoremidterm {
	double cs = .60;
	double lq = .65;
	double attendance = .05;
	double sw = .15;
	double assignment = .15;
	double ME = .40; 
	double outof; 
	double** lqArr;
	double** swArr;
	double** assignmentArr;
	double metofin = .15;
	double fin = .25;
};



//prototyping
void printMTGradingInfo(scoremidterm* s);
void lqCalculations(scoremidterm* s);
void attendanceCalculation(scoremidterm* s);
void swCalculation(scoremidterm* s);
void assignmentCalculation(scoremidterm* s);
void csCalculation(double* Lconverted, double* sConverted, double* aConverted, double* atnd, scoremidterm* s);
void mtCalculation(scoremidterm* s);
void midtermCalculation(double* mConverted, double* classStanding);
void finalCalculation(double* mConverted, double* classStanding, scoremidterm* s);
void printGradeBreakdown(double* MEpercent, double *classStanding, double* finConverted);


	int choice1;
	int choice2;
	scoremidterm s;
	int lqAmount;
	int swAmount;
	int assignmentAmount;
	double Lconverted, sConverted, aConverted, atnd, mConverted, finConverted;
	double classStanding, mtFinalCalculation;
	double ME2fin;
	double midtermGrade, MEpercent, mtHPS;
	double finGrade, Finpercent, finHPS, MEpercents;

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
				cout << "\n--------" << endl;
				lqCalculations(&s);
				cout << "\n--------" << endl;
				attendanceCalculation(&s);
				cout << "\n--------" << endl;
				swCalculation(&s);
				cout << "\n--------" << endl;
				assignmentCalculation(&s);
				cout << "\n--------" << endl;
				csCalculation(&Lconverted, &sConverted, &aConverted, &atnd, &s);
				cout << "\n--------" << endl;
				mtCalculation(&s);
				cout << "--------" << endl;
				midtermCalculation(&classStanding, &mConverted);
				cout << "--------" << endl;
				
				
			} else if (choice2 == 2) {
					printMTGradingInfo(&s); 
				cout << "\n--------" << endl;
				lqCalculations(&s);
				cout << "\n--------" << endl;
				attendanceCalculation(&s);
				cout << "\n--------" << endl;
				swCalculation(&s);
				cout << "\n--------" << endl;
				assignmentCalculation(&s);
				cout << "\n--------" << endl;
				csCalculation(&Lconverted, &sConverted, &aConverted, &atnd, &s);
				cout << "\n--------" << endl;
				finalCalculation(&mConverted, &classStanding, &s);
				cout << "\n--------" << endl;
				printGradeBreakdown(&MEpercents, &classStanding, &finConverted); //final grade breakdown
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

void printFinalGradingInfo(scoremidterm* s) {
	cout << "Class Standing = 60% of the midterm grade.\n"
		 << " - Long Quiz: 65%\n"
		 << " - Attendance: 5%\n"
		 << " - Seatwork: 15%\n"
		 << " - Assignments: 15%\n"
		 << "Midterm Exam = 15%" << endl;
		 cout << "Final Exam = 15%" << endl;
	cout << "Please input your scores. Make sure you insert the HPS!" << endl << endl;
	
	system ("pause"); 
}

void attendanceCalculation(scoremidterm* s) {
	double schooldays;
	double attended;
	cout << "How many days of school do you have: "; cin >> schooldays;
	cout << "How many days of school have you attended: "; cin >> attended;
	
	double atnd = attended / schooldays; 
	atnd = (atnd * s->attendance) * 100;
	cout << "attendance = " << atnd << "%";
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
		cout << "HPS #" << i+1 << " : ";  cin >> s->lqArr[i][1]; }
		
	//calculate the grade
	
	double lqAverage = 0; 
		double HPS = 0;
	
	for (int i = 0; i < lqAmount; i++) {
		lqAverage += (s->lqArr[i][0]); 
		HPS += (s->lqArr[i][1]);
	}
	
	double div = lqAverage;
	div = (div/HPS) * 100;
	Lconverted = div * s-> lq;
	cout << "Long Quiz = " << Lconverted << "%";
}

void swCalculation(scoremidterm* s) {
	cout << "\nEnter the amount of Seatworks that you have: "; cin >> swAmount;
	s -> swArr = new double*[swAmount];
	for (int i = 0; i < swAmount; i++) {
		s -> swArr[i] = new double[2];
	}
	
	cout << "\nEnter the scores of your seatworks then the HPS: " << endl;
	for (int i = 0; i < swAmount; i++) {
		cout << "Seatwork #" << i + 1 << " : "; 
		cin >> s-> swArr[i][0];
	}
	
	//for HPS
	cout << "Highest Possible Score: " << endl;
	for (int i = 0; i < swAmount; i++) {
		cout << "HPS #" << i + 1 << " : "; 
		cin >> s->	swArr[i][1];
	}
	
	//for calculations 
	double swAverage = 0;
	double HPS = 0;
	
	for (int i = 0; i < swAmount; i++) {
		swAverage += (s->swArr[i][0]);
		HPS += (s->swArr[i][1]);
	}
	
	double swComp = (swAverage / HPS) * 100;
	sConverted = swComp * s->sw;
	cout << "Seatwork = " << sConverted << "%";
}
	
void assignmentCalculation(scoremidterm* s) {
	cout << "\nEnter the amount of Assignments that you have: "; cin >> assignmentAmount;
	s -> assignmentArr = new double*[assignmentAmount];
	for (int i = 0; i < assignmentAmount; i++) {
		s -> assignmentArr[i] = new double[2];
	}
	
	//for hps 
	cout << "\nEnter the scores of your assignments then the HPS: " << endl;
	for (int i = 0; i < assignmentAmount; i++) {
		cout << "Assignment #" << i + 1 << " : "; 
		cin >> s-> assignmentArr[i][0];
	}
	
	cout << "Highest Possible Score: " << endl;
	for (int i = 0; i < assignmentAmount; i++) {
		cout << "HPS #" << i + 1 << " : "; 
		cin >> s->	assignmentArr[i][1];
	}
	
	//for calculations
	double assignmentAverage = 0;
	double HPS = 0;
	
	for (int i = 0; i < assignmentAmount; i++) {
		assignmentAverage += (s->assignmentArr[i][0]);
		HPS += (s->assignmentArr[i][1]);
	}
	
	double assignmentComp = (assignmentAverage / HPS) * 100;
	aConverted = assignmentComp * s->assignment;
	cout << "Assignment = " << aConverted << "%";
}

void csCalculation(double* Lconverted, double* sConverted, double* aConverted, double* atnd, scoremidterm* s) {
	classStanding = (*Lconverted + *atnd + *sConverted + *aConverted) * s->cs + 3;
	cout << endl << endl << "Class Standing: " << classStanding <<"%";
}

void mtCalculation(scoremidterm* s) {
	cout << "Enter your Midterm Exam: "; cin >> midtermGrade;
	cout << "Enter the HPS: "; cin>> mtHPS;
	MEpercent = (midtermGrade / mtHPS) * 100;
	mConverted = MEpercent * s->ME;
}

void midtermCalculation (double* mConverted, double* classStanding) {
	mtFinalCalculation = *mConverted + *classStanding; 
	cout << "Midterm Grade: " << mtFinalCalculation << endl;
	cout << "Class Standing: " << *classStanding << endl  << "Midterm Exam: " << *mConverted << endl;
	double mtgwa = *classStanding + *mConverted; 
	cout << "Your midterm grade is: " << mtgwa << endl;
	
}

void finalCalculation (double* MEpercent, double* classStanding, scoremidterm* s) {
	cout << "Enter your Midterm Exam: "; cin >> midtermGrade;
	cout << "Enter the HPS: "; cin>> mtHPS;
	*MEpercent = (midtermGrade / mtHPS) * 100;
	MEpercents = *MEpercent * s -> metofin;
	cout << "Midterm Exam Grade: " << MEpercents << "%" << endl;
	cout << "Enter your Final Exam Score: "; cin >> finGrade;
	cout << "Enter the HPS: "; cin >> finHPS;
	
	Finpercent = (finGrade / finHPS) * 100;
	finConverted = Finpercent * s -> fin;
	cout << "Final Exam Grade: " << finConverted << "%" << endl;
}

void printGradeBreakdown(double* MEpercents, double *classStanding, double* finConverted) {
	cout << "Class Standing: " << *classStanding << endl  << "Midterm Exam: " << *MEpercents << endl << "Final Exam: " << *finConverted << endl;
	double gwa = *classStanding + *MEpercents + *finConverted;
	cout << "Your gwa is : " << gwa;
}


