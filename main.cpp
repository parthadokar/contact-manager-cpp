#include <iostream>
#include <cstdlib> 

struct Contact {
        int id;
        double contactNumber;
        std::string contactName;
    };

Contact contactList[100];
int contactCount = 0;

void addContact(Contact contactList[],int &contactCount) {
    if (contactCount >= 100) {
        std::cout << "Contact list full, Can't add more contacts" << "\n";
        return;
    }

    std::cout << "Enter Contact Name" << "\n";
    std::getline(std::cin,contactList[contactCount].contactName);
    std::cout << "Enter Contact Number" << "\n";
    std::cin >> contactList[contactCount].contactNumber;
    contactList[contactCount].id = contactCount +1;
    contactCount++;
    std::cout << "Contact Added" << "\n";
}

void viewContact(Contact contactList[],int &contactCount) {
    for (int i = 0;i < contactCount;i++) {
        if (contactCount == 0) {
            std::cout << "No Data" << "\n";
        } else {
            std::cout << contactList[i].id  << " . " << contactList[i].contactName << " - " << contactList[i].contactNumber <<"\n";
        }
    }
}

void searchContact(Contact contactList[],int &contactCount) {
    std::string keyword;
    std::cout << "Enter the keywords you want to search \n";
    std::getline(std::cin,keyword);
    bool matchFound = false;
    for (int i = 0; i < contactCount;i++) {
        std::size_t found  = contactList[i].contactName.find(keyword);
        if (found != std::string::npos) {
            matchFound = true;
            std::cout << "Name : " << contactList[i].contactName << "\n";
        } 
       
        if (!matchFound) {
            std::cout << "No Match Found";
        }
    }
}

void deleteContact(Contact contactList[], int &contactCount) {
    if (contactCount == 0) {
        std::cout << "No Data\n";
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        std::cout << contactList[i].id << " . " << contactList[i].contactName
                  << " - " << contactList[i].contactNumber << "\n";
    }

    int removeID;
    std::cout << "Which contact do you want to remove? (ENTER THE ID): \n";
    std::cin >> removeID;

    bool found = false;
    for (int i = 0; i < contactCount; i++) {
        if (contactList[i].id == removeID) {
            // Shift remaining contacts left
            for (int j = i; j < contactCount - 1; j++) {
                contactList[j] = contactList[j + 1];
                contactList[j].id = j + 1; // Reassign IDs sequentially
            }
            contactCount--;
            std::cout << "Contact Removed Successfully\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Invalid ID. Contact not found.\n";
    }
}


int main () {
    int choice;
    std::cout << "Welcome to Contact Manager" << "\n";
    while (true) {
    std::cout << "What would you like to do?" << "\n" << "1.Add Contact" << "\n" << "2.View Contacts" << "\n" << "3.Search Contact" << "\n" << "4.Delete Contact" << "\n" << "5.Exit" << "\n";
    std::cin >> choice;
    std::cin.ignore();
    
    switch(choice) {
        case 1 : {
            addContact(contactList,contactCount);
            break;
        } 
        case 2 : {
            viewContact(contactList,contactCount);
        }
        case 3 : {
            searchContact(contactList,contactCount);
            break;
        } case 4 : {
            deleteContact(contactList,contactCount);
            break;
        } case 5 : {
            std::cout<< "Exiting" << "\n";
            exit(0);
            break;
        } default : {
            std::cout << "Wrong Choice" << "\n";
        }
    } 
} return 0;
}
