#include"types.h"
int main()
{
    SetConsoleTitleA("My expenses");
    log_save("Запуск програми");
    while(true)
    {
        system("cls");
        cout<<"Виконавець: студент гр. КI-212 Кубицький Я.М."<<endl; line;
        menu_unit menu[]={{"Перейти до Organization", organization_menu},
                          {"Перейти до Person", person_menu},
                          {"Перейти до Characteristic", characteristic_menu},
                          {"Перейти до Parameters", parameters_menu},
                          {"Перейти до операцiй над деревом", operations_tree_menu},
                          {"Перейти до пошукового меню", search_menu},
                          {"Вихiд", NULL},};
        for(int i=0;i<7;i++){cout<<i+1<<" "<<menu[i].text<<endl;}
        cout<<"\nВедiть число пункта: ";
        int v=getInt(1,7);
        for(int b=0;b<7;b++)
        {
            if(v==7){log_save("Вихiд"); exit(0);}
            if(v==(b+1)){menu[b].func();}
        }
    }
}
