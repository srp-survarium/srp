void __thiscall survarium::player_stamina::sprint(survarium::player_stamina *this, unsigned int current_time_in_ms)
{
  float time_delta_in_sec; // [esp+10h] [ebp-4h]

  time_delta_in_sec = (double)(current_time_in_ms - this->m_last_tick_time_in_ms) / 1000.0;
  survarium::player_stamina::decrease_value(
    this,
    (float)(this->m_spending_speed * this->m_spending_speed_factor) * time_delta_in_sec);
  this->m_last_spending_time_in_ms = current_time_in_ms;
}
