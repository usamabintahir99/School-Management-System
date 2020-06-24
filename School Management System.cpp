#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

struct student
{
	string fname;
	string lname;
	string rollNumber;
	string classes;
	string address;
	string contact;
	string sub[6];
	string teach[6];

}studentData;

struct teacher
{
	string fst_name;
	string lst_name;
	string qualification;
	string exp;
	string pay;
	string subj;
	string lec;
	string addrs;
	string cel_no; 
	string blod_grp; 
	string year;
	string classes;

}teacherData;

struct login
{
	string username;
	string password;
};

void main()
{
main:

	system("cls");

	cout << "\t\t\t\t*****************************************";
	cout << "\n\t\t\t\t*\tSCHOOL MANAGEMENT SYSTEM\t*\n";
	cout << "\t\t\t\t*****************************************";
	cout << "\n\n\t\t\t\t\t\tMAIN SCREEN\n\n";
	cout << "Which section do tou want to go: " << endl << endl;
	cout << "1.Students Information" << endl;
	cout << "2.Teacher Information" << endl;
	cout << "3.Exit Program" << endl << endl;

	int choice = 0;

	cout << "Enter your choice: ";
	cin >> choice;

	if (choice == 1)
	{
	smain:
		system("cls");

		cout << "\t\t\tSTUDENTS INFORMATION AND BIO DATA SECTION\n\n\n";
		cout << "Which section do you want to go: " << endl << endl;
		cout << "1.Create a new entry\n";
		cout << "2.Find and display an entry\n";
		cout << "3.Edit an entry\n";
		cout << "4.Delete an entry\n";
		cout << "5.Jump to main\n";

		int schoice = 0;

		cout<<endl << "Enter your choice: ";
		cin >> schoice;

		if (schoice == 1)
		{
		sentery:

			system("cls");

			cin.ignore();

			cout << "Enter first name of student: ";
			getline(cin, studentData.fname);

			cout << "Enter last name of student: ";
			getline(cin, studentData.lname);

			cout << "Enter roll number of student: ";
			getline(cin, studentData.rollNumber);

			cout << "Enter class of student: ";
			getline(cin, studentData.classes);

			cout << "Enter contact number: ";
			getline(cin, studentData.contact);

			cout << "Enter address: ";
			getline(cin, studentData.address);

			for (int x = 0; x < 6; x++)
			{
				cout<<endl << "Enter name of subject #"<<x+1<<": ";
				getline(cin, studentData.sub[x]);

				cout << "Enter name of teacher who teaches subject #" << x+1 << ": ";
				getline(cin, studentData.teach[x]);

			}

			ofstream ostu("student.txt", ios::app);

			ostu << studentData.fname << endl;
			ostu << studentData.lname << endl;
			ostu << studentData.rollNumber << endl;
			ostu << studentData.classes << endl;
			ostu << studentData.contact << endl;
			ostu << studentData.address << endl;
			for (int x = 0; x < 6; x++)
			{
				ostu << studentData.sub[x]<<endl;
				ostu << studentData.teach[x]<<endl;
			}
			ostu.close();

			cout<< "New Record is successfully saved." << endl<<endl;

			char aent;
			cout << "Do you want to enter another entery [Y] or [N]" << endl;
			cin >> aent;

			if (aent == 'Y' || aent == 'y')
			{
				goto sentery;
			}
			else if (aent == 'N' || aent == 'n')
			{
				cout <<endl << "1.Do you want to go back" << endl;
				cout << "2.Do you want to go to main screen" << endl;
				cout << "3.Do you want to exit" << endl<<endl;
				cout << "Enter your choice: ";
				int sc = 0;

				cin >> sc;

				if (sc == 1)
				{
					goto smain;
				}
				else if (sc == 2)
				{
					goto main;
				}
				else
				{
					exit(0);
				}

			}

		}

		else if (schoice == 2)
		{
			sfind:

			system("cls");
			string rn;

			cout << "Enter roll number of student" << endl;
			cin >> rn;

			ifstream istu("student.txt");

			if (istu.fail())
			{
				cout << "Error in loading file" << endl;
			}
			else
			{
				int notfound = 0;

				while (!istu.eof())
				{
					getline(istu, studentData.fname);
					getline(istu, studentData.lname);
					getline(istu, studentData.rollNumber);
					getline(istu, studentData.classes);
					getline(istu, studentData.contact);
					getline(istu, studentData.address);

					for (int x = 0; x < 6; x++)
					{
						getline(istu, studentData.sub[x]);
						getline(istu, studentData.teach[x]);
					}

					if (rn == studentData.rollNumber)
					{
						notfound = 1;

						cout<<endl << "First name of student: ";
						cout << studentData.fname;
						cout << endl;

						cout << "Last name of student: ";
						cout << studentData.lname;
						cout << endl;

						cout << "Roll Number of student: ";
						cout << studentData.rollNumber;
						cout << endl;

						cout << "Class of student: ";
						cout << studentData.classes;
						cout << endl;

						cout << "Contact number of student: ";
						cout << studentData.contact;
						cout << endl;

						cout << "Address of student: ";
						cout << studentData.address;
						cout << endl << endl;


						cout << "Subjects\t\tTeachers" << endl;
						for (int x = 0; x < 6; x++)
						{
							cout << studentData.sub[x] << "\t\t\t" << studentData.teach[x] << endl;
						}
						cout << endl;

						break;
					}

				}


				if (notfound == 0)
				{
					cout << "Record does not found" << endl;
				}

				istu.close();

				cout << "Do you want to find another entery  [Y] or [N]" << endl;
		
				char fc;
				cin >> fc;

				if (fc == 'Y' || fc=='y')
				{
					goto sfind;
				}

				else if (fc == 'N' || fc == 'n')
				{
					cout << endl << "1.Do you want to go back" << endl;
					cout << "2.Do you want to go to main screen" << endl;
					cout << "3.Do you want to exit" << endl<<endl;
					cout << "Enter your choice: ";
					int sc = 0;
					cin >> sc;
					
					if (sc == 1)
					{
						goto smain;
					}
				    else if (sc == 2)
				    {
					    goto main;
				    }
				    else
				    {
					    exit(0);
				    }

				}

			}

		}
		else if (schoice == 3)
		{
		    estu:

			system("cls");

			string rnumber;
			cout << "Enter roll number of student: ";
			cin >> rnumber;

			ifstream iestu("student.txt");

			if (iestu.fail())
			{
				cout << "Error in loading file" << endl;
			}
			else
			{
				int i = 0;
				string str;

				while (!iestu.eof())
				{
					getline(iestu, str);
					i++;
				}

				iestu.close();

				ifstream iestu("student.txt");

				for (int j = 0; j < i / 18; j++)
				{
					getline(iestu, studentData.fname);
					getline(iestu, studentData.lname);
					getline(iestu, studentData.rollNumber);
					getline(iestu, studentData.classes);
					getline(iestu, studentData.contact);
					getline(iestu, studentData.address);

					for (int x = 0; x < 6; x++)
					{
						getline(iestu, studentData.sub[x]);
						getline(iestu, studentData.teach[x]);
					}


					if (rnumber != studentData.rollNumber)
					{
						ofstream oestu("temp.txt", ios::app);

						oestu << studentData.fname << endl;
						oestu << studentData.lname << endl;
						oestu << studentData.rollNumber << endl;
						oestu << studentData.classes << endl;
						oestu << studentData.contact << endl;
						oestu << studentData.address << endl;
						for (int x = 0; x < 6; x++)
						{
							oestu << studentData.sub[x] << endl;
							oestu << studentData.teach[x] << endl;
						}
						oestu.close();

					}

					else if (rnumber == studentData.rollNumber)
					{
						cout << endl << "Enter new data: " << endl << endl;

						cin.ignore();

						cout << "Enter first name of student: ";
						getline(cin, studentData.fname);

						cout << "Enter last name of student: ";
						getline(cin, studentData.lname);

						cout << "Enter roll number of student: ";
						getline(cin, studentData.rollNumber);

						cout << "Enter class of student: ";
						getline(cin, studentData.classes);

						cout << "Enter contact number: ";
						getline(cin, studentData.contact);

						cout << "Enter address: ";
						getline(cin, studentData.address);

						for (int x = 0; x < 6; x++)
						{
							cout<<endl << "Enter name of subject #" << x+1 << ": ";
							getline(cin, studentData.sub[x]);

							cout << "Enter name of teacher who teaches subject #" << x+1 << ": ";
							getline(cin, studentData.teach[x]);

						}


						ofstream oestu("temp.txt", ios::app);

						oestu << studentData.fname << endl;
						oestu << studentData.lname << endl;
						oestu << studentData.rollNumber << endl;
						oestu << studentData.classes << endl;
						oestu << studentData.contact << endl;
						oestu << studentData.address << endl;
						for (int x = 0; x < 6; x++)
						{
							oestu << studentData.sub[x] << endl;
							oestu << studentData.teach[x] << endl;
						}
						oestu.close();

						cout << "Your entery has been succesfully edited." << endl;

					}

				}
				
				iestu.close();
				remove("student.txt");
				rename("temp.txt", "student.txt");

			}

			cout<<endl << "Do you want to edit another entery [Y] or [N]" << endl;

			char rch;
			cin >> rch;

			if (rch == 'Y' || rch == 'y')
			{
				goto estu;
			}
			else if (rch == 'N' || rch == 'n')
			{
				cout<< endl << "1.Do you want to go back" << endl;
				cout << "2.Do you want to go to main screen" << endl;
				cout << "3.Do you want to exit" << endl;
				cout<<endl << "Enter your choice: ";

				int sc = 0;

				cin >> sc;

				if (sc == 1)
				{
					goto smain;
				}
				else if (sc == 2)
				{
					goto main;
				}
				else
				{
					exit(0);
				}

			}


		}

		else if (schoice == 4)
		{
		  dstu:

			system("cls");

			string rnumber;
			cout << "Enter roll number of student: ";
			cin >> rnumber;

			ifstream iestu("student.txt");

			if (iestu.fail())
			{
				cout << "Error in loading file" << endl;
			}
			else
			{
				int i = 0;
				string str;

				while (!iestu.eof())
				{
					getline(iestu, str);
					i++;
				}

				iestu.close();

				ifstream iestu("student.txt");

				for (int j = 0; j < i / 18; j++)
				{
					getline(iestu, studentData.fname);
					getline(iestu, studentData.lname);
					getline(iestu, studentData.rollNumber);
					getline(iestu, studentData.classes);
					getline(iestu, studentData.contact);
					getline(iestu, studentData.address);

					for (int x = 0; x < 6; x++)
					{
						getline(iestu, studentData.sub[x]);
						getline(iestu, studentData.teach[x]);
					}


					if (rnumber != studentData.rollNumber)
					{
						ofstream oestu("temp.txt", ios::app);

						oestu << studentData.fname << endl;
						oestu << studentData.lname << endl;
						oestu << studentData.rollNumber << endl;
						oestu << studentData.classes << endl;
						oestu << studentData.contact << endl;
						oestu << studentData.address << endl;
						for (int x = 0; x < 6; x++)
						{
							oestu << studentData.sub[x] << endl;
							oestu << studentData.teach[x] << endl;
						}
						oestu.close();

					}

				}

				iestu.close();
				remove("student.txt");
				rename("temp.txt", "student.txt");

			}

			cout << "Your entery has been succesfully deleted." << endl;

			cout << endl << "Do you want to delete another entery [Y] or [N]" << endl;

			char rch;
			cin >> rch;

			if (rch == 'Y' || rch == 'y')
			{
				goto dstu;
			}
			else if (rch == 'N' || rch == 'n')
			{
				cout << endl << "1.Do you want to go back" << endl;
				cout << "2.Do you want to go to main screen" << endl;
				cout << "3.Do you want to exit" << endl;
				cout << endl << "Enter your choice: ";

				int sc = 0;

				cin >> sc;

				if (sc == 1)
				{
					goto smain;
				}
				else if (sc == 2)
				{
					goto main;
				}
				else
				{
					exit(0);
				}

			}

		}

		else if (schoice == 5)
		{
			goto main;
		}

	}

	else if (choice == 2)
	{
		tmain:

		system("cls");

		cout << "\t\t\tTEACHERS INFORMATION AND BIODATA SECTION\n\n\n";
		cout << "Which section do you want to go: " << endl << endl;
		cout << "1.Create a new entry\n";
		cout << "2.Find and display an entry\n";
		cout << "3.Edit an entry\n";
		cout << "4.Delete an entry\n";
		cout << "5.Jump to main\n";

		int tchoice = 0;

		cout<<endl << "Enter your choice: ";
		cin >> tchoice;

		if (tchoice == 1)
		{
		tentery:

			system("cls");

			cin.ignore();

			cout << "Enter first name of teacher: ";
			getline(cin, teacherData.fst_name);

			cout << "Enter last name of teacher: ";
			getline(cin, teacherData.lst_name);

			cout << "Enter qualification of teacher: ";
			getline(cin, teacherData.qualification);

			cout << "Enter experience (in year) of teacher: ";
			getline(cin, teacherData.exp);

			cout << "Enter number of year in this school: ";
			getline(cin, teacherData.year);

			cout << "Enter which subject he/she teaches: ";
			getline(cin, teacherData.subj);

			cout << "Enter number of Lecture (per week): ";
			getline(cin, teacherData.lec);

			cout << "Enter pay of teacher: ";
			getline(cin, teacherData.pay);

			cout << "Enter phone number of teacher: ";
			getline(cin, teacherData.cel_no);

			cout << "Enter blood group of teacher: ";
			getline(cin,teacherData.blod_grp);


			ofstream oteach("teacher.txt", ios::app);

			oteach << teacherData.fst_name << endl;
			oteach << teacherData.lst_name << endl;
			oteach << teacherData.qualification << endl;
			oteach << teacherData.exp << endl;
			oteach << teacherData.year << endl;
			oteach << teacherData.subj << endl;
			oteach << teacherData.lec << endl;
			oteach << teacherData.pay << endl;
			oteach << teacherData.cel_no << endl;
			oteach << teacherData.blod_grp << endl;

			oteach.close();

			char tent;
			cout << "Do you want to enter another entery [Y] or [N]" << endl;
			cin >> tent;

			if (tent == 'Y' || tent == 'y')
			{
				goto tentery;
			}
			else if (tent == 'N' || tent == 'n')
			{
				cout << "1.Do you want to go back" << endl;
				cout << "2.Do you want to go to main screen" << endl;
				cout << "3.Do you want to exit" << endl;
				cout << endl << "Enter your choice: ";
				int sc = 0;

				cin >> sc;

				if (sc == 1)
				{
					goto tmain;
				}
				else if (sc == 2)
				{
					goto main;
				}
				else
				{
					exit(0);
				}

			}

		}

		else if (tchoice == 2)
		{
			tfind:

			system("cls");
			string fn,ln;

			cin.ignore();

			cout << "Enter first name of teacher" << endl;
			getline(cin,fn);

			cout << "Enter last name of teacher" << endl;
			getline(cin,ln);


			ifstream iteach("teacher.txt");

			if (iteach.fail())
			{
				cout << "Error in loading file" << endl;
			}
			else
			{
				int notfound = 0;

				while (!iteach.eof())
				{
					getline(iteach, teacherData.fst_name);
					getline(iteach, teacherData.lst_name);
					getline(iteach, teacherData.qualification);
					getline(iteach, teacherData.exp);
					getline(iteach, teacherData.year);
					getline(iteach, teacherData.subj);
					getline(iteach, teacherData.lec);
					getline(iteach, teacherData.pay);
					getline(iteach, teacherData.cel_no);
					getline(iteach, teacherData.blod_grp);

					if (fn == teacherData.fst_name && ln == teacherData.lst_name )
					{
						notfound = 1;

						cout << "First name of teacher: ";
						cout << teacherData.fst_name;
						cout << endl;

						cout << "Last name of teacher: ";
						cout << teacherData.lst_name;
						cout << endl;

						cout << "Qualification of teacher: ";
						cout << teacherData.qualification;
						cout << endl;

						cout << "Experience of teacher: ";
						cout << teacherData.exp;
						cout << endl;

						cout << "Number of year in this School: ";
						cout << teacherData.year;
						cout << endl;

						cout << "Subject he/she teaches in this School: ";
						cout << teacherData.subj;
						cout << endl;

						cout << "Number of lectures (per week) in this School: ";
						cout << teacherData.lec;
						cout << endl;

						cout << "Pay of teacher in this School: ";
						cout << teacherData.pay;
						cout << endl;

						cout << "Phone Number of teacher: ";
						cout << teacherData.cel_no;
						cout << endl;

						cout << "Blood Group of techer: ";
						cout << teacherData.blod_grp;
						cout << endl;

						break;
					}

				}


				if (notfound == 0)
				{
					cout << "Record does not found" << endl;
				}

				iteach.close();

				cout<<endl << "Do you want to find another entery [Y] or [N]" << endl;

				char fc;
				cin >> fc;

				if (fc == 'Y' || fc == 'y')
				{
					goto tfind;
				}

				else if (fc == 'N' || fc == 'n')
				{
					cout << "1.Do you want to go back" << endl;
					cout << "2.Do you want to go to main screen" << endl;
					cout << "3.Do you want to exit" << endl;
					cout << endl << "Enter your choice: ";
					int sc = 0;
					cin >> sc;

					if (sc == 1)
					{
						goto tmain;
					}
					else if (sc == 2)
					{
						goto main;
					}
					else
					{
						exit(0);
					}

				}

			}

		}

		else if (tchoice == 3)
		{
		   eteach:

			system("cls");

			string fn,ln;
			
			cin.ignore();

			cout << "Enter first name of teacher" << endl;
			getline(cin, fn);

			cout << "Enter last name of teacher" << endl;
			getline(cin, ln);


			ifstream iteach("teacher.txt");

			if (iteach.fail())
			{
				cout << "Error in loading file" << endl;
			}
			else
			{
				int i = 0;
				string str;

				while (!iteach.eof())
				{
					getline(iteach, str);
					i++;
				}

				iteach.close();

				ifstream iteach("teacher.txt");

				for (int j = 0; j < i / 10; j++)
				{
					getline(iteach, teacherData.fst_name);
					getline(iteach, teacherData.lst_name);
					getline(iteach, teacherData.qualification);
					getline(iteach, teacherData.exp);
					getline(iteach, teacherData.year);
					getline(iteach, teacherData.subj);
					getline(iteach, teacherData.lec);
					getline(iteach, teacherData.pay);
					getline(iteach, teacherData.cel_no);
					getline(iteach, teacherData.blod_grp);


					if (fn != teacherData.fst_name && ln != teacherData.lst_name)
					{
						ofstream oteach("temp.txt", ios::app);

						oteach << teacherData.fst_name << endl;
						oteach << teacherData.lst_name << endl;
						oteach << teacherData.qualification << endl;
						oteach << teacherData.exp << endl;
						oteach << teacherData.year << endl;
						oteach << teacherData.subj << endl;
						oteach << teacherData.lec << endl;
						oteach << teacherData.pay << endl;
						oteach << teacherData.cel_no << endl;
						oteach << teacherData.blod_grp << endl;

						oteach.close();

					}

					else if (fn == teacherData.fst_name && ln == teacherData.lst_name)
					{

						cout << endl << "Enter new data: " << endl<<endl;

						cout<< "Enter first name of teacher: ";
						getline(cin, teacherData.fst_name);

						cout << "Enter last name of teacher: ";
						getline(cin, teacherData.lst_name);

						cout << "Enter qualification of teacher: ";
						getline(cin, teacherData.qualification);

						cout << "Enter experience (in year) of teacher: ";
						getline(cin, teacherData.exp);

						cout << "Enter number of year in this school: ";
						getline(cin, teacherData.year);

						cout << "Enter which subject he/she teaches: ";
						getline(cin, teacherData.subj);

						cout << "Enter number of Lecture (per week): ";
						getline(cin, teacherData.lec);

						cout << "Enter pay of teacher: ";
						getline(cin, teacherData.pay);

						cout << "Enter phone number of teacher: ";
						getline(cin, teacherData.cel_no);

						cout << "Enter blood group of teacher: ";
						getline(cin, teacherData.blod_grp);


						ofstream oteach("temp.txt", ios::app);

						oteach << teacherData.fst_name << endl;
						oteach << teacherData.lst_name << endl;
						oteach << teacherData.qualification << endl;
						oteach << teacherData.exp << endl;
						oteach << teacherData.year << endl;
						oteach << teacherData.subj << endl;
						oteach << teacherData.lec << endl;
						oteach << teacherData.pay << endl;
						oteach << teacherData.cel_no << endl;
						oteach << teacherData.blod_grp << endl;

						oteach.close();

						cout << "Your entery has been succesfully edited." << endl;

					}

				}

				iteach.close();
				remove("teacher.txt");
				rename("temp.txt", "teacher.txt");

			}

			cout << endl << "Do you want to edit another entery [Y] or [N]" << endl;

			char rch;
			cin >> rch;

			if (rch == 'Y' || rch == 'y')
			{
				goto eteach;
			}
			else if (rch == 'N' || rch == 'n')
			{
				cout << endl << "1.Do you want to go back" << endl;
				cout << "2.Do you want to go to main screen" << endl;
				cout << "3.Do you want to exit" << endl;
				cout << endl << "Enter your choice: ";

				int sc = 0;

				cin >> sc;

				if (sc == 1)
				{
					goto tmain;
				}
				else if (sc == 2)
				{
					goto main;
				}
				else
				{
					exit(0);
				}

			}


		}

		else if (tchoice == 4)
		{
		    dteach:

			system("cls");

			string fn, ln;

			cin.ignore();

			cout << "Enter first name of teacher" << endl;
			getline(cin, fn);

			cout << "Enter last name of teacher" << endl;
			getline(cin, ln);


			ifstream iteach("teacher.txt");

			if (iteach.fail())
			{
				cout << "Error in loading file" << endl;
			}
			else
			{
				int i = 0;
				string str;

				while (!iteach.eof())
				{
					getline(iteach, str);
					i++;
				}

				iteach.close();

				ifstream iteach("teacher.txt");

				for (int j = 0; j < i / 10; j++)
				{
					getline(iteach, teacherData.fst_name);
					getline(iteach, teacherData.lst_name);
					getline(iteach, teacherData.qualification);
					getline(iteach, teacherData.exp);
					getline(iteach, teacherData.year);
					getline(iteach, teacherData.subj);
					getline(iteach, teacherData.lec);
					getline(iteach, teacherData.pay);
					getline(iteach, teacherData.cel_no);
					getline(iteach, teacherData.blod_grp);


					if (fn != teacherData.fst_name && ln != teacherData.lst_name)
					{
						ofstream oteach("temp.txt", ios::app);

						oteach << teacherData.fst_name << endl;
						oteach << teacherData.lst_name << endl;
						oteach << teacherData.qualification << endl;
						oteach << teacherData.exp << endl;
						oteach << teacherData.year << endl;
						oteach << teacherData.subj << endl;
						oteach << teacherData.lec << endl;
						oteach << teacherData.pay << endl;
						oteach << teacherData.cel_no << endl;
						oteach << teacherData.blod_grp << endl;

						oteach.close();

					}

				}

				iteach.close();
				remove("teacher.txt");
				rename("temp.txt", "teacher.txt");

			}

			cout << "Your entery has been succesfully deleted." << endl;

			cout << endl << "Do you want to delete another entery [Y] or [N]" << endl;

			char rch;
			cin >> rch;

			if (rch == 'Y' || rch == 'y')
			{
				goto dteach;
			}
			else if (rch == 'N' || rch == 'n')
			{
				cout << endl << "1.Do you want to go back" << endl;
				cout << "2.Do you want to go to main screen" << endl;
				cout << "3.Do you want to exit" << endl;
				cout << endl << "Enter your choice: ";

				int sc = 0;

				cin >> sc;

				if (sc == 1)
				{
					goto tmain;
				}
				else if (sc == 2)
				{
					goto main;
				}
				else
				{
					exit(0);
				}

			}

		}

		else if (tchoice == 5)
		{
			goto main;
		}

	}

	else
	{
		exit(0);
	}


}