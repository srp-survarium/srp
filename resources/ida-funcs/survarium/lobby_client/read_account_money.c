char __usercall survarium::lobby_client::read_account_money@<al>(
        survarium::lobby_client *this@<ecx>,
        vostok::network_core::buffer_reader *reader@<eax>)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v3; // esi
  unsigned int v5; // [esp+8h] [ebp-4h]
  unsigned int v6; // [esp+8h] [ebp-4h]

  m_pointer = reader->m_pointer;
  v5 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_account_money.generic_money = v5;
  v3 = reader->m_pointer;
  v6 = *(_DWORD *)v3;
  reader->m_pointer = v3 + 4;
  this->m_account_money.premium_money = v6;
  vostok::network_core::buffer_reader::r_string(
    (vostok::network_core::buffer_reader *)this,
    (char *)reader,
    (unsigned __int8 *)this);
  return 1;
}
