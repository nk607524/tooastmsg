#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

        ui->tableWidget->setMouseTracking(true);
         //statusBar()->showMessage("Hover over a cell to see the value");

    // Create the main label
//    label = new QLabel(this);
//    label->setText("Hover over me!");
//    label->setAlignment(Qt::AlignCenter);
//    label->setCursor(Qt::PointingHandCursor);  // Set cursor shape
//    label->setFixedSize(300, 100);
//    label->move(100, 100);
//    label->show();

//    // Create toast label
    toastLabel = new QLabel(this);
    //toastLabel->setStyleSheet("background-color: black; color: white; padding: 5px; border-radius: 5px;");
//   // toastLabel->hide();

//    // Timer to hide toast
    timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &MainWindow::hideToast);

    // Enable mouse tracking
//    setMouseTracking(true);
//    label->setMouseTracking(true);
}

// Show a floating toast message near the cursor
void MainWindow::showToast(const QString &message, const QPoint &pos) {
//    toastLabel->setText(message);
//    toastLabel->adjustSize();
//    toastLabel->move(pos + QPoint(10, 10)); // Offset slightly from cursor
//    toastLabel->show();

//    timer->start(1000); // Hide toast after 1 second
    qDebug() << "Showing toast at" << pos << "with message:" << message;
       toastLabel->setText(message);
       toastLabel->adjustSize();
       qDebug()<<"bnr1"<<endl;
       toastLabel->move(pos + QPoint(10, 10)); // Offset slightly from cursor
       qDebug()<<"bnr2"<<endl;

       toastLabel->raise();  // Ensure it's above other widgets
       qDebug()<<"bnr3"<<endl;

       toastLabel->activateWindow();
       qDebug()<<"bnr4"<<endl;

       toastLabel->show();
       qDebug()<<"bnr5"<<endl;

       timer->start(2000); // Hide toast after 2 seconds
       qDebug()<<"bnr6"<<endl;

}

// Hide the toast message
void MainWindow::hideToast() {
    
    toastLabel->hide();
    timer->stop();
}

// Capture mouse movement and display toast
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
//    if (label->geometry().contains(event->pos())) {
//        showToast("Mouse Hovered!", event->globalPos());
//    }
//    QMainWindow::mouseMoveEvent(event);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_tableWidget_cellEntered(int row, int column)
{
//    if (QTableWidgetItem *item = ui->tableWidget->item(row, column)) {
//           item->setToolTip(item->text());  // Set tooltip with cell text
//       }

    qDebug()<<"bnr ::"<<ui->tableWidget->item(row, column)->text()<<endl;

//    if (QTableWidgetItem *item = ui->tableWidget->item(row, column)) {
//           showToast(item->text(), QCursor::pos());  // Show floating toast near the cursor
//       }
    if (QTableWidgetItem *item = ui->tableWidget->item(row, column)) {
             // statusBar()->showMessage(item->text());

            showToast(item->text(), QCursor::pos());
           // hideToast();

           }


}
