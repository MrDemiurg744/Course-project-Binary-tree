#include "types.h"
int num_organization=0;
int num_person=0;
int num_characteristic=0;
int num_parameters=0;
int num_data=0;
organization *arr=new organization[num_organization];
void organization_menu()
{
    log_save("����i� �� ���� Organization");
    while(true)
    {
        system("cls");
        if(num_organization==0){cout<<"Organization �"<<num_person+1<<endl;}
        else{cout<<"Organization �"<<num_person+1<<": "<<arr[num_organization-1].name<<endl;} line;
        menu_unit menu[]={{"�⢮�� Organization", add_organization},
                          {"������� ��i Organization", show_organization},
                          {"������� ����i��� ��ॢ�", show_full_tree},
                          {"��i��� Organization", switch_organization},
                          {"�����㢠� Organization", edit_organization},
                          {"������� Organization", delete_organization},
                          {"������� ��i Organization", del_all_organization},
                          {"��३� �� Person ����", person_menu},
                          {"��३� �� ��������� ����", main_menu},
                          {"���i�", NULL},};
        for(int i=0;i<10;i++){cout<<i+1<<" "<<menu[i].text<<endl;}
        cout<<"\n���i�� �᫮ �㭪�: ";
        int v=getInt(1,10);
        for(int b=0;b<10;b++)
        {
            if(v==10){log_save("���i�"); exit(0);}
            if(v==(b+1)){menu[b].func();}
        }
    }
}
void add_organization()
{
    system("cls");
    cout<<"�⢮७�� Organization"<<endl; line;
    num_organization++;
    organization *ar_2=new organization[num_organization];
    memcpy(ar_2, arr, sizeof(organization)*num_organization);
    arr=new organization[num_organization];
    arr=ar_2;
    cout<<"����i�� ����� Organization: ";
    getStr(arr[num_organization-1].name,40);
    cout<<"����i�� ����� Organization: ";
    arr[num_organization-1].pay=getInt(0,LONG_MAX);
    cout<<"����i�� �i��i��� Person: ";
    arr[num_organization-1].capacity=getInt(0,LONG_MAX);
    arr[num_organization-1].child=new person[arr[num_organization-1].capacity];
    for(int i=0;i<arr[num_organization-1].capacity;i++)
    {
        cout<<"����i�� i�'� ��� Person �"<<i+1<<": ";
        getStr(arr[num_organization-1].child[i].name,40);
        cout<<"����i�� ���i� ஡�� ��� Person �"<<i+1<<": ";
        arr[num_organization-1].child[i].level=getInt(0,LONG_MAX);
        cout<<"����i�� �i��i��� characteristic ��� Person �"<<i+1<<": ";
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
                cout<<"����i�� �i��i��� parameters � characteristic ��� Person �"<<i+1<<": ";
                volum=getInt(0,LONG_MAX);
            }
            arr[num_organization-1].child[i].child[b].capacity=volum;
            cout<<"����i�� ����� characteristic �"<<b+1<<" ��� Person �"<<i+1<<": ";
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
                cout<<"����i�� ���祭�� parameters �"<<c+1<<" ��� characteristic "<<arr[num_organization-1].child[i].child[b].name<<" ��� Person �"<<i+1<<": ";
                getStr(arr[num_organization-1].child[i].child[b].child[c].name,40);
            }
        }
    }
    pause();
    log_save("�⢮�� Organization");
}
void show_organization()
{
    system("cls");
    cout<<"����� ������� ��ॢ�"<<endl; line;
    if(num_organization==0){cout<<"����� ��ॢ�"<<endl;}
    else
    {
        for(int i=0;i<num_organization;i++)
        {
            cout<<"Organization �"<<i+1<<endl<<"�����: "<<arr[i].name<<endl<<"����: "<<arr[i].pay<<endl<<"�i��i��� ��i�: "<<arr[i].capacity<<endl;
        }
    }
    pause();
    log_save("������� ����i��� ��ॢ�");
}
void switch_organization()
{
    system("cls");
    cout<<"��i�� Organization"<<endl; line;
    int num_person_ad;
    cout<<"����i�� ����� Organization:";
    num_person_ad=getInt(1,LONG_MAX);
    if(num_person_ad<=num_organization)
    {
        num_person=num_person_ad;
        num_person--;
    }
    else{cout<<"�쮣� ��ॢ� �� i���!"<<endl;}
    pause();
    log_save("��i��� Organization");
}
void edit_organization()
{
    system("cls");
    cout<<"�����㢠��� Organization"<<endl; line;
    if(num_organization==0){cout<<"����� ��ॢ�"<<endl;}
    else
    {
        cout<<"����i�� ����� Organization: ";
        getStr(arr[num_person].name,40);
        cout<<"����i�� ����� Organization: ";
        arr[num_person].pay=getInt(0,LONG_MAX);
        cout<<"����i�� �i��i��� Person: ";
        arr[num_person].capacity=getInt(0,LONG_MAX);
        arr[num_person].child=new person[arr[num_person].capacity];
        for(int i=0;i<arr[num_person].capacity;i++)
        {
            cout<<"����i�� i�'� ��� Person �"<<i+1<<": ";
            getStr(arr[num_person].child[i].name,40);
            cout<<"����i�� ���i� ஡�� ��� Person �"<<i+1<<": ";
            arr[num_person].child[i].level=getInt(0,LONG_MAX);
            cout<<"����i�� �i��i��� characteristic ��� Person �"<<i+1<<": ";
            arr[num_person].child[i].capacity=getInt(0,LONG_MAX);
            arr[num_person].child[i].child=new characteristic[arr[num_person].child[i].capacity];
            int volum=0;
            for(int i=0;i<arr[num_person].capacity;i++)
            {
                for(int b=0;b<arr[num_person].child[i].capacity;b++)
                {
                    if(b==0)
                    {
                        cout<<"����i�� �i��i��� parameters � characteristic ��� Person �"<<i+1<<": ";
                        volum=getInt(0,LONG_MAX);
                    }
                    arr[num_person].child[i].child[b].capacity=volum;
                    cout<<"����i�� ����� characteristic �"<<b+1<<" ��� Person �"<<i+1<<": ";
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
                        cout<<"����i�� ���祭�� parameters �"<<c+1<<" ��� characteristic "<<arr[num_organization-1].child[i].child[b].name<<" ��� Person �"<<i+1<<": ";
                        getStr(arr[num_organization-1].child[i].child[b].child[c].name,40);
                    }
                }
            }
        }
    }
    pause();
    log_save("�����㢠� Organization");
}
void delete_organization()
{
    system("cls");
    cout<<"��������� Organization"<<endl; line;
    if(num_organization==0){cout<<"����� Organization ��� ���������";}
    else
    {
        for(int i=num_person;i<num_organization;i++){arr[i]=arr[i+1];}
        num_organization--;
        cout<<"Organization �"<<num_person+1<<" �㫠 ��������"<<endl;
        if(num_person!=0){num_person--;}
    }
    pause();
    log_save("������� Organization");
}
void del_all_organization()
{
    system("cls");
    cout<<"��������� ��i� Organization"<<endl; line;
    if(num_organization==0){cout<<"����� Organization ��� ���������";}
    else
    {
        for(int x=num_organization; x>0;x--)
        {
            for(int i=num_person;i<num_organization;i++){arr[i]=arr[i+1];}
            num_organization--;
            if(num_person!=0){num_person--;}
        }
        cout<<"��i organization �㫨 �������i"<<endl;
    }
    pause();
    log_save("������� ��i Organization");
}
