#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
const int SIZE = 100;
int choice;
long long int idCounter = 100000;

struct information {
	long long int id;
	string name;
	long long int mobileNumber;
	string password;
};

struct student {
	information inf;
	string department;
	int academicYear;
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

struct grade
{
	float total;
	float final;
	float practical;
	float yearWork;
	float quiz;
};

struct course
{
	string name;
	grade gr;
	string academicMemberName;
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
}exm[SIZE];

struct appointment
{
	schedule sch;
}app[SIZE];

void signUp(int, int&, int&, int&, student[], staff[], administration[]);
void signIn(int, int, int, int, int&, student[], staff[], administration[]);
void addCourse(int&, course[]);
void viewCourses(int, course[]);
void removeCourse(int&, course[]);
void selectCourse(int, staff[]);
void stuMenu();
void stfMenu(int);
void admMenu(int&, course[]);
long long int generateID();
string getPassword();

int main()
{
	int choice;
	int numOfStu = 0;
	int numOfStf = 0;
	int numOfAdm = 0;
	int numOfCou = 0;

	do
	{
	cout << "====== College Management System ======" << endl;
	cout << "[1] - Sign Up" << endl;
	cout << "[2] - Sign In" << endl;
	cout << "[0] - Exit" << endl;
	cout << "-------------------------------------------\n";
	cout << "Enter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		signUp(choice,numOfStu, numOfStf, numOfAdm, stu, stf, adm);
		break;
	case 2:
		signIn(choice, numOfStu, numOfStf, numOfAdm, numOfCou, stu, stf, adm);
		break;
	case 0:
		cout << "Exiting..." << endl;
		return 0;
	default:
		cout << "Invalid choice! Please try again." << endl;
		break;
	}
	} while (true);
}

void signUp(int choice,int& numOfStu, int& numOfstf, int& numOfAdm, student stu[], staff stf[], administration adm[]) {
		cout << "====== Sign Up Menu ======\n";
	do {
		cout << "Choose your role:\n";
		cout << "[1] - Student\n";
		cout << "[2] - Academic Staff Member\n";
		cout << "[3] - Administration Member\n";
		cout << "[0] - Back\n";
		cout << "-------------------------------------------\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
			cout << "Invalid choice! Please try again.\n";
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

	cin.ignore();

	switch (choice) {
	case 1:
		stu[numOfStu].inf.id = generateID();
		cout << "Your generated ID: " << stu[numOfStu].inf.id << endl;
		cout << "Enter your full name (3 parts): ";
		getline(cin, stu[numOfStu].inf.name);
		cout << "Enter your mobile number: "; cin >> stu[numOfStu].inf.mobileNumber;
		cout << "Enter your password: "; cin >> stu[numOfStu].inf.password;
		cout << "Enter your department: "; cin >> stu[numOfStu].department;
		cout << "Enter your academic year: "; cin >> stu[numOfStu].academicYear;
		cout << "\nStudent registered successfully!\n";
		numOfStu++;
		break;

	case 2:
		stf[numOfstf].inf.id = generateID();
		cout << "Your generated ID: " << stf[numOfstf].inf.id << endl;
		cout << "Enter your full name (3 parts): ";
		getline(cin, stf[numOfstf].inf.name);
		cout << "Enter your mobile number: "; cin >> stf[numOfstf].inf.mobileNumber;
		cout << "Enter your password: "; cin >> stf[numOfstf].inf.password;
		cout << "Enter your department: "; cin >> stf[numOfstf].department;
		cout << "Enter your position: "; cin >> stf[numOfstf].position;
		cout << "\nStaff member registered successfully!\n";
		numOfstf++;
		break;

	case 3:
		adm[numOfAdm].inf.id = generateID();
		cout << "Your generated ID is: " << adm[numOfAdm].inf.id << endl;
		cout << "Enter your full name: ";
		getline(cin, adm[numOfAdm].inf.name);
		cout << "Enter your mobile number: "; cin >> adm[numOfAdm].inf.mobileNumber;
		cout << "Enter your password: "; cin >> adm[numOfAdm].inf.password;
		cout << "Enter your position: "; cin >> adm[numOfAdm].position;
		cout << "\nAdministration member registered successfully!\n";
		numOfAdm++;
		break;

	case 0: return;
	}
}

long long int generateID() {
	return idCounter++;
}

void signIn(int choice, int numOfStu, int numOfStf, int numOfAdm, int& numOfCou, student stu[], staff stf[], administration adm[])
{
    do {
		cout << "====== Sign In Menu ======" << endl;
        cout << "Choose your role:\n";
		cout << "[1] - Student\n";
		cout << "[2] - Academic Staff Member\n";
		cout << "[3] - Administration Member\n";
		cout << "[0] - Back\n";
		cout << "-------------------------------------------\n";
		cout << "Enter your choice: ";
		cin >> choice;

        if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
            cout << "Invalid choice! Please try again.\n";

    } while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

	if (choice == 0) return;

    int tempID;
    cout << "Enter your ID: ";
    cin >> tempID;

    int trials = 3;
    bool loggedIn = false;

    while (trials > 0 && !loggedIn)
    {
        cout << "Enter password: ";
        string tempPass;
		cin.ignore();
		getline(cin,tempPass);

        switch (choice)
        {
        case 1:
            for (int i = 0; i < numOfStu; i++)
            {
                if (stu[i].inf.id == tempID && stu[i].inf.password == tempPass)
                {
                    cout << "Welcome " << stu[i].inf.name << endl;
                    loggedIn = true;
					stuMenu();
                    break;
                }
            }
            break;

        case 2:
            for (int i = 0; i < numOfStf; i++)
            {
                if (stf[i].inf.id == tempID && stf[i].inf.password == tempPass)
                {
                    cout << "Welcome " << stf[i].inf.name << endl;
                    loggedIn = true;
					stfMenu(i);
                    break;
                }
            }
            break;

        case 3:
            for (int i = 0; i < numOfAdm; i++)
            {
                if (adm[i].inf.id == tempID && adm[i].inf.password == tempPass)
                {
                    cout << "Welcome " << adm[i].inf.name << endl;
                    loggedIn = true;
					admMenu(numOfCou, cou);
                    break;
                }
            }
            break;
        }

        if (!loggedIn)
        {
            trials--;
            if (trials > 0)
                cout << "\nWrong password! You have " << trials << " trial(s) left.\n";
            else
            {
                cout << "\nWrong password! You have no trials left.\n";
                return;
            }	
        }
    }
}

string getPassword()
{
	string password = "";
	char ch;

	while ((ch = getch()) != '\r')
	{
		password += ch;
		cout << '*';
	}
	cout << endl;
	return password;
}

void stuMenu()
{
	do
	{
	cout << "====== Student Dashboard ======" << endl;
	cout << "[1] - Course Registration" << endl;
	cout << "[2] - Request Grades" << endl;
	cout << "[3] - Request Appointment with Staff Members" << endl;
	cout << "[0] - Logout" << endl;
	cout << "-------------------------------------------\n";
	cout << "Enter your choice: ";
	cin >> choice;

	if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
        cout << "Invalid choice! Please try again\n";

    } while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

	switch (choice)
	{
	case 1:
		/* Student Add Courses func */
		break;
	
	case 2:
		/* Student Request grades func */
		break;
	
	case 3:
		/* Student Request Appoi. func */
		break;

	case 0:
		return;
	}
}

void stfMenu(int stfIndex)
{
do
	{
	cout << "====== Staff Dashboard ======" << endl;
	cout << "[1] - Set Grades" << endl;
	cout << "[2] - View Appointments" << endl;
	cout << "[3] - Select Courses to Teach" << endl;
	cout << "[0] - Logout" << endl;
	cout << "-------------------------------------------\n";
	cout << "Enter your choice: ";
	cin >> choice;

	if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
        cout << "Invalid choice! Please try again\n";

    } while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

	switch (choice)
	{
	case 1:

		break;
	
	case 2:
		break;
	
	case 3:
		selectCourse(stfIndex, stf);
		break;

	case 0:
		return;
	}
}

void admMenu(int &numOfCou, course cou[])
{
	do
	{
	cout << "====== Administration Dashboard ======" << endl;
	cout << "[1] - Add Course" << endl;
	cout << "[2] - Remove Course" << endl;
	cout << "[3] - View Courses" << endl;
	cout << "[4] - Add Course Schedule" << endl;
	cout << "[5] - Add Exam Schedule" << endl;
	cout << "[0] - Logout" << endl;
	cout << "-------------------------------------------\n";
	cout << "Enter your choice: ";
	cin >> choice;

	if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 0)
        cout << "Invalid choice! Please try again\n";

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

	case 4:
		/* Admin Add Course Schedules func */
		break;
	
	case 5:
		/* Admin Add Exam Schedule func */
		break;

	case 0:
		return;
	}
}

void addCourse(int &numOfCou, course cou[])
{
	char cont;

	do {
		do
		{
			cin.ignore();
			cout << "Enter Course Name: ";
			getline(cin, cou[numOfCou].name);

			cout << "Enter Course Total Marks: ";
			cin >> cou[numOfCou].gr.total;

			cout << "Enter Course Final Marks: ";
			cin >> cou[numOfCou].gr.final;

			cout << "Enter Course Practical Marks: ";
			cin >> cou[numOfCou].gr.practical;

			cout << "Enter Course Year Work Marks: ";
			cin >> cou[numOfCou].gr.yearWork;

			cout << "Enter Course Quiz Marks: ";
			cin >> cou[numOfCou].gr.quiz;

			if (cou[numOfCou].gr.total != cou[numOfCou].gr.final + cou[numOfCou].gr.practical + cou[numOfCou].gr.yearWork + cou[numOfCou].gr.quiz)
				cout << "\nInvalid Total Marks! Please Try Again." << endl;
			
		} while (cou[numOfCou].gr.total != cou[numOfCou].gr.final + cou[numOfCou].gr.practical + cou[numOfCou].gr.yearWork + cou[numOfCou].gr.quiz);

		numOfCou++;

		cout << "\nDo you want to enter another course ? (y/n): ";
		cin >> cont;

	} while (cont == 'y' || cont == 'Y');
}

void viewCourses(int numOfCou,course cou[])
{
	cout << "====== Courses ======" << endl;
	for (int j = 0; j < numOfCou; j++)
	{
		cout << "Course " << "[" << j + 1 << "]" << endl;

		cout << "Name: " << cou[j].name << endl;
		cout << "Total Marks: " << cou[j].gr.total << endl;
		cout << "Final Marks: " << cou[j].gr.final << endl;
		cout << "Practical Marks: " << cou[j].gr.practical << endl;
		cout << "Year Work Marks: " << cou[j].gr.yearWork << endl;
		cout << "Quiz Marks: " << cou[j].gr.quiz << endl;

		cout << "\n-\n";
	}
}

void removeCourse(int &numOfCou, course cou[])
{
	string remCourse;
	cout << "Enter Course you want to remove: ";
	cin.ignore();
	getline(cin,remCourse);

	for (int i = 0; i < numOfCou; i++)
	{
		if (remCourse == cou[i].name)
		{
            for (int j = i; j < numOfCou - 1; j++)
            {
                cou[j] = cou[j + 1];
            }
            numOfCou--;
            cout << "Course removed successfully!\n";
            return;
		}
        }
    }

void selectCourse(int stfIndex, staff stf[])
{
	int courseCount = 0;
	cout << "Enter your teaching courses (press 'Enter' to finish): ";
		string temp;
		cin.ignore();
		for (int courseCount = 0; courseCount < 10; courseCount++)
		{
    		getline(cin, temp);
    		if (temp == "") break;
    		stf[stfIndex].teachingCourses[courseCount] = temp;
		}
		cout << "Courses added successfully!" << endl;
}
