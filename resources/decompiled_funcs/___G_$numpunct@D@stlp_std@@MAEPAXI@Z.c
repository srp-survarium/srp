stlp_std::numpunct<char> *__thiscall stlp_std::numpunct<char>::`scalar deleting destructor'(
        stlp_std::numpunct<char> *this,
        char a2)
{
  stlp_std::numpunct<char>::~numpunct<char>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
