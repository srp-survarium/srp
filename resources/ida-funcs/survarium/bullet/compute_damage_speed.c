void __usercall survarium::bullet::compute_damage_speed(survarium::bullet *this@<ecx>, survarium::bullet *a2@<esi>)
{
  bool m_is_melee; // cl
  float max_damage_distance; // xmm1_4
  const survarium::weapon_ammunition *m_weapon_ammunition; // eax
  float min_damage_distance; // xmm6_4
  float v6; // xmm2_4
  float m_air_resistance; // xmm4_4
  float v8; // xmm7_4
  float m_min_damage_distance; // xmm5_4
  survarium::bullet_manager *m_bullet_manager; // eax
  vostok::math::float3 *v11; // eax
  const vostok::math::float3 *v12; // edx
  vostok::math::float3 *v13; // eax
  float time; // [esp+0h] [ebp-18h]
  vostok::math::float3 v15; // [esp+4h] [ebp-14h] BYREF
  float v16; // [esp+10h] [ebp-8h]
  float v17; // [esp+14h] [ebp-4h]

  m_is_melee = a2->m_is_melee;
  if ( m_is_melee )
    max_damage_distance = s_bm_current_air_resistance;
  else
    max_damage_distance = a2->m_weapon->m_damage_params.max_damage_distance;
  m_weapon_ammunition = a2->m_weapon_ammunition;
  if ( m_is_melee )
    min_damage_distance = s_bm_current_air_resistance;
  else
    min_damage_distance = a2->m_weapon->m_damage_params.min_damage_distance;
  v6 = fsqrt(
         (float)((float)(a2->m_start_velocity.y * a2->m_start_velocity.y)
               + (float)(a2->m_start_velocity.z * a2->m_start_velocity.z))
       + (float)(a2->m_start_velocity.x * a2->m_start_velocity.x));
  m_air_resistance = a2->m_air_resistance;
  v8 = s_bm_current_air_resistance
     - fsqrt(
         s_bm_current_air_resistance
       - (float)((float)((float)(m_air_resistance
                               * (float)(m_weapon_ammunition->m_max_damage_distance * max_damage_distance))
                       * 2.0)
               * (float)(s_bm_current_air_resistance / v6)));
  m_min_damage_distance = m_weapon_ammunition->m_min_damage_distance;
  m_bullet_manager = a2->m_bullet_manager;
  v17 = v8 * (float)(s_bm_current_air_resistance / m_air_resistance);
  v16 = (float)(s_bm_current_air_resistance
              - fsqrt(
                  s_bm_current_air_resistance
                - (float)((float)((float)((float)(m_min_damage_distance * min_damage_distance) * m_air_resistance) * 2.0)
                        * (float)(s_bm_current_air_resistance / v6))))
      * (float)(s_bm_current_air_resistance / m_air_resistance);
  v11 = survarium::bullet::compute_parabolic_velocity(&m_bullet_manager->m_gravity, &v15, a2, v17);
  time = v16;
  a2->m_max_damage_speed = fsqrt((float)((float)(v11->y * v11->y) + (float)(v11->z * v11->z)) + (float)(v11->x * v11->x));
  v13 = survarium::bullet::compute_parabolic_velocity(v12, &v15, a2, time);
  a2->m_min_damage_speed = fsqrt((float)((float)(v13->y * v13->y) + (float)(v13->z * v13->z)) + (float)(v13->x * v13->x));
}
