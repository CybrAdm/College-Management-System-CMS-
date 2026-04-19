#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
const int SIZE = 100;
long long int idCounter = 100000;

struct information {
	long long int id;
	string name;
	string mobileNumber;
	string password;
};

struct student {
	information inf;
	string department;
	int academicYear;
	string studentCourses[10];
} stu[SIZE];

struct staff {
	information inf;
	string department;
	string position;
	string teachingCourses[10];
} stf[SIZE];

struct administration {
	information inf;
	string position;
} adm[SIZE];

struct gradeScheme
{
	float total;
	float finalMax;
	float practicalMax;
	float yearWorkMax;
	float quizMax;
};

struct grade
{
	float total;
	float final;
	float practical;
	float yearWork;
	float quiz;
	float percentage;
	string letter;
};

struct enrollment
{
	int studentIndex[SIZE];
	grade g[SIZE];
};

struct course
{
	string name;
	int creditHours;
	int academicYear;
	gradeScheme gr;
	string academicMemberName[5];
	int studentCount;
	enrollment enr;
	int weekDay;
	int hour;
	int minute;
}cou[SIZE];

struct schedule
{
	int day;
	int month;
	int year;

	int hour;
	int minute;
};

struct exam
{
	schedule sch;
	course co;
}exm[SIZE];

struct appointment
{
	long long int studentID;
	string stfName;
	schedule sch;
} app[SIZE];

void signUp(int&, int&, int&, student[], staff[], administration[]);
long long int generateID();
void signIn(int, int, int, int&, int&, int&, exam[], appointment[], course[], student[], staff[], administration[]);
string getPassword();
void forgetPassword(int, int, int, int, student[], staff[], administration[]);
void addCourse(int&, course[]);
void viewCourses(int, course[]);
void removeCourse(int&, course[]);
void selectCourse(int, int, staff[], course[]);
void stuMenu(int&, int, int, int&, appointment[], student[], staff[]);
void stfMenu(int, int, course[], student[], staff[]);
void admMenu(int&,int&, exam[], course[]);
void couMenu(int&, course[]);
void requestAppointment(int, int, int&, appointment[], student[], staff[]);
// void setGrades(int, int, course[], student[], staff[]);
void calculateGrade(int, grade&, course[]);
void registerCourses(int, int);
void dropCourses(int, int&);
void viewRegCou(int);
void couRegMenu(int&, int);
void availableCourses(int, int);
void exmMenu(int, int&, course[], exam[]);
void setExamSchedule(int, int&, course[], exam[]);
void viewExamSchedule(int, int, course[], exam[]);
void removeExamSchedule(int, int&, course[], exam[]);

int main()
{
	int choice;
	int numOfStu = 0;
	int numOfStf = 0;
	int numOfAdm = 0;
	int numOfCou = 0;
	int numOfApp = 0;
	int numOfExm = 0;


	stu[0] = { {100000, "Ahmed Ali",     "01012345678", "256" },  "Computer Science",    1 };
	stu[1] = { {100001, "Sara Mohamed",  "01023456789", "256" },  "Information Systems", 2 };
	stu[2] = { {100002, "Omar Khaled",   "01034567890", "256"},  "Computer Science",    3 };
	stu[3] = { {100003, "Ahmed Kareem",     "01012345678", "256" },  "Computer Science",    4 };
	stu[4] = { {100004, "Jana Walid",  "01023456789", "256" },  "Information Systems", 1 };
	stu[5] = { {100005, "Yousef Ehab",   "01034567890", "256"},  "Computer Science",    2 };
	numOfStu = 6;

	stf[0] = { {200000, "Mona Hassan",   "01098765432", "256" }, "Information Systems", "Lecturer" };
	stf[1] = { {200001, "Youssef Nabil", "01087654321", "256"}, "Computer Science",    "Professor" };
	stf[2] = { {200002, "Naglaa Badr",   "01098765432", "256" }, "Information Systems", "Lecturer" };
	stf[3] = { {200003, "Naglaa Fathy",   "01098765432", "256" }, "Information Systems", "Lecturer" };
	stf[4] = { {200004, "Israa Nabil", "01087654321", "256"}, "Computer Science",    "Professor" };
	stf[5] = { {200005, "Salsabil Amin", "01087654321", "256"}, "Computer Science",    "Professor" };
	numOfStf = 6;

	adm[0] = { {300000, "Karim Saleh", "01122334455", "256" }, "Registrar" };
	adm[1] = { {300001, "Nadia Fawzy", "01133445566", "256"}, "Supervisor" };
	numOfAdm = 2;

	cou[0] = { "Calculus I",          3, 1, {100, 60, 0,  30, 10} };
	cou[1] = { "Calculus II",         3, 1, {100, 60, 0,  30, 10} };
	cou[2] = { "Physics I",           3, 1, {100, 50, 15, 25, 10} };
	cou[3] = { "Introduction to CS",  3, 2, {100, 60, 0,  30, 10} };
	cou[4] = { "Linear Algebra",      3, 2, {100, 60, 0,  30, 10} };
	cou[5] = { "English I",           2, 2, {100, 60, 0,  30, 10} };
	cou[6] = { "Data Structures",     3, 3, {100, 60, 10, 20, 10} };
	cou[7] = { "Discrete Math",       3, 3, {100, 60, 0,  30, 10} };
	cou[8] = { "Database Systems",    3, 3, {100, 55, 15, 20, 10} };
	cou[9] = { "OOP",     3, 4, {100, 60, 10, 20, 10} };
	cou[10] = { "SWE",       3, 4, {100, 60, 0,  30, 10} };
	cou[11] = { "AI",    3, 4, {100, 55, 15, 20, 10} };
	numOfCou = 12;






	do
	{
		cout << "====== College Management System ======" << endl;
		cout << "[1] - Sign Up" << endl;
		cout << "[2] - Sign In" << endl;
		cout << "[0] - Exit" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			signUp(numOfStu, numOfStf, numOfAdm, stu, stf, adm);
			break;
		case 2:
			signIn(numOfStu, numOfStf, numOfAdm, numOfCou, numOfApp, numOfExm, exm, app, cou, stu, stf, adm);
			break;
		case 0:
			cout << "Exiting..." << endl;
			return 0;
		default:
			cout << "Invalid choice! Please try again" << "\n\n";
			break;
		}
	} while (true);
}

void signUp(int& numOfStu, int& numOfStf, int& numOfAdm, student stu[], staff stf[], administration adm[])
{
	int choice;
	do {
		cout << "====== Sign Up Menu ======" << endl;
		cout << "[1] - Student" << endl;
		cout << "[2] - Academic Staff Member" << endl;
		cout << "[3] - Administration Member" << endl;
		cout << "[0] - Back" << endl;
		cout << "--------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
			cout << "Invalid choice! Please try again" << "\n\n";
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

	cin.ignore();

	switch (choice) {
	case 1:
		stu[numOfStu].inf.id = generateID();
		cout << "Your generated ID: " << stu[numOfStu].inf.id << endl;
		cout << "Enter your full name: "; getline(cin, stu[numOfStu].inf.name);
		cout << "Enter your mobile number: "; getline(cin, stu[numOfStu].inf.mobileNumber);
		cout << "Enter your password: "; getline(cin, stu[numOfStu].inf.password);
		cout << "Enter your department (General, SWE, AI, CSEC, ROB, DMM, BIO): "; getline(cin, stu[numOfStu].department);
		cout << "Enter your academic year (1, 2, 3, 4): "; cin >> stu[numOfStu].academicYear;
		cout << "\nStudent registered successfully!\n" << endl;
		numOfStu++;
		break;

	case 2:
		stf[numOfStf].inf.id = generateID();
		cout << "Your generated ID: " << stf[numOfStf].inf.id << endl;
		cout << "Enter your full name: "; getline(cin, stf[numOfStf].inf.name);
		cout << "Enter your mobile number: "; getline(cin, stf[numOfStf].inf.mobileNumber);
		cout << "Enter your password: "; getline(cin, stf[numOfStf].inf.password);
		cout << "Enter your department: "; getline(cin, stf[numOfStf].department);
		cout << "Enter your position: "; getline(cin, stf[numOfStf].position);
		cout << "\nStaff member registered successfully!\n" << endl;
		numOfStf++;
		break;

	case 3:
		adm[numOfAdm].inf.id = generateID();
		cout << "Your generated ID is: " << adm[numOfAdm].inf.id << endl;
		cout << "Enter your full name: "; getline(cin, adm[numOfAdm].inf.name);
		cout << "Enter your mobile number: "; getline(cin, adm[numOfAdm].inf.mobileNumber);
		cout << "Enter your password: "; getline(cin, adm[numOfAdm].inf.password);
		cout << "Enter your position: "; getline(cin, adm[numOfAdm].position);
		cout << "\nAdministration member registered successfully!\n" << endl;
		numOfAdm++;
		break;

	case 0:
		cout << "Returning to the Main Menu... \n" << endl;
		return;
	}
}

long long int generateID() {
	return idCounter++;
}


void signIn(int numOfStu, int numOfStf, int numOfAdm, int& numOfCou, int& numOfApp, int& numOfExm, exam exm[], appointment app[], course cou[], student stu[], staff stf[], administration adm[])
{
	int choice;
	do {
		cout << "====== Sign In Menu ======\n";
		cout << "[1] - Student\n";
		cout << "[2] - Academic Staff Member\n";
		cout << "[3] - Administration Member\n";
		cout << "[0] - Back\n";
		cout << "--------------------------\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
			cout << "Invalid choice! Please try again\n\n";

	} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

	if (choice == 0) {
		cout << "Returning to the Main Menu...\n\n";
		return;
	}

	long long int tempID;
	cout << "Enter your ID: ";
	cin >> tempID;

	bool idFound = false;
	int userIndex = -1;

	switch (choice) {
	case 1:
		for (int i = 0; i < numOfStu; i++)
			if (stu[i].inf.id == tempID) { idFound = true; userIndex = i; break; }
		break;
	case 2:
		for (int i = 0; i < numOfStf; i++)
			if (stf[i].inf.id == tempID) { idFound = true; userIndex = i; break; }
		break;
	case 3:
		for (int i = 0; i < numOfAdm; i++)
			if (adm[i].inf.id == tempID) { idFound = true; userIndex = i; break; }
		break;
	}

	if (!idFound) {
		cout << "\nID Not Found! Please try again\n\n";
		return;
	}

	int trials = 3;
	bool loggedIn = false;

	while (trials > 0 && !loggedIn) {
		cout << "Enter password: ";
		string tempPass = getPassword();

		switch (choice) {
		case 1:
			if (stu[userIndex].inf.password == tempPass) {
				cout << "\nWelcome, " << stu[userIndex].inf.name << "\n\n";
				loggedIn = true;
				stuMenu(numOfCou, userIndex, numOfStf, numOfApp, app, stu, stf);
			}
			break;
		case 2:
			if (stf[userIndex].inf.password == tempPass) {
				cout << "\nWelcome, " << stf[userIndex].inf.name << "\n\n";
				loggedIn = true;
				stfMenu(userIndex, numOfCou, cou, stu, stf);
			}
			break;
		case 3:
			if (adm[userIndex].inf.password == tempPass) {
				cout << "\nWelcome, " << adm[userIndex].inf.name << "\n\n";
				loggedIn = true;
				admMenu(numOfCou, numOfExm, exm, cou);
			}
			break;
		}

		if (!loggedIn) {
			trials--;
			if (trials > 0) {
				cout << "\nWrong password! You have " << trials << " trial(s) left.\n\n";
			}
			else {
				cout << "\nWrong password! You have no trials left.\n";
				cout << "If you forgot your password, press 1. Otherwise press 0: ";
				int x; cin >> x;
				if (x == 1) {
					forgetPassword(choice, numOfStu, numOfStf, numOfAdm, stu, stf, adm);
					return;
				}
				else {
					cout << "Returning to the Main Menu...\n\n";
				}
				return;
			}
		}
	}
}

string getPassword() {
	string password = "";
	char ch;

	while ((ch = _getch()) != 13) {
		if (ch == 8) {
			if (!password.empty()) {
				password.pop_back();
				cout << "\b \b";
			}
		}
		else {
			password += ch;
			cout << '*';
		}
	}
	cout << endl;
	return password;
}


void forgetPassword(int choice, int numOfStu, int numOfStf, int numOfAdm, student stu[], staff stf[], administration adm[])
{
	bool found = false;
	while (!found) {
		string phone;
		cout << "Enter your mobile number (or type '0' to cancel): ";
		cin >> phone;

		if (phone == "0") {
			cout << "Returning to the Main Menu...\n\n";
			return;
		}


		if (choice == 1) {
			for (int i = 0; i < numOfStu; i++) {
				if (stu[i].inf.mobileNumber == phone) {
					found = true;
					cout << "Phone found! Your ID is: " << stu[i].inf.id << endl;
					cout << "Enter your new password: ";
					stu[i].inf.password = getPassword();
					cout << "Password has been reset successfully!\n\n";
					break;
				}
			}
		}
		else if (choice == 2) {
			for (int i = 0; i < numOfStf; i++) {
				if (stf[i].inf.mobileNumber == phone) {
					found = true;
					cout << "Phone found! Your ID is: " << stf[i].inf.id << endl;
					cout << "Enter your new password: ";
					stf[i].inf.password = getPassword();
					cout << "Password has been reset successfully!\n\n";
					break;
				}
			}
		}
		else if (choice == 3) {
			for (int i = 0; i < numOfAdm; i++) {
				if (adm[i].inf.mobileNumber == phone) {
					found = true;
					cout << "Phone found! Your ID is: " << adm[i].inf.id << endl;
					cout << "Enter your new password: ";
					adm[i].inf.password = getPassword();
					cout << "Password reset successfully!\n\n";
					break;
				}
			}
		}

		if (!found) {
			cout << "Mobile number not found! Please try again\n\n";
		}
	}
}

	void stuMenu(int& numOfCou, int stuIndex, int numOfStf, int& numOfApp, appointment app[], student stu[], staff stf[])
	{
	int choice;
	do
	{
		do
		{
			cout << "====== Student Dashboard ======" << endl;
			cout << "[1] - Course Registration" << endl;
			cout << "[2] - Request Grades" << endl;
			cout << "[3] - Request Appointment with Staff Members" << endl;
			cout << "[0] - Logout" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
				cout << "Invalid choice! Please try again\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

		switch (choice)
		{
		case 1:
			couRegMenu(numOfCou, stuIndex);
			break;

		case 2:
			/* Student Request grades func */
			break;

		case 3:
			/* Student Request Appoi. func */
			requestAppointment(stuIndex, numOfStf, numOfApp, app, stu, stf);
			break;

		case 0:
			cout << "Logging Out... \n" << endl;
			return;
		}
	} while (true);
}

void stfMenu(int stfIndex, int numOfCou, course cou[], student stu[], staff stf[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Staff Dashboard ======" << endl;
			cout << "[1] - Set Grades" << endl;
			cout << "[2] - View Appointments" << endl;
			cout << "[3] - Select Courses to Teach" << endl;
			cout << "[0] - Logout" << endl;
			cout << "-----------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
				cout << "Invalid choice! Please try again" << "\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

		switch (choice)
		{
		case 1:

			/* Staff Set Grades func */
			break;

		case 2:
			/* Staff View Appointments func */
			break;

		case 3:
			selectCourse(stfIndex, numOfCou, stf, cou);
			break;

		case 0:
			cout << "Returning to the Main Menu... \n" << endl;
			return;
		}
	} while (true);
}

void admMenu(int& numOfCou,int& numOfExm, exam exm[], course cou[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Administration Dashboard ======" << endl;
			cout << "[1] - Edit Courses" << endl;
			cout << "[2] - Add Course Schedule" << endl;
			cout << "[3] - Add Exam Schedule" << endl;
			cout << "[0] - Logout" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
				cout << "Invalid choice! Please try again" << "\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

		switch (choice)
		{
		case 1:
			couMenu(numOfCou, cou);
			break;

		case 2:
			/* Admin Add Course Schedules func */
			break;

		case 3:
			exmMenu(numOfCou, numOfExm, cou, exm);
			break;

		case 0:
			cout << "Returning to the Main Menu... \n" << endl;
			return;
		}
	} while (true);
}

void addCourse(int& numOfCou, course cou[])
{
	char cont;
	do {
		if (numOfCou >= SIZE)
		{
			cout << "\nMaximum number of courses reached!\n" << endl;
			return;
		}
		
			cin.ignore();
			cout << "Enter Course Name: ";
			getline(cin, cou[numOfCou].name);

			cout << "Enter Course Credit Hour (1-5): ";
			cin >> cou[numOfCou].creditHours;
			if (cou[numOfCou].creditHours > 5 || cou[numOfCou].creditHours <= 0)
			{
				cout << "\nInvalid Credit Hours! Please Try Again\n" << endl;
				return;
			}

			cout << "Enter Course Academic Year (1-4): ";
			cin >> cou[numOfCou].academicYear;
			if (cou[numOfCou].academicYear > 4 || cou[numOfCou].academicYear <= 0)
			{
				cout << "\nInvalid Academic Year! Please Try Again\n" << endl;
				return;
			}

			cout << "Enter Course Total Marks: ";
			cin >> cou[numOfCou].gr.total;

			cout << "Enter Course Final Max Marks: ";
			cin >> cou[numOfCou].gr.finalMax;

			cout << "Enter Course Practical Max Marks: ";
			cin >> cou[numOfCou].gr.practicalMax;

			cout << "Enter Course Year Work Max Marks: ";
			cin >> cou[numOfCou].gr.yearWorkMax;

			cout << "Enter Course Quiz Max Marks: ";
			cin >> cou[numOfCou].gr.quizMax;

			if (cou[numOfCou].gr.total != cou[numOfCou].gr.finalMax + cou[numOfCou].gr.practicalMax + cou[numOfCou].gr.yearWorkMax + cou[numOfCou].gr.quizMax)
			{
				cout << "\nInvalid Total Marks! Please Try Again\n" << endl;
				return;
			}

		cout << "\nCourse added successfully!" << endl;
		numOfCou++;

		do {
			cout << "\nDo you want to add another course? (Y/N): ";
			cin >> cont;
			cout << endl;

			if (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";

		} while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

		if (cont == 'n' || cont == 'N')
			cout << "Returning to Administration Dashboard... \n" << endl;

	} while (cont == 'y' || cont == 'Y');
}

void viewCourses(int numOfCou, course cou[])
{
	if (numOfCou == 0)
	{
		cout << "No Courses available\n" << endl;
		return;
	}
	cout << "====== Courses (" << numOfCou << ") ======\n\n";
	for (int j = 0; j < numOfCou; j++)
	{
		cout << "Course " << "[" << j + 1 << "]" << endl;

		cout << "Name: " << cou[j].name << endl;
		cout << "Credit Hours: " << cou[j].creditHours << endl;
		cout << "Academic Year: " << cou[j].academicYear << endl;
		cout << "Total Marks: " << cou[j].gr.total << endl;
		cout << "Final Max Marks: " << cou[j].gr.finalMax << endl;
		cout << "Practical Max Marks: " << cou[j].gr.practicalMax << endl;
		cout << "Year Work Max Marks: " << cou[j].gr.yearWorkMax << endl;
		cout << "Quiz Max Marks: " << cou[j].gr.quizMax << endl;

		cout << endl;
	}
}

void removeCourse(int& numOfCou, course cou[])
{
	if (numOfCou == 0)
	{
		cout << "No Courses available\n" << endl;
		return;
	}

	string remCourse;
	cout << "Enter Name of Course you want to remove: ";
	cin.ignore();
	getline(cin, remCourse);

	for (int i = 0; i < numOfCou; i++)
	{
		if (remCourse == cou[i].name)
		{
			for (int j = i; j < numOfCou - 1; j++)
			{
				cou[j] = cou[j + 1];
			}
			numOfCou--;
			cout << "\nCourse removed successfully!\n\n";
			return;
		}
	}

	cout << "\nCourse doesn't Exist, Please try again\n" << endl;
	return;
}

void selectCourse(int stfIndex, int numOfCou, staff stf[], course cou[])
{
	cout << "Enter your teaching courses (Enter '0' to finish): ";
	cin.ignore();

	string temp_courses[10];
	int courseCount = 0;

	while (courseCount < 10)
	{
		string temp;
		getline(cin, temp);

		if (temp == "0")
		{
			cout << "\nReturning to Staff Dashboard... \n" << endl;
			break;
		}

		bool found = false;
		for (int i = 0; i < numOfCou; i++) {
			if (cou[i].name == temp) {
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "\nCourse is not available! Please try again\n\n";
			cout << "Enter another course (or '0' to finish): ";
			continue;
		}

		bool alreadyAdded = false;
		for (int j = 0; j < courseCount; j++) {
			if (temp_courses[j] == temp) {
				cout << "\nAlready added! Please try again\n\n";
				cout << "Enter another course (or '0' to finish): ";
				alreadyAdded = true;
				break;
			}
		}

		if (!alreadyAdded) {
			temp_courses[courseCount] = temp;
			courseCount++;
			cout << "\nCourse added successfully!\n\n";

			for (int i = 0; i < numOfCou; i++) {
				if (cou[i].name == temp) {
					for (int j = 0; j < 5; j++) {
						if (cou[i].academicMemberName[j] == "") {
							cou[i].academicMemberName[j] = stf[stfIndex].inf.name;
							break;
						}
					}
					break;
				}
			}

			cout << "Enter another course (or '0' to finish): ";
		}
	}

	for (int i = 0; i < courseCount; i++)
		stf[stfIndex].teachingCourses[i] = temp_courses[i];
}

void couMenu(int& numOfCou, course cou[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Courses Menu ======" << endl;
			cout << "[1] - Add Course" << endl;
			cout << "[2] - Remove Course" << endl;
			cout << "[3] - View Courses" << endl;
			cout << "[0] - Back" << endl;
			cout << "--------------------------\n";
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
				cout << "Invalid choice! Please try again\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

		switch (choice)
		{
		case 1:
			addCourse(numOfCou, cou);
			break;

		case 2:
			removeCourse(numOfCou, cou);
			break;

		case 3:
			viewCourses(numOfCou, cou);
			break;

		case 0:
			cout << "Returning to Administration Dashboard... \n" << endl;
			return;
		}
	} while (true);
}

void requestAppointment(int stuIndex, int numOfStf, int& numOfApp, appointment app[], student stu[], staff stf[])
{

	int choice;

	if (numOfApp >= SIZE)
	{
		cout << "\nMaximum number of appointments reached!\n" << endl;
		return;
	}

	if (numOfStf == 0)
	{
		cout << "\nNo staff members available\n" << endl;
		return;
	}

	cout << "\n====== Request Appointment ======" << endl;


	app[numOfApp].studentID = stu[stuIndex].inf.id;
	cout << "Your ID: " << app[numOfApp].studentID << endl;


	cout << "\nAvailable Staff Members:\n";
	for (int i = 0; i < numOfStf; i++)
	{
		cout << "[" << i + 1 << "] - " << stf[i].inf.name << " (" << stf[i].department << ")" << endl;
	}

	cout << "\nChoose Staff Member number: ";
	cin >> choice;

	if (choice < 1 || choice > numOfStf)
	{
		cout << "\nInvalid choice! Please try again\n" << endl;
		return;
	}

	app[numOfApp].stfName = stf[choice - 1].inf.name;

	do {
		cout << "Enter Day (1-31): ";
		cin >> app[numOfApp].sch.day;

		if (app[numOfApp].sch.day < 1 || app[numOfApp].sch.day > 31)
		{
			cout << "\nInvalid day! Please enter a value between 1 and 31\n\n";
		}

	} while (app[numOfApp].sch.day < 1 || app[numOfApp].sch.day > 31);


	do {
		cout << "Enter Month (1-12): ";
		cin >> app[numOfApp].sch.month;

		if (app[numOfApp].sch.month < 1 || app[numOfApp].sch.month > 12)
		{
			cout << "\nInvalid month! Please enter a value between 1 and 12\n\n";
		}

	} while (app[numOfApp].sch.month < 1 || app[numOfApp].sch.month > 12);

	do {
		cout << "Enter Hour (8-20): ";
		cin >> app[numOfApp].sch.hour;

		if (app[numOfApp].sch.hour < 8 || app[numOfApp].sch.hour > 20)
		{
			cout << "\nInvalid hour! Working hours are from 8 to 20\n\n";
		}

	} while (app[numOfApp].sch.hour < 8 || app[numOfApp].sch.hour > 20);

	do {
		cout << "Enter Minute (0, 15, 30, 45): ";
		cin >> app[numOfApp].sch.minute;

		if (app[numOfApp].sch.minute != 0 &&
			app[numOfApp].sch.minute != 15 &&
			app[numOfApp].sch.minute != 30 &&
			app[numOfApp].sch.minute != 45)
		{
			cout << "\nInvalid minute! Choose (0, 15, 30, or 45)\n\n";
		}
	} while (app[numOfApp].sch.minute != 0 && app[numOfApp].sch.minute != 15 && app[numOfApp].sch.minute != 30 && app[numOfApp].sch.minute != 45);

	for (int i = 0; i < numOfApp; i++)
	{
		if (app[i].stfName == app[numOfApp].stfName &&
			app[i].sch.day == app[numOfApp].sch.day &&
			app[i].sch.month == app[numOfApp].sch.month &&
			app[i].sch.hour == app[numOfApp].sch.hour &&
			app[i].sch.minute == app[numOfApp].sch.minute)
		{
			cout << "\nThis time slot is already requested for this Staff Member!\n" << endl;
			return;
		}
	}


	cout << "\nAppointment requested successfully with " << stf[choice - 1].position << " " << app[numOfApp].stfName << "!\n" << endl;

	numOfApp++;
}

void calculateGrade(int couIdx, grade& g, course cou[])
{
	float totalMax = cou[couIdx].gr.finalMax + cou[couIdx].gr.quizMax + cou[couIdx].gr.practicalMax + cou[couIdx].gr.yearWorkMax;

	g.total = g.final + g.quiz + g.practical + g.yearWork;

	float percentage = (g.total / totalMax) * 100.0;
	g.percentage = percentage;

	if (percentage >= 97)
		g.letter = "A+";
	else if (percentage < 97 && percentage >= 93)
		g.letter = "A";
	else if (percentage < 93 && percentage >= 89)
		g.letter = "A-";
	else if (percentage < 89 && percentage >= 84)
		g.letter = "B+";
	else if (percentage < 84 && percentage >= 80)
		g.letter = "B";
	else if (percentage < 80 && percentage >= 76)
		g.letter = "B-";
	else if (percentage < 76 && percentage >= 73)
		g.letter = "C+";
	else if (percentage < 73 && percentage >= 70)
		g.letter = "C";
	else if (percentage < 70 && percentage >= 67)
		g.letter = "C-";
	else if (percentage < 67 && percentage >= 64)
		g.letter = "D+";
	else if (percentage < 64 && percentage >= 60)
		g.letter = "D";
	else
		g.letter = "F";
}

/*void setGrades(int stfIndex, int numOfCou, course cou[], student stu[], staff stf[])
{
	int choice;
	int stfCouCount = 0;
	int coursemap[10];

	cout << "\ncourses you teach:\n";

	for (int i = 0; i < numOfCou; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (stf[stfIndex].teachingCourses[j] == cou[i].name)
			{
				cout << "[" << stfCouCount + 1 << "]" << " - " << cou[i].name << endl;
				coursemap[stfCouCount] = i;
				stfCouCount++;
			}
		}
	}

	if (stfCouCount == 0)
	{
		cout << "No Courses Available" << "\n\n";
		return;
	}

	cout << "choose course: ";
	cin >> choice;

	if (choice < 1 || choice > stfCouCount)
	{
		cout << "Invalid Choice! Please try again";
		return;
	}

	int couIdx = coursemap[choice - 1];

	cout << "\n students: \n";
	for (int i = 0; i < cou[couIdx].studentCount; i++)
	{
		int stuIdx = cou[couIdx].enr.studentIndex[i];
		cout << i + 1 << ". " << stu[stuIdx].inf.name << endl;
	}

	int stuChoice;
	cout << "choose student: ";
	cin >> stuChoice;

	if (stuChoice < 1 || stuChoice > cou[couIdx].studentCount)
	{
		cout << "Invaild choice!!\n";
		return;
	}

	int realindex = cou[couIdx].enr.studentIndex[stuChoice - 1];
	grade& g = cou[couIdx].enr.g[stuChoice - 1];

	cout << "\n entering grades for: " << stu[realindex].inf.name << "\n\n";

	cout << "*NOTE* - The total marks for this course are: " << cou[couIdx].gr.total << "\n\n";
	do
	{
		cout << "final (0-" << cou[couIdx].gr.finalMax << "): ";
		cin >> g.final;
	} while (g.final < 0 || g.final > cou[couIdx].gr.finalMax);
	do
	{
		cout << "quiz (0-" << cou[couIdx].gr.quizMax << "): ";
		cin >> g.quiz;
	} while (g.quiz < 0 || g.quiz > cou[couIdx].gr.quizMax);
	do
	{
		cout << "practical (0-" << cou[couIdx].gr.practicalMax << "): ";
		cin >> g.practical;
	} while (g.practical < 0 || g.practical > cou[couIdx].gr.practicalMax);
	do
	{
		cout << "Year Work (0-" << cou[couIdx].gr.yearWorkMax << "): ";
		cin >> g.yearWork;
	} while (g.yearWork < 0 || g.yearWork > cou[couIdx].gr.yearWorkMax);

	calculateGrade(couIdx, g, cou);
	cout << "done!!\n";
	cout << "total: " << g.total << endl;
	cout << "grade: " << g.letter << endl;
}*/

void registerCourses(int numOfCou, int stuIndex)
{
	if (numOfCou == 0) {
		cout << "No Courses available\n" << endl;
		return;
	}

	int count = 0;
	for (int i = 0; i < numOfCou; i++) {
		if (stu[stuIndex].academicYear == cou[i].academicYear)
			count++;
	}

	int cntr = 1;

	cout << "====== Available Courses (" << count << ") ======\n";
	for (int i = 0; i < numOfCou; i++)
	{
		if (stu[stuIndex].academicYear == cou[i].academicYear)
		{
			cout << "[" << cntr++ << "] - " << cou[i].name << endl;
		}
	}

	cout << endl;

	char cont;
	do {
		cin.ignore();
		string regCou;
		cout << "Enter name of Course that you want to register: ";
		getline(cin, regCou);

		bool found = false;
		for (int i = 0; i < numOfCou; i++) {
			if (regCou == cou[i].name && cou[i].academicYear == stu[stuIndex].academicYear)
			{
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "\nCourse is not available! Please try again\n\n";
		}
		else {
			bool alreadyReg = false;
			for (int j = 0; j < 10; j++) {
				if (stu[stuIndex].studentCourses[j] == regCou) {
					cout << "\nAlready registered!\n\n";
					alreadyReg = true;
					break;
				}
			}
			if (!alreadyReg) {
				bool registered = false;
				for (int i = 0; i < 10; i++) {
					if (stu[stuIndex].studentCourses[i] == "") {
						stu[stuIndex].studentCourses[i] = regCou;
						cout << "\nCourse registered successfully!\n\n";
						registered = true;

						for (int j = 0; j < numOfCou; j++) {
							if (cou[j].name == regCou) {
								cou[j].enr.studentIndex[cou[j].studentCount] = stuIndex;
								cou[j].studentCount++;
								break;
							}
						}

						break;
					}
				}
				if (!registered)
					cout << "Maximum courses reached! Cannot register more\n\n";
			}
		}

		do {
			cout << "Do you want to register another course? (Y/N): ";
			cin >> cont;
			cout << endl;

			if (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";

		} while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

		if (cont == 'n' || cont == 'N')
			cout << "Returning to Student Dashboard... \n" << endl;

	} while (cont == 'y' || cont == 'Y');
}

void dropCourses(int stuIndex, int& numOfCou) {

	int count = 0;
	char cont;

	for (int i = 0; i < 10; i++) {
		if (stu[stuIndex].studentCourses[i] != "")
			count++;
	}
	if (count == 0) {
		cout << "No Courses Registered\n\n";
		return;
	}
	cout << "====== Registered Courses (" << count << ") ======\n";
	for (int i = 0; i < 10; i++)
	{
		if (stu[stuIndex].studentCourses[i] != "")
			cout << "[" << i + 1 << "] " << "- " << stu[stuIndex].studentCourses[i] << endl;
	}

	cout << endl;

	do
	{
		cin.ignore();
		string dropCou;
		cout << "Enter name of Course that you want to drop: ";
		getline(cin, dropCou);

		bool found = false;
		for (int i = 0; i < 10; i++) {
			if (stu[stuIndex].studentCourses[i] == dropCou) {

				for (int j = 0; j < numOfCou; j++) {
					if (cou[j].name == dropCou) {
						for (int k = 0; k < cou[j].studentCount; k++) {
							if (cou[j].enr.studentIndex[k] == stuIndex) {
								cou[j].enr.studentIndex[k] = cou[j].enr.studentIndex[cou[j].studentCount - 1];
								cou[j].studentCount--;
								break;
							}
						}
						break;
					}
				}

				for (int j = i; j < 9; j++) {
					stu[stuIndex].studentCourses[j] = stu[stuIndex].studentCourses[j + 1];
					stu[stuIndex].studentCourses[9] = "";
				}
				found = true;
				cout << "\nCourse dropped successfully!\n\n";
				count--;
				break;
			}
		}

		if (!found)
			cout << "\nCourse is not available! Please try again\n\n";

		do {
			cout << "Do you want to drop another course? (Y/N): ";
			cin >> cont;
			cout << endl;

			if (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";

		} while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

		if (cont == 'n' || cont == 'N')
			cout << "Returning to Student Dashboard... \n" << endl;

	} while (cont == 'y' || cont == 'Y');
}

void viewRegCou(int stuIndex) {

	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (stu[stuIndex].studentCourses[i] != "")
			count++;
	}
	if (count == 0) {
		cout << "No Courses Registered\n\n";
		return;
	}

	cout << "====== Registered Courses (" << count << ") ======\n";
	for (int i = 0; i < 10; i++) {
		if (stu[stuIndex].studentCourses[i] != "")
			cout << "[" << i + 1 << "] " << "- " << stu[stuIndex].studentCourses[i] << endl;
	}
	cout << endl;
}


void couRegMenu(int& numOfCou, int stuIndex) {
	int choice;
	do {
		cout << "====== Course Registration ======\n";
		cout << "[1] - Register Courses\n";
		cout << "[2] - View Available Courses\n";
		cout << "[3] - Drop Courses\n";
		cout << "[4] - View Registered Courses\n";
		cout << "[0] - Back\n";
		cout << "---------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1: registerCourses(numOfCou, stuIndex);
			break;
		case 2: availableCourses(numOfCou, stuIndex);
			break;
		case 3: dropCourses(stuIndex, numOfCou);
			break;
		case 4: viewRegCou(stuIndex);
			break;
		case 0: cout << "Returning to Student Dashboard... \n\n";
			return;
		default: cout << "Invalid choice! Please try again\n\n";
		}
	} while (true);
}

void availableCourses(int numOfCou, int stuIndex)
{
	int cntr = 1;
	int count = 0;
	for (int i = 0; i < numOfCou; i++) {
		if (stu[stuIndex].academicYear == cou[i].academicYear)
			count++;
	}

	cout << "====== Available Courses (" << count << ") ======" << endl;
	for (int i = 0; i < numOfCou; i++)
	{
		if (stu[stuIndex].academicYear == cou[i].academicYear)
		{
			cout << "[" << cntr++ << "] - " << cou[i].name << endl;
		}
	}
	cout << endl;
}

void exmMenu(int numOfCou, int& numOfExm, course cou[], exam exm[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Exam Schedule Menu ======" << endl;
			cout << "[1] - Set Exam Schedule" << endl;
			cout << "[2] - View Exam Schedule" << endl;
			cout << "[3] - Remove Exam Schedule" << endl;
			cout << "[0] - Back" << endl;
			cout << "--------------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
				cout << "Invalid choice! Please try again" << "\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

		switch (choice)
		{
		case 1:
			setExamSchedule(numOfCou, numOfExm, cou, exm);
			break;

		case 2:
			viewExamSchedule(numOfCou, numOfExm, cou, exm);
			break;

		case 3:
			removeExamSchedule(numOfCou, numOfExm, cou, exm);
			break;

		case 0:
			cout << "Returning to Administration Dashboard... \n" << endl;
			return;
		}
	} while (true);
}

void setExamSchedule(int numOfCou, int& numOfExm, course cou[], exam exm[])
{
	if (numOfCou == 0)
	{
		cout << "No courses available to set Exam Schedule!\n" << endl;
		return;
	}

	cout << "====== Available Courses (" << numOfCou << ") ======" << endl;
	for (int i = 0; i < numOfCou; i++)
		cout << "[" << i + 1 << "] - " << cou[i].name << endl;
	cout << endl;

	char again;
	do
	{
		int courseChoice;
		do
		{
			cout << "Select a Course (1-" << numOfCou << "): ";
			cin >> courseChoice;

			if (courseChoice < 1 || courseChoice > numOfCou)
				cout << "\nInvalid choice! Please enter a value between 1 and " << numOfCou << "\n\n";

		} while (courseChoice < 1 || courseChoice > numOfCou);

		int idx = courseChoice - 1;

		cout << "\nSetting Exam Schedule for: " << cou[idx].name << endl;
		cout << "-------------------------------" << endl;

		int d, mo, y, h, mi;

		do
		{
			cout << "Enter Exam Day (1-31): ";
			cin >> d;
			if (d < 1 || d > 31) cout << "\nInvalid Day! Please enter a value between 1 and 31\n\n";
		} while (d < 1 || d > 31);

		do
		{
			cout << "Enter Exam Month (1-12): ";
			cin >> mo;
			if (mo < 1 || mo > 12) cout << "\nInvalid Month! Please enter a value between 1 and 12\n\n";
		} while (mo < 1 || mo > 12);

		do
		{
			cout << "Enter Exam Year (2026-2030): ";
			cin >> y;
			if (y < 2026 || y > 2030) cout << "\nInvalid Year! Please enter a value between 2026 and 2030\n\n";
		} while (y < 2026 || y > 2030);

		do
		{
			cout << "Enter Exam Hour (8-20): ";
			cin >> h;
			if (h < 8 || h > 20) cout << "\nInvalid Hour! Please enter a value between 8 and 20\n\n";
		} while (h < 8 || h > 20);

		do
		{
			cout << "Enter Exam Minute (0-59): ";
			cin >> mi;
			if (mi < 0 || mi > 59) cout << "\nInvalid Minute! Please enter a value between 0 and 59\n\n";
		} while (mi < 0 || mi > 59);

		int examIdx = -1;
		for (int i = 0; i < numOfExm; i++) {
			if (exm[i].co.name == cou[idx].name) {
				examIdx = i;
				break;
			}
		}
		if (examIdx == -1) {
			examIdx = numOfExm;
			numOfExm++;
		}

		exm[examIdx].co.name = cou[idx].name;
		exm[examIdx].sch.day = d;
		exm[examIdx].sch.month = mo;
		exm[examIdx].sch.year = y;
		exm[examIdx].sch.hour = h;
		exm[examIdx].sch.minute = mi;

		cout << "\nExam Schedule has been set successfully for " << cou[idx].name << "!\n" << endl;

		do {
			cout << "Do you want to set another Exam Schedule (Y/N): ";
			cin >> again;
			cout << endl;

			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";

		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		if (again == 'n' || again == 'N')
			cout << "Returning to Administration Dashboard... \n" << endl;

	} while (again == 'y' || again == 'Y');
}

void viewExamSchedule(int numOfCou, int numOfExm, course cou[], exam exm[])
{
	if (numOfCou == 0)
	{
		cout << "No courses available!\n" << endl;
		return;
	}

	if (numOfExm == 0)
	{
		cout << "No Exam Schedules have been set yet!\n" << endl;
		return;
	}


	cout << "====== Exam Schedule (" << numOfExm << ") ======" << endl;
	for (int i = 0; i < numOfExm; i++)
	{
			cout << "Course : " << exm[i].co.name << endl;
			cout << "Date   : " << exm[i].sch.day << "/"
				<< exm[i].sch.month << "/"
				<< exm[i].sch.year << endl;

			cout << "Time   : ";
			if (exm[i].sch.hour < 10)   cout << "0";
			cout << exm[i].sch.hour << ":";
			if (exm[i].sch.minute < 10) cout << "0";
			cout << exm[i].sch.minute << endl;

			cout << endl;
		
	}

}


void removeExamSchedule(int numOfCou, int& numOfExm, course cou[], exam exm[])
{
	if (numOfCou == 0)
	{
		cout << "No courses available!\n" << endl;
		return;
	}

	if (numOfExm == 0)
	{
		cout << "No Exam Schedules have been set yet!\n" << endl;
		return;
	}

	char again;
	do
	{
		int cntr = 1;

		cout << "====== Exam Schedule (" << numOfExm << ") ======" << endl;
		for (int i = 0; i < numOfExm; i++)
			if (exm[i].sch.year != 0)
				cout << "[" << cntr++ << "] - " << exm[i].co.name << endl;
		cout << endl;

		int courseChoice;
		do
		{
			cout << "Select a course to remove its Exam Schedule (1-" << cntr-1 << "): ";
			cin >> courseChoice;


			if (courseChoice < 1 || courseChoice > numOfExm)
				cout << "\nInvalid choice! Please try again\n\n";
			else if (exm[courseChoice - 1].sch.year == 0)
				cout << "\nThis Course has no Exam Schedule! Please enter a value between 1 and 12\n\n";

		} while (courseChoice < 1 || courseChoice > numOfExm || exm[courseChoice - 1].sch.year == 0);

		int idx = courseChoice - 1;

		char confirm;
		cout << "Are you sure you want to remove the exam schedule for " << exm[idx].co.name << " (Y/N): ";
		cin >> confirm;

		while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N')
		{
			cout << "\nInvalid choice! Please enter (Y/N)\n";
			cout << "Are you sure you want to remove the exam schedule for " << exm[idx].co.name << " (Y/N): ";
			cin >> confirm;
		}

		
			if (confirm == 'y' || confirm == 'Y') {

				string removedName = exm[idx].co.name;
				for (int i = idx; i < numOfExm - 1; i++)
					exm[i] = exm[i + 1];

				exm[numOfExm - 1].co.name = "";
				exm[numOfExm - 1].sch.day = 0;
				exm[numOfExm - 1].sch.month = 0;
				exm[numOfExm - 1].sch.year = 0;
				exm[numOfExm - 1].sch.hour = 0;
				exm[numOfExm - 1].sch.minute = 0;
				numOfExm--;

				cout << "\nExam schedule for " << removedName << " removed successfully!\n" << endl;
			}
			else if (confirm == 'n' || confirm == 'N') {
				cout << "\nOperation Cancelled! Exam Schedule remains unchanged\n" << endl;
			}
			else
			{
				cout << "\nInvalid choice! Please enter (Y/N)\n";
			}
		
		bool stillHasExams = false;
		for (int i = 0; i < numOfExm; i++)
			if (exm[i].sch.year != 0)
			{
				stillHasExams = true;
				break;
			}

		if (!stillHasExams)
		{
			cout << "No more exam schedules to remove.\n" << endl;
			return;
		}

		do
		{
			cout << "Do you want to remove another exam schedule? (Y/N): ";
			cin >> again;
			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "\nInvalid choice! Please enter (Y/N)\n";
			if (again == 'n' || again == 'N')
			cout << "\nReturning to Administration Dashboard... " << endl;
		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		cout << endl;

	} while (again == 'y' || again == 'Y');
}
