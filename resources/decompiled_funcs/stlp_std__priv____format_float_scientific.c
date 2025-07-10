unsigned int __usercall stlp_std::priv::__format_float_scientific@<eax>(
        stlp_std::priv::__basic_iostring<char> *buf@<esi>,
        const char *bp@<ecx>,
        int decpt,
        int sign,
        bool is_zero,
        unsigned int flags,
        int precision)
{
  int v8; // eax
  unsigned int size; // eax
  char v10; // bl
  int v11; // eax
  unsigned int v12; // eax
  char *M_finish; // eax
  stlp_std::priv::__basic_iostring<char> *M_data; // ecx
  const char *v15; // edi
  char *v16; // ecx
  unsigned int v17; // eax
  char i; // bl
  stlp_std::priv::__basic_iostring<char> *v20; // edx
  char *v21; // ecx
  unsigned int v22; // eax
  int *v23; // ecx
  unsigned int v24; // ecx
  char *v25; // edi
  int v26; // ebx
  char v27; // al
  char *v28; // edi
  int v30; // [esp+Ch] [ebp-18h] BYREF
  unsigned int __group_pos; // [esp+10h] [ebp-14h]
  unsigned int v32; // [esp+14h] [ebp-10h] BYREF
  char expbuf[8]; // [esp+18h] [ebp-Ch] BYREF

  if ( sign )
  {
    if ( (stlp_std::priv::__basic_iostring<char> *)buf->_M_start_of_storage._M_data == buf )
      v8 = (char *)buf - buf->_M_finish + 16;
    else
      v8 = buf->_M_buffers._M_end_of_storage - buf->_M_finish;
    if ( v8 == 1 )
    {
      size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
               buf,
               1u);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        buf,
        size);
    }
    buf->_M_finish[1] = 0;
    *buf->_M_finish++ = 45;
  }
  else if ( (flags & 0x800) != 0 )
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::operator+=(
      buf,
      43);
  }
  v10 = *bp;
  if ( (stlp_std::priv::__basic_iostring<char> *)buf->_M_start_of_storage._M_data == buf )
    v11 = (char *)buf - buf->_M_finish + 16;
  else
    v11 = buf->_M_buffers._M_end_of_storage - buf->_M_finish;
  if ( v11 == 1 )
  {
    v12 = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
            buf,
            1u);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
      buf,
      v12);
  }
  buf->_M_finish[1] = 0;
  *buf->_M_finish++ = v10;
  M_finish = buf->_M_finish;
  M_data = (stlp_std::priv::__basic_iostring<char> *)buf->_M_start_of_storage._M_data;
  v15 = bp + 1;
  __group_pos = M_finish - (char *)M_data;
  if ( precision || (flags & 0x400) != 0 )
  {
    if ( M_data == buf )
      v16 = (char *)((char *)buf - M_finish + 16);
    else
      v16 = (char *)(buf->_M_buffers._M_end_of_storage - M_finish);
    if ( v16 == (char *)1 )
    {
      v17 = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
              buf,
              1u);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        buf,
        v17);
    }
    buf->_M_finish[1] = 0;
    *buf->_M_finish++ = 46;
    M_finish = buf->_M_finish;
  }
  for ( i = *v15; i; ++v15 )
  {
    if ( !precision-- )
      break;
    v20 = (stlp_std::priv::__basic_iostring<char> *)buf->_M_start_of_storage._M_data;
    if ( v20 == buf )
      v21 = (char *)((char *)buf - M_finish + 16);
    else
      v21 = (char *)(buf->_M_buffers._M_end_of_storage - M_finish);
    if ( v21 == (char *)1 )
    {
      v22 = M_finish - (char *)v20;
      v30 = 1;
      v32 = v22;
      if ( -2 == v22 )
        stlp_std::__stl_throw_length_error("basic_string");
      v23 = (int *)&v32;
      if ( v22 <= 1 )
        v23 = &v30;
      v24 = *v23 + v22 + 1;
      if ( v24 == -1 || v24 < v22 )
        v24 = -2;
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        buf,
        v24);
    }
    buf->_M_finish[1] = 0;
    *buf->_M_finish++ = i;
    i = v15[1];
    M_finish = buf->_M_finish;
  }
  if ( precision > 0 )
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::append(
      buf,
      precision,
      48);
  v25 = &expbuf[5];
  expbuf[5] = 0;
  if ( is_zero )
    goto LABEL_53;
  v26 = decpt - 1;
  if ( decpt - 1 < 0 )
    v26 = 1 - decpt;
  for ( ; v26 > 9; v26 /= 10 )
    *--v25 = v26 % 10 + 48;
  *--v25 = v26 + 48;
  if ( v25 > &expbuf[3] )
  {
LABEL_53:
    do
      *--v25 = 48;
    while ( v25 > &expbuf[3] );
  }
  if ( decpt > 0 || (v27 = 45, is_zero) )
    v27 = 43;
  v28 = v25 - 1;
  *v28-- = v27;
  *v28 = ~(unsigned __int8)(flags >> 9) & 0x20 | 0x45;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_append(
    buf,
    v28,
    &v28[strlen(v28)]);
  return __group_pos;
}
