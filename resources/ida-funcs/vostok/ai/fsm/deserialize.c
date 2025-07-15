void __userpurge vostok::ai::fsm::deserialize(
        vostok::ai::fsm *this@<eax>,
        vostok::network_core::buffer_reader *reader@<edx>,
        vostok::network_core::buffer_reader *client_reader)
{
  const unsigned __int8 *m_pointer; // esi
  vostok::ai::fsm_state *m_first; // ecx
  char v5; // bl
  unsigned __int8 v6; // [esp+Fh] [ebp-1h]

  m_pointer = reader->m_pointer;
  v6 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  m_first = this->m_states.m_first;
  v5 = 0;
  this->m_current_state = 0;
  if ( m_first )
  {
    while ( v5 != v6 )
    {
      m_first = m_first->next;
      ++v5;
      if ( !m_first )
        goto LABEL_6;
    }
    this->m_current_state = m_first;
  }
LABEL_6:
  this->m_current_state->deserialize(this->m_current_state, reader, client_reader);
}
