#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function to display tasks
void displayTasks(const vector<Task>& tasks) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ". ";
        if (tasks[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter new task: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
}

// Function to mark a task as completed
void completeTask(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter task number to complete: ";
    cin >> taskNumber;
    cin.ignore(); // Ignore newline character
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to delete a task
void deleteTask(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;
    cin.ignore(); // Ignore newline character
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "To-Do App" << endl;
        cout << "1. Display tasks" << endl;
        cout << "2. Add new task" << endl;
        cout << "3. Complete task" << endl;
        cout << "4. Delete task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1:
                displayTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                completeTask(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
