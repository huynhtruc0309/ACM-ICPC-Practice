## Khai báo và sử dụng
```
sort(iterator1, iterator 2, option);
```
## Sắp xếp tăng dần
```
sort(v.begin(), v.end())
```
## Sắp xếp tăng dần (viết hàm/tham số)
```
sort(v.begin(), v.end(), option);
bool option (int a, int b)
{
    return a < b;
}
```
## Sắp xếp giảm dần
```
#include <functional>
sort(v.begin(), v.end(), greater<int>());
```
## Sắp xếp giảm dần (viết hàm/ tham số)
```
sort(v.begin(), v.end(), option);
bool option(int a, int b)
{
    return a > b;
}
```
## Sử dụng hàm sort để sắp xếp mảng con
```
sort(v.begin() + 1, v.begin() + 4);
```
## Khai báo cấu trúc phân số
```
struct Fraction
{
    int num;
    int denom;
}

vector<Fraction> v;
v.push_back(Fraction{5, 4});
v.push_back(Fraction{7, 9});
v.push_back(Fraction{1, 8});
```
## Sắp xếp mảng cấu trúc tăng dần
```
bool option(const Fraction &x, const Fraction &y)
{
    return (double)x.num/x.denom < (double)y.num/y.denom;
}
sort(v.begin(), v.end(), option);
```
## Sắp xếp mảng cấu trúc giảm dần
```
bool option(const Fraction &x, const Fraction &y)
{
    return (double)x.num/x.denom > (double)y.num/y.denom;
}
sort(v.begin(), v.end(), option);
```
## Sắp xếp cấu trúc sinh viên
### Cách 1
```
struct Student
{
    int id;
    double score;
};

bool option(const& Student A, const& Student B)
{
    if (A.score > B.score || A.score == B.score && A.id < B.id)
        return true;
    return false;
}

int main()
{
    vector<Student> list_student;
    list_student.push_back({100, 8.5});
    list_student.push_back({101, 7.5});
    list_student.push_back({102, 8.5});
    list_student.push_back({103, 10});
    list_student.push_back({104, 10});
    list_student.push_back({105, 4.5});
    sort(list_student.begin(), list_student.end(), option);
    for (int i = 0; i < list_student.size(); i++)
        cout << list_student[i].id << " " << list_student[i].score << endl;

    return 0;
}
```
### Cách 2
```
struct Student {
    int id;
    double score;
    bool operator < (const Student& B)
    {
        if (score > B.score || (score == B.score && id < B.id))
            return true;
        return false;
    }
};

int main()
{
    vector<Student> list_student;
    list_student.push_back({100, 8.5});
    list_student.push_back({101, 7.5});
    list_student.push_back({102, 8.5});
    list_student.push_back({103, 10});
    list_student.push_back({104, 10});
    list_student.push_back({105, 4.5});
    sort(list_student.begin(), list_student.end());
    for (int i = 0; i < list_student.size(); i++)
        cout << list_student[i].id << " " << list_student[i].score << endl;

    return 0;
}
```