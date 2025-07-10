void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        const stlp_std::allocator<char> *__a)
{
  this->_M_finish = (char *)this;
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>(
    &this->_M_start_of_storage,
    __a,
    (char *)this);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_allocate_block(this, 0x10u);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_terminate_string(this);
}
