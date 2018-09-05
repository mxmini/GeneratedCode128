#include "customlabel.h"
#include <QPainter>
#include <string.h>
#include <QFontMetrics>
#include <QFont>
#include <QtDebug>

CustomLabel::CustomLabel(QWidget *parent) : QLabel(parent)
{
    seriesNumber = new char[100];
    encodeValue = new char[1000];

    memset(seriesNumber, 0, sizeof(seriesNumber));
    memset(encodeValue, 0, sizeof(encodeValue));
     memset(code128, 0, sizeof(code128));

    initialCode128();

}

    CustomLabel::~CustomLabel()
{

    delete[] seriesNumber;
    delete[] encodeValue;
}

void CustomLabel::paintEvent(QPaintEvent *event)
{
    if (strlen(encodeValue) == 0)
        return ;

    QPainter painter(this);

    painter.setPen(Qt::NoPen);

    for (int i = 0; i < strlen(encodeValue); i++)
    {
        if (encodeValue[i] == 'b')       //black
        {
            painter.setBrush(QBrush(QColor(Qt::black)));
            painter.drawRect(i * 2, 0, 2, 60);
        }
        else
        {
            painter.setBrush(QBrush(QColor(Qt::white)));
            painter.drawRect(i * 2, 0, 2, 60);
        }

    }

    QFont font(QStringLiteral("黑体"), 12, 86);
    QFontMetrics fontMetrics(font);

     painter.setPen(Qt::SolidLine);
     painter.setFont(QFont("黑体",12, 86));

    int width = fontMetrics.width(QString(seriesNumber));
    int height = fontMetrics.height();

    int x  = strlen(encodeValue) * 2;

    painter.drawText((x - width)/2, 61,width, height,Qt::AlignLeft, QString(seriesNumber));

    qDebug() << x;
}

void CustomLabel::drawCode128()
{
    this->update();
}

CustomLabel::setSeriesNumber(const char * number)
{
    strcpy(this->seriesNumber, number);
   //generateEncodeValue();
    variousEncode();
    this->update();
}

const char *CustomLabel::getSeriesNumer() const
{
    return this->seriesNumber;
}

void CustomLabel::initialCode128()
{
    code128[0][0] = " ";            //code128A
    code128[0][1] = " ";            //code128B
    code128[0][2] = "00";           //code128C
    code128[0][3] = "212222";       //BandCode
    code128[0][4] = "bbsbbssbbss";      //编码值

    code128[1][0] = "!";
    code128[1][1] = "!";
    code128[1][2] = "01";
    code128[1][3] = "222122";
    code128[1][4] = "bbssbbsbbss";

    code128[2][0] = "\"";
    code128[2][1] = "\"";
    code128[2][2] = "02";
    code128[2][3] = "222221";
    code128[2][4] = "bbssbbssbbs";

    code128[3][0] = "#";
    code128[3][1] = "#";
    code128[3][2] = "03";
    code128[3][3] = "121223";
    code128[3][4] = "bssbssbbsss";

    code128[4][0] = "$";
    code128[4][1] = "$";
    code128[4][2] = "04";
    code128[4][3] = "121322";
    code128[4][4] = "bssbsssbbss";

    code128[5][0] = "%";
    code128[5][1] = "%";
    code128[5][2] = "05";
    code128[5][3] = "131222";
    code128[5][4] = "bsssbssbbss";

    code128[6][0] = "&";
    code128[6][1] = "&";
    code128[6][2] = "06";
    code128[6][3] = "122213";
    code128[6][4] = "bssbbssbsss";

    code128[7][0] = "'";
    code128[7][1] = "'";
    code128[7][2] = "07";
    code128[7][3] = "122312";
    code128[7][4] = "bssbbsssbss";

    code128[8][0] = "(";
    code128[8][1] = "(";
    code128[8][2] = "08";
    code128[8][3] = "132212";
    code128[8][4] = "bsssbbssbss";

    code128[9][0] = ")";
    code128[9][1] = ")";
    code128[9][2] = "09";
    code128[9][3] = "221213";
    code128[9][4] = "bbssbssbsss";

    code128[10][0] = "*";
    code128[10][1] = "*";
    code128[10][2] = "10";
    code128[10][3] = "221312";
    code128[10][4] = "bbssbsssbss";

    code128[11][0] = "+";
    code128[11][1] = "+";
    code128[11][2] = "11";
    code128[11][3] = "231212";
    code128[11][4] = "bbsssbssbss";

    code128[12][0] = ",";
    code128[12][1] = ",";
    code128[12][2] = "12";
    code128[12][3] = "112232";
    code128[12][4] = "bsbbssbbbss";

    code128[13][0] = "-";
    code128[13][1] = "-";
    code128[13][2] = "13";
    code128[13][3] = "122132";
    code128[13][4] = "bssbbsbbbss";

    code128[14][0] = ".";
    code128[14][1] = ".";
    code128[14][2] = "14";
    code128[14][3] = "122231";
    code128[14][4] = "bssbbssbbbs";

    code128[15][0] = "/";
    code128[15][1] = "/";
    code128[15][2] = "15";
    code128[15][3] = "113222";
    code128[15][4] = "bsbbbssbbss";

    code128[16][0] = "0";
    code128[16][1] = "0";
    code128[16][2] = "16";
    code128[16][3] = "123122";
    code128[16][4] = "bssbbbsbbss";

    code128[17][0] = "1";
    code128[17][1] = "1";
    code128[17][2] = "17";
    code128[17][3] = "123221";
    code128[17][4] = "bssbbbssbbs";

    code128[18][0] = "2";
    code128[18][1] = "2";
    code128[18][2] = "18";
    code128[18][3] = "223211";
    code128[18][4] = "bbssbbbssbs";

    code128[19][0] = "3";
    code128[19][1] = "3";
    code128[19][2] = "19";
    code128[19][3] = "221132";
    code128[19][4] = "bbssbsbbbss";

    code128[20][0] = "4";
    code128[20][1] = "4";
    code128[20][2] = "20";
    code128[20][3] = "221231";
    code128[20][4] = "bbssbssbbbs";

    code128[21][0] = "5";
    code128[21][1] = "5";
    code128[21][2] = "21";
    code128[21][3] = "213212";
    code128[21][4] = "bbsbbbssbsss";

    code128[22][0] = "6";
    code128[22][1] = "6";
    code128[22][2] = "22";
    code128[22][3] = "223112";
    code128[22][4] = "bbssbbbsbss";

    code128[23][0] = "7";
    code128[23][1] = "7";
    code128[23][2] = "23";
    code128[23][3] = "312131";
    code128[23][4] = "bbbsbbsbbbs";

    code128[24][0] = "8";
    code128[24][1] = "8";
    code128[24][2] = "24";
    code128[24][3] = "311222";
    code128[24][4] = "bbbsbssbbss";

    code128[25][0] = "9";
    code128[25][1] = "9";
    code128[25][2] = "25";
    code128[25][3] = "321122";
    code128[25][4] = "bbbssbsbbss";


    code128[26][0] = ":";
    code128[26][1] = ":";
    code128[26][2] = "26";
    code128[26][3] = "321221";
    code128[26][4] = "bbbssbssbbs";

    code128[27][0] = ";";
    code128[27][1] = ";";
    code128[27][2] = "27";
    code128[27][3] = "312212";
    code128[27][4] = "bbbsbbssbss";

    code128[28][0] = "<";
    code128[28][1] = "<";
    code128[28][2] = "28";
    code128[28][3] = "322112";
    code128[28][4] = "bbbssbbsbss";

    code128[29][0] = "=";
    code128[29][1] = "=";
    code128[29][2] = "29";
    code128[29][3] = "322211";
    code128[29][4] = "bbbssbbssbs";

    code128[30][0] = ">";
    code128[30][1] = ">";
    code128[30][2] = "30";
    code128[30][3] = "212123";
    code128[30][4] = "bbsbbsbbsss";

    code128[31][0] = "?";
    code128[31][1] = "?";
    code128[31][2] = "31";
    code128[31][3] = "212321";
    code128[31][4] = "bbsbbsssbbs";

    code128[32][0] = "@";
    code128[32][1] = "@";
    code128[32][2] = "32";
    code128[32][3] = "232121";
    code128[32][4] = "bbsssbbsbbs";

    code128[33][0] = "A";
    code128[33][1] = "A";
    code128[33][2] = "33";
    code128[33][3] = "111323";
    code128[33][4] = "bsbsssbbsss";

    code128[34][0] = "B";
    code128[34][1] = "B";
    code128[34][2] = "34";
    code128[34][3] = "131123";
    code128[34][4] = "bsssbsbbsss";

    code128[35][0] = "C";
    code128[35][1] = "C";
    code128[35][2] = "35";
    code128[35][3] = "131321";
    code128[35][4] = "bsssbsssbbs";

    code128[36][0] = "D";
    code128[36][1] = "D";
    code128[36][2] = "36";
    code128[36][3] = "112313";
    code128[36][4] = "bsbbsssbsss";

    code128[37][0] = "E";
    code128[37][1] = "E";
    code128[37][2] = "37";
    code128[37][3] = "132113";
    code128[37][4] = "bsssbbsbsss";

    code128[38][0] = "F";
    code128[38][1] = "F";
    code128[38][2] = "38";
    code128[38][3] = "132311";
    code128[38][4] = "bsssbbsssbs";

    code128[39][0] = "G";
    code128[39][1] = "G";
    code128[39][2] = "39";
    code128[39][3] = "211313";
    code128[39][4] = "bbsbsssbsss";

    code128[40][0] = "H";
    code128[40][1] = "H";
    code128[40][2] = "40";
    code128[40][3] = "231113";
    code128[40][4] = "bbsssbsbsss";

    code128[41][0] = "I";
    code128[41][1] = "I";
    code128[41][2] = "41";
    code128[41][3] = "231311";
    code128[41][4] = "bbsssbsssbs";

    code128[42][0] = "J";
    code128[42][1] = "J";
    code128[42][2] = "42";
    code128[42][3] = "112133";
    code128[42][4] = "bsbbsbbbsss";

    code128[43][0] = "K";
    code128[43][1] = "K";
    code128[43][2] = "43";
    code128[43][3] = "112331";
    code128[43][4] = "bsbbsssbbbs";

    code128[44][0] = "L";
    code128[44][1] = "L";
    code128[44][2] = "44";
    code128[44][3] = "132131";
    code128[44][4] = "bsssbbsbbbs";

    code128[45][0] = "M";
    code128[45][1] = "M";
    code128[45][2] = "45";
    code128[45][3] = "113123";
    code128[45][4] = "bsbbbsbbsss";

    code128[46][0] = "N";
    code128[46][1] = "N";
    code128[46][2] = "46";
    code128[46][3] = "113321";
    code128[46][4] = "bsbbbsssbbs";

    code128[47][0] = "O";
    code128[47][1] = "O";
    code128[47][2] = "47";
    code128[47][3] = "133121";
    code128[47][4] = "bsssbbbsbbs";

    code128[48][0] = "P";
    code128[48][1] = "P";
    code128[48][2] = "48";
    code128[48][3] = "313121";
    code128[48][4] = "bbbsbbbsbbs";

    code128[49][0] = "Q";
    code128[49][1] = "Q";
    code128[49][2] = "49";
    code128[49][3] = "211331";
    code128[49][4] = "bbsbsssbbbs";

    code128[50][0] = "R";
    code128[50][1] = "R";
    code128[50][2] = "50";
    code128[50][3] = "231131";
    code128[50][4] = "bbsssbsbbbs";

    code128[51][0] = "S";
    code128[51][1] = "S";
    code128[51][2] = "51";
    code128[51][3] = "213113";
    code128[51][4] = "bbsbbbsbsss";

    code128[52][0] = "T";
    code128[52][1] = "T";
    code128[52][2] = "52";
    code128[52][3] = "213311";
    code128[52][4] = "bbsbbbsssbs";

    code128[53][0] = "U";
    code128[53][1] = "U";
    code128[53][2] = "53";
    code128[53][3] = "213131";
    code128[53][4] = "bbsbbbsbbbs";

    code128[54][0] = "V";
    code128[54][1] = "V";
    code128[54][2] = "54";
    code128[54][3] = "311123";
    code128[54][4] = "bbbsbsbbsss";

    code128[55][0] = "W";
    code128[55][1] = "W";
    code128[55][2] = "55";
    code128[55][3] = "311321";
    code128[55][4] = "bbbsbsssbbs";

    code128[56][0] = "X";
    code128[56][1] = "X";
    code128[56][2] = "56";
    code128[56][3] = "331121";
    code128[56][4] = "bbbsssbsbbs";

    code128[57][0] = "Y";
    code128[57][1] = "Y";
    code128[57][2] = "57";
    code128[57][3] = "312113";
    code128[57][4] = "bbbsbbsbsss";

    code128[58][0] = "Z";
    code128[58][1] = "Z";
    code128[58][2] = "58";
    code128[58][3] = "312311";
    code128[58][4] = "bbbsbbsssbs";

    code128[59][0] = "[";
    code128[59][1] = "[";
    code128[59][2] = "59";
    code128[59][3] = "332111";
    code128[59][4] = "bbbsssbbsbs";

    code128[60][0] = "\\";
    code128[60][1] = "\\";
    code128[60][2] = "60";
    code128[60][3] = "314111";
    code128[60][4] = "bbbsbbbbsbs";

    code128[61][0] = "]";
    code128[61][1] = "]";
    code128[61][2] = "61";
    code128[61][3] = "221411";
    code128[61][4] = "bbssbssssbs";

    code128[62][0] = "^";
    code128[62][1] = "^";
    code128[62][2] = "62";
    code128[62][3] = "431111";
    code128[62][4] = "bbbbsssbsbs";

    code128[63][0] = "_";
    code128[63][1] = "_";
    code128[63][2] = "63";
    code128[63][3] = "111224";
    code128[63][4] = "bsbssbbssss";

    code128[64][0] = "NUL";
    code128[64][1] = "`";
    code128[64][2] = "64";
    code128[64][3] = "111422";
    code128[64][4] = "bsbssssbbss";

    code128[65][0] = "SOH";
    code128[65][1] = "a";
    code128[65][2] = "65";
    code128[65][3] = "121124";
    code128[65][4] = "bssbsbbssss";

    code128[66][0] = "STX";
    code128[66][1] = "b";
    code128[66][2] = "66";
    code128[66][3] = "121421";
    code128[66][4] = "bssbssssbbs";

    code128[67][0] = "ETX";
    code128[67][1] = "c";
    code128[67][2] = "67";
    code128[67][3] = "141122";
    code128[67][4] = "bssssbsbbss";

    code128[68][0] = "EOT";
    code128[68][1] = "d";
    code128[68][2] = "68";
    code128[68][3] = "141221";
    code128[68][4] = "bssssbssbbs";

    code128[69][0] = "ENQ";
    code128[69][1] = "e";
    code128[69][2] = "69";
    code128[69][3] = "112214";
    code128[69][4] = "bsbbssbssss";

    code128[70][0] = "ACK";
    code128[70][1] = "f";
    code128[70][2] = "70";
    code128[70][3] = "112412";
    code128[70][4] = "bsbbssssbss";

    code128[71][0] = "BEL";
    code128[71][1] = "g";
    code128[71][2] = "71";
    code128[71][3] = "122114";
    code128[71][4] = "bssbbsbssss";

    code128[72][0] = "BS";
    code128[72][1] = "h";
    code128[72][2] = "72";
    code128[72][3] = "122411";
    code128[72][4] = "bssbbssssbs";

    code128[73][0] = "HT";
    code128[73][1] = "i";
    code128[73][2] = "73";
    code128[73][3] = "142112";
    code128[73][4] = "bssssbbsbss";

    code128[74][0] = "LF";
    code128[74][1] = "j";
    code128[74][2] = "74";
    code128[74][3] = "142211";
    code128[74][4] = "bssssbbssbs";

    code128[75][0] = "VT";
    code128[75][1] = "k";
    code128[75][2] = "75";
    code128[75][3] = "241211";
    code128[75][4] = "bbssssbssbs";

    code128[76][0] = "FF";
    code128[76][1] = "I";
    code128[76][2] = "76";
    code128[76][3] = "221114";
    code128[76][4] = "bbssbsbssss";

    code128[77][0] = "CR";
    code128[77][1] = "m";
    code128[77][2] = "77";
    code128[77][3] = "413111";
    code128[77][4] = "bbbbsbbbsbs";

    code128[78][0] = "SO";
    code128[78][1] = "n";
    code128[78][2] = "78";
    code128[78][3] = "241112";
    code128[78][4] = "bbssssbsbss";


    code128[79][0] = "SI";
    code128[79][1] = "o";
    code128[79][2] = "79";
    code128[79][3] = "134111";
    code128[79][4] = "bsssbbbbsbs";

    code128[80][0] = "DLE";
    code128[80][1] = "p";
    code128[80][2] = "80";
    code128[80][3] = "111242";
    code128[80][4] = "bsbssbbbbss";

    code128[81][0] = "DC1";
    code128[81][1] = "q";
    code128[81][2] = "81";
    code128[81][3] = "121142";
    code128[81][4] = "bssbsbbbbss";

    code128[82][0] = "DC2";
    code128[82][1] = "r";
    code128[82][2] = "82";
    code128[82][3] = "121241";
    code128[82][4] = "bssbssbbbbs";

    code128[83][0] = "DC3";
    code128[83][1] = "s";
    code128[83][2] = "83";
    code128[83][3] = "114212";
    code128[83][4] = "bsbbbbssbss";

    code128[84][0] = "DC4";
    code128[84][1] = "t";
    code128[84][2] = "84";
    code128[84][3] = "124112";
    code128[84][4] = "bssbbbbsbss";

    code128[85][0] = "NAK";
    code128[85][1] = "u";
    code128[85][2] = "85";
    code128[85][3] = "124211";
    code128[85][4] = "bssbbbbssbs";

    code128[86][0] = "SYN";
    code128[86][1] = "v";
    code128[86][2] = "86";
    code128[86][3] = "411212";
    code128[86][4] = "bbbbsbssbss";

    code128[87][0] = "ETB";
    code128[87][1] = "w";
    code128[87][2] = "87";
    code128[87][3] = "421112";
    code128[87][4] = "bbbbssbsbss";

    code128[88][0] = "CAN";
    code128[88][1] = "x";
    code128[88][2] = "88";
    code128[88][3] = "421211";
    code128[88][4] = "bbbbssbssbs";

    code128[89][0] = "EM";
    code128[89][1] = "y";
    code128[89][2] = "89";
    code128[89][3] = "212141";
    code128[89][4] = "bbsbbsbbbbs";

    code128[90][0] = "SUB";
    code128[90][1] = "z";
    code128[90][2] = "90";
    code128[90][3] = "214121";
    code128[90][4] = "bbsbbbbsbbs";

    code128[91][0] = "ESC";
    code128[91][1] = "{";
    code128[91][2] = "91";
    code128[91][3] = "412121";
    code128[91][4] = "bbbbsbbsbbs";

    code128[92][0] = "FS";
    code128[92][1] = "|";
    code128[92][2] = "92";
    code128[92][3] = "111143";
    code128[92][4] = "bsbsbbbbsss";

    code128[93][0] = "GS";
    code128[93][1] = "}";
    code128[93][2] = "93";
    code128[93][3] = "111341";
    code128[93][4] = "bsbsssbbbbs";

    code128[94][0] = "RS";
    code128[94][1] = "~";
    code128[94][2] = "94";
    code128[94][3] = "131141";
    code128[94][4] = "bsssbsbbbbs";

    code128[95][0] = "US";
    code128[95][1] = "DEL";
    code128[95][2] = "95";
    code128[95][3] = "114113";
    code128[95][4] = "bsbbbbsbsss";


    code128[96][0] = "FNC3";
    code128[96][1] = "FNC3";
    code128[96][2] = "96";
    code128[96][3] = "114311";
    code128[96][4] = "bsbbbbsssbs";

    code128[97][0] = "FNC2";
    code128[97][1] = "FNC2";
    code128[97][2] = "97";
    code128[97][3] = "411113";
    code128[97][4] = "bbbbsbsbsss";

    code128[98][0] = "SHIFT";
    code128[98][1] = "SHIFT";
    code128[98][2] = "98";
    code128[98][3] = "411311";
    code128[98][4] = "bbbbsbsssbs";

    code128[99][0] = "CODEC";
    code128[99][1] = "CODEC";
    code128[99][2] = "99";
    code128[99][3] = "113141";
    code128[99][4] = "bsbbbsbbbbs";

    code128[100][0] = "CODEB";
    code128[100][1] = "FNC4";
    code128[100][2] = "CODEB";
    code128[100][3] = "114131";
    code128[100][4] = "bsbbbbsbbbs";


    code128[101][0] = "FNC4";
    code128[101][1] = "CODEA";
    code128[101][2] = "CODEA";
    code128[101][3] = "311141";
    code128[101][4] = "bbbsbsbbbbs";

    code128[102][0] = "FNC1";
    code128[102][1] = "FNC1";
    code128[102][2] = "FNC1";
    code128[102][3] = "411131";
    code128[102][4] = "bbbbsbsbbbs";

    code128[103][0] = "StartA";
    code128[103][1] = "StartA";
    code128[103][2] = "StartA";
    code128[103][3] = "211412";
    code128[103][4] = "bbsbssssbss";

    code128[104][0] = "StartB";
    code128[104][1] = "StartB";
    code128[104][2] = "StartB";
    code128[104][3] = "211214";
    code128[104][4] = "bbsbssbssss";

    code128[105][0] = "StartC";
    code128[105][1] = "StartC";
    code128[105][2] = "StartC";
    code128[105][3] = "211232";
    code128[105][4] = "bbsbssbbbss";

    code128[106][0] = "Stop";
    code128[106][1] = "Stop";
    code128[106][2] = "Stop";
    code128[106][3] = "2331112";
    code128[106][4] = "bbsssbbbsbsbb";

}

void CustomLabel::generateEncodeValue()
{
    std::vector<int> check;

    memset(encodeValue, 0, sizeof(encodeValue));

    sprintf(encodeValue, "%s", code128[105][4]);

    if (strlen(seriesNumber) == 0)
        return ;

    if (strlen(seriesNumber) % 2 == 0)      //code128C
    {
        doubleEncode:
        int len = strlen(seriesNumber);
        for (int i = 0; i < len; i += 2)
        {
            char tmp[3] = {0};

            tmp[0] = seriesNumber[i];
            tmp[1] = seriesNumber[i + 1];
            for (int j = 0; j <107; j++ )
            {
                if (strcmp(tmp,code128[j][2]) == 0)
                {
                    check.push_back(j);
                    strcat(encodeValue, code128[j][4]);
                    break;
                }
            }

        }
        if (strlen(seriesNumber) % 2 != 0)
            goto singleEncode;
        int checkNum = 105;
        for(int i = 0; i < check.size(); i++)
        {
            checkNum += (i+1) *check.at(i);
        }

        checkNum %= 103;

        strcat(encodeValue,code128[checkNum][4]);
        strcat(encodeValue, code128[106][4]);

        return ;
    }

    goto doubleEncode;

    singleEncode:
    strcat(encodeValue,code128[101][4]);
    check.push_back(101);
    char tmp[2] = {0};

    sprintf(tmp,"%c", seriesNumber[strlen(seriesNumber) -1]);

    for (int i = 0; i < 107; i++)
    {

        if (strcmp(code128[i][0],tmp) == 0)
         {
            check.push_back(i);
            strcat(encodeValue, code128[i][4]);
            break;
        }
    }
    int checkNum = 105;
    for(int i = 0; i < check.size(); i++)
    {
        checkNum += (i+1) *check.at(i);
    }

    checkNum %= 103;

    strcat(encodeValue,code128[checkNum][4]);
    strcat(encodeValue, code128[106][4]);


}

void CustomLabel::variousEncode()
{

    memset(encodeValue, 0, sizeof(encodeValue));

    bool codeA = false;
    bool codeB = false;
    bool codeC = false;
    std::vector<int> check;
    int checkNum = 0;
    int i = 0;

   while (i < strlen(seriesNumber))
   {
        if(seriesNumber[i] >= '0' && seriesNumber[i] <= '9')
        {

            if ((i + 1) == strlen(seriesNumber))            //单个的设置为CodeA编码方式
            {
                if(codeB)       //codeB to codeA
                {
                    strcat(encodeValue, code128[101][4]);
                    check.push_back(101);
                }
                else if (codeC)         //codeC to codeA
                {
                    strcat(encodeValue, code128[101][4]);
                    check.push_back(101);
                }
                char tmp[2] = {0};

                tmp[0] = seriesNumber[i];

                for (int j = 0; j < 107; j++)
                {
                    if (strcmp(tmp,code128[j][0]) == 0)
                    {
                        strcat(encodeValue, code128[j][4]);
                        check.push_back(j);
                        break;
                    }
                }
                break;
            }

            if (seriesNumber[i+1] >= '0' && seriesNumber[i+1] <= '9')
            {
                if (i == 0)
                {
                    strcat(encodeValue, code128[105][4]);           //startC
                    checkNum = 105;
                }
                else
                {
                    if (codeA)          //codeA to codeC
                    {
                        strcat(encodeValue, code128[99][4]);            //codeC
                        check.push_back(99);
                    }
                    else if (codeB)     //codeB to codeC
                    {
                          strcat(encodeValue, code128[99][4]);            //codeC
                           check.push_back(99);
                    }

                }
                char tmp[3] = {0};

                tmp[0] = seriesNumber[i];
                tmp[1] = seriesNumber[i+1];

                for (int j = 0; j < 107; j++)
                {
                    if (strcmp(tmp,code128[j][2]) == 0)
                    {
                        strcat(encodeValue, code128[j][4]);
                        check.push_back(j);
                        break;
                    }
                }

                codeC = true;           //标识当前采用的codeC编码
                codeA = false;
                codeB = false;

                i += 2;
            }
            else if (seriesNumber[i+1] >= 'a' && seriesNumber[i+1] <= 'z')
            {
                if (i == 0)
                {
                    sprintf(encodeValue, "%s", code128[104][4]);            //startB
                    checkNum = 104;

                    char tmp[2] = {0};

                    tmp[0] = seriesNumber[i];

                    for (int j = 0; j < 107; j++)
                    {
                        if (strcmp(tmp, code128[j][1]) == 0)
                        {
                            strcat(encodeValue, code128[j][4]);
                            check.push_back(j);
                            break;
                        }
                    }
                }
               else
                {
                    //单个数字设置为codeA
                    if (codeB)      //codeB to codeA
                    {
                        strcat(encodeValue, code128[101][4]);
                        check.push_back(101);
                    }
                    else if (codeC) //codeC to codeA
                    {
                        strcat(encodeValue, code128[101][4]);
                        check.push_back(101);
                    }
                    char tmp[2] = {0};

                    tmp[0] = seriesNumber[i];

                    for (int j = 0; j < 107; j++)
                    {
                        if (strcmp(tmp, code128[j][0]) == 0)
                        {
                            strcat(encodeValue, code128[j][4]);
                            check.push_back(j);
                            break;
                        }
                    }

                    strcat(encodeValue,code128[100][4]); //codeB
                    check.push_back(100);
                }



                char str[2] = {0};

                sprintf(str, "%c", seriesNumber[i+1]);
                for (int j = 0; j < 107; j++)
                    if (strcmp(str, code128[j][1]) == 0)
                    {
                        strcat(encodeValue, code128[j][4]);
                        check.push_back(j);
                        break;
                    }

                codeB = true;       //标识当前采用的codeB编码
                codeA = false;
                codeC = false;

                 i += 2;
            }
            else //if (seriesNumber[i+1] >= 'A' && seriesNumber[i+1] <= 'Z')
            {
                if (i == 0)
                {
                    sprintf(encodeValue, "%s", code128[103][4]);            //startA
                    checkNum = 103;

                    char tmp[2] = {0};

                    tmp[0] = seriesNumber[i];

                    for (int j = 0; j < 107; j++)
                    {
                        if (strcmp(tmp, code128[j][0]) == 0)
                        {
                            strcat(encodeValue, code128[j][4]);
                            check.push_back(j);
                            break;
                        }
                    }
                }
                else
                {
                    if (codeB)   //codeB to codeA
                    {
                        strcat(encodeValue, code128[101][4]);
                        check.push_back(101);
                    }
                    else if (codeC)      //codeC to codeA
                    {
                        strcat(encodeValue, code128[101][4]);
                        check.push_back(101);
                    }

                    char tmp[2] = {0};

                    tmp[0] = seriesNumber[i];

                    for (int j = 0; j < 107; j++)
                    {
                        if (strcmp(tmp, code128[j][0]) == 0)
                        {
                            strcat(encodeValue, code128[j][4]);
                            check.push_back(j);
                            break;
                        }
                    }
                //    strcat(encodeValue,code128[101][4]);            //codeA
                //    check.push_back(101);
                }

                char str[2] = {0};

                sprintf(str, "%c", seriesNumber[i+1]);
                for (int j = 0; j < 107; j++)
                    if (strcmp(str, code128[j][0]) == 0)
                    {
                        strcat(encodeValue, code128[j][4]);
                        check.push_back(j);
                        break;
                    }

                codeA = true;           //标识当前采用的codeA编码
                codeB = false;
                codeC = false;

                 i += 2;
            }
        }
        else if (seriesNumber[i] >= 'a' && seriesNumber[i] <= 'z')
        {
            if (i == 0)
            {
                sprintf(encodeValue, "%s", code128[104][4]);            //startB
                checkNum = 104;
            }
           else
            {
                if (codeA)      //由codeA编码变成codeB
                {
                    strcat(encodeValue, code128[100][4]);       //codeA to codeB
                    check.push_back(100);
                }
                else if (codeC)
                {
                    strcat(encodeValue, code128[100][4]);       //codeC to codeB
                    check.push_back(100);
                }
            }
            char tmp[2] = {0};

            tmp[0] = seriesNumber[i];
            for (int j = 0; j < 107; j++)
                if (strcmp(tmp, code128[j][1]) == 0)
                {
                    strcat(encodeValue, code128[j][4]);
                    check.push_back(j);
                    break;
                }

            codeB = true;
            codeA = false;
            codeC = false;

            i++;
        }
        else //if (seriesNumber[i] >= 'A' && seriesNumber[i] <= 'Z' )
        {
            if (i == 0)
            {
                sprintf(encodeValue, "%s", code128[103][4]);            //startA
                checkNum = 103;
            }
           else
            {
                if (codeB)          //codeB to codeA
                {
                    strcat(encodeValue, code128[101][4]);
                    check.push_back(101);
                }
                else if (codeC)         //codeC to codeA
                {
                    strcat(encodeValue, code128[101][4]);
                    check.push_back(101);
                }
            }

            char tmp[2] = {0};

            tmp[0] = seriesNumber[i];
            for (int j = 0; j < 107; j++)
                if (strcmp(tmp, code128[j][0]) == 0)
                {
                    strcat(encodeValue, code128[j][4]);
                    check.push_back(j);
                    break;
                }

            codeA  = true;
            codeB = false;
            codeC = false;

            i++;
        }
   }

   for (int i = 0; i < check.size(); i++)
   {
        checkNum += (i+1) * check.at(i);
   }

   checkNum %= 103;

   strcat(encodeValue, code128[checkNum][4]);
   strcat(encodeValue, code128[106][4]);

}
