#include "questionmanagement.h"
#include "outrowidget.h"

QuestionManagement::QuestionManagement(const std::vector<QuestionTemplate::MultipleChoice*>& questionList, int displayCount, QWidget* parent) : QStackedWidget(parent), questionList(questionList){}
