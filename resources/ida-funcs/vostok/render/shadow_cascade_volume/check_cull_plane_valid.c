char __userpurge vostok::render::shadow_cascade_volume::check_cull_plane_valid@<al>(
        vostok::render::shadow_cascade_volume *this@<ecx>,
        int a2@<eax>,
        const vostok::math::plane *plane,
        float *sign,
        float mad_factor)
{
  float *v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm0_4
  float i; // [esp+28h] [ebp-8h]
  char v13; // [esp+2Eh] [ebp-2h]
  char v14; // [esp+2Fh] [ebp-1h]

  v6 = *(float **)a2;
  v7 = (*(_DWORD *)(a2 + 4) - *(_DWORD *)a2) / 24;
  v8 = 0;
  v14 = 0;
  v13 = 0;
  for ( i = 0.0; v8 < v7; v6 += 6 )
  {
    v9 = (float)((float)((float)(*(float *)&this->view_frustum_rays.m_end * (float)(v6[4] + (float)(v6[1] * 5.0)))
                       + (float)(*(float *)&this->view_frustum_rays.m_max_end * (float)(v6[5] + (float)(v6[2] * 5.0))))
               + (float)(*(float *)&this->view_frustum_rays.m_begin * (float)((float)(*v6 * 5.0) + v6[3])))
       + *(float *)this->view_frustum_rays.m_buffer[0].m_store;
    if ( fabs(v9) >= 0.001 )
    {
      if ( v13 )
      {
        if ( (v9 >= 0.0 || i >= 0.0) && (v9 <= 0.0 || i <= 0.0) )
        {
          v14 = 0;
          break;
        }
      }
      else
      {
        if ( v9 <= 0.0 )
          v10 = FLOAT_N1_0;
        else
          v10 = s_bm_current_air_resistance;
        i = v10;
        v14 = 1;
        v13 = 1;
      }
    }
    ++v8;
  }
  plane->normal.x = i;
  return v14;
}
