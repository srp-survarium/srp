void __cdecl stlp_std::swap<unsigned int>(unsigned int *__a, unsigned int *__b)
{
  unsigned int v2; // ecx

  v2 = *__a;
  *__a = *__b;
  *__b = v2;
}


void __cdecl stlp_std::swap<stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_Buffers>(
        stlp_std::priv::_String_base<char,stlp_std::allocator<char> >::_Buffers *__a,
        stlp_std::priv::_String_base<char,stlp_std::allocator<char> >::_Buffers *__b)
{
  char *M_end_of_storage; // edx
  int v3; // ebx
  int v4; // esi
  int v5; // edi

  M_end_of_storage = __a->_M_end_of_storage;
  v3 = *(_DWORD *)&__a->_M_static_buf[12];
  v4 = *(_DWORD *)&__a->_M_static_buf[4];
  v5 = *(_DWORD *)&__a->_M_static_buf[8];
  *__a = *__b;
  __b->_M_end_of_storage = M_end_of_storage;
  *(_DWORD *)&__b->_M_static_buf[4] = v4;
  *(_DWORD *)&__b->_M_static_buf[8] = v5;
  *(_DWORD *)&__b->_M_static_buf[12] = v3;
}


void __cdecl stlp_std::swap<stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t>>::_Buffers>(
        stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers *__a,
        stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers *__b)
{
  stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers __tmp; // [esp+8h] [ebp-24h] BYREF

  qmemcpy(&__tmp, __a, sizeof(__tmp));
  qmemcpy(__a, __b, sizeof(stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers));
  qmemcpy(__b, &__tmp, sizeof(stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t> >::_Buffers));
}


void __usercall stlp_std::swap<vostok::size_policy>(vostok::size_policy *__a@<ecx>, vostok::size_policy *__b@<eax>)
{
  unsigned int m_size; // edx

  m_size = __a->m_size;
  __a->m_size = __b->m_size;
  __b->m_size = m_size;
}
