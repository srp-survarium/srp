void __thiscall survarium::lobby_menu::on_stats_message_arrived(
        survarium::lobby_menu *this,
        survarium::lobby_menu *w_text,
        const wchar_t *w_sender_name,
        wchar_t *message_channel,
        survarium::flash_value *message_channela)
{
  unsigned __int16 *v5; // esi
  const wchar_t *v6; // eax
  const wchar_t *v7; // edi
  unsigned __int16 *v8; // eax
  unsigned __int16 *v9; // eax
  int v10; // eax
  survarium::game *m_game; // ecx
  survarium::lobby_client *v12; // eax
  survarium::lobby_client *v13; // ecx
  survarium::lobby_client *v14; // eax
  survarium::lobby_client *v15; // ecx
  unsigned __int16 *v16; // eax
  const wchar_t *player_exp; // [esp+10h] [ebp-BCh]
  unsigned int pConvertedChars; // [esp+14h] [ebp-B8h] BYREF
  survarium::flash_value player_count_val; // [esp+18h] [ebp-B4h] BYREF
  wchar_t w_player_count[8]; // [esp+38h] [ebp-94h] BYREF
  wchar_t w_player_id[32]; // [esp+48h] [ebp-84h] BYREF
  wchar_t w_player_exp[34]; // [esp+88h] [ebp-44h] BYREF

  v5 = wcsstr(w_sender_name, L"Player [ ");
  player_exp = wcsstr(w_sender_name, L"#e:[");
  wcsstr(w_sender_name, L"#mc:[");
  v6 = wcsstr(w_sender_name, L"#pc:[");
  v7 = v6;
  if ( v5 )
  {
    v8 = wcsstr(v5, L" ]");
    wcsncpy_s((unsigned int)w_sender_name, w_player_id, 0x20u, v5 + 9, v8 - v5 - 9);
    pConvertedChars = 0;
    wcstombs_s(&pConvertedChars, player_count_val.body, 0x20u, w_player_id, 0xFFFFFFFF);
    if ( strcmp(
           player_count_val.body,
           w_text->m_game->m_network_client->lobby_client(w_text->m_game->m_network_client)->account_nickname_) )
    {
      return;
    }
    survarium::chat_handler::add_message(
      w_text->m_game->m_chat_handler,
      w_text->m_game->m_chat_handler,
      message_channela,
      w_sender_name,
      message_channel);
    if ( player_exp )
    {
      v9 = wcsstr(player_exp, L"]");
      wcsncpy_s((unsigned int)w_sender_name, w_player_exp, 0x20u, player_exp + 4, v9 - player_exp - 4);
      v10 = _wtoi(w_player_exp);
      m_game = w_text->m_game;
      w_text->m_match_stats.last_match_exp_delta = v10;
      if ( m_game->m_network_client->lobby_client(m_game->m_network_client)->m_net_client_connected )
      {
        v12 = w_text->m_game->m_network_client->lobby_client(w_text->m_game->m_network_client);
        survarium::lobby_client::query_client_status(v13, v12, q_account_money);
        v14 = w_text->m_game->m_network_client->lobby_client(w_text->m_game->m_network_client);
        survarium::lobby_client::query_client_status(v15, v14, q_player_skills);
      }
    }
    goto LABEL_6;
  }
  if ( !v6 )
  {
LABEL_6:
    survarium::chat_handler::add_message(
      w_text->m_game->m_chat_handler,
      w_text->m_game->m_chat_handler,
      message_channela,
      w_sender_name,
      message_channel);
    return;
  }
  v16 = wcsstr(v6, L"]");
  wcsncpy_s((unsigned int)w_sender_name, w_player_count, 8u, v7 + 5, v16 - v7 - 5);
  *(_DWORD *)player_count_val.body = 0;
  *(_DWORD *)&player_count_val.body[4] = 0;
  survarium::flash_value::SetStringW(&player_count_val, w_player_count);
  Scaleform::GFx::Movie::Invoke(
    w_text->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_games_online",
    0,
    (const Scaleform::GFx::Value *)&player_count_val,
    1u);
  if ( (player_count_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_count_val.body + 8))(
      *(_DWORD *)player_count_val.body,
      &player_count_val,
      *(_DWORD *)&player_count_val.body[8]);
}
