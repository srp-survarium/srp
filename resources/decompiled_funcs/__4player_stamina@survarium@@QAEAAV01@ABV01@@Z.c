survarium::player_stamina *__thiscall survarium::player_stamina::operator=(
        survarium::player_stamina *this,
        const survarium::player_stamina *other)
{
  if ( this != other )
  {
    this->m_max_value = other->m_max_value;
    this->m_value = other->m_value;
    this->m_spending_speed = other->m_spending_speed;
    this->m_regeneration_speed = other->m_regeneration_speed;
    this->m_max_value_factor = other->m_max_value_factor;
    this->m_spending_speed_factor = other->m_spending_speed_factor;
    this->m_last_tick_time_in_ms = other->m_last_tick_time_in_ms;
    this->m_spending_threshold = other->m_spending_threshold;
    this->m_regeneration_speed_factor = other->m_regeneration_speed_factor;
    this->m_regeneration_threshold = other->m_regeneration_threshold;
    this->m_last_spending_time_in_ms = other->m_last_spending_time_in_ms;
    this->m_lower_threshold_was_reached = other->m_lower_threshold_was_reached;
  }
  return this;
}
