char __userpurge vostok::render::shadow_cascade_volume::check_cull_plane_valid@<al>(
        vostok::render::shadow_cascade_volume *this@<ecx>,
        float **a2@<eax>,
        const vostok::math::plane *plane,
        float *sign,
        float mad_factor)
{
  float *v6; // esi
  char v7; // bl
  unsigned int v8; // edi
  unsigned int v9; // eax
  float *v10; // ecx
  float v11; // xmm0_4
  float orient; // [esp+0h] [ebp-20h]
  char valid; // [esp+24h] [ebp+4h]

  v6 = *a2;
  v7 = 0;
  v8 = 0;
  v9 = ((char *)a2[1] - (char *)*a2) / 24;
  valid = 0;
  orient = 0.0;
  if ( v9 )
  {
    v10 = v6;
    do
    {
      v11 = (float)((float)((float)(plane->normal.y * (float)(v10[4] + (float)(v10[1] * 5.0)))
                          + (float)(plane->normal.z * (float)(v10[5] + (float)(v10[2] * 5.0))))
                  + (float)(plane->normal.x * (float)((float)(*v10 * 5.0) + v10[3])))
          + plane->d;
      if ( fabs(v11) >= 0.001 )
      {
        if ( v7 )
        {
          if ( (v11 >= 0.0 || orient >= 0.0) && (v11 <= 0.0 || orient <= 0.0) )
          {
            valid = 0;
            break;
          }
        }
        else
        {
          if ( v11 <= 0.0 )
            orient = -1.0;
          else
            orient = *(float *)&clear_value;
          valid = 1;
          v7 = 1;
        }
      }
      ++v8;
      v10 += 6;
    }
    while ( v8 < v9 );
  }
  *sign = orient;
  return valid;
}
