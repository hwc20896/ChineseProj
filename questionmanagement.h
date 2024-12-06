#pragma once
#ifndef QUESTIONMANAGEMENT
#define QUESTIONMANAGEMENT
#include <QStackedWidget>
#include <vector>
#include "questiontemplate.h"

#define PrivateInsidePrivate

class QuestionManagement : public QStackedWidget{
    public:
        QuestionManagement(const std::vector<QuestionTemplate::MultipleChoice*>& questionList, int displayCount, QWidget* parent = 0);
    private:
        std::vector<QuestionTemplate::MultipleChoice*> questionList;
        std::vector<QuestionWidget::MultipleChoice*> pageList;
};

#endif
