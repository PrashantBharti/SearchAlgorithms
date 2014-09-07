#ifndef __generic_type_h__
#define __generic_type_h__
/***********************************************/
namespace generictypedef
{
/***********************************************/
//Enumeration type resemble a type in generic type
/***********************************************/
enum class DTYPE { TYPE_NULL,TYPE_BOOL, TYPE_CHAR, TYPE_INT, TYPE_REAL, TYPE_STR };
/***********************************************/
class GENERICTYPE
{
public:
	GENERICTYPE(void);
	GENERICTYPE(bool bValue_);
	GENERICTYPE(char cValue_);
	GENERICTYPE(int iValue_);
	GENERICTYPE(double dValue_);
	GENERICTYPE(char *strValue_);
	GENERICTYPE(const GENERICTYPE &generictype);
	~GENERICTYPE(void);

public:
	operator bool(void) const { return bValue; }
	operator char(void) const { return cValue; }
	operator int(void) const { return iValue; }
	operator double(void) const { return dValue; }
	operator const char*(void) const { return strValue; }
	GENERICTYPE& operator =(const GENERICTYPE &generictype);

public:
	DTYPE DataType(void) const {return eDataType;}
	bool GetBool(void) const {return bValue;}
	char GetChar(void) const {return cValue;}
	int GetInt(void) const {return iValue;}
	double GetReal(void) const {return dValue;}
	const char* GetStr(void) const {return strValue;}

private:
	DTYPE eDataType;
	union
	{
		bool bValue;
		char cValue;
		int iValue;
		double dValue;
		char strValue[100];
	};
};
/***********************************************/
}
/***********************************************/
#endif __generic_type_h__