#include "types.h"
extern organization *arr;
const char *FILE_log = "log.txt";
const char *FILE_save_load = "expenses.txt";
const char *FILE_test = "expenses_test.txt";
void operations_tree_menu()
{
    log_save("Перехiд до меню операцiй над деревом");
    system("cls");
    while(true)
    {
        system("cls");
        cout<<"Операцiї над деревом"<<endl; line;
        menu_unit menu_2[]={{"Показати повнiстю дерево", show_full_tree},
                            {"Зберегти дерева у файлi", save_tree},
                            {"Завантажити дерева з файлу", load_tree},
                            {"Завантажити тестове дерево", test_tree},
                            {"Показати логи", log_view},
                            {"Видалити логи", log_delete},
                            {"Перейти до головного меню", main_menu},
                            {"Вихiд", NULL},};
        for(int i=0;i<8;i++){cout<<i+1<<" "<<menu_2[i].text<<endl;}
        cout<<"\nВедiть число пункта: ";
        int v=getInt(1,8);
        for(int b=0;b<8;b++)
        {
            if(v==8){log_save("Вихiд"); exit(0);}
            if(v==(b+1)){menu_2[b].func();}
        }
    }
    pause();
}
void show_full_tree()
{
    system("cls");
    cout<<"Показ повнiстю дерева"<<endl; line;
    if(num_organization==0){cout<<"Немає дерева"<<endl;}
    else
    {
        cout<<"Organization №"<<num_person + 1<<endl<<"  Назва: "<<arr[num_person].name<<endl<<"  Плата: "<<arr[num_person].pay<<endl<<"  Кiлькiсть Person: "<<arr[num_person].capacity<<endl<<"    Person: "<<endl;
        if(arr[num_person].capacity==0){cout<<"    Немає Person"<<endl;}
        else
        {
            for(int b=0;b<arr[num_person].capacity;b++)
            {
                cout<<"    Iм'я: "<<arr[num_person].child[b].name<<". Досвiд роботи: "<<arr[num_person].child[b].level;
                if(arr[num_person].child[b].capacity>=1&&arr[num_person].child[b].capacity<=UCHAR_MAX)
                {
                    cout<<endl<<"      Список Сharacteristic: ";
                    int i=0;
                    cout<<arr[num_person].child[b].child[i].name; i++;
                    if(arr[num_person].child[b].capacity>1)
                    {
                        do{cout<<", "<<arr[num_person].child[b].child[i].name; i++;}
                        while(i<arr[num_person].child[b].capacity);
                    }
                    if(arr[num_person].child[b].child[i].capacity<=0&&arr[num_person].child[b].child[i].capacity>UCHAR_MAX){cout<<endl<<"        Немає parameters"<<endl;}
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
                    cout<<endl<<"      Немає characteristic"<<endl;
                }
            }
        }
    }
    pause();
    log_save("Показати повнiстю дерево");
}
void test_tree()
{
    system("cls");
    cout<<"Завантаження тестового дерева"<<endl; line;
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
    log_save("Загрузити тестове дерево з файла expenses_test.txt");
}
void save_tree()
{
    system("cls");
    cout<<"Збереження дерева у файлi"<<endl; line;
    if(num_organization==0){cout<<"Немає дерев для зберегти у файлi"<<endl;}
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
    log_save("Зберегти дерева у файлi expenses.txt");
}
void load_tree()
{
    system("cls");
    cout<<"Завантаження дерева з файлу"<<endl; line;
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
    log_save("Загрузити дерева з файлу expenses.txt");
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
    cout<<"Показ логiв"<<endl; line;
    log_save("Показати логи");
    string log;
    ifstream logs(FILE_log);
    while(getline(logs, log)){cout<<log<<endl;}
    logs.close();
    pause();
}
void log_delete()
{
    system("cls");
    cout<<"Видалення логiв"<<endl; line;
    cout<<"Всi логи були видаленi успiшно!"<<endl;
    ofstream log;
    log.open(FILE_log,ios_base::trunc);
    log.close();
    ofstream logNew;
    logNew.open(FILE_log,ios_base::app);
    logNew<<"Курсовий проект <My expenses> виконавець: студент гр. КI-212 Кубицький Я.М."<<endl;
    logNew.close();
    log_save("Видалити логи");
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
            cout<<"Необхiдно ввести число в дiапозонi "<<min<<"-"<<max<<", введiть ще раз: ";
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
        cout<<"Необхiдно ввести значення до "<<maxMemory<<" cимволiв, введiть ще раз: ";
        goto input_str;
    }
}
void main_menu()
{
    log_save("Перейти до головного меню");
    main();
}
void pause()
{
    cout<<"\nДля продовження натиснiть будь яку клавiшу...";
    getch();
}
