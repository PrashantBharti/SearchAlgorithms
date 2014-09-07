#include "basicdef.h"
#include "generictype.h"
#include "searchalgorithms.h"
using namespace searchalgorithmsdef;

int CompFunc(GENERICTYPE *pgenerictypeValue1, GENERICTYPE *pgenerictypeValue2)
{
	return pgenerictypeValue2->GetInt() - pgenerictypeValue1->GetInt();
}

int main(int argc, char *argv[])
{
	GENERICTYPE arrItems[5] = {5, 4, 3, 2, 1};
	size_t szValueIndexBS = SEARCH::BinarySearch(arrItems, sizeof(arrItems)/sizeof(arrItems[0]), &GENERICTYPE(4), &CompFunc);
	size_t szValueIndexIS = SEARCH::InterpolationSearch(arrItems, sizeof(arrItems)/sizeof(arrItems[0]), &GENERICTYPE(4), &CompFunc);
	return 0;
}