#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

class Worker
{
private:
    std::string name_surname = " ";
    int experience;
    double hourlySalary;
    int hoursWorked;
public:
    Worker(std::string name_surname, int experience, double hourlySalary, int hoursWorked)
        : name_surname(name_surname), experience(experience), hourlySalary(hourlySalary), hoursWorked() {}
    double calculateSalary()
    {
        return hourlySalary * hoursWorked;
    }

    double calculateBonus()
    {
        if (experience < 1) return 0;
        if (experience < 3) return calculateSalary() * 0.05;
        if (experience < 5) return calculateSalary() * 0.08;
        return calculateSalary() * 0.15;
    }

    void displayInfo()
    {
        std::cout << "Работник: " << name_surname << "\n"
            << "Стаж: " << experience << " лет\n"
            << "Зарплата за отработанное время: " << calculateSalary() << "\n"
            << "Премия: " << calculateBonus() << "\n";
    }

    void WritingFile(const std::string& nameFile)
    {
        std::ofstream file(nameFile, std::ios::app);
        file << name_surname << "," << experience << "," << hourlySalary << "," << hoursWorked << "\n";
        file.close();
    }
};

void conclusionFile(const std::string& nameFile)
{
    std::ifstream file(nameFile);
    std::string string;
    while (std::getline(file, string))
    {
        std::cout << string << "\n";
    }
    file.close();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Worker WorkerOne("Иван Иванов", 2, 500, 160);
    Worker WorkerTwo("Петр Петров", 4, 600, 160);
    Worker WorkerThree("Сидор Сидоров", 6, 700, 160);

    WorkerOne.WritingFile("Worker.txt");
    WorkerTwo.WritingFile("Worker.txt");
    WorkerThree.WritingFile("Worker.txt");

    conclusionFile("Worker.txt");

    return 0;
}