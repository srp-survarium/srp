char __usercall survarium::lobby_client::read_service_prices@<al>(
        survarium::lobby_client *this@<ecx>,
        vostok::network_core::buffer_reader *reader@<eax>)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v3; // esi
  unsigned int v5; // [esp+8h] [ebp-4h]
  unsigned int v6; // [esp+8h] [ebp-4h]
  unsigned int v7; // [esp+8h] [ebp-4h]

  m_pointer = reader->m_pointer;
  v5 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_service_prices.reroll_cost = v5;
  v3 = reader->m_pointer;
  v6 = *(_DWORD *)v3;
  reader->m_pointer = v3 + 4;
  this->m_service_prices.add_profile_cost = v6;
  v7 = *(_DWORD *)reader->m_pointer;
  reader->m_pointer += 4;
  this->m_service_prices.rename_account_cost = v7;
  return 1;
}
