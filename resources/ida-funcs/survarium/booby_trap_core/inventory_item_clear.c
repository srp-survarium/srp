void __thiscall survarium::booby_trap_core::inventory_item_clear(survarium::booby_trap_core *this)
{
  if ( this->m_trap_state )
    survarium::booby_trap_core::remove(this);
}
