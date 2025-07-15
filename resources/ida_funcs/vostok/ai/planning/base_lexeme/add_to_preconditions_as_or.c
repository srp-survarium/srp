void __thiscall vostok::ai::planning::base_lexeme::add_to_preconditions_as_or(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::generalized_action *action)
{
  survarium::game_camera *v2; // ecx
  vostok::ai::planning::generalized_action *clone; // [esp+10h] [ebp-4h]

  vostok::ai::planning::base_lexeme::add_to_preconditions(
    (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme,
    action);
  clone = vostok::ai::planning::generalized_action::clone(action);
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::ai::planning::base_lexeme::add_to_preconditions(
    (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
    clone);
}
