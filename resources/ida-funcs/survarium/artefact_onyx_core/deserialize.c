void __thiscall survarium::artefact_onyx_core::deserialize(
        survarium::artefact_onyx_core *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  survarium::artefact_onyx_core *v4; // esi
  survarium::inventory_item *v5; // ecx
  const unsigned __int8 *m_pointer; // eax
  unsigned int v7; // ecx
  const unsigned __int8 *v8; // esi
  float v9; // xmm0_4

  v4 = this;
  survarium::artefact_base::deserialize(this, reader, client_reader, time_offset);
  if ( v4->m_state == artefact_state_picked_active )
  {
    m_pointer = reader->m_pointer;
    v7 = *(_DWORD *)m_pointer;
    reader->m_pointer = m_pointer + 4;
    this->m_time_left_to_deactivate = v7;
    v8 = reader->m_pointer;
    v9 = *(float *)v8;
    v5 = (survarium::inventory_item *)(v8 + 4);
    reader->m_pointer = v8 + 4;
    this->m_damage_to_absorb = v9;
    v4 = this;
  }
  if ( survarium::inventory_item::is_holder_assigned(v5, (int)v4) )
  {
    if ( v4->m_inventory->m_holder->cast_to_base_player(v4->m_inventory->m_holder)->m_is_alive )
      v4->enable_passive_effects(v4);
  }
}
