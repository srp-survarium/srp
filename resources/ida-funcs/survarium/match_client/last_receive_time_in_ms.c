unsigned int __thiscall survarium::match_client::last_receive_time_in_ms(survarium::match_client *this)
{
  return *(_DWORD *)((char *)&loc_55F48 + (unsigned int)*this->m_client.m_client);
}
