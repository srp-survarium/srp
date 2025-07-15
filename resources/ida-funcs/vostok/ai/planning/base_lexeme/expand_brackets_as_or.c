vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::expand_brackets_as_or(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator)
{
  vostok::ai::planning::base_lexeme_ptr *v3; // eax

  v3 = result;
  result->m_lexeme = this;
  if ( this )
  {
    if ( this->m_destroy_manually )
      ++this->m_counter;
  }
  return v3;
}


vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::expand_brackets_as_or(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::ai::planning::base_lexeme_ptr *allocator,
        vostok::memory::stack_allocator *right)
{
  const vostok::ai::planning::base_lexeme *m_lexeme; // eax
  vostok::ai::planning::base_lexeme_ptr *v7; // ecx
  vostok::ai::planning::base_lexeme *v8; // ecx
  vostok::ai::planning::base_lexeme_ptr *v9; // eax
  vostok::ai::planning::base_lexeme *v10; // ecx
  vostok::ai::planning::base_lexeme_ptr *v11; // eax
  const vostok::ai::planning::base_lexeme *v12; // eax
  const vostok::ai::planning::base_lexeme *v14; // [esp+0h] [ebp-1Ch]
  const vostok::ai::planning::base_lexeme *v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+Ch] [ebp-10h] BYREF
  int v17; // [esp+10h] [ebp-Ch] BYREF
  const vostok::ai::planning::base_lexeme *v18; // [esp+14h] [ebp-8h]
  int v19; // [esp+18h] [ebp-4h]
  vostok::ai::planning::base_lexeme *v20; // [esp+28h] [ebp+Ch]

  v19 = 0;
  type_info::raw_name(&vostok::ai::planning::base_lexeme `RTTI Type Descriptor');
  m_lexeme = allocator[5].m_lexeme;
  v7 = (vostok::ai::planning::base_lexeme_ptr *)&m_lexeme[1];
  v20 = (vostok::ai::planning::base_lexeme *)m_lexeme;
  allocator[5].m_lexeme = m_lexeme + 1;
  if ( m_lexeme )
  {
    v8 = (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme;
    v19 = 3;
    v9 = vostok::ai::planning::base_lexeme::expand_brackets(v8, &v16, allocator, right, v14);
    v10 = (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme;
    v18 = v9->m_lexeme;
    v11 = vostok::ai::planning::base_lexeme::expand_brackets(v10, &v17, allocator, right, v15);
    vostok::ai::planning::base_lexeme::base_lexeme(v11->m_lexeme, v18, v20, operation_type_or, 1u);
  }
  else
  {
    v12 = 0;
  }
  result->m_lexeme = v12;
  if ( v12 && v12->m_destroy_manually )
    ++v12->m_counter;
  if ( (v19 & 2) != 0 )
  {
    v19 &= ~2u;
    vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(v7, &v17);
  }
  if ( (v19 & 1) != 0 )
    vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(v7, &v16);
  return result;
}
