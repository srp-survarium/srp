unsigned int __cdecl survarium::player_logic_base_state::movement_animation_index(const survarium::player_input *input)
{
  bool move_bwd_pressed; // [esp+0h] [ebp-4h]
  bool move_right_pressed; // [esp+1h] [ebp-3h]
  bool move_fwd_pressed; // [esp+2h] [ebp-2h]
  bool move_left_pressed; // [esp+3h] [ebp-1h]

  move_fwd_pressed = (input->actions_mask & 1) != 0;
  move_bwd_pressed = (input->actions_mask & 2) != 0;
  move_left_pressed = (input->actions_mask & 4) != 0;
  move_right_pressed = (input->actions_mask & 8) != 0;
  if ( (input->actions_mask & 1) != 0 && (input->actions_mask & 2) != 0 )
  {
    move_fwd_pressed = 0;
    move_bwd_pressed = 0;
  }
  if ( (input->actions_mask & 4) != 0 && (input->actions_mask & 8) != 0 )
  {
    move_left_pressed = 0;
    move_right_pressed = 0;
  }
  if ( move_fwd_pressed )
  {
    if ( move_left_pressed )
    {
      return 24;
    }
    else if ( move_right_pressed )
    {
      return 6;
    }
    else
    {
      return 3;
    }
  }
  else if ( move_bwd_pressed )
  {
    if ( move_left_pressed )
    {
      return 18;
    }
    else if ( move_right_pressed )
    {
      return 12;
    }
    else
    {
      return 15;
    }
  }
  else if ( move_left_pressed )
  {
    return 21;
  }
  else if ( move_right_pressed )
  {
    return 9;
  }
  else
  {
    return 0;
  }
}
