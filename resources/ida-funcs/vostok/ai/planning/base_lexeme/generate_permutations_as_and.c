vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::generate_permutations_as_and(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator,
        const vostok::ai::planning::base_lexeme *left)
{
  vostok::ai::planning::base_lexeme *m_arena_current_position; // eax
  const vostok::ai::planning::base_lexeme *v6; // eax

  type_info::raw_name(&vostok::ai::planning::base_lexeme `RTTI Type Descriptor');
  m_arena_current_position = (vostok::ai::planning::base_lexeme *)allocator->m_arena_current_position;
  allocator->m_arena_current_position = &m_arena_current_position[1];
  if ( m_arena_current_position )
    vostok::ai::planning::base_lexeme::base_lexeme(left, this, m_arena_current_position, operation_type_and, 1u);
  else
    v6 = 0;
  result->m_lexeme = v6;
  if ( v6 && v6->m_destroy_manually )
    ++v6->m_counter;
  return result;
}
