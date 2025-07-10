vostok::animation::mixing::expression *__thiscall survarium::weapon_core_chamber_a_round_state::weapon_and_hands_expression(
        survarium::weapon_core_chamber_a_round_state *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id,
        vostok::animation::mixing::base_lexeme *weight_driving_animation)
{
  vostok::animation::mixing::animation_lexeme *v6; // ecx
  vostok::animation::mixing::expression *v7; // eax
  vostok::animation::mixing::animation_lexeme *v8; // ecx
  vostok::animation::mixing::animation_lexeme *v9; // ecx
  vostok::animation::mixing::expression v12; // [esp+74h] [ebp-120h] BYREF
  vostok::animation::mixing::expression right; // [esp+7Ch] [ebp-118h] BYREF
  vostok::animation::mixing::expression hands_expression; // [esp+84h] [ebp-110h] BYREF
  survarium::weapon_lexeme_pair lexeme_pair; // [esp+8Ch] [ebp-108h] BYREF

  survarium::weapon_core_chamber_a_round_state::get_weapon_lexeme_pair(
    this,
    &lexeme_pair,
    buffer,
    is_third_view,
    user_state_id);
  survarium::weapon_core_chamber_a_round_state::get_user_hands_expression(
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
    v6);
  v7 = vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme>(
         &hands_expression,
         &lexeme_pair.main_lexeme,
         &v12);
  vostok::animation::mixing::operator+(result, v7, &right);
  vostok::animation::mixing::expression::~expression(&v12);
  vostok::animation::mixing::expression::~expression(&right);
  vostok::animation::mixing::expression::~expression(&hands_expression);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v8, (int)&lexeme_pair.offset_lexeme);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v9, (int)&lexeme_pair);
  return result;
}
