vostok::animation::mixing::expression *__thiscall survarium::weapon_core_aimed_state::weapon_and_hands_expression(
        survarium::weapon_core_aimed_state *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation)
{
  _BYTE *v6; // eax
  vostok::animation::mixing::addition_lexeme *v7; // eax
  vostok::animation::mixing::addition_lexeme *v8; // ecx
  vostok::animation::mixing::animation_lexeme *v9; // ecx
  vostok::animation::mixing::animation_lexeme *v10; // ecx
  _BYTE v12[132]; // [esp-84h] [ebp-1E4h] BYREF
  const survarium::weapon_core_aimed_state *thisa; // [esp+8h] [ebp-158h]
  vostok::animation::mixing::addition_lexeme v14; // [esp+2Ch] [ebp-134h] BYREF
  vostok::animation::mixing::expression *v15; // [esp+50h] [ebp-110h]
  char v16; // [esp+57h] [ebp-109h]
  survarium::weapon_lexeme_pair lexeme_pair; // [esp+58h] [ebp-108h] BYREF

  thisa = this;
  v16 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v6 )
  {
    qmemcpy(v12, weight_driving_animation, sizeof(v12));
    survarium::weapon_user_dead_state::finalize(0);
  }
  survarium::weapon_core_aimed_state::get_weapon_lexeme_pair(
    (survarium::weapon_core_aimed_state *)thisa,
    &lexeme_pair,
    buffer,
    is_third_view,
    user_state_id);
  vostok::animation::mixing::addition_lexeme::addition_lexeme(
    &v14,
    (vostok::animation::mixing::base_lexeme *)&lexeme_pair,
    (vostok::animation::mixing::base_lexeme *)&lexeme_pair.offset_lexeme);
  v15 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v7);
  vostok::animation::mixing::addition_lexeme::~addition_lexeme(v8, (int)&v14);
  vostok::animation::mixing::expression::expression(v15, result);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v9, (int)&lexeme_pair.offset_lexeme);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v10, (int)&lexeme_pair);
  return result;
}
