#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include "binary_tree.h"
#include "node.h"

#define RAND_MAX 800000000

int main()
{
    srand(time(NULL));
    clock_t start = clock();
    binary_tree<int>* bt = new binary_tree<int>();
    /*bt->add(1);
    bt->add(2);
    bt->add(20);
    bt->add(25);
    bt->add(30);
    bt->add(10);
    bt->add(11);
    bt->add(12);
    bt->add(18);
    bt->add(17);
    bt->add(9);
    bt->add(7);
    bt->add(8);
    bt->add(4);
    bt->add(5);
    bt->add(6);*/
    int r = 10000000;
    for (int i = 1; i < r; i++)
    {
        int x = abs((rand() << 15 + rand()) % 1000000);
        bt->add(x);
    }

    clock_t t2 = clock();
    std::cout << "Time:" << (float)(t2 - start) / (float)CLOCKS_PER_SEC << std::endl;
    std::cout << "Time for element:" << (float)(t2 - start) / (float)CLOCKS_PER_SEC / r << std::endl;
    std::cout << "Wysokosc drzewa: " << bt->height(bt->head) << std::endl;
    std::cout << "Stosunek wysokości drzewa do rozmiaru danych: " << bt->height(bt->head) / (float)r << std::endl;
    std::cout << "Logarytm o podstawie 2 z danych: " << log2(r) << std::endl;
    std::cout << "Stosunek wysokości drzewa do logarytmu: " << bt->height(bt->head) / log2(r) << std::endl;
    
    clock_t s = clock();
    int n = 10000, licznik = 0;
    for (int i = 0; i < n; i++)
    {
        int x = abs((rand() << 15 + rand()) % 1000000);
        if (bt->get(x) != NULL) licznik++;

    }
    clock_t t3 = clock();
    std::cout << "\nLiczba znalezionych elementow: " << licznik << std::endl;
    std::cout << "Time:" << (float)(t3 - s) / (float)CLOCKS_PER_SEC << std::endl;
    std::cout << "Time for element:" << (float)(t3 - s) / (float)CLOCKS_PER_SEC / n << std::endl;



    /*std::cout << bt->inOrder(bt->head) << std::endl;
    bt->preOrder(bt->head);
    std::cout << "\n" << bt->height(bt->head);*/
    bt->clear(bt->head);
    return 0;
}
int main2()
{
    for (int i = 0; i < 10; i++)
    {
        int x = abs((rand() << 15 + rand()) % 1000000);
        std::cout << x << std::endl;
    }

}