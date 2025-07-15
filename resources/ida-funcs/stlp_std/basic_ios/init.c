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


void __thiscall stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::init(
        stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *__sb)
{
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *v3; // ebx
  BOOL v4; // eax
  stlp_std::locale *v5; // eax
  const stlp_std::ctype<wchar_t> *M_cached_ctype; // ecx
  stlp_std::locale v7; // [esp+10h] [ebp-10h] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  v3 = __sb;
  v4 = __sb == 0;
  this->_M_streambuf = __sb;
  this->_M_iostate = v4;
  if ( (v4 & this->_M_exception_mask) != 0 )
    stlp_std::ios_base::_M_throw_failure(this);
  stlp_std::locale::locale(&v7);
  v8 = 0;
  stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::imbue(this, (stlp_std::locale *)&__sb, v5);
  stlp_std::locale::~locale((stlp_std::locale *)&__sb);
  v8 = -1;
  stlp_std::locale::~locale(&v7);
  this->_M_tied_ostream = 0;
  this->_M_exception_mask = 0;
  this->_M_fmtflags = 4104;
  LODWORD(this->_M_width) = 0;
  HIDWORD(this->_M_width) = 0;
  LODWORD(this->_M_precision) = 6;
  this->_M_iostate = v3 == 0;
  M_cached_ctype = this->_M_cached_ctype;
  HIDWORD(this->_M_precision) = 0;
  this->_M_fill = M_cached_ctype->do_widen((stlp_std::ctype<wchar_t> *)M_cached_ctype, 32);
}
