void __thiscall survarium::player_stamina::regenerate(survarium::player_stamina *this, unsigned int current_time_in_ms)
{
  float time_delta_in_sec; // [esp+10h] [ebp-4h]

  if ( this->m_last_tick_time_in_ms )
  {
    time_delta_in_sec = (double)(current_time_in_ms - this->m_last_tick_time_in_ms) / 1000.0;
    survarium::player_stamina::increase_value(
      this,
      (float)(time_delta_in_sec * this->m_regeneration_speed) * this->m_regeneration_speed_factor);
  }
}
