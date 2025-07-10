const char *__thiscall survarium::jump_logic::get_animation_caption(
        survarium::jump_logic *this,
        survarium::jump_animation_parts anim_part)
{
  survarium::game_camera *v2; // ecx
  survarium::jump_animation_parts jump_animation_index; // [esp+8h] [ebp-1Ch]
  survarium::move_direction_enum move_direction; // [esp+1Ch] [ebp-8h]
  bool m_is_jump_from_right_leg; // [esp+23h] [ebp-1h]

  m_is_jump_from_right_leg = this->m_is_jump_from_right_leg;
  move_direction = this->m_jumping_direction;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  jump_animation_index = survarium::get_jump_animation_index(move_direction, m_is_jump_from_right_leg, anim_part);
  survarium::weapon_user_dead_state::finalize(v2);
  return survarium::jump_animations_captions[jump_animation_index];
}
