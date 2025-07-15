vostok::animation::mixing::expression *__thiscall survarium::pistol_weapon_core_hide_state::get_user_hands_expression(
        survarium::pistol_weapon_core_hide_state *this,
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::base_lexeme *weapon_lexeme,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id,
        vostok::animation::mixing::base_lexeme *weight_driving_animation)
{
  survarium::base_player *user; // esi
  vostok::animation::mixing::animation_lexeme_parameters *v9; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v10; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v11; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v12; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v13; // ecx
  vostok::animation::mixing::animation_lexeme *v14; // ecx
  vostok::animation::mixing::animation_lexeme *v15; // ecx
  survarium::game_camera *v16; // ecx
  vostok::animation::mixing::animation_lexeme *v17; // [esp+0h] [ebp-11Ch]
  _BYTE v19[84]; // [esp+28h] [ebp-F4h] BYREF
  vostok::animation::mixing::animation_lexeme override_lexeme; // [esp+7Ch] [ebp-A0h] BYREF
  const char *animation_captions[2]; // [esp+108h] [ebp-14h]
  vostok::animation::linear_interpolator interpolator; // [esp+110h] [ebp-Ch] BYREF
  unsigned int user_state_index; // [esp+118h] [ebp-4h]

  if ( user_state_id == type_sprint )
  {
    fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>(
      (vostok::animation::mixing::expression *)this,
      result);
  }
  else
  {
    user_state_index = user_state_id == type_crouch;
    animation_captions[0] = "stand_hide";
    animation_captions[1] = "crouch_hide";
    vostok::animation::linear_interpolator::linear_interpolator(
      (vostok::animation::linear_interpolator *)this,
      &interpolator,
      SLODWORD(s_aim_transition_time));
    user = survarium::weapon_core::get_user((survarium::weapon_core *)this, (int)this->m_weapon);
    vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
      (vostok::animation::mixing::animation_lexeme_parameters *)user_state_index,
      (int)v19,
      buffer,
      &this->m_user_animations[is_third_view][user_state_index],
      weapon_lexeme,
      weight_driving_animation,
      v17);
    v10 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
            (vostok::animation::mixing::animation_lexeme_parameters *)user,
            v9);
    v11 = vostok::animation::mixing::animation_lexeme_parameters::bones_mask(
            (vostok::animation::mixing::animation_lexeme_parameters *)2,
            v10);
    v12 = vostok::animation::mixing::animation_lexeme_parameters::playback_type(
            (vostok::animation::mixing::animation_lexeme_parameters *)1,
            v11);
    vostok::animation::mixing::animation_lexeme::animation_lexeme(&override_lexeme, v12);
    vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v13, (int)v19);
    vostok::animation::mixing::expression::expression(
      result,
      (vostok::animation::mixing::base_lexeme *)&override_lexeme,
      v14);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v15, (int)&override_lexeme);
    survarium::weapon_user_dead_state::finalize(v16);
  }
  return result;
}
