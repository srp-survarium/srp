stlp_std::numpunct<wchar_t> *__thiscall stlp_std::numpunct<wchar_t>::`scalar deleting destructor'(
        stlp_std::numpunct<wchar_t> *this,
        char a2)
{
  stlp_std::numpunct<wchar_t>::~numpunct<wchar_t>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
