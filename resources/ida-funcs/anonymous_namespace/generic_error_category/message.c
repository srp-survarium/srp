stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__stdcall `anonymous namespace'::generic_error_category::message(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *a1,
        int errnum)
{
  int v2; // ebx
  char *v3; // eax
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v4; // eax
  int v5; // ebx
  stlp_std::allocator<char> v7; // [esp+Fh] [ebp-29h] BYREF
  unsigned int v8; // [esp+10h] [ebp-28h]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v9; // [esp+14h] [ebp-24h] BYREF
  int v10; // [esp+34h] [ebp-4h]

  v2 = 0;
  v8 = 0;
  if ( (dword_8E4C34 & 1) == 0 )
  {
    dword_8E4C34 |= 1u;
    v10 = 1;
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&dword_8E4C1C,
      "Unknown error",
      &v7);
    atexit(sub_69F460);
    LOBYTE(v10) = 0;
  }
  v3 = strerror(errnum);
  if ( v3 )
  {
    v8 = 1;
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      &v9,
      v3,
      (const stlp_std::allocator<char> *)&errnum);
    v2 = 3;
    v10 = 2;
    v8 = 3;
  }
  else
  {
    v4 = (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&dword_8E4C1C;
  }
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    a1,
    v4);
  v5 = v2 | 4;
  v10 = 0;
  if ( (v5 & 2) != 0 )
  {
    v8 = v5 & 0xFFFFFFFD;
    if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v9._M_start_of_storage._M_data != &v9 )
    {
      if ( v9._M_start_of_storage._M_data )
      {
        if ( (unsigned int)(v9._M_buffers._M_end_of_storage - v9._M_start_of_storage._M_data) <= 0x80 )
          stlp_std::__node_alloc::_M_deallocate(
            (_STLP_atomic_freelist::item *)v9._M_start_of_storage._M_data,
            v9._M_buffers._M_end_of_storage - v9._M_start_of_storage._M_data);
        else
          operator delete(v9._M_start_of_storage._M_data);
      }
    }
  }
  return a1;
}
