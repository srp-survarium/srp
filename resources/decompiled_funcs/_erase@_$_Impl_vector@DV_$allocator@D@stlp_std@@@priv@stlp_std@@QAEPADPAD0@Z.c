char *__thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::erase(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        char *__first,
        char *__last)
{
  if ( __first != __last )
    this->_M_finish = (char *)stlp_std::priv::__copy_trivial(
                                (unsigned __int8 *)__last,
                                (unsigned __int8 *)this->_M_finish,
                                (unsigned __int8 *)__first);
  return __first;
}
