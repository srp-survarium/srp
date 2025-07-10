vostok::animation::mixing::expression *__thiscall survarium::weapon_core_shotgun_reload_state::weapon_and_hands_expression(
        survarium::weapon_core_shotgun_reload_state *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation)
{
  survarium::weapon_core_shotgun_reload_base_substate::weapon_and_hands_expression(
    (survarium::weapon_core_shotgun_reload_base_substate *)this->m_logic->m_current_state,
    result,
    buffer,
    is_third_view,
    user_state_id,
    weight_driving_animation);
  return result;
}
