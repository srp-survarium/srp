void __thiscall stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t>>::_String_base<wchar_t,stlp_std::allocator<wchar_t>>(
        stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> > *this,
        const stlp_std::allocator<wchar_t> *__a,
        signed int __n)
{
  signed int v3; // eax
  stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::allocator<wchar_t> > *p_M_start_of_storage; // edi
  wchar_t *v6; // eax
  unsigned int v7; // edx

  v3 = __n;
  p_M_start_of_storage = &this->_M_start_of_storage;
  this->_M_finish = (wchar_t *)this;
  this->_M_start_of_storage._M_data = (wchar_t *)this;
  __n = v3;
  if ( v3 <= 0 )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( (unsigned int)v3 > 0x10 )
  {
    v6 = (wchar_t *)stlp_std::allocator<wchar_t>::_M_allocate(&this->_M_start_of_storage, v3, (unsigned int *)&__n);
    v7 = __n;
    p_M_start_of_storage->_M_data = v6;
    this->_M_finish = v6;
    this->_M_buffers._M_end_of_storage = &v6[v7];
  }
}
