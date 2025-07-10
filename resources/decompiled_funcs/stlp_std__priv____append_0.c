void __cdecl stlp_std::priv::__append_0(stlp_std::priv::__basic_iostring<wchar_t> *buf)
{
  const stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *name; // ecx
  stlp_std::forward_iterator_tag __formal; // [esp+1h] [ebp-1h] BYREF

  __formal.stlp_std::input_iterator_tag = (stlp_std::input_iterator_tag)HIBYTE(name);
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_appendT<wchar_t const *>(
    buf,
    name->_M_start_of_storage._M_data,
    &name->_M_start_of_storage._M_data[name->_M_finish - name->_M_start_of_storage._M_data],
    &__formal);
}
