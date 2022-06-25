#ifndef TYPES_H
#define TYPES_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <limits.h>
using namespace std;
#define SIZE_NAME 40
#define line for(int i=0;i<=120;i++){if(i<119){cout<<"-";}else{cout<<endl;}}
extern int num_organization;
extern int num_person;
extern int num_characteristic;
extern int num_parameters;
extern int num_data;
struct organization;
struct person;
struct characteristic;
struct parameters;
typedef void menufunk();
struct menu_unit
{
    string text;
    menufunk *func;
};
struct organization
{
    char name[SIZE_NAME];
    int pay;
    person *child;
    int capacity;
};
struct person
{
    char name[SIZE_NAME];
    int level;
    characteristic *child;
    int capacity;
    organization *parent;
};
struct characteristic
{
    char name[SIZE_NAME];
    int capacity;
    parameters *child;
    person *parent;
};
struct parameters
{
    char name[SIZE_NAME];
    characteristic *parent;
};
void main_menu();
void organization_menu();
void person_menu();
void characteristic_menu();
void parameters_menu();
void operations_tree_menu();
void search_menu();

void show_organization();
void show_person();
void show_characteristic();
void show_parameters();

void switch_organization();
void switch_person();
void switch_characteristic();
void switch_parameters();

void add_organization();
void add_person();
void add_characteristic();
void add_parameters();

void edit_organization();
void edit_person();
void edit_characteristic();
void edit_parameters();

void delete_organization();
void delete_person();
void delete_characteristic();
void delete_parameters();

void del_all_organization();
void del_all_person();
void del_all_characteristic();
void del_all_parameters();

void test_tree();
void show_full_tree();
void save_tree();
void load_tree();

void search_level();
void search_letter();
void top_list();

void log_save(string name);
void log_view();
void log_delete();

int main();
void pause();
int getInt(int min,int max);
void getStr(char str[],int maxMemory);
#endif // TYPES_H
