char __thiscall survarium::bullet::try_reflect(
        survarium::bullet *this,
        survarium::bullet *ray_result,
        const vostok::math::float3 *direction,
        float *a4)
{
  const survarium::weapon_ammunition *m_weapon_ammunition; // eax
  const survarium::game_material *m_collided_material; // ecx
  survarium::bullet_manager *m_bullet_manager; // ecx
  float v8; // xmm2_4
  float v9; // xmm1_4
  __m128i v10; // xmm0
  float v11; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  vostok::math::float4x4 *v15; // eax
  float v16; // xmm1_4
  float v17; // xmm1_4
  survarium::bullet_manager *v18; // ecx
  float m_ricochet_dispersion_angle; // xmm1_4
  const survarium::game_material *v20; // eax
  __m128i m_ricochet_dispersion_koef_low; // xmm0
  vostok::math::float4x4 *v22; // eax
  float v23; // xmm3_4
  unsigned int v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  const survarium::weapon_ammunition *v29; // eax
  const survarium::weapon_core *m_weapon; // ecx
  float v31; // xmm1_4
  float m_damage; // xmm0_4
  float m_pierce; // xmm0_4
  float v34; // [esp+0h] [ebp-94h]
  float v35; // [esp+0h] [ebp-94h]
  float v36; // [esp+4h] [ebp-90h]
  float v37; // [esp+1Ch] [ebp-78h]
  float v38; // [esp+1Ch] [ebp-78h]
  float v39; // [esp+20h] [ebp-74h]
  float m_ricochet_chance_koef; // [esp+24h] [ebp-70h]
  float m_ricochet_chance; // [esp+28h] [ebp-6Ch]
  float v42; // [esp+2Ch] [ebp-68h]
  vostok::math::float3 v43; // [esp+30h] [ebp-64h] BYREF
  float v44; // [esp+3Ch] [ebp-58h] BYREF
  float v45; // [esp+40h] [ebp-54h]
  float v46; // [esp+44h] [ebp-50h]
  vostok::math::float3 v47; // [esp+48h] [ebp-4Ch] BYREF
  _BYTE v48[64]; // [esp+54h] [ebp-40h] BYREF

  if ( ray_result->m_ricochet_count >= 2u )
    return 0;
  v42 = (float)((float)(direction[1].z * a4[1]) + (float)(direction[2].x * a4[2])) + (float)(direction[1].y * *a4);
  __libm_sse2_acos();
  m_weapon_ammunition = ray_result->m_weapon_ammunition;
  m_collided_material = ray_result->m_collided_material;
  v39 = v42 - 1.5707964;
  v37 = (float)(m_weapon_ammunition->m_ricochet_angle * m_collided_material->m_ricochet_koef) >= 1.5707964
      ? pi_d2_11
      : m_weapon_ammunition->m_ricochet_angle * m_collided_material->m_ricochet_koef;
  if ( (float)(v42 - 1.5707964) > v37 )
    return 0;
  m_ricochet_chance = m_weapon_ammunition->m_ricochet_chance;
  m_ricochet_chance_koef = m_collided_material->m_ricochet_chance_koef;
  v38 = 1.0 / v37;
  if ( (1.0 - m_ricochet_chance_koef * m_ricochet_chance) * v38 * v39 >= vostok::math::random32::random_f(
                                                                           &ray_result->m_bullet_manager->m_random,
                                                                           1.0) )
    return 0;
  m_bullet_manager = ray_result->m_bullet_manager;
  v8 = (float)(direction[2].x * 2.0) * COERCE_FLOAT(LODWORD(v42) ^ _mask__NegFloat_);
  v9 = *a4 + (float)((float)(direction[1].y * 2.0) * COERCE_FLOAT(LODWORD(v42) ^ _mask__NegFloat_));
  v10 = (__m128i)*((unsigned int *)a4 + 2);
  v43.y = (float)((float)(direction[1].z * 2.0) * COERCE_FLOAT(LODWORD(v42) ^ _mask__NegFloat_)) + a4[1];
  *(float *)v10.m128i_i32 = *(float *)v10.m128i_i32 + v8;
  v11 = (float)(v43.y * 0.0) - *(float *)v10.m128i_i32;
  LODWORD(v43.z) = v10.m128i_i32[0];
  v12 = v9 * 0.0;
  v43.x = v9;
  v13 = v9 - (float)(v43.y * 0.0);
  *(float *)v10.m128i_i32 = (float)(*(float *)v10.m128i_i32 * 0.0) - v12;
  v14 = s_bm_current_air_resistance
      / fsqrt((float)((float)(v11 * v11) + (float)(v13 * v13)) + (float)(*(float *)v10.m128i_i32
                                                                       * *(float *)v10.m128i_i32));
  *(float *)v10.m128i_i32 = *(float *)v10.m128i_i32 * v14;
  v44 = v11 * v14;
  v45 = *(float *)v10.m128i_i32;
  v46 = v13 * v14;
  v34 = vostok::math::random32::random_f(&m_bullet_manager->m_random, 6.2831855);
  v15 = vostok::math::create_rotation(&v43, (int)v48, v10, v34);
  v16 = v15->i.y * v44;
  v47.x = (float)((float)(v15->j.x * v45) + (float)(v15->k.x * v46)) + (float)(v15->i.x * v44);
  *(float *)v10.m128i_i32 = (float)((float)(v15->j.y * v45) + v16) + (float)(v15->k.y * v46);
  v17 = v15->i.z * v44;
  LODWORD(v47.y) = v10.m128i_i32[0];
  v18 = ray_result->m_bullet_manager;
  *(float *)v10.m128i_i32 = (float)((float)(v15->j.z * v45) + v17) + (float)(v15->k.z * v46);
  m_ricochet_dispersion_angle = ray_result->m_weapon_ammunition->m_ricochet_dispersion_angle;
  v20 = ray_result->m_collided_material;
  LODWORD(v47.z) = v10.m128i_i32[0];
  m_ricochet_dispersion_koef_low = (__m128i)LODWORD(v20->m_ricochet_dispersion_koef);
  *(float *)m_ricochet_dispersion_koef_low.m128i_i32 = *(float *)m_ricochet_dispersion_koef_low.m128i_i32
                                                     * m_ricochet_dispersion_angle;
  v35 = vostok::math::random32::random_f(&v18->m_random, *(const float *)m_ricochet_dispersion_koef_low.m128i_i32);
  v22 = vostok::math::create_rotation(&v47, (int)v48, m_ricochet_dispersion_koef_low, v35);
  v23 = fsqrt(
          (float)((float)(ray_result->m_velocity.x * ray_result->m_velocity.x)
                + (float)(ray_result->m_velocity.z * ray_result->m_velocity.z))
        + (float)(ray_result->m_velocity.y * ray_result->m_velocity.y))
      * (float)(s_bm_current_air_resistance
              - (float)((float)(ray_result->m_collided_material->m_bullet_reflection_speed_down * v38) * v39));
  *(float *)m_ricochet_dispersion_koef_low.m128i_i32 = (float)((float)((float)(v22->k.x * v43.z)
                                                                     + (float)(v22->j.x * v43.y))
                                                             + (float)(v22->i.x * v43.x))
                                                     * v23;
  *(float *)&v24 = (float)((float)((float)(v22->i.y * v43.x) + (float)(v22->k.y * v43.z)) + (float)(v22->j.y * v43.y))
                 * v23;
  v25 = (float)((float)((float)(v22->i.z * v43.x) + (float)(v22->k.z * v43.z)) + (float)(v22->j.z * v43.y)) * v23;
  v26 = a4[2];
  *(_QWORD *)&v47.x = __PAIR64__(v24, m_ricochet_dispersion_koef_low.m128i_u32[0]);
  v27 = *a4;
  v47.z = v25;
  v28 = a4[1] * 0.001;
  v44 = direction->y - (float)(v27 * 0.001);
  v45 = direction->z - v28;
  v46 = direction[1].x - (float)(v26 * 0.001);
  survarium::bullet::change_trajectory((survarium::bullet *)&v44, ray_result->m_life_time, ray_result, &v47, v36);
  ++ray_result->m_ricochet_count;
  v29 = ray_result->m_weapon_ammunition;
  m_weapon = ray_result->m_weapon;
  v31 = v29->m_min_damage_amount * m_weapon->m_damage_params.min_damage_amount;
  m_damage = (float)(v29->m_damage * m_weapon->m_damage_params.bullet_damage) * v31;
  if ( m_damage > ray_result->m_damage )
    m_damage = ray_result->m_damage;
  ray_result->m_damage = m_damage;
  m_pierce = (float)(v29->m_pierce * m_weapon->m_damage_params.bullet_pierce) * v31;
  if ( m_pierce > ray_result->m_pierce )
    m_pierce = ray_result->m_pierce;
  ray_result->m_pierce = m_pierce;
  return 1;
}
