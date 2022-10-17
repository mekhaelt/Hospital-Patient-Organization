#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output

using namespace std; 


int main()
{
    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt","xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient
    bool cInput; // boolean value used to check if a valid input was received
    


        

    // PARTS 1/3/4
    do // do while loop controlling the input and bubblesorts
    {
        cInput = false; // value is set to false (if value stays at false, the do while loop won't run again)
        cout << "Please enter the sorting category (Age, ID, First, Last, Sex): "; 
        string y; // initializing the variable (represents the sorting category)
        cin >> y; // input for y
        char input[y.length()];  // creating an array based on the size of y

        for (int i = 0; i < y.length(); i++) 
        {
            input[i]=y[i]; // iterates y and stores each letter in input
            if ((int)input[i] > 65 && (int)input[i] < 91) // if the character is an upper case letter convert to a lower case letter
            {
                input[i] = char((int)input[i] + 32); 
                
            }
        }

        string k; // initializes k

        for(int i = 0; i < y.length(); i++)  
        {      
            k = k + input[i];  // gives k the value of the chars from input (after all letters have been converted to lower case)
        }  



    
        if (k == "age") 
        {
        cout << "Case 1, sorting by Age." << endl;
        cout << endl;

        for (int i = 0; i < NUM_PATIENTS - 1; i++) // for loop
            for (int j = 0; j < NUM_PATIENTS - i - 1; j++) // another for loop so that all of the values can be compared 
                if (age[j] > age[j + 1]) // comparing the values in age
                {
                    swap(age[j], age[j + 1]); // swapping all of the values for every array if age[j] > age[j+1]
                    swap(id[j], id[j + 1]); 
                    swap(firstName[j], firstName[j + 1]);
                    swap(lastName[j], lastName[j + 1]);
                    swap(sex[j], sex[j + 1]);
                    
                }

                 else if (age[j] == age[j + 1]) // if age[j] == age[j+1]
                    {
                        if (strcmp(firstName[j], firstName[j+1]) > 0) // compares values in firstName (acts as a tiebreaker)
                        {
                            swap(age[j], age[j + 1]); // swapping all of the values for every array, if firstName[j] comes later alphabetically then firstName[j+1]
                            swap(id[j], id[j + 1]);
                            swap(firstName[j], firstName[j + 1]);
                            swap(lastName[j], lastName[j + 1]);
                            swap(sex[j], sex[j + 1]);
                                    
                        }
                    }
    
        }

        else if (k == "id")
        {
            cout << "Case 2, sorting by ID." << endl;
            cout << endl;

            for (int i = 0; i < NUM_PATIENTS - 1; i++) // for loop
                for (int j = 0; j < NUM_PATIENTS - i - 1; j++) // another for loop so that all of the values can be compared 
                    if (stoi(id[j]) > stoi(id[j + 1])) // comparing the values in id
                    {
                        swap(age[j], age[j + 1]); // swapping all of the values for every array if the number stored in id[j] > the number stored in id[j+1]
                        swap(id[j], id[j + 1]);
                        swap(firstName[j], firstName[j + 1]);
                        swap(lastName[j], lastName[j + 1]);
                        swap(sex[j], sex[j + 1]);
                                
                    }

                    else if (stoi(id[j]) == stoi(id[j + 1])) // if the value of the number at id[j] == the value of the number at id[j+1]
                    {
                        if (strcmp(firstName[j], firstName[j+1]) > 0) // compares values in firstName (acts as a tiebreaker)
                        {
                            swap(age[j], age[j + 1]); // swapping all of the values for every array, if firstName[j] comes later alphabetically then firstName[j+1]
                            swap(id[j], id[j + 1]);
                            swap(firstName[j], firstName[j + 1]);
                            swap(lastName[j], lastName[j + 1]);
                            swap(sex[j], sex[j + 1]);
                                    
                        }
                    }
        }

        else if (k == "sex")
        {
            cout << "Case 3, sorting by Sex." << endl; 
            cout << endl;

             for (int i = 0; i < NUM_PATIENTS - 1; i++) // for loop
                for (int j = 0; j < NUM_PATIENTS - i - 1; j++) // another for loop so that all of the values can be compared 
                    if (sex[j] + '0' > sex[j+1] + '0') // comparing the values in sex
                    {
                        swap(age[j], age[j + 1]); // swapping all of the values for every array if the ASCII value at the first index of sex > the ASCII value at the second index of sex
                        swap(id[j], id[j + 1]);
                        swap(firstName[j], firstName[j + 1]);
                        swap(lastName[j], lastName[j + 1]);
                        swap(sex[j], sex[j + 1]);
                                
                    }

                    else if (sex[j] + '0' == sex[j+1] + '0') // if the ASCII value at the first index of sex == the ASCII value at the second index of sex
                    {
                        if (strcmp(firstName[j], firstName[j+1]) > 0) // compares values in firstName (acts as a tiebreaker)
                        {
                            swap(age[j], age[j + 1]); // swapping all of the values for every array, if firstName[j] comes later alphabetically then firstName[j+1]
                            swap(id[j], id[j + 1]);
                            swap(firstName[j], firstName[j + 1]);
                            swap(lastName[j], lastName[j + 1]);
                            swap(sex[j], sex[j + 1]);
                                    
                        }
                    }
        }

        else if (k == "last")
        {
            cout << "Case 4, sorting by Last Name." << endl;
            cout << endl;

             for (int i = 0; i < NUM_PATIENTS - 1; i++) // for loop
                for (int j = 0; j < NUM_PATIENTS - i - 1; j++) // another for loop so that all of the values can be compared 
                    if (strcmp(lastName[j], lastName[j+1]) > 0) // comparing the values in lastName
                    {
                        swap(age[j], age[j + 1]);// swapping all of the values for every array, if lastName[j] comes later alphabetically then lastName[j+1]
                        swap(firstName[j], firstName[j + 1]);
                        swap(lastName[j], lastName[j + 1]);
                        swap(sex[j], sex[j + 1]);
                                
                    }

                    else if (strcmp(lastName[j], lastName[j+1]) == 0) // if lastName[j] is the same alphabetically as lastName[j+1]
                    {
                        if (strcmp(firstName[j], firstName[j+1]) > 0) // compares values in firstName (acts as a tiebreaker)
                        {
                            swap(age[j], age[j + 1]); // swapping all of the values for every array, if firstName[j] comes later alphabetically then firstName[j+1]
                            swap(id[j], id[j + 1]);
                            swap(firstName[j], firstName[j + 1]);
                            swap(lastName[j], lastName[j + 1]);
                            swap(sex[j], sex[j + 1]);
                                    
                        }
                    }
        }


        
        else if (k == "first")
        {
            cout << "Case 5, sorting by First Name." << endl;
            cout << endl;

            for (int i = 0; i < NUM_PATIENTS - 1; i++) // for loop
                for (int j = 0; j < NUM_PATIENTS - i - 1; j++) // another for loop so that all of the values can be compared 
                    if (strcmp(firstName[j], firstName[j+1]) > 0) // comparing the values in firstName
                    {
                        swap(age[j], age[j + 1]); // swapping all of the values for every array, if firstName[j] comes later alphabetically then firstName[j+1]
                        swap(id[j], id[j + 1]);
                        swap(firstName[j], firstName[j + 1]);
                        swap(lastName[j], lastName[j + 1]);
                        swap(sex[j], sex[j + 1]);
                                
                    }
        }

        else
        {
            cout << "Unexpected input. ";
            cInput = true; // sets cInput value to true (causes do while loop to run again)
        }
        
    } 
    while (cInput == true); // condition for do while loop


    // PART 2: Outputting patient records to terminal in tabular form

    //Outputting patient's age to terminal in tabular form
    cout << setw(11) << "Age:";
    for (int i = 0; i<NUM_PATIENTS; i++) // 
    {
        cout << setw(11) << age[i];
    } 
        cout << endl;

    //Outputting patient's id to terminal in tabular form
    cout << setw(11) << "ID:";
    for (int i = 0; i<NUM_PATIENTS; i++)
    {
        cout << setw(11) << id[i];
    } 
    cout << endl;

    //Outputting patient's first name to terminal in tabular form
    cout << setw(11) << "First Name:";
    for (int i = 0; i<NUM_PATIENTS; i++)
    {
        cout << setw(11) << firstName[i];
    } 
    cout << endl;

    //Outputting patient's last name to terminal in tabular form
    cout << setw(11) << "Last Name:";
    for (int i = 0; i<NUM_PATIENTS; i++)
    {
        cout << setw(11) << lastName[i];
    } 
    cout << endl;

    //Outputting patient's sex to terminal in tabular form
     cout << setw(11) << "Sex:";
    for (int i = 0; i<NUM_PATIENTS; i++)
    {
        cout << setw(11) << sex[i];
    } 
    cout << endl;




    return 0;
}

