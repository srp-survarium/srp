survarium::weapon_lexeme_pair *__thiscall survarium::double_barreled_weapon_core_reload_state::get_weapon_lexeme_pair(
        survarium::double_barreled_weapon_core_reload_state *this,
        survarium::weapon_lexeme_pair *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id)
{
  vostok::animation::linear_interpolator *v5; // ecx
  const vostok::animation::base_interpolator *v6; // eax
  survarium::game_camera *v7; // ecx
  int v10; // [esp+10h] [ebp-20h] BYREF
  char v11; // [esp+1Bh] [ebp-15h]
  unsigned int weapon_state_index; // [esp+1Ch] [ebp-14h]
  const char *weapon_animation_captions[2]; // [esp+20h] [ebp-10h]
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *selected_animation; // [esp+28h] [ebp-8h]
  const char *animation_identifier; // [esp+2Ch] [ebp-4h]

  v11 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  weapon_animation_captions[0] = "reload_first_barrel";
  weapon_animation_captions[1] = "reload_both_barrels";
  weapon_state_index = survarium::weapon_core::ammo_in_magazine((survarium::weapon_core *)this, (int)this->m_weapon) != 1;
  animation_identifier = weapon_animation_captions[weapon_state_index];
  selected_animation = &this->m_weapon_animations[is_third_view][user_state_id == type_crouch][weapon_state_index];
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
    2u,
    this->m_animation_timescale,
    play_once_and_freeze_at_end,
    v6);
  survarium::weapon_user_dead_state::finalize(v7);
  return result;
}
