/*1.实现有指针型成员变量的类的赋值符号的重载*/
class CMyString
{
public :
   CMyString();
   virtual ~CMyString();
   CMyString& operator= (const CMyString& mystr);
private:
   char*  pstr;
};

CMyString& CMyString::operator =(const CMyString& mystr)
{
   if (myStr == *this)
   {
      return *this;
   }
   
   if (strlen(this->pstr) < strlen(mystr.pstr) + 1)
   {
      delete this->pstr[];
      this->pstr = NULL;
   }
   else
   {
       this->pstr = new char[strlen(mystr.pstr) + 1];
   }
   memcpy(this->pstr, mystr.pstr);
   
   return *this;
}

CMyString& CMyString::operator=(const CMyString& mystr)
{
   if (*this != mystr)
   {
      CMyString tempStr(mystr);
      tempStr.pstr = mystr.pstr;
      mystr.pstr = this.pstr;
      this.pstr = temp.pstr;
   }

   return *this;   
}

