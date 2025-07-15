void __thiscall survarium::booby_trap_set_core::action(
        survarium::booby_trap_set_core *this,
        bool key_down,
        unsigned int current_time_in_ms)
{
  unsigned __int16 *p_m_amount; // esi
  survarium::inventory_item *v5; // ecx

  p_m_amount = &this->m_amount;
  if ( this->m_amount && !key_down )
  {
    if ( survarium::booby_trap_set_core::try_to_place_trap(this, (int)this) )
    {
      v5 = (survarium::inventory_item *)*p_m_amount;
      LOWORD(v5) = (_WORD)v5 - 1;
      survarium::inventory_item::set_amount(v5, (int)this);
    }
  }
}
