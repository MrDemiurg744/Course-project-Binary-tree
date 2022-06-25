#include "types.h"
extern organization *arr;
void person_menu()
{
    log_save("Перехiд до меню Person");
    system("cls");
    if(arr[num_person].capacity<=0||arr[num_person].capacity>UCHAR_MAX){cout<<"Немає Person"<<endl;}
    else
    {
        while(true)
        {
            system("cls");
            cout<<"Organization №"<<num_organization<<": "<<arr[num_organization-1].name<<" / "<<"Person №"<<num_characteristic+1<<": "<<arr[num_organization-1].child[num_characteristic].name<<endl; line;
            menu_unit menu_2[]={{"Створити Person", add_person},
                                {"Показати всi Person", show_person},
                                {"Показати повнiстю дерево", show_full_tree},
                                {"Змiнити Person", switch_person},
                                {"Редагувати Person", edit_person},
                                {"Видалити Person", delete_person},
                                {"Видалити всi Person", del_all_person},
                                {"Перейти до Characteristic меню", characteristic_menu},
                                {"Назад", organization_menu},
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
void add_person()
{
    system("cls");
    cout<<"Створення Person"<<endl; line;
    if(num_organization==0){cout<<"Немає дерева"<<endl;}
    else
    {
        arr[num_person].capacity++;
        person *ar_2=new person[arr[num_person].capacity];
        memcpy(ar_2, arr[num_person].child, sizeof(person)*arr[num_person].capacity);
        arr[num_person].child=new person[arr[num_person].capacity];
        arr[num_person].child=ar_2;
        cout<<"Введiть iм'я для Person №"<<num_person+1<<" в Organization "<<arr[num_person].name<<": ";
        getStr(arr[num_person].child[arr[num_person].capacity-1].name,40);
        cout<<"Введiть досвiд роботи для Person №"<<num_person+1<<" в Organization "<<arr[num_person].name<<": ";
        arr[num_person].child[arr[num_person].capacity-1].level=getInt(0,LONG_MAX);
        cout<<"Введiть кiлькiсть characteristic для Person №"<<num_person+1<<" в Organization "<<arr[num_person].name<<": ";
        arr[num_person].child[arr[num_person].capacity-1].capacity=getInt(0,LONG_MAX);
        arr[num_person].child[arr[num_person].capacity-1].child=new characteristic[arr[num_person].child[arr[num_person].capacity-1].capacity];
        for(int b=0; b<arr[num_person].child[arr[num_person].capacity-1].capacity;b++)
        {
            cout<<"Введiть назву characteristic №"<<b+1<<": ";
            getStr(arr[num_person].child[arr[num_person].capacity-1].child[b].name,40);
            cout<<"Введiть кiлькiсть parameters в characteristic "<<arr[num_person].child[arr[num_person].capacity-1].child[b].name<<": ";
            arr[num_person].child[arr[num_person].capacity-1].child[b].capacity=getInt(0,LONG_MAX);
            arr[num_person].child[arr[num_person].capacity-1].child[b].child=new parameters[arr[num_person].child[arr[num_person].capacity-1].child[b].capacity];
        }
        for(int b=0; b<arr[num_person].child[arr[num_person].capacity-1].capacity;b++)
        {
            for(int i=0; i<arr[num_person].child[arr[num_person].capacity-1].child[b].capacity;i++){
                cout<<"Введiть значення parameters №"<<i+1<<" для characteristic "<<arr[num_person].child[arr[num_person].capacity-1].child[b].name<<": ";
                getStr(arr[num_person].child[arr[num_person].capacity-1].child[b].child[i].name,40);
            }
        }
    }
    pause();
    log_save("Створити Person");
}
void show_person()
{
    system("cls");
    cout<<"Показ всiх Person"<<endl; line;
    for(int i=0;i<arr[num_person].capacity;i++)
    {
        cout<<"Person №"<<i+1<<", iм'я "<<arr[num_person].child[i].name<<", досвiд роботи "<<arr[num_person].child[i].level<<" кiлькiсть characteristic: "<<arr[num_person].child[i].capacity<<endl;
    }
    pause();
    log_save("Показати всi Person");
}
void switch_person()
{
    system("cls");
    cout<<"Змiна Person"<<endl; line;
    int num_characteristic_ad;
    cout<<"Введiть номер Person: ";
    num_characteristic_ad=getInt(1,LONG_MAX);
    if(num_characteristic_ad<=arr[num_person].capacity&&num_characteristic_ad>=1)
    {
        num_characteristic=num_characteristic_ad;
        num_characteristic--;
    }
    else{cout<<"Немає дерева"<<endl;}
    log_save("Змiнити Person");
    pause();
}
void edit_person()
{
    system("cls");
    cout<<"Редагування Person"<<endl; line;
    if(num_organization==0){cout<<"Немає дерева"<<endl;}
    else
    {
        for(int i=0;i<arr[num_person].capacity;i++)
        {
            cout<<"Введiть iм'я для Person №"<<arr[num_person].name<<" в Organization "<<arr[num_organization-1].name<<": ";
            getStr(arr[num_person].child[i].name,40);
            cout<<"Введiть досвiд роботи для Person №"<<arr[num_person].name<<" в Organization "<<arr[num_organization-1].name<<": ";;
            arr[num_person].child[i].level=getInt(0,LONG_MAX);
            cout<<"Введiть кiлькiсть characteristic для Person №"<<arr[num_person].name<<" в Organization "<<arr[num_organization-1].name<<": ";
            arr[num_person].child[i].capacity=getInt(0,LONG_MAX);
            arr[num_person].child[i].child=new characteristic[arr[num_person].child[i].capacity];
            for (int b=0;b<arr[num_person].child[i].capacity;b++)
            {
                cout<<"Введiть назву characteristic №"<<b+1<<" для Person "<<arr[num_person].child[i].name<<" в Organization "<<arr[num_organization-1].name<<": ";
                getStr(arr[num_person].child[i].child[b].name,40);
                cout<<"Введiть кiлькiсть витрат для characteristic №"<<b+1 <<" для Person "<<arr[num_person].child[i].name<<" в Organization "<<arr[num_organization-1].name<<": ";
                arr[num_person].child[i].child[b].capacity=getInt(0,LONG_MAX);
                arr[num_person].child[i].child[b].child=new parameters[arr[num_person].child[i].child[b].capacity];
                for(int c=0;c<arr[num_person].child[i].child[b].capacity;c++)
                {
                    cout<<"Введiть значення parameters №"<<b+1<<" для characteristic "<<arr[num_organization-1].child[i].child[b].name<<": ";
                    getStr(arr[num_person].child[i].child[b].child[c].name,40);
                }
            }
        }
    }
    pause();
    log_save("Редагувати Person");
}
void delete_person()
{
    system("cls");
    cout<<"Видалення Person"<<endl; line;
    int person_delete;
    if(arr[num_person].capacity==0){cout<<"Немає Person для видалення";}
    else
    {
        cout<<"Введiть номер Person яку буде видалено: ";
        person_delete=getInt(0,LONG_MAX);
        person_delete--;
        for(int i=person_delete;i<arr[num_person].capacity;i++)
        {
            arr[num_person].child[i]=arr[num_person].child[i+1];
        }
        arr[num_person].capacity--;
        cout<<"Person №"<<person_delete+1<<" в Organization №"<<num_person+1<<" була видалена"<<endl;
        num_characteristic=0;
    }
    if(arr[num_person].capacity==0){organization_menu();}
    pause();
    log_save("Видалити Person");
}
void del_all_person()
{
    system("cls");
    cout<<"Видалення всiх Person"<<endl; line;
    if(arr[num_person].capacity==0){cout<<"Немає Person для видалення";}
    else
    {
        for(int x=arr[num_person].capacity; x>0;x--)
        {
            arr[num_person].child[x]=arr[num_person].child[x+1];
            arr[num_person].capacity--;
        }
        cout<<"Всi Person були видаленi"<<endl;
    }
    pause();
    log_save("Видалити всi Person");
}
