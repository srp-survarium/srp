vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::expand_brackets_as_and(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::ai::planning::base_lexeme_ptr *allocator)
{
  vostok::ai::planning::base_lexeme_ptr *v4; // ecx
  vostok::ai::planning::base_lexeme_ptr *v5; // ecx
  vostok::memory::stack_allocator *v7; // [esp+0h] [ebp-10h]
  vostok::memory::stack_allocator *v8; // [esp+0h] [ebp-10h]
  const vostok::ai::planning::base_lexeme *v9; // [esp+0h] [ebp-10h]
  vostok::ai::planning::base_lexeme *v10; // [esp+8h] [ebp-8h] BYREF
  vostok::memory::stack_allocator *v11; // [esp+Ch] [ebp-4h] BYREF

  vostok::ai::planning::base_lexeme::expand_brackets(
    (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme,
    &v10,
    allocator,
    v7);
  vostok::ai::planning::base_lexeme::expand_brackets(
    (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
    &v11,
    allocator,
    v8);
  vostok::ai::planning::base_lexeme::expand_brackets(v10, result, allocator, v11, v9);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(v4, (int *)&v11);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(v5, (int *)&v10);
  return result;
}
