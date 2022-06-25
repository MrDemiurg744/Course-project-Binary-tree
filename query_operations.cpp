#include "types.h"
extern organization *arr;
void search_menu()
{
    if(num_organization==0){cout<<endl<<"����� Organization";}
    else
    {
        log_save("����i� �� ���㪮���� ����");
        system("cls");
        while(true)
        {
            system("cls");
            cout<<"���㪮�� ����"<<endl; line;
            menu_unit menu_2[]={{"���� Person � ����i��訬 �⠦�� ஡��", search_level},
                                {"����� Organization �� ����i� �㪢i", search_letter},
                                {"Person � �⠦�� ஡�� �i��� 5 பi�", top_list},
                                {"��३� �� ��������� ����", main_menu},
                                {"���i�", NULL},};
            for(int i=0;i<5;i++){cout<<i+1<<" "<<menu_2[i].text<<endl;}
            cout<<"\n���i�� �᫮ �㭪�: ";
            int v=getInt(1,5);
            for(int b=0;b<5;b++)
            {
                if(v==5){log_save("���i�"); exit(0);}
                if(v==(b+1)){menu_2[b].func();}
            }
        }
    }
    pause();
}
void search_letter()
{
    system("cls");
    cout<<"���� Organization �� ����i� �㪢i"<<endl; line;
    cout<<"����i�� ����� �㪢� ��� �����: ";
    char b[1]; getStr(b,1);
    int x=0;
    for(int i=0;i<num_organization;i++)
    {
        if(b[0]==arr[i].name[0])
        {
            cout<<endl<<"Organization �"<<i+1<<" ����� "<<arr[i].name<<", ���� "<<arr[i].pay<<", �i��i��� person "<<arr[i].capacity<<endl;
            x++;
        }
    }
    if(x==0){cout<<"�� �������� organization �� ����i� �㪢i"<<endl;}
    log_save("����� Organization �� ����i� �㪢i");
    pause();
}
void top_list()
{
    system("cls");
    cout<<"Person �i �⠦�� ஡�� �i��� 5 பi�"<<endl; line;
    int ad=5;
    int x=0;
    for(int i=0;i<num_organization;i++)
    {
        for(int b=0;b<arr[i].capacity;b++)
        {
            if(ad<=arr[i].child[b].level)
            {
                x++;
                cout<<"Organization "<<arr[i].name<<", i�'� "<<arr[i].child[b].name<<", �⠦ "<<arr[i].child[b].level<<" பi�"<<endl;
            }
        }
    }
    if(x==0){cout<<"����� Person �i �⠦�� ஡�� �i��� 5 பi�"<<endl;}
    log_save("Person �i �⠦�� ஡�� �i��� 5 பi�");
    pause();
}
void search_level()
{
    system("cls");
    cout<<"���� Person � ����i��訬 �⠦�� ஡��"<<endl; line;
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
    cout<<"Person � ����i��訬 �⠦�� ஡��: "<<arr[num_1].child[num_2].name<<" � organization "<<arr[num_1].name<<", �⠦: "<<arr[num_1].child[num_2].level<<endl;
    log_save("���� Person � ����i��訬 �⠦�� ஡��");
    pause();
}
