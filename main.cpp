#include"types.h"
int main()
{
    SetConsoleTitleA("My expenses");
    log_save("����� �ணࠬ�");
    while(true)
    {
        system("cls");
        cout<<"����������: ��㤥�� ��. �I-212 �㡨�쪨� �.�."<<endl; line;
        menu_unit menu[]={{"��३� �� Organization", organization_menu},
                          {"��३� �� Person", person_menu},
                          {"��३� �� Characteristic", characteristic_menu},
                          {"��३� �� Parameters", parameters_menu},
                          {"��३� �� �����i� ��� ��ॢ��", operations_tree_menu},
                          {"��३� �� ���㪮���� ����", search_menu},
                          {"���i�", NULL},};
        for(int i=0;i<7;i++){cout<<i+1<<" "<<menu[i].text<<endl;}
        cout<<"\n���i�� �᫮ �㭪�: ";
        int v=getInt(1,7);
        for(int b=0;b<7;b++)
        {
            if(v==7){log_save("���i�"); exit(0);}
            if(v==(b+1)){menu[b].func();}
        }
    }
}
