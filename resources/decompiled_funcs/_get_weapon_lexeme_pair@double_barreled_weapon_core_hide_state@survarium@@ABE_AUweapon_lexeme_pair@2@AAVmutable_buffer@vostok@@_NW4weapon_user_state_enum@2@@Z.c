survarium::weapon_lexeme_pair *__thiscall survarium::double_barreled_weapon_core_hide_state::get_weapon_lexeme_pair(
        survarium::double_barreled_weapon_core_hide_state *this,
        survarium::weapon_lexeme_pair *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id)
{
  vostok::animation::linear_interpolator *v5; // ecx
  const vostok::animation::base_interpolator *v6; // eax
  survarium::game_camera *v7; // ecx
  int v10; // [esp+10h] [ebp-24h] BYREF
  char v11; // [esp+1Bh] [ebp-19h]
  const char *weapon_animation_captions[3]; // [esp+1Ch] [ebp-18h]
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *selected_animation; // [esp+28h] [ebp-Ch]
  unsigned int weapon_animation_index; // [esp+2Ch] [ebp-8h]
  const char *animation_identifier; // [esp+30h] [ebp-4h]

  v11 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  weapon_animation_captions[0] = "hide_both_barrels_empty";
  weapon_animation_captions[1] = "hide_one_barrel_loaded";
  weapon_animation_captions[2] = "hide_two_barrels_loaded";
  weapon_animation_index = survarium::weapon_core::ammo_in_magazine((survarium::weapon_core *)this, (int)this->m_weapon);
  animation_identifier = weapon_animation_captions[weapon_animation_index];
  selected_animation = &this->m_weapon_animations[is_third_view][user_state_id == type_crouch][weapon_animation_index];
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
