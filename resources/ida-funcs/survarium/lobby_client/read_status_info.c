char __usercall survarium::lobby_client::read_status_info@<al>(
        survarium::lobby_client *this@<eax>,
        vostok::network_core::packet_reader *reader@<esi>)
{
  const unsigned __int8 *m_pointer; // ecx
  unsigned __int8 v3; // dl
  const unsigned __int8 *v4; // ecx
  unsigned int v5; // edx
  const unsigned __int8 *v6; // ecx
  unsigned int v7; // edx
  const unsigned __int8 *v8; // ecx
  const unsigned __int8 *v9; // ecx
  unsigned int v10; // edi
  char *m_buffer; // ebx
  char *m_begin; // ecx

  m_pointer = reader->m_pointer;
  v3 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  this->m_status = v3;
  if ( v3 )
  {
    if ( (unsigned int)v3 - 1 <= 2 )
    {
      v4 = reader->m_pointer;
      v5 = *(_DWORD *)v4;
      reader->m_pointer = v4 + 4;
      this->m_match_order_id = v5;
      v6 = reader->m_pointer;
      v7 = *(_DWORD *)v6;
      reader->m_pointer = v6 + 4;
      this->m_match_id = v7;
      v8 = reader->m_pointer;
      LOBYTE(v7) = *v8;
      reader->m_pointer = v8 + 1;
      this->m_team_id = (unsigned __int8)v7;
    }
  }
  else
  {
    this->m_match_order_id = -1;
    this->m_match_id = -1;
    this->m_team_id = team_undefined;
  }
  v9 = reader->m_pointer;
  if ( v9 == &reader->m_packet->m_buffer[reader->m_packet->m_buffer_size] )
  {
    m_begin = this->m_last_status_message.m_begin;
    this->m_last_status_message.m_end = m_begin;
    *m_begin = 0;
  }
  else
  {
    v10 = *v9;
    m_buffer = this->m_last_status_message.m_buffer;
    reader->m_pointer = v9 + 1;
    memcpy((unsigned __int8 *)this->m_last_status_message.m_buffer, (unsigned __int8 *)v9 + 1, v10);
    reader->m_pointer += v10;
    m_buffer[v10] = 0;
  }
  return 1;
}
