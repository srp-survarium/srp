void __thiscall survarium::medkit::action(survarium::medkit *this, bool key_down, unsigned int current_time_in_ms)
{
  unsigned __int16 *p_m_amount; // esi
  survarium::inventory_item *v5; // ecx

  if ( key_down && !this->m_active )
  {
    p_m_amount = &this->m_amount;
    if ( this->m_amount )
    {
      survarium::medkit::set_active(this, 1, current_time_in_ms);
      v5 = (survarium::inventory_item *)*p_m_amount;
      LOWORD(v5) = (_WORD)v5 - 1;
      survarium::inventory_item::set_amount(v5, (int)this);
    }
  }
}
