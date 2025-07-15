stlp_std::messages<char> *__thiscall stlp_std::messages<char>::`vector deleting destructor'(
        stlp_std::messages<char> *this,
        char a2)
{
  this->__vftable = (stlp_std::messages<char>_vtbl *)&stlp_std::messages<char>::`vftable';
  stlp_std::locale::facet::~facet(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


stlp_std::messages<wchar_t> *__thiscall stlp_std::messages<wchar_t>::`vector deleting destructor'(
        stlp_std::messages<wchar_t> *this,
        char a2)
{
  this->__vftable = (stlp_std::messages<wchar_t>_vtbl *)&stlp_std::messages<wchar_t>::`vftable';
  stlp_std::locale::facet::~facet(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
