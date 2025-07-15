bool __usercall vostok::network_core::http_client::add_result_content@<al>(
        vostok::network_core::http_client *this@<ecx>,
        int a2@<eax>)
{
  stlp_std::basic_istream<char,stlp_std::char_traits<char> > *v3; // eax
  int v4; // esi
  int v5; // edi
  stlp_std::basic_istream<char,stlp_std::char_traits<char> > __is; // [esp+8h] [ebp-88h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __x; // [esp+78h] [ebp-18h] BYREF

  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::basic_istream<char,stlp_std::char_traits<char>>(
    &__is,
    (stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *)(a2 + 128),
    1);
  __x._M_finish = (char *)&__x;
  __x._M_start_of_storage._M_data = (char *)&__x;
  __x._M_buffers._M_static_buf[0] = 0;
  while ( 1 )
  {
    v3 = stlp_std::getline<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(&__is, &__x, 10);
    if ( ((*(_DWORD *)&v3->gap0[*(_DWORD *)(*(_DWORD *)v3->gap0 + 4) + 12] & 5) == 0
        ? (unsigned int)&v3->gap0[*(_DWORD *)(*(_DWORD *)v3->gap0 + 4)]
        : 0) == 0
      || stlp_std::operator==<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(&__x, "\r") )
    {
      break;
    }
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_append(
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)(a2 + 176),
      __x._M_start_of_storage._M_data,
      __x._M_finish);
  }
  v4 = *(_DWORD *)(a2 + 192);
  v5 = *(_DWORD *)(a2 + 196);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__x);
  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'(&__is);
  return (unsigned int)(v4 - v5) < 0x400;
}
