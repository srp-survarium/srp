void __thiscall survarium::body_part_parameters::regenerate(
        survarium::body_part_parameters *this,
        unsigned int time_delta_ms,
        unsigned int current_time_in_ms)
{
  unsigned int next_regen_time; // [esp+14h] [ebp-10h]
  unsigned int regenerate_delta; // [esp+1Ch] [ebp-8h]
  float amount; // [esp+20h] [ebp-4h]

  regenerate_delta = time_delta_ms;
  if ( this->m_regeneration_timeout )
  {
    next_regen_time = this->m_regeneration_timeout + this->m_last_hit_time;
    if ( current_time_in_ms <= next_regen_time )
      return;
    regenerate_delta = vostok::math::min(current_time_in_ms - next_regen_time, time_delta_ms);
  }
  amount = (double)regenerate_delta * this->m_regeneration_speed / 1000.0;
  survarium::body_part_parameters::increase_health(this, amount);
  if ( this->m_damage_model->m_affects_applying_type == type_apply_directly )
    survarium::body_part_parameters::update_affects(this, current_time_in_ms);
}
