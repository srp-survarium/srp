void __thiscall stlp_std::basic_ios<char,stlp_std::char_traits<char>>::setstate(
        stlp_std::basic_ios<char,stlp_std::char_traits<char> > *this,
        int __state)
{
  int v2; // [esp+8h] [ebp-Ch]

  if ( this->_M_streambuf )
    v2 = __state | this->_M_iostate;
  else
    v2 = __state | this->_M_iostate | 1;
  this->_M_iostate = v2;
  if ( (this->_M_exception_mask & this->_M_iostate) != 0 )
    stlp_std::ios_base::_M_throw_failure(this);
}
