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
	string mobileNumber;
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
void signIn(int, int, int, int, int&, student[], staff[], administration[], course[]);
void addCourse(int&, course[]);
void viewCourses(int, course[]);
void removeCourse(int&, course[]);
void selectCourse(int, staff[]);
void stuMenu();
void stfMenu(int);
void admMenu(int&, course[]);
void couMenu(int, course[]);
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
	cout << "---------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		signUp(choice,numOfStu, numOfStf, numOfAdm, stu, stf, adm);
		break;
	case 2:
		signIn(choice, numOfStu, numOfStf, numOfAdm, numOfCou, stu, stf, adm, cou);
		break;
	case 0:
		cout << "Exiting..." << endl;
		return 0;
	default:
		cout << "Invalid choice! Please try again." << "\n\n";
		break;
	}
	} while (true);
}

void signUp(int choice,int& numOfStu, int& numOfStf, int& numOfAdm, student stu[], staff stf[], administration adm[]) {
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
		cout << "\nYour generated ID: " << stu[numOfStu].inf.id << endl;
		cout << "Enter your full name: "; getline(cin, stu[numOfStu].inf.name);
		cout << "Enter your mobile number: "; getline(cin, stu[numOfStu].inf.mobileNumber);
		cout << "Enter your password: "; getline(cin, stu[numOfStu].inf.password);
		cout << "Enter your department: "; getline(cin,stu[numOfStu].department);
		cout << "Enter your academic year ([1], [2], [3], [4]): "; cin >> stu[numOfStu].academicYear;
		cout << "\nStudent registered successfully!\n" << endl;
		numOfStu++;
		break;

	case 2:
		stf[numOfStf].inf.id = generateID();
		cout << "Your generated ID: " << stf[numOfStf].inf.id << endl;
		cout << "Enter your full name: "; getline(cin, stf[numOfStf].inf.name);
		cout << "Enter your mobile number: "; getline(cin,adm[numOfStf].inf.mobileNumber);
		cout << "Enter your password: "; getline(cin,stf[numOfStf].inf.password);
		cout << "Enter your department: "; getline(cin,stf[numOfStf].department);
		cout << "Enter your position: "; getline(cin,stf[numOfStf].position);
		cout << "\nStaff member registered successfully!\n" << endl;
		numOfStf++;
		break;

	case 3:
		adm[numOfAdm].inf.id = generateID();
		cout << "Your generated ID is: " << adm[numOfAdm].inf.id << endl;
		cout << "Enter your full name: "; getline(cin, adm[numOfAdm].inf.name);
		cout << "Enter your mobile number: "; getline(cin,adm[numOfAdm].inf.mobileNumber);
		cout << "Enter your password: "; getline(cin, adm[numOfAdm].inf.password);
		cout << "Enter your position: "; getline(cin,adm[numOfAdm].position);
		cout << "\nAdministration member registered successfully!\n" << endl;
		numOfAdm++;
		break;

	case 0:
		cout<< "Returning to the Main Menu... \n"<< endl;
		return;
	}
}

long long int generateID() {
	return idCounter++;
}

void signIn(int choice, int numOfStu, int numOfStf, int numOfAdm, int& numOfCou, student stu[], staff stf[], administration adm[], course cou[])
{
     do {
        cout << "====== Sign In Menu ======" << endl;
        cout << "Choose your role:\n";
        cout << "[1] - Student\n";
        cout << "[2] - Academic Staff Member\n";
        cout << "[3] - Administration Member\n";
        cout << "[0] - Back\n";
        cout << "--------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
            cout << "Invalid choice! Please try again" << "\n\n";

    } while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

    if (choice == 0)
	{
		cout<< "Returning to the Main Menu... \n"<< endl;
		return;
	}
    int tempID;
    cout << "Enter your ID: ";
    cin >> tempID;
    bool idFound = false;
    int userIndex = -1;

    switch (choice)
    {
    case 1:
        for (int i = 0; i < numOfStu; i++)
            if (stu[i].inf.id == tempID)
			{
				idFound = true;
				userIndex = i;
				break;
			}
        break;
    case 2:
        for (int i = 0; i < numOfStf; i++)
            if (stf[i].inf.id == tempID)
			{
				idFound = true;
				userIndex = i;
				break;
			}
        break;
    case 3:
        for (int i = 0; i < numOfAdm; i++)
            if (adm[i].inf.id == tempID)
			{
				idFound = true;
				userIndex = i;
				break;
			}
        break;
    }

    if (!idFound)
    {
        cout << "\nID Not Found! Please try again\n" << endl;
        return;
    }

    int trials = 3;
    bool loggedIn = false;

    while (trials > 0 && !loggedIn)
    {
        cout << "Enter password: ";
        string tempPass = getPassword();

        switch (choice)
        {
        case 1:
            if (stu[userIndex].inf.password == tempPass)
            {
                cout << "\nWelcome, " << stu[userIndex].inf.name << "\n\n";
                loggedIn = true;
                stuMenu();
            }
            break;

        case 2:
            if (stf[userIndex].inf.password == tempPass)
            {
                cout << "\nWelcome, " << stf[userIndex].inf.name << "\n\n";
                loggedIn = true;
                stfMenu(userIndex);
            }
            break;

        case 3:
            if (adm[userIndex].inf.password == tempPass)
            {
                cout << "\nWelcome, " << adm[userIndex].inf.name << "\n\n";
                loggedIn = true;
                admMenu(numOfCou, cou);
            }
            break;
        }

        if (!loggedIn)
        {
            trials--;
            if (trials > 0)
                cout << "\nWrong password! You have " << trials << " trial(s) left.\n\n";
            else
			{
                cout << "\nWrong password! You have no trials left, Returning to the Main Menu...\n\n";
				return;
			}
        }
    }
}

string getPassword() {
    string password = "";
    char ch;

    while ((ch = getch()) != 13) // 13 == '/r' == Enter
	{ 
        if (ch == 8) // 8 == Backspace
		{ 
            if (!password.empty())
			{
                password.pop_back();
                cout << "\b \b";
            }
        }
        else
		{
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

void stuMenu()
{
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
		cout<< "Returning to the Main Menu... \n"<< endl;
		return;
	}
} while (true);
}

void stfMenu(int stfIndex)
{
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
			selectCourse(stfIndex, stf);
			break;

		case 0:
			cout<< "Returning to the Main Menu... \n"<< endl;
			return;
		}
	} while (true);
}

void admMenu(int &numOfCou, course cou[])
{
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
			/* Admin Add Exam Schedule func */
			break;

		case 0:
			cout<< "Returning to the Main Menu... \n"<< endl;
			return;
		}
	} while (true);
}

void addCourse(int &numOfCou, course cou[])
{
	char cont;

	do {
		if (numOfCou >= SIZE)
        {
            cout << "\nMaximum number of courses reached!\n" << endl;
            return;
        }
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
				cout << "\nInvalid Total Marks! Please Try Again\n" << endl;
			
		} while (cou[numOfCou].gr.total != cou[numOfCou].gr.final + cou[numOfCou].gr.practical + cou[numOfCou].gr.yearWork + cou[numOfCou].gr.quiz);

		numOfCou++;

		do {
            cout << "\nDo you want to enter another course? (y/n)";
            cin >> cont;
			cout << endl;

            if (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N')
                cout << "\nInvalid choice! Please enter (y/n)\n";

        } while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

        if (cont == 'n' || cont == 'N')
            cout << "\nCourse(s) added successfully!\n" << endl;

	} while (cont == 'y' || cont == 'Y');
}

void viewCourses(int numOfCou,course cou[])
{
	if(numOfCou == 0)
	{
		cout << "No Courses available\n" << endl;
		return;
	}
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

		cout << endl;
	}
}

void removeCourse(int &numOfCou, course cou[])
{
	if(numOfCou == 0)
	{
		cout << "No Courses available\n" << endl;
		return;
	}

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
            cout << "\nCourse removed successfully!\n\n";
            return;
		}
        }

		cout << "\nCourse doesn't Exist, Please try again\n" << endl;
		return;
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

void couMenu(int numOfCou, course cou[])
{
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

		case 0:
			cout<< "Returning to Administration Dashboard... \n"<< endl;
			return;
		}
	} while (true);
}
