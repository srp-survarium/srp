void __userpurge survarium::game_world_ui::set_local_respawn_time(
        unsigned int time_left_sec@<eax>,
        survarium::text_translator *a2@<ecx>,
        survarium::game_world_ui *this)
{
  unsigned int v4; // edi
  char v5[512]; // [esp+10h] [ebp-41Ch] BYREF
  char string[512]; // [esp+210h] [ebp-21Ch] BYREF
  survarium::flash_value v7; // [esp+410h] [ebp-1Ch] BYREF

  memset(string, 0, sizeof(string));
  v4 = time_left_sec / 0x3C;
  if ( time_left_sec )
  {
    survarium::text_translator::translate_text(
      a2,
      (int)&this->m_game_world->m_game->m_text_translator,
      "st_respawn_time_pref",
      v5);
    sprintf_s(string, 0x200u, "%s %02d:%02d", v5, v4, time_left_sec - 60 * v4);
  }
  *(_DWORD *)v7.body = 0;
  *(_DWORD *)&v7.body[4] = 0;
  survarium::flash_value::SetString(&v7, string);
  Scaleform::GFx::Movie::Invoke(
    this->m_game_hud_ui.m_object->movie->m_movie,
    "root.set_respawn_time",
    0,
    (const Scaleform::GFx::Value *)&v7,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v7);
}
