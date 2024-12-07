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
    QTMC* Question01 = new QTMC("下列哪個成語和\"道聼塗説\"\n詞意更接近？",{"空穴來風", "三人成虎"},Option::A);
    QTMC* Question02 = new QTMC("\"但願人長久，千里共嬋娟\"，\n其中嬋娟指的是什麼？",{"月亮","姻緣"},Option::A);
    QTMC* Question03 = new QTMC("\"爆竹聲中一歲除，春風送暖入屠蘇\"，\n這裡的\"屠蘇\"指的是：",{"蘇州","房屋","酒","莊稼"},Option::C);
    QTMC* Question04 = new QTMC("\"拱手而立\"表示對長者的尊敬，\n一般來說，男子行拱手禮時應該：",{"左手在外","右手在外"},Option::A);
    QTMC* Question05 = new QTMC("我國的京劇臉譜色彩含義豐富，紅色一般表示\n忠勇俠義，白色一般表示陰險奸詐，\n那麼黑色一般表示：",{"忠耿正直","剛愎自用"},Option::A);
    QTMC* Question06 = new QTMC("《三十六計》是體現我國古代卓越軍事思想\n的一部兵書，下列不屬於《三十六計》的是：",{"忠耿正直","剛愎自用"},Option::A);
    QTMC* Question07 = new QTMC("\"床前明月光\"是李白的千古名句，\n其中\"床\"指的是什麼？",{"窗戶","臥具","井上的圍欄"},Option::C);
    QTMC* Question08 = new QTMC("1932 年，清華大學招生試題中有一道對對子題\n，上聯\"孫行者\"，下面下聯中最合適的是：",{"祖沖之","周作人","郁達夫","郁達夫"},Option::A);
    QTMC* Question09 = new QTMC("\"月上柳梢頭，人約黃昏後\"描寫的是哪個傳統節日？",{"中秋節","元宵節","端午節","七夕節"},Option::B);
    QTMC* Question10 = new QTMC("我國古代有很多計量單位，比如詩句\"黃河遠上白雲間，一片孤城萬仞山\"中的\"仞\"，一仞約相當於：",{"一個成年人的高度","成年人一臂的長度"},Option::B);
    QTMC* Question11 = new QTMC("下列哪一句詩描寫的場景最適合採用水墨畫來表現？",{"落霞與孤鶩齊飛，\n秋水共長天一色","返景入深林，\n複照青苔上","孤舟蓑笠翁，\n獨釣寒江雪","接天蓮葉無窮碧，\n映日荷花別樣紅"},Option::C);
    QTMC* Question12 = new QTMC("下列哪個成語典故與項羽有關？",{"隔岸觀火","暗度陳倉","背水一戰","破釜沉舟"},Option::D);
    QTMC* Question13 = new QTMC("《百家姓》中沒有下面哪個姓？",{"烏","巫","肖","蕭"},Option::C);
    QTMC* Question14 = new QTMC("\"生旦淨末丑\"是京劇的行當，其中\"淨\"是：",{"男角,女角"},Option::A);
    QTMC* Question15 = new QTMC("我們常說的\"十八般武藝\"最初指的是什麼？",{"使用十八種兵器的技能","十八種武術動作"},Option::A);
    QTMC* Question16 = new QTMC("假如你的一首五絕詩被雜誌社採用，按照正文部分每字5元來計算，你應得多少稿費？",{"50元","100元","200元"},Option::B);
    QTMC* Question17 = new QTMC("下面哪個字常用作表示順序的第五位元？",{"戊","戍","戌"},Option::A);
    QTMC* Question18 = new QTMC("諸子百家中名家的特點是注重邏輯辯證，以下哪個典故能體現名家的這一特點？",{"白馬非馬","指鹿為馬"},Option::A);
    QTMC* Question19 = new QTMC("古人的婚禮在什麼時間舉行？",{"早上","中午","傍晚"},Option::C);
    QTMC* Question20 = new QTMC("\"近朱者赤，近墨者黑\"所蘊含的道理\n和下列哪句話最相似？",{"青出於藍，而勝於藍","蓬生麻中，不扶而直","公生明，偏生暗"},Option::B);
    QTMC* Question21 = new QTMC("\"天時不如地利，地利不如人和\"出自：",{"《孟子》","《莊子》"},Option::A);
    QTMC* Question22 = new QTMC("我國書法藝術博大精深，請問\n\"歐體\"是指誰的字體？",{"歐陽修","歐陽詢"},Option::B);
    QTMC* Question23 = new QTMC("文學史上被稱作\"小李杜\"的是杜牧和誰？",{"李賀,李商隱"},Option::B);
    QTMC* Question24 = new QTMC("\"大禹治水\"的故事家喻戶曉，\n大禹治理的是哪個流域的洪水？",{"長江流域","黃河流域"},Option::B);
    QTMC* Question25 = new QTMC("古代宮殿大門前成對的石獅一般都是：",{"左雄右雌","左雌右雄"},Option::A);
    QTMC* Question26 = new QTMC("\"結髮\"在古時是指結婚時：",{"丈夫把頭髮束起來","妻子把頭髮束起來","把夫妻頭髮束在一起"},Option::C);
    QTMC* Question27 = new QTMC("\"鄂爾多斯\"在蒙古語中是什麼意思？",{"大草原","盛產羊毛的地方","眾多宮殿","美麗的地方"},Option::C);
    QTMC* Question28 = new QTMC("《西遊記》中唐僧的原型是：",{"玄奘","鑒真"},Option::A);
    QTMC* Question29 = new QTMC("唐代詩人賈島\"二句三年得，一吟雙淚流\"的詩句是：",{"獨行潭底影，數息樹邊身。","鳥宿池邊樹，僧敲月下門。"},Option::A);
    QTMC* Question30 = new QTMC("我國傳統表示次序的\"天干\"共有幾個字？",{"十個","十二個"},Option::A);
    QTMC* Question31 = new QTMC("被譽為\"萬園之園\"的是：",{"頤和園","圓明園"},Option::B);
    QTMC* Question32 = new QTMC("\"水\"字屬於下列哪種漢字構成方式？",{"象形字","表意字"},Option::A);
    QTMC* Question33 = new QTMC("現在我們常用\"陽春白雪\"和\"下里巴人\"指代高雅和通俗的文藝作品，請問這兩個成語最初指的是什麼？",{"文章","畫作","樂曲"},Option::C);
    QTMC* Question34 = new QTMC("京劇《貴妃醉酒》是根據哪部古代戲曲改編而成的？",{"《桃花扇》","《長生殿》","《牡丹亭》","《南柯記》"},Option::B);
    QTMC* Question35 = new QTMC("道家思想在我國影響深遠，請問歷史中的哪一時期最接近道家所主張的無為而治？",{"文景之治","光武中興","貞觀之治","開無盛世"},Option::A);
    QTMC* Question36 = new QTMC("下面哪句話出自《孟子》？",{"\"水能載舟，亦能覆舟\"","\"先天下之憂而憂，後天下之樂而樂\"","\"民惟邦本，本固邦寧\"","\"獨樂樂，與人樂樂，孰樂？\""},Option::D);
    QTMC* Question37 = new QTMC("下列哪個不是北京的別稱？",{"大都","中都","上都","南京"},Option::C);
    QTMC* Question38 = new QTMC("\"諱疾忌醫\"典故中的君王是：",{"齊桓公","蔡桓公"},Option::B);
    QTMC* Question39 = new QTMC("\"桃花潭水深千尺，不及汪倫送我情\"詩中的\"我\"指的是誰？",{"杜甫","李白"},Option::B);
    QTMC* Question40 = new QTMC("我們熟悉的《百家姓》是按照什麼方式排列的？",{"人口數量","政治地位"},Option::B);
}

#endif // QUESTIONLIST_H
