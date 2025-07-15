vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::expand_brackets(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator)
{
  const vostok::ai::planning::base_lexeme_ptr *v3; // eax
  vostok::ai::planning::base_lexeme_ptr v5; // [esp+4h] [ebp-4h] BYREF

  v3 = this->m_function_pointers->m_brackets_opener1(this, &v5, allocator);
  vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(result, v3);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&v5);
  return result;
}


vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::expand_brackets(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator,
        const vostok::ai::planning::base_lexeme *right)
{
  const vostok::ai::planning::base_lexeme_ptr *v4; // eax
  vostok::ai::planning::base_lexeme_ptr v6; // [esp+4h] [ebp-4h] BYREF

  v4 = this->m_function_pointers->m_brackets_opener2(this, &v6, allocator, right);
  vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(result, v4);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&v6);
  return result;
}
