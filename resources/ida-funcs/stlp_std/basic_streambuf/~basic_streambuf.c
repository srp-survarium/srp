void __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::~basic_streambuf<char,stlp_std::char_traits<char>>(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this)
{
  this->__vftable = (stlp_std::basic_streambuf<char,stlp_std::char_traits<char> >_vtbl *)&stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::locale::~locale(&this->_M_locale);
}


void __thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::~basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  this->__vftable = (stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> >_vtbl *)&stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  stlp_std::locale::~locale(&this->_M_locale);
}
