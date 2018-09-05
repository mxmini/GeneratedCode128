#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QLabel>
#include <QPaintEvent>

enum EncodeType
{
    Code128A = 0,
    Code128B = 1,
    Code128C = 2
};

class CustomLabel : public QLabel
{
    Q_OBJECT

public:
    CustomLabel(QWidget *parent = nullptr);
    ~CustomLabel();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

public slots:
    void drawCode128();

public:
    setSeriesNumber(const char *);
    const char *getSeriesNumer() const;

private:
    void initialCode128();
    void generateEncodeValue();
    void variousEncode();

private:
    char *code128[107][5];
    char *seriesNumber;
    char *encodeValue;
    EncodeType type;
};

#endif // CUSTOMLABEL_H
