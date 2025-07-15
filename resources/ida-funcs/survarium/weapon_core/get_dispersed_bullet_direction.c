// local variable allocation has failed, the output may be wrong!
vostok::math::float3 *__userpurge survarium::weapon_core::get_dispersed_bullet_direction@<eax>(
        survarium::weapon_core *this@<ecx>,
        int a2@<eax>,
        float a3@<xmm0>,
        vostok::math::float3 *result,
        const vostok::math::float4x4 *fire_bullet_transform)
{
  survarium::weapon_core *v6; // ecx
  __m128i v7; // xmm0
  vostok::math::float4x4 *rotation; // eax
  float y; // xmm1_4
  __m128i z_low; // xmm0
  float x; // xmm2_4
  float v12; // xmm4_4
  vostok::math::float4x4 *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v18; // [esp+4h] [ebp-64h]
  float v19; // [esp+4h] [ebp-64h]
  _BYTE v20[64]; // [esp+14h] [ebp-54h] BYREF
  vostok::math::float3 v21; // [esp+54h] [ebp-14h] BYREF
  float dispersion_amount; // [esp+60h] [ebp-8h]
  int v23; // [esp+64h] [ebp-4h]

  v18 = s_dispersion_bullet_sigma_value;
  survarium::weapon_core::get_dispersion(this, a2);
  dispersion_amount = survarium::weapon_core::get_dispersion_amount(
                        v6,
                        (boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647> *)a2,
                        a3,
                        v18);
  v7.m128i_i32[0] = boost::random::uniform_real_distribution<float>::operator()<boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647>>(
                      (boost::random::uniform_real_distribution<float> *)(a2 + 1064),
                      (boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647> *)(a2 + 1060));
  v23 = v7.m128i_i32[0];
  rotation = vostok::math::create_rotation(
               (const vostok::math::float3 *)&fire_bullet_transform->lines[2],
               (int)v20,
               v7,
               *(float *)v7.m128i_i32);
  y = fire_bullet_transform->i.y;
  z_low = (__m128i)LODWORD(fire_bullet_transform->i.z);
  x = fire_bullet_transform->i.x;
  v19 = dispersion_amount * 0.0055555557 * 3.1415927;
  v12 = rotation->j.y;
  v21.x = (float)((float)(rotation->j.x * y) + (float)(rotation->k.x * *(float *)z_low.m128i_i32))
        + (float)(rotation->i.x * fire_bullet_transform->i.x);
  v21.y = (float)((float)(rotation->i.y * x) + (float)(v12 * y)) + (float)(rotation->k.y * *(float *)z_low.m128i_i32);
  v21.z = (float)((float)(rotation->i.z * x) + (float)(rotation->j.z * y))
        + (float)(rotation->k.z * *(float *)z_low.m128i_i32);
  v13 = vostok::math::create_rotation(&v21, (int)v20, z_low, v19);
  z_low.m128i_i32[0] = LODWORD(fire_bullet_transform->k.z);
  v14 = fire_bullet_transform->k.y;
  v15 = fire_bullet_transform->k.x;
  v16 = v13->j.y;
  result->x = (float)((float)(v13->j.x * v14) + (float)(v13->k.x * *(float *)z_low.m128i_i32)) + (float)(v13->i.x * v15);
  result->y = (float)((float)(v13->i.y * v15) + (float)(v16 * v14)) + (float)(v13->k.y * *(float *)z_low.m128i_i32);
  result->z = (float)((float)(v13->i.z * v15) + (float)(v13->j.z * v14)) + (float)(v13->k.z * *(float *)z_low.m128i_i32);
  return result;
}
