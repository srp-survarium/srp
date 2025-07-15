void __usercall survarium::game_world_ui::on_damage_affect_applying(
        survarium::game_world_ui *this@<esi>,
        const char *bodypart@<ecx>,
        const survarium::hit_affects_type_enum affect@<eax>,
        const survarium::affect_event_type_enum event_type@<edi>)
{
  const char *v4; // eax
  char v5; // dl
  unsigned __int8 v6; // al
  survarium::flash_movie_resource *v7; // eax
  survarium::flash_movie_resource *m_object; // ecx
  survarium::flash_value value; // [esp+0h] [ebp-1Ch] BYREF

  if ( affect == affects_type_hand_damage )
  {
    v4 = "left_hand";
    while ( *v4 == *bodypart )
    {
      if ( !*v4 )
        goto LABEL_7;
      v5 = v4[1];
      if ( v5 != bodypart[1] )
        break;
      v4 += 2;
      bodypart += 2;
      if ( !v5 )
      {
LABEL_7:
        v6 = 1;
        goto LABEL_11;
      }
    }
    v6 = 2;
  }
  else
  {
    if ( affect != affects_type_leg_damage )
      return;
    v6 = (strcmp("left_leg", bodypart) != 0) + 3;
  }
LABEL_11:
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  if ( event_type )
  {
    if ( event_type == affect_canceling || event_type == affect_recalling )
    {
      m_object = this->m_game_hud_ui.m_object;
      *(_DWORD *)&value.body[4] = 4;
      *(_DWORD *)&value.body[8] = v6;
      Scaleform::GFx::Movie::Invoke(
        m_object->movie->m_movie,
        "root.heal_player_body_part",
        0,
        (const Scaleform::GFx::Value *)&value,
        1u);
    }
  }
  else
  {
    *(_DWORD *)&value.body[8] = v6;
    v7 = this->m_game_hud_ui.m_object;
    *(_DWORD *)&value.body[4] = 4;
    Scaleform::GFx::Movie::Invoke(
      v7->movie->m_movie,
      "root.crit_player_body_part",
      0,
      (const Scaleform::GFx::Value *)&value,
      1u);
  }
  if ( (value.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
      *(_DWORD *)value.body,
      &value,
      *(_DWORD *)&value.body[8]);
}
