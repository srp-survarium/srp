survarium::weapon_lexeme_pair *__thiscall survarium::double_barreled_weapon_core_idle_state::get_weapon_lexeme_pair(
        survarium::double_barreled_weapon_core_idle_state *this,
        survarium::weapon_lexeme_pair *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id)
{
  const vostok::animation::base_interpolator *v5; // eax
  survarium::game_camera *v6; // ecx
  int v9; // [esp+10h] [ebp-24h] BYREF
  char v10; // [esp+1Bh] [ebp-19h]
  const char *weapon_animation_captions[3]; // [esp+1Ch] [ebp-18h]
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *selected_animation; // [esp+28h] [ebp-Ch]
  unsigned int animation_index; // [esp+2Ch] [ebp-8h]
  const char *animation_identifier; // [esp+30h] [ebp-4h]

  v10 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  weapon_animation_captions[0] = "idle_both_barrels_empty";
  weapon_animation_captions[1] = "idle_one_barrel_loaded";
  weapon_animation_captions[2] = "idle_two_barrels_loaded";
  animation_index = survarium::weapon_core::ammo_in_magazine((survarium::weapon_core *)this, (int)this->m_weapon);
  animation_identifier = weapon_animation_captions[animation_index];
  selected_animation = &this->m_weapon_animations[is_third_view][user_state_id == type_crouch][animation_index];
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
