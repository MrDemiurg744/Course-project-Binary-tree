#include "types.h"
extern organization *arr;
void search_menu()
{
    if(num_organization==0){cout<<endl<<"Немає Organization";}
    else
    {
        log_save("Перехiд до пошукового меню");
        system("cls");
        while(true)
        {
            system("cls");
            cout<<"Пошукове меню"<<endl; line;
            menu_unit menu_2[]={{"Пошук Person з найбiльшим стажем роботи", search_level},
                                {"Знайти Organization по першiй буквi", search_letter},
                                {"Person з стажем роботи бiльше 5 рокiв", top_list},
                                {"Перейти до головного меню", main_menu},
                                {"Вихiд", NULL},};
            for(int i=0;i<5;i++){cout<<i+1<<" "<<menu_2[i].text<<endl;}
            cout<<"\nВедiть число пункта: ";
            int v=getInt(1,5);
            for(int b=0;b<5;b++)
            {
                if(v==5){log_save("Вихiд"); exit(0);}
                if(v==(b+1)){menu_2[b].func();}
            }
        }
    }
    pause();
}
void search_letter()
{
    system("cls");
    cout<<"Пошук Organization по першiй буквi"<<endl; line;
    cout<<"Введiть першу букву для пошуку: ";
    char b[1]; getStr(b,1);
    int x=0;
    for(int i=0;i<num_organization;i++)
    {
        if(b[0]==arr[i].name[0])
        {
            cout<<endl<<"Organization №"<<i+1<<" назва "<<arr[i].name<<", плата "<<arr[i].pay<<", кiлькiсть person "<<arr[i].capacity<<endl;
            x++;
        }
    }
    if(x==0){cout<<"Не знайдено organization по першiй буквi"<<endl;}
    log_save("Знайти Organization по першiй буквi");
    pause();
}
void top_list()
{
    system("cls");
    cout<<"Person зi стажем роботи бiльше 5 рокiв"<<endl; line;
    int ad=5;
    int x=0;
    for(int i=0;i<num_organization;i++)
    {
        for(int b=0;b<arr[i].capacity;b++)
        {
            if(ad<=arr[i].child[b].level)
            {
                x++;
                cout<<"Organization "<<arr[i].name<<", iм'я "<<arr[i].child[b].name<<", стаж "<<arr[i].child[b].level<<" рокiв"<<endl;
            }
        }
    }
    if(x==0){cout<<"Немає Person зi стажем роботи бiльше 5 рокiв"<<endl;}
    log_save("Person зi стажем роботи бiльше 5 рокiв");
    pause();
}
void search_level()
{
    system("cls");
    cout<<"Пошук Person з найбiльшим стажем роботи"<<endl; line;
    int num_1=0, num_2=0, max=0;
    for(int i=0;i<num_organization;i++)
    {
        for(int b=0;b<arr[i].capacity;b++)
        {
            if(arr[i].child[b].level>max)
            {
                max=arr[i].child[b].level;
                num_1=i;
                num_2=b;
            }
        }
    }
    cout<<"Person з найбiльшим стажем роботи: "<<arr[num_1].child[num_2].name<<" в organization "<<arr[num_1].name<<", стаж: "<<arr[num_1].child[num_2].level<<endl;
    log_save("Пошук Person з найбiльшим стажем роботи");
    pause();
}
