#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Contact {
    int id;
    float mobile;
    char name[40];
    char email[40];
    char fbID[40];
    char address[100];

public:
    Contact() {
        id = 0;
        mobile = 0.0f;
        strcpy(name, "");
        strcpy(email, "");
        strcpy(fbID, "");
        strcpy(address, "");
    }
    Contact(int cid, const char* cname, const char* cemail, float cmobile, const char* cfbID, const char* caddr) {
        id = cid;
        mobile = cmobile;
        strncpy(name, cname, sizeof(name)-1);
        name[sizeof(name)-1] = '\0';
        strncpy(email, cemail, sizeof(email)-1);
        email[sizeof(email)-1] = '\0';
        strncpy(fbID, cfbID, sizeof(fbID)-1);
        fbID[sizeof(fbID)-1] = '\0';
        strncpy(address, caddr, sizeof(address)-1);
        address[sizeof(address)-1] = '\0';
    }
    void disp() const {
        cout << "ID            : " << id      << endl;
        cout << "Name          : " << name    << endl;
        cout << "Address       : " << address << endl;
        cout << "Email         : " << email   << endl;
        cout << "Mobile        : " << mobile  << endl;
        cout << "Facebook ID   : " << fbID    << endl;
        cout << "=====================================================\n";
    }
    friend void search(int id);
    friend void deleteRecord(int id);
};

void addContact(const Contact& c) {
    ofstream fout("contacts.dat", ios::app | ios::binary);
    if (!fout) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    fout.write(reinterpret_cast<const char*>(&c), sizeof(c));
    fout.close();
    cout << "Contact Added successfully" << endl;
}

void dispAll() {
    Contact temp;
    ifstream fin("contacts.dat", ios::binary);
    if (!fin) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    while (fin.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
        temp.disp();
    }
    fin.close();
}

void search(int id) {
    ifstream fin("contacts.dat", ios::binary);
    if (!fin) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    Contact temp;
    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
        if (temp.id == id) {
            cout << "Record Found:" << endl;
            temp.disp();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found." << endl;
    }
    fin.close();
}

void deleteRecord(int id) {
    ifstream fin("contacts.dat", ios::binary);
    if (!fin) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    ofstream fout("temp.dat", ios::binary);
    if (!fout) {
        cerr << "Error opening temporary file for writing." << endl;
        return;
    }
    Contact obj;
    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        if (obj.id != id) {
            fout.write(reinterpret_cast<const char*>(&obj), sizeof(obj));
        } else {
            found = true;
        }
    }
    fin.close();
    fout.close();
    if (found) {
        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");
        cout << "Contact deleted successfully." << endl;
    } else {
        cout << "Contact with ID " << id << " not found." << endl;
        remove("temp.dat");
    }
}

#endif
