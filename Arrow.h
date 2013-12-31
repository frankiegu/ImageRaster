#pragma once
#include "qgraphicsitem.h"

class Marker :
	public mData,
	public Container,
	public Format
{
public:
	Marker(Container* branch=0):
		Container(branch), mData(), Format() { }
	~Marker() { }
};

class Arrow :
	public QGraphicsLineItem
{
	std::vector<QLineF> lines;
	std::vector<QLineF> compose();

public:
	Arrow(const QLineF& l, QGraphicsItem *parent=0, int arrowhead=(int)Both);
	~Arrow(void);

	enum { Type = UserType + 1 };
	int type() const { return Type; }

	enum ArrowHead {
		Start, End, Both
	} arrowHead;

	virtual QRectF boundingRect() const;

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
		QWidget *widget = 0);

	virtual QPainterPath shape() const;
};

class ArrowMarker :
	public Arrow,
	public Marker
{
	Arrow *bgA;
	QGraphicsSimpleTextItem *myText;
	QLineF load_oneClickLine(const QLineF& l);
protected:
	virtual QPointF textBaseline() const;
public:
	ArrowMarker(const QLineF& l, Container *branch=0);
	~ArrowMarker() { }

	enum { Type = UserType + 2 };
	int type() const { return Type; }

	QRectF boundingRect() const;

	QPainterPath shape() const;

	void setLabel(const QString& txt) override {
		myLabel = txt;
		myText->setText(txt);
	}
	void setFont(const QFont& f) override {
		myFont = f;
		myText->setFont(f);
	}

	void setPen1(const QPen& p);
	void setPen2(const QPen& p);

};

class RectMarker :
	public ArrowMarker
{
	QGraphicsRectItem* bg;
	QGraphicsRectItem* fg;
	QLineF calculateMarkerLine(const QRectF&);
	QRectF testOneClick(const QRectF&) const;
public:
	RectMarker(const QRectF& r,	Container *branch=0, QGraphicsItem *parent=0);
	~RectMarker() { }

	enum { Type = UserType + 3 };
	int type() const { return Type; }

	QRectF boundingRect() const;

	QPainterPath shape() const;

	void setPen1(const QPen& p);
	void setPen2(const QPen& p);
};

class CircleMarker :
	public ArrowMarker
{
	QGraphicsEllipseItem* bg;
	QGraphicsEllipseItem* fg;
	QLineF calculateMarkerLine(const QRectF&);
	QRectF testOneClick(const QRectF&) const;
public:
	CircleMarker(const QRectF& r,	Container *branch=0, QGraphicsItem *parent=0);
	~CircleMarker() { }

	enum { Type = UserType + 4 };
	int type() const { return Type; }

	QRectF boundingRect() const;

	QPainterPath shape() const;

	void setPen1(const QPen& p);
	void setPen2(const QPen& p);
};

//Rulers:
class Ruler :
	public rData,
	public Format,
	public Container
{
public:
	Ruler(Container* branch=0):
		Container(branch), rData(), Format() { }
	~Ruler() { }
};

class LineRuler:
	public Ruler,
	public Arrow
{
	bool showArrow;
protected:
	Arrow* bg;
	QGraphicsSimpleTextItem* myText;
	virtual QPointF calculateTextPos() const;
public:
	LineRuler(const QLineF& l, Container* parent=0);
	~LineRuler();

	enum { Type = UserType + 5 };
	int type() const { return Type; }

	QRectF boundingRect() const;

	QPainterPath shape() const;

	QString text() const { return myText->text(); }
	void setText(const QString& txt);
	virtual QString defaultText() const;

	void setPen1(const QPen& p);
	void setPen2(const QPen& p);

	void setFont(const QFont& f);
};

class RectRuler:
	public LineRuler
{
	QGraphicsRectItem *myRect, *bgR;
protected:
	QPointF calculateTextPos() const override;
public:
	RectRuler(const QRectF& r, Container* parent=0);
	
	enum { Type = UserType + 6 };
	int type() const { return Type; }

	QRectF boundingRect() const;

	QPainterPath shape() const;

	QString defaultText() const override;

	void setPen1(const QPen& p);
	void setPen2(const QPen& p);

	QRectF rect() const { return myRect->rect(); }
};

class CircleRuler:
	public LineRuler
{
	QGraphicsEllipseItem *myRect, *bgR;
protected:
	QPointF calculateTextPos() const override;
public:
	CircleRuler(const QRectF& r, Container* parent=0);
	
	enum { Type = UserType + 7 };
	int type() const { return Type; }

	QRectF boundingRect() const;

	QPainterPath shape() const;

	QString defaultText() const override;

	void setPen1(const QPen& p);
	void setPen2(const QPen& p);

	QRectF rect() const { return myRect->rect(); }
};

class Circle2Ruler:
	public LineRuler
{
	QGraphicsEllipseItem *myRect1, *bgR1;
	QGraphicsEllipseItem *myRect2, *bgR2;
	QLineF lineFrom2Rect(const QRectF& r1, const QRectF& r2);
public:
	Circle2Ruler(const QRectF& r1, const QRectF& r2, Container* parent=0);
	
	enum { Type = UserType + 8 };
	int type() const { return Type; }

	QRectF boundingRect() const;

	QPainterPath shape() const;

	void setPen1(const QPen& p);
	void setPen2(const QPen& p);
};

class PolyRuler:
	public LineRuler
{
	QGraphicsPolygonItem *myRect, *bgR;
protected:
	QPointF calculateTextPos() const override;
public:
	PolyRuler(const QPolygonF& r, Container* parent=0);
	
	enum { Type = UserType + 7 };
	int type() const { return Type; }

	QRectF boundingRect() const;

	QPainterPath shape() const;

	QString defaultText() const override;

	void setPen1(const QPen& p);
	void setPen2(const QPen& p);

	QPolygonF rect() { return myRect->polygon(); }
};