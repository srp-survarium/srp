bool __thiscall survarium::player_stamina::can_be_spent(survarium::player_stamina *this)
{
  return this->m_spending_threshold < this->m_value || !this->m_lower_threshold_was_reached;
}
