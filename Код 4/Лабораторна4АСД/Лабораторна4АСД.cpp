#include <iostream>

using namespace std;

#define N 7
#define M 8

    struct docEdit  // Створення структури "Подія редагування документу"
    {
        string text;
        int lineId;

    };

    struct Stack   // Створення структури стеку
    {
        docEdit stack[N];
        int topId = -1;

        void push(docEdit event)  // Функція додавання елементу
        {
            if (topId < N - 1)
            {
                topId++;
                stack[topId] = event;
            }
            else  // Якщо стек повний
                cout << "Stack is full. New event can't be added.\n";
        }

        void pop()  // Функція видалення елементу зі стеку
        {
            if (topId == -1)  // Якщо стек пустий
            {
                cout << "Stack is already empty.\n";
            }
            else
            {
                topId--;
            }
        }

        bool empty(bool quiet = false)   // Функція перевірки стека на пустоту
        {
            if (topId == -1)  // Якщо стек пустий
            {
                if (!quiet)
                    cout << "Stack is empty\n";
                return true;
            }
            else  // Якщо в стеку є елементи
            {
                if (!quiet)
                    cout << "Stack isn't empty\n";
                return false;
            }
        }

        int size(bool quiet = false)  // Функція визначення кількості елементів у стеку
        {
            if (!quiet)
                cout << "Stack consists of " << topId + 1 << " event(s).\n";
            return topId + 1;
        }

        void clear()  // Функція видалення всіх елементів зі стеку
        {
            topId = -1;
        }

        docEdit top(bool quiet = false)  // Функція виведення елементу, що знаходиться на вершині стеку
        {
            if (topId == -1)  // Якщо стек пустий
            {
                if (!quiet)
                    cout << "Stack is empty\n";
                docEdit returnedElem;
                return returnedElem;
            }
            else  // В іншому випадку виводиться елемент на вершині стеку
            {
                if (!quiet)
                    cout << "Last edit was \"" << stack[topId].text << "\" operation, that was used on the line " << stack[topId].lineId << ".\n";
                return stack[topId];
            }
        }

    };

    struct Worker  // Створення структури "Робітник"
    {
        string position;
        float workExp;
        int salary;
    };

    struct Queue  // Створення структури черги
    {
        Worker queue[M];
        int head = -1;
        int tail = -1;

        void push(Worker worker)  // Функція додавання елементу
        {
            if (head - tail == -7)  // Якщо черга заповнена
                cout << "The queue is full. New worker can't be added.\n";

            else if (head == -1)  // Якщо черга пуста
            {
                head++;
                tail++;
                queue[tail % M] = worker;
            }

            else  // В інших випадках додається елемент
            {
                tail++;
                queue[tail % M] = worker;
            }
        }

        void pop()  // Функція видалення елементу з черги
        {
            if (head == -1)  // Якщо черга пуста
            {
                cout << "Queue is already empty.\n";
            }

            else if (head % M == tail % M)  // Якщо видаляється останній елемент
            {
                head = -1;
                tail = -1;
            }

            else  // В звичайному випадку просто видаляється елемент
            {
                head++;
            }
        }

        bool empty(bool quiet = false)  // Функція перевірки черги на пустоту
        {
            if (head == -1)  // Якщо черга пуста
            {
                if (!quiet)
                    cout << "The queue is empty.\n";
                return true;
            }

            else  // Якщо в черзі є елементи
            {
                if (!quiet)
                    cout << "The queue isn't empty\n";
                return false;
            }
        }

        int size(bool quiet = false)  // Функція визначення кількості елементів у черзі
        {
            if (head == -1)  // Якщо в черзі немає елементів
            {
                if (!quiet)
                    cout << "The queue consists of 0 worker(s).\n";
                return 0;
            }

            else  // В іншому випадку
            {
                if (!quiet)
                    cout << "The queue consists of " << tail - head + 1 << " worker(s).\n";
                return tail - head + 1;
            }
        }

        void clear()  // Функція видалення всіх елементів з черги
        {
            head = -1;
            tail = -1;
        }

        Worker front(bool quiet = false)  // Функція виведення найпершого елементу в черзі
        {
            if (head == -1)  // Якщо черга пуста
            {
                if (!quiet)
                    cout << "The queue is empty.\n";
                void;
            }

            else  // В іншому випадку виводиться найперший елемент
            {
                if (!quiet)
                {
                    cout << "The first worker in the queue holds the position of " << queue[head % M].position << ", his work experience: " << queue[head % M].workExp << " years\n";
                    cout << "and his salary is " << queue[head % M].salary << " UAH.\n";
                }
                return queue[head % M];
            }
        }

    };

    void print(Stack stack)  // Функція виведення вмісту стеку
    {
        if (stack.size(true) == 0)  // Якщо стек пустий
            cout << "The stack is empty.\n";
        else
        {
            docEdit event;
            while (!stack.empty(true))
            {
                event = stack.top(true);
                cout << stack.size(true) << ") Operation: \"" << event.text << "\" was executed on the line " << event.lineId << ".\n";
                stack.pop();
            }
        }
        cout << endl;
    }

    void print(Queue queue)  // Функція виведення вмісту черги
    {
        if (queue.size(true) == 0)  // Якщо черга пуста
            cout << "The queue is empty\n";
        else
        {
            Worker person;
            int queueId = 1;
            while (!queue.empty(true))
            {
                person = queue.front(true);
                cout << queueId << ") Worker's position: \"" << person.position << "\", experience: " << person.workExp << " years, salary: " << person.salary << " UAH.\n";
                queue.pop();
                queueId++;
            }
        }
        cout << endl;
    }



int main()
{
    int taskNum;
    while (true)
    {
        cout << "Enter the number of task(0 to exit): ";  // Вибір завдання
        cin >> taskNum;

        if (taskNum == 0)  // Вихід з програми
        {
            return 0;
        }

        else if (taskNum == 1)  // Перше завдання 
        {
            cout << "Task 1:\n\n";

            cout << "1)\n";  // Створити стек історії редагування документу, розмір історії 7.

            Stack editHist;

            editHist.size();
            print(editHist);

            cout << "2)\n";  // Додати в неї 4 різні події.

            editHist.push({ "Writing", 1 });
            editHist.push({ "Copying", 42 });
            editHist.push({ "Inserting", 36 });
            editHist.push({ "Paragraph creation", 108 });

            editHist.size();
            print(editHist);

            cout << "3)\n";  // Додати в неї ще 5 подій.

            editHist.push({ "Cutting", 77 });
            editHist.push({ "Inserting", 14 });
            editHist.push({ "Changing background colour", 50 });
            editHist.push({ "Inserting image", 69 });
            editHist.push({ "Changing text size", 2 });

            editHist.size();
            print(editHist);

            cout << "4)\n";  // Зробити “undo” останніх двох подій.

            editHist.pop();
            editHist.pop();

            editHist.size();
            print(editHist);

            cout << "5)\n";  // Зробити “undo” останньої події, додати її ще раз вже з іншим текстом.

            docEdit task5Event = editHist.top();
            editHist.pop();
            task5Event.text = "Changing text colour";
            editHist.push(task5Event);
            editHist.top();

            editHist.size();
            print(editHist);

            cout << "6)\n";  // Зробити “undo” ще 6 разів.

            editHist.pop();
            editHist.pop();
            editHist.pop();
            editHist.pop();
            editHist.pop();
            editHist.pop();

            editHist.size();
            print(editHist);
        }

        else if (taskNum == 2)  // Друге завдання 
        {
            cout << "Task 2:\n\n";

            cout << "1)\n";  // Створити чергу робітників на підвищення зарплати, розмір черги 8.

            Queue SalaryIncr;

            SalaryIncr.size();
            print(SalaryIncr);

            cout << "2)\n";  // Додати в неї 5 різних робітників.

            SalaryIncr.push({ "SMM Manager", 2.5, 16000 });
            SalaryIncr.push({ "Frontend developer", 1, 25000 });
            SalaryIncr.push({ "Cleaner", 5, 9000 });
            SalaryIncr.push({ "Accountant", 8, 16300 });
            SalaryIncr.push({ "Assistant", 4, 13000 });

            SalaryIncr.size();
            print(SalaryIncr);

            cout << "3)\n";  // Взяти першого робітника, підвищити йому зарплату на 200 та знову додати в чергу.

            Worker task3Worker = SalaryIncr.front();
            SalaryIncr.pop();
            task3Worker.salary += 200;
            cout << "Now the salary of " << task3Worker.position << " is " << task3Worker.salary << " UAH\n";
            SalaryIncr.push(task3Worker);

            SalaryIncr.size();
            print(SalaryIncr);

            cout << "4)\n";  // Додати ще 4 робітника.

            SalaryIncr.push({ "System administrator", 0.5, 18000 });
            SalaryIncr.push({ "Office clerk", 15, 14250 });
            SalaryIncr.push({ "HR Manager", 0.5, 18000 });
            SalaryIncr.push({ "Backend developer", 2, 30000 });

            SalaryIncr.size();
            print(SalaryIncr);

            cout << "5)\n";  // Забрати 3 робітників з черги.

            SalaryIncr.pop();
            SalaryIncr.pop();
            SalaryIncr.pop();

            SalaryIncr.size();
            print(SalaryIncr);

            cout << "6)\n";  // Забрати ще 7 робітників з черги.

            SalaryIncr.pop();
            SalaryIncr.pop();
            SalaryIncr.pop();
            SalaryIncr.pop();
            SalaryIncr.pop();
            SalaryIncr.pop();
            SalaryIncr.pop();

            SalaryIncr.size();
            print(SalaryIncr);

        }
        else  // Вибрано завдання, що не існує
            cout << "This task doesn't exist.\n";
    }
}
