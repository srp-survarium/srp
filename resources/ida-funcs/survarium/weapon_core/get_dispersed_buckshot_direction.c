vostok::math::float3 *__userpurge survarium::weapon_core::get_dispersed_buckshot_direction@<eax>(
        survarium::weapon_core *this@<ecx>,
        survarium::weapon_core *a2@<eax>,
        vostok::math::float3 *result,
        vostok::math::float3 *bullets_direction)
{
  __m128i m_buck_dispersion_low; // xmm0
  vostok::math::float3 *v6; // esi
  survarium::weapon_core *v7; // ecx
  vostok::math::float4x4 *rotation; // eax
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  __m128i z_low; // xmm0
  vostok::math::float4x4 *v13; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float v16; // xmm4_4
  vostok::math::float3 *v17; // eax
  float v18; // [esp+4h] [ebp-6Ch]
  float v19; // [esp+4h] [ebp-6Ch]
  _BYTE v20[64]; // [esp+14h] [ebp-5Ch] BYREF
  vostok::math::float3 v21; // [esp+54h] [ebp-1Ch] BYREF
  vostok::math::float3 v22; // [esp+60h] [ebp-10h] BYREF
  float dispersion_amount; // [esp+6Ch] [ebp-4h]

  m_buck_dispersion_low = (__m128i)LODWORD(a2->m_ammunition.m_object->m_buck_dispersion);
  if ( *(float *)m_buck_dispersion_low.m128i_i32 == 0.0 )
  {
    v6 = bullets_direction;
  }
  else
  {
    v18 = s_dispersion_buckshot_sigma_value;
    survarium::weapon_core::get_buck_dispersion(a2);
    dispersion_amount = survarium::weapon_core::get_dispersion_amount(
                          v7,
                          (boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647> *)a2,
                          *(const float *)m_buck_dispersion_low.m128i_i32,
                          v18);
    m_buck_dispersion_low.m128i_i32[0] = boost::random::uniform_real_distribution<float>::operator()<boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647>>(
                                           &a2->m_uniform_distribution,
                                           &a2->m_random_generator);
    survarium::arbitrary_right(bullets_direction, &v22);
    rotation = vostok::math::create_rotation(
                 bullets_direction,
                 (int)v20,
                 m_buck_dispersion_low,
                 *(float *)m_buck_dispersion_low.m128i_i32);
    v19 = dispersion_amount * 0.0055555557 * 3.1415927;
    v9 = rotation->j.y * v22.y;
    v21.x = (float)((float)(rotation->j.x * v22.y) + (float)(rotation->k.x * v22.z)) + (float)(v22.x * rotation->i.x);
    v10 = (float)((float)(rotation->i.y * v22.x) + v9) + (float)(rotation->k.y * v22.z);
    v11 = rotation->j.z * v22.y;
    v21.y = v10;
    z_low = (__m128i)LODWORD(rotation->i.z);
    *(float *)z_low.m128i_i32 = (float)((float)(*(float *)z_low.m128i_i32 * v22.x) + v11)
                              + (float)(rotation->k.z * v22.z);
    LODWORD(v21.z) = z_low.m128i_i32[0];
    v13 = vostok::math::create_rotation(&v21, (int)v20, z_low, v19);
    z_low.m128i_i32[0] = LODWORD(bullets_direction->z);
    y = bullets_direction->y;
    x = bullets_direction->x;
    v16 = v13->j.y;
    v21.x = (float)((float)(v13->j.x * y) + (float)(v13->k.x * *(float *)z_low.m128i_i32))
          + (float)(bullets_direction->x * v13->i.x);
    v21.y = (float)((float)(v13->i.y * x) + (float)(v16 * y)) + (float)(v13->k.y * *(float *)z_low.m128i_i32);
    v21.z = (float)((float)(v13->i.z * x) + (float)(v13->j.z * y)) + (float)(v13->k.z * *(float *)z_low.m128i_i32);
    v6 = &v21;
  }
  v17 = result;
  *result = *v6;
  return v17;
}
