#include "types.h"
int num_organization=0;
int num_person=0;
int num_characteristic=0;
int num_parameters=0;
int num_data=0;
organization *arr=new organization[num_organization];
void organization_menu()
{
    log_save("Перехiд до меню Organization");
    while(true)
    {
        system("cls");
        if(num_organization==0){cout<<"Organization №"<<num_person+1<<endl;}
        else{cout<<"Organization №"<<num_person+1<<": "<<arr[num_organization-1].name<<endl;} line;
        menu_unit menu[]={{"Створити Organization", add_organization},
                          {"Показати всi Organization", show_organization},
                          {"Показати повнiстю дерево", show_full_tree},
                          {"Змiнити Organization", switch_organization},
                          {"Редагувати Organization", edit_organization},
                          {"Видалити Organization", delete_organization},
                          {"Видалити всi Organization", del_all_organization},
                          {"Перейти до Person меню", person_menu},
                          {"Перейти до головного меню", main_menu},
                          {"Вихiд", NULL},};
        for(int i=0;i<10;i++){cout<<i+1<<" "<<menu[i].text<<endl;}
        cout<<"\nВедiть число пункта: ";
        int v=getInt(1,10);
        for(int b=0;b<10;b++)
        {
            if(v==10){log_save("Вихiд"); exit(0);}
            if(v==(b+1)){menu[b].func();}
        }
    }
}
void add_organization()
{
    system("cls");
    cout<<"Створення Organization"<<endl; line;
    num_organization++;
    organization *ar_2=new organization[num_organization];
    memcpy(ar_2, arr, sizeof(organization)*num_organization);
    arr=new organization[num_organization];
    arr=ar_2;
    cout<<"Введiть назву Organization: ";
    getStr(arr[num_organization-1].name,40);
    cout<<"Введiть плату Organization: ";
    arr[num_organization-1].pay=getInt(0,LONG_MAX);
    cout<<"Введiть кiлькiсть Person: ";
    arr[num_organization-1].capacity=getInt(0,LONG_MAX);
    arr[num_organization-1].child=new person[arr[num_organization-1].capacity];
    for(int i=0;i<arr[num_organization-1].capacity;i++)
    {
        cout<<"Введiть iм'я для Person №"<<i+1<<": ";
        getStr(arr[num_organization-1].child[i].name,40);
        cout<<"Введiть досвiд роботи для Person №"<<i+1<<": ";
        arr[num_organization-1].child[i].level=getInt(0,LONG_MAX);
        cout<<"Введiть кiлькiсть characteristic для Person №"<<i+1<<": ";
        arr[num_organization-1].child[i].capacity=getInt(0,LONG_MAX);
        arr[num_organization-1].child[i].child=new characteristic[arr[num_organization-1].child[i].capacity];
    }
    int volum=0;
    for(int i=0;i<arr[num_organization-1].capacity;i++)
    {
        for(int b=0;b<arr[num_organization-1].child[i].capacity;b++)
        {
            if(b==0)
            {
                cout<<"Введiть кiлькiсть parameters в characteristic для Person №"<<i+1<<": ";
                volum=getInt(0,LONG_MAX);
            }
            arr[num_organization-1].child[i].child[b].capacity=volum;
            cout<<"Введiть назву characteristic №"<<b+1<<" для Person №"<<i+1<<": ";
            getStr(arr[num_organization-1].child[i].child[b].name,40);
            arr[num_organization-1].child[i].child[b].child=new parameters[arr[num_organization-1].child[i].child[b].capacity];
        }
    }
    for(int i=0;i<arr[num_organization-1].capacity;i++)
    {
        for(int b=0;b<arr[num_organization-1].child[i].capacity;b++)
        {
            for(int c=0;c<arr[num_organization-1].child[i].child[b].capacity;c++)
            {
                cout<<"Введiть значення parameters №"<<c+1<<" для characteristic "<<arr[num_organization-1].child[i].child[b].name<<" для Person №"<<i+1<<": ";
                getStr(arr[num_organization-1].child[i].child[b].child[c].name,40);
            }
        }
    }
    pause();
    log_save("Створити Organization");
}
void show_organization()
{
    system("cls");
    cout<<"Показ повного дерева"<<endl; line;
    if(num_organization==0){cout<<"Немає дерева"<<endl;}
    else
    {
        for(int i=0;i<num_organization;i++)
        {
            cout<<"Organization №"<<i+1<<endl<<"Назва: "<<arr[i].name<<endl<<"Плата: "<<arr[i].pay<<endl<<"Кiлькiсть осiб: "<<arr[i].capacity<<endl;
        }
    }
    pause();
    log_save("Показати повнiстю дерево");
}
void switch_organization()
{
    system("cls");
    cout<<"Змiна Organization"<<endl; line;
    int num_person_ad;
    cout<<"Введiть номер Organization:";
    num_person_ad=getInt(1,LONG_MAX);
    if(num_person_ad<=num_organization)
    {
        num_person=num_person_ad;
        num_person--;
    }
    else{cout<<"Цього дерева не iснує!"<<endl;}
    pause();
    log_save("Змiнити Organization");
}
void edit_organization()
{
    system("cls");
    cout<<"Редагування Organization"<<endl; line;
    if(num_organization==0){cout<<"Немає дерева"<<endl;}
    else
    {
        cout<<"Введiть назву Organization: ";
        getStr(arr[num_person].name,40);
        cout<<"Введiть плату Organization: ";
        arr[num_person].pay=getInt(0,LONG_MAX);
        cout<<"Введiть кiлькiсть Person: ";
        arr[num_person].capacity=getInt(0,LONG_MAX);
        arr[num_person].child=new person[arr[num_person].capacity];
        for(int i=0;i<arr[num_person].capacity;i++)
        {
            cout<<"Введiть iм'я для Person №"<<i+1<<": ";
            getStr(arr[num_person].child[i].name,40);
            cout<<"Введiть досвiд роботи для Person №"<<i+1<<": ";
            arr[num_person].child[i].level=getInt(0,LONG_MAX);
            cout<<"Введiть кiлькiсть characteristic для Person №"<<i+1<<": ";
            arr[num_person].child[i].capacity=getInt(0,LONG_MAX);
            arr[num_person].child[i].child=new characteristic[arr[num_person].child[i].capacity];
            int volum=0;
            for(int i=0;i<arr[num_person].capacity;i++)
            {
                for(int b=0;b<arr[num_person].child[i].capacity;b++)
                {
                    if(b==0)
                    {
                        cout<<"Введiть кiлькiсть parameters в characteristic для Person №"<<i+1<<": ";
                        volum=getInt(0,LONG_MAX);
                    }
                    arr[num_person].child[i].child[b].capacity=volum;
                    cout<<"Введiть назву characteristic №"<<b+1<<" для Person №"<<i+1<<": ";
                    getStr(arr[num_person].child[i].child[b].name,40);
                    arr[num_person].child[i].child[b].child=new parameters[arr[num_person].child[i].child[b].capacity];
                }
            }
            for(int i=0;i<arr[num_person].capacity;i++)
            {
                for(int b=0;b<arr[num_person].child[i].capacity;b++)
                {
                    for(int c=0;c<arr[num_person].child[i].child[b].capacity;c++)
                    {
                        cout<<"Введiть значення parameters №"<<c+1<<" для characteristic "<<arr[num_organization-1].child[i].child[b].name<<" для Person №"<<i+1<<": ";
                        getStr(arr[num_organization-1].child[i].child[b].child[c].name,40);
                    }
                }
            }
        }
    }
    pause();
    log_save("Редагувати Organization");
}
void delete_organization()
{
    system("cls");
    cout<<"Видалення Organization"<<endl; line;
    if(num_organization==0){cout<<"Немає Organization для видалення";}
    else
    {
        for(int i=num_person;i<num_organization;i++){arr[i]=arr[i+1];}
        num_organization--;
        cout<<"Organization №"<<num_person+1<<" була видалено"<<endl;
        if(num_person!=0){num_person--;}
    }
    pause();
    log_save("Видалити Organization");
}
void del_all_organization()
{
    system("cls");
    cout<<"Видалення всiх Organization"<<endl; line;
    if(num_organization==0){cout<<"Немає Organization для видалення";}
    else
    {
        for(int x=num_organization; x>0;x--)
        {
            for(int i=num_person;i<num_organization;i++){arr[i]=arr[i+1];}
            num_organization--;
            if(num_person!=0){num_person--;}
        }
        cout<<"Всi organization були видаленi"<<endl;
    }
    pause();
    log_save("Видалити всi Organization");
}
