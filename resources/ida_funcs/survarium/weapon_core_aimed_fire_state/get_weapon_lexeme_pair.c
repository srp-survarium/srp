survarium::weapon_lexeme_pair *__thiscall survarium::weapon_core_aimed_fire_state::get_weapon_lexeme_pair(
        survarium::weapon_core_aimed_fire_state *this,
        survarium::weapon_lexeme_pair *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id)
{
  survarium::weapon_core *m_weapon; // ecx
  const vostok::animation::base_interpolator *v6; // eax
  survarium::game_camera *v7; // ecx
  unsigned __int16 m_bullets_in_queue; // [esp+12h] [ebp-12h]
  int v11; // [esp+14h] [ebp-10h] BYREF
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *selected_animation; // [esp+1Ch] [ebp-8h]
  const char *animation_identifier; // [esp+20h] [ebp-4h]

  animation_identifier = "weapon-aimed_fire";
  selected_animation = &this->m_weapon_animations[is_third_view][user_state_id == type_crouch];
  survarium::weapon_core_animation_end_aware_state::set_animation_to_wait(this, selected_animation);
  m_weapon = this->m_weapon;
  m_bullets_in_queue = m_weapon->m_bullets_in_queue;
  v6 = (const vostok::animation::base_interpolator *)vostok::animation::linear_interpolator::linear_interpolator(
                                                       (vostok::animation::linear_interpolator *)m_weapon,
                                                       &v11,
                                                       SLODWORD(s_aim_transition_time));
  survarium::get_weapon_lexeme_pair_impl(
    result,
    buffer,
    animation_identifier,
    selected_animation,
    this->m_weapon,
    &this->m_animation_playback_state,
    1u,
    this->m_animation_timescale,
    (const vostok::animation::mixing::playback_enum)(m_bullets_in_queue <= 1u),
    v6);
  survarium::weapon_user_dead_state::finalize(v7);
  return result;
}
