#include "types.h"
extern organization *arr;
void characteristic_menu()
{
    log_save("����i� �� ���� Characteristic");
    system("cls");
    if(arr[num_person].capacity<=0||arr[num_person].capacity>UCHAR_MAX){cout<<"����� Characteristic"<<endl;}
    else
    {
        while(true)
        {
            system("cls");
            cout<<"Organization �"<<num_organization<<": "<<arr[num_organization-1].name<<" / "<<"Person �"<<num_characteristic+1<<": "<<arr[num_organization-1].child[num_characteristic].name<<" / "<<"Characteristic �"<<num_parameters+1<<": "<<arr[num_organization-1].child[num_characteristic].child[num_parameters].name<<endl; line;
            menu_unit menu_2[]={{"�⢮�� Characteristic", add_characteristic},
                                {"������� ��i Characteristic", show_characteristic},
                                {"������� ����i��� ��ॢ�", show_full_tree},
                                {"��i��� Characteristic", switch_characteristic},
                                {"�����㢠� Characteristic", edit_characteristic},
                                {"������� Characteristic", delete_characteristic},
                                {"������� ��i Characteristic", del_all_characteristic},
                                {"��३� �� Parameters ����", parameters_menu},
                                {"�����", person_menu},
                                {"��३� �� ��������� ����", main_menu},
                                {"���i�", NULL},};
            for(int i=0;i<11;i++){cout<<i+1<<" "<<menu_2[i].text<<endl;}
            cout<<"\n���i�� �᫮ �㭪�: ";
            int v=getInt(1,11);
            for(int b=0;b<11;b++)
            {
                if(v==11){log_save("���i�"); exit(0);}
                if(v==(b+1)){menu_2[b].func();}
            }
        }
    }
    pause();
}
void add_characteristic()
{
    system("cls");
    cout<<"�⢮७�� Characteristic"<<endl; line;
    arr[num_person].child[num_characteristic].capacity++;
    characteristic *ar_2=new characteristic[arr[num_person].child[num_characteristic].capacity];
    memcpy(ar_2, arr[num_person].child[num_characteristic].child, sizeof(characteristic)*arr[num_person].child[num_characteristic].capacity);
    arr[num_person].child[num_characteristic].child=new characteristic[arr[num_person].child[num_characteristic].capacity];
    arr[num_person].child[num_characteristic].child=ar_2;
    cout<<"����i�� ����� characteristic �"<<arr[num_person].child[num_characteristic].capacity<<" ��� Person �"<<num_characteristic+1<<": ";
    getStr(arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].name,40);
    cout<<"����i�� �i��i��� parameters � characteristic �"<<arr[num_person].child[num_characteristic].capacity<<" ��� Person �"<<num_characteristic+1<<": ";
    arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].capacity=getInt(0,LONG_MAX);
    arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].child=new parameters[ arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].capacity];
    for(int b=0; b<arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].capacity;b++)
    {
        cout<<"����i�� ���祭�� parameters �"<<b+1<<" � characteristic �"<<arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].capacity<<": ";
        getStr(arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].child[b].name,40);
    }
    pause();
    log_save("�⢮�� Characteristic");
}
void show_characteristic()
{
    system("cls");
    cout<<"����� ��i� Characteristic"<<endl; line;
    if(arr[num_person].child[num_characteristic].capacity>=1&&arr[num_person].child[num_characteristic].capacity<=UCHAR_MAX)
    {
        cout<<"      �haracteristics: ";
        int i=0;
        cout<<arr[num_person].child[num_characteristic].child[i].name; i++;
        if(arr[num_person].child[num_characteristic].capacity>1)
        {
            do{cout<<", "<<arr[num_person].child[num_characteristic].child[i].name; i++;}
            while(i<arr[num_person].child[num_characteristic].capacity);
        }
        if(arr[num_person].child[num_characteristic].child[i].capacity<=0&&arr[num_person].child[num_characteristic].child[i].capacity>UCHAR_MAX){cout<<endl<<"        ����� parameters";}
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
        cout<<endl<<"      ����� characteristic"<<endl;
    }
    pause();
    log_save("������� ��i Characteristic");
}
void switch_characteristic()
{
    system("cls");
    cout<<"��i�� Characteristic"<<endl; line;
    int num_parameters_ad;
    cout<<"����i�� ����� Characteristic: ";
    num_parameters_ad=getInt(1,LONG_MAX);
    if(num_parameters_ad<=arr[num_person].child[num_characteristic&&num_parameters_ad>=1].capacity)
    {
        num_parameters=num_parameters_ad;
        num_parameters--;
    }
    else{cout<<"����� ��ॢ�"<<endl;}
    pause();
    log_save("��i��� Characteristic");
}
void edit_characteristic()
{
    system("cls");
    cout<<"�����㢠��� Characteristic"<<endl; line;
    if(arr[num_person].child[num_characteristic].capacity==0){cout<<"����� ��ॢ�"<<endl;}
    else
    {
        for(int i=0;i<arr[num_person].child[num_characteristic].capacity;i++)
        {
            cout<<"����i�� ����� characteristic �"<<i+1<<" ��� Person �"<<num_characteristic+1<<": ";
            getStr(arr[num_person].child[num_characteristic].child[i].name,40);
            cout<<"����i�� �i��i��� parameters � characteristic �"<<i+1<<" ��� Person �"<<num_characteristic+1<<": ";
            arr[num_person].child[num_characteristic].child[i].capacity=getInt(0,LONG_MAX);
            arr[num_person].child[num_characteristic].child[i].child=new parameters[arr[num_person].child[num_characteristic].child[i].capacity];
            for(int c=0;c<arr[num_person].child[num_characteristic].child[i].capacity;c++)
            {
                cout<<"����i�� ���祭�� parameters �"<<c+1<<" � characteristic �"<<i+1<<": ";
                getStr(arr[num_person].child[num_characteristic].child[i].child[c].name,40);
            }
        }
    }
    pause();
    log_save("�����㢠� Characteristic");
}
void delete_characteristic()
{
    system("cls");
    cout<<"��������� Characteristic"<<endl; line;
    int characteristic_delete;
    if(arr[num_person].child[num_characteristic].capacity==0){cout<<"����� Characteristic ��� ���������";}
    else
    {
        cout<<"����i�� ����� characteristic �� �㤥 ��������: ";
        characteristic_delete=getInt(0,LONG_MAX);
        characteristic_delete--;
        for(int i=characteristic_delete;i<arr[num_person].child[num_characteristic].capacity;i++)
        {
            arr[num_person].child[num_characteristic].child[i]=arr[num_person].child[num_characteristic].child[i+1];
        }
        arr[num_person].child[num_characteristic].capacity--;
        cout<<"Characteristic �"<<characteristic_delete+1<<" "<<arr[num_person].child[num_characteristic].child[arr[num_person].child[num_characteristic].capacity-1].name<<" � person �"<<num_characteristic+1<<" �㤠 ��������";
    }
    pause();
    if(arr[num_person].child[num_characteristic].capacity==0){person_menu();}
    log_save("������� Characteristic");
    pause();
}
void del_all_characteristic()
{
    system("cls");
    cout<<"��������� ��i� Characteristic"<<endl; line;
    if(arr[num_person].child[num_characteristic].capacity==0){cout<<"����� Characteristic ��� ���������";}
    else
    {
        for(int x=arr[num_person].child[num_characteristic].capacity; x>0;x--)
        {
            arr[num_person].child[num_characteristic].child[x]=arr[num_person].child[num_characteristic].child[x+1];
            arr[num_person].child[num_characteristic].capacity--;
        }
        cout<<"��i Characteristic �㫨 �������i"<<endl;
    }
    pause();
    log_save("������� ��i Characteristic");
}
