void __usercall vostok::render::cloud_simulation::fill_default_volume(
        vostok::render::cloud_simulation *this@<ecx>,
        int *a2@<esi>)
{
  unsigned int i; // ebp
  unsigned int v3; // edx
  unsigned int v4; // ecx
  unsigned int j; // eax

  memset(a2[20], 0, 4 * a2[24] * a2[22] * a2[23]);
  for ( i = 0; i < a2[24]; ++i )
  {
    v3 = 0;
    if ( a2[22] )
    {
      v4 = a2[23];
      do
      {
        for ( j = 0; j < v4; ++j )
        {
          *(_DWORD *)(a2[20] + 4 * (v3 + a2[22] * (j + i * v4))) = 0;
          v4 = a2[23];
        }
        ++v3;
      }
      while ( v3 < a2[22] );
    }
  }
}
