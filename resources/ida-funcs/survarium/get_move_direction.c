int __thiscall survarium::get_move_direction(const survarium::player_input *input)
{
  unsigned int actions_mask; // esi
  char v2; // al
  bool v3; // dl
  bool v4; // cl
  bool v5; // bl

  actions_mask = input->actions_mask;
  v2 = actions_mask & 1;
  v3 = (actions_mask & 2) != 0;
  v4 = (actions_mask & 4) != 0;
  v5 = (actions_mask & 8) != 0;
  if ( (actions_mask & 1) != 0 && (actions_mask & 2) != 0 )
  {
    v2 = 0;
    v3 = 0;
  }
  if ( (actions_mask & 4) != 0 && (actions_mask & 8) != 0 )
  {
    v4 = 0;
    v5 = 0;
  }
  if ( v2 )
  {
    if ( v4 )
      return 8;
    return v5 + 1;
  }
  else if ( v3 )
  {
    if ( v4 )
      return 6;
    return !v5 + 4;
  }
  else
  {
    if ( v4 )
      return 7;
    return v5 ? 3 : 0;
  }
}
