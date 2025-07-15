vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::generate_permutations(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator,
        const vostok::ai::planning::base_lexeme *left)
{
  const vostok::ai::planning::base_lexeme_ptr *v4; // eax
  vostok::ai::planning::base_lexeme_ptr v6; // [esp+4h] [ebp-4h] BYREF

  v4 = this->m_function_pointers->m_generator(this, &v6, allocator, left);
  vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(result, v4);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&v6);
  return result;
}
