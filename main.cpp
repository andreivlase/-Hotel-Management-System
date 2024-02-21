#include <iostream>
using namespace std;

class Hotel {
private:
    struct Node {
        int id, date;
        string name, roomtype;
        Node *next;
    };

public:
    Node *head = NULL;
    void menu();
    void insert();
    void search();
    void update();
    void del();
    void sort();
    void show();
};

void Hotel::menu() {
    int choice;
    do {
        cout << "\n\t___Hotel Management System___" << endl;
        cout << "\nS.No   Functions    Description" << endl;
        cout << "1\tAllocate Room\t\tInsert New Room" << endl;
        cout << "2\tSearch Room\t\tSearch Room with RoomID" << endl;
        cout << "3\tUpdate Room\t\tUpdate Room Record" << endl;
        cout << "4\tDelete Room\t\tDelete Room with RoomID" << endl;
        cout << "5\tShow Room Records\tShow Room Records that (we Added)" << endl;
        cout << "6\tSort Room Records\tSort Room Records based on Room ID" << endl;
        cout << "7\tExit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                update();
                break;
            case 4:
                del();
                break;
            case 5:
                show();
                break;
            case 6:
                sort();
                break;
            case 7:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);
}

void Hotel::insert() {
    cout << "\n\t___Hotel Management System___" << endl;
    Node *new_node = new Node;
    cout << "Enter Room ID: ";
    cin >> new_node->id;
    cout << "Enter Customer Name: ";
    cin >> new_node->name;
    cout << "Enter Allocated Date: ";
    cin >> new_node->date;
    cout << "Enter Room Type: ";
    cin >> new_node->roomtype;

    new_node->next = head;
    head = new_node;

    cout << "\nNew Room Inserted." << endl;
}

void Hotel::search() {
    cout << "\n\t___Hotel Management System___" << endl;
    int t_id;
    cout << "Enter Room ID: ";
    cin >> t_id;
    Node *ptr = head;
    while (ptr != NULL) {
        if (t_id == ptr->id) {
            cout << "\nRoom ID: " << ptr->id << endl;
            cout << "Customer Name: " << ptr->name << endl;
            cout << "Room Allocate Date: " << ptr->date << endl;
            cout << "Room Type: " << ptr->roomtype << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "Room not found." << endl;
}

void Hotel::update() {
    cout << "\n\t___Hotel Management System___" << endl;
    int t_id;
    cout << "Enter Room ID to update: ";
    cin >> t_id;
    Node *ptr = head;
    while (ptr != NULL) {
        if (t_id == ptr->id) {
            cout << "\nEnter New Room ID: ";
            cin >> ptr->id;
            cout << "Enter New Customer Name: ";
            cin >> ptr->name;
            cout << "Enter New Allocated Date: ";
            cin >> ptr->date;
            cout << "Enter New Room Type: ";
            cin >> ptr->roomtype;
            cout << "\nUpdate Record Successfully." << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "Room not found." << endl;
}

void Hotel::del() {
    cout << "\n\t___Hotel Management System___" << endl;
    int t_id;
    cout << "Enter Room ID to delete: ";
    cin >> t_id;
    if (head == NULL) {
        cout << "Linked list is empty." << endl;
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    if (temp != NULL && temp->id == t_id) {
        head = temp->next;
        delete temp;
        cout << "Delete Room Record Successfully." << endl;
        return;
    }
    while (temp != NULL && temp->id != t_id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Room not found." << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Delete Room Record Successfully." << endl;
}

void Hotel::show() {
    cout << "\n\t___Hotel Management System___" << endl;
    if (head == NULL) {
        cout << "No records found." << endl;
        return;
    }
    Node *ptr = head;
    while (ptr != NULL) {
        cout << "\nRoom ID: " << ptr->id << endl;
        cout << "Customer Name: " << ptr->name << endl;
        cout << "Room Allocate Date: " << ptr->date << endl;
        cout << "Room Type: " << ptr->roomtype << endl;
        ptr = ptr->next;
    }
}

void Hotel::sort() {
    if (head == NULL) {
        cout << "\nLinked list is empty." << endl;
        return;
    }
    int count = 0, t_date, t_id;
    string t_name, t_roomtype;
    Node *ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    for (int i = 0; i < count; i++) {
        ptr = head;
        while (ptr->next != NULL) {
            if (ptr->id > ptr->next->id) {
                t_id = ptr->id;
                t_name = ptr->name;
                t_date = ptr->date;
                t_roomtype = ptr->roomtype;

                ptr->id = ptr->next->id;
                ptr->name = ptr->next->name;
                ptr->date = ptr->next->date;
                ptr->roomtype = ptr->next->roomtype;

                ptr->next->id = t_id;
                ptr->next->name = t_name;
                ptr->next->date = t_date;
                ptr->next->roomtype = t_roomtype;
            }
            ptr = ptr->next;
        }
    }
}

int main() {
    Hotel h;
    h.menu();
    return 0;
}
