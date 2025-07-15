unsigned int __usercall stlp_std::priv::__format_float_fixed@<eax>(
        stlp_std::priv::__basic_iostring<char> *buf@<esi>,
        char *bp,
        int decpt,
        unsigned int sign,
        __int16 flags,
        int precision)
{
  int v6; // eax
  unsigned int size; // eax
  int v8; // edi
  char v9; // al
  char v10; // bl
  stlp_std::priv::__basic_iostring<char> *M_data; // edx
  char *M_finish; // eax
  char *v13; // ecx
  unsigned int v14; // eax
  int *p_sign; // ecx
  unsigned int v16; // ecx
  char *v17; // eax
  stlp_std::priv::__basic_iostring<char> *v18; // ecx
  char *v19; // ecx
  unsigned int v20; // eax
  const char *v21; // edi
  char i; // cl
  char v23; // bl
  stlp_std::priv::__basic_iostring<char> *v24; // edx
  char *v25; // ecx
  unsigned int v26; // eax
  int *v27; // ecx
  unsigned int v28; // ecx
  int v30; // [esp+Ch] [ebp-8h] BYREF
  unsigned int __group_pos; // [esp+10h] [ebp-4h]

  if ( sign && decpt > -precision && *bp )
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::operator+=(
      buf,
      45);
  }
  else if ( (flags & 0x800) != 0 )
  {
    if ( (stlp_std::priv::__basic_iostring<char> *)buf->_M_start_of_storage._M_data == buf )
      v6 = (char *)buf - buf->_M_finish + 16;
    else
      v6 = buf->_M_buffers._M_end_of_storage - buf->_M_finish;
    if ( v6 == 1 )
    {
      size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
               buf,
               1u);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        buf,
        size);
    }
    buf->_M_finish[1] = 0;
    *buf->_M_finish++ = 43;
  }
  v8 = decpt;
  if ( decpt <= 0 )
    goto LABEL_15;
  do
  {
    v9 = *bp;
    if ( *bp )
    {
      ++bp;
      v10 = v9;
    }
    else
    {
LABEL_15:
      v10 = 48;
    }
    M_data = (stlp_std::priv::__basic_iostring<char> *)buf->_M_start_of_storage._M_data;
    M_finish = buf->_M_finish;
    if ( M_data == buf )
      v13 = (char *)((char *)buf - M_finish + 16);
    else
      v13 = (char *)(buf->_M_buffers._M_end_of_storage - M_finish);
    if ( v13 == (char *)1 )
    {
      v14 = M_finish - (char *)M_data;
      v30 = 1;
      sign = v14;
      if ( -2 == v14 )
LABEL_32:
        stlp_std::__stl_throw_length_error("basic_string");
      p_sign = (int *)&sign;
      if ( v14 <= 1 )
        p_sign = &v30;
      v16 = *p_sign + v14 + 1;
      if ( v16 == -1 || v16 < v14 )
        v16 = -2;
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        buf,
        v16);
    }
    buf->_M_finish[1] = 0;
    *buf->_M_finish++ = v10;
    v17 = buf->_M_finish;
    --v8;
  }
  while ( v8 > 0 );
  v18 = (stlp_std::priv::__basic_iostring<char> *)buf->_M_start_of_storage._M_data;
  __group_pos = v17 - (char *)v18;
  if ( (flags & 0x400) != 0 || precision > 0 )
  {
    if ( v18 == buf )
      v19 = (char *)((char *)buf - v17 + 16);
    else
      v19 = (char *)(buf->_M_buffers._M_end_of_storage - v17);
    if ( v19 == (char *)1 )
    {
      v20 = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
              buf,
              1u);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        buf,
        v20);
    }
    buf->_M_finish[1] = 0;
    *buf->_M_finish++ = 46;
    v17 = buf->_M_finish;
  }
  v21 = bp;
  for ( i = *bp; *v21; v17 = buf->_M_finish )
  {
    if ( --precision < 0 )
      break;
    if ( ++decpt > 0 )
    {
      v23 = i;
      ++v21;
    }
    else
    {
      v23 = 48;
    }
    v24 = (stlp_std::priv::__basic_iostring<char> *)buf->_M_start_of_storage._M_data;
    if ( v24 == buf )
      v25 = (char *)((char *)buf - v17 + 16);
    else
      v25 = (char *)(buf->_M_buffers._M_end_of_storage - v17);
    if ( v25 == (char *)1 )
    {
      v26 = v17 - (char *)v24;
      v30 = 1;
      sign = v26;
      if ( -2 == v26 )
        goto LABEL_32;
      v27 = (int *)&sign;
      if ( v26 <= 1 )
        v27 = &v30;
      v28 = *v27 + v26 + 1;
      if ( v28 == -1 || v28 < v26 )
        v28 = -2;
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        buf,
        v28);
    }
    buf->_M_finish[1] = 0;
    *buf->_M_finish++ = v23;
    i = *v21;
  }
  if ( precision > 0 )
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::append(
      buf,
      precision,
      48);
  return __group_pos;
}
