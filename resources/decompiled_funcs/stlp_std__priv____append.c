void __usercall stlp_std::priv::__append(
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *name@<eax>,
        stlp_std::priv::__basic_iostring<char> *buf)
{
  stlp_std::forward_iterator_tag __formal; // [esp+3h] [ebp-1h] BYREF

  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
    buf,
    name->_M_start_of_storage._M_data,
    name->_M_finish,
    &__formal);
}
