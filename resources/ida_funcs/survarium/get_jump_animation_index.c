survarium::jump_animation_parts __cdecl survarium::get_jump_animation_index(
        survarium::move_direction_enum move_direction,
        bool jump_from_right_leg,
        survarium::jump_animation_parts animation_part)
{
  survarium::jump_animation_parts result; // eax

  switch ( move_direction )
  {
    case move_direction_on_site:
      result = animation_part;
      break;
    case move_direction_fwd:
      result = animation_part + (jump_from_right_leg ? 4 : 10);
      break;
    case move_direction_fwd_right:
      result = animation_part + (jump_from_right_leg ? 16 : 22);
      break;
    case move_direction_right:
      result = animation_part + (jump_from_right_leg ? 28 : 34);
      break;
    case move_direction_back_right:
      result = animation_part + (jump_from_right_leg ? 40 : 46);
      break;
    case move_direction_back:
      result = animation_part + (jump_from_right_leg ? 52 : 58);
      break;
    case move_direction_back_left:
      result = animation_part + (jump_from_right_leg ? 64 : 70);
      break;
    case move_direction_left:
      result = animation_part + (jump_from_right_leg ? 76 : 82);
      break;
    case move_direction_fwd_left:
      result = animation_part + (jump_from_right_leg ? 88 : 94);
      break;
  }
  return result;
}
