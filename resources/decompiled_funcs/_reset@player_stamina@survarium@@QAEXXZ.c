void __thiscall survarium::player_stamina::reset(survarium::player_stamina *this)
{
  this->m_value = this->m_max_value * this->m_max_value_factor;
  this->m_lower_threshold_was_reached = 0;
  this->m_last_spending_time_in_ms = 0;
}
