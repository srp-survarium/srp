void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // esi
  vostok::math::float4_pod *p_j; // edi
  const vostok::math::float4x4 *v6; // eax
  float m_half_length; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  const vostok::math::float4x4 *v22; // eax
  float v23; // xmm0_4
  vostok::math::float4 *m_begin; // edx
  unsigned int v25; // eax
  unsigned int v26; // ecx
  float y; // [esp+Ch] [ebp-34h]
  float v28; // [esp+Ch] [ebp-34h]
  float z; // [esp+10h] [ebp-30h]
  float x; // [esp+10h] [ebp-30h]
  float v31; // [esp+14h] [ebp-2Ch]
  float closest_point; // [esp+18h] [ebp-28h]
  float v; // [esp+24h] [ebp-1Ch]
  float v_4; // [esp+28h] [ebp-18h]
  float v_8; // [esp+2Ch] [ebp-14h]

  p_c = &this->m_testee->get_matrix(this->m_testee)->c;
  p_j = &this->m_testee->get_matrix(this->m_testee)->j;
  v6 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  m_half_length = testee->m_half_length;
  v8 = p_c->x - (float)(p_j->x * m_half_length);
  y = p_c->y;
  v9 = y - (float)(p_j->y * m_half_length);
  z = p_c->z;
  v10 = z - (float)(p_j->z * m_half_length);
  v11 = y + (float)(p_j->y * m_half_length);
  v12 = z + (float)(p_j->z * m_half_length);
  v31 = v6->c.z;
  v28 = v6->c.y;
  v = (float)(p_c->x + (float)(p_j->x * m_half_length)) - v8;
  v13 = v11 - v9;
  x = v6->c.x;
  v14 = v12 - v10;
  v15 = (float)((float)((float)((float)(x - v8) * v) + (float)((float)(v31 - v10) * v14))
              + (float)((float)(v28 - v9) * v13))
      / (float)((float)((float)(v * v) + (float)(v14 * v14)) + (float)(v13 * v13));
  v16 = 0.0;
  if ( v15 > 0.0 )
  {
    v16 = *(float *)&clear_value;
    if ( *(float *)&clear_value >= v15 )
      v16 = (float)((float)((float)((float)(x - v8) * v) + (float)((float)(v31 - v10) * v14))
                  + (float)((float)(v28 - v9) * v13))
          / (float)((float)((float)(v * v) + (float)(v14 * v14)) + (float)(v13 * v13));
  }
  v17 = (float)(v14 * v16) + v10;
  v18 = v13 * v16;
  v19 = v16;
  v20 = bounding_volume->m_radius + testee->m_radius;
  closest_point = (float)(v19 * v) + v8;
  v21 = v18 + v9;
  if ( (float)((float)((float)((float)(closest_point - x) * (float)(closest_point - x))
                     + (float)((float)(v17 - v31) * (float)(v17 - v31)))
             + (float)((float)(v21 - v28) * (float)(v21 - v28))) <= (float)(v20 * v20) )
  {
    v22 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v23 = closest_point - v22->c.x;
    v22 = (const vostok::math::float4x4 *)((char *)v22 + 48);
    v_4 = v21 - v22->i.y;
    v_8 = v17 - v22->i.z;
    this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
    m_begin = bounding_volume->m_planes.m_begin;
    v25 = bounding_volume->m_planes.m_end - m_begin;
    v26 = 0;
    if ( v25 )
    {
      while ( (float)((float)((float)(m_begin->x * v23) + (float)(m_begin->z * v_8)) + (float)(m_begin->y * v_4)) <= (float)((float)(bounding_volume->m_radius * m_begin->w) + testee->m_radius) )
      {
        ++v26;
        ++m_begin;
        if ( v26 >= v25 )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      this->m_result = 1;
    }
  }
}
