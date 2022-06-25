#include "types.h"
extern organization *arr;
void characteristic_menu()
{
    log_save("Перехiд до меню Characteristic");
    system("cls");
    if(arr[num_person].capacity<=0||arr[num_person].capacity>UCHAR_MAX){cout<<"Немає Characteristic"<<endl;}
    else
    {
        while(true)
        {
            system("cls");
            cout<<"Organization №"<<num_organization<<": "<<arr[num_organization-1].name<<" / "<<"Person №"<<num_characteristic+1<<": "<<arr[num_organization-1].child[num_characteristic].name<<" / "<<"Characteristic №"<<num_parameters+1<<": "<<arr[num_organization-1].child[num_characteristic].child[num_parameters].name<<endl; line;
            menu_unit menu_2[]={{"Створити Characteristic", add_characteristic},
                                {"Показати всi Characteristic", show_characteristic},
                                {"Показати повнiстю дерево", show_full_tree},
                                {"Змiнити Characteristic", switch_characteristic},
                                {"Редагувати Characteristic", edit_characteristic},
                                {"Видалити Characteristic", delete_characteristic},
                                {"Видалити всi Characteristic", del_all_characteristic},
                                {"Перейти до Parameters меню", parameters_menu},
                                {"Назад", person_menu},
                                {"Перейти до головного меню", main_menu},
                                {"Вихiд", NULL},};
            for(int i=0;i<11;i++){cout<<i+1<<" "<<menu_2[i].text<<endl;}
            cout<<"\nВедiть число пункта: ";
            int v=getInt(1,11);
            for(int b=0;b<11;b++)
            {
                if(v==11){log_save("Вихiд"); exit(0);}
                if(v==(b+1)){menu_2[b].func();}
            }
        }
    }
    pause();
}
void add_characteristic()
{
    system("cls");
    cout<<"Створення Characteristic"<<endl; line;
    arr[num_person].child[num_characteristic].capacity++;
    characteristic *ar_2=new characteristic[arr[num_person].child[num_characteristic].capacity];
    memcpy(ar_2, arr[num_person].child[num_characteristic].child, sizeof(characteristic)*arr[num_person].child[num_characteristic].capacity);
    arr[num_person].child[num_characteristic].child=new characteristic[arr[num_person].child[num_characteristic].capacity];
    arr[num_person].child[num_characteristic].child=ar_2;
    cout<<"Введiть назву characteristic №"<<arr[num_person].child[num_characteristic].capacity<<" для Person №"<<num_characteristic+1<<": ";
    getStr(arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].name,40);
    cout<<"Введiть кiлькiсть parameters в characteristic №"<<arr[num_person].child[num_characteristic].capacity<<" для Person №"<<num_characteristic+1<<": ";
    arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].capacity=getInt(0,LONG_MAX);
    arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].child=new parameters[ arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].capacity];
    for(int b=0; b<arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].capacity;b++)
    {
        cout<<"Введiть значення parameters №"<<b+1<<" в characteristic №"<<arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].capacity<<": ";
        getStr(arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].child[b].name,40);
    }
    pause();
    log_save("Створити Characteristic");
}
void show_characteristic()
{
    system("cls");
    cout<<"Показ всiх Characteristic"<<endl; line;
    if(arr[num_person].child[num_characteristic].capacity>=1&&arr[num_person].child[num_characteristic].capacity<=UCHAR_MAX)
    {
        cout<<"      Сharacteristics: ";
        int i=0;
        cout<<arr[num_person].child[num_characteristic].child[i].name; i++;
        if(arr[num_person].child[num_characteristic].capacity>1)
        {
            do{cout<<", "<<arr[num_person].child[num_characteristic].child[i].name; i++;}
            while(i<arr[num_person].child[num_characteristic].capacity);
        }
        if(arr[num_person].child[num_characteristic].child[i].capacity<=0&&arr[num_person].child[num_characteristic].child[i].capacity>UCHAR_MAX){cout<<endl<<"        Немає parameters";}
        else
        {
            cout<<endl<<"        Parameters: "<<endl;
            for(int c=0;c<arr[num_person].child[num_characteristic].capacity;c++)
            {
                cout<<"        Characteristic "<<arr[num_person].child[num_characteristic].child[c].name<<": "<<endl;
                for(int i=0;i<arr[num_person].child[num_characteristic].child[c].capacity;i++)
                {
                    cout<<"        "<<arr[num_person].child[num_characteristic].child[c].child[i].name<<endl;
                }
            }
        }
    }
    else
    {
        cout<<endl<<"      Немає characteristic"<<endl;
    }
    pause();
    log_save("Показати всi Characteristic");
}
void switch_characteristic()
{
    system("cls");
    cout<<"Змiна Characteristic"<<endl; line;
    int num_parameters_ad;
    cout<<"Введiть номер Characteristic: ";
    num_parameters_ad=getInt(1,LONG_MAX);
    if(num_parameters_ad<=arr[num_person].child[num_characteristic&&num_parameters_ad>=1].capacity)
    {
        num_parameters=num_parameters_ad;
        num_parameters--;
    }
    else{cout<<"Немає дерева"<<endl;}
    pause();
    log_save("Змiнити Characteristic");
}
void edit_characteristic()
{
    system("cls");
    cout<<"Редагування Characteristic"<<endl; line;
    if(arr[num_person].child[num_characteristic].capacity==0){cout<<"Немає дерева"<<endl;}
    else
    {
        for(int i=0;i<arr[num_person].child[num_characteristic].capacity;i++)
        {
            cout<<"Введiть назву characteristic №"<<i+1<<" для Person №"<<num_characteristic+1<<": ";
            getStr(arr[num_person].child[num_characteristic].child[i].name,40);
            cout<<"Введiть кiлькiсть parameters в characteristic №"<<i+1<<" для Person №"<<num_characteristic+1<<": ";
            arr[num_person].child[num_characteristic].child[i].capacity=getInt(0,LONG_MAX);
            arr[num_person].child[num_characteristic].child[i].child=new parameters[arr[num_person].child[num_characteristic].child[i].capacity];
            for(int c=0;c<arr[num_person].child[num_characteristic].child[i].capacity;c++)
            {
                cout<<"Введiть значення parameters №"<<c+1<<" в characteristic №"<<i+1<<": ";
                getStr(arr[num_person].child[num_characteristic].child[i].child[c].name,40);
            }
        }
    }
    pause();
    log_save("Редагувати Characteristic");
}
void delete_characteristic()
{
    system("cls");
    cout<<"Видалення Characteristic"<<endl; line;
    int characteristic_delete;
    if(arr[num_person].child[num_characteristic].capacity==0){cout<<"Немає Characteristic для видалення";}
    else
    {
        cout<<"Введiть номер characteristic яку буде видалено: ";
        characteristic_delete=getInt(0,LONG_MAX);
        characteristic_delete--;
        for(int i=characteristic_delete;i<arr[num_person].child[num_characteristic].capacity;i++)
        {
            arr[num_person].child[num_characteristic].child[i]=arr[num_person].child[num_characteristic].child[i+1];
        }
        arr[num_person].child[num_characteristic].capacity--;
        cout<<"Characteristic №"<<characteristic_delete+1<<" "<<arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].name<<" у person №"<<num_characteristic+1<<" буда видалена";
    }
    pause();
    if(arr[num_person].child[num_characteristic].capacity==0){person_menu();}
    log_save("Видалити Characteristic");
    pause();
}
void del_all_characteristic()
{
    system("cls");
    cout<<"Видалення всiх Characteristic"<<endl; line;
    if(arr[num_person].child[num_characteristic].capacity==0){cout<<"Немає Characteristic для видалення";}
    else
    {
        for(int x=arr[num_person].child[num_characteristic].capacity; x>0;x--)
        {
            arr[num_person].child[num_characteristic].child[x]=arr[num_person].child[num_characteristic].child[x+1];
            arr[num_person].child[num_characteristic].capacity--;
        }
        cout<<"Всi Characteristic були видаленi"<<endl;
    }
    pause();
    log_save("Видалити всi Characteristic");
}
