#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Create the main label
    label = new QLabel(this);
    label->setText("Hover over me!");
    label->setAlignment(Qt::AlignCenter);
    label->setCursor(Qt::PointingHandCursor);  // Set cursor shape
    label->setFixedSize(300, 100);
    label->move(100, 100);
    label->show();

    // Create toast label
    toastLabel = new QLabel(this);
    toastLabel->setStyleSheet("background-color: black; color: white; padding: 5px; border-radius: 5px;");
    toastLabel->hide();

    // Timer to hide toast
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::hideToast);

    // Enable mouse tracking
    setMouseTracking(true);
    label->setMouseTracking(true);
}

// Show a floating toast message near the cursor
void MainWindow::showToast(const QString &message, const QPoint &pos) {
    toastLabel->setText(message);
    toastLabel->adjustSize();
    toastLabel->move(pos + QPoint(10, 10)); // Offset slightly from cursor
    toastLabel->show();

    timer->start(1000); // Hide toast after 1 second
}

// Hide the toast message
void MainWindow::hideToast() {
    toastLabel->hide();
    timer->stop();
}

// Capture mouse movement and display toast
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (label->geometry().contains(event->pos())) {
        showToast("Mouse Hovered!", event->globalPos());
    }
    QMainWindow::mouseMoveEvent(event);
}

MainWindow::~MainWindow() {
    delete ui;
}
