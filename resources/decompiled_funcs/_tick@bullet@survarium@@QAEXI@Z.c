void __thiscall survarium::bullet::tick(survarium::bullet *this, unsigned int current_time_in_ms)
{
  survarium::game_camera *v2; // ecx
  vostok::math::float3_pod *v3; // ecx
  const vostok::math::float3_pod *v4; // eax
  vostok::math::float3_pod *v5; // ecx
  float v6; // xmm0_4
  survarium::game_camera *v7; // ecx
  __int128 _FFFFFFF8; // [esp-8h] [ebp-A4h]
  vostok::math::float3 v10; // [esp+50h] [ebp-4Ch] BYREF
  char v11; // [esp+5Fh] [ebp-3Dh]
  vostok::math::float3 d; // [esp+60h] [ebp-3Ch] BYREF
  float d_len; // [esp+6Ch] [ebp-30h]
  float speed; // [esp+70h] [ebp-2Ch]
  float length; // [esp+74h] [ebp-28h]
  survarium::collision_result result; // [esp+78h] [ebp-24h]
  float time; // [esp+7Ch] [ebp-20h] BYREF
  unsigned __int16 invalid_tracer_idx; // [esp+80h] [ebp-1Ch]
  float high_time; // [esp+84h] [ebp-18h] BYREF
  float low_time; // [esp+88h] [ebp-14h]
  const vostok::math::float3 *gravity; // [esp+8Ch] [ebp-10h]
  vostok::math::float3 zero_velocity; // [esp+90h] [ebp-Ch] BYREF

  this->m_current_time_in_ms = current_time_in_ms;
  vostok::math::float3::float3(&zero_velocity, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  invalid_tracer_idx = -1;
  low_time = this->m_life_time;
  high_time = (double)(current_time_in_ms - this->m_born_time_in_ms) / 1000.0 * survarium::s_bm_bullet_time_factor;
  v11 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  gravity = &this->m_bullet_manager->m_gravity;
  while ( 1 )
  {
    if ( vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&this->m_velocity) < 1.0 )
    {
      this->m_start_velocity = zero_velocity;
      return;
    }
    if ( this->m_change_trajectory_count >= 0x20 )
    {
      this->m_start_velocity = zero_velocity;
      return;
    }
    if ( low_time == high_time )
      return;
    time = survarium::bullet::pick_next_permissible_time(this, low_time, high_time, gravity);
    if ( low_time == time )
    {
      this->m_start_velocity = zero_velocity;
      return;
    }
    *((float *)&_FFFFFFF8 + 3) = low_time;
    *(_QWORD *)&_FFFFFFF8 = *(_QWORD *)&this->m_position.x;
    DWORD2(_FFFFFFF8) = LODWORD(this->m_position.z);
    result = survarium::bullet::check_collision(this, _FFFFFFF8, time);
    if ( result == collision_result_collide )
    {
      this->m_start_velocity = zero_velocity;
      return;
    }
    if ( result == collision_result_pierced || result == collision_result_reflected )
    {
      low_time = this->m_life_time;
      high_time = high_time - time;
      time = this->m_life_time;
    }
    if ( time != 0.0 && !survarium::bullet::update_bullet_position(this, time, gravity) )
    {
      this->m_start_velocity = zero_velocity;
      return;
    }
    if ( vostok::math::is_similar<float>(&time, &high_time, 0.0000099999997) )
      break;
    survarium::weapon_user_dead_state::finalize(v2);
    low_time = time;
    survarium::weapon_user_dead_state::finalize(v7);
  }
  if ( this->m_tracer_idx != 0xFFFF )
  {
    vostok::math::operator-(&this->m_start_position, &this->m_position, &d);
    d_len = vostok::math::float3_pod::length(v3, &d.x);
    vostok::math::float3::float3(&v10, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 1.0);
    vostok::math::float3_pod::normalize_safe(&d, v4);
    speed = vostok::math::float3_pod::length(v5, &this->m_velocity.x);
    v6 = g_bullet_tracer_exposition;
    vostok::math::min();
    length = v6 * speed;
    if ( this->m_initiator->is_local
      && !this->m_change_trajectory_count
      && g_bullet_tracer_exposition > this->m_life_time )
    {
      length = length - 5.0;
    }
    if ( this->m_change_trajectory_count && length > d_len )
      length = d_len;
    if ( length > 0.0 )
      survarium::bullet_manager::update_tracer(this->m_bullet_manager, this, &this->m_position, &d, length);
  }
}
