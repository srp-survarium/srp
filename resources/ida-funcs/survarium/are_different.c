bool __fastcall survarium::are_different(
        const survarium::player_input *new_input,
        const survarium::player_input *previous_input)
{
  unsigned int actions_mask; // eax

  actions_mask = new_input->actions_mask;
  return previous_input->actions_mask != actions_mask
      || (actions_mask & 0x60) == 0x60
      || new_input->rotation_delta.x != 0.0
      || new_input->rotation_delta.y != 0.0;
}
