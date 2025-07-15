BOOL __thiscall survarium::match_client::is_disconnected(survarium::match_client *this)
{
  vostok::network::match_client_impl **m_client; // eax

  m_client = this->m_client.m_client;
  return !*m_client || *(_DWORD *)((char *)&loc_55F64 + (_DWORD)*m_client) == 3;
}
