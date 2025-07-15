// bad sp value at call has been detected, the output may be wrong!
char __userpurge survarium::bullet::update_bullet_position@<al>(
        survarium::bullet *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        float a5@<xmm0>,
        survarium::bullet *time,
        const vostok::math::float3 *gravity,
        float a8)
{
  float *v8; // eax
  survarium::bullet *v9; // ecx
  const survarium::weapon_ammunition *m_weapon_ammunition; // eax
  float v12; // xmm0_4
  float m_distance; // xmm1_4
  float m_max_damage_speed; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float bullet_pierce; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm6_4
  bool m_is_melee; // cl
  float min_damage_amount; // xmm0_4
  const survarium::weapon_ammunition *v22; // eax
  float v23; // xmm5_4
  float bullet_damage; // xmm1_4
  float v25; // xmm2_4
  float m_damage; // xmm0_4
  float m_pierce; // xmm0_4
  _BYTE v28[12]; // [esp+14h] [ebp-24h] BYREF
  vostok::math::float3 v29; // [esp+20h] [ebp-18h] BYREF
  vostok::math::float3 v30; // [esp+2Ch] [ebp-Ch] BYREF

  survarium::bullet::compute_trajectory_position(time, this, &v30, a5, *(float *)&gravity);
  v8 = (float *)((int (__thiscall *)(vostok::physics::world *, _BYTE *, int, int, int))time->m_bullet_manager->m_physics_world->get_world_aabb)(
                  time->m_bullet_manager->m_physics_world,
                  v28,
                  a3,
                  a4,
                  a2);
  if ( v30.x < *v8 || v30.y < v8[1] || v30.z < v8[2] || v8[3] < v30.x || v8[4] < v30.y || v8[5] < v30.z )
    return 0;
  m_weapon_ammunition = time->m_weapon_ammunition;
  v12 = fsqrt(
          (float)((float)((float)(v30.z - time->m_position.z) * (float)(v30.z - time->m_position.z))
                + (float)((float)(v30.y - time->m_position.y) * (float)(v30.y - time->m_position.y)))
        + (float)((float)(v30.x - time->m_position.x) * (float)(v30.x - time->m_position.x)))
      + time->m_flown_distance;
  time->m_flown_distance = v12;
  m_distance = m_weapon_ammunition->m_distance;
  if ( v12 >= m_distance )
  {
    time->m_flown_distance = m_distance;
    return 0;
  }
  time->m_velocity = *survarium::bullet::compute_trajectory_velocity(time, v9, &v29, v12, *(float *)&gravity);
  if ( fabs(
         (float)((float)(time->m_velocity.x * time->m_velocity.x) + (float)(time->m_velocity.y * time->m_velocity.y))
       + (float)(time->m_velocity.z * time->m_velocity.z)) < 0.0000099999997 )
    return 0;
  m_max_damage_speed = time->m_max_damage_speed;
  *(_QWORD *)&time->m_position.x = *(_QWORD *)&v30.x;
  LODWORD(time->m_life_time) = gravity;
  time->m_position.z = v30.z;
  v15 = time->m_min_damage_speed - m_max_damage_speed;
  v16 = fsqrt(
          (float)((float)(time->m_velocity.x * time->m_velocity.x) + (float)(time->m_velocity.z * time->m_velocity.z))
        + (float)(time->m_velocity.y * time->m_velocity.y))
      - m_max_damage_speed;
  bullet_pierce = s_bm_current_air_resistance;
  v18 = v16 / v15;
  if ( v18 > 0.0 )
  {
    if ( s_bm_current_air_resistance < v18 )
      v19 = s_bm_current_air_resistance;
    else
      v19 = v18;
  }
  else
  {
    v19 = 0.0;
  }
  m_is_melee = time->m_is_melee;
  if ( m_is_melee )
    min_damage_amount = s_bm_current_air_resistance;
  else
    min_damage_amount = time->m_weapon->m_damage_params.min_damage_amount;
  v22 = time->m_weapon_ammunition;
  v23 = v22->m_min_damage_amount * min_damage_amount;
  if ( m_is_melee )
    bullet_damage = s_bm_current_air_resistance;
  else
    bullet_damage = time->m_weapon->m_damage_params.bullet_damage;
  v25 = s_bm_current_air_resistance - v19;
  m_damage = (float)((float)((float)(v22->m_damage * bullet_damage)
                           - (float)((float)(v22->m_damage * bullet_damage) * v23))
                   * (float)(s_bm_current_air_resistance - v19))
           + (float)((float)(v22->m_damage * bullet_damage) * v23);
  if ( m_damage > time->m_damage )
    m_damage = time->m_damage;
  time->m_damage = m_damage;
  if ( !m_is_melee )
    bullet_pierce = time->m_weapon->m_damage_params.bullet_pierce;
  m_pierce = (float)((float)((float)(v22->m_pierce * bullet_pierce)
                           - (float)((float)(v22->m_pierce * bullet_pierce) * v23))
                   * v25)
           + (float)((float)(v22->m_pierce * bullet_pierce) * v23);
  if ( m_pierce > time->m_pierce )
    m_pierce = time->m_pierce;
  time->m_pierce = m_pierce;
  return 1;
}
