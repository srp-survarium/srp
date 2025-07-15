void __thiscall survarium::timelimit_rule_core::deserialize(
        survarium::timelimit_rule_core *this,
        vostok::network_core::buffer_reader *reader,
        const unsigned int time_offset)
{
  unsigned int v3; // esi
  const unsigned __int8 *v4; // edx
  unsigned int v5; // ebx
  unsigned int v6; // esi
  const unsigned __int8 *m_pointer; // esi
  unsigned int v8; // [esp+18h] [ebp+Ch]

  v3 = *(_DWORD *)reader->m_pointer;
  v4 = reader->m_pointer + 4;
  reader->m_pointer = v4;
  v5 = v3;
  if ( v3 != -1 )
    v5 = v3 + time_offset;
  v6 = *(_DWORD *)v4;
  reader->m_pointer = v4 + 4;
  this->m_current_time_in_ms = v6;
  if ( v6 != -1 )
    this->m_current_time_in_ms = time_offset + v6;
  m_pointer = reader->m_pointer;
  v8 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_players_mask = v8;
  HIBYTE(v8) = *reader->m_pointer++;
  this->m_state_start_time_ms = v5;
  this->m_current_state = HIBYTE(v8);
}
