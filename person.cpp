#include "types.h"
extern organization *arr;
void person_menu()
{
    log_save("����i� �� ���� Person");
    system("cls");
    if(arr[num_person].capacity<=0||arr[num_person].capacity>UCHAR_MAX){cout<<"����� Person"<<endl;}
    else
    {
        while(true)
        {
            system("cls");
            cout<<"Organization �"<<num_organization<<": "<<arr[num_organization-1].name<<" / "<<"Person �"<<num_characteristic+1<<": "<<arr[num_organization-1].child[num_characteristic].name<<endl; line;
            menu_unit menu_2[]={{"�⢮�� Person", add_person},
                                {"������� ��i Person", show_person},
                                {"������� ����i��� ��ॢ�", show_full_tree},
                                {"��i��� Person", switch_person},
                                {"�����㢠� Person", edit_person},
                                {"������� Person", delete_person},
                                {"������� ��i Person", del_all_person},
                                {"��३� �� Characteristic ����", characteristic_menu},
                                {"�����", organization_menu},
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
void add_person()
{
    system("cls");
    cout<<"�⢮७�� Person"<<endl; line;
    if(num_organization==0){cout<<"����� ��ॢ�"<<endl;}
    else
    {
        arr[num_person].capacity++;
        person *ar_2=new person[arr[num_person].capacity];
        memcpy(ar_2, arr[num_person].child, sizeof(person)*arr[num_person].capacity);
        arr[num_person].child=new person[arr[num_person].capacity];
        arr[num_person].child=ar_2;
        cout<<"����i�� i�'� ��� Person �"<<num_person+1<<" � Organization "<<arr[num_person].name<<": ";
        getStr(arr[num_person].child[arr[num_person].capacity-1].name,40);
        cout<<"����i�� ���i� ஡�� ��� Person �"<<num_person+1<<" � Organization "<<arr[num_person].name<<": ";
        arr[num_person].child[arr[num_person].capacity-1].level=getInt(0,LONG_MAX);
        cout<<"����i�� �i��i��� characteristic ��� Person �"<<num_person+1<<" � Organization "<<arr[num_person].name<<": ";
        arr[num_person].child[arr[num_person].capacity-1].capacity=getInt(0,LONG_MAX);
        arr[num_person].child[arr[num_person].capacity-1].child=new characteristic[arr[num_person].child[arr[num_person].capacity-1].capacity];
        for(int b=0; b<arr[num_person].child[arr[num_person].capacity-1].capacity;b++)
        {
            cout<<"����i�� ����� characteristic �"<<b+1<<": ";
            getStr(arr[num_person].child[arr[num_person].capacity-1].child[b].name,40);
            cout<<"����i�� �i��i��� parameters � characteristic "<<arr[num_person].child[arr[num_person].capacity-1].child[b].name<<": ";
            arr[num_person].child[arr[num_person].capacity-1].child[b].capacity=getInt(0,LONG_MAX);
            arr[num_person].child[arr[num_person].capacity-1].child[b].child=new parameters[arr[num_person].child[arr[num_person].capacity-1].child[b].capacity];
        }
        for(int b=0; b<arr[num_person].child[arr[num_person].capacity-1].capacity;b++)
        {
            for(int i=0; i<arr[num_person].child[arr[num_person].capacity-1].child[b].capacity;i++){
                cout<<"����i�� ���祭�� parameters �"<<i+1<<" ��� characteristic "<<arr[num_person].child[arr[num_person].capacity-1].child[b].name<<": ";
                getStr(arr[num_person].child[arr[num_person].capacity-1].child[b].child[i].name,40);
            }
        }
    }
    pause();
    log_save("�⢮�� Person");
}
void show_person()
{
    system("cls");
    cout<<"����� ��i� Person"<<endl; line;
    for(int i=0;i<arr[num_person].capacity;i++)
    {
        cout<<"Person �"<<i+1<<", i�'� "<<arr[num_person].child[i].name<<", ���i� ஡�� "<<arr[num_person].child[i].level<<" �i��i��� characteristic: "<<arr[num_person].child[i].capacity<<endl;
    }
    pause();
    log_save("������� ��i Person");
}
void switch_person()
{
    system("cls");
    cout<<"��i�� Person"<<endl; line;
    int num_characteristic_ad;
    cout<<"����i�� ����� Person: ";
    num_characteristic_ad=getInt(1,LONG_MAX);
    if(num_characteristic_ad<=arr[num_person].capacity&&num_characteristic_ad>=1)
    {
        num_characteristic=num_characteristic_ad;
        num_characteristic--;
    }
    else{cout<<"����� ��ॢ�"<<endl;}
    log_save("��i��� Person");
    pause();
}
void edit_person()
{
    system("cls");
    cout<<"�����㢠��� Person"<<endl; line;
    if(num_organization==0){cout<<"����� ��ॢ�"<<endl;}
    else
    {
        for(int i=0;i<arr[num_person].capacity;i++)
        {
            cout<<"����i�� i�'� ��� Person �"<<arr[num_person].name<<" � Organization "<<arr[num_organization-1].name<<": ";
            getStr(arr[num_person].child[i].name,40);
            cout<<"����i�� ���i� ஡�� ��� Person �"<<arr[num_person].name<<" � Organization "<<arr[num_organization-1].name<<": ";;
            arr[num_person].child[i].level=getInt(0,LONG_MAX);
            cout<<"����i�� �i��i��� characteristic ��� Person �"<<arr[num_person].name<<" � Organization "<<arr[num_organization-1].name<<": ";
            arr[num_person].child[i].capacity=getInt(0,LONG_MAX);
            arr[num_person].child[i].child=new characteristic[arr[num_person].child[i].capacity];
            for (int b=0;b<arr[num_person].child[i].capacity;b++)
            {
                cout<<"����i�� ����� characteristic �"<<b+1<<" ��� Person "<<arr[num_person].child[i].name<<" � Organization "<<arr[num_organization-1].name<<": ";
                getStr(arr[num_person].child[i].child[b].name,40);
                cout<<"����i�� �i��i��� ����� ��� characteristic �"<<b+1 <<" ��� Person "<<arr[num_person].child[i].name<<" � Organization "<<arr[num_organization-1].name<<": ";
                arr[num_person].child[i].child[b].capacity=getInt(0,LONG_MAX);
                arr[num_person].child[i].child[b].child=new parameters[arr[num_person].child[i].child[b].capacity];
                for(int c=0;c<arr[num_person].child[i].child[b].capacity;c++)
                {
                    cout<<"����i�� ���祭�� parameters �"<<b+1<<" ��� characteristic "<<arr[num_organization-1].child[i].child[b].name<<": ";
                    getStr(arr[num_person].child[i].child[b].child[c].name,40);
                }
            }
        }
    }
    pause();
    log_save("�����㢠� Person");
}
void delete_person()
{
    system("cls");
    cout<<"��������� Person"<<endl; line;
    int person_delete;
    if(arr[num_person].capacity==0){cout<<"����� Person ��� ���������";}
    else
    {
        cout<<"����i�� ����� Person �� �㤥 ��������: ";
        person_delete=getInt(0,LONG_MAX);
        person_delete--;
        for(int i=person_delete;i<arr[num_person].capacity;i++)
        {
            arr[num_person].child[i]=arr[num_person].child[i+1];
        }
        arr[num_person].capacity--;
        cout<<"Person �"<<person_delete+1<<" � Organization �"<<num_person+1<<" �㫠 ��������"<<endl;
        num_characteristic=0;
    }
    if(arr[num_person].capacity==0){organization_menu();}
    pause();
    log_save("������� Person");
}
void del_all_person()
{
    system("cls");
    cout<<"��������� ��i� Person"<<endl; line;
    if(arr[num_person].capacity==0){cout<<"����� Person ��� ���������";}
    else
    {
        for(int x=arr[num_person].capacity; x>0;x--)
        {
            arr[num_person].child[x]=arr[num_person].child[x+1];
            arr[num_person].capacity--;
        }
        cout<<"��i Person �㫨 �������i"<<endl;
    }
    pause();
    log_save("������� ��i Person");
}
