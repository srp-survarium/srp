stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::`vector deleting destructor'(
        stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        char a2)
{
  this->__vftable = (stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t> >_vtbl *)&stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  stlp_std::ios_base::~ios_base(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
