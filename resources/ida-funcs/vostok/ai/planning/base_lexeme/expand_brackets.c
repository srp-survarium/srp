vostok::ai::planning::base_lexeme_ptr *__userpurge vostok::ai::planning::base_lexeme::expand_brackets@<eax>(
        vostok::ai::planning::base_lexeme *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator)
{
  int v4; // eax
  vostok::ai::planning::base_lexeme_ptr *v5; // ecx

  v4 = *(_DWORD *)((int (__stdcall *)(vostok::ai::planning::base_lexeme_ptr **, vostok::ai::planning::base_lexeme_ptr *))this->m_function_pointers->m_brackets_opener1)(
                    &result,
                    result);
  *a2 = v4;
  if ( v4 && *(_BYTE *)(v4 + 22) )
    ++*(_WORD *)(v4 + 20);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(v5, (int *)&result);
  return (vostok::ai::planning::base_lexeme_ptr *)a2;
}


vostok::ai::planning::base_lexeme_ptr *__userpurge vostok::ai::planning::base_lexeme::expand_brackets@<eax>(
        vostok::ai::planning::base_lexeme *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator,
        const vostok::ai::planning::base_lexeme *right)
{
  int v5; // eax
  vostok::ai::planning::base_lexeme_ptr *v6; // ecx

  v5 = *(_DWORD *)((int (__stdcall *)(vostok::memory::stack_allocator **, vostok::ai::planning::base_lexeme_ptr *, vostok::memory::stack_allocator *))this->m_function_pointers->m_brackets_opener2)(
                    &allocator,
                    result,
                    allocator);
  *a2 = v5;
  if ( v5 && *(_BYTE *)(v5 + 22) )
    ++*(_WORD *)(v5 + 20);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(v6, (int *)&allocator);
  return (vostok::ai::planning::base_lexeme_ptr *)a2;
}
