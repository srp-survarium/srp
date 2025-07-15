stlp_std::locale *__thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::pubimbue(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        stlp_std::locale *result,
        const stlp_std::locale *__loc)
{
  stlp_std::locale *v3; // esi

  v3 = (stlp_std::locale *)this;
  this->imbue(this, __loc);
  v3 += 7;
  stlp_std::locale::locale(result, v3);
  stlp_std::locale::operator=(v3, __loc);
  return result;
}


stlp_std::locale *__thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::pubimbue(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::locale *result,
        const stlp_std::locale *__loc)
{
  stlp_std::locale *v3; // esi

  v3 = (stlp_std::locale *)this;
  this->imbue(this, __loc);
  v3 += 7;
  stlp_std::locale::locale(result, v3);
  stlp_std::locale::operator=(v3, __loc);
  return result;
}
