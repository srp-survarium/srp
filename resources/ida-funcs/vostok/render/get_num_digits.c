int __usercall vostok::render::get_num_digits@<eax>(unsigned __int8 *v@<eax>)
{
  unsigned int v1; // esi
  int v2; // edi
  unsigned int v3; // ecx

  v1 = (unsigned int)v;
  if ( v )
  {
    if ( v > &vostok::memory::s_CRT_arena[613496] )
      v1 = (unsigned int)&vostok::memory::s_CRT_arena[613496];
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
      if ( v3 >= (unsigned int)&loc_F4240 )
        break;
      v3 *= 10;
      ++v2;
    }
    while ( v1 / v3 );
  }
  return v2;
}
