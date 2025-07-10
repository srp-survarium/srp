vostok::animation::mixing::expression *__thiscall survarium::weapon_core_show_state::get_user_hands_expression(
        survarium::weapon_core_show_state *this,
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
  vostok::animation::mixing::animation_lexeme *v16; // [esp+0h] [ebp-118h]
  _BYTE v18[84]; // [esp+2Ch] [ebp-ECh] BYREF
  vostok::animation::mixing::animation_lexeme override_lexeme; // [esp+80h] [ebp-98h] BYREF
  const char *animation_captions[2]; // [esp+10Ch] [ebp-Ch]
  unsigned int user_state_index; // [esp+114h] [ebp-4h]

  if ( user_state_id == type_sprint )
  {
    fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>(
      (vostok::animation::mixing::expression *)this,
      result);
  }
  else
  {
    user_state_index = user_state_id == type_crouch;
    animation_captions[0] = "stand_show";
    animation_captions[1] = "crouch_show";
    user = survarium::weapon_core::get_user((survarium::weapon_core *)this, (int)this->m_weapon);
    vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
      (vostok::animation::mixing::animation_lexeme_parameters *)user_state_index,
      (int)v18,
      buffer,
      &this->m_user_animations[is_third_view][user_state_index],
      weapon_lexeme,
      weight_driving_animation,
      v16);
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
    vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v13, (int)v18);
    vostok::animation::mixing::expression::expression(
      result,
      (vostok::animation::mixing::base_lexeme *)&override_lexeme,
      v14);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v15, (int)&override_lexeme);
  }
  return result;
}
