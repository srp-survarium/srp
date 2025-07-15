vostok::animation::mixing::expression *__thiscall survarium::pistol_weapon_core_reload_state::weapon_and_hands_expression(
        survarium::pistol_weapon_core_reload_state *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id,
        vostok::animation::mixing::base_lexeme *weight_driving_animation)
{
  survarium::game_camera *v6; // ecx
  vostok::animation::mixing::addition_lexeme *v7; // eax
  vostok::animation::mixing::addition_lexeme *v8; // ecx
  vostok::animation::mixing::animation_lexeme *v9; // ecx
  vostok::animation::mixing::animation_lexeme *v10; // ecx
  vostok::animation::mixing::animation_lexeme *v12; // ecx
  vostok::animation::mixing::expression *v13; // eax
  vostok::animation::mixing::animation_lexeme *v14; // ecx
  vostok::animation::mixing::animation_lexeme *v15; // ecx
  vostok::animation::mixing::addition_lexeme v17; // [esp+84h] [ebp-14Ch] BYREF
  vostok::animation::mixing::expression *v18; // [esp+A8h] [ebp-128h]
  vostok::animation::mixing::expression v19; // [esp+ACh] [ebp-124h] BYREF
  vostok::animation::mixing::expression right; // [esp+B4h] [ebp-11Ch] BYREF
  char v21; // [esp+BFh] [ebp-111h]
  vostok::animation::mixing::expression hands_expression; // [esp+C0h] [ebp-110h] BYREF
  survarium::weapon_lexeme_pair lexeme_pair; // [esp+C8h] [ebp-108h] BYREF

  survarium::pistol_weapon_core_reload_state::get_weapon_lexeme_pair(
    this,
    &lexeme_pair,
    buffer,
    is_third_view,
    user_state_id);
  if ( user_state_id == type_sprint )
  {
    vostok::animation::mixing::addition_lexeme::addition_lexeme(
      &v17,
      (vostok::animation::mixing::base_lexeme *)&lexeme_pair,
      (vostok::animation::mixing::base_lexeme *)&lexeme_pair.offset_lexeme);
    v18 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v7);
    vostok::animation::mixing::addition_lexeme::~addition_lexeme(v8, (int)&v17);
    vostok::animation::mixing::expression::expression(v18, result);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v9, (int)&lexeme_pair.offset_lexeme);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v10, (int)&lexeme_pair);
  }
  else
  {
    v21 = 0;
    survarium::weapon_user_dead_state::finalize(v6);
    survarium::pistol_weapon_core_reload_state::get_user_hands_expression(
      this,
      &hands_expression,
      (vostok::animation::mixing::base_lexeme *)&lexeme_pair.offset_lexeme,
      buffer,
      is_third_view,
      user_state_id,
      weight_driving_animation);
    vostok::animation::mixing::expression::expression(
      &right,
      (vostok::animation::mixing::base_lexeme *)&lexeme_pair.offset_lexeme,
      v12);
    v13 = vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme>(
            &hands_expression,
            &lexeme_pair.main_lexeme,
            &v19);
    vostok::animation::mixing::operator+(result, v13, &right);
    vostok::animation::mixing::expression::~expression(&v19);
    vostok::animation::mixing::expression::~expression(&right);
    vostok::animation::mixing::expression::~expression(&hands_expression);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v14, (int)&lexeme_pair.offset_lexeme);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v15, (int)&lexeme_pair);
  }
  return result;
}
