#ifndef __serach_algorithms_h__
#define __serach_algorithms_h__
/***********************************************/
namespace searchalgorithmsdef
{
/***********************************************/
using namespace generictypedef;
/***********************************************/
//SEARCH class implements two serach functions
//Binary Search which assumes array is sorted and searches the required value in O(NlogN)
//Interpolation Search which assumes array is sorted and data is equispaced and searches the required value in O(N)
/***********************************************/
class SEARCH
{
public:
	static int BinarySearch(GENERICTYPE generictypeArray[], size_t szGenericTypeArray, GENERICTYPE *pGenericTypeValue, int (*pCompFunc)(GENERICTYPE *pgenerictypeValue1, GENERICTYPE *pgenerictypeValue2));
	static int InterpolationSearch(GENERICTYPE generictypeArray[], size_t szGenericTypeArray, GENERICTYPE *pGenericTypeValue, int (*pCompFunc)(GENERICTYPE *pgenerictypeValue1, GENERICTYPE *pgenerictypeValue2));
};
/***********************************************/
}
/***********************************************/
#endif