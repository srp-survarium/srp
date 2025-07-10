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
