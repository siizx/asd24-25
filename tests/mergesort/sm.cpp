
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std; // minchia, mi ero dimenticato tutte ste cazzatine

void fondi(vector<int> &v, unsigned int inizio, unsigned int centro, unsigned int fine)
{
    if (inizio < fine)
    {
        vector<int> sin, des;
        unsigned int indiceDestra = 0;
        unsigned int indiceSinistra = 0;

        for (unsigned int i = inizio; i <= centro; i++)
        {
            sin.push_back(v[i]);
        }

        for (unsigned int i = centro + 1; i <= fine; i++)
        {
            des.push_back(v[i]);
        }

        // ora che abbiamo popolato i vettori, sappiamo la loro size.
        unsigned int maxSin = sin.size() - 1;
        unsigned int maxdes = des.size() - 1;

        for (unsigned int i = inizio; i <= fine; i++)
        {
            if (indiceSinistra <= maxSin && indiceDestra <= maxdes)
            {
                if (sin[indiceSinistra] < des[indiceDestra])
                {
                    v[i] = sin[indiceSinistra];
                    indiceSinistra++;
                    continue;
                }
                else
                {
                    v[i] = des[indiceDestra];
                    indiceDestra++;
                    continue;
                }
            }
            else if (indiceSinistra <= maxSin && indiceDestra > maxdes)
            {
                v[i] = sin[indiceSinistra];
                indiceSinistra++;
                continue;
            }
            else
            {
                v[i] = des[indiceDestra];
                indiceDestra++;
                continue;
            }
        }
    }
}

void ms(vector<int> &v, unsigned int inizio, unsigned int fine)
{
    if (inizio < fine)
    {
        unsigned int centro = (inizio + fine) / 2;
        ms(v, inizio, centro);
        ms(v, centro + 1, fine);
        fondi(v, inizio, centro, fine);
    }
}

void mergesort(vector<int> &v)
{
    if (v.size() > 0)
    {
        ms(v, 0, v.size() - 1);
    }
}

int main()
{

    std::vector<int> v = {22, 536, 75, 1, 95, 83, 99, 20, 17, 53};

    cout << "Vector disordinato: ";
    for (unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    mergesort(v);

    cout << "Vector ordinato: ";
    for (unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
