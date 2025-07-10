void __cdecl stlp_std::swap<stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t>>::_Buffers>(
        stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers *__a,
        stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers *__b)
{
  stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers __tmp; // [esp+8h] [ebp-24h] BYREF

  qmemcpy(&__tmp, __a, sizeof(__tmp));
  qmemcpy(__a, __b, sizeof(stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers));
  qmemcpy(__b, &__tmp, sizeof(stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers));
}
