BOOL __fastcall survarium::operator==(const survarium::player_input *second, const survarium::player_input *first)
{
  return first->rotation_delta.x == second->rotation_delta.x
      && first->rotation_delta.y == second->rotation_delta.y
      && first->actions_mask == second->actions_mask;
}
