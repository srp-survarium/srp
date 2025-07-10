vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::expand_brackets_as_and(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator)
{
  survarium::game_camera *v3; // ecx
  vostok::ai::planning::base_lexeme_ptr right; // [esp+14h] [ebp-8h] BYREF
  vostok::ai::planning::base_lexeme_ptr left; // [esp+18h] [ebp-4h] BYREF

  vostok::ai::planning::base_lexeme::expand_brackets(
    (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme,
    &left,
    allocator);
  vostok::ai::planning::base_lexeme::expand_brackets(
    (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
    &right,
    allocator);
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::ai::planning::base_lexeme::expand_brackets(
    (vostok::ai::planning::base_lexeme *)left.m_lexeme,
    result,
    allocator,
    right.m_lexeme);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&right);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&left);
  return result;
}
