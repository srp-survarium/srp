stlp_std::locale *__thiscall stlp_std::basic_ios<char,stlp_std::char_traits<char>>::imbue(
        stlp_std::basic_ios<char,stlp_std::char_traits<char> > *this,
        stlp_std::locale *result,
        stlp_std::locale *__loc)
{
  stlp_std::locale v5; // [esp+Ch] [ebp-8h] BYREF
  stlp_std::locale __tmp; // [esp+10h] [ebp-4h] BYREF

  stlp_std::ios_base::imbue(this, &__tmp, __loc);
  if ( this->_M_streambuf )
  {
    stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::pubimbue(this->_M_streambuf, &v5, __loc);
    stlp_std::locale::~locale(&v5);
  }
  this->_M_cached_ctype = (const stlp_std::ctype<char> *)stlp_std::locale::_M_use_facet(
                                                           __loc,
                                                           &stlp_std::ctype<char>::id);
  stlp_std::locale::locale(result, &__tmp);
  stlp_std::locale::~locale(&__tmp);
  return result;
}
