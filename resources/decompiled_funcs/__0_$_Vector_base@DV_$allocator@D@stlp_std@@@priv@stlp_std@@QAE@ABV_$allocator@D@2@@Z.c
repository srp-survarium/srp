void __thiscall stlp_std::priv::_Vector_base<char,stlp_std::allocator<char>>::_Vector_base<char,stlp_std::allocator<char>>(
        stlp_std::priv::_Vector_base<char,stlp_std::allocator<char> > *this,
        const stlp_std::allocator<char> *__a)
{
  this->_M_start = 0;
  this->_M_finish = 0;
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>(
    &this->_M_end_of_storage,
    __a,
    0);
}
