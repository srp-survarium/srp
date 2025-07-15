void __thiscall stlp_std::basic_ios<char,stlp_std::char_traits<char>>::clear(
        stlp_std::basic_ios<char,stlp_std::char_traits<char> > *this,
        int __state)
{
  int v2; // eax

  v2 = __state;
  if ( !this->_M_streambuf )
    v2 = __state | 1;
  this->_M_iostate = v2;
  if ( (v2 & this->_M_exception_mask) != 0 )
    stlp_std::ios_base::_M_throw_failure(this);
}
