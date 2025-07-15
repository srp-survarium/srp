char __usercall vostok::render::remove_model_if_shadow_not_it_frustum_predicate::operator()@<al>(
        vostok::render::remove_model_if_shadow_not_it_frustum_predicate *this@<ecx>,
        vostok::render::render_surface_instance *in_model@<eax>)
{
  float z; // xmm1_4
  vostok::math::frustum *m_frustum; // esi
  vostok::math::float3 *v6; // edi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  unsigned int v11; // edx
  float v12; // xmm6_4
  float *v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm2_4
  int v16; // xmm1_4
  unsigned int v18; // [esp+0h] [ebp-50h]
  vostok::math::aabb v19; // [esp+Ch] [ebp-44h] BYREF
  float v20; // [esp+2Ch] [ebp-24h]
  float v21; // [esp+30h] [ebp-20h]
  float v22; // [esp+34h] [ebp-1Ch]
  float v23; // [esp+38h] [ebp-18h]
  vostok::math::float3 v24; // [esp+3Ch] [ebp-14h] BYREF
  int v25; // [esp+48h] [ebp-8h]
  float v26; // [esp+4Ch] [ebp-4h]

  in_model->m_parent->get_aabb(in_model->m_parent, &v19);
  vostok::math::aabb::modify((vostok::math::aabb *)in_model->m_transform, &v19);
  v21 = this->m_sun_direction.x * 300.0;
  v22 = this->m_sun_direction.y * 300.0;
  z = this->m_sun_direction.z;
  m_frustum = this->m_frustum;
  v6 = 0;
  v23 = z * 300.0;
  while ( 2 )
  {
    vostok::math::aabb::vertex(&v19, &v24, v6, v18);
    v7 = (float)(v24.y + v22) - v24.y;
    v8 = (float)(v24.z + v23) - v24.z;
    v9 = (float)(v21 + v24.x) - v24.x;
    v10 = s_bm_current_air_resistance / fsqrt((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9));
    v11 = 0;
    v12 = v10 * v7;
    v20 = v10 * v8;
    v13 = (float *)m_frustum;
    do
    {
      v14 = (float)((float)((float)(v13[1] * v24.y) + (float)(v13[2] * v24.z)) + (float)(*v13 * v24.x)) + v13[3];
      v15 = (float)((float)(*v13 * (float)(v10 * v9)) + (float)(v13[1] * v12)) + (float)(v13[2] * v20);
      if ( v15 == 0.0 )
      {
        v26 = (float)((float)((float)(v13[1] * v24.y) + (float)(v13[2] * v24.z)) + (float)(*v13 * v24.x)) + v13[3];
        v25 = LODWORD(v14) & 0x7FFFFFFF;
        v16 = LODWORD(v14) & 0x7FFFFFFF;
      }
      else
      {
        *(float *)&v16 = v14 / v15;
      }
      if ( COERCE_FLOAT(v16 ^ _mask__NegFloat_) >= 0.0 )
        return 0;
      ++v11;
      v13 += 5;
    }
    while ( v11 < 6 );
    v6 = (vostok::math::float3 *)((char *)v6 + 1);
    if ( (unsigned int)v6 < 8 )
      continue;
    break;
  }
  ++vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_invisible_shadow_clipped_dips.value;
  return 1;
}
