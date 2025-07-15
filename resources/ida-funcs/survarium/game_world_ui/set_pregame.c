void __userpurge survarium::game_world_ui::set_pregame(
        unsigned int time_left_sec@<eax>,
        survarium::game_world_ui *this,
        char *str)
{
  unsigned int v4; // edi
  char string[512]; // [esp+10h] [ebp-418h] BYREF
  char v6[512]; // [esp+210h] [ebp-218h] BYREF
  survarium::flash_value v7; // [esp+410h] [ebp-18h] BYREF

  v4 = time_left_sec / 0x3C;
  survarium::text_translator::translate_text(
    (survarium::text_translator *)0x3C,
    (int)&this->m_game_world->m_game->m_text_translator,
    str,
    v6);
  sprintf_s(string, 0x200u, "%s %02d:%02d", v6, v4, time_left_sec - 60 * v4);
  *(_DWORD *)v7.body = 0;
  *(_DWORD *)&v7.body[4] = 0;
  survarium::flash_value::SetString(&v7, string);
  Scaleform::GFx::Movie::Invoke(
    this->m_game_hud_ui.m_object->movie->m_movie,
    "root.set_pregame",
    0,
    (const Scaleform::GFx::Value *)&v7,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v7);
}
