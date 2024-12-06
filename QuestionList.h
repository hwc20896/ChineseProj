#ifndef QUESTIONLIST_H
#define QUESTIONLIST_H

#include "questiontemplate.h"

namespace QuestionList{
    /* Format:
     * @First slot: Question Title
     * @Second slot: Options embraced
     * @Third slot: Correct option (0->A, 1->B, 2->C, 3->D)
     */
    using QTMC = QuestionTemplate::MultipleChoice;
    QTMC* Question1 = new QTMC("下列哪個成語和\"道聼塗説\"\n詞意更接近？",{"空穴來風", "三人成虎"},Option::A);
    QTMC* Question2 = new QTMC("\"但願人長久，千里共嬋娟\"，\n其中嬋娟指的是什麼？",{"月亮","姻緣"},Option::A);
    QTMC* Question3 = new QTMC("\"爆竹聲中一歲除，春風送暖入屠蘇\"，\n這裡的\"屠蘇\"指的是：",{"蘇州","房屋","酒","莊稼"},Option::C);
    QTMC* Question4 = new QTMC("\"拱手而立\"表示對長者的尊敬，\n一般來說，男子行拱手禮時應該：",{"左手在外","右手在外"},Option::A);
    QTMC* Question5 = new QTMC("我國的京劇臉譜色彩含義豐富，紅色一般表示\n忠勇俠義，白色一般表示陰險奸詐，\n那麼黑色一般表示：",{"忠耿正直","剛愎自用"},Option::A);
    QTMC* Question6 = new QTMC("《三十六計》是體現我國古代卓越軍事思想\n的一部兵書，下列不屬於《三十六計》的是：",{"忠耿正直","剛愎自用"},Option::A);
    QTMC* Question7 = new QTMC("\"床前明月光\"是李白的千古名句，\n其中\"床\"指的是什麼？",{"窗戶","臥具","井上的圍欄"},Option::C);
}

#endif // QUESTIONLIST_H
