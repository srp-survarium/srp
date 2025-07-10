stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *__thiscall stlp_std::basic_ios<char,stlp_std::char_traits<char>>::rdbuf(
        stlp_std::basic_ios<char,stlp_std::char_traits<char> > *this,
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *__buf)
{
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *__tmp; // [esp+Ch] [ebp-4h]

  __tmp = this->_M_streambuf;
  this->_M_streambuf = __buf;
  this->_M_iostate = this->_M_streambuf == 0;
  if ( (this->_M_exception_mask & this->_M_iostate) != 0 )
    stlp_std::ios_base::_M_throw_failure(this);
  return __tmp;
}
