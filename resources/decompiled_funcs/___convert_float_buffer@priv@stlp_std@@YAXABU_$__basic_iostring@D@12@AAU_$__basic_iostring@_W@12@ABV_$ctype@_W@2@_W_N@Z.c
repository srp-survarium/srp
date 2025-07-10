void __cdecl stlp_std::priv::__convert_float_buffer(
        const stlp_std::priv::__basic_iostring<char> *str,
        stlp_std::priv::__basic_iostring<wchar_t> *out,
        stlp_std::ctype<wchar_t> *ct,
        wchar_t dot,
        int __check_dot)
{
  char *M_finish; // ebx
  char *M_data; // edi
  stlp_std::ctype<wchar_t> *v7; // ebp
  stlp_std::priv::__basic_iostring<wchar_t> *v8; // esi
  wchar_t v9; // ax
  stlp_std::priv::__basic_iostring<wchar_t> *v10; // edx
  wchar_t v11; // bx
  wchar_t *v12; // eax
  int v13; // ecx
  unsigned int v14; // eax
  int *v15; // ecx
  unsigned int v16; // ecx
  _BYTE *v18; // edi
  wchar_t v19; // ax
  stlp_std::priv::__basic_iostring<wchar_t> *v20; // edx
  wchar_t v21; // bx
  wchar_t *v22; // eax
  int v23; // ecx
  unsigned int v24; // eax
  int *v25; // ecx
  unsigned int v26; // ecx
  int v27; // [esp+10h] [ebp-8h] BYREF
  int v28; // [esp+14h] [ebp-4h] BYREF
  const char *str_end; // [esp+1Ch] [ebp+4h]

  M_finish = str->_M_finish;
  M_data = str->_M_start_of_storage._M_data;
  str_end = M_finish;
  if ( (_BYTE)__check_dot )
  {
    if ( M_data == M_finish )
      return;
    v7 = ct;
    v8 = out;
    while ( *M_data != 46 )
    {
      LOBYTE(__check_dot) = *M_data;
      v9 = v7->do_widen(v7, __check_dot);
      v10 = (stlp_std::priv::__basic_iostring<wchar_t> *)out->_M_start_of_storage._M_data;
      v11 = v9;
      v12 = out->_M_finish;
      if ( v10 == out )
      {
        v13 = 16 - (((char *)v12 - (char *)out) >> 1);
        v7 = ct;
      }
      else
      {
        v13 = out->_M_buffers._M_end_of_storage - v12;
      }
      if ( v13 == 1 )
      {
        v28 = 1;
        v14 = ((char *)v12 - (char *)v10) >> 1;
        v27 = v14;
        if ( v14 == 2147483646 )
LABEL_19:
          stlp_std::__stl_throw_length_error("basic_string");
        v15 = &v27;
        if ( v14 <= 1 )
          v15 = &v28;
        v16 = v14 + *v15 + 1;
        if ( v16 > 0x7FFFFFFE || v16 < v14 )
          v16 = 2147483646;
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_reserve(
          out,
          v16);
      }
      out->_M_finish[1] = 0;
      *out->_M_finish++ = v11;
      if ( ++M_data == str_end )
        return;
      M_finish = (char *)str_end;
    }
  }
  else
  {
    if ( M_data == M_finish )
      return;
    v7 = ct;
    LOBYTE(__check_dot) = *M_data;
    dot = ct->do_widen(ct, __check_dot);
    v8 = out;
  }
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::push_back(
    v8,
    dot);
  if ( M_data != M_finish )
  {
    v18 = M_data + 1;
    if ( v18 != M_finish )
    {
      do
      {
        LOBYTE(__check_dot) = *v18;
        v19 = v7->do_widen(v7, __check_dot);
        v20 = (stlp_std::priv::__basic_iostring<wchar_t> *)v8->_M_start_of_storage._M_data;
        v21 = v19;
        v22 = v8->_M_finish;
        if ( v20 == v8 )
        {
          v23 = 16 - (((char *)v22 - (char *)v8) >> 1);
          v7 = ct;
        }
        else
        {
          v23 = v8->_M_buffers._M_end_of_storage - v22;
        }
        if ( v23 == 1 )
        {
          v27 = 1;
          v24 = ((char *)v22 - (char *)v20) >> 1;
          v28 = v24;
          if ( v24 == 2147483646 )
            goto LABEL_19;
          v25 = &v28;
          if ( v24 <= 1 )
            v25 = &v27;
          v26 = *v25 + v24 + 1;
          if ( v26 > 0x7FFFFFFE || v26 < v24 )
            v26 = 2147483646;
          stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_reserve(
            v8,
            v26);
        }
        v8->_M_finish[1] = 0;
        *v8->_M_finish++ = v21;
        ++v18;
      }
      while ( v18 != str_end );
    }
  }
}
