#include "types.h"
extern organization *arr;
const char *FILE_log = "log.txt";
const char *FILE_save_load = "expenses.txt";
const char *FILE_test = "expenses_test.txt";
void operations_tree_menu()
{
    log_save("����i� �� ���� �����i� ��� ��ॢ��");
    system("cls");
    while(true)
    {
        system("cls");
        cout<<"�����i� ��� ��ॢ��"<<endl; line;
        menu_unit menu_2[]={{"������� ����i��� ��ॢ�", show_full_tree},
                            {"���ॣ� ��ॢ� � 䠩�i", save_tree},
                            {"�����⠦�� ��ॢ� � 䠩��", load_tree},
                            {"�����⠦�� ��⮢� ��ॢ�", test_tree},
                            {"������� ����", log_view},
                            {"������� ����", log_delete},
                            {"��३� �� ��������� ����", main_menu},
                            {"���i�", NULL},};
        for(int i=0;i<8;i++){cout<<i+1<<" "<<menu_2[i].text<<endl;}
        cout<<"\n���i�� �᫮ �㭪�: ";
        int v=getInt(1,8);
        for(int b=0;b<8;b++)
        {
            if(v==8){log_save("���i�"); exit(0);}
            if(v==(b+1)){menu_2[b].func();}
        }
    }
    pause();
}
void show_full_tree()
{
    system("cls");
    cout<<"����� ����i��� ��ॢ�"<<endl; line;
    if(num_organization==0){cout<<"����� ��ॢ�"<<endl;}
    else
    {
        cout<<"Organization �"<<num_person + 1<<endl<<"  �����: "<<arr[num_person].name<<endl<<"  ����: "<<arr[num_person].pay<<endl<<"  �i��i��� Person: "<<arr[num_person].capacity<<endl<<"    Person: "<<endl;
        if(arr[num_person].capacity==0){cout<<"    ����� Person"<<endl;}
        else
        {
            for(int b=0;b<arr[num_person].capacity;b++)
            {
                cout<<"    I�'�: "<<arr[num_person].child[b].name<<". ���i� ஡��: "<<arr[num_person].child[b].level;
                if(arr[num_person].child[b].capacity>=1&&arr[num_person].child[b].capacity<=UCHAR_MAX)
                {
                    cout<<endl<<"      ���᮪ �haracteristic: ";
                    int i=0;
                    cout<<arr[num_person].child[b].child[i].name; i++;
                    if(arr[num_person].child[b].capacity>1)
                    {
                        do{cout<<", "<<arr[num_person].child[b].child[i].name; i++;}
                        while(i<arr[num_person].child[b].capacity);
                    }
                    if(arr[num_person].child[b].child[i].capacity<=0&&arr[num_person].child[b].child[i].capacity>UCHAR_MAX){cout<<endl<<"        ����� parameters"<<endl;}
                    else
                    {
                        cout<<endl<<"        Parameters: "<<endl;
                        for(int c=0;c<arr[num_person].child[b].capacity;c++)
                        {
                            cout<<"        Characteristic "<<arr[num_person].child[b].child[c].name<<": "<<endl;
                            for(int i=0;i<arr[num_person].child[b].child[c].capacity;i++)
                            {
                                cout<<"        "<<arr[num_person].child[b].child[c].child[i].name<<endl;
                            }
                        }
                    }
                }
                else
                {
                    cout<<endl<<"      ����� characteristic"<<endl;
                }
            }
        }
    }
    pause();
    log_save("������� ����i��� ��ॢ�");
}
void test_tree()
{
    system("cls");
    cout<<"�����⠦���� ��⮢��� ��ॢ�"<<endl; line;
    num_organization++;
    organization *ar_2=new organization[num_organization];
    memcpy(ar_2, arr, sizeof(organization)*num_organization);
    arr=new organization[num_organization];
    arr=ar_2;
    ifstream file;
    file.open(FILE_test);
    file>>arr[num_organization-1].name>>arr[num_organization-1].pay>>arr[num_organization-1].capacity;
    arr[num_organization-1].child=new person[arr[num_organization-1].capacity];
    for(int i=0;i<arr[num_organization-1].capacity;i++)
    {
        file>>arr[num_organization-1].child[i].name>>arr[num_organization-1].child[i].level>>arr[num_organization-1].child[i].capacity;
        arr[num_organization-1].child[i].child=new characteristic[arr[num_organization-1].child[i].capacity];
        for(int b=0;b<arr[num_organization-1].child[i].capacity;b++)
        {
            file>>arr[num_organization-1].child[i].child[b].name>>arr[num_organization-1].child[i].child[b].capacity;
            arr[num_organization-1].child[i].child[b].child=new parameters[arr[num_organization-1].child[i].child[b].capacity];
            for(int c=0;c<arr[num_organization-1].child[i].child[b].capacity;c++)
            {
                file>>arr[num_organization-1].child[i].child[b].child[c].name;
            }
        }
    }
    file.close();
    pause();
    log_save("����㧨� ��⮢� ��ॢ� � 䠩�� expenses_test.txt");
}
void save_tree()
{
    system("cls");
    cout<<"���०���� ��ॢ� � 䠩�i"<<endl; line;
    if(num_organization==0){cout<<"����� ��ॢ ��� ���ॣ� � 䠩�i"<<endl;}
    else
    {
        ofstream file;
        file.open(FILE_save_load);
        file<<arr[num_organization-1].name<<" "<<arr[num_organization-1].pay<<" "<<arr[num_organization-1].capacity<<endl;
        for(int b=0;b<arr[num_organization-1].capacity;b++)
        {
            file<<arr[num_organization-1].child[b].name<<" "<<arr[num_organization-1].child[b].level<<" "<<arr[num_organization-1].child[b].capacity<<endl;
            for(int c=0;c<arr[num_organization-1].child[b].capacity;c++)
            {
                file<<arr[num_organization-1].child[b].child[c].name<<" "<<arr[num_organization-1].child[b].child[c].capacity<<endl;
                for(int d=0;d<arr[num_organization-1].child[b].child[c].capacity;d++)
                {
                    file<<arr[num_organization-1].child[b].child[c].child[d].name<<" "<<endl;
                }
            }
        }
        file.close();
    }
    pause();
    log_save("���ॣ� ��ॢ� � 䠩�i expenses.txt");
}
void load_tree()
{
    system("cls");
    cout<<"�����⠦���� ��ॢ� � 䠩��"<<endl; line;
    num_organization++;
    organization *ar_2=new organization[num_organization];
    memcpy(ar_2, arr, sizeof(organization)*num_organization);
    arr=new organization[num_organization];
    arr=ar_2;
    ifstream file;
    file.open(FILE_save_load);
    file>>arr[num_organization-1].name>>arr[num_organization-1].pay>>arr[num_organization-1].capacity;
    arr[num_organization-1].child=new person[arr[num_organization-1].capacity];
    for(int i=0;i<arr[num_organization-1].capacity;i++)
    {
        file>>arr[num_organization-1].child[i].name>>arr[num_organization-1].child[i].level>>arr[num_organization-1].child[i].capacity;
        arr[num_organization-1].child[i].child=new characteristic[arr[num_organization-1].child[i].capacity];
        for(int b=0;b<arr[num_organization-1].child[i].capacity;b++)
        {
            file>>arr[num_organization-1].child[i].child[b].name>>arr[num_organization-1].child[i].child[b].capacity;
            arr[num_organization-1].child[i].child[b].child=new parameters[arr[num_organization-1].child[i].child[b].capacity];
            for(int c=0;c<arr[num_organization-1].child[i].child[b].capacity;c++)
            {
                file>>arr[num_organization-1].child[i].child[b].child[c].name;
            }
        }
    }
    file.close();
    pause();
    log_save("����㧨� ��ॢ� � 䠩�� expenses.txt");
}
void log_save(string name)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    ofstream log;
    log.open(FILE_log,ios_base::app);
    log<<"Time: "<< ltm->tm_hour << ":"<< ltm->tm_min << ":"<< ltm->tm_sec << " - "<< name << endl;
    log.close();
}
void log_view()
{
    system("cls");
    cout<<"����� ���i�"<<endl; line;
    log_save("������� ����");
    string log;
    ifstream logs(FILE_log);
    while(getline(logs, log)){cout<<log<<endl;}
    logs.close();
    pause();
}
void log_delete()
{
    system("cls");
    cout<<"��������� ���i�"<<endl; line;
    cout<<"��i ���� �㫨 �������i ��i譮!"<<endl;
    ofstream log;
    log.open(FILE_log,ios_base::trunc);
    log.close();
    ofstream logNew;
    logNew.open(FILE_log,ios_base::app);
    logNew<<"���ᮢ�� �஥�� <My expenses> ����������: ��㤥�� ��. �I-212 �㡨�쪨� �.�."<<endl;
    logNew.close();
    log_save("������� ����");
    pause();
}
int getInt(int min, int max)
{
    input_int:
    char str[UCHAR_MAX];
    cin.getline(str,UCHAR_MAX);
    int num = atoi(str);
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        if(num<min||num>max||!isdigit(str[i]))
        {
            cout<<"�����i��� ����� �᫮ � �i������i "<<min<<"-"<<max<<", ����i�� � ࠧ: ";
            goto input_int;
        }
    }
    return num;
}
void getStr(char str[],int maxMemory)
{
    input_str:
    cin.getline(str, UCHAR_MAX);
    int len = strlen(str);
    if(len>maxMemory)
    {
        cout<<"�����i��� ����� ���祭�� �� "<<maxMemory<<" c�����i�, ����i�� � ࠧ: ";
        goto input_str;
    }
}
void main_menu()
{
    log_save("��३� �� ��������� ����");
    main();
}
void pause()
{
    cout<<"\n��� �த������� ����i�� ��� �� ����i��...";
    getch();
}
