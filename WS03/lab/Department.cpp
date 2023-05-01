/*
*****************************************************************************
                  Workshop 3 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 01 Feburary 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {
    Department department;
    Project project;

    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
        
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();

            
            
       


            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

    void Department::updateName(const char* newname) {
        if (newname != nullptr && strlen(newname) != 0) {
            if (department_name != nullptr) {
                delete[] department_name;
                department_name = nullptr;
            }
            department_name = new char[strlen(newname) + 1];
            strcpy(department_name, newname);
        }


    }

    void Department::updateBudget(double change) {
        budget_department += change;

    }

    bool Department::addProject(Project& newproject) {

        bool check = false;
        

        double final_cost = totalexpenses() + newproject.m_cost;
        int new_size = 0;
        if (final_cost > budget_department) {
            check = false;
        }
        else if (final_cost < budget_department && num_projects == 0) {
            pj_ptr = new Project[1];
            pj_ptr[0] = newproject;
            num_projects+=1;
            check = true;
        }
        else if (final_cost < budget_department && num_projects > 0) {
            Project* temp_project = nullptr;
            new_size = num_projects + 1;

            temp_project = new Project[new_size];
            for (int i = 0; i < new_size-1; i++) {
                temp_project[i] = pj_ptr[i];
            }
            temp_project[num_projects] = newproject;
            delete[] pj_ptr;
            num_projects += 1;
            pj_ptr = new Project[num_projects];
            for (int i = 0; i < num_projects; i++) {
                pj_ptr[i] = temp_project[i];
            }
            
            delete[] temp_project;
            check = true;
        }

        return check;
    }


            /*
        
        if (final_cost <= budget_department) {
            if (num_projects == 0) {
                pj_ptr = new Project[1];
                pj_ptr[0] = newproject;
                
            }
            else if (num_projects > 0) {
                Project* temp_project = nullptr;
                
                temp_project = new Project[num_projects+1];
                for (int i = 0; i < num_projects; i++) {
                    temp_project[i] = pj_ptr[i];
                }
                temp_project[num_projects] = newproject;
                delete[] pj_ptr;
                num_projects += 1;
                pj_ptr = new Project[num_projects + 1];
                for (int i = 0; i < num_projects; i++) {
                    pj_ptr[i] = temp_project[i];
                }
                delete[] temp_project;
                
            }
            check = true;
        }
        else if (final_cost > budget_department) {
            check = false;
        }
            
        return check;

        */

                /*
                new_size = department.num_projects + 1;
                temp_project = new Project[new_size];
                for (int i = 0; i < new_size; i++) {
                    temp_project[i] = 
                }
                temp_project[new_size] = newproject;
                delete[] 
                */
            
        

    

    void Department::createDepartment(const char* newname, Project& newproject, double change) {

        updateName(newname);
        addProject(newproject);
        updateBudget(change);


    }

    Project* Department::fetchProjects() const {
        /*
        This function will return the list of projects a department is currently working on.
        */
        return pj_ptr;

    }

    int Department::fetchNumProjects() const {
        return num_projects;
    }
   
    double Department::fetchBudget() const {
        return budget_department;
    }


    char* Department::fetchName() const
    {
        return department_name;
    }

    double Department::totalexpenses() {
        double cost = 0.0;
        for (int i = 0; i < num_projects; i++) {
            cost += pj_ptr[i].m_cost;
        }
        return cost;
   
    }

    
    double Department::remainingBudget() {

        return budget_department - totalexpenses();
    }


    void Department::clearDepartment() {

        delete[] department_name;

        delete[] pj_ptr;
    }



}