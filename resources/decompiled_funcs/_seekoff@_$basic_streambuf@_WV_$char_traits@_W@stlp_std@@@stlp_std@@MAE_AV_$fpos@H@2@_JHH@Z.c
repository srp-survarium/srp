stlp_std::fpos<int> *__thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::seekoff(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::fpos<int> *result,
        __int64 __formal,
        int a4,
        int a5)
{
  stlp_std::fpos<int> *v5; // eax

  v5 = result;
  result->_M_pos = -1;
  result->_M_st = 0;
  return v5;
}
