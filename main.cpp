#include <QCoreApplication>
#include <QDebug>
#include <QStack>

void printJavaStyle(QList<QString> list);
void printSTLstyle(QList<QString> list);
void printUsingForeach(QList<QString> list);
void printInReverse1(QList<QString> list);
void printInReverse2(QList<QString> list);
void printInReverse3(QList<QString> list);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";

    // TODO: using Java-style iterators print the longest name from the list
    // use QString::arg to output message with this name
    printJavaStyle(names);


    // TODO: using STL-style iterators print the shortest name from the list
    // use QString::prepend and append to output message with this name
    printSTLstyle(names);



    // TODO: using foreach and QStringList show all names with "lynn" suffix
    // and print it separated by ',' as one string
    printUsingForeach(names);


    // print all names in reverse order
    // TODO: 1. Using QStack
    printInReverse1(names);


    // TODO: 2. Using other QList
    printInReverse2(names);

    // TODO: 3. Without other containers
    printInReverse3(names);

    return a.exec();
}

void printJavaStyle(QList<QString> list)
{
    QMutableListIterator<QString> iter(list);
    QString longestName;
    while (iter.hasNext()) {
        QString name = iter.next();
        if(name.size() > longestName.size())
        {
           longestName = name;
        }
    }
    qDebug()<< QString("The longest name is %1").arg(longestName) << "\n";
}

void printSTLstyle(QList<QString> list)
{
    QString shortestName = "1234567890";
    foreach(auto const & i, list)
    {
        if(i.size() < shortestName.size())
        {
            shortestName = i;
        }
    }
    qDebug()<< QString(" is the shortest name").prepend(shortestName);
    qDebug()<< QString("The shortest name is ").append(shortestName) << "\n";
}

void printUsingForeach(QList<QString> list)
{
    QStringList mylist;
    foreach(auto const & i, list)
    {
        if(i.contains("lynn", Qt::CaseInsensitive))
        {
            mylist << i;
        }
    }
    qDebug() << mylist << "\n";
}

void printInReverse1(QList<QString> list)
{
    QStack<QString> stack;
    foreach(auto const &i, list)
    {
        stack.push(i);
    }
    while (!stack.isEmpty())
        qDebug() << stack.pop();

    qDebug() << "\n";
}

void printInReverse2(QList<QString> list)
{
    QList<QString> myList;
    for(auto i = list.rbegin(); i != list.rend(); i++)
    {
        myList.append(*i);
    }
    qDebug() << myList << "\n";
}

void printInReverse3(QList<QString> list)
{
    for(auto i = list.rbegin(); i != list.rend(); i++)
    {
        qDebug() << *i;
    }
    qDebug() << "\n";
}
