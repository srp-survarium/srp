int __usercall vostok::render::get_num_digits@<eax>(char *v@<eax>)
{
  unsigned int v1; // esi
  int v2; // edi
  unsigned int v3; // ecx

  v1 = (unsigned int)v;
  if ( v )
  {
    if ( v > &stru_984D24.m_working_macro_list.m_buffer[33].m_store[300] )
      v1 = (unsigned int)&stru_984D24.m_working_macro_list.m_buffer[33].m_store[300];
  }
  else
  {
    v1 = 0;
  }
  v2 = 0;
  v3 = 1;
  if ( v1 )
  {
    do
    {
      if ( v3 >= (unsigned int)&off_F4240 )
        break;
      v3 *= 10;
      ++v2;
    }
    while ( v1 / v3 );
  }
  return v2;
}
