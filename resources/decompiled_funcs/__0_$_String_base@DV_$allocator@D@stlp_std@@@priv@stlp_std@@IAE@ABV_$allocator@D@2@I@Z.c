void __thiscall stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_String_base<char,stlp_std::allocator<char>>(
        stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *this,
        const stlp_std::allocator<char> *__a,
        unsigned int __n)
{
  this->_M_finish = (char *)this;
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>(
    &this->_M_start_of_storage,
    __a,
    (char *)this);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_allocate_block(this, __n);
}
