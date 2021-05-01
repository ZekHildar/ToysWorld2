#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

const int RAZMERCHAROV = 20;

struct Mir
{
    char toy_name[RAZMERCHAROV];
    float price;
    int count;
    int min_age;
    int max_age;
};

struct list
{
    Mir spisok;
    list* next;
};

vector <Mir> mir;
const Mir NULLMIR = {
    "9fd663c21v5asqe87s",-1,-1,-1,-1
};

void Nazvaniya(char* slovo, int switch_on)
{
    switch (switch_on)
    {
    case 0:
    {
        for (int i = 0; i < RAZMERCHAROV; i++)
        {
            if (slovo[i] == 10)
            {
                for (int k = i; k < RAZMERCHAROV; k++)
                {
                    slovo[k] = ' ';
                }
            }
            cout << slovo[i];
        }
        break;
    }
    case 1:
    {
        for (int i = 0; i < RAZMERCHAROV; i++)
        {
            if (slovo[i] == ' ')
                break;
            cout << slovo[i];
        }
        break;
    }
    default:
        break;
    }
}
void printTable(vector<Mir> igrushka)
{
    SetConsoleOutputCP(866);
    printf("%c", 201);
    for (int i = 0; i < 59; i++)
    {
        if ((i == 20) || (i == 30) || (i == 38) || (i == 48)) printf("%c", 203);
        else printf("%c", 205);
    }
    printf("%c\n", 187);

    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-20s", "Название");
    SetConsoleOutputCP(866);
    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-9s", "Цена");
    SetConsoleOutputCP(866);
    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-7s", "Кол-во");
    SetConsoleOutputCP(866);
    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-9s", "Мин.возр");
    SetConsoleOutputCP(866);
    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-10s", "Макс.возр");
    SetConsoleOutputCP(866);
    printf("%c\n", 186);
    printf("%c", 204);
    for (int i = 0; i < 59; i++)
    {
        if ((i == 20) || (i == 30) || (i == 38) || (i == 48)) printf("%c", 206);
        else printf("%c", 205);
    }
    printf("%c\n", 185);

    for (int i = 0; i < igrushka.size(); i++) {
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        Nazvaniya(igrushka[i].toy_name, 0);
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        printf("%-9.2f", igrushka[i].price);
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        printf("%-7i", igrushka[i].count);
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        printf("%-9i", igrushka[i].min_age);
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        printf("%-10i", igrushka[i].max_age);
        SetConsoleOutputCP(866);
        printf("%c\n", 186);
        if (i != igrushka.size() - 1) {
            printf("%c", 204);
            for (int i = 0; i < 59; i++)
            {
                if ((i == 20) || (i == 30) || (i == 38) || (i == 48)) printf("%c", 206);
                else printf("%c", 205);
            }
            printf("%c\n", 185);
        }
    };
    printf("%c", 200);
    for (int i = 0; i < 59; i++)
    {
        if ((i == 20) || (i == 30) || (i == 38) || (i == 48)) printf("%c", 202);
        else printf("%c", 205);
    }
    printf("%c\n", 188);
    SetConsoleOutputCP(1251);
}
void printTableList(list* k)
{
    list* copyTable = k;
    SetConsoleOutputCP(866);
    printf("%c", 201);
    for (int i = 0; i < 59; i++)
    {
        if ((i == 20) || (i == 30) || (i == 38) || (i == 48)) printf("%c", 203);
        else printf("%c", 205);
    }
    printf("%c\n", 187);

    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-20s", "Название");
    SetConsoleOutputCP(866);
    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-9s", "Цена");
    SetConsoleOutputCP(866);
    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-7s", "Кол-во");
    SetConsoleOutputCP(866);
    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-9s", "Мин.возр");
    SetConsoleOutputCP(866);
    printf("%c", 186);
    SetConsoleOutputCP(1251);
    printf("%-10s", "Макс.возр");
    SetConsoleOutputCP(866);
    printf("%c\n", 186);
    printf("%c", 204);
    for (int i = 0; i < 59; i++)
    {
        if ((i == 20) || (i == 30) || (i == 38) || (i == 48)) printf("%c", 206);
        else printf("%c", 205);
    }
    printf("%c\n", 185);

    while ( copyTable != NULL)
    {
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        Nazvaniya(copyTable->spisok.toy_name, 0);
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        printf("%-9.2f", copyTable->spisok.price);
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        printf("%-7i", copyTable->spisok.count);
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        printf("%-9i", copyTable->spisok.min_age);
        SetConsoleOutputCP(866);
        printf("%c", 186);
        SetConsoleOutputCP(1251);
        printf("%-10i", copyTable->spisok.max_age);
        SetConsoleOutputCP(866);
        printf("%c\n", 186);
        if (copyTable->next != NULL) {
            printf("%c", 204);
            for (int i = 0; i < 59; i++)
            {
                if ((i == 20) || (i == 30) || (i == 38) || (i == 48)) printf("%c", 206);
                else printf("%c", 205);
            }
            printf("%c\n", 185);
        }
        copyTable = copyTable->next;
    };
    printf("%c", 200);
    for (int i = 0; i < 59; i++)
    {
        if ((i == 20) || (i == 30) || (i == 38) || (i == 48)) printf("%c", 202);
        else printf("%c", 205);
    }
    printf("%c\n", 188);
    SetConsoleOutputCP(1251);
}
void getInfo()
{
    // open file
    FILE* f;
    fopen_s(&f, "Toys.txt", "rb");
    int data_size;
    if (!f)
    {
        cout << "Файла нет" << endl;
        return;
    }

    // create bufer vector Mir 
    vector <Mir> igrushka;

    // read to buf vector Mir
    fread(&data_size, sizeof(int), 1, f);
    for (int i = 0; i < data_size; i++)
    {
        Mir element;

        fread(&element, sizeof(Mir), 1, f);
        igrushka.push_back(element);
    }

    // print vector mir as table
    printTable(igrushka);

    // save buf to global vector mir
    mir = igrushka;

    // close file
    fclose(f);
}
Mir readElement()
{
    Mir kl;
    cout << "Введите название игрушки: ";
    getchar();
    memset(kl.toy_name, 0, sizeof(char) * RAZMERCHAROV);
    for (int i = 0; i < RAZMERCHAROV; i++)
    {
        kl.toy_name[i] = getchar();
        if (kl.toy_name[i] == 10) break;
    }
    cout << "Введите цену игрушки: ";
    cin >> kl.price;
    if (kl.price < 0)
    {
        cout << "Ошибка ввода" << endl;
        return NULLMIR;
    }
    cout << "Введите кол-во игрушек: ";
    cin >> kl.count;
    if (kl.count < 0)
    {
        cout << "Ошибка ввода" << endl;
        return NULLMIR;
    }
    cout << "Введите минимальный возраст: ";
    cin >> kl.min_age;
    if (kl.min_age < 0)
    {
        cout << "Ошибка ввода" << endl;
        return NULLMIR;
    }
    cout << "Введите максимальный возраст: ";
    cin >> kl.max_age;
    if ((kl.max_age < 0) || (kl.max_age < kl.min_age))
    {
        cout << "Ошибка ввода" << endl;
        return NULLMIR;
    }
    return kl;
}
vector<Mir> readMir()
{
    
    vector <Mir> data;
    while (true)
    {
        
        Mir buffer = readElement();
        if (buffer.price == NULLMIR.price) break;
        // TODO: Сделать проверку ошибок ввода
        data.push_back(buffer);
        cout << "Хотите ли вы добавить еще игрушку? (y/n): ";
        char K;
        cin >> K;
        if ((K == 'y') || (K == 'д') || (K == 'Y') || (K == '1')) continue;
        else break;
    }
    return data;
}
void writeToFile(vector<Mir> data)
{
    int data_size;
    data_size = data.size();
    FILE* f;
    fopen_s(&f, "Toys.txt", "wb");
    fwrite(&data_size, sizeof(int), 1, f);
    for (auto it = data.begin(); it != data.end(); it++) {
        fwrite(&(*it), sizeof(Mir), 1, f);
    };
    fclose(f);
}

void writeInfo()
{
    char a;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do {
        cout << "Хотите ввести игрушку? (y/n): ";
        cin >> a;
        switch (a)
        {
        case 'Y':
        case 'y': {
            mir = readMir();
            writeToFile(mir);
            break;
        }
        case 'N':
        case 'n': {
            break;
        }
        default: {
            cout << "Ошибка ввода" << endl;
        }
        }
    } while ((a == 'y') && (a != 'n') || (a == 'Y') && (a != 'N'));

}

void Pervoe()
{
    int vozrast;
    vector <Mir> cache;
    cout << "Введите возраст ребенка: ";
    scanf_s("%i", &vozrast);
    bool k = false;
    cout << endl;
    int i = 0;
    // search all valid objeckts && add it to vector Mir cache
    for (auto it = mir.begin(); it != mir.end(); ++it) {
        if ((it->min_age <= (int)vozrast) && (it->max_age >= (int)vozrast))
        {
            Mir kl;
            for (int a = 0; a < RAZMERCHAROV; a++)
            {
                kl.toy_name[a] = it->toy_name[a];
            }
            kl.count = it->count;
            kl.max_age = it->max_age;
            kl.min_age = it->min_age;
            kl.price = it->price;
            cache.push_back(kl);
            k = true;
        }
    }

    // if found valid
    if (k)
    {
        // sort 
        for (int a = 0; a < cache.size() - 1; a++)
        {
            if (cache.size() == 0) break;
            if (cache[a].price < cache[a + 1].price)
            {
                Mir swap;
                swap = cache[a];
                cache[a] = cache[a + 1];
                cache[a + 1] = swap;
                int k = a;
                for (int k = a; (k >= 1) && (cache[k].price > cache[k - 1].price); k--) {
                    swap = cache[k];
                    cache[k] = cache[k - 1];
                    cache[k - 1] = swap;
                }
            }
        }

        printTable(cache);
    }
    // if not found valid
    else
    {
        cout << "Такой игрушки нет";
        cout << endl;
    }
    cout << endl;
    return;
}
void Vtoroe()
{
    cout << endl;
    vector<Mir> buff;
    buff.push_back(mir[0]);
    for (auto it = mir.begin(); it != mir.end(); ++it) {
        if (it->price >= buff[0].price)
            buff[0] = *it;
    }
    printTable(buff);
    cout << endl;
}
void Tretie()
{
    int vozrastA;
    int vozrastB;
    vector <Mir> cache;
    float stoimost;
    cout << "Какая максимальная стоимость игрушки?: ";
    cin >> stoimost;
    cout << "Какой минимальный возраст ребенка?: ";
    cin >> vozrastA;
    cout << "Какой максимальный возраст ребенка?: ";
    cin >> vozrastB;
    bool k = false;
    cout << endl;
    for (auto it = mir.begin(); it != mir.end(); ++it) {
        if (((vozrastA <= it->max_age) && (vozrastB >= it->min_age)) &&
            (((it->min_age <= vozrastA) && (it->max_age >= vozrastB)) || ((vozrastA <= it->min_age) && (vozrastB <= it->max_age)) || ((vozrastA >= it->min_age) && (vozrastB >= it->max_age)) ||
                /*Если в заданный промежуток входит игрушка, но минимальный возраст больше введенного, а максимальный меньше заданного*/
                ((vozrastA <= it->min_age) && (vozrastB >= it->max_age)))
            && (it->price <= stoimost) && (vozrastA <= vozrastB))
        {
            Mir kl;
            for (int a = 0; a < RAZMERCHAROV; a++)
            {
                kl.toy_name[a] = it->toy_name[a];
            }
            kl.count = it->count;
            kl.max_age = it->max_age;
            kl.min_age = it->min_age;
            kl.price = it->price;
            cache.push_back(kl);
            k = true;
        }
    }
    for (int a = 0; a < cache.size() - 1; a++)
    {
        if (cache.size() == 0) break;
        if (cache[a].price < cache[a + 1].price)
        {
            Mir swap;
            swap = cache[a];
            cache[a] = cache[a + 1];
            cache[a + 1] = swap;
            int k = a;

            for (int k = a; (k >= 1) && (cache[k].price > cache[k - 1].price); k--) {
                swap = cache[k];
                cache[k] = cache[k - 1];
                cache[k - 1] = swap;
            }
        }
    }
    if (k) {
        printTable(cache);
    }
    else
    {
        cout << "Такой игрушки нет";
        cout << endl;
    }
    getchar();
    cout << endl;
}
int Sravnenie(char* slovo1, char* slovo2)
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    for (int i = 0; i < RAZMERCHAROV; i++)
    {
        if (slovo1[i] == slovo2[i]) continue;
        if (slovo1[i] < slovo2[i]) return -1;
        if (slovo1[i] > slovo2[i]) return 1;
    }
    SetConsoleOutputCP(866);
    SetConsoleCP(866);
    return 0;
}
void QS(vector <Mir>& igrushka, int left, int right)
{
    int i = left, j = right;
    Mir k;
    Mir opora = igrushka[(left + right) / 2];

    do {
        while (Sravnenie(igrushka[i].toy_name, opora.toy_name) == -1)
            i++;
        while (Sravnenie(igrushka[j].toy_name, opora.toy_name) == 1)
            j--;
        if (i <= j) {
            k = igrushka[i];
            igrushka[i] = igrushka[j];
            igrushka[j] = k;
            i++;
            j--;
        }
    } while (i <= j);

    /* Рекурсия */
    if (left < j)
        QS(igrushka, left, j);
    if (i < right)
        QS(igrushka, i, right);
}
void Pyatoe()
{
    cout << "Хотите отсортировать файл? y/n: ";
    char turn;
    cin >> turn;

    switch (turn)
    {
    case 'n':
    case 'N':
    {
        break;
    }
    case 'y':
    case 'Y':
    {
        QS(mir, 0, mir.size() - 1);
        writeToFile(mir);
    }
    }
}

list* init(Mir info, list* next)
{
    list* try1;
    try1 = (list*)malloc(sizeof(list));
    try1->spisok = info;
    try1->next = next;
    return(try1);
}

list* NewNoda(list* noda, Mir a)
{
    list* try2;
    try2 = (list*)malloc(sizeof(list));
    try2->spisok = a;
    try2->next = noda->next;
    noda->next = try2;
    return(try2);

}
void Print(list* test)
{
    list* copy = test;
    while (true)
    {
        Nazvaniya(copy->spisok.toy_name, 0);
        //printf("%-20s", GetName(igrushka[i].toy_name));
        printf("%-9.2f", copy->spisok.price);
        printf("%-7i", copy->spisok.count);
        printf("%-9i", copy->spisok.min_age);
        printf("%-10i", copy->spisok.max_age);
        cout << endl;
        if (copy->next == NULL) break;
        copy = copy->next;
    }
}
void PushSort(list*& k, Mir inner)
{
    list* copy = k;
    list* previous = NULL;
    while (1)
    {
        if ((copy->spisok.price > inner.price) || (copy->next == NULL)) break;
        else
        {
            previous = copy;
            copy = copy->next;
        }
    }
    if (copy->spisok.price > inner.price)
    {
        if (previous == NULL)
        {
            //Вставка в начало
            list* a = init(inner, copy);
            k = a;
            return;
        }
        else
        {
            //Вставка в середину
            NewNoda(previous, inner);
            return;
        }
    }
    //Вставка в конец
    NewNoda(copy, inner);
}
void DeleteNoda(list* mainnoda, list* deletenoda)
{
    if (deletenoda == NULL) return;
    list* copy = mainnoda;
    while (true)
    {
        if (copy->next == deletenoda) break;
        copy = copy->next;
    }
    copy->next = deletenoda->next;
    free(deletenoda);
}
list* Search(char* k, list* MainNoda)
{
    list* copy = MainNoda;
    while (true)
    {
        if ((copy->next == NULL) || (Sravnenie(copy->spisok.toy_name, k) == 0)) break;
        copy = copy->next;
    }
    if (Sravnenie(copy->spisok.toy_name, k) == 0) return copy;
    return NULL;
}
void WriteListToFile(list* k)
{
    int data_size = 1;
    {
        list* cope = k;
        while (true)
        {
            if (cope->next != NULL)
            {
                data_size++;
                cope = cope->next;
            }
            else break;
        }
    }
    FILE* f;
    fopen_s(&f, "Toys.txt", "wb");
    fwrite(&data_size, sizeof(int), 1, f);
    list* cope = k;
    while (cope != NULL)
    {
        fwrite(&cope->spisok, sizeof(Mir), 1, f);
        cope = cope->next;
    }
    fclose(f);
    getInfo();
}
void WorkOnList()
{
    list* k = init(mir[0], NULL);
    for (int i = 1; i < mir.size(); i++)
    {
        PushSort(k, mir[i]);
    }
    printTableList(k);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    cout << "1.Добавить элемент\n2.Удалить элемент\n3.Выйти\nВыберите действие: ";
    scanf_s("%i",&choice);
    switch(choice)
    {
    case 1:
    {
        Mir buffer = readElement();
        if (buffer.price == NULLMIR.price) break;
        PushSort(k, buffer);
        WriteListToFile(k);
        break;
    }
   
    case 2:
    {
        cout << "Введите название игрушки: ";
        char name[RAZMERCHAROV];
        scanf_s("%s", name, sizeof(name));
        for (int i = 0; i < RAZMERCHAROV; i++)
        {
            if (name[i] == 0)
            {
                for (int j = i; j < RAZMERCHAROV; j++)
                {
                    name[j] = ' ';
                }
                break;
            }
        }
        DeleteNoda(k, Search(name, k));
        WriteListToFile(k);
        break;
    }
    case 3:
    {
        break;
    }
    default: break;
    }
    return;
    cout << "Введите название игрушки: ";
    getchar();
    SetConsoleCP(1251);
    Mir opora;
    char name[RAZMERCHAROV];
    memset(name, 0, sizeof(char) * RAZMERCHAROV);
    for (int i = 0; i < RAZMERCHAROV; i++)
    {
        name[i] = getchar();
        if (name[i] == 10)
        {
            for (int j = i; j < RAZMERCHAROV; j++)
            {
                name[i] = ' ';
                cout << j;
            }
            break;
        }
    }
    DeleteNoda(k, Search(name, k));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Print(k);
    int kolvo = 1;
    {
        list* cope = k;
        while (true)
        {
            if (cope->next != NULL)
            {
                kolvo++;
                cope = cope->next;
            }
            else break;
        }
    }
}
int main()
{
    SetConsoleOutputCP(1251);
    system("color F0");
    FILE* f;
    fopen_s(&f, "Toys.txt", "rb");
    int size;
    while (true)
    {
        if (!f)
        {
            // not found file
            break;

        }
        fread(&size, sizeof(int), 1, f);
        if (size < 1)
        {
            // empty file
            cout << "Файл пустой";
            break;
        }
        else
        {
            // read from file
            getInfo();
            break;
        }
    }
    fclose(f);
    bool bExit = 1;
    while (bExit)
    {
        system("cls");
        printTable(mir);
        cout << "\n\n\n\n";
        int t;
        cout << "1. Подбор игрушек по возрасту" << endl;
        cout << "2. Самая дорогая игрушка" << endl;
        cout << "3. Подбор игрушки по цене и возрасту" << endl;
        cout << "4. Запись игрушек в базу" << endl;
        cout << "5. Чтение списка игрушек" << endl;
        cout << "6. Редактирование списка игрушек" << endl;
        cout << "0. Выйти из программы" << endl << "  >>";
        scanf_s("%i", &t);
        switch (t)
        {
        case 1: {
            Pervoe();
            break;
        }
        case 2: {
            Vtoroe();
            break;
        }
        case 3: {
            Tretie();
            break;
        }
        case 4: {
            writeInfo();
            break;
        }
        case 5: {
            Pyatoe();
            break;
        }
        case 6:
        {
            WorkOnList();
            break;
        }
        case 0:
        {
            bExit = 0;
            break;
        }
        default:
        {
            // error input
            break;
        }
        }
        system("Pause");
    }
    return 0;
}
//TODO: present to teacher