stlp_std::codecvt<char,char,int> *__thiscall stlp_std::codecvt<char,char,int>::`vector deleting destructor'(
        stlp_std::codecvt<char,char,int> *this,
        char a2)
{
  stlp_std::codecvt<char,char,int>::~codecvt<char,char,int>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


stlp_std::codecvt<wchar_t,char,int> *__thiscall stlp_std::codecvt<wchar_t,char,int>::`vector deleting destructor'(
        stlp_std::codecvt<wchar_t,char,int> *this,
        char a2)
{
  stlp_std::codecvt<wchar_t,char,int>::~codecvt<wchar_t,char,int>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
