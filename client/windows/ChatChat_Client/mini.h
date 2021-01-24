#ifndef MINI_H
#define MINI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Mini; }
QT_END_NAMESPACE

class Mini : public QMainWindow
{
    Q_OBJECT

public:
    Mini(QWidget *parent = nullptr);
    ~Mini();

private:
    Ui::Mini *ui;
};
#endif // MINI_H
