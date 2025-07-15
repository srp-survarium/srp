void __thiscall stlp_std::basic_ios<char,stlp_std::char_traits<char>>::_M_handle_exception(
        stlp_std::basic_ios<char,stlp_std::char_traits<char> > *this,
        int __flag)
{
  this->_M_iostate |= __flag;
}


void __thiscall stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::_M_handle_exception(
        stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        int __flag)
{
  this->_M_iostate |= __flag;
  if ( (__flag & this->_M_exception_mask) != 0 )
    _CxxThrowException(0, 0);
}
