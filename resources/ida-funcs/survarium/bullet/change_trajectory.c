void __thiscall survarium::bullet::change_trajectory(
        survarium::bullet *this,
        const vostok::math::float3 *new_position,
        const vostok::math::float3 *new_velocity,
        float collision_time)
{
  ++this->m_change_trajectory_count;
  this->m_start_position = *new_position;
  this->m_start_velocity = *new_velocity;
  this->m_position = this->m_start_position;
  this->m_velocity = this->m_start_velocity;
  this->m_current_resistance = this->m_air_resistance;
  this->m_born_time_in_ms += vostok::math::floor((float)(1000.0 * collision_time) / survarium::s_bm_bullet_time_factor);
  this->m_life_time = *(float *)&FLOAT_0_0;
}
