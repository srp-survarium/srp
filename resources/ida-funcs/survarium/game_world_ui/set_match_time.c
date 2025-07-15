void __userpurge survarium::game_world_ui::set_match_time(
        unsigned int time_left_sec@<eax>,
        survarium::game_world_ui *this)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  char string[512]; // [esp+10h] [ebp-21Ch] BYREF
  survarium::flash_value v6; // [esp+210h] [ebp-1Ch] BYREF

  memset(string, 0, sizeof(string));
  if ( time_left_sec )
  {
    v3 = time_left_sec / 0x3C;
    v4 = time_left_sec % 0x3C;
    if ( v4 >= 0x3C )
    {
      ++v3;
      v4 -= 60;
    }
    sprintf_s(string, 0x200u, "%02d:%02d", v3, v4);
  }
  *(_DWORD *)v6.body = 0;
  *(_DWORD *)&v6.body[4] = 0;
  survarium::flash_value::SetString(&v6, string);
  Scaleform::GFx::Movie::Invoke(
    this->m_game_hud_ui.m_object->movie->m_movie,
    "root.set_match_time",
    0,
    (const Scaleform::GFx::Value *)&v6,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v6);
}
