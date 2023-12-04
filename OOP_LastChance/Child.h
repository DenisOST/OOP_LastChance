#include "ILesson.h"

class Child
{
public:
	vector<ICharacterFeatures*> addFeatures;
	ICountingAction * countingAction;
	IWritingAction * writingAction;
	IReadingAction * readingAction;
	IMultiplyAction * multiplyAction;
	string Name = "";
	ILesson * CurrentLesson;

	Child()
	{
		CurrentLesson = NULL;
	}

	~Child()
	{
	}

	void addCounting() { countingAction->counting(); }
	void addWriting() { writingAction->writing(); }
	void addReading() { readingAction->reading(); }
	void addMultiply() { multiplyAction->multiply(); }
	void SetName(string name) { Name = name; }
	
	void DisplaySkills() {
		this->addCounting();
		this->addMultiply();
		this->addReading();
		this->addWriting();
		cout << Name << endl;
	}

	void DisplayFeatures() {
		for (vector<ICharacterFeatures*>::iterator
			it = addFeatures.begin();
			it != addFeatures.end();  it++) {
			(*it)->features();
		}

	}

	void addFeature(ICharacterFeatures *newFeatures) {
		addFeatures.push_back(newFeatures);
	}

	void SetTask(ILesson* lesson)
	{
		CurrentLesson = lesson;
	}

	void CompleteLesson()
	{
		CurrentLesson->doLesson();
	}
};

class Preschooler : public Child {
public:
	Preschooler() {
		countingAction = new CanNotCounting();
		writingAction = new CanWriting();
		readingAction = new CanNotReading();
		multiplyAction = new CanNotMultiply();
	}

	Preschooler(ICountingAction *c, IWritingAction *w, IReadingAction *r, IMultiplyAction *m, string name) {
		countingAction = c;
		writingAction = w;
		readingAction = r;
		multiplyAction = m;
		SetName(name);
	}
}; 

class Schooler : public Child {
public:
	Schooler() {
		countingAction = new CanCounting();
		writingAction = new CanWriting();
		readingAction = new CanReading();
		multiplyAction = new CanNotMultiply();
	}

	Schooler(ICountingAction* c, IWritingAction* w, IReadingAction* r, IMultiplyAction* m, string name) {
		countingAction = c;
		writingAction = w;
		readingAction = r;
		multiplyAction = m;
		SetName(name);
	}
};

class Oldschooler : public Child {
public:
	Oldschooler() {
		countingAction = new CanCounting();
		writingAction = new CanWriting();
		readingAction = new CanReading();
		multiplyAction = new CanMultiply();
	}

	Oldschooler(ICountingAction* c, IWritingAction* w, IReadingAction* r, IMultiplyAction* m, string name) {
		countingAction = c;
		writingAction = w;
		readingAction = r;
		multiplyAction = m;
		SetName(name);
	}
};

