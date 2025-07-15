void __usercall stlp_std::priv::__append_1(
        stlp_std::priv::__basic_iostring<wchar_t> *buf@<ebx>,
        char *first@<edi>,
        char *last@<edx>,
        const stlp_std::ctype<wchar_t> *ct@<ecx>)
{
  stlp_std::forward_iterator_tag __formal; // [esp+Dh] [ebp-85h] BYREF
  wchar_t __first[64]; // [esp+Eh] [ebp-84h] BYREF

  ct->do_widen(ct, first, last, __first);
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_appendT<wchar_t const *>(
    buf,
    __first,
    &__first[last - first],
    &__formal);
}
