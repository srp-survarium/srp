void __thiscall survarium::oxygen_tank::deserialize(
        survarium::oxygen_tank *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  bool v6; // zf
  survarium::oxygen_tank::item_influence *v7; // edi
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v8; // eax
  survarium::damage_model *v9; // ecx
  vostok::network_core::buffer_reader *readera; // [esp+14h] [ebp+8h]
  vostok::network_core::buffer_reader *client_readerb; // [esp+18h] [ebp+Ch]
  vostok::network_core::buffer_reader *client_readera; // [esp+18h] [ebp+Ch]
  bool time_offset_3; // [esp+1Fh] [ebp+13h]

  survarium::inventory_item::deserialize(this, reader, client_reader, time_offset);
  time_offset_3 = this->m_active;
  this->m_active = vostok::network_core::buffer_reader::r<bool>(reader);
  m_pointer = reader->m_pointer;
  client_readerb = *(vostok::network_core::buffer_reader **)m_pointer;
  reader->m_pointer = m_pointer + 4;
  v6 = !this->m_active;
  this->m_amount_ms = (unsigned int)client_readerb;
  if ( !v6 )
  {
    client_readera = 0;
    if ( this->m_influences_count )
    {
      readera = 0;
      do
      {
        v7 = (survarium::oxygen_tank::item_influence *)((char *)readera + (unsigned int)this->m_influences);
        v8 = this->m_inventory->m_holder->damage_model(this->m_inventory->m_holder);
        survarium::damage_model::register_body_part_damage_protector(
          v8->m_object,
          (survarium::damage_protector *)((char *)readera + (unsigned int)this->m_influences),
          v9,
          v7->body_part_name);
        client_readera = (vostok::network_core::buffer_reader *)((char *)client_readera + 1);
        readera += 12;
      }
      while ( (unsigned int)client_readera < this->m_influences_count );
    }
  }
  if ( time_offset_3 )
  {
    if ( !this->m_active )
      survarium::game_world_core::unregister_tickable_object(this->m_game_world_core, &this->survarium::tickable_object);
  }
  else if ( this->m_active )
  {
    survarium::game_world_core::register_tickable_object(
      (survarium::game_world_core *)&this->survarium::tickable_object,
      (int)this->m_game_world_core);
  }
}
