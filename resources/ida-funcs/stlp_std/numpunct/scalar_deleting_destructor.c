stlp_std::numpunct<char> *__thiscall stlp_std::numpunct<char>::`scalar deleting destructor'(
        stlp_std::numpunct<char> *this,
        char a2)
{
  stlp_std::numpunct<char>::~numpunct<char>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


stlp_std::numpunct<wchar_t> *__thiscall stlp_std::numpunct<wchar_t>::`scalar deleting destructor'(
        stlp_std::numpunct<wchar_t> *this,
        char a2)
{
  stlp_std::numpunct<wchar_t>::~numpunct<wchar_t>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
