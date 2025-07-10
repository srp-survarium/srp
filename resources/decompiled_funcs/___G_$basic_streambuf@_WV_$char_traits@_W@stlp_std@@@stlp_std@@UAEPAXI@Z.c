stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::`scalar deleting destructor'(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        char a2)
{
  this->__vftable = (stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> >_vtbl *)&stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  stlp_std::locale::~locale(&this->_M_locale);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
