vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *__thiscall survarium::jump_logic::get_move_animation(
        survarium::jump_logic *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *result,
        bool is_third_view)
{
  survarium::weapon_user_animations_selector *m_owner; // [esp+10h] [ebp-Ch]

  m_owner = this->m_owner;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_owner);
  survarium::weapon_user_animations_container::get_stand_animation(
    m_owner->m_animations.m_object,
    result,
    0,
    3 * this->m_jumping_direction,
    is_third_view);
  return result;
}
