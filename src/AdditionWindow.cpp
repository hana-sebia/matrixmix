
#include <QPushButton>
#include <QDebug>
#include "AdditionWindow.h"
#include "Error.h"

AdditionWindow::AdditionWindow(MatrixLibrary* lib, QWidget* parent) : QDialog (parent)
{
    this->lib = lib;
    op1Name = "_";
    op2Name = "_";
    op1 = nullptr;
    op2 = nullptr;

    resultImg = new ShowMatrixWidget(this);
    resultImg->hide();

    QLabel* title = new QLabel("Addition");
    title->setStyleSheet("font-size: 30px;");
    title->setAlignment(Qt::AlignCenter);

    QVBoxLayout* op1ChoiceLayout = new QVBoxLayout;
    QLabel* op1Title = new QLabel("Choix de la matrice 1 : ");
    op1View = new MatrixViewWidget(lib, this);
    op1ChoiceLayout->addWidget(op1Title);
    op1ChoiceLayout->addWidget(op1View);

    QVBoxLayout* op2ChoiceLayout = new QVBoxLayout;
    QLabel* op2Title = new QLabel("Choix de la matrice 2 : ");
    op2View = new MatrixViewWidget(lib, this);
    op2ChoiceLayout->addWidget(op2Title);
    op2ChoiceLayout->addWidget(op2View);

    QHBoxLayout* formLayout = new QHBoxLayout;
    formLayout->addLayout(op1ChoiceLayout);
    formLayout->addLayout(op2ChoiceLayout);

    formula = new QLabel("_  +  _");
    formula->setStyleSheet("font-size: 40px");
    formula->setAlignment(Qt::AlignCenter);
    formula->setContentsMargins(0,25,0, 25);

    QPushButton* calculer = new QPushButton("Calculer");

    QVBoxLayout* subLayout1 = new QVBoxLayout;
    subLayout1->addWidget(title);
    subLayout1->addLayout(formLayout);
    subLayout1->addWidget(formula);
    QWidget* subWidget1 = new QWidget(this);
    subWidget1->setLayout(subLayout1);
    subWidget1->setFixedHeight(400);

    mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(10);
    mainLayout->addWidget(subWidget1);
    mainLayout->addWidget(resultImg);
    mainLayout->addWidget(calculer);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);


    connect(op1View, &MatrixViewWidget::clicked,
            [this] () -> void
            {
                this->computeSelection(0);
            });
    connect(op2View, &MatrixViewWidget::clicked,
            [this] () -> void
            {
                this->computeSelection(1);
            });
    connect(calculer, &QPushButton::clicked, this, &AdditionWindow::computeOperation);

    setLayout(mainLayout);
}


void AdditionWindow:: computeSelection (bool op)
{
    int selectedRow;
    QString selectedName;
    resultImg->hide();
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    updateGeometry();

    if(!op)
    {
        op2 = nullptr;
        op2Name = "_";

        selectedRow = op1View->currentIndex().row();
        selectedName = op1View->model()->item(selectedRow)->data(2).toString();
        op1Name = selectedName;
        op1 = lib->find(op1Name.toStdString());
        formula->setText(op1Name + " + " + op2Name);
        op2View->update(
               [this](const Matrix* a)
               {
                   return ((op1->getNbCols() == a->getNbCols()) &&
                    (op1->getNbRows() == a->getNbRows()));
               });
    }
    else
    {
        selectedRow = op2View->currentIndex().row();
        selectedName = op2View->model()->item(selectedRow)->data(2).toString();
        op2Name = selectedName;
        op2 = lib->find(selectedName.toStdString());
        formula->setText(op1Name + " + " + op2Name);
    }
}


void AdditionWindow:: computeOperation ()
{
    if((op1 == nullptr) || (op2 == nullptr))
    {
        showError("Opérande Manquante !", "Veuillez bien sélectionner vos 2 Matrices", this);
        return;
    }


    result = *op1 + *op2;
    resultImg->compute_img(&result);
    resultImg->show();
}


AdditionWindow:: ~AdditionWindow ()
{
}
