#include "basicdef.h"
#include "generictype.h"
#include "searchalgorithms.h"
using namespace searchalgorithmsdef;
/***********************************************/
/*static*/ int SEARCH::BinarySearch(GENERICTYPE generictypeArray[], size_t szGenericTypeArray, GENERICTYPE *pGenericTypeValue, int (*pCompFunc)(GENERICTYPE *pgenerictypeValue1, GENERICTYPE *pgenerictypeValue2))
{
	if(IS_NULL(generictypeArray) || szGenericTypeArray == 0 || IS_NULL(pGenericTypeValue) || IS_NULL(pCompFunc))
		return FALSE;

	size_t szLowerIndex = 0;
	size_t szHigherIndex = szGenericTypeArray - 1;

	while(pCompFunc(pGenericTypeValue, &generictypeArray[szLowerIndex]) >= 0 &&
		   pCompFunc(pGenericTypeValue, &generictypeArray[szHigherIndex]) <= 0)
	{
		size_t szMiddleIndex = (szHigherIndex - szLowerIndex)/2 + szLowerIndex;
		if(pCompFunc(pGenericTypeValue, &generictypeArray[szMiddleIndex]) == 0)
			return szMiddleIndex;

		if(pCompFunc(pGenericTypeValue, &generictypeArray[szMiddleIndex]) < 0 && szMiddleIndex > szLowerIndex)
			szHigherIndex = szMiddleIndex - 1;
		else if(pCompFunc(pGenericTypeValue, &generictypeArray[szMiddleIndex]) > 0 && szMiddleIndex < szHigherIndex)
			szLowerIndex = szMiddleIndex + 1;
		else
			return FALSE;
	}

	return FALSE;
}
/***********************************************/
/*static*/ int SEARCH::InterpolationSearch(GENERICTYPE generictypeArray[], size_t szGenericTypeArray, GENERICTYPE *pGenericTypeValue, int (*pCompFunc)(GENERICTYPE *pgenerictypeValue1, GENERICTYPE *pgenerictypeValue2))
{
	if(IS_NULL(generictypeArray) || szGenericTypeArray == 0 || IS_NULL(pGenericTypeValue) || IS_NULL(pCompFunc))
		return FALSE;

	size_t szLowerIndex = 0;
	size_t szHigherIndex = szGenericTypeArray - 1;

	while(pCompFunc(pGenericTypeValue, &generictypeArray[szLowerIndex]) >= 0 &&
		   pCompFunc(pGenericTypeValue, &generictypeArray[szHigherIndex]) <= 0)
	{
		int iYY1 = pCompFunc(pGenericTypeValue, &generictypeArray[szLowerIndex]);
		int iY2Y1 = pCompFunc(&generictypeArray[szHigherIndex], &generictypeArray[szLowerIndex]);
		size_t szExtraX = ((iYY1)*(szHigherIndex - szLowerIndex))/(iY2Y1);

		size_t szMiddleIndex = szLowerIndex +  szExtraX;
		if(pCompFunc(pGenericTypeValue, &generictypeArray[szMiddleIndex]) == 0)
			return szMiddleIndex;

		if(pCompFunc(pGenericTypeValue, &generictypeArray[szMiddleIndex]) < 0 && szMiddleIndex > szLowerIndex)
			szHigherIndex = szMiddleIndex - 1;
		else if(pCompFunc(pGenericTypeValue, &generictypeArray[szMiddleIndex]) > 0 && szMiddleIndex < szHigherIndex)
			szLowerIndex = szMiddleIndex + 1;
		else
			return FALSE;
	}

	return FALSE;
}
/***********************************************/