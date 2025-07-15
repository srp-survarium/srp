void __userpurge survarium::game_world_ui::set_match_time(
        unsigned int time_left_ms@<eax>,
        survarium::game_world_ui *this)
{
  double v2; // st7
  unsigned int v3; // esi
  unsigned int v4; // eax
  float value; // [esp+0h] [ebp-6Ch]
  float valuea; // [esp+0h] [ebp-6Ch]
  float v7; // [esp+Ch] [ebp-60h]
  survarium::flash_value match_time_str; // [esp+14h] [ebp-58h] BYREF
  char buff[64]; // [esp+2Ch] [ebp-40h] BYREF

  if ( time_left_ms )
  {
    v2 = (double)time_left_ms;
    v7 = v2;
    value = v2 * 0.000016666667;
    v3 = vostok::math::floor(value);
    valuea = (v7 - (double)(60000 * v3)) * 0.001;
    v4 = vostok::math::floor(valuea);
    vostok::sprintf<64>((char (*)[64])buff, "MATCH TIME: %02d : %02d", v3, v4);
  }
  else
  {
    vostok::sprintf<64>((char (*)[64])buff, "MATCH TIME IS UP!!!!");
  }
  *(_DWORD *)match_time_str.body = 0;
  *(_DWORD *)&match_time_str.body[4] = 0;
  survarium::flash_value::SetString(&match_time_str, buff);
  Scaleform::GFx::Movie::Invoke(
    this->m_game_hud_ui.m_object->movie->m_movie,
    "root.set_match_time",
    0,
    (const Scaleform::GFx::Value *)&match_time_str,
    1u);
  if ( (match_time_str.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)match_time_str.body + 8))(
      *(_DWORD *)match_time_str.body,
      &match_time_str,
      *(_DWORD *)&match_time_str.body[8]);
}
