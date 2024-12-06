#pragma once
#ifndef QUESTIONMANAGEMENT
#define QUESTIONMANAGEMENT
#include <QStackedWidget>
#include <vector>
#include "questiontemplate.h"

#define PrivateInsidePrivate

class QuestionManagement : public QStackedWidget{
    public:
        QuestionManagement(const std::vector<QuestionTemplate::MultipleChoice*>& questionList, size_t displayCount, QWidget* parent = 0);
    private:
        std::vector<QuestionTemplate::MultipleChoice*> questionList;
        std::vector<QuestionWidget::MultipleChoice*> pageList;
        std::vector<QuestionTemplate::MultipleChoice*> GetRandomOrder(std::vector<QuestionTemplate::MultipleChoice*> Questions, size_t Quantity);
        void Finish();
        void UpdatePages();
        std::vector<int> range(int Lim);
        int Corr=0, Incorr=0;
        int CurrentIndex=0;
};

#endif
