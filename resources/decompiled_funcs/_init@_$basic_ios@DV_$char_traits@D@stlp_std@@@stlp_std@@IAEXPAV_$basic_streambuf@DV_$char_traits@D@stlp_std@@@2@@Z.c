void __thiscall stlp_std::basic_ios<char,stlp_std::char_traits<char>>::init(
        stlp_std::basic_ios<char,stlp_std::char_traits<char> > *this,
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *__sb)
{
  stlp_std::locale *v2; // eax
  stlp_std::locale result; // [esp+20h] [ebp-8h] BYREF
  stlp_std::locale v5; // [esp+24h] [ebp-4h] BYREF

  stlp_std::basic_ios<char,stlp_std::char_traits<char>>::rdbuf(this, __sb);
  stlp_std::locale::locale(&v5);
  stlp_std::basic_ios<char,stlp_std::char_traits<char>>::imbue(this, &result, v2);
  stlp_std::locale::~locale(&result);
  stlp_std::locale::~locale(&v5);
  this->_M_tied_ostream = 0;
  this->_M_exception_mask = 0;
  this->_M_iostate = __sb == 0;
  this->_M_fmtflags = 4104;
  this->_M_width = 0;
  this->_M_precision = 6;
  this->_M_fill = 32;
}
