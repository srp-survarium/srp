unsigned __int8 __thiscall survarium::lobby_client::read_profile(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  const unsigned __int8 *m_pointer; // esi
  unsigned __int8 result; // al
  survarium::player_profile *m_buffer_size; // ecx
  const unsigned __int8 **p_m_pointer; // [esp+Ch] [ebp-8h]
  survarium::player_profile *v8; // [esp+10h] [ebp-4h]
  const unsigned __int8 *v9; // [esp+20h] [ebp+Ch]
  unsigned __int8 v10; // [esp+23h] [ebp+Fh]

  m_pointer = a3->m_pointer;
  result = -1;
  v8 = *(survarium::player_profile **)m_pointer;
  a3->m_pointer = m_pointer + 4;
  v10 = 0;
  while ( 1 )
  {
    m_buffer_size = (survarium::player_profile *)reader[126 * v10 + 51].m_buffer_size;
    p_m_pointer = &reader[126 * v10 + 51].m_pointer;
    if ( m_buffer_size == v8 )
      break;
    if ( ++v10 >= 8u )
      return result;
  }
  survarium::player_profile::deserialize_static(
    m_buffer_size,
    (vostok::network_core::buffer_reader *)&reader[126 * v10 + 51].m_pointer,
    a3);
  reader[126 * v10 + 88].m_buffer = 0;
  result = v10;
  v9 = *(const unsigned __int8 **)a3->m_pointer;
  a3->m_pointer += 4;
  p_m_pointer[375] = v9;
  return result;
}
