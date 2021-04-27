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

vector<Mir> readMir()
{
    vector <Mir> data;
    while (true)
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
            break;
        }
        cout << "Введите кол-во игрушек: ";
        cin >> kl.count;
        if (kl.count < 0)
        {
            cout << "Ошибка ввода" << endl;
            break;
        }
        cout << "Введите минимальный возраст: ";
        cin >> kl.min_age;
        if (kl.min_age < 0)
        {
            cout << "Ошибка ввода" << endl;
            break;
        }
        cout << "Введите максимальный возраст: ";
        cin >> kl.max_age;
        if ((kl.max_age < 0) || (kl.max_age < kl.min_age))
        {
            cout << "Ошибка ввода" << endl;
            break;
        }
        data.push_back(kl);
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
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
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