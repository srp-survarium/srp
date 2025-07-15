bool __userpurge survarium::base_game_scene::point_to_screen@<al>(
        vostok::math::float2 *result@<edi>,
        survarium::base_game_scene *this,
        const vostok::math::float3 *p)
{
  vostok::math::uint2 *p_m_current_size; // esi
  unsigned int x; // ebx
  float z; // xmm6_4
  float y; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  double v13; // st7
  float v14; // xmm0_4
  int v15; // eax
  double v16; // st6
  float v17; // xmm1_4
  bool v18; // cc
  float v19; // xmm0_4
  unsigned int *v20; // ecx
  bool v21; // al
  float v22; // xmm1_4
  vostok::math::float4x4 v23; // [esp+8h] [ebp-98h] BYREF
  vostok::math::float4x4 v24; // [esp+48h] [ebp-58h] BYREF
  float v25; // [esp+88h] [ebp-18h]
  float v26; // [esp+8Ch] [ebp-14h]
  int v27; // [esp+98h] [ebp-8h]
  unsigned int *p_y; // [esp+9Ch] [ebp-4h]
  float v29; // [esp+A8h] [ebp+8h]
  float v30; // [esp+A8h] [ebp+8h]
  float v31; // [esp+A8h] [ebp+8h]
  float v32; // [esp+ACh] [ebp+Ch]

  p_m_current_size = &this->m_game->m_render_output_window.m_object->m_current_size;
  x = p_m_current_size->x;
  p_y = &this->m_game->m_render_output_window.m_object->m_current_size.y;
  v27 = *p_y >> 1;
  vostok::math::float4x4::try_invert(&this->m_inverted_view_matrix, &v23);
  vostok::math::mul4x4(&this->m_projection_matrix, &v23, &v24);
  z = p->z;
  y = p->y;
  v7 = (float)((float)((float)(v24.k.x * z) + (float)(v24.i.x * p->x)) + (float)(v24.j.x * y)) + v24.c.x;
  v8 = (float)((float)((float)(v24.k.y * z) + (float)(v24.i.y * p->x)) + (float)(v24.j.y * y)) + v24.c.y;
  v9 = (float)((float)((float)(v24.k.z * z) + (float)(v24.i.z * p->x)) + (float)(v24.j.z * y)) + v24.c.z;
  v10 = v24.j.w * y;
  v11 = s_bm_current_air_resistance;
  v12 = s_bm_current_air_resistance
      / (float)((float)((float)((float)(v24.k.w * z) + (float)(v24.i.w * p->x)) + v10) + v24.c.w);
  v25 = v12 * v7;
  v13 = (float)(v12 * v7) + 1.0;
  v26 = v12 * v8;
  v14 = v12 * v9;
  v15 = v27;
  v29 = v13 * (double)(x >> 1);
  result->x = v29;
  v16 = (double)v27;
  if ( v15 < 0 )
    v16 = v16 + 4294967300.0;
  v17 = v13 * (double)(x >> 1);
  v18 = v11 <= v14;
  v19 = 0.0;
  v32 = (1.0 - v26) * v16;
  result->y = v32;
  if ( v18 || v29 <= 0.0 || v32 <= 0.0 || (double)p_m_current_size->x <= v29 )
  {
    v20 = p_y;
  }
  else
  {
    v20 = p_y;
    if ( (double)*p_y > v32 )
    {
      v21 = 1;
      goto LABEL_11;
    }
  }
  v21 = 0;
LABEL_11:
  if ( v32 >= 0.0 )
  {
    if ( v29 > 0.0 )
    {
      v31 = (float)p_m_current_size->x;
      if ( v31 < v17 )
        v17 = (float)p_m_current_size->x;
    }
    else
    {
      v17 = 0.0;
    }
    result->x = v17;
    v22 = result->y;
    if ( v22 > 0.0 )
    {
      v19 = (float)*v20;
      if ( v19 >= v22 )
        v19 = result->y;
    }
    result->y = v19;
  }
  else
  {
    result->y = (float)*v20;
    if ( v29 <= 0.0 || (v19 = (float)p_m_current_size->x, v19 < v17) )
      v30 = v19;
    else
      v30 = v13 * (double)(x >> 1);
    result->x = v30;
    result->x = (double)p_m_current_size->x - v30;
  }
  return v21;
}
