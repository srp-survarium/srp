int __userpurge survarium::network_client::get_player_team@<eax>(
        survarium::network_client *this@<ecx>,
        int a2@<eax>,
        const char *player_profile_name)
{
  int v3; // esi
  unsigned __int8 v4; // bl

  v3 = *(_DWORD *)(a2 + 13768);
  v4 = 0;
  while ( strcmp(player_profile_name, (const char *)(1488 * v4 + v3 + 24)) )
  {
    if ( ++v4 >= 0x14u )
      return 3;
  }
  return *(_DWORD *)(1488 * v4 + v3 + 456);
}
