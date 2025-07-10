void __thiscall survarium::lobby_menu::update_status(survarium::lobby_menu *this, survarium::lobby_menu *thisa)
{
  survarium::game *m_game; // eax
  survarium::lobby_client *v3; // esi
  vostok::network::login_client *v4; // esi
  int v5; // eax
  survarium::flash_movie_resource *m_object; // edx
  int v7; // edi
  char *v8; // eax
  survarium::flash_value account_info; // [esp+2Ch] [ebp-180h] BYREF
  survarium::flash_value b_val; // [esp+44h] [ebp-168h] BYREF
  survarium::flash_value port; // [esp+5Ch] [ebp-150h] BYREF
  survarium::flash_value log_message; // [esp+74h] [ebp-138h] BYREF
  vostok::fixed_string<128> buff; // [esp+8Ch] [ebp-120h] BYREF
  char v14; // [esp+118h] [ebp-94h] BYREF
  vostok::fixed_string<128> status_str; // [esp+11Ch] [ebp-90h] BYREF
  char v16; // [esp+1A8h] [ebp-4h] BYREF

  status_str.m_begin = status_str.m_buffer;
  m_game = thisa->m_game;
  status_str.m_end = status_str.m_buffer;
  status_str.m_max_end = &v16;
  status_str.m_buffer[0] = 0;
  *(_DWORD *)b_val.body = 0;
  *(_DWORD *)&b_val.body[4] = 2;
  b_val.body[8] = 0;
  v3 = m_game->m_network_client->lobby_client(m_game->m_network_client);
  if ( survarium::lobby_client::status(v3, &status_str) == surf_lobby_menu )
  {
    *(_DWORD *)&b_val.body[4] = 2;
    b_val.body[8] = 1;
  }
  v4 = thisa->m_game->m_network_client->login_client(thisa->m_game->m_network_client);
  v5 = (int)thisa->m_game->m_network_client->lobby_client(thisa->m_game->m_network_client);
  m_object = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)account_info.body = 0;
  *(_DWORD *)&account_info.body[4] = 0;
  v7 = v5;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&account_info);
  v8 = vostok::network::login_client::account_name(v4);
  survarium::flash_value::SetElement(&account_info, v8, 0);
  survarium::flash_value::SetElement(&account_info, v4->m_server_host, 1u);
  *(_DWORD *)&port.body[4] = 0;
  *(_DWORD *)port.body = 0;
  *(_DWORD *)&port.body[8] = v4->m_server_port;
  *(_DWORD *)&port.body[4] = 4;
  (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)account_info.body + 52))(
    *(_DWORD *)account_info.body,
    *(_DWORD *)&account_info.body[8],
    2,
    &port);
  buff.m_end = buff.m_buffer;
  buff.m_begin = buff.m_buffer;
  buff.m_max_end = &v14;
  buff.m_buffer[0] = 0;
  vostok::buffer_string::assignf(&buff, "%s:%d", (const char *)(v7 + 42), *(unsigned __int16 *)(v7 + 40));
  survarium::flash_value::SetElement(&account_info, buff.m_begin, 3u);
  Scaleform::GFx::Movie::Invoke(
    thisa->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.lobby_menu.set_account_info",
    0,
    (const Scaleform::GFx::Value *)&account_info,
    1u);
  *(_DWORD *)log_message.body = 0;
  *(_DWORD *)&log_message.body[4] = 0;
  survarium::flash_value::SetString(&log_message, status_str.m_begin);
  Scaleform::GFx::Movie::Invoke(
    thisa->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.lock_play_button",
    0,
    (const Scaleform::GFx::Value *)&b_val,
    1u);
  Scaleform::GFx::Movie::Invoke(
    thisa->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_status_info",
    0,
    (const Scaleform::GFx::Value *)&log_message,
    1u);
  if ( (log_message.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)log_message.body + 8))(
      *(_DWORD *)log_message.body,
      &log_message,
      *(_DWORD *)&log_message.body[8]);
    *(_DWORD *)log_message.body = 0;
  }
  *(_DWORD *)&log_message.body[4] = 0;
  if ( (port.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)port.body + 8))(
      *(_DWORD *)port.body,
      &port,
      *(_DWORD *)&port.body[8]);
    *(_DWORD *)port.body = 0;
  }
  *(_DWORD *)&port.body[4] = 0;
  if ( (account_info.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)account_info.body + 8))(
      *(_DWORD *)account_info.body,
      &account_info,
      *(_DWORD *)&account_info.body[8]);
    *(_DWORD *)account_info.body = 0;
  }
  *(_DWORD *)&account_info.body[4] = 0;
  if ( (b_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)b_val.body + 8))(
      *(_DWORD *)b_val.body,
      &b_val,
      *(_DWORD *)&b_val.body[8]);
}
