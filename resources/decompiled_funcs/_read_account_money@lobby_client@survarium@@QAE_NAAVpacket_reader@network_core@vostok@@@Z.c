char __usercall survarium::lobby_client::read_account_money@<al>(
        survarium::lobby_client *this@<edi>,
        vostok::network_core::packet_reader *reader@<esi>)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned int v3; // ecx
  const unsigned __int8 *v4; // eax
  unsigned int v5; // ecx
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // eax
  unsigned int v8; // ebx

  m_pointer = reader->m_pointer;
  v3 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_account_money.generic_money = v3;
  v4 = reader->m_pointer;
  v5 = *(_DWORD *)v4;
  reader->m_pointer = v4 + 4;
  this->m_account_money.premium_money = v5;
  v6 = reader->m_pointer;
  LOBYTE(v5) = *v6;
  reader->m_pointer = v6 + 1;
  this->m_player_leveling_info.total_skill_points = v5;
  v7 = reader->m_pointer;
  v8 = *v7;
  reader->m_pointer = v7 + 1;
  memcpy((unsigned __int8 *)this, (unsigned __int8 *)v7 + 1, v8);
  reader->m_pointer += v8;
  this->account_nickname_[v8] = 0;
  return 1;
}
