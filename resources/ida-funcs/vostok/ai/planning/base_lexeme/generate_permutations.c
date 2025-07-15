vostok::ai::planning::base_lexeme_ptr *__userpurge vostok::ai::planning::base_lexeme::generate_permutations@<eax>(
        vostok::ai::planning::base_lexeme *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator,
        const vostok::ai::planning::base_lexeme *left)
{
  int v5; // eax
  vostok::ai::planning::base_lexeme_ptr *v6; // ecx

  v5 = *(_DWORD *)((int (__stdcall *)(vostok::memory::stack_allocator **, vostok::ai::planning::base_lexeme_ptr *, vostok::memory::stack_allocator *))this->m_function_pointers->m_generator)(
                    &allocator,
                    result,
                    allocator);
  *a2 = v5;
  if ( v5 && *(_BYTE *)(v5 + 22) )
    ++*(_WORD *)(v5 + 20);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(v6, (int *)&allocator);
  return (vostok::ai::planning::base_lexeme_ptr *)a2;
}
