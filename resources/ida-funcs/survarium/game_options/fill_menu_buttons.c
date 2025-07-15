void __thiscall survarium::game_options::fill_menu_buttons(
        survarium::game_options *this,
        survarium::game_options *in_game_world,
        bool in_game_worlda)
{
  char *m_buffer; // eax
  const char *v4; // esi
  char *v5; // eax
  const char *v6; // esi
  char *v7; // eax
  const char *v8; // esi
  char *v9; // eax
  const char *v10; // esi
  char *v11; // eax
  const char *v12; // esi
  char *v13; // eax
  const char *v14; // esi
  char *v15; // eax
  const char *v16; // esi
  char *v17; // eax
  const char *v18; // esi
  char *v19; // eax
  const char *v20; // esi
  char *v21; // eax
  const char *v22; // esi
  char *v23; // eax
  const char *v24; // esi
  char *v25; // eax
  const char *v26; // esi
  char *v27; // eax
  const char *v28; // esi
  char *v29; // eax
  const char *v30; // esi
  survarium::game_options *v31; // edi
  survarium::flash_movie_resource *m_object; // ecx
  survarium::main_menu_button_name_to_action *v33; // esi
  unsigned __int8 v34; // al
  int v35; // ebp
  survarium::flash_movie_resource *v36; // edx
  int v37; // ecx
  survarium::flash_value button_member; // [esp+44h] [ebp-6D0h] BYREF
  int v39; // [esp+5Ch] [ebp-6B8h]
  survarium::flash_value button; // [esp+60h] [ebp-6B4h] BYREF
  survarium::flash_value buttons_array; // [esp+78h] [ebp-69Ch] BYREF
  int v42; // [esp+90h] [ebp-684h] BYREF
  int v43; // [esp+94h] [ebp-680h]
  wchar_t *v44; // [esp+98h] [ebp-67Ch]
  survarium::main_menu_button_name_to_action name_to_action_in_lobby_menu[3]; // [esp+A8h] [ebp-66Ch] BYREF
  survarium::main_menu_button_name_to_action name_to_action_in_game_world[4]; // [esp+1B0h] [ebp-564h] BYREF
  wchar_t button_txt[514]; // [esp+310h] [ebp-404h] BYREF

  m_buffer = name_to_action_in_game_world[0].name.m_buffer;
  name_to_action_in_game_world[0].name.m_begin = name_to_action_in_game_world[0].name.m_buffer;
  name_to_action_in_game_world[0].name.m_end = name_to_action_in_game_world[0].name.m_buffer;
  name_to_action_in_game_world[0].name.m_max_end = (char *)&name_to_action_in_game_world[0].action;
  name_to_action_in_game_world[0].name.m_buffer[0] = 0;
  v4 = "st_mm_button_back";
  do
  {
    if ( m_buffer >= name_to_action_in_game_world[0].name.m_max_end )
      break;
    *m_buffer = *v4;
    m_buffer = name_to_action_in_game_world[0].name.m_end + 1;
    ++v4;
    ++name_to_action_in_game_world[0].name.m_end;
  }
  while ( *v4 );
  *m_buffer = 0;
  v5 = name_to_action_in_game_world[0].action.m_buffer;
  name_to_action_in_game_world[0].action.m_begin = name_to_action_in_game_world[0].action.m_buffer;
  name_to_action_in_game_world[0].action.m_end = name_to_action_in_game_world[0].action.m_buffer;
  name_to_action_in_game_world[0].action.m_max_end = (char *)&name_to_action_in_game_world[1];
  name_to_action_in_game_world[0].action.m_buffer[0] = 0;
  v6 = "back";
  do
  {
    if ( v5 >= name_to_action_in_game_world[0].action.m_max_end )
      break;
    *v5 = *v6;
    v5 = name_to_action_in_game_world[0].action.m_end + 1;
    ++v6;
    ++name_to_action_in_game_world[0].action.m_end;
  }
  while ( *v6 );
  *v5 = 0;
  v7 = name_to_action_in_game_world[1].name.m_buffer;
  name_to_action_in_game_world[1].name.m_begin = name_to_action_in_game_world[1].name.m_buffer;
  name_to_action_in_game_world[1].name.m_end = name_to_action_in_game_world[1].name.m_buffer;
  name_to_action_in_game_world[1].name.m_max_end = (char *)&name_to_action_in_game_world[1].action;
  name_to_action_in_game_world[1].name.m_buffer[0] = 0;
  v8 = "st_mm_button_settings";
  do
  {
    if ( v7 >= name_to_action_in_game_world[1].name.m_max_end )
      break;
    *v7 = *v8;
    v7 = name_to_action_in_game_world[1].name.m_end + 1;
    ++v8;
    ++name_to_action_in_game_world[1].name.m_end;
  }
  while ( *v8 );
  *v7 = 0;
  v9 = name_to_action_in_game_world[1].action.m_buffer;
  name_to_action_in_game_world[1].action.m_begin = name_to_action_in_game_world[1].action.m_buffer;
  name_to_action_in_game_world[1].action.m_end = name_to_action_in_game_world[1].action.m_buffer;
  name_to_action_in_game_world[1].action.m_max_end = (char *)&name_to_action_in_game_world[2];
  name_to_action_in_game_world[1].action.m_buffer[0] = 0;
  v10 = "settings";
  do
  {
    if ( v9 >= name_to_action_in_game_world[1].action.m_max_end )
      break;
    *v9 = *v10;
    v9 = name_to_action_in_game_world[1].action.m_end + 1;
    ++v10;
    ++name_to_action_in_game_world[1].action.m_end;
  }
  while ( *v10 );
  *v9 = 0;
  v11 = name_to_action_in_game_world[2].name.m_buffer;
  name_to_action_in_game_world[2].name.m_begin = name_to_action_in_game_world[2].name.m_buffer;
  name_to_action_in_game_world[2].name.m_end = name_to_action_in_game_world[2].name.m_buffer;
  name_to_action_in_game_world[2].name.m_max_end = (char *)&name_to_action_in_game_world[2].action;
  name_to_action_in_game_world[2].name.m_buffer[0] = 0;
  v12 = "st_mm_button_leave_match";
  do
  {
    if ( v11 >= name_to_action_in_game_world[2].name.m_max_end )
      break;
    *v11 = *v12;
    v11 = name_to_action_in_game_world[2].name.m_end + 1;
    ++v12;
    ++name_to_action_in_game_world[2].name.m_end;
  }
  while ( *v12 );
  *v11 = 0;
  v13 = name_to_action_in_game_world[2].action.m_buffer;
  name_to_action_in_game_world[2].action.m_begin = name_to_action_in_game_world[2].action.m_buffer;
  name_to_action_in_game_world[2].action.m_end = name_to_action_in_game_world[2].action.m_buffer;
  name_to_action_in_game_world[2].action.m_max_end = (char *)&name_to_action_in_game_world[3];
  name_to_action_in_game_world[2].action.m_buffer[0] = 0;
  v14 = "leave_match";
  do
  {
    if ( v13 >= name_to_action_in_game_world[2].action.m_max_end )
      break;
    *v13 = *v14;
    v13 = name_to_action_in_game_world[2].action.m_end + 1;
    ++v14;
    ++name_to_action_in_game_world[2].action.m_end;
  }
  while ( *v14 );
  *v13 = 0;
  v15 = name_to_action_in_game_world[3].name.m_buffer;
  name_to_action_in_game_world[3].name.m_begin = name_to_action_in_game_world[3].name.m_buffer;
  name_to_action_in_game_world[3].name.m_end = name_to_action_in_game_world[3].name.m_buffer;
  name_to_action_in_game_world[3].name.m_max_end = (char *)&name_to_action_in_game_world[3].action;
  name_to_action_in_game_world[3].name.m_buffer[0] = 0;
  v16 = "st_mm_button_exit_to_os";
  do
  {
    if ( v15 >= name_to_action_in_game_world[3].name.m_max_end )
      break;
    *v15 = *v16;
    v15 = name_to_action_in_game_world[3].name.m_end + 1;
    ++v16;
    ++name_to_action_in_game_world[3].name.m_end;
  }
  while ( *v16 );
  *v15 = 0;
  v17 = name_to_action_in_game_world[3].action.m_buffer;
  name_to_action_in_game_world[3].action.m_begin = name_to_action_in_game_world[3].action.m_buffer;
  name_to_action_in_game_world[3].action.m_end = name_to_action_in_game_world[3].action.m_buffer;
  name_to_action_in_game_world[3].action.m_max_end = (char *)button_txt;
  name_to_action_in_game_world[3].action.m_buffer[0] = 0;
  v18 = "exit_to_os";
  do
  {
    if ( v17 >= name_to_action_in_game_world[3].action.m_max_end )
      break;
    *v17 = *v18;
    v17 = name_to_action_in_game_world[3].action.m_end + 1;
    ++v18;
    ++name_to_action_in_game_world[3].action.m_end;
  }
  while ( *v18 );
  *v17 = 0;
  v19 = name_to_action_in_lobby_menu[0].name.m_buffer;
  name_to_action_in_lobby_menu[0].name.m_begin = name_to_action_in_lobby_menu[0].name.m_buffer;
  name_to_action_in_lobby_menu[0].name.m_end = name_to_action_in_lobby_menu[0].name.m_buffer;
  name_to_action_in_lobby_menu[0].name.m_max_end = (char *)&name_to_action_in_lobby_menu[0].action;
  name_to_action_in_lobby_menu[0].name.m_buffer[0] = 0;
  v20 = "st_mm_button_back";
  do
  {
    if ( v19 >= name_to_action_in_lobby_menu[0].name.m_max_end )
      break;
    *v19 = *v20;
    v19 = name_to_action_in_lobby_menu[0].name.m_end + 1;
    ++v20;
    ++name_to_action_in_lobby_menu[0].name.m_end;
  }
  while ( *v20 );
  *v19 = 0;
  v21 = name_to_action_in_lobby_menu[0].action.m_buffer;
  name_to_action_in_lobby_menu[0].action.m_begin = name_to_action_in_lobby_menu[0].action.m_buffer;
  name_to_action_in_lobby_menu[0].action.m_end = name_to_action_in_lobby_menu[0].action.m_buffer;
  name_to_action_in_lobby_menu[0].action.m_max_end = (char *)&name_to_action_in_lobby_menu[1];
  name_to_action_in_lobby_menu[0].action.m_buffer[0] = 0;
  v22 = "back";
  do
  {
    if ( v21 >= name_to_action_in_lobby_menu[0].action.m_max_end )
      break;
    *v21 = *v22;
    v21 = name_to_action_in_lobby_menu[0].action.m_end + 1;
    ++v22;
    ++name_to_action_in_lobby_menu[0].action.m_end;
  }
  while ( *v22 );
  *v21 = 0;
  v23 = name_to_action_in_lobby_menu[1].name.m_buffer;
  name_to_action_in_lobby_menu[1].name.m_begin = name_to_action_in_lobby_menu[1].name.m_buffer;
  name_to_action_in_lobby_menu[1].name.m_end = name_to_action_in_lobby_menu[1].name.m_buffer;
  name_to_action_in_lobby_menu[1].name.m_max_end = (char *)&name_to_action_in_lobby_menu[1].action;
  name_to_action_in_lobby_menu[1].name.m_buffer[0] = 0;
  v24 = "st_mm_button_settings";
  do
  {
    if ( v23 >= name_to_action_in_lobby_menu[1].name.m_max_end )
      break;
    *v23 = *v24;
    v23 = name_to_action_in_lobby_menu[1].name.m_end + 1;
    ++v24;
    ++name_to_action_in_lobby_menu[1].name.m_end;
  }
  while ( *v24 );
  *v23 = 0;
  v25 = name_to_action_in_lobby_menu[1].action.m_buffer;
  name_to_action_in_lobby_menu[1].action.m_begin = name_to_action_in_lobby_menu[1].action.m_buffer;
  name_to_action_in_lobby_menu[1].action.m_end = name_to_action_in_lobby_menu[1].action.m_buffer;
  name_to_action_in_lobby_menu[1].action.m_max_end = (char *)&name_to_action_in_lobby_menu[2];
  name_to_action_in_lobby_menu[1].action.m_buffer[0] = 0;
  v26 = "settings";
  do
  {
    if ( v25 >= name_to_action_in_lobby_menu[1].action.m_max_end )
      break;
    *v25 = *v26;
    v25 = name_to_action_in_lobby_menu[1].action.m_end + 1;
    ++v26;
    ++name_to_action_in_lobby_menu[1].action.m_end;
  }
  while ( *v26 );
  *v25 = 0;
  v27 = name_to_action_in_lobby_menu[2].name.m_buffer;
  name_to_action_in_lobby_menu[2].name.m_begin = name_to_action_in_lobby_menu[2].name.m_buffer;
  name_to_action_in_lobby_menu[2].name.m_end = name_to_action_in_lobby_menu[2].name.m_buffer;
  name_to_action_in_lobby_menu[2].name.m_max_end = (char *)&name_to_action_in_lobby_menu[2].action;
  name_to_action_in_lobby_menu[2].name.m_buffer[0] = 0;
  v28 = "st_mm_button_exit_to_os";
  do
  {
    if ( v27 >= name_to_action_in_lobby_menu[2].name.m_max_end )
      break;
    *v27 = *v28;
    v27 = name_to_action_in_lobby_menu[2].name.m_end + 1;
    ++v28;
    ++name_to_action_in_lobby_menu[2].name.m_end;
  }
  while ( *v28 );
  *v27 = 0;
  v29 = name_to_action_in_lobby_menu[2].action.m_buffer;
  name_to_action_in_lobby_menu[2].action.m_begin = name_to_action_in_lobby_menu[2].action.m_buffer;
  name_to_action_in_lobby_menu[2].action.m_end = name_to_action_in_lobby_menu[2].action.m_buffer;
  name_to_action_in_lobby_menu[2].action.m_max_end = (char *)name_to_action_in_game_world;
  name_to_action_in_lobby_menu[2].action.m_buffer[0] = 0;
  v30 = "exit_to_os";
  do
  {
    if ( v29 >= name_to_action_in_lobby_menu[2].action.m_max_end )
      break;
    *v29 = *v30;
    v29 = name_to_action_in_lobby_menu[2].action.m_end + 1;
    ++v30;
    ++name_to_action_in_lobby_menu[2].action.m_end;
  }
  while ( *v30 );
  v31 = in_game_world;
  *v29 = 0;
  m_object = in_game_world->m_options_ui.m_object;
  *(_DWORD *)buttons_array.body = 0;
  *(_DWORD *)&buttons_array.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&buttons_array);
  if ( in_game_worlda )
  {
    v33 = name_to_action_in_game_world;
    v34 = 4;
  }
  else
  {
    v33 = name_to_action_in_lobby_menu;
    v34 = 3;
  }
  v35 = 0;
  v39 = v34;
  do
  {
    v36 = v31->m_options_ui.m_object;
    *(_DWORD *)button.body = 0;
    *(_DWORD *)&button.body[4] = 0;
    Scaleform::GFx::Movie::CreateObject(v36->movie->m_movie, (Scaleform::GFx::Value *)&button, 0, 0, 0);
    *(_DWORD *)&button_member.body[8] = v33->action.m_begin;
    *(_DWORD *)button_member.body = 0;
    *(_DWORD *)&button_member.body[4] = 6;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)button.body + 20))(
      *(_DWORD *)button.body,
      *(_DWORD *)&button.body[8],
      "action",
      &button_member,
      (button.body[4] & 0x8F) == 10);
    survarium::text_translator::translate_text(&v31->m_game->m_text_translator, v33->name.m_begin, button_txt);
    v37 = 0;
    v42 = 0;
    v43 = 7;
    v44 = button_txt;
    if ( (button_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)button_member.body + 8))(
        *(_DWORD *)button_member.body,
        &button_member,
        *(_DWORD *)&button_member.body[8]);
      v37 = v42;
      *(_DWORD *)button_member.body = 0;
    }
    *(_DWORD *)&button_member.body[4] = 7;
    *(_DWORD *)&button_member.body[8] = button_txt;
    if ( (v43 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v37 + 8))(v37, &v42, v44);
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)button.body + 20))(
      *(_DWORD *)button.body,
      *(_DWORD *)&button.body[8],
      "label",
      &button_member,
      (button.body[4] & 0x8F) == 10);
    (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)buttons_array.body + 52))(
      *(_DWORD *)buttons_array.body,
      *(_DWORD *)&buttons_array.body[8],
      v35,
      &button);
    if ( (button_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)button_member.body + 8))(
        *(_DWORD *)button_member.body,
        &button_member,
        *(_DWORD *)&button_member.body[8]);
      *(_DWORD *)button_member.body = 0;
    }
    *(_DWORD *)&button_member.body[4] = 0;
    if ( (button.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)button.body + 8))(
        *(_DWORD *)button.body,
        &button,
        *(_DWORD *)&button.body[8]);
    v31 = in_game_world;
    ++v35;
    ++v33;
    --v39;
  }
  while ( v39 );
  Scaleform::GFx::Movie::Invoke(
    in_game_world->m_options_ui.m_object->movie->m_movie,
    "root.set_options",
    0,
    (const Scaleform::GFx::Value *)&buttons_array,
    1u);
  if ( (buttons_array.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)buttons_array.body + 8))(
      *(_DWORD *)buttons_array.body,
      &buttons_array,
      *(_DWORD *)&buttons_array.body[8]);
}
