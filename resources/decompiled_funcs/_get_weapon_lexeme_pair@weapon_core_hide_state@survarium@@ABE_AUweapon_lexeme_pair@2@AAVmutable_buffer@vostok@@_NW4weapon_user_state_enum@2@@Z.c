survarium::weapon_lexeme_pair *__thiscall survarium::weapon_core_hide_state::get_weapon_lexeme_pair(
        survarium::weapon_core_hide_state *this,
        survarium::weapon_lexeme_pair *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id)
{
  vostok::animation::linear_interpolator *v5; // ecx
  const vostok::animation::base_interpolator *v6; // eax
  survarium::game_camera *v7; // ecx
  int v10; // [esp+10h] [ebp-10h] BYREF
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *selected_animation; // [esp+18h] [ebp-8h]
  const char *animation_identifier; // [esp+1Ch] [ebp-4h]

  animation_identifier = "weapon-hide";
  selected_animation = &this->m_weapon_animations[is_third_view][user_state_id == type_crouch];
  survarium::weapon_core_animation_end_aware_state::set_animation_to_wait(this, selected_animation);
  v6 = (const vostok::animation::base_interpolator *)vostok::animation::linear_interpolator::linear_interpolator(
                                                       v5,
                                                       &v10,
                                                       SLODWORD(s_aim_transition_time));
  survarium::get_weapon_lexeme_pair_impl(
    result,
    buffer,
    animation_identifier,
    selected_animation,
    this->m_weapon,
    &this->m_animation_playback_state,
    7u,
    this->m_time_scale,
    play_once_and_freeze_at_end,
    v6);
  survarium::weapon_user_dead_state::finalize(v7);
  return result;
}
