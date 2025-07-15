stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *__thiscall stlp_std::basic_ios<char,stlp_std::char_traits<char>>::rdbuf(
        stlp_std::basic_ios<char,stlp_std::char_traits<char> > *this,
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *__buf)
{
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_streambuf; // esi

  M_streambuf = this->_M_streambuf;
  this->_M_streambuf = __buf;
  stlp_std::basic_ios<char,stlp_std::char_traits<char>>::clear(this, 0);
  return M_streambuf;
}
