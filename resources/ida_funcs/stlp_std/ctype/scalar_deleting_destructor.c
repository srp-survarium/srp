stlp_std::ctype<wchar_t> *__thiscall stlp_std::ctype<wchar_t>::`scalar deleting destructor'(
        stlp_std::ctype<wchar_t> *this,
        char a2)
{
  stlp_std::ctype<wchar_t>::~ctype<wchar_t>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
