#include <string.h>
#include "basicdef.h"
#include "generictype.h"
using namespace generictypedef;
/***********************************************/
GENERICTYPE::GENERICTYPE(void)
: eDataType(DTYPE::TYPE_NULL)
, iValue(0)
{
}
/***********************************************/
GENERICTYPE::GENERICTYPE(bool bValue_)
: eDataType(DTYPE::TYPE_BOOL)
, bValue(bValue_)
{
}
/***********************************************/
GENERICTYPE::GENERICTYPE(char cValue_)
: eDataType(DTYPE::TYPE_CHAR)
, cValue(cValue_)
{
}
/***********************************************/
GENERICTYPE::GENERICTYPE(int iValue_)
: eDataType(DTYPE::TYPE_INT)
, iValue(iValue_)
{
}
/***********************************************/
GENERICTYPE::GENERICTYPE(double dValue_)
: eDataType(DTYPE::TYPE_REAL)
, dValue(dValue_)
{
}
/***********************************************/
GENERICTYPE::GENERICTYPE(char *strValue_)
: eDataType(DTYPE::TYPE_STR)
{
	size_t szStr = 0;
	while(*(strValue_ + szStr) != '\0')
		szStr++;

	strncpy_s(strValue, sizeof(strValue)/sizeof(char), strValue_, szStr);
}
/***********************************************/
GENERICTYPE::GENERICTYPE(const GENERICTYPE &generictype)
{
	eDataType = generictype.DataType();
	switch (eDataType)
	{
	case DTYPE::TYPE_NULL:
		iValue = 0;
		break;
	case DTYPE::TYPE_BOOL:
		bValue = generictype;
		break;
	case DTYPE::TYPE_CHAR:
		cValue = generictype;
		break;
	case DTYPE::TYPE_INT:
		iValue = generictype;
		break;
	case DTYPE::TYPE_REAL:
		dValue = generictype;
		break;
	case DTYPE::TYPE_STR:
		size_t szStr = 0;
		const char* strValue_ = generictype;
		while(*(strValue_ + szStr) != '\0')
			szStr++;
		strncpy_s(strValue, sizeof(strValue)/sizeof(char), strValue_, szStr);
		break;
	}
}
/***********************************************/
GENERICTYPE::~GENERICTYPE(void)
{
}
/***********************************************/
GENERICTYPE& GENERICTYPE::operator=(const GENERICTYPE &generictype)
{
	eDataType = generictype.DataType();
	switch (eDataType)
	{
	case DTYPE::TYPE_NULL:
		iValue = 0;
		break;
	case DTYPE::TYPE_BOOL:
		bValue = generictype;
		break;
	case DTYPE::TYPE_CHAR:
		cValue = generictype;
		break;
	case DTYPE::TYPE_INT:
		iValue = generictype;
		break;
	case DTYPE::TYPE_REAL:
		dValue = generictype;
		break;
	case DTYPE::TYPE_STR:
		size_t szStr = 0;
		const char* strValue_ = generictype;
		while(*(strValue_ + szStr) != '\0')
			szStr++;
		strncpy_s(strValue, sizeof(strValue)/sizeof(char), strValue_, szStr);
		break;
	}

	return *this;
}
/***********************************************/
