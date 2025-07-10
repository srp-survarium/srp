void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        unsigned int __n,
        int __c,
        const stlp_std::allocator<wchar_t> *__a)
{
  wchar_t *v5; // edi

  stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t>>::_String_base<wchar_t,stlp_std::allocator<wchar_t>>(
    this,
    __a,
    __n + 1);
  v5 = &this->_M_start_of_storage._M_data[__n];
  stlp_std::priv::__ufill<wchar_t *,wchar_t,int>(this->_M_start_of_storage._M_data, v5, (wchar_t *)&__c);
  this->_M_finish = v5;
  *v5 = 0;
}
