#pragma once
#include <vector>
#include <string>

typedef struct{

	std::vector<int> mInfo;
	std::string mName;

}Container;


class GenericObj{
public:
	GenericObj();
	~GenericObj();
	void initObj(bool verbosity);
	void initContainerArray(int dataSize, std::vector<std::string> descriptors);
	void fillContainerArray(std::vector<int> info, std::string name);
	void finished();
public:
	int dependentEmperical(int choose, std::vector<std::vector<int> > what, bool order, bool exactly, bool progress = false, int times = 10000);
	int independentEmperical(int choose, std::vector<std::vector<int> > what, bool order, bool exactly, bool progress = false, int times = 10000);
	int dependentLogical(int choose, std::vector<std::vector<int> > what, bool order, bool exactly, bool progress = false);
	int independentLogical(int choose, std::vector<std::vector<int> > what, bool order, bool exactly, bool progress = false);
private:
	bool match(Container against, std::vector<int> with);
	Container drawMe();
	std::string retMsg;
	bool verbose;
	std::vector<Container> ContainerArray;
	std::vector<Container> ContainerArrayCopy;
	std::vector<std::string> desc;
	int infoSize;
	bool done;


};