void __thiscall survarium::lobby_client::read_squad_member_profile(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *profile)
{
  survarium::player_profile **m_pointer; // esi
  survarium::player_profile *v5; // [esp+14h] [ebp+8h]
  survarium::player_profile *v6; // [esp+14h] [ebp+8h]

  m_pointer = (survarium::player_profile **)reader->m_pointer;
  v5 = *m_pointer;
  reader->m_pointer = (const unsigned __int8 *)(m_pointer + 1);
  profile->m_pointer = (const unsigned __int8 *)v5;
  survarium::player_profile::deserialize_static(v5, profile, reader);
  v6 = *(survarium::player_profile **)reader->m_pointer;
  reader->m_pointer += 4;
  profile[125].m_buffer = (const unsigned __int8 *)v6;
}
