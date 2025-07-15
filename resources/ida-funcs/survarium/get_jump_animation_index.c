unsigned int __usercall survarium::get_jump_animation_index@<eax>(
        const bool jump_from_right_leg@<cl>,
        unsigned int animation_part@<eax>,
        const survarium::jump_type_enum jump_type)
{
  int v3; // edx

  switch ( jump_type )
  {
    case jump_type_on_site:
      return animation_part;
    case jump_type_fwd:
      v3 = !jump_from_right_leg ? 42 : 36;
      goto LABEL_16;
    case jump_type_fwd_right:
      v3 = !jump_from_right_leg ? 54 : 48;
      goto LABEL_16;
    case jump_type_fwd_left:
      v3 = !jump_from_right_leg ? 66 : 60;
      goto LABEL_16;
    case jump_type_sprint_fwd:
      v3 = !jump_from_right_leg ? 78 : 72;
      goto LABEL_16;
    case jump_type_sprint_fwd_right:
      v3 = !jump_from_right_leg ? 90 : 84;
      goto LABEL_16;
    case jump_type_sprint_fwd_left:
      v3 = !jump_from_right_leg ? 102 : 96;
LABEL_16:
      animation_part += v3;
      break;
    case jump_type_from_site_fwd:
      animation_part += 4;
      break;
    case jump_type_from_site_fwd_right:
      animation_part += 8;
      break;
    case jump_type_from_site_right:
      animation_part += 12;
      break;
    case jump_type_from_site_back_right:
      animation_part += 16;
      break;
    case jump_type_from_site_back:
      animation_part += 20;
      break;
    case jump_type_from_site_back_left:
      animation_part += 24;
      break;
    case jump_type_from_site_left:
      animation_part += 28;
      break;
    case jump_type_from_site_fwd_left:
      animation_part += 32;
      break;
  }
  return animation_part;
}
