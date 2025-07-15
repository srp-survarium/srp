vostok::fixed_string<128> *__usercall vostok::fs_new::file_open_flags_to_string@<eax>(
        vostok::fixed_string<128> *a1@<eax>,
        vostok::fixed_string<128> *result,
        const vostok::fs_new::file_mode::mode_enum mode)
{
  char *v3; // edx
  char *v4; // edx

  a1->m_begin = a1->m_buffer;
  a1->m_end = a1->m_buffer;
  a1->m_max_end = (char *)&a1[1];
  a1->m_buffer[0] = 0;
  a1->m_buffer[0] = 0;
  if ( result )
  {
    if ( result == (vostok::fixed_string<128> *)1 )
    {
      v3 = "open_existing";
    }
    else
    {
      if ( result != (vostok::fixed_string<128> *)2 )
        goto LABEL_8;
      v3 = "append_or_create";
    }
  }
  else
  {
    v3 = "create_always";
  }
  a1 = (vostok::fixed_string<128> *)vostok::buffer_string::operator+=(a1, v3);
LABEL_8:
  switch ( mode )
  {
    case create_always:
      v4 = "+write";
      return (vostok::fixed_string<128> *)vostok::buffer_string::operator+=(a1, v4);
    case open_existing:
      v4 = "+read";
      return (vostok::fixed_string<128> *)vostok::buffer_string::operator+=(a1, v4);
    case append_or_create:
      v4 = "+read_write";
      return (vostok::fixed_string<128> *)vostok::buffer_string::operator+=(a1, v4);
  }
  return a1;
}
