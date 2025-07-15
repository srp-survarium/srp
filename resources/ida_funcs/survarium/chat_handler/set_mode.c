void __thiscall survarium::chat_handler::set_mode(
        survarium::chat_handler *this,
        survarium::chat_handler *is_game_mode,
        bool is_game_modea)
{
  survarium::chat_handler *v3; // edi
  unsigned __int8 v4; // cl
  unsigned __int8 v5; // bl
  survarium::flash_movie_resource *m_object; // ecx
  survarium::flash_movie_resource *v7; // eax
  survarium::text_translator *m_game; // eax
  survarium::chat_tab *v9; // ebx
  const char *v10; // edi
  int v11; // ecx
  wchar_t *key; // esi
  int v13; // ecx
  int name_low; // esi
  bool v15; // zf
  survarium::flash_movie_resource *v16; // ecx
  survarium::flash_value chat_tab_member; // [esp+94h] [ebp-4F4h] BYREF
  survarium::chat_tab *current_tabs; // [esp+ACh] [ebp-4DCh]
  int v19; // [esp+B0h] [ebp-4D8h]
  survarium::flash_value chat_tab_value; // [esp+B4h] [ebp-4D4h] BYREF
  int v21; // [esp+CCh] [ebp-4BCh]
  int v22; // [esp+D0h] [ebp-4B8h] BYREF
  int v23; // [esp+D4h] [ebp-4B4h]
  wchar_t *v24; // [esp+D8h] [ebp-4B0h]
  survarium::flash_value is_heavy_mode; // [esp+E8h] [ebp-4A0h] BYREF
  survarium::flash_value channels_array; // [esp+100h] [ebp-488h] BYREF
  survarium::chat_tab game_menu_tabs[2]; // [esp+118h] [ebp-470h] BYREF
  survarium::chat_tab lobby_menu_tabs[5]; // [esp+138h] [ebp-450h] BYREF
  wchar_t channel_name_txt[512]; // [esp+188h] [ebp-400h] BYREF

  v3 = is_game_mode;
  lobby_menu_tabs[1].key = (const char *)&buf;
  lobby_menu_tabs[4].key = (const char *)&buf;
  lobby_menu_tabs[0].name = "st_chat_channel_general";
  lobby_menu_tabs[0].color = "White";
  lobby_menu_tabs[0].id = 1;
  lobby_menu_tabs[0].key = "/general";
  lobby_menu_tabs[1].name = "st_chat_channel_private";
  lobby_menu_tabs[1].color = "Pink";
  lobby_menu_tabs[1].id = 4;
  lobby_menu_tabs[2].name = "st_chat_channel_clan";
  lobby_menu_tabs[2].color = "Blue";
  lobby_menu_tabs[2].id = 3;
  lobby_menu_tabs[2].key = "/clan";
  lobby_menu_tabs[3].name = "st_chat_channel_squad";
  lobby_menu_tabs[3].color = "Green";
  lobby_menu_tabs[3].id = 8;
  lobby_menu_tabs[3].key = "/squad";
  lobby_menu_tabs[4].name = "st_chat_channel_system";
  lobby_menu_tabs[4].color = "Red";
  lobby_menu_tabs[4].id = 2;
  v4 = 9;
  if ( is_game_modea )
    v4 = (is_game_mode->m_game->m_network_client->messaging_client(is_game_mode->m_game->m_network_client)->m_game_team_id != team_1)
       + 6;
  game_menu_tabs[0].name = "st_chat_channel_team";
  game_menu_tabs[0].color = "White";
  game_menu_tabs[0].id = v4;
  game_menu_tabs[0].key = "/team";
  game_menu_tabs[1].name = "st_chat_channel_match";
  game_menu_tabs[1].color = "White";
  game_menu_tabs[1].id = 5;
  game_menu_tabs[1].key = "/all";
  is_game_mode->m_game_ui_mode = is_game_modea;
  if ( is_game_modea )
  {
    current_tabs = game_menu_tabs;
    v5 = 2;
  }
  else
  {
    current_tabs = lobby_menu_tabs;
    v5 = 5;
  }
  m_object = is_game_mode->m_chat_ui.m_object;
  *(_DWORD *)channels_array.body = 0;
  *(_DWORD *)&channels_array.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&channels_array);
  v19 = 0;
  current_tabs = (survarium::chat_tab *)((char *)current_tabs + 8);
  v21 = v5;
  do
  {
    v7 = v3->m_chat_ui.m_object;
    *(_DWORD *)chat_tab_value.body = 0;
    *(_DWORD *)&chat_tab_value.body[4] = 0;
    Scaleform::GFx::Movie::CreateObject(v7->movie->m_movie, (Scaleform::GFx::Value *)&chat_tab_value, 0, 0, 0);
    m_game = (survarium::text_translator *)v3->m_game;
    v9 = current_tabs;
    v10 = *(const char **)&current_tabs[-1].id;
    *(_DWORD *)chat_tab_member.body = 0;
    *(_DWORD *)&chat_tab_member.body[4] = 0;
    survarium::text_translator::translate_text(m_game + 247, v10, channel_name_txt);
    v11 = 0;
    v22 = 0;
    v23 = 7;
    v24 = channel_name_txt;
    if ( (chat_tab_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)chat_tab_member.body + 8))(
        *(_DWORD *)chat_tab_member.body,
        &chat_tab_member,
        *(_DWORD *)&chat_tab_member.body[8]);
      v11 = v22;
      *(_DWORD *)chat_tab_member.body = 0;
    }
    *(_DWORD *)&chat_tab_member.body[4] = 7;
    *(_DWORD *)&chat_tab_member.body[8] = channel_name_txt;
    if ( (v23 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v11 + 8))(v11, &v22, v24);
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)chat_tab_value.body
                                                                                         + 20))(
      *(_DWORD *)chat_tab_value.body,
      *(_DWORD *)&chat_tab_value.body[8],
      "name",
      &chat_tab_member,
      (chat_tab_value.body[4] & 0x8F) == 10);
    key = (wchar_t *)v9[-1].key;
    v13 = 0;
    v22 = 0;
    v23 = 6;
    v24 = key;
    if ( (chat_tab_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)chat_tab_member.body + 8))(
        *(_DWORD *)chat_tab_member.body,
        &chat_tab_member,
        *(_DWORD *)&chat_tab_member.body[8]);
      v13 = v22;
      *(_DWORD *)chat_tab_member.body = 0;
    }
    *(_DWORD *)&chat_tab_member.body[4] = 6;
    *(_DWORD *)&chat_tab_member.body[8] = key;
    if ( (v23 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v13 + 8))(v13, &v22, v24);
    (*(void (__thiscall **)(_DWORD, _DWORD, const vostok::render::shader_configuration *, survarium::flash_value *, bool))(**(_DWORD **)chat_tab_value.body + 20))(
      *(_DWORD *)chat_tab_value.body,
      *(_DWORD *)&chat_tab_value.body[8],
      &stru_9555EC,
      &chat_tab_member,
      (chat_tab_value.body[4] & 0x8F) == 10);
    name_low = LOBYTE(v9->name);
    if ( (chat_tab_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)chat_tab_member.body + 8))(
        *(_DWORD *)chat_tab_member.body,
        &chat_tab_member,
        *(_DWORD *)&chat_tab_member.body[8]);
      *(_DWORD *)chat_tab_member.body = 0;
    }
    *(_DWORD *)&chat_tab_member.body[4] = 4;
    *(_DWORD *)&chat_tab_member.body[8] = name_low;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)chat_tab_value.body
                                                                                         + 20))(
      *(_DWORD *)chat_tab_value.body,
      *(_DWORD *)&chat_tab_value.body[8],
      "id",
      &chat_tab_member,
      (chat_tab_value.body[4] & 0x8F) == 10);
    if ( (chat_tab_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)chat_tab_member.body + 8))(
        *(_DWORD *)chat_tab_member.body,
        &chat_tab_member,
        *(_DWORD *)&chat_tab_member.body[8]);
      *(_DWORD *)chat_tab_member.body = 0;
    }
    *(_DWORD *)&chat_tab_member.body[4] = 4;
    *(_DWORD *)&chat_tab_member.body[8] = name_low;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)chat_tab_value.body
                                                                                         + 20))(
      *(_DWORD *)chat_tab_value.body,
      *(_DWORD *)&chat_tab_value.body[8],
      "icon",
      &chat_tab_member,
      (chat_tab_value.body[4] & 0x8F) == 10);
    if ( strcmp(v9->color, (const char *)&buf) )
    {
      survarium::flash_value::SetString(&chat_tab_member, v9->color);
      (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int *, survarium::flash_value *, bool))(**(_DWORD **)chat_tab_value.body
                                                                                             + 20))(
        *(_DWORD *)chat_tab_value.body,
        *(_DWORD *)&chat_tab_value.body[8],
        &stru_955964.id_crc,
        &chat_tab_member,
        (chat_tab_value.body[4] & 0x8F) == 10);
    }
    (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)channels_array.body + 52))(
      *(_DWORD *)channels_array.body,
      *(_DWORD *)&channels_array.body[8],
      v19,
      &chat_tab_value);
    if ( (chat_tab_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)chat_tab_member.body + 8))(
        *(_DWORD *)chat_tab_member.body,
        &chat_tab_member,
        *(_DWORD *)&chat_tab_member.body[8]);
      *(_DWORD *)chat_tab_member.body = 0;
    }
    *(_DWORD *)&chat_tab_member.body[4] = 0;
    if ( (chat_tab_value.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)chat_tab_value.body + 8))(
        *(_DWORD *)chat_tab_value.body,
        &chat_tab_value,
        *(_DWORD *)&chat_tab_value.body[8]);
    v3 = is_game_mode;
    ++v19;
    v15 = v21-- == 1;
    current_tabs = v9 + 1;
  }
  while ( !v15 );
  Scaleform::GFx::Movie::Invoke(
    is_game_mode->m_chat_ui.m_object->movie->m_movie,
    "root.set_channels",
    0,
    (const Scaleform::GFx::Value *)&channels_array,
    1u);
  v16 = is_game_mode->m_chat_ui.m_object;
  is_heavy_mode.body[8] = !is_game_mode->m_game_ui_mode;
  *(_DWORD *)is_heavy_mode.body = 0;
  *(_DWORD *)&is_heavy_mode.body[4] = 2;
  Scaleform::GFx::Movie::Invoke(
    v16->movie->m_movie,
    "root.set_heavy",
    0,
    (const Scaleform::GFx::Value *)&is_heavy_mode,
    1u);
  if ( (is_heavy_mode.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)is_heavy_mode.body + 8))(
      *(_DWORD *)is_heavy_mode.body,
      &is_heavy_mode,
      *(_DWORD *)&is_heavy_mode.body[8]);
    *(_DWORD *)is_heavy_mode.body = 0;
  }
  *(_DWORD *)&is_heavy_mode.body[4] = 0;
  if ( (channels_array.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)channels_array.body + 8))(
      *(_DWORD *)channels_array.body,
      &channels_array,
      *(_DWORD *)&channels_array.body[8]);
}
