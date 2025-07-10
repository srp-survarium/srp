void __usercall vostok::buffer_vector<vostok::render::stage *>::resize(
        vostok::buffer_vector<vostok::render::stage *> *this@<ecx>,
        int *a2@<edi>)
{
  int v2; // ecx
  unsigned int v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ecx
  _DWORD *v6; // edx
  _DWORD *i; // eax

  v2 = *a2;
  v3 = (a2[1] - *a2) >> 2;
  if ( v3 != 29 )
  {
    if ( v3 <= 0x1D )
    {
      v4 = (_DWORD *)(v2 + 116);
      v5 = (_DWORD *)(v2 + 4 * v3);
      if ( v5 != v4 )
      {
        v6 = v5 + 1;
        do
        {
          for ( i = v5; i != v6; ++i )
          {
            if ( i )
              *i = 0;
          }
          ++v5;
          ++v6;
        }
        while ( v5 != v4 );
      }
      a2[1] = *a2 + 116;
    }
    else
    {
      a2[1] = v2 + 116;
    }
  }
}
