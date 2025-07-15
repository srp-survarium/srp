char __userpurge survarium::lobby_client::read_account_services@<al>(
        vostok::network_core::buffer_reader *reader@<eax>,
        survarium::lobby_client *this)
{
  const unsigned __int8 *m_pointer; // ecx
  unsigned int v3; // ebx
  unsigned __int8 *v4; // ecx
  const unsigned __int8 *v5; // esi
  int v6; // edx
  survarium::faction_loyalty_item v8[8]; // [esp+Ch] [ebp-28h] BYREF
  unsigned int v9; // [esp+1Ch] [ebp-18h]
  unsigned int v10; // [esp+20h] [ebp-14h]
  BOOL v11; // [esp+24h] [ebp-10h]
  int v12; // [esp+28h] [ebp-Ch]
  int v13; // [esp+2Fh] [ebp-5h]
  unsigned __int8 v14; // [esp+33h] [ebp-1h]

  m_pointer = reader->m_pointer;
  v3 = 0;
  v14 = *m_pointer;
  v4 = (unsigned __int8 *)(m_pointer + 1);
  reader->m_pointer = v4;
  LOBYTE(v11) = 0;
  LOBYTE(v13) = 0;
  if ( v14 )
  {
    v12 = v14;
    do
    {
      v5 = reader->m_pointer;
      v14 = *v5;
      v6 = v14;
      reader->m_pointer = v5 + 2;
      v5 += 2;
      v9 = *(_DWORD *)v5;
      reader->m_pointer = v5 + 4;
      v5 += 4;
      v10 = *(_DWORD *)v5;
      v4 = (unsigned __int8 *)(v5 + 4);
      reader->m_pointer = v5 + 4;
      if ( v6 )
      {
        if ( v6 <= 4 )
        {
          v4 = (unsigned __int8 *)(2 * (unsigned __int8)v13);
          LOBYTE(v13) = v13 + 1;
          *(&v8[0].faction_id + (_DWORD)v4) = v6;
          *(&v8[0].loyalty_value + (_DWORD)v4) = v10;
        }
      }
      else
      {
        v3 = v9;
        LOBYTE(v11) = 1;
      }
      --v12;
    }
    while ( v12 );
  }
  survarium::lobby_menu::set_factions_loyalties((survarium::lobby_menu *)v4, (int)this->m_game->m_lobby_menu, v8, v13);
  survarium::lobby_menu::set_player_premium_access_status(v3, this->m_game->m_lobby_menu, v11);
  return 1;
}
