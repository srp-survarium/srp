unsigned __int8 __userpurge survarium::lobby_client::read_profile_content_info@<al>(
        vostok::network_core::packet_reader *reader@<edi>,
        survarium::lobby_client *this)
{
  unsigned __int8 *m_pointer; // esi
  unsigned int profile_id; // ecx
  unsigned __int8 result; // al
  unsigned __int8 v5; // bl
  int v6; // edx
  survarium::player_profile *v7; // esi
  survarium::player_profile profile; // [esp+10h] [ebp-1B8h] BYREF

  survarium::player_profile::player_profile(&profile);
  m_pointer = (unsigned __int8 *)reader->m_pointer;
  memcpy((unsigned __int8 *)&profile, m_pointer, sizeof(profile));
  profile_id = profile.profile_id;
  result = -1;
  reader->m_pointer = m_pointer + 440;
  v5 = 0;
  while ( 1 )
  {
    v6 = v5;
    v7 = &this->m_profiles[v6];
    if ( this->m_profiles[v6].profile_id == profile_id )
      break;
    if ( ++v5 >= 3u )
      return result;
  }
  memcpy((unsigned __int8 *)&this->m_profiles[v6], (unsigned __int8 *)&profile, sizeof(this->m_profiles[v6]));
  v7->team = team_1;
  return v5;
}
