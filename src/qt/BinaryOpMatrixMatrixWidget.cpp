
#include "BinaryOpMatrixMatrixWidget.h"
#include "Error.h"
#include <QVBoxLayout>
#include <QPushButton>



BinaryOpMatrixMatrixWidget:: BinaryOpMatrixMatrixWidget(const type& t, const QMatrixLibrary* lib, QWidget* parent) : AbstractOperationWidget(lib,parent)
{    
    constructType(t);
    result = Matrix();

    op1.first = "_";
    op2.first = "_";
    op1.second = nullptr;
    op2.second = nullptr;

    description->setText(op1.first + logo + op2.first);

    QVBoxLayout* op1ChoiceLayout = new QVBoxLayout;
    QLabel* op1Title = new QLabel("Choix de la matrice 1 : ");
    op1Title -> setAlignment(Qt::AlignCenter);
    view1 = new MatrixViewWidget(lib, this);
    op1ChoiceLayout->addWidget(op1Title);
    op1ChoiceLayout->addWidget(view1);
    op1ChoiceLayout->setContentsMargins(0,0,20,0);

    QVBoxLayout* op2ChoiceLayout = new QVBoxLayout;
    QLabel* op2Title = new QLabel("Choix de la matrice 2 : ");
    op2Title->setAlignment(Qt::AlignCenter);
    view2 = new MatrixViewWidget(lib, this);
    op2ChoiceLayout->addWidget(op2Title);
    op2ChoiceLayout->addWidget(view2);
    op2ChoiceLayout->setContentsMargins(20,0,0,0);

    QHBoxLayout* formLayout = new QHBoxLayout;
    formLayout->addLayout(op1ChoiceLayout);
    formLayout->addLayout(op2ChoiceLayout);
    formLayout->setAlignment(Qt::AlignCenter);
    formLayout->setContentsMargins(0,0,20,0);

    description->setText(op1.first + logo + op2.first);

    QVBoxLayout* buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(calculer);
    buttonLayout->setAlignment(Qt::AlignCenter| Qt::AlignTop);

    QVBoxLayout* subLayout1 = new QVBoxLayout;
    subLayout1->addWidget(title);
    subLayout1->addLayout(formLayout);

    QVBoxLayout* subLayout2 = new QVBoxLayout;
    subLayout2->addWidget(description);
    subLayout2->addLayout(buttonLayout);

    QHBoxLayout* subLayout3 = new QHBoxLayout;
    subLayout3->addLayout(subLayout1);
    subLayout3->addLayout(subLayout2);

    QWidget* subWidget1 = new QWidget(this);
    subWidget1->setLayout(subLayout3);
    subWidget1->setMaximumHeight(300);
    subWidget1->setMaximumWidth(800);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(10);
    mainLayout->addWidget(subWidget1);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    connect(view1, &MatrixViewWidget::clicked,
            [this] () -> void
            {
                this->computeSelection(0);
            });
    connect(view2, &MatrixViewWidget::clicked,
            [this] () -> void
            {
                this->computeSelection(1);
            });

    view1->refresh(sortFunction);
    view2->refresh(sortFunction);

    setLayout(mainLayout);
}


void BinaryOpMatrixMatrixWidget:: updateViews()
{
    view1->refresh();
    view2->refresh();
    if(op1.second != nullptr) // si op1 is selected, refresh view2 with the good closure.
    {
        view2->refresh(sortViewFunction(op1.second));
    }
}

void BinaryOpMatrixMatrixWidget:: computeOperation()
{
    if(operation == nullptr) return;

    if((op1.second == nullptr) || (op2.second == nullptr))
    {
        Error::showError("Opérande manquante !", "Veuillez bien sélectionner vos 2 matrices", this);
        return;
    }

    result = operation(op1.second, op2.second);
    QVariant genericResult;
    genericResult.setValue(result);

    emit newResult(genericResult);
}


void BinaryOpMatrixMatrixWidget:: computeSelection(const bool view)
{
    if(!view)
    {
        op2.second = nullptr;
        op2.first = "_";

        op1.first = view1->nameOfSelectedMatrix();
        assert(getLib()->exist(op1.first.toStdString()));
        op1.second = getLib()->find_matrix(op1.first.toStdString());
        view2->refresh(sortViewFunction(op1.second));
    }
    else
    {
        op2.first = view2->nameOfSelectedMatrix();
        assert(getLib()->exist(op2.first.toStdString()));
        op2.second = getLib()->find_matrix(op2.first.toStdString());
    }

    description->setText(op1.first + logo + op2.first);
}



void BinaryOpMatrixMatrixWidget:: constructType(const type& t)
{
    switch(t)
    {
        case ADDITION :
        {
            sortViewFunction = [](const Matrix* a) -> std::function<bool(const Matrix* b)>
            {
                return [a](const Matrix* b) -> bool
                {
                    return (a->getNbRows() == b->getNbRows()) && (a->getNbCols() == b->getNbCols());
                };
            };

            operation =[](const Matrix* a, const Matrix* b) -> Matrix
            {
                return *a + *b;
            };

            setTitle("Addition");
            logo =  " + " ;

            break;
        }
        case SOUSTRACTION :
        {
            sortViewFunction = [](const Matrix* a) -> std::function<bool(const Matrix* b)>
            {
                return [a](const Matrix* b) -> bool
                {
                    return (a->getNbRows() == b->getNbRows()) && (a->getNbCols() == b->getNbCols());
                };
            };

            operation =[](const Matrix* a, const Matrix* b) -> Matrix
            {
                return *a - *b;
            };

            setTitle("Soustraction");
            logo = " - ";

            break;
        }
        case MULTIPLICATION :
        {
            sortViewFunction = [](const Matrix* a) -> std::function<bool(const Matrix* b)>
            {
                return [a](const Matrix* b) -> bool
                {
                    return (a->getNbCols() == b->getNbRows());
                };
            };

            operation = [](const Matrix* a, const Matrix* b) -> Matrix
            {
                return *a * *b;
            };

            setTitle("Multiplication");
            logo = " * ";

            break;
        }
        case DIVISION :
        {
            sortViewFunction = [] (const Matrix* a) -> std::function<bool(const Matrix* b)>
            {
                return [a](const Matrix* b) -> bool
                {
                    return (a->getNbCols() == b->getNbRows()) && b->isSQMatrix() && (b->determinant() != 0.0);
                };
            };

            operation = [](const Matrix* a, const Matrix* b) -> Matrix
            {
                return  a->operator/(*b);
            };

            setTitle("Division");
            logo = " / ";
        }
    }
}

