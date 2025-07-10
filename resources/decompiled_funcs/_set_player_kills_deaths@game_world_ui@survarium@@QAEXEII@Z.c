void __thiscall survarium::game_world_ui::set_player_kills_deaths(
        survarium::game_world_ui *this,
        survarium::game_world_ui *player_id,
        unsigned __int8 kills,
        unsigned int deaths,
        unsigned int deathsa)
{
  survarium::flash_movie_resource *m_object; // ecx
  survarium::flash_movie_resource *v6; // ecx
  survarium::flash_value out_event_property; // [esp+98h] [ebp-34h] BYREF
  survarium::flash_value out_event; // [esp+B0h] [ebp-1Ch] BYREF

  m_object = player_id->m_game_hud_ui.m_object;
  *(_DWORD *)out_event.body = 0;
  *(_DWORD *)&out_event.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(m_object->movie->m_movie, (Scaleform::GFx::Value *)&out_event, 0, 0, 0);
  v6 = player_id->m_game_hud_ui.m_object;
  *(_DWORD *)out_event_property.body = 0;
  *(_DWORD *)&out_event_property.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(v6->movie->m_movie, (Scaleform::GFx::Value *)&out_event_property, 0, 0, 0);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[8] = kills;
  *(_DWORD *)&out_event_property.body[4] = 3;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "id",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[8] = deaths;
  *(_DWORD *)&out_event_property.body[4] = 3;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "kills",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[8] = deathsa;
  *(_DWORD *)&out_event_property.body[4] = 3;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "deaths",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[4] = 3;
  *(_DWORD *)&out_event_property.body[8] = 66;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "ping",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[4] = 3;
  *(_DWORD *)&out_event_property.body[8] = 0;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "rank",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[4] = 3;
  *(_DWORD *)&out_event_property.body[8] = 0;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "artifacts",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  Scaleform::GFx::Movie::Invoke(
    player_id->m_game_hud_ui.m_object->movie->m_movie,
    "root.list_update_player",
    0,
    (const Scaleform::GFx::Value *)&out_event,
    1u);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[4] = 0;
  if ( (out_event.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event.body + 8))(
      *(_DWORD *)out_event.body,
      &out_event,
      *(_DWORD *)&out_event.body[8]);
}
