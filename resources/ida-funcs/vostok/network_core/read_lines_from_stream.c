void __cdecl vostok::network_core::read_lines_from_stream(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *prefix)
{
  stlp_std::basic_istream<char,stlp_std::char_traits<char> > *v1; // eax
  stlp_std::basic_istream<char,stlp_std::char_traits<char> > __is; // [esp+8h] [ebp-8Ch] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __s; // [esp+78h] [ebp-1Ch] BYREF

  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::basic_istream<char,stlp_std::char_traits<char>>(
    &__is,
    prefix,
    1);
  __s._M_finish = (char *)&__s;
  __s._M_start_of_storage._M_data = (char *)&__s;
  __s._M_buffers._M_static_buf[0] = 0;
  do
    v1 = stlp_std::getline<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(&__is, &__s, 10);
  while ( ((*(_DWORD *)&v1->gap0[*(_DWORD *)(*(_DWORD *)v1->gap0 + 4) + 12] & 5) == 0
         ? (unsigned int)&v1->gap0[*(_DWORD *)(*(_DWORD *)v1->gap0 + 4)]
         : 0) != 0
       && !stlp_std::operator==<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(&__s, "\r") );
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__s);
  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'(&__is);
}
