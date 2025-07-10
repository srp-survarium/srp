stlp_std::locale *__thiscall stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::imbue(
        stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::locale *result,
        stlp_std::locale *__loc)
{
  stlp_std::locale *v4; // edi
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *M_streambuf; // ecx
  int v7; // [esp+0h] [ebp-28h] BYREF
  stlp_std::ios_base *v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+14h] [ebp-14h]
  int *v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  v10 = &v7;
  v8 = this;
  v9 = 0;
  v4 = __loc;
  v11 = 0;
  stlp_std::ios_base::imbue(this, result, __loc);
  M_streambuf = this->_M_streambuf;
  v9 = 1;
  v11 = 1;
  if ( M_streambuf )
  {
    stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::pubimbue(
      M_streambuf,
      (stlp_std::locale *)&__loc,
      v4);
    stlp_std::locale::~locale((stlp_std::locale *)&__loc);
  }
  this->_M_cached_ctype = (const stlp_std::ctype<wchar_t> *)stlp_std::locale::_M_use_facet(
                                                              v4,
                                                              &stlp_std::ctype<wchar_t>::id);
  return result;
}
