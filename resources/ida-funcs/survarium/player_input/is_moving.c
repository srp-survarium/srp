BOOL __thiscall survarium::player_input::is_moving(survarium::player_input *this)
{
  BOOL result; // eax

  result = 1;
  if ( (this->actions_mask & 1) == (this->actions_mask & 2) )
    return (this->actions_mask & 8) != (this->actions_mask & 4);
  return result;
}
