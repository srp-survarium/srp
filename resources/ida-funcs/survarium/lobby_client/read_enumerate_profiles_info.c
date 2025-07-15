char __userpurge survarium::lobby_client::read_enumerate_profiles_info@<al>(
        vostok::network_core::packet_reader *reader@<esi>,
        survarium::lobby_client *this)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned __int8 v3; // cl
  unsigned __int8 v4; // bl
  const unsigned __int8 *v5; // ecx
  unsigned int v6; // edx
  const unsigned __int8 *v7; // eax
  unsigned int v8; // edi
  char *profile_name; // ecx
  survarium::lobby_client *m_begin; // ecx
  char *v11; // eax
  char *m_end; // ecx

  m_pointer = reader->m_pointer;
  v3 = *m_pointer;
  v4 = 0;
  reader->m_pointer = m_pointer + 1;
  for ( this->m_profiles_count = v3; v4 < this->m_profiles_count; profile_name[v8] = 0 )
  {
    v5 = reader->m_pointer;
    v6 = *(_DWORD *)v5;
    reader->m_pointer = v5 + 4;
    this->m_profiles[v4].profile_id = v6;
    v7 = reader->m_pointer;
    v8 = *v7;
    reader->m_pointer = v7 + 1;
    memcpy((unsigned __int8 *)this->m_profiles[v4].profile_name, (unsigned __int8 *)v7 + 1, v8);
    reader->m_pointer += v8;
    profile_name = this->m_profiles[v4++].profile_name;
  }
  m_begin = (survarium::lobby_client *)this->m_player_name.m_begin;
  v11 = this->m_profiles[0].profile_name;
  if ( m_begin != (survarium::lobby_client *)this->m_profiles[0].profile_name )
  {
    this->m_player_name.m_end = (char *)m_begin;
    m_begin->account_nickname_[0] = 0;
    if ( this != (survarium::lobby_client *)-616 )
    {
      for ( ; *v11; ++v11 )
      {
        m_end = this->m_player_name.m_end;
        if ( m_end >= this->m_player_name.m_max_end )
          break;
        *m_end = *v11;
        ++this->m_player_name.m_end;
      }
      *this->m_player_name.m_end = 0;
    }
  }
  return 1;
}
