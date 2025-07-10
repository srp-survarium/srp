bool __thiscall vostok::network::match_client::is_disconnected(vostok::network::match_client *this)
{
  return !*this->m_client || *(int *)((char *)&dword_258154 + (unsigned int)*this->m_client) == 3;
}
