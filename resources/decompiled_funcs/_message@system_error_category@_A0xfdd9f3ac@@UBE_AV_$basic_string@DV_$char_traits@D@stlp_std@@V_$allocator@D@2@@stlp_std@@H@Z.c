stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__stdcall `anonymous namespace'::system_error_category::message(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *a1,
        DWORD dwMessageId)
{
  DWORD v2; // eax
  HLOCAL v3; // esi
  char *M_finish; // edx
  char *M_data; // ebp
  int v6; // eax
  char v7; // cl
  int v8; // ecx
  char *v9; // esi
  char *v10; // edi
  HLOCAL v12; // [esp-4h] [ebp-5Ch]
  stlp_std::allocator<char> __a; // [esp+17h] [ebp-41h] BYREF
  char Buffer[4]; // [esp+18h] [ebp-40h] BYREF
  int v15; // [esp+1Ch] [ebp-3Ch]
  int v16; // [esp+20h] [ebp-38h]
  HLOCAL hMem; // [esp+24h] [ebp-34h]
  int v18; // [esp+28h] [ebp-30h]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v19; // [esp+2Ch] [ebp-2Ch]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __s; // [esp+30h] [ebp-28h] BYREF
  int v21; // [esp+54h] [ebp-4h]

  v15 = 0;
  v19 = a1;
  *(_DWORD *)Buffer = 0;
  v2 = FormatMessageA(0x1300u, 0, dwMessageId, 0x400u, Buffer, 0, 0);
  v3 = *(HLOCAL *)Buffer;
  hMem = *(HLOCAL *)Buffer;
  v21 = 1;
  if ( v2 )
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      &__s,
      *(char **)Buffer,
      &__a);
    M_finish = __s._M_finish;
    M_data = __s._M_start_of_storage._M_data;
    v6 = __s._M_finish - __s._M_start_of_storage._M_data;
    for ( LOBYTE(v21) = 2; M_finish != M_data; v6 = M_finish - M_data )
    {
      v7 = *(M_finish - 1);
      if ( v7 != 10 && v7 != 13 )
        break;
      v8 = v6 - 1;
      v18 = -1;
      if ( !v6 )
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_throw_out_of_range(&__s);
      v16 = 1;
      v9 = &M_data[v6];
      v10 = &M_data[v8];
      if ( &M_data[v8] != &M_data[v6] )
      {
        if ( M_finish - v9 != -1 )
        {
          memmove((unsigned __int8 *)&M_data[v6 - 1], (unsigned __int8 *)&M_data[v6], M_finish - &M_data[v6 - 1]);
          M_data = __s._M_start_of_storage._M_data;
          M_finish = __s._M_finish;
        }
        M_finish += v10 - v9;
        __s._M_finish = M_finish;
      }
    }
    if ( M_finish != M_data && *(M_finish - 1) == 46 )
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::erase(
        &__s,
        M_finish - M_data - 1,
        0xFFFFFFFF);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      a1,
      &__s);
    v15 = 1;
    LOBYTE(v21) = 1;
    if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)__s._M_start_of_storage._M_data != &__s
      && __s._M_start_of_storage._M_data )
    {
      if ( (unsigned int)(__s._M_buffers._M_end_of_storage - __s._M_start_of_storage._M_data) <= 0x80 )
        stlp_std::__node_alloc::_M_deallocate(
          (_STLP_atomic_freelist::item *)__s._M_start_of_storage._M_data,
          __s._M_buffers._M_end_of_storage - __s._M_start_of_storage._M_data);
      else
        operator delete(__s._M_start_of_storage._M_data);
    }
    v12 = hMem;
  }
  else
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      a1,
      "Unknown error",
      &__a);
    v15 = 1;
    v12 = v3;
  }
  LOBYTE(v21) = 0;
  LocalFree(v12);
  return a1;
}
