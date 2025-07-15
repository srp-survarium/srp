int __thiscall survarium::lobby_client::squad_ready_count(survarium::lobby_client *this)
{
  int v1; // ebx
  unsigned int v2; // edi
  bool *p_ready; // esi

  v1 = 0;
  v2 = 0;
  if ( this->m_squad_members.m_end - this->m_squad_members.m_begin )
  {
    p_ready = &this->m_squad_members.m_begin->ready;
    do
    {
      if ( *p_ready )
        ++v1;
      ++v2;
      p_ready += 80;
    }
    while ( v2 < this->m_squad_members.m_end - this->m_squad_members.m_begin );
  }
  return v1;
}
