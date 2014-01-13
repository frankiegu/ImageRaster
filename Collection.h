#pragma once

class Format {
	//Simply meant to enhance Graphics Item formatting capabilities
protected:
	QFont myFont;
	QPen myOutPen;
	QPen myInPen;
public:
	Format(): 
		myFont(QFont("Courrier")),
		myInPen(QPen(QBrush(Qt::black), 1)),
		myOutPen(QPen(Qt::white)) { }
	~Format() { }

	virtual QPen pen1() const { return myInPen; }
	virtual void setPen1(const QPen& p) { myInPen = p; }
	virtual QPen pen2() const { return myOutPen; }
	virtual void setPen2(const QPen& p) { myOutPen = p; }
	virtual QFont font() const { return myFont; }
	virtual void setFont(const QFont& f) { myFont = f; }
};

class mData {
protected:
	QString myLabel;
public:
	mData(const QString& l = "") :
		myLabel(l) { }
	virtual QString label() const { return myLabel; }
	virtual void setLabel(const QString& l) { myLabel = l; }
};

class FormatData {
protected:
	QFont myFont;
	QPen myPen;
	QBrush myBrush;
	QString myText;
	QString myUnit;
	int size1;	//i.e. width
	int size2;	//i.e. height
public:
	FormatData(QPen p = QPen(QColor(Qt::black)), QBrush b = QBrush(QColor(Qt::black)), 
		QFont f = QFont(), QString txt = "", QString unit = " \u00b5m",
		int s1 = 0, int s2 = 0) :
	myPen(p), myBrush(b), myFont(f), myText(txt), myUnit(unit), size1(s1), size2(s2) { }
	~FormatData() { };

	//Getter methods, I use prefix get to avoid confusion with same properties in derived class.
	QFont getFont() const { return myFont; }
	QPen getPen() const { return myPen; }
	QBrush getBrush() const { return myBrush; }
	QString getText() const { return myText; }
	QString getUnit() const { return myUnit; }
	int getWidth() const { return size1; }
	int getHeight() const { return size2; }
	int getRadius() const { return size1; }
	int getSize1() const { return size1; }
	int getSize2() const { return size2; }

	QString getSize1Text() const { return myText + QString().number(size1) + myUnit; }
	QString getSize2Text() const { return myText + QString().number(size2) + myUnit; }
	FormatData getFormatData() const { return *this; }

	//Use them if in doubt about s1 or s2:
	virtual void setWidth(const int& w) { size1 = w; }
	virtual void setHeight(const int& h) { size2 = h; }
	virtual void setRadius(const int& r) { size1 = r; }

	virtual void setTxt(const QString& t) { myText = t; }
	virtual void setUnit(const QString& t) { myUnit = t; }
	virtual void setFont(const QFont& f) { myFont = f; }
	virtual void setBrush(const QBrush& b) { myBrush = b; }
	virtual void setPen(const QPen& p) { myPen = p; }
};

class Container
{
protected:
	Container *branch;
	QList<Container*> leaves;
public:
	Container(Container* parent = 0)
		: branch(parent) {
			if (parent) parent->addLeaf(this);
	}
	void addLeaf(Container* leaf) {
		leaves.append(leaf);
		leaf->setBranch(this);
	}
	void removeLeaf(Container* leaf) {
		leaves.removeOne(leaf);
	}
	QList<Container*> leafItems() const {
		return leaves;
	}
	Container* getBranch() {
		return branch; 
	}
	void setBranch(Container* newBranch) {
		//if (branch) branch->removeLeaf(this);
		branch = newBranch;
		//newBranch->addLeaf(this);
	}
	void unbranch() {
		branch->removeLeaf(this);
	}
	~Container() {
		if (branch) branch->removeLeaf(this);
		foreach(auto *p, leaves)
			delete p;
	}
};

class rData {
	double num1, num2, num3;
	double modifier;
public:
	rData() :
		num1(0), num2(0), num3(0), modifier(1.0) { }
	enum class Unit {
		Micrometer, Milimeter, Centimeter, Meter
	};
	virtual double width()  const { return num1; }
	virtual double height() const { return num2; }
	virtual double area()   const { return num3; }
	virtual double radius() const { return num1; }
	virtual double length() const { return num1; }
	virtual double mod()	const { return modifier; }

	virtual void setWidth(const double& w)	{ num1 = w; }
	virtual void setHeight(const double& h)	{ num2 = h; }
	virtual void setArea(const double& a)	{ num3 = a; }
	virtual void setRadius(const double& r)	{ num1 = r; }
	virtual void setLength(const double& l)	{ num1 = l; }
	virtual void setMod(const Unit& u);
	virtual void setMod(const double& m) { modifier = m; }

	virtual QString unit() const;
};

//Shorthand converter:
namespace Converter {
	int ToInt(const char* val);
	std::string ToString(const int val);
};


