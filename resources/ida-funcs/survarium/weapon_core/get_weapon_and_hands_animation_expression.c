vostok::animation::mixing::expression *__thiscall survarium::weapon_core::get_weapon_and_hands_animation_expression(
        survarium::weapon_core *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum weapon_user_state_id,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation)
{
  ((void (__thiscall *)(vostok::ai::fsm_state *, vostok::animation::mixing::expression *, vostok::mutable_buffer *, bool, survarium::weapon_user_state_enum, vostok::animation::mixing::animation_lexeme *))this->m_logic->m_current_state->__vftable[1].execute)(
    this->m_logic->m_current_state,
    result,
    buffer,
    is_third_view,
    weapon_user_state_id,
    weight_driving_animation);
  return result;
}
