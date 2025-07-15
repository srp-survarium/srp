survarium::weapon_lexeme_pair *__thiscall survarium::weapon_core_shotgun_reload_base_substate::get_weapon_lexeme_pair(
        survarium::weapon_core_shotgun_reload_base_substate *this,
        survarium::weapon_lexeme_pair *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id)
{
  vostok::animation::linear_interpolator *v5; // ecx
  const vostok::animation::base_interpolator *v6; // eax
  survarium::game_camera *v7; // ecx
  int v10; // [esp+1Ch] [ebp-8h] BYREF

  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_animation_to_wait_for,
    &this->m_weapon_animations[is_third_view][user_state_id == type_crouch]);
  v6 = (const vostok::animation::base_interpolator *)vostok::animation::linear_interpolator::linear_interpolator(
                                                       v5,
                                                       &v10,
                                                       SLODWORD(s_aim_transition_time));
  survarium::get_weapon_lexeme_pair_impl(
    result,
    buffer,
    this->m_animation_id,
    &this->m_animation_to_wait_for,
    this->m_weapon,
    this->m_animation_playback_state,
    this->m_time_synchronization_group,
    this->m_animation_timescale,
    (const vostok::animation::mixing::playback_enum)this->m_playback_type,
    v6);
  survarium::weapon_user_dead_state::finalize(v7);
  return result;
}
