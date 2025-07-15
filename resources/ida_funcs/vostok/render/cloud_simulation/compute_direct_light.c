void __userpurge vostok::render::cloud_simulation::compute_direct_light(
        vostok::render::cloud_simulation *this@<ecx>,
        _DWORD *a2@<esi>,
        const vostok::render::cloud_key_parameters *sun_direction,
        const vostok::render::cloud_key_parameters *init_key)
{
  unsigned int v4; // eax
  unsigned int i; // ebp
  int v6; // ebx
  unsigned int v7; // edi
  long double v8; // st7
  float v9; // xmm0_4
  float v10; // [esp+8h] [ebp-28h]
  float extinction; // [esp+Ch] [ebp-24h]
  unsigned int x; // [esp+20h] [ebp-10h]
  unsigned int z; // [esp+24h] [ebp-Ch]
  vostok::render::cloud_simulation::voxel v; // [esp+28h] [ebp-8h]
  float v15; // [esp+2Ch] [ebp-4h]

  for ( z = 0; z < a2[24]; ++z )
  {
    x = 0;
    if ( a2[22] )
    {
      v4 = a2[23];
      do
      {
        for ( i = 0; i < v4; ++i )
        {
          v6 = a2[20];
          v7 = z * v4 + i;
          v = *(vostok::render::cloud_simulation::voxel *)(v6 + 4 * (x + v7 * a2[22]));
          extinction = sun_direction->extinction;
          v10 = powf((float)v.y * 0.0039215689, 16.0);
          v8 = powf(v10, extinction) * 4.0;
          if ( v8 > 0.0 )
          {
            v9 = v8;
            v15 = v8;
            if ( *(float *)&clear_value < v15 )
              v9 = *(float *)&clear_value;
          }
          else
          {
            v9 = 0.0;
          }
          v.z = (int)(float)(v9 * 255.0);
          *(vostok::render::cloud_simulation::voxel *)(v6 + 4 * (x + v7 * a2[22])) = v;
          v4 = a2[23];
        }
        ++x;
      }
      while ( x < a2[22] );
    }
  }
}
