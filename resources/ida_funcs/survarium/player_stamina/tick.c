void __thiscall survarium::player_stamina::tick(
        survarium::player_stamina *this,
        unsigned int current_time_in_ms,
        bool is_sprinting)
{
  if ( is_sprinting )
    survarium::player_stamina::sprint(this, current_time_in_ms);
  if ( (float)(this->m_max_value * this->m_max_value_factor) > this->m_value
    && (this->m_value == 0.0
     || this->m_last_spending_time_in_ms && this->m_last_spending_time_in_ms + 1000 < current_time_in_ms) )
  {
    survarium::player_stamina::regenerate(this, current_time_in_ms);
  }
  this->m_last_tick_time_in_ms = current_time_in_ms;
}
