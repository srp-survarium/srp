stlp_std::fpos<int> *__thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::seekpos(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        stlp_std::fpos<int> *result,
        stlp_std::fpos<int> __formal,
        int a4)
{
  result->_M_pos = -1;
  result->_M_st = 0;
  return result;
}


stlp_std::fpos<int> *__thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::seekpos(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::fpos<int> *result,
        stlp_std::fpos<int> __formal,
        int a4)
{
  stlp_std::fpos<int> *v4; // eax

  v4 = result;
  result->_M_pos = -1;
  result->_M_st = 0;
  return v4;
}
