vostok::animation::mixing::expression *__thiscall survarium::pistol_weapon_core_reload_state::get_user_hands_expression(
        survarium::pistol_weapon_core_reload_state *this,
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::base_lexeme *weapon_lexeme,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id,
        vostok::animation::mixing::base_lexeme *weight_driving_animation)
{
  vostok::animation::linear_interpolator *v7; // ecx
  survarium::weapon_core *v8; // ecx
  survarium::base_player *user; // esi
  vostok::animation::mixing::animation_lexeme_parameters *v10; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v11; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v12; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v13; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v14; // ecx
  vostok::animation::mixing::animation_lexeme *v15; // ecx
  vostok::animation::mixing::animation_lexeme *v16; // ecx
  survarium::game_camera *v17; // ecx
  vostok::animation::mixing::animation_lexeme *v19; // [esp+0h] [ebp-11Ch]
  _BYTE v21[84]; // [esp+20h] [ebp-FCh] BYREF
  vostok::animation::mixing::animation_lexeme override_lexeme; // [esp+74h] [ebp-A8h] BYREF
  unsigned int weapon_state_index; // [esp+FCh] [ebp-20h]
  vostok::animation::linear_interpolator interpolator; // [esp+100h] [ebp-1Ch] BYREF
  unsigned int user_state_index; // [esp+108h] [ebp-14h]
  const char *user_animation_captions[2][2]; // [esp+10Ch] [ebp-10h]

  user_animation_captions[0][0] = "stand_reload_pistol";
  user_animation_captions[0][1] = "stand_reload_empty_pistol";
  user_animation_captions[1][0] = "crouch_reload_pistol";
  user_animation_captions[1][1] = "crouch_reload_empty_pistol";
  user_state_index = user_state_id == type_crouch;
  weapon_state_index = survarium::weapon_core::ammo_in_magazine((survarium::weapon_core *)this, (int)this->m_weapon) == 0;
  vostok::animation::linear_interpolator::linear_interpolator(v7, &interpolator, SLODWORD(s_aim_transition_time));
  user = survarium::weapon_core::get_user(v8, (int)this->m_weapon);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    (vostok::animation::mixing::animation_lexeme_parameters *)buffer,
    (int)v21,
    buffer,
    &this->m_user_animations[is_third_view][user_state_index][weapon_state_index],
    weapon_lexeme,
    weight_driving_animation,
    v19);
  v11 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
          (vostok::animation::mixing::animation_lexeme_parameters *)user,
          v10);
  v12 = vostok::animation::mixing::animation_lexeme_parameters::bones_mask(
          (vostok::animation::mixing::animation_lexeme_parameters *)2,
          v11);
  v13 = vostok::animation::mixing::animation_lexeme_parameters::playback_type(
          (vostok::animation::mixing::animation_lexeme_parameters *)1,
          v12);
  vostok::animation::mixing::animation_lexeme::animation_lexeme(&override_lexeme, v13);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v14, (int)v21);
  vostok::animation::mixing::expression::expression(
    result,
    (vostok::animation::mixing::base_lexeme *)&override_lexeme,
    v15);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v16, (int)&override_lexeme);
  survarium::weapon_user_dead_state::finalize(v17);
  return result;
}
