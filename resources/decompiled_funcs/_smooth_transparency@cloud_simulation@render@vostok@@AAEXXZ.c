void __usercall vostok::render::cloud_simulation::smooth_transparency(
        vostok::render::cloud_simulation *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ebp
  unsigned int v3; // edx
  unsigned int v4; // ebx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  int v7; // esi
  float x; // xmm0_4
  unsigned int v9; // ecx
  unsigned int z; // [esp+4h] [ebp-10h]
  unsigned int v11; // [esp+8h] [ebp-Ch]
  vostok::render::cloud_simulation::voxel v; // [esp+Ch] [ebp-8h]

  v2 = 0;
  for ( z = 0; v2 < a2[24]; z = v2 )
  {
    v3 = 0;
    if ( a2[22] )
    {
      v4 = a2[23];
      v5 = v4 - 1;
      do
      {
        v6 = 1;
        if ( v5 > 1 )
        {
          do
          {
            v7 = a2[20];
            v11 = v6 + v2 * v4;
            v = *(vostok::render::cloud_simulation::voxel *)(v7 + 4 * (v3 + v11 * a2[22]));
            x = (float)v.x;
            if ( v3 - 1 < a2[22] && v6 < v4 && z < a2[24] && !*(_BYTE *)(v7 + 4 * (v3 + v11 * a2[22]) - 4) )
              x = x * 0.64999998;
            v9 = a2[22];
            if ( v3 + 1 >= v9 || v6 >= v4 )
            {
              v2 = z;
            }
            else
            {
              v2 = z;
              if ( z < a2[24] && !*(_BYTE *)(v7 + 4 * (v3 + v11 * v9) + 4) )
                x = x * 0.64999998;
            }
            if ( v3 < a2[22] )
            {
              if ( v6 - 1 < v4 && v2 < a2[24] && !*(_BYTE *)(v7 + 4 * (v3 + a2[22] * (v11 - 1))) )
                x = x * 0.64999998;
              if ( v3 < a2[22] )
              {
                if ( v6 + 1 < v4 && v2 < a2[24] && !*(_BYTE *)(v7 + 4 * (v3 + a2[22] * (v11 + 1))) )
                  x = x * 0.64999998;
                if ( v3 < a2[22] )
                {
                  if ( v6 < v4 && v2 - 1 < a2[24] && !*(_BYTE *)(v7 + 4 * (v3 + a2[22] * (v6 + v4 * (v2 - 1)))) )
                    x = x * 0.64999998;
                  if ( v3 < a2[22]
                    && v6 < v4
                    && v2 + 1 < a2[24]
                    && !*(_BYTE *)(v7 + 4 * (v3 + a2[22] * (v6 + v4 * (v2 + 1)))) )
                  {
                    x = x * 0.64999998;
                  }
                }
              }
            }
            if ( x > 0.0 )
            {
              if ( x > 255.0 )
                x = 255.0;
            }
            else
            {
              x = 0.0;
            }
            v.x = (int)x;
            *(vostok::render::cloud_simulation::voxel *)(v7 + 4 * (v3 + v11 * a2[22])) = v;
            v4 = a2[23];
            ++v6;
            v5 = v4 - 1;
          }
          while ( v6 < v4 - 1 );
        }
        ++v3;
      }
      while ( v3 < a2[22] );
    }
    ++v2;
  }
}
