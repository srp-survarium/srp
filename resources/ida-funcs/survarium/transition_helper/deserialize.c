void __userpurge survarium::transition_helper::deserialize(
        survarium::transition_helper *this@<ecx>,
        vostok::network_core::buffer_reader *reader@<eax>,
        const unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  float v4; // xmm0_4
  const unsigned __int8 *v5; // esi
  float v6; // xmm0_4
  const unsigned __int8 *v7; // esi
  float v8; // xmm0_4
  const unsigned __int8 *v9; // esi
  float v10; // xmm0_4
  unsigned int v11; // eax
  unsigned int v12; // [esp+8h] [ebp-4h]

  m_pointer = reader->m_pointer;
  v4 = *(float *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_current_value = v4;
  v5 = reader->m_pointer;
  v6 = *(float *)v5;
  reader->m_pointer = v5 + 4;
  this->m_start_value = v6;
  v7 = reader->m_pointer;
  v8 = *(float *)v7;
  reader->m_pointer = v7 + 4;
  this->m_target_value = v8;
  v9 = reader->m_pointer;
  v10 = *(float *)v9;
  reader->m_pointer = v9 + 4;
  this->m_transition_time = v10;
  v12 = *(_DWORD *)reader->m_pointer;
  reader->m_pointer += 4;
  v11 = v12;
  if ( v12 != -1 )
    v11 = time_offset + v12;
  this->m_start_transition_time_in_ms = v11;
}
