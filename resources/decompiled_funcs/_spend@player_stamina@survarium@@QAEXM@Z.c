void __thiscall survarium::player_stamina::spend(survarium::player_stamina *this, float amount)
{
  survarium::player_stamina::decrease_value(this, amount);
  this->m_last_spending_time_in_ms = this->m_last_tick_time_in_ms;
}
