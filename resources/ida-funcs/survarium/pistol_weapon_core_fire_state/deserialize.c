void __thiscall survarium::pistol_weapon_core_fire_state::deserialize(
        survarium::pistol_weapon_core_fire_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  unsigned __int8 client_reader_3; // [esp+1Fh] [ebp+Fh]

  survarium::weapon_core_fire_state_base::deserialize(this, reader, client_reader);
  client_reader_3 = *reader->m_pointer++;
  this->m_weapon_animation_index = client_reader_3;
}
