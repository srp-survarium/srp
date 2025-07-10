stlp_std::locale *__thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::pubimbue(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        stlp_std::locale *result,
        const stlp_std::locale *__loc)
{
  stlp_std::locale __tmp; // [esp+4h] [ebp-4h] BYREF

  this->imbue(this, __loc);
  stlp_std::locale::locale(&__tmp, &this->_M_locale);
  stlp_std::locale::operator=(&this->_M_locale, __loc);
  stlp_std::locale::locale(result, &__tmp);
  stlp_std::locale::~locale(&__tmp);
  return result;
}
