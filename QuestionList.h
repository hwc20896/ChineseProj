#ifndef QUESTIONLIST_H
#define QUESTIONLIST_H

#include "questiontemplate.h"

namespace QuestionList{
    /* Format:
     * @First slot: Question Title
     * @Second slot: Options embraced
     * @Third slot: Correct option (0->A, 1->B, 2->C, 3->D)
     */
    QMC* Question1 = new QMC("下列哪個成語和\"道聼塗説\"詞意更接近？",{"空穴來風", "三人成虎"},0);
    QMC* Question2 = new QMC("\"但願人長久，千里共嬋娟\"，其中嬋娟指的是什麼？",{"月亮","姻緣"},0);
    QMC* Question3 = new QMC("\"爆竹聲中一歲除，春風送暖入屠蘇\"，這裡的\"屠蘇\"指的是：",{"蘇州","房屋","酒","莊稼"},2);
    QMC* Question4 = new QMC("\"拱手而立\"表示對長者的尊敬，一般來說，男子行拱手禮時應該：",{"左手在外","右手在外"},0);
    QMC* Question5 = new QMC("我國的京劇臉譜色彩含義豐富，紅色一般表示忠勇俠義，白色一般表示陰險奸詐，那麼黑色一般表示：",{"忠耿正直","剛愎自用"},0);
    QMC* Question6 = new QMC("《三十六計》是體現我國古代卓越軍事思想的一部兵書，下列不屬於《三十六計》的是：",{"忠耿正直","剛愎自用"},0);
    QMC* Question7 = new QMC("\"床前明月光\"是李白的千古名句，其中\"床\"指的是什麼？",{"窗戶","臥具","井上的圍欄"},2);
}

#endif // QUESTIONLIST_H
