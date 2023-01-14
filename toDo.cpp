#include <iostream>
#include <string>

std::string* todoList = nullptr;
int tasksCount = 0;
int maxTasks = 0;

void addTask(std::string task) {
    if (tasksCount < maxTasks) {
        todoList[tasksCount] = task;
        tasksCount++;
    } else {
        std::string* newTodoList = new std::string[maxTasks + 10];
        for (int i = 0; i < tasksCount; i++) {
            newTodoList[i] = todoList[i];
        }
        maxTasks += 10;
        delete[] todoList;
        todoList = newTodoList;
        todoList[tasksCount] = task;
        tasksCount++;
    }
}

void removeTask(int index) {
    if (index >= 0 && index < tasksCount) {
        for (int i = index; i < tasksCount - 1; i++) {
            todoList[i] = todoList[i + 1];
        }
        tasksCount--;
    } else {
        std::cout << "Error: Invalid index!" << std::endl;
    }
}

void listTasks() {
    for (int i = 0; i < tasksCount; i++) {
        std::cout << i + 1 << ". " << todoList[i] << std::endl;
    }
}

int main() {
    todoList = new std::string[10];
    maxTasks = 10;
    while (true) {
        std::cout << "1. Add task" << std::endl;
        std::cout << "2. Remove task" << std::endl;
        std::cout << "3. List tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << std::endl;
        
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string task;
            std::cout << std::endl;
            std::cout << "Enter task: ";
            std::cin >> task;
            addTask(task);
        } else if (choice == 2) {
            int index;
            std::cout << std::endl;
            std::cout << "Enter index of task to remove: ";
            std::cin >> index;
            removeTask(index - 1);
        } else if (choice == 3) {
            std::cout << std::endl;
            listTasks();
            std::cout << std::endl;
        } else {
            break;
        }
    }
    delete[] todoList;
    return 0;
}