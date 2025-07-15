void __userpurge vostok::animation::hand_to_weapon_ik_solver::deserialize(
        vostok::animation::hand_to_weapon_ik_solver *this@<ecx>,
        vostok::network_core::buffer_reader *reader@<eax>,
        const unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // esi
  const unsigned __int8 *v9; // esi
  unsigned __int8 v10; // [esp+Fh] [ebp-1h]
  int v11; // [esp+18h] [ebp+8h]
  int v12; // [esp+18h] [ebp+8h]

  m_pointer = reader->m_pointer;
  v10 = *m_pointer;
  reader->m_pointer = ++m_pointer;
  v11 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_hands[0].start_transition_time_in_ms = v11 != 0 ? time_offset + v11 : 0;
  v5 = reader->m_pointer;
  HIBYTE(v11) = *v5;
  reader->m_pointer = v5 + 1;
  this->m_hands[0].locator_id = HIBYTE(v11);
  v6 = reader->m_pointer;
  HIBYTE(v11) = *v6;
  reader->m_pointer = v6 + 1;
  this->m_hands[0].previous_locator_id = HIBYTE(v11);
  v7 = reader->m_pointer;
  v12 = *(_DWORD *)v7;
  reader->m_pointer = v7 + 4;
  this->m_hands[1].start_transition_time_in_ms = v12 != 0 ? time_offset + v12 : 0;
  v8 = reader->m_pointer;
  HIBYTE(v12) = *v8;
  reader->m_pointer = v8 + 1;
  this->m_hands[1].locator_id = HIBYTE(v12);
  v9 = reader->m_pointer;
  HIBYTE(v12) = *v9;
  reader->m_pointer = v9 + 1;
  this->m_hands[1].previous_locator_id = HIBYTE(v12);
  this->m_hands[0].is_active = v10 & 1;
  this->m_hands[1].is_active = (v10 & 2) != 0;
}
