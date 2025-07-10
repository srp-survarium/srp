stlp_std::codecvt<char,char,int> *__thiscall stlp_std::codecvt<char,char,int>::`vector deleting destructor'(
        stlp_std::codecvt<char,char,int> *this,
        char a2)
{
  stlp_std::codecvt<char,char,int>::~codecvt<char,char,int>(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
