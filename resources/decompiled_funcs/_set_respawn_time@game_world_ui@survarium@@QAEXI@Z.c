void __thiscall survarium::game_world_ui::set_respawn_time(
        survarium::game_world_ui *this,
        survarium::game_world_ui *time_left)
{
  survarium::flash_value respawn_time_str; // [esp+8h] [ebp-58h] BYREF
  char buff[64]; // [esp+20h] [ebp-40h] BYREF

  if ( this )
    vostok::sprintf<64>(
      (char (*)[64])buff,
      "WILL RESPAWN IN  %02d : %02d",
      (unsigned int)this / 0x3C,
      (unsigned int)this % 0x3C);
  else
    vostok::sprintf<64>((char (*)[64])buff, (const char *)&buf);
  *(_DWORD *)respawn_time_str.body = 0;
  *(_DWORD *)&respawn_time_str.body[4] = 0;
  survarium::flash_value::SetString(&respawn_time_str, buff);
  Scaleform::GFx::Movie::Invoke(
    time_left->m_game_hud_ui.m_object->movie->m_movie,
    "root.set_respawn_time",
    0,
    (const Scaleform::GFx::Value *)&respawn_time_str,
    1u);
  if ( (respawn_time_str.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)respawn_time_str.body + 8))(
      *(_DWORD *)respawn_time_str.body,
      &respawn_time_str,
      *(_DWORD *)&respawn_time_str.body[8]);
}
