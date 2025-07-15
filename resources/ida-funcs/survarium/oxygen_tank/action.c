void __thiscall survarium::oxygen_tank::action(survarium::oxygen_tank *this, bool key_down)
{
  if ( key_down )
  {
    if ( this->m_amount_ms )
      survarium::oxygen_tank::set_active(this, !this->m_active);
  }
}
