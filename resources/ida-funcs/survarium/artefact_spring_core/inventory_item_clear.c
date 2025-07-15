void __thiscall survarium::artefact_spring_core::inventory_item_clear(survarium::artefact_spring_core *this)
{
  survarium::artefact_spring_core *v2; // ecx
  survarium::artefact_spring_core *v3; // ecx

  if ( this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder)->m_is_alive )
  {
    survarium::artefact_spring_core::remove_passive_modifiers(v2, (int)this);
    if ( this->m_state == artefact_state_picked_active )
      survarium::artefact_spring_core::remove_active_modifiers(v3, (int)this);
  }
}
