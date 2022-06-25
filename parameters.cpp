#include "types.h"
extern organization *arr;
void parameters_menu()
{
    log_save("Перехiд до меню Parameters");
    system("cls");
    if(arr[num_person].capacity<=0||arr[num_person].capacity>UCHAR_MAX){cout<<"Немає Parameters"<<endl;}
    else
    {
        while(true)
        {
            system("cls");
            cout<<"Organization №"<<num_organization<<": "<<arr[num_organization-1].name<<" / "<<"Person №"<<num_characteristic+1<<": "<<arr[num_organization-1].child[num_characteristic].name<<" / "<<"Characteristic №"<<num_parameters+1<<": "<<arr[num_organization-1].child[num_characteristic].child[num_parameters].name<<" / "<<"Parameters №"<<num_data+1<<": "<<arr[num_person].child[num_characteristic].child[num_parameters].child[num_data].name<<endl; line;
            menu_unit menu_2[]={{"Створити Parameters", add_parameters},
                                {"Показати всi Parameters", show_parameters},
                                {"Показати повнiстю дерево", show_full_tree},
                                {"Змiнити Parameters", switch_parameters},
                                {"Редагувати Parameters", edit_parameters},
                                {"Видалити Parameters", delete_parameters},
                                {"Видалити всi Parameters", del_all_parameters},
                                {"Назад", characteristic_menu},
                                {"Перейти до головного меню", main_menu},
                                {"Вихiд", NULL},};
            for(int i=0;i<10;i++){cout<<i+1<<" "<<menu_2[i].text<<endl;}
            cout<<"\nВедiть число пункта: ";
            int v=getInt(1,10);
            for(int b=0;b<10;b++)
            {
                if(v==10){log_save("Вихiд"); exit(0);}
                if(v==(b+1)){menu_2[b].func();}
            }
        }
    }
    pause();
}
void add_parameters()
{
    system("cls");
    cout<<"Створення parameters"<<endl; line;
    arr[num_person].child[num_characteristic].child[num_parameters].capacity++;
    parameters *ar_2=new parameters[arr[num_person].child[num_characteristic].child[num_parameters].capacity];
    memcpy(ar_2, arr[num_person].child[num_characteristic].child[num_parameters].child, sizeof(parameters)*arr[num_person].child[num_characteristic].child[num_parameters].capacity);
    arr[num_person].child[num_characteristic].child[num_parameters].child=new parameters[arr[num_person].child[num_characteristic].child[num_parameters].capacity];
    arr[num_person].child[num_characteristic].child[num_parameters].child=ar_2;
    cout<<"Введiть значення Parameters №"<<arr[num_person].child[num_characteristic].child[num_parameters].capacity<<" в Characteristic №"<<num_parameters+1<<": ";
    getStr(arr[num_person].child[num_characteristic].child[num_parameters].child[arr[num_person].child[num_characteristic].child[num_parameters].capacity-1].name,40);
    log_save("Створити parameters");
    pause();
}
void show_parameters()
{
    system("cls");
    cout<<"Показ всiх Parameters"<<endl; line;
    cout<<"Значення "<<arr[num_person].child[num_characteristic].child[num_parameters].name<<" в characteristic №"<<num_parameters+1<<": "<<endl;
    for(int i=0;i<arr[num_person].child[num_characteristic].child[num_parameters].capacity;i++)
    {
        cout<<arr[num_person].child[num_characteristic].child[num_parameters].child[i].name<<endl;
    }
    log_save("Показати всi Parameters");
    pause();
}
void switch_parameters()
{
    system("cls");
    cout<<"Змiна Parameters"<<endl; line;
    int num_data_ad;
    cout<<"Введiть номер Parameters: ";
    num_data_ad=getInt(1,LONG_MAX);
    if(num_data_ad<=arr[num_person].child[num_characteristic].child[num_parameters&&num_data_ad>=1].capacity)
    {
        num_data=num_data_ad;
        num_data--;
    }
    else{cout<<"Немає дерева"<<endl;}
    log_save("Змiнити Parameters");
    pause();
}
void edit_parameters()
{
    system("cls");
    cout<<"Редагування Parameters"<<endl; line;
    if(arr[num_person].child[num_characteristic].child[num_parameters].capacity==0){cout<<"No trees";}
    else
    {
        for(int i=0;i<arr[num_person].child[num_characteristic].child[num_parameters].capacity;i++){
            cout<<"Введiть parameters в characteristic №"<<num_parameters+1<<": ";
            getStr(arr[num_person].child[num_characteristic].child[num_parameters].child[i].name,40);
        }
        for(int i=0;i<arr[num_person].child[num_characteristic].child[num_parameters].capacity;i++)
        {
            cout<<endl<<arr[num_person].child[num_characteristic].child[num_parameters].child[i].name<<" ";
        }
    }
    pause();
    log_save("Редагувати Parameters");
}
void delete_parameters()
{
    system("cls");
    cout<<"Видалення Parameters"<<endl; line;
    int parameters_delete;
    if(arr[num_person].child[num_characteristic].child[num_parameters].capacity==0){cout<<"No parameters to delete";}
    else
    {
        cout<<"Введiть номер parameters яку буде видалено: ";
        parameters_delete=getInt(0,LONG_MAX);
        parameters_delete--;
        for(int i=parameters_delete;i<arr[num_person].child[num_characteristic].child[num_parameters].capacity;i++)
        {
            arr[num_person].child[num_characteristic].child[num_parameters].child[i]=arr[num_person].child[num_characteristic].child[num_parameters].child[i+1];
        }
        arr[num_person].child[num_characteristic].child[num_parameters].capacity--;
        cout<<"Parameters №"<<parameters_delete+1<<" в characteristic №"<<num_parameters+1<<" був видалениий";
    }
    if(arr[num_person].child[num_characteristic].child[num_parameters].capacity==0){characteristic_menu();}
    log_save("Видалити Parameters");
    pause();
}
void del_all_parameters()
{
    system("cls");
    cout<<"Видалення всiх Parameters"<<endl; line;
    if(arr[num_person].child[num_characteristic].child[num_parameters].capacity==0){cout<<"Немає Parameters для видалення";}
    else
    {
        for(int x=arr[num_person].child[num_characteristic].child[num_parameters].capacity; x>0;x--)
        {
            arr[num_person].child[num_characteristic].child[num_parameters].child[x]=arr[num_person].child[num_characteristic].child[num_parameters].child[x];
            arr[num_person].child[num_characteristic].child[num_parameters].capacity--;
        }
        cout<<"Всi Parameters були видаленi"<<endl;
    }
    pause();
    log_save("Видалити всi Parameters");
}


