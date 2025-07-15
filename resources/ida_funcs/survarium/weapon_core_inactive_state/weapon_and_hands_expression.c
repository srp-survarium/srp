void __thiscall survarium::weapon_core_inactive_state::weapon_and_hands_expression(
        survarium::weapon_core_inactive_state *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)buffer);
}
