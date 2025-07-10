void __thiscall survarium::game_world_ui::initialize(
        survarium::game_world_ui *this,
        survarium::game_world_ui *options,
        survarium::match_options *optionsa)
{
  survarium::game_world *m_game_world; // edx
  unsigned int m_object; // edx
  unsigned __int8 victory_items_count; // cl
  survarium::game_team_id *p_team; // eax
  int v7; // edx
  int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  char *v12; // ebp
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  int v15; // esi
  int v16; // ecx
  survarium::flash_value player_item_property; // [esp+B4h] [ebp-4FCh] BYREF
  int v18; // [esp+CCh] [ebp-4E4h]
  survarium::flash_value player_item; // [esp+D0h] [ebp-4E0h] BYREF
  survarium::flash_value v; // [esp+E8h] [ebp-4C8h] BYREF
  int v21; // [esp+100h] [ebp-4B0h]
  survarium::game_team_id local_player_team; // [esp+104h] [ebp-4ACh]
  unsigned int pConvertedChars; // [esp+108h] [ebp-4A8h] BYREF
  survarium::flash_value players_array; // [esp+10Ch] [ebp-4A4h] BYREF
  survarium::flash_value game_mode_val; // [esp+124h] [ebp-48Ch] BYREF
  survarium::flash_value victory_items_count_val; // [esp+13Ch] [ebp-474h] BYREF
  int v27; // [esp+154h] [ebp-45Ch] BYREF
  int v28; // [esp+158h] [ebp-458h]
  wchar_t *v29; // [esp+15Ch] [ebp-454h]
  wchar_t profile_name_w[32]; // [esp+16Ch] [ebp-444h] BYREF
  wchar_t team_name[514]; // [esp+1ACh] [ebp-404h] BYREF

  m_game_world = options->m_game_world;
  *(_DWORD *)v.body = 0;
  *(_DWORD *)&v.body[4] = 0;
  survarium::text_translator::translate_text(&m_game_world->m_game->m_text_translator, "st_label_teamA", team_name);
  survarium::flash_value::SetStringW(&v, team_name);
  Scaleform::GFx::Movie::SetVariable(
    options->m_game_hud_ui.m_object->movie->m_movie,
    "root.player_list.players.team1.text",
    (const Scaleform::GFx::Value *)&v,
    SV_Sticky);
  survarium::text_translator::translate_text(
    &options->m_game_world->m_game->m_text_translator,
    "st_label_teamB",
    team_name);
  survarium::flash_value::SetStringW(&v, team_name);
  Scaleform::GFx::Movie::SetVariable(
    options->m_game_hud_ui.m_object->movie->m_movie,
    "root.player_list.players.team2.text",
    (const Scaleform::GFx::Value *)&v,
    SV_Sticky);
  if ( (v.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)v.body + 8))(
      *(_DWORD *)v.body,
      &v,
      *(_DWORD *)&v.body[8]);
    *(_DWORD *)v.body = 0;
  }
  m_object = (unsigned int)options->m_game_hud_ui.m_object;
  *(_DWORD *)&v.body[4] = 4;
  *(_DWORD *)&v.body[8] = &vostok::memory::s_CRT_arena[5508664];
  Scaleform::GFx::Movie::SetVariable(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object + 264) + 4),
    "root.player_list.players.team2.textColor",
    (const Scaleform::GFx::Value *)&v,
    SV_Sticky);
  options->m_game_mode = optionsa->match_mode_;
  options->m_match_time = optionsa->match_time;
  victory_items_count = optionsa->victory_items_count;
  options->m_victory_items_count = victory_items_count;
  local_player_team = team_undefined;
  p_team = &optionsa->player_profiles[0].team;
  v7 = 20;
  do
  {
    if ( *((_BYTE *)p_team + 4) )
      local_player_team = *p_team;
    p_team += 110;
    --v7;
  }
  while ( v7 );
  v8 = victory_items_count;
  v9 = (unsigned int)options->m_game_hud_ui.m_object;
  *(_DWORD *)&victory_items_count_val.body[8] = v8;
  *(_DWORD *)victory_items_count_val.body = 0;
  *(_DWORD *)&victory_items_count_val.body[4] = 4;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v9 + 264) + 4),
    "root.set_artifacts_required",
    0,
    (const Scaleform::GFx::Value *)&victory_items_count_val,
    1u);
  v10 = (unsigned int)options->m_game_hud_ui.m_object;
  *(_DWORD *)&game_mode_val.body[8] = options->m_game_mode;
  *(_DWORD *)game_mode_val.body = 0;
  *(_DWORD *)&game_mode_val.body[4] = 4;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v10 + 264) + 4),
    "root.set_game_type",
    0,
    (const Scaleform::GFx::Value *)&game_mode_val,
    1u);
  v11 = (unsigned int)options->m_game_hud_ui.m_object;
  *(_DWORD *)players_array.body = 0;
  *(_DWORD *)&players_array.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v11 + 264) + 4),
    (Scaleform::GFx::Value *)&players_array);
  v18 = 0;
  v12 = (char *)&optionsa->player_profiles[0].team;
  v21 = 20;
  do
  {
    if ( *(_DWORD *)v12 != 3 )
    {
      v13 = (unsigned int)options->m_game_hud_ui.m_object;
      *(_DWORD *)player_item.body = 0;
      *(_DWORD *)&player_item.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(v13 + 264) + 4),
        (Scaleform::GFx::Value *)&player_item,
        0,
        0,
        0);
      v14 = (unsigned int)options->m_game_hud_ui.m_object;
      *(_DWORD *)player_item_property.body = 0;
      *(_DWORD *)&player_item_property.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(v14 + 264) + 4),
        (Scaleform::GFx::Value *)&player_item_property,
        0,
        0,
        0);
      if ( (player_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_item_property.body + 8))(
          *(_DWORD *)player_item_property.body,
          &player_item_property,
          *(_DWORD *)&player_item_property.body[8]);
        *(_DWORD *)player_item_property.body = 0;
      }
      *(_DWORD *)&player_item_property.body[8] = v18;
      *(_DWORD *)&player_item_property.body[4] = 3;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_item.body
                                                                                           + 20))(
        *(_DWORD *)player_item.body,
        *(_DWORD *)&player_item.body[8],
        "id",
        &player_item_property,
        (player_item.body[4] & 0x8F) == 10);
      v15 = (*(_DWORD *)v12 != local_player_team) + 1;
      if ( (player_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_item_property.body + 8))(
          *(_DWORD *)player_item_property.body,
          &player_item_property,
          *(_DWORD *)&player_item_property.body[8]);
        *(_DWORD *)player_item_property.body = 0;
      }
      *(_DWORD *)&player_item_property.body[4] = 3;
      *(_DWORD *)&player_item_property.body[8] = v15;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_item.body
                                                                                           + 20))(
        *(_DWORD *)player_item.body,
        *(_DWORD *)&player_item.body[8],
        "team",
        &player_item_property,
        (player_item.body[4] & 0x8F) == 10);
      pConvertedChars = 0;
      mbstowcs_s(&pConvertedChars, profile_name_w, 0x20u, v12 - 424, 0xFFFFFFFF);
      v16 = 0;
      v27 = 0;
      v28 = 7;
      v29 = profile_name_w;
      if ( (player_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_item_property.body + 8))(
          *(_DWORD *)player_item_property.body,
          &player_item_property,
          *(_DWORD *)&player_item_property.body[8]);
        v16 = v27;
        *(_DWORD *)player_item_property.body = 0;
      }
      *(_DWORD *)&player_item_property.body[4] = 7;
      *(_DWORD *)&player_item_property.body[8] = profile_name_w;
      if ( (v28 & 0x40) != 0 )
        (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v16 + 8))(v16, &v27, v29);
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_item.body
                                                                                           + 20))(
        *(_DWORD *)player_item.body,
        *(_DWORD *)&player_item.body[8],
        "name",
        &player_item_property,
        (player_item.body[4] & 0x8F) == 10);
      if ( (player_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_item_property.body + 8))(
          *(_DWORD *)player_item_property.body,
          &player_item_property,
          *(_DWORD *)&player_item_property.body[8]);
        *(_DWORD *)player_item_property.body = 0;
      }
      *(_DWORD *)&player_item_property.body[4] = 3;
      *(_DWORD *)&player_item_property.body[8] = 66;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_item.body
                                                                                           + 20))(
        *(_DWORD *)player_item.body,
        *(_DWORD *)&player_item.body[8],
        "ping",
        &player_item_property,
        (player_item.body[4] & 0x8F) == 10);
      if ( (player_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_item_property.body + 8))(
          *(_DWORD *)player_item_property.body,
          &player_item_property,
          *(_DWORD *)&player_item_property.body[8]);
        *(_DWORD *)player_item_property.body = 0;
      }
      *(_DWORD *)&player_item_property.body[4] = 3;
      *(_DWORD *)&player_item_property.body[8] = 0;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_item.body
                                                                                           + 20))(
        *(_DWORD *)player_item.body,
        *(_DWORD *)&player_item.body[8],
        "rank",
        &player_item_property,
        (player_item.body[4] & 0x8F) == 10);
      if ( (player_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_item_property.body + 8))(
          *(_DWORD *)player_item_property.body,
          &player_item_property,
          *(_DWORD *)&player_item_property.body[8]);
        *(_DWORD *)player_item_property.body = 0;
      }
      *(_DWORD *)&player_item_property.body[4] = 3;
      *(_DWORD *)&player_item_property.body[8] = 0;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_item.body
                                                                                           + 20))(
        *(_DWORD *)player_item.body,
        *(_DWORD *)&player_item.body[8],
        "artifacts",
        &player_item_property,
        (player_item.body[4] & 0x8F) == 10);
      (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)players_array.body + 52))(
        *(_DWORD *)players_array.body,
        *(_DWORD *)&players_array.body[8],
        v18,
        &player_item);
      if ( (player_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_item_property.body + 8))(
          *(_DWORD *)player_item_property.body,
          &player_item_property,
          *(_DWORD *)&player_item_property.body[8]);
        *(_DWORD *)player_item_property.body = 0;
      }
      *(_DWORD *)&player_item_property.body[4] = 0;
      if ( (player_item.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_item.body + 8))(
          *(_DWORD *)player_item.body,
          &player_item,
          *(_DWORD *)&player_item.body[8]);
    }
    ++v18;
    v12 += 440;
    --v21;
  }
  while ( v21 );
  Scaleform::GFx::Movie::Invoke(
    options->m_game_hud_ui.m_object->movie->m_movie,
    "root.list_set_players",
    0,
    (const Scaleform::GFx::Value *)&players_array,
    1u);
  if ( (players_array.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)players_array.body + 8))(
      *(_DWORD *)players_array.body,
      &players_array,
      *(_DWORD *)&players_array.body[8]);
    *(_DWORD *)players_array.body = 0;
  }
  *(_DWORD *)&players_array.body[4] = 0;
  if ( (game_mode_val.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)game_mode_val.body + 8))(
      *(_DWORD *)game_mode_val.body,
      &game_mode_val,
      *(_DWORD *)&game_mode_val.body[8]);
    *(_DWORD *)game_mode_val.body = 0;
  }
  *(_DWORD *)&game_mode_val.body[4] = 0;
  if ( (victory_items_count_val.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)victory_items_count_val.body + 8))(
      *(_DWORD *)victory_items_count_val.body,
      &victory_items_count_val,
      *(_DWORD *)&victory_items_count_val.body[8]);
    *(_DWORD *)victory_items_count_val.body = 0;
  }
  *(_DWORD *)&victory_items_count_val.body[4] = 0;
  if ( (v.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)v.body + 8))(
      *(_DWORD *)v.body,
      &v,
      *(_DWORD *)&v.body[8]);
}
