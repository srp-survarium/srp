void __userpurge survarium::lobby_menu::on_match_message_arrived(
        const wchar_t *w_text@<eax>,
        survarium::lobby_menu *this)
{
  unsigned __int16 *v3; // esi
  unsigned __int16 *v4; // eax
  unsigned __int16 *v5; // esi
  unsigned __int16 *v6; // eax
  survarium::flash_movie_resource *m_object; // edx
  const wchar_t *v8; // esi
  unsigned __int16 *v9; // eax
  unsigned __int16 *v10; // eax
  survarium::flash_value players_in_queue_val; // [esp+40h] [ebp-C4h] BYREF
  const wchar_t *queue_state_message; // [esp+58h] [ebp-ACh]
  const wchar_t *player_left_message; // [esp+5Ch] [ebp-A8h]
  survarium::game_team_id team; // [esp+60h] [ebp-A4h]
  survarium::flash_value add_player_args[2]; // [esp+64h] [ebp-A0h] BYREF
  wchar_t w_player_team[8]; // [esp+94h] [ebp-70h] BYREF
  wchar_t w_player_in_queue[16]; // [esp+A4h] [ebp-60h] BYREF
  wchar_t w_player_name[32]; // [esp+C4h] [ebp-40h] BYREF

  v3 = wcsstr(w_text, L"#+p:[ ");
  player_left_message = wcsstr(w_text, L"#-p:[ ");
  queue_state_message = wcsstr(w_text, L"#q:[");
  if ( v3 )
  {
    v4 = wcsstr(v3, L" ]");
    wcsncpy_s(0, w_player_name, 0x20u, v3 + 6, v4 - v3 - 6);
    v5 = wcsstr(w_text, L"#t:[");
    v6 = wcsstr(v5, L"]");
    wcsncpy_s(0, w_player_team, 8u, v5 + 4, v6 - v5 - 4);
    team = _wtoi(w_player_team);
    `vector constructor iterator'(
      add_player_args[0].body,
      0x18u,
      2,
      (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
    Scaleform::GFx::Movie::CreateObject(
      this->m_match_making_ui.m_object->movie->m_movie,
      (Scaleform::GFx::Value *)add_player_args,
      0,
      0,
      0);
    *(_DWORD *)players_in_queue_val.body = 0;
    *(_DWORD *)&players_in_queue_val.body[4] = 0;
    survarium::flash_value::SetStringW(&players_in_queue_val, w_player_name);
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)add_player_args[0].body
                                                                                         + 20))(
      *(_DWORD *)add_player_args[0].body,
      *(_DWORD *)&add_player_args[0].body[8],
      "name",
      &players_in_queue_val,
      (add_player_args[0].body[4] & 0x8F) == 10);
    if ( (players_in_queue_val.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)players_in_queue_val.body + 8))(
        *(_DWORD *)players_in_queue_val.body,
        &players_in_queue_val,
        *(_DWORD *)&players_in_queue_val.body[8]);
      *(_DWORD *)players_in_queue_val.body = 0;
    }
    *(_DWORD *)&players_in_queue_val.body[4] = 4;
    *(_DWORD *)&players_in_queue_val.body[8] = 0;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)add_player_args[0].body
                                                                                         + 20))(
      *(_DWORD *)add_player_args[0].body,
      *(_DWORD *)&add_player_args[0].body[8],
      "icon",
      &players_in_queue_val,
      (add_player_args[0].body[4] & 0x8F) == 10);
    if ( (add_player_args[1].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)add_player_args[1].body + 8))(
        *(_DWORD *)add_player_args[1].body,
        &add_player_args[1],
        *(_DWORD *)&add_player_args[1].body[8]);
      *(_DWORD *)add_player_args[1].body = 0;
    }
    m_object = this->m_match_making_ui.m_object;
    *(_DWORD *)&add_player_args[1].body[4] = 4;
    *(_DWORD *)&add_player_args[1].body[8] = team;
    Scaleform::GFx::Movie::Invoke(
      m_object->movie->m_movie,
      "root.add_player",
      0,
      (const Scaleform::GFx::Value *)add_player_args,
      2u);
    if ( (players_in_queue_val.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)players_in_queue_val.body + 8))(
        *(_DWORD *)players_in_queue_val.body,
        &players_in_queue_val,
        *(_DWORD *)&players_in_queue_val.body[8]);
      *(_DWORD *)players_in_queue_val.body = 0;
    }
    *(_DWORD *)&players_in_queue_val.body[4] = 0;
    `vector destructor iterator'(
      add_player_args[0].body,
      0x18u,
      2,
      (void (__thiscall *)(void *))survarium::flash_value::~flash_value);
  }
  v8 = player_left_message;
  if ( player_left_message )
  {
    v9 = wcsstr(player_left_message, L" ]");
    wcsncpy_s(0, w_player_name, 0x20u, v8 + 6, v9 - v8 - 6);
    *(_DWORD *)players_in_queue_val.body = 0;
    *(_DWORD *)&players_in_queue_val.body[4] = 0;
    survarium::flash_value::SetStringW(&players_in_queue_val, w_player_name);
    Scaleform::GFx::Movie::Invoke(
      this->m_match_making_ui.m_object->movie->m_movie,
      "root.remove_player",
      0,
      (const Scaleform::GFx::Value *)&players_in_queue_val,
      1u);
    if ( (players_in_queue_val.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)players_in_queue_val.body + 8))(
        *(_DWORD *)players_in_queue_val.body,
        &players_in_queue_val,
        *(_DWORD *)&players_in_queue_val.body[8]);
  }
  if ( queue_state_message )
  {
    v10 = wcsstr(queue_state_message, L"]");
    wcsncpy_s(0, w_player_in_queue, 0x10u, queue_state_message + 4, v10 - queue_state_message - 4);
    *(_DWORD *)players_in_queue_val.body = 0;
    *(_DWORD *)&players_in_queue_val.body[4] = 0;
    survarium::flash_value::SetStringW(&players_in_queue_val, w_player_in_queue);
    Scaleform::GFx::Movie::Invoke(
      this->m_match_making_ui.m_object->movie->m_movie,
      "root.set_place",
      0,
      (const Scaleform::GFx::Value *)&players_in_queue_val,
      1u);
    if ( (players_in_queue_val.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)players_in_queue_val.body + 8))(
        *(_DWORD *)players_in_queue_val.body,
        &players_in_queue_val,
        *(_DWORD *)&players_in_queue_val.body[8]);
  }
}
