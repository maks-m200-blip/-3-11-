#include <iostream>
#include <clocale>
int main() {
    std::setlocale(LC_ALL, "Russian");
    int vremya=0, chas=0, day=0, status=0,stavka=0,minut=0;
    double schet, schetnds;
    std::cout<<"Введите данные звонка:"<<'\n';
    std::cout<<"Длительность(мин):";std::cin>>vremya;
    std::cout<<"Час начала(0-23):";std::cin>>chas;
    std::cout<<"День недели(1-7, 1-пн):";std::cin>>day;
    std::cout<<"Постоянный клиент(1-да/0-нет):";std::cin>>status;
    std::cout<<"=== РАСЧЕТ СТОИМОСТИ ==="<<'\n';
    if(vremya>=60){
        minut=1;
    }
    else{
        minut=0;
    }
    if(day==6 || day==7){
        stavka=2;
 
    }
    else{
        if(8<=chas<=22){
            stavka=5;
        }
        else{
            stavka=3;
    }
    }  
    if(status==1){
        if(minut==1){
            schet = vremya*stavka*0.85;
            schetnds=schet*1.2;
        }
        else{
            schet = vremya*stavka*0.95;
            schetnds=schet*1.2;
        }
    }
    else{
        if(minut==1){
            schet= vremya*stavka*0.9;
            schetnds=schet*1.2;
        }
        else{
            schet = vremya*stavka;
            schetnds=schet*1.2;
        }
    }
    if(stavka==5){
        std::cout<<"Тариф: будни-день (5.00 руб/мин)"<<'\n';
    }
    if(stavka==3){
        std::cout<<"Тариф: будни-ночь (3.00 руб/мин)"<<'\n';
    }
    if(stavka==2){
        std::cout<<"Тариф: выходные (2.00 руб/мин)"<<'\n';
    }
    std::cout<<"Базовая стоимость:"<<stavka*vremya<<"руб"<<'\n'<<"Скидки:"<<'\n'<<"- За длительность:"<<stavka*vremya*minut*0.1<<"руб"<<'\n'<<"- Потоянный клиент"<<stavka*vremya*status*0.05<<"руб"<<'\n'<<"Итого без НДС:"<<schet<<"руб"<<'\n'<<"НДС 20%:"<< schet*0.2<< "руб"<<'\n'<<"К ОПЛАТЕ"<< schetnds<<"руб";
}