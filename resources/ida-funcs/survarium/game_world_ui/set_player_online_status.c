void __userpurge survarium::game_world_ui::set_player_online_status(
        unsigned int player_id@<eax>,
        survarium::game_world_ui *this,
        bool is_online)
{
  survarium::base_network_client *m_network_client; // ecx
  int v5; // eax
  survarium::flash_value *v6; // eax
  int i; // ecx
  survarium::flash_movie_resource *m_object; // edx
  char *v9; // esi
  int j; // edi
  int v11; // ecx
  unsigned int pConvertedChars; // [esp+10h] [ebp-43Ch] BYREF
  survarium::flash_value player_online_value[2]; // [esp+14h] [ebp-438h] BYREF
  char v14; // [esp+44h] [ebp-408h] BYREF
  wchar_t w_player_name[514]; // [esp+48h] [ebp-404h] BYREF

  m_network_client = this->m_game_world->m_game->m_network_client;
  v5 = (int)m_network_client->match_options(m_network_client);
  pConvertedChars = 0;
  mbstowcs_s(&pConvertedChars, w_player_name, 0x200u, (char *)(v5 + 440 * player_id + 8), 0xFFFFFFFF);
  v6 = player_online_value;
  for ( i = 1; i >= 0; --i )
  {
    if ( v6 )
    {
      *(_DWORD *)v6->body = 0;
      *(_DWORD *)&v6->body[4] = 0;
    }
    ++v6;
  }
  survarium::flash_value::SetStringW(player_online_value, w_player_name);
  if ( (player_online_value[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_online_value[1].body + 8))(
      *(_DWORD *)player_online_value[1].body,
      &player_online_value[1],
      *(_DWORD *)&player_online_value[1].body[8]);
    *(_DWORD *)player_online_value[1].body = 0;
  }
  m_object = this->m_game_hud_ui.m_object;
  *(_DWORD *)&player_online_value[1].body[4] = 2;
  player_online_value[1].body[8] = is_online;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.set_online_player",
    0,
    (const Scaleform::GFx::Value *)player_online_value,
    2u);
  v9 = &v14;
  for ( j = 1; j >= 0; --j )
  {
    v11 = *((_DWORD *)v9 - 5);
    v9 -= 24;
    if ( (v11 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v9 + 8))(v9, *((_DWORD *)v9 + 2));
      *(_DWORD *)v9 = 0;
    }
    *((_DWORD *)v9 + 1) = 0;
  }
}
