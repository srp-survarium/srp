void __thiscall survarium::inventory_item::deserialize(
        survarium::inventory_item *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        const unsigned int time_offset)
{
  survarium::inventory *m_object; // eax
  const unsigned __int8 *m_pointer; // esi
  survarium::profile_slot_enum v7; // eax
  unsigned __int8 v9; // [esp+1Ch] [ebp+8h]
  unsigned __int8 v10; // [esp+1Fh] [ebp+Bh]

  this->m_amount = vostok::network_core::buffer_reader::r<unsigned short>(reader);
  v9 = *reader->m_pointer++;
  if ( v9 == 0xFF )
    m_object = 0;
  else
    m_object = survarium::game_world_core::player(this->m_game_world_core, v9)->m_inventory.m_object;
  this->m_inventory = m_object;
  if ( m_object )
  {
    m_pointer = reader->m_pointer;
    v10 = *m_pointer;
    reader->m_pointer = m_pointer + 1;
    v7 = v10;
  }
  else
  {
    v7 = max_slots_count;
  }
  this->m_slot_id = v7;
}
