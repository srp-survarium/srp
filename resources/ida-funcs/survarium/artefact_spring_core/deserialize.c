void __thiscall survarium::artefact_spring_core::deserialize(
        survarium::artefact_spring_core *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  survarium::inventory_item *v5; // ecx
  const unsigned __int8 *m_pointer; // eax
  survarium::artefact_spring_core *v7; // ecx
  survarium::artefact_spring_core *v8; // ecx
  unsigned int time_offseta; // [esp+18h] [ebp+10h]

  survarium::artefact_base::deserialize(this, reader, client_reader, time_offset);
  if ( this->m_state == artefact_state_picked_active )
  {
    m_pointer = reader->m_pointer;
    v5 = (survarium::inventory_item *)reader;
    time_offseta = *(_DWORD *)m_pointer;
    reader->m_pointer = m_pointer + 4;
    this->m_time_left_to_deactivate = time_offseta;
  }
  if ( survarium::inventory_item::is_holder_assigned(v5, (int)this)
    && this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder)->m_is_alive )
  {
    survarium::artefact_spring_core::add_passive_modifiers(v7, (int)this);
    if ( this->m_state == artefact_state_picked_active )
      survarium::artefact_spring_core::add_active_modifiers(v8, (int)this);
  }
}
