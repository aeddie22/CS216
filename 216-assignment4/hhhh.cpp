//6209650297 สมิตา ขวัญสุวรรณ
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

enum EntryType { Legitimate, Empty };

// เก็บค่า index เเละ ค่า string
struct HashNode
{
    string element;
    enum EntryType info;
};

// เก็บค่า ขนาด ของตาราง hash table (127031)
struct HashTable
{
    int size;
    HashNode* table;
};

int HashFunc(int key, int size)
{
    return key % size;
}

HashTable* initializeTable(int size)
{
    HashTable* htable;

    htable = new HashTable;
    htable->size = size; // เช็ค ขนาดของ hashtable ว่าเป็น prime number หรือเปล่า
    htable->table = new HashNode[htable->size]; // สร้าง hashnode ที่มีขนาดเท่ากับ size ที่เรากำหนด

    for (int i = 0; i < htable->size; i++)
    {
        htable->table[i].info = Empty;
        htable->table[i].element = "";
    }
    return htable;
}

int Find(int key, string t_value, HashTable* htable)
{
    int pos = HashFunc(key, htable->size);
    int collisions = 0;
    while (htable->table[pos].info != Empty && htable->table[pos].element != t_value)
    {
        pos = pos + pow(++collisions - 1, 2);
        if (pos >= htable->size)
            pos = pos - htable->size;
    }
    return pos;
}

// what = 456100
void Insert(int key, string t_value, HashTable* htable)
{
    int pos = Find(key, t_value, htable);
    if (htable->table[pos].info != Legitimate)
    {
        htable->table[pos].info = Legitimate;
        htable->table[pos].element = t_value;
    }
}

void Retrieve(HashTable* htable)
{
    for (int i = 0; i < htable->size; i++)
    {
        string value = htable->table[i].element;
        if (value.empty())
            cout << "Position: " << i + 1 << " Element: Null" << endl;
        else
            cout << "Position: " << i + 1 << " Element: " << value << endl;
    }

}

int ConvertStrToInt(string str)
{
    int l = str.length();
    int results = 0;
    int convert;
    for (int i = 0; i < l; i++) {
        convert = str[i] - NULL;
        convert = pow(convert, 3);
        results += convert;
    }
    return results;
}
// what = w = 100, h = 101, a = 96, t = 97
int Calculate(string str) {
    int result = 0;
    result = ConvertStrToInt(str);

    return result;
}

vector<string> File_Transfer(string path)
{
    string myText;
    vector<string> result;
    ifstream MyReadFile(path);
    while (getline(MyReadFile, myText))
    {
        result.push_back(myText);
    }
    MyReadFile.close();

    return result;
}

void Query_To_Find(int key, string t_value, HashTable* htable)
{
    int pos = HashFunc(key, htable->size);
    int collisions = 1;
    while (true)
    {
        if (htable->table[pos].element == "" && htable->table[pos].info == Empty)
        {
            cout << "NOT FOUND" << endl;
            break;
        }
        else if (htable->table[pos].info == Legitimate && htable->table[pos].element != t_value)
            cout << "Collision: " << htable->table[pos].element << endl;
        else if (htable->table[pos].info == Legitimate && htable->table[pos].element == t_value)
        {
            cout << "FOUND: " << htable->table[pos].element << endl;
            break;
        }

        pos = pos + pow(collisions, 2);
        collisions = collisions + 1;
        if (pos >= htable->size)
            pos = pos - htable->size;
    }
}
/*
 * Main Contains Menu
 */
int main()
{
    vector<string> text;
    vector<int> data;
    HashTable* htable;

    // เริ่มสร้างตาราง
    htable = initializeTable(127031);
    // อ่านข้อมูลจาก dict ที่อาจารย์ให้
    text = File_Transfer("dict.txt");
    // แปลง String เป็น ASCII ยกกำลัง 3 และ ใส่ key ทุกตัวจาก dict.txt ลงไปยัง hash table
    for (int i = 0; i < text.size(); i++)
        Insert(Calculate(text[i]), text[i], htable);

    // แสดงข้อมูลที่มีอยู่ใน hash table ทั้งหมด
    //Retrieve(htable);

    // ค้นหาคำ จากคียร์บอร์ด
    string keyword = "";
    int query_data = 0;
    while (true) {
        cout << "Enter a word: ";
        getline(cin, keyword);
        query_data = Calculate(keyword);
        Query_To_Find(query_data, keyword, htable);

        if (keyword.length() < 1)
            break;
    }

    return 0;

};
