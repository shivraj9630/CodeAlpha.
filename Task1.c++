#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoList {
private:
    struct Task {
        string description;
        bool completed;
    };

    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        } else {
            cout << "Invalid task index" << endl;
        }
    }

    void showTasks() {
        if (tasks.empty()) {
            cout << "No tasks to show." << endl;
        } else {
            cout << "Current tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                string status = tasks[i].completed ? "[x]" : "[ ]";
                cout << i + 1 << ". " << status << " " << tasks[i].description << endl;
            }
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        cout << "\nTODO LIST APPLICATION" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Mark task as completed" << endl;
        cout << "3. View current tasks" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                cout << "Task added successfully!" << endl;
                break;
            }
            case 2: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                todoList.markTaskCompleted(index - 1);
                cout << "Task marked as completed!" << endl;
                break;
            }
            case 3:
                todoList.showTasks();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
