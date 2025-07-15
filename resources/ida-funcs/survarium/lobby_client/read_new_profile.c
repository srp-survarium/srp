char __userpurge survarium::lobby_client::read_new_profile@<al>(
        vostok::network_core::buffer_reader *reader@<eax>,
        const vostok::network_core::tcp_packet *this)
{
  survarium::lobby_player_profile *v2; // ebx
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v4; // esi
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // esi
  survarium::game *m_first; // eax
  survarium::lobby_menu *v9; // ecx
  survarium::lobby_client *v10; // ecx
  survarium::lobby_client *v11; // ecx
  unsigned int v13; // [esp+Ch] [ebp-8h]
  unsigned int v14; // [esp+Ch] [ebp-8h]
  unsigned int v15; // [esp+Ch] [ebp-8h]
  unsigned int v16; // [esp+Ch] [ebp-8h]
  unsigned __int8 v17; // [esp+13h] [ebp-1h]

  v2 = (survarium::lobby_player_profile *)(&this[15].m_writer + 63 * LOBYTE(this[15].m_buffer.m_capacity));
  m_pointer = reader->m_pointer;
  v13 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  v2->profile_id = v13;
  v4 = reader->m_pointer;
  v17 = *v4;
  reader->m_pointer = v4 + 1;
  v2->skill_points_total = v17;
  v5 = reader->m_pointer;
  v14 = *(_DWORD *)v5;
  reader->m_pointer = v5 + 4;
  v2->current_exp = v14;
  v6 = reader->m_pointer;
  v15 = *(_DWORD *)v6;
  reader->m_pointer = v6 + 4;
  v2->prev_level_exp = v15;
  v7 = reader->m_pointer;
  v16 = *(_DWORD *)v7;
  reader->m_pointer = v7 + 4;
  v2->next_level_exp = v16;
  vostok::network_core::buffer_reader::r_string(
    (vostok::network_core::buffer_reader *)v2->profile_name,
    (char *)reader,
    (unsigned __int8 *)v2->profile_name);
  m_first = (survarium::game *)this[1].m_writer.serialization_operations_descriptors.m_first;
  ++LOBYTE(this[15].m_buffer.m_capacity);
  survarium::lobby_menu::fill_profiles(v9, (int)m_first->m_lobby_menu);
  survarium::lobby_client::query_profile_contents(v10, this, v2->profile_id);
  survarium::lobby_client::query_client_status(v11, this, 5u);
  return 1;
}
