void __thiscall survarium::lobby_menu::on_player_reputations_arrived(
        survarium::lobby_menu *this,
        survarium::lobby_menu *thisa)
{
  survarium::lobby_menu *v2; // edi
  survarium::player_reputation *m_player_reputations; // edx
  const void *reputation_points; // ebp
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  const vostok::configs::binary_config_value *v7; // esi
  int v8; // ebx
  int v9; // edi
  survarium::flash_value *v10; // eax
  int i; // ecx
  survarium::flash_movie_resource *m_object; // ecx
  char *v13; // esi
  int j; // ebp
  int v15; // eax
  unsigned __int8 current_reputation_level; // [esp+17h] [ebp-6Fh]
  unsigned __int8 reputation_id; // [esp+18h] [ebp-6Eh]
  unsigned __int8 player_reputation_level; // [esp+19h] [ebp-6Dh]
  char faction_str[32]; // [esp+1Ah] [ebp-6Ch] BYREF
  survarium::flash_value player_progress_args[3]; // [esp+3Ah] [ebp-4Ch] BYREF
  char v21; // [esp+82h] [ebp-4h] BYREF

  v2 = thisa;
  for ( reputation_id = 0;
        reputation_id < v2->m_game->m_network_client->lobby_client(v2->m_game->m_network_client)->m_player_reputations_count;
        ++reputation_id )
  {
    m_player_reputations = v2->m_game->m_network_client->lobby_client(v2->m_game->m_network_client)->m_player_reputations;
    reputation_points = (const void *)m_player_reputations[reputation_id].reputation_points;
    sprintf_s<32>((char (*)[32])faction_str, "faction_%d", m_player_reputations[reputation_id].faction_id);
    v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   v2->m_game->m_items_dictionary.m_object->dict_config.m_object->m_root,
                                                   "factions_dict");
    v6 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v5, faction_str);
    v7 = vostok::configs::binary_config_value::operator[](v6, "levels");
    v8 = 24 * v7->count / 24;
    player_reputation_level = 0;
    current_reputation_level = 0;
    if ( (_BYTE)v8 )
    {
      v9 = 0;
      do
      {
        if ( reputation_points >= vostok::configs::binary_config_value::operator[](
                                    (vostok::configs::binary_config_value *)((char *)v7->data.pointer + v9),
                                    (char *)&stru_955964)->data.pointer )
          player_reputation_level = current_reputation_level;
        v9 += 24;
        ++current_reputation_level;
      }
      while ( current_reputation_level < (unsigned __int8)v8 );
      v2 = thisa;
    }
    v10 = player_progress_args;
    for ( i = 2; i >= 0; --i )
    {
      if ( v10 )
      {
        *(_DWORD *)v10->body = 0;
        *(_DWORD *)&v10->body[4] = 0;
      }
      ++v10;
    }
    if ( (player_progress_args[0].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_progress_args[0].body + 8))(
        *(_DWORD *)player_progress_args[0].body,
        player_progress_args,
        *(_DWORD *)&player_progress_args[0].body[8]);
      *(_DWORD *)player_progress_args[0].body = 0;
    }
    *(_DWORD *)&player_progress_args[0].body[4] = 4;
    *(_DWORD *)&player_progress_args[0].body[8] = player_reputation_level;
    if ( (player_progress_args[1].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_progress_args[1].body + 8))(
        *(_DWORD *)player_progress_args[1].body,
        &player_progress_args[1],
        *(_DWORD *)&player_progress_args[1].body[8]);
      *(_DWORD *)player_progress_args[1].body = 0;
    }
    m_object = v2->m_lobby_menu_ui.m_object;
    *(_DWORD *)&player_progress_args[1].body[4] = 4;
    *(_DWORD *)&player_progress_args[1].body[8] = reputation_points;
    Scaleform::GFx::Movie::Invoke(
      m_object->movie->m_movie,
      "root.setup_player_progress",
      0,
      (const Scaleform::GFx::Value *)player_progress_args,
      3u);
    v13 = &v21;
    for ( j = 2; j >= 0; --j )
    {
      v15 = *((_DWORD *)v13 - 5);
      v13 -= 24;
      if ( (v15 & 0x40) != 0 )
      {
        (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v13 + 8))(v13, *((_DWORD *)v13 + 2));
        *(_DWORD *)v13 = 0;
      }
      *((_DWORD *)v13 + 1) = 0;
    }
  }
}
