vostok::animation::mixing::expression *__thiscall survarium::weapon_core_aimed_fire_state::weapon_and_hands_expression(
        survarium::weapon_core_aimed_fire_state *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation)
{
  vostok::animation::mixing::addition_lexeme *v6; // eax
  vostok::animation::mixing::addition_lexeme *v7; // ecx
  vostok::animation::mixing::animation_lexeme *v8; // ecx
  vostok::animation::mixing::animation_lexeme *v9; // ecx
  vostok::animation::mixing::animation_lexeme *v11; // ecx
  vostok::animation::mixing::expression *v12; // eax
  vostok::animation::mixing::animation_lexeme *v13; // ecx
  vostok::animation::mixing::animation_lexeme *v14; // ecx
  vostok::animation::mixing::addition_lexeme v16; // [esp+84h] [ebp-148h] BYREF
  vostok::animation::mixing::expression *v17; // [esp+A8h] [ebp-124h]
  vostok::animation::mixing::expression v18; // [esp+ACh] [ebp-120h] BYREF
  vostok::animation::mixing::expression right; // [esp+B4h] [ebp-118h] BYREF
  vostok::animation::mixing::expression hands_expression; // [esp+BCh] [ebp-110h] BYREF
  survarium::weapon_lexeme_pair lexeme_pair; // [esp+C4h] [ebp-108h] BYREF

  survarium::weapon_core_aimed_fire_state::get_weapon_lexeme_pair(
    this,
    &lexeme_pair,
    buffer,
    is_third_view,
    user_state_id);
  if ( user_state_id == type_sprint || user_state_id == type_jump )
  {
    vostok::animation::mixing::addition_lexeme::addition_lexeme(
      &v16,
      (vostok::animation::mixing::base_lexeme *)&lexeme_pair,
      (vostok::animation::mixing::base_lexeme *)&lexeme_pair.offset_lexeme);
    v17 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v6);
    vostok::animation::mixing::addition_lexeme::~addition_lexeme(v7, (int)&v16);
    vostok::animation::mixing::expression::expression(v17, result);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v8, (int)&lexeme_pair.offset_lexeme);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v9, (int)&lexeme_pair);
    return result;
  }
  else
  {
    survarium::weapon_core_aimed_fire_state::get_user_hands_expression(
      this,
      &hands_expression,
      (vostok::animation::mixing::base_lexeme *)&lexeme_pair.offset_lexeme,
      buffer,
      is_third_view,
      user_state_id);
    vostok::animation::mixing::expression::expression(
      &right,
      (vostok::animation::mixing::base_lexeme *)&lexeme_pair.offset_lexeme,
      v11);
    v12 = vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme>(
            &hands_expression,
            &lexeme_pair.main_lexeme,
            &v18);
    vostok::animation::mixing::operator+(result, v12, &right);
    vostok::animation::mixing::expression::~expression(&v18);
    vostok::animation::mixing::expression::~expression(&right);
    vostok::animation::mixing::expression::~expression(&hands_expression);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v13, (int)&lexeme_pair.offset_lexeme);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v14, (int)&lexeme_pair);
    return result;
  }
}
