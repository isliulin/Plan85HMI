#ifndef CTRLTRAINOUTLINE_H
#define CTRLTRAINOUTLINE_H

#include <QWidget>

#define TRAINMAX 4
#define WIDTH 395
#define HEIGHT 213
#define WIDTHMAX 800
#define HEIGHTMAX 500

namespace Ui {
class CtrlTrainOutLine;
}

class CtrlTrainOutLine : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlTrainOutLine(QWidget *parent = 0);
    ~CtrlTrainOutLine();
    void updatePagePos(int trainnum);
    void updateData(QList<bool>direction,QList<unsigned short int>kn,QList<bool>panto,QList<bool>gaoya,
                    QList<bool>zhuduan,QList<bool>parking,QList<bool>traction,QList<bool>brake);
private:
    Ui::CtrlTrainOutLine *ui;
};

#endif // CTRLTRAINOUTLINE_H
