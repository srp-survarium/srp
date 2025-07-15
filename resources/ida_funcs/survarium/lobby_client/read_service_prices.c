char __usercall survarium::lobby_client::read_service_prices@<al>(
        survarium::lobby_client *this@<ecx>,
        vostok::network_core::packet_reader *reader@<eax>)
{
  const unsigned __int8 *m_pointer; // edx
  unsigned int v3; // esi
  const unsigned __int8 *v4; // edx
  unsigned int v5; // esi
  const unsigned __int8 *v6; // edx
  unsigned int v7; // esi

  m_pointer = reader->m_pointer;
  v3 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_service_prices.reroll_cost = v3;
  v4 = reader->m_pointer;
  v5 = *(_DWORD *)v4;
  reader->m_pointer = v4 + 4;
  this->m_service_prices.add_profile_cost = v5;
  v6 = reader->m_pointer;
  v7 = *(_DWORD *)v6;
  reader->m_pointer = v6 + 4;
  this->m_service_prices.rename_account_cost = v7;
  return 1;
}
