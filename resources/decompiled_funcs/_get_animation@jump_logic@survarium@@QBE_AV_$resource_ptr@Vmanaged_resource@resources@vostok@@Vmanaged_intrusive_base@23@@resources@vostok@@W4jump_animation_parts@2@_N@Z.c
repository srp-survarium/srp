vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *__thiscall survarium::jump_logic::get_animation(
        survarium::jump_logic *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *result,
        survarium::jump_animation_parts anim_part,
        bool is_third_view)
{
  survarium::game_camera *v4; // ecx
  survarium::jump_animation_parts jump_animation_index; // [esp+4h] [ebp-1Ch]
  survarium::weapon_user_animations_selector *m_owner; // [esp+Ch] [ebp-14h]
  survarium::weapon_user_animations_container *m_object; // [esp+10h] [ebp-10h]
  survarium::move_direction_enum move_direction; // [esp+18h] [ebp-8h]
  bool m_is_jump_from_right_leg; // [esp+1Fh] [ebp-1h]

  m_is_jump_from_right_leg = this->m_is_jump_from_right_leg;
  move_direction = this->m_jumping_direction;
  m_owner = this->m_owner;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  m_object = m_owner->m_animations.m_object;
  jump_animation_index = survarium::get_jump_animation_index(move_direction, m_is_jump_from_right_leg, anim_part);
  survarium::weapon_user_dead_state::finalize(v4);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    result,
    &m_object->m_jump_animations[is_third_view][jump_animation_index]);
  return result;
}
