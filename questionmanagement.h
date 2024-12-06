#pragma once
#ifndef QUESTIONMANAGEMENT
#define QUESTIONMANAGEMENT
#include <QStackedWidget>
#include <vector>
#include "questiontemplate.h"

#define PrivateInsidePrivate

class QuestionManagement : public QStackedWidget{
    public:
        QuestionManagement(const std::vector<Question::QuestionBase*>& questions, int Quantity, QWidget* parent = 0);
    private Variables:
        std::vector<QQB*> QuestionList;
        std::vector<QTQB*> PageList;
        int Quantity;
        int CurrentIndex=0;
        int Corr=0, Incorr=0;
    private Functions:
        std::vector<int> GetRandomOrder(const std::vector<QQB*>& Questions, size_t Quantity);
        void Finish();
        void UpdatePages();
    private PrivateInsidePrivate Functions:
        inline int GetRandomNumber(int High,int Low=0){return rand()%(High - Low) + Low;}
        std::vector<int> range(int Lim);
};

#endif
