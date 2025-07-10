char __thiscall survarium::bullet::update_bullet_position(
        survarium::bullet *this,
        float time,
        const vostok::math::float3 *gravity)
{
  vostok::math::float3 *v4; // eax
  vostok::math::float3_pod *v5; // ecx
  const vostok::math::float3 *v6; // edx
  survarium::game_camera *y_low; // ecx
  float value; // [esp+20h] [ebp-2Ch] BYREF
  vostok::math::float3 v10; // [esp+24h] [ebp-28h] BYREF
  vostok::math::float3 v11; // [esp+30h] [ebp-1Ch] BYREF
  const vostok::math::float3 *new_position; // [esp+3Ch] [ebp-10h]
  vostok::math::float3 result; // [esp+40h] [ebp-Ch] BYREF

  survarium::bullet::compute_trajectory_position(this, &result, time, gravity);
  new_position = &result;
  if ( !survarium::bullet_manager::is_inside_collision_db(this->m_bullet_manager, &result) )
    return 0;
  v4 = vostok::math::operator-(&this->m_position, new_position, &v11);
  this->m_flown_distance = vostok::math::float3_pod::length(v5, &v4->x) + this->m_flown_distance;
  if ( this->m_flown_distance < this->m_max_distance )
  {
    this->m_velocity = *survarium::bullet::compute_trajectory_velocity(this, &v10, this->m_life_time, gravity);
    value = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&this->m_velocity);
    if ( vostok::math::is_zero<float>(&value, &epsilon_5_84) )
    {
      return 0;
    }
    else
    {
      v6 = new_position;
      this->m_position.x = new_position->x;
      y_low = (survarium::game_camera *)LODWORD(v6->y);
      LODWORD(this->m_position.y) = y_low;
      this->m_position.z = v6->z;
      survarium::weapon_user_dead_state::finalize(y_low);
      this->m_life_time = time;
      return 1;
    }
  }
  else
  {
    this->m_flown_distance = this->m_max_distance;
    return 0;
  }
}
