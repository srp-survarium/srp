void __cdecl stlp_std::priv::__append_0(stlp_std::priv::__basic_iostring<wchar_t> *buf)
{
  int v1; // ecx
  stlp_std::forward_iterator_tag __formal; // [esp+1h] [ebp-1h] BYREF

  __formal.stlp_std::input_iterator_tag = (stlp_std::input_iterator_tag)HIBYTE(v1);
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_appendT<wchar_t const *>(
    buf,
    *(wchar_t **)(v1 + 36),
    (const wchar_t *)(*(_DWORD *)(v1 + 36) + 2 * ((*(_DWORD *)(v1 + 32) - *(_DWORD *)(v1 + 36)) >> 1)),
    &__formal);
}
