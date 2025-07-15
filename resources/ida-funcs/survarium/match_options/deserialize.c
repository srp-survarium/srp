void __usercall survarium::match_options::deserialize(
        survarium::match_options *this@<edi>,
        vostok::network_core::packet_reader *reader@<esi>)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned __int8 v3; // cl
  const unsigned __int8 *v4; // eax
  unsigned int v5; // ebx
  const unsigned __int8 *v6; // eax
  unsigned __int8 v7; // cl
  const unsigned __int8 *v8; // eax
  unsigned __int8 v9; // cl
  const unsigned __int8 *v10; // eax
  unsigned __int8 v11; // cl
  const unsigned __int8 *v12; // eax
  unsigned __int8 v13; // cl
  const unsigned __int8 *v14; // eax
  unsigned __int16 v15; // cx

  m_pointer = reader->m_pointer;
  v3 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  this->map_id = v3;
  v4 = reader->m_pointer;
  v5 = *v4;
  reader->m_pointer = v4 + 1;
  memcpy((unsigned __int8 *)this->map_name, (unsigned __int8 *)v4 + 1, v5);
  reader->m_pointer += v5;
  this->map_name[v5] = 0;
  v6 = reader->m_pointer;
  v7 = *v6;
  reader->m_pointer = v6 + 1;
  this->match_mode_ = v7;
  v8 = reader->m_pointer;
  v9 = *v8;
  reader->m_pointer = v8 + 1;
  this->players_count = v9;
  v10 = reader->m_pointer;
  v11 = *v10;
  reader->m_pointer = v10 + 1;
  this->victory_items_count = v11;
  v12 = reader->m_pointer;
  v13 = *v12;
  reader->m_pointer = v12 + 1;
  this->respawn_time = v13;
  v14 = reader->m_pointer;
  v15 = *(_WORD *)v14;
  reader->m_pointer = v14 + 2;
  this->match_time = v15;
  this->match_id = -1;
  this->received_players_count = -1;
}
