bool __thiscall survarium::player_input::is_sprinting(survarium::player_input *this)
{
  return (this->actions_mask & 0x200) != 0 && (this->actions_mask & 1) != 0 && (this->actions_mask & 0x16E) == 0;
}
