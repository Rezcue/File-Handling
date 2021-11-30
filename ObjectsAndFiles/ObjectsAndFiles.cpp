#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include <fstream>



using namespace std;
//******************Creating Class**************************
//default private:      --> cant be changed outside of class
//public:         -->for "Getter"- und ""Setter"-functions outside of the class
//protected: --> can be accessed by sub-class too
class Person {
private:
    //Person Veriables
    //If you want to store "class" in a "binary"-files you cant use "strings"
    //A string is an array of char so --> use char variable [size]
    char newName [30];
    char newGender[10];
    char likesThings[50];
    char dislikesThings[50];
    //char being used to avoid int-keyboard-entries
    char newAge[15];
public:
    //------------"set"- and "get"-functions-------------
    //"Set"-functions
    void setDataPerson();
    //sets newName, newGender, likesThings, dislikesThings
    //"Get"-functions
    string getName() const;
    //getName 
    //@return string - name of person
    //After the file has been read you can use strings to compare
    void getDataPerson();
    //gets the rest of the private variables

};
//**********************************************************

//******************Class-Methods***************************
void Person::setDataPerson()
{
    string name, gender, age, likesthing, dislikesthing;
    //Ignore or clear one or more characters from the input buffer
    cin.ignore();
    //Prints info to user in terminal
    cout << "Enter name: Lastname Firstname " << endl;
    //gets whole entered line as string
    getline(cin, name);
    //converts string into char array
    strcpy_s(newName, name.c_str());

    cout << "Enter gender: " << endl;

    getline(cin, gender);
    strcpy_s(newGender, gender.c_str());

    cout << "Enter age: " << endl;
    getline(cin, age);
    strcpy_s(newAge, age.c_str());

    cout << "Enter likes of Person: 1, 2, 3, ... " << endl;
    getline(cin, likesthing);
    strcpy_s(likesThings, likesthing.c_str());

    cout << "Enter dislikes of Person: 1, 2, 3, ... " << endl;
    getline(cin, dislikesthing);
    strcpy_s(dislikesThings, dislikesthing.c_str());

}
void Person::getDataPerson()
{
    cout << "Name: " << newName << endl;
    cout << "Gender: " << newGender << endl;
    cout << "Age: " << newAge << endl;
    cout << "Likes: " << likesThings << endl;
    cout << "Dislikes: " << dislikesThings << endl;
}
string Person::getName() const
{
    return newName;
}
//**********************************************************

//******************Declare functions***********************
//Those functions need to be declared before the main()
void AddPerson();
void ShowList();
//Functions below need parameter string n to work
void ShowPerson(string name);
void ChangeDataPerson(string name);
void DeletePerson(string name);
//**********************************************************

//***********************main()*****************************
//"Main"-functions: ->starts programm and calls functions
int main()
{
    //use char to avoid int-keyboard-entries
    char option;
    //Use do-while-schleife for the user-menu-display
    //Do-while-loop acts and checks afterwards
    //Means "user-menu" will be kept alive until while-condition is met 
    do
    {
        //parameter string name
        string name;
        //display "main-menu"
        cout << "  MAIN MENU" << endl;
        cout << "*************" << endl;
        cout << " 1. Show List" << endl;
        cout << " 2. Show Person" << endl;
        cout << " 3. Add Person" << endl;
        cout << " 4. Edit Person" << endl;
        cout << " 5. Delete Person" << endl;
        cout << " 6. Exit" << endl;
        //Enter "option" into terminal using the parameter char option
        cin >> option; 
        //Clears screen
        system("cls");
        //Use switch-function to delcare cases to every option for the main-manu
        //Conditon-parameter entered char option
        switch (option) 
        {
        //case '1' <--- use '' to declare 1 as char
        case '1':
            //Calls cuntion ShowList() and runs it
            ShowList();
            //Every case needs to know when to stop 
            //With break; the case knows when to stop
            //If break; is not declared it will run the next case automatically 
            //Till the next breaK;
            break;
        case '2':
            //Print Text to terminal
            cout << "-->Enter Full Name<--" << endl;
            //Ignore or clear one or more characters from the input buffer
            cin.ignore();
            //getline --> String input
            getline(cin, name);
            system("cls");
            cout << name << endl;
            cout << "================" << endl;
            cout << endl;
            //Calls funcion ShowPerson(name); and runs it
            //Needs the parameter name as argument
            ShowPerson(name);
            break;
        case '3':
            AddPerson();
            break;
        case '4':
            //Initialize parameter char option1
            char option1;
            //Clears screen
            system("cls");
            //Calls functin Showlist();
            ShowList();
            //Print Text to terminal
            cout << "-->Enter Full Name<--" << endl;
            //Ignore or clear one or more characters from the input buffer
            cin.ignore();
           //Getline --> String input
            getline(cin, name);
            system("cls");
            //Print name to terminal
            cout << name << endl;
            cout << "================" << endl;
            //Calls function
            ShowPerson(name);
            //Displays menu-options
            cout << "================" << endl;
            cout << endl;
            cout << "================" << endl;
            cout << "=====Option=====" << endl;
            cout << "================" << endl;
            cout << "=>1. Change Data " << endl;
            cout << "=>2. Delete From List" << endl;
            cout << "=>Enter Option<=" << endl;
            cout << "________________" << endl;
            //Enter option
            cin >> option1;
            //Deals with different inputs
            switch (option1) 
            {
            case '1':
                ChangeDataPerson(name);
                break;
            case '2':
                DeletePerson(name);
                break;
            //Does not accept any other keyborad-entries then cases available
            default:
                //Print notice that invaild option entered
                cout << "Invaild!" << endl; 
                break;
            }
            break;
        case '5':
            system("cls");
            ShowList();
            cout << "-->Enter Full Name<--" << endl;
            cin.ignore();
            //getline --> String input (while line)
            getline(cin, name);
            system("cls");
            cout << name << endl;
            cout << "================" << endl;
            /*ChangeDataPerson(n);*/
            ShowPerson(name);
            DeletePerson(name);
            break;
        default: 
            cout << "\a";
        }
    //Condition to break the do-while-loop
    //Exits the programm
    } while (option != '6');
    //Since main() is an int main() in needs to return a int at the end
    return 0;
}
//**********************************************************

//*******************Build functions************************
//Function to add a new Object to the file
//void functions dont return any thing when they end
void AddPerson() 
{
    //Building a new object "newPerson"
    Person newPerson;
    //1. initialize file with ofstream Variable;
    ofstream appFile;
    //2. open file 
    //Creates file when not already existing
    //Variable.open("Dataname.type), ios::type(here its binary) | others conitions)
    //                                    -->ios::app to add to file
    appFile.open("Person.dat", ios::binary | ios::app);
    //Calls class-method to get the Data from class
    newPerson.setDataPerson();
    //3. write to file 
    //Writing the object's (newPerson) data in file 
    appFile.write((char*)&newPerson, sizeof(Person));
    //4. close file
    appFile.close();
    cout << "New Person Has Been Added!" << endl;
}


void ShowList()
{
    Person newPerson;
    ifstream inFile;
    //1. open file
    inFile.open("Person.dat", ios::binary | ios::in);
    //if file not open then --> print 
    if (!inFile)
    {
        cout << "File cant be opened! Press any Key..." << endl;
        return;
    }
    cout << "List Of Persons:" << endl;
    cout << "******************" << endl;
    //2. read file
    //while file being read get data from objects line for line 
    while (inFile.read((char*)(&newPerson), sizeof(Person)))
    {
        //Calls class-method
        newPerson.getDataPerson();
        cout << "\n=====================\n";
        cout << endl;
    }
    //3. close file
    inFile.close();
}

void ShowPerson(string name)
{
    Person newPerson;
    ifstream myFile;
    myFile.open("Person.dat", ios::binary);
    if (!myFile)
    {
        cout << "File cant be opened! Press any Key..." << endl;
        return;
    }
    //initialize int i 
    int i = 0;
    //while file being read get data from objects line for line 
    while (myFile.read(reinterpret_cast<char*>(&newPerson), sizeof(Person)))
    {
        //If newName from obj newPerson equals to string name then show data for this person
        if (newPerson.getName() == name)
        {
            newPerson.getDataPerson();
            cout << "/////////////////////" << endl;
            //Keeps count of object with same name in file
            i++;
        }
    }
    cout << "Found " << i << " Persons With Name " << name << endl;
    myFile.close();
    //If now object with enter name found infile --> i=0
    if (i == 0) {
        cout << "Person not on the List!" << endl;
    };

}
void ChangeDataPerson(string name)
{
    Person newPerson;
    fstream File;
    //ios::in to read a file 
    //ios::out to write to file
    File.open("Person.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File cant be opened! Press any Key..." << endl;

        return;
    }
    //initialize flag 
    bool flag = false;
    cout << "****Change DATA****" << endl;
    //while file being read get data from objects line for line 
    while (File.read((char*)(&newPerson), sizeof(Person)) && flag == false)
    { 
    //If string name maches newName of obj. newPerson 
    if (newPerson.getName() == name)
        {
           //Print data of person
           newPerson.getDataPerson();
           cout << "Enter New Data Of Selected Person" << endl;
           cout << "\n================================\n";
           //Set new data for this person
           newPerson.setDataPerson();
           //integer with postition in object (to get to the beginning of the Obj.)
           int pos = (-1) *int(sizeof(newPerson));
           //Go to position 0 of the object 
           File.seekp(pos, ios::cur);
           //Write the new data for this person from the beginning
           File.write((char*)&newPerson, sizeof(Person));
           cout << "Saved New Data for " << newPerson.getName() << "!" << endl;
           //set flag to true 
           flag = true;
        }
    }
    //if flag=flase after the fiel has been read --> print 
    if (flag == false)
        cout << "Person Not Found" << endl;
    File.close();
}

void DeletePerson(string name)
//You cant delete single data from file 
//1. creat  file (old/current.File)
//2. open new file (temp.File)
//3. Go to the beginning of the old/current.File
//4. While Read old/current.File 
//5. Add if () to add Filter to catch the data you want to delte and skip it
//6. Write to new.File 
//7. Close new.File
//8. Clise old/curren.File
//9. remove old/curren.File
//10. rename new.file in old/curren.File

{
    Person newPerson;
    ifstream inFile;
    //1. creat file (old/current.File)
    inFile.open("Person.dat", ios::binary |ios::in);
    if (!inFile)
    {
        cout << "File cant be opened! Press any Key..." << endl;
        return;
    }
    ofstream outFile;
    //2. open new file (temp.File)
    outFile.open("Temp.dat", ios::out);
    //3. Go to the beginning of the old/current.File
    inFile.seekg(0, ios::beg);
    //4. While Read old/current.File
    while (inFile.read(reinterpret_cast<char*>(&newPerson), sizeof(Person)))
    {
        //5. Add if () to add Filter to catch the data you want to delte and skip it (1=)
        if (newPerson.getName() != name)
        {
            //6. Write to new.File 
            outFile.write(reinterpret_cast<char*>(&newPerson), sizeof(Person));
        }
    }
    //7. Close new.File
    outFile.close();
    //8. Clise old/curren.File
    inFile.close();
    //9. remove old/curren.File
    remove("Person.dat");
    rename("Temp.dat", "Person.dat");
    cout << "======================" << endl;
    cout << "Person Removed From List!" << endl;
    cout << "======================" << endl;
    cout << "Pess Enter To Continue" << endl;
    cout << "______________________" << endl;
    cin.get();
}
//**********************************************************