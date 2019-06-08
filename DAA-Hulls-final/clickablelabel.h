//!  Custom QLabel Class.
/*!
  Custom QLabel for Overriding the mousePressEvent to get coordinates of mouse click.
*/
#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();

    int x,y;
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // CLICKABLELABEL_H
