survarium::weapon_lexeme_pair *__thiscall survarium::weapon_core_idle_state::get_weapon_lexeme_pair(
        survarium::weapon_core_idle_state *this,
        survarium::weapon_lexeme_pair *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id)
{
  const vostok::animation::base_interpolator *v5; // eax
  survarium::game_camera *v6; // ecx
  int v9; // [esp+10h] [ebp-10h] BYREF
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *selected_animation; // [esp+18h] [ebp-8h]
  const char *animation_identifier; // [esp+1Ch] [ebp-4h]

  animation_identifier = "weapon-idle";
  selected_animation = &this->m_weapon_animations[is_third_view][user_state_id == type_crouch];
  v5 = (const vostok::animation::base_interpolator *)vostok::animation::linear_interpolator::linear_interpolator(
                                                       (vostok::animation::linear_interpolator *)selected_animation,
                                                       &v9,
                                                       SLODWORD(s_aim_transition_time));
  survarium::get_weapon_lexeme_pair_impl(
    result,
    buffer,
    animation_identifier,
    selected_animation,
    this->m_weapon,
    &this->m_animation_playback_state,
    0xFFFFFFFF,
    1.0,
    play_cyclically,
    v5);
  survarium::weapon_user_dead_state::finalize(v6);
  return result;
}
