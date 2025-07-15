int __thiscall survarium::player_logic_base_state::movement_animation_index(const survarium::player_input *input)
{
  unsigned int actions_mask; // ecx
  unsigned int v2; // edx
  char v3; // al
  bool v4; // bl
  bool v5; // cl
  char v6; // dl

  actions_mask = input->actions_mask;
  v2 = actions_mask >> 3;
  v3 = actions_mask & 1;
  v4 = (actions_mask & 2) != 0;
  v5 = (actions_mask & 4) != 0;
  v6 = v2 & 1;
  if ( v3 && v4 )
  {
    v3 = 0;
    v4 = 0;
  }
  if ( v5 )
  {
    if ( v6 )
    {
      v5 = 0;
      v6 = 0;
    }
  }
  if ( v3 )
  {
    if ( v5 )
      return 24;
    return v6 == 0 ? 3 : 6;
  }
  else if ( v4 )
  {
    if ( v5 )
      return 18;
    return v6 == 0 ? 15 : 12;
  }
  else
  {
    if ( v5 )
      return 21;
    return v6 != 0 ? 9 : 0;
  }
}
