#include "devicedatariom.h"
#include "ui_devicedatariom.h"
#include <QTableWidget>
#include <QButtonGroup>

#define _LOCAL1 80, 50, 600, 176
#define _LOCAL2 80, 250, 600, 176
#define _LOCALDO1 80, 50, 600, 176
#define _LOCALDO2 80, 250, 600, 176
#define _LOCALAX 80, 300, 600, 88
#define _ROWDI 8
#define _ROWDO 8
#define _ROWAX 4
#define _COLUMNDI 3
#define _COLUMNDO 2
#define _COLUMNAX 4

#define _TABLE ("color:white; gridline-color: white;")
enum ButtonID
{
    uRiom1 = 1,
    uRiom2
};

DeviceDataRIOM::DeviceDataRIOM(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceDataRIOM)
{
    ui->setupUi(this);
    this->diTable1 = new QTableWidget(_ROWDI, _COLUMNDI, this);
    this->diTable2 = new QTableWidget(_ROWDI, _COLUMNDI, this);
    this->doTable1 = new QTableWidget(_ROWDO, _COLUMNDO, this);
    this->doTable2 = new QTableWidget(_ROWDO, _COLUMNDO, this);
    this->axTable = new QTableWidget(_ROWAX, _COLUMNAX, this);

    this->diTable1->setGeometry(_LOCAL1);
    this->diTable2->setGeometry(_LOCAL2);
    this->doTable1->setGeometry(_LOCALDO1);
    this->doTable2->setGeometry(_LOCALDO2);
    this->axTable->setGeometry(_LOCALAX);

    this->initialTableView(this->diTable1);
    this->initialTableView(this->diTable2);
    this->initialTableView(this->doTable1);
    this->initialTableView(this->doTable2);
    this->initialTableView(this->axTable);

    this->setWidth(this->diTable1);
    this->setWidth(this->diTable2);
    this->setWidth(this->doTable1, true);
    this->setWidth(this->doTable2, true);
    this->setWidth(this->axTable, false, true);

    this->riomButtons = new QButtonGroup;
    this->riomButtons->addButton(ui->btnRiom1, uRiom1);
    this->riomButtons->addButton(ui->btnRiom2, uRiom2);
    this->riomButtons->setExclusive(true);
    connect(riomButtons, SIGNAL(buttonClicked(int)), this, SLOT(onRiomButtonClicked(int)));

    this->r1di1 << "电钥匙" << "升弓" << "降弓" << "主断合" << "主断分" << "电控紧急"
                << "向前" << "向后" << "方向零位" << "司控器B位" << "司控器T位" << "司控器B1/3位"
                << "司控器T1/3位" << "司控器B2/3位" << "司控器T2/3位" << "司控器零位" << "自动换端"  << "停放制动施加"
                << "停放制动缓解" << "" << "" << "" << "" << "";

    this->r1di2 << "电钥匙" << "升弓" << "降弓" << "主断合" << "主断分" << "电控紧急"
                << "向前" << "向后" << "方向零位" << "司控器B位" << "司控器T位" << ""
                << "电笛" << "低音风笛" << "高音风笛" << "无人警惕按钮" << "无人警惕脚踏" << "强泵位"
                << "运行位" << "复位按钮" << "定速按钮" << "撒沙脚踏" << "空调故障" << "半自动过分相按钮";

    this->r2di1 << "接地开关状态" << "高压隔离开关状态" << "受电弓压力开关" << "受电弓隔离阀" << "辅助风缸隔离塞门" << "油流1状态"
                << "主变压器温度开关" << "主变压力释放阀" << "油流2状态" << "" << "制动缸压力开关" << "控制电路接地"
                << "主断状态" << "停放制动压力2开关" << "无火塞门状态" << "高压隔离开关转换开关状态" << "监控设备紧急" << "紧急制动隔离塞门状态"
                << "24V模块状态" << "BCU紧急" << "BCU故障" << "BCU卸载" << "总风压力开关3状态" << "辅助风缸压力开关";

    this->r2di2 << "接地开关状态" << "主断状态" << "受电弓压力开关" << "" << "受电弓隔离阀" << "主变温度开关"
                << "主变压力释放阀" << "油流2状态" << "" << "制动缸压力开关2状态" << "油流1状态" << "布赫继电器状态（报警）"
                << "布赫继电器状态（动作）" << "总风压力开关3状态" << "无火塞门状态" << "紧急制动隔离塞门状态" << "总风压力开关2状态" << ""
                << "机械间50度" << "机械间35度" << "" << "机械间-25度" << "" << "";

    this->r2di3 << "输入库接触器状态" << "输入库相序状态" << "库内动车位" << "测试位" << "辅助压缩机接触器状态" << "车长阀状态"
                << "输入库断路器状态" << "输入库充电接触器状态" << "输入库工作接触器状态" << "预告和恢复：ANSC2" << "强断：ANSC2" << "自动过分相故障ANSC故障："
                << "安全回路状态" << "监控卸载" << "" << "" << "" << ""
                << "电钥匙" << "" << "" << "" << "" << "";

    this->r2di4 << "压缩机接触器2状态" << "压缩机接触器3状态" << "压缩机低温保护" << "压缩机断路器状态" << "压缩机接触器1状态" << "干燥器故障状态"
                << "原边过流继电器状态" << "停放制动隔离阀状态" << "1架制动缸隔离阀状态" << "" << "受电弓前控制环状态" << "受电弓后控制环状态"
                << "主断路器前控制环状态" << "主断路器后控制环状态" << "单节模式继电器状态" << "" << "" << ""
                << "辅助压缩机停机" << "" << "" << "后备制动" << "" << "";

    this->r2di5 << "压缩机接触器2状态" << "压缩机接触器3状态" << "压缩机断路器状态" << "压缩机接触器1状态" << "原边过流继电器状态" << "停放制动隔离阀状态"
                << "Ⅱ架制动缸隔离阀状态" << "撒砂隔离阀状态" << "顶盖1通风开关状态" << "停放压力开关1状态" << "机车电器紧急" << "预加热接触器3状态"
                << "-25摄氏度预加热状态" << "顶盖2通风开关状态" << "" << "总风压力开关1状态" << "总风压力开关2状态" << ""
                << "防火压力检测1" << "防火压力检测2" << "" << "" << "强制加热" << "";

    this->r1do1 << "他端占用" << "主断分" << "轴隔离" << "辅助隔离" << "压缩机故障" << "蓄电池低压"
                << "换端" << "" << "" << "" << "" << ""
                << "" << "" << "" << "" ;

    this->r2do1 << "升弓继电器" << "无人警惕报警" << "" << "单节模式输出" << "" << "主断闭合"
                << "压缩机接触器1命令" << "压缩机接触器2命令" << "压缩机接触器3命令" << "车顶通风继电器2" << "" << ""
                << "" << "" << "" << "";

    this->r2do2 << "主断闭合" << "" << "" << "" << "输入库继电器" << "蓄电池继电器"
                << "主断故障继电器" << "本节防火管报警" << "它节防火管报警" << "蓄电池禁止切除继电器" << "库用工作继电器" << "库内工作继电器"
                << "停放制动按钮指示灯" << "无人警惕报警" << "" << "" ;

    this->r2do3 << "" << "操纵端激活继电器1" << "操纵端激活继电器2" << "轮缘润滑继电器" << "停放制动继电器" << "辅压机排风电磁阀"
                << "向前" << "向后" << "牵引" << "零位" << "制动" << ""
                << "本节防火管报警" << "它节防火管报警" << "" << "" ;

    this->r2do4 << "辅助压缩机继电器" << "无人警惕-BCU" << "" << "紧急制动-BCU" << "空电联锁信号" << "前撒沙"
                << "后撒沙" << "高压隔离开关继电器开" << "高压隔离开关继电器关" << "单节升弓继电器" << "升弓继电器2" << "零速"
                << "电钥匙" << "" << "" << "" ;

//    this->r1ax << "" << "调速手柄模拟量输入" << "" << "" << "" << ""
//                << "" << "";

    //default show riom1
    onRiomButtonClicked(uRiom1);
}

DeviceDataRIOM::~DeviceDataRIOM()
{
    delete ui;
}

void DeviceDataRIOM::setTableView(QTableWidget *table,QList<QString> channelNameList, int column)
{
    int size = channelNameList.size();
    if (0 == column)
    {
        logger()->error("set tableView devide 0");
        return;
    }

    for (int count = 0; count < size; count++)
    {
        if (4 == column)//ax
        {
            table->item(count / 2, (count % 2) * 2)->setText(channelNameList[count]);
        }
        else //di/do
        {
            table->item(count/column, count%column)->setText(channelNameList[count]);
        }
    }
}


void DeviceDataRIOM::setViews( int page)
{

    if (this->isRiom1)
    {
        ui->labelPage->setText(QString::number(page) + "/" + QString::number(2));
        if (1 == page)
        {
            cleanContent(this->diTable1);
            cleanContent(this->diTable2);
            this->setTableView(this->diTable1, this->r1di1, _COLUMNDI);
            this->setTableView(this->diTable2, this->r1di2, _COLUMNDI);

            ui->labelName1->setText("RIDI1");
            ui->labelName2->setText("R1DI2");
            this->diTable1->show();
            this->diTable2->show();
            this->doTable1->hide();
            this->doTable2->hide();
            this->axTable->hide();

        }
        else if (2 == page)
        {
            cleanContent(this->doTable1);
            cleanContent(this->axTable);
            this->setTableView(this->doTable1, this->r1do1, _COLUMNDO);
           this->axTable->item(0,2)->setText("调速手柄模拟量输入");

            ui->labelName1->setText("RIDO1");
            ui->labelName2->setText("R1AX");
            this->diTable1->hide();
            this->diTable2->hide();
            this->doTable1->show();
            this->doTable2->hide();
            this->axTable->show();
        }
        else
        {
            logger()->error("page number is over the scope");
        }
    }
    else //riom2
    {
        ui->labelPage->setText(QString::number(page) + "/" + QString::number(5));
        if (1 == page)
        {
            cleanContent(this->diTable1);
            cleanContent(this->diTable2);
            this->setTableView(this->diTable1, this->r2di1, _COLUMNDI);
            this->setTableView(this->diTable2, this->r2di2, _COLUMNDI);
            ui->labelName1->setText("R2DI1");
            ui->labelName2->setText("R2DI2");
            this->diTable1->show();
            this->diTable2->show();
            this->doTable1->hide();
            this->doTable2->hide();
            this->axTable->hide();
        }
        else if (2 == page)
        {
            cleanContent(this->diTable1);
            cleanContent(this->diTable2);
            this->setTableView(this->diTable1, this->r2di3, _COLUMNDI);
            this->setTableView(this->diTable2, this->r2di4, _COLUMNDI);
            ui->labelName1->setText("R2DI3");
            ui->labelName2->setText("R2DI4");
            this->diTable1->show();
            this->diTable2->show();
            this->doTable1->hide();
            this->doTable2->hide();
            this->axTable->hide();
        }
        else if (3 == page)
        {
            cleanContent(this->diTable1);
            cleanContent(this->doTable2);
            this->setTableView(this->diTable1, this->r2di5, _COLUMNDI);
            this->setTableView(this->doTable2, this->r2do1, _COLUMNDO);
            ui->labelName1->setText("R2DI5");
            ui->labelName2->setText("R2DO1");
            this->diTable1->show();
            this->diTable2->hide();
            this->doTable1->hide();
            this->doTable2->show();
            this->axTable->hide();
        }

        else if (4 == page)
        {
            cleanContent(this->doTable1);
            cleanContent(this->doTable2);
            this->setTableView(this->doTable1, this->r2do2, _COLUMNDO);
            this->setTableView(this->doTable2, this->r2do3, _COLUMNDO);
            ui->labelName1->setText("R2DO2");
            ui->labelName2->setText("R2DO3");
            this->diTable1->hide();
            this->diTable2->hide();
            this->doTable1->show();
            this->doTable2->show();
            this->axTable->hide();
        }

        else if (5 == page)
        {
            cleanContent(this->doTable1);
            this->setTableView(this->doTable1, this->r2do4, _COLUMNDO);
            this->diTable1->hide();
            this->diTable2->hide();
            this->doTable1->show();
            this->doTable2->hide();
            this->axTable->hide();
            ui->labelName1->setText("R2DO4");
            ui->labelName2->setText("");
        }
    }
}

void DeviceDataRIOM::setWidth(QTableWidget *table,bool isDo, bool isAx)
{
    if (isAx)
    {
        table->setColumnWidth(0,150);
        table->setColumnWidth(1,150);
        table->setColumnWidth(2,150);
    }
    else if (isDo)
    {
        table->setColumnWidth(0,300);
    }
    else
    {
        table->setColumnWidth(0,200);
        table->setColumnWidth(1,200);
    }
}

/**
@brief:initial the table when new
@param:the table object
*/
void DeviceDataRIOM::initialTableView(QTableWidget *table){
    if (NULL == table)
    {
        _LOG << "table is null in IOSignals::initialTableView;";
        return;
    }

    table->setStyleSheet(_TABLE);
    table->hide();
    table->horizontalHeader()->hide();
    table->verticalHeader()->hide();
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->horizontalHeader()->setStretchLastSection(true);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->verticalHeader()->setStretchLastSection(true);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setFocusPolicy(Qt::NoFocus);
    table->verticalHeader()->setDefaultSectionSize(22);


    for (int row = 0; row < table->rowCount(); row ++)
    {
        for (int column = 0; column < table->columnCount(); column ++)
        {
            QTableWidgetItem *tableItem = new QTableWidgetItem("");
            tableItem->setFlags(Qt::ItemIsEditable);
            table->setItem(row, column, tableItem);
        }
    }
}


/**
@brief:update the di/do states and stylesheet of the table
@param: *table:the table to update; &state:the list records the states of one di/do;
column:the column of table(di column = 3; do column = 2)
*/
void DeviceDataRIOM::updateDio(QTableWidget *table, QList<bool> &state, int column)
{
    if (0 == column)
    {
        logger()->error("the state devide 0");
        return;
    }
    int tableRow, tableColumn;

    for (int i = 0; i < state.length(); i++)
    {
        tableRow = i / column;
        tableColumn = i % column;

        if (state.at(i))
        {
            table->item(tableRow, tableColumn)->setTextAlignment(Qt::AlignLeft);
            table->item(tableRow, tableColumn)->setTextColor(QColor(0, 0, 0));
            table->item(tableRow, tableColumn)->setBackgroundColor(QColor(0, 255, 0));
        }
        else
        {
            table->item(tableRow, tableColumn)->setTextAlignment(Qt::AlignLeft);
            table->item(tableRow, tableColumn)->setTextColor(QColor(0, 0, 0));
            table->item(tableRow, tableColumn)->setBackgroundColor(QColor(255, 0, 0));
        }
    }
}

// the function will use when there are more do channels
//void DeviceDataRIOM::updateAx(QTableWidget *table, QList<int> &state)
//{
//    if (0 == _COLUMNDOAX)//will not happen(in case of)
//    {
//        logger()->error("the state devide 0");
//        return;
//    }
//    int tableRow, tableColumn;

//    for (int i = 0; i < state.length(); i++)
//    {
//        tableRow = i / (_COLUMNDOAX/2);
//        tableColumn = i % (_COLUMNDOAX/2) + 1;
//        tableIndexColumn = tableColumn - 1;
//        table->item(tableRow, tableIndexColumn)->setText(...);

//        table->item(tableRow, tableColumn)->setTextAlignment(Qt::AlignLeft);
//        table->item(tableRow, tableColumn)->setText(QString::number(state.at(i)));
//        table->item(tableRow, tableColumn)->setBackgroundColor(QColor(0, 255, 0));
//    }
//}

void DeviceDataRIOM::updatePage()
{
    QList<bool> states;
    if (this->isRiom1)
    {
        if (1 == this->page)
        {
            states << this->database->data_RIOM->RIOM1_B_CABKEY_1 << this->database->data_RIOM->RIOM1_B_PG_UP_1
                   << this->database->data_RIOM->RIOM1_B_PG_DN_1 << this->database->data_RIOM->RIOM1_B_PG_UP_1
                   << this->database->data_RIOM->RIOM1_B_MCBOFF_1 << this->database->data_RIOM->RIOM1_B_EmBrButtton_1
                   << this->database->data_RIOM->RIOM1_B_DIR_FORWARD_1 << this->database->data_RIOM->RIOM1_B_DIR_BACKWARD_1
                   << this->database->data_RIOM->RIOM1_B_DIR_ZERO_1 << this->database->data_RIOM->RIOM1_B_MSCT_B_1
                   << this->database->data_RIOM->RIOM1_B_MSCT_T_1 << this->database->data_RIOM->RIOM1_B_MSCT_B13
                   << this->database->data_RIOM->RIOM1_B_MSCT_T13 << this->database->data_RIOM->RIOM1_B_MSCT_B23
                   << this->database->data_RIOM->RIOM1_B_MSCT_T23 << this->database->data_RIOM->RIOM1_B_MSCT_N
                   << this->database->data_RIOM->RIOM1_B_CAB_CHANGE << this->database->data_RIOM->RIOM1_B_PARKBRAKE_ON
                   << this->database->data_RIOM->RIOM1_B_PARKBRAKE_OFF << false
                   << false << false << false << false;
            updateDio(this->diTable1, states, _COLUMNDI);
            states.clear();

            states << this->database->data_RIOM->RIOM1_B_CABKEY_2 << this->database->data_RIOM->RIOM1_B_PG_UP_2
                   << this->database->data_RIOM->RIOM1_B_PG_DN_2 << this->database->data_RIOM->RIOM1_B_MCBON_2
                   << this->database->data_RIOM->RIOM1_B_MCBOFF_2 << this->database->data_RIOM->RIOM1_B_EmBrButtton_2
                   << this->database->data_RIOM->RIOM1_B_DIR_FORWARD_2 << this->database->data_RIOM->RIOM1_B_DIR_BACKWARD_2
                   << this->database->data_RIOM->RIOM1_B_DIR_ZERO_2 << this->database->data_RIOM->RIOM1_B_MSCT_B_2
                   << this->database->data_RIOM->RIOM1_B_MSCT_T_2 << false
                   << this->database->data_RIOM->RIOM1_B_HORN_ELEC << this->database->data_RIOM->RIOM1_B_HORN_LOW
                   << this->database->data_RIOM->RIOM1_B_HORN_HIGH << this->database->data_RIOM->RIOM1_B_DEADMAN_BUTTON
                   << this->database->data_RIOM->RIOM1_B_DEADMAN_FOOT << this->database->data_RIOM->RIOM1_B_CPR_P
                   << this->database->data_RIOM->RIOM1_B_CPR_R << this->database->data_RIOM->RIOM1_B_RESET
                   << this->database->data_RIOM->RIOM1_B_CONS << this->database->data_RIOM->RIOM1_B_FOOT_SAND
                   << this->database->data_RIOM->RIOM1_B_AIRCONDITION_FAULT << this->database->data_RIOM->RIOM1_B_MNSC;
            updateDio(this->diTable2, states, _COLUMNDI);
            states.clear();
        }
        else if (2 == this->page)
        {
            states << this->database->data_RIOM->M1_R1_B_LIGHT_OTHERCAB<<  this->database->data_RIOM->M1_R1_B_LIGHT_MCB_OFF
                   << this->database->data_RIOM->M1_R1_B_LIGHT_ISO_AXI <<  this->database->data_RIOM->M1_R1_B_LIGHT_ISO_ACU
                   << this->database->data_RIOM->M1_R1_B_LIGHT_CPR <<  this->database->data_RIOM->M1_R1_B_LIGHT_BATLOW
                   << this->database->data_RIOM->M1_R1_B_LIHGT_CABCHANGE <<  false
                   << false <<  false
                   << false <<  false
                   << false <<  false
                   << false <<  false;
            updateDio(this->doTable1, states, _COLUMNDO);
            states.clear();

            this->axTable->item(0, 3)->setText(QString::number(this->database->data_RIOM->RIOM1_N_MSCT1));
        }
        else
        {
            logger()->error("page number is over the scope");
        }
    }
    else
        //riom2
    {
        if (1 == this->page)
        {
            states << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false;
            updateDio(this->diTable1, states, _COLUMNDI);
            states.clear();

            states << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false;
            updateDio(this->diTable2, states, _COLUMNDI);
            states.clear();
        }
        else if (2 == this->page)
        {
            states << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false;
            updateDio(this->diTable1, states, _COLUMNDI);
            states.clear();

            states << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false;
            updateDio(this->diTable2, states, _COLUMNDI);
            states.clear();
        }
        else if (3 == this->page)
        {
            states << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false;
            updateDio(this->diTable1, states, _COLUMNDI);
            states.clear();

            states << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false;
            updateDio(this->doTable2, states, _COLUMNDO);
            states.clear();
        }
        else if (4 == this->page)
        {
            states << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false;
            updateDio(this->doTable1, states, _COLUMNDO);
            states.clear();

            states << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false;
            updateDio(this->doTable2, states, _COLUMNDO);
            states.clear();
        }
        else if (5 == this->page)
        {
            states << false << false << false << false << false << false << false << false
                   << false << false << false << false << false << false << false << false;
            updateDio(this->doTable1, states, _COLUMNDO);
            states.clear();
        }
    }
}

void DeviceDataRIOM::cleanContent(QTableWidget *table)
{
    if (NULL == table)
    {
        _LOG <<"table is null in IOSignals::cleanContent;";
        return;
    }

    for (int row = 0; row < table->rowCount(); row ++)
    {
        for (int column = 0; column < table->columnCount(); column ++)
        {
            if (NULL == table->item(row, column))
            {
                _LOG << "tableItem at " << row << ", " << column << " is null";
                return;
            }
            table->item(row, column)->setText("");
        }
    }
}

void DeviceDataRIOM::onRiomButtonClicked(int riom)
{
    if (uRiom1 == riom)
    {
        riomButtons->button(uRiom1)->setStyleSheet(NButtonDOWN);
        riomButtons->button(uRiom2)->setStyleSheet(NButtonUP);
        this->isRiom1 = true;
    }
    else
    {
        riomButtons->button(uRiom2)->setStyleSheet(NButtonDOWN);
        riomButtons->button(uRiom1)->setStyleSheet(NButtonUP);
        this->isRiom1 = false;
    }
    this->page = 1;
    this->setViews(this->page);
}

void DeviceDataRIOM::on_btnNext_clicked()
{
    if (this->isRiom1 && this->page < 2)
    {
        page++;
    }
    else if (!this->isRiom1 && this->page < 5)
    {
        page++;
    }
    this->setViews(this->page);
    return;
}

void DeviceDataRIOM::on_btnPre_clicked()
{
   if (this->page > 1) this->page--;
   this->setViews(this->page);
}
