stlp_std::basic_ios<char,stlp_std::char_traits<char> > *__thiscall stlp_std::basic_ios<char,stlp_std::char_traits<char>>::`vector deleting destructor'(
        stlp_std::basic_ios<char,stlp_std::char_traits<char> > *this,
        char a2)
{
  this->__vftable = (stlp_std::basic_ios<char,stlp_std::char_traits<char> >_vtbl *)&stlp_std::basic_ios<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::ios_base::~ios_base(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
