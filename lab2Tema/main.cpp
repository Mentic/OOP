#include <iostream>
#include "NumberList.h"
#include "Student.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    NumberList numbers;
    numbers.Init();
    numbers.Add(6);
    numbers.Add(8);
    numbers.Add(3);
    numbers.Add(5);
    numbers.Add(14);
    numbers.Add(28);
    numbers.Sort();
    numbers.Print();


    //Problema2:
    Student student;
    student.setName("Andrei");
    std::cout << student.getName() << std::endl;
    student.setNotaEngleza(8);
    student.setNotaIstorie(2);
    student.setNotaMatematica(12);
    std::cout<< student.getNotaEngleza() << std::endl;
    std::cout<< student.getNotaIstorie() << std::endl;
    std::cout<< student.getNotaMatematica() << std::endl;
    std::cout<< student.notaMedie()<<std::endl;

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}