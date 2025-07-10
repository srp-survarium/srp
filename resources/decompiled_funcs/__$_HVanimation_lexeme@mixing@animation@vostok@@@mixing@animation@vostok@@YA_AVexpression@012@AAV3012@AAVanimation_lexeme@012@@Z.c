vostok::animation::mixing::expression *__usercall vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme>@<eax>(
        vostok::animation::mixing::expression *left@<ecx>,
        vostok::animation::mixing::animation_lexeme *right@<eax>,
        vostok::animation::mixing::expression *a3)
{
  int v4; // eax
  int v5; // eax
  vostok::animation::mixing::expression *v6; // ecx
  vostok::animation::mixing::addition_lexeme **v7; // ecx
  vostok::animation::mixing::addition_lexeme *v8; // esi
  bool v9; // zf
  vostok::animation::mixing::addition_lexeme v10; // [esp+8h] [ebp-24h] BYREF

  if ( left->m_node.m_object && left->m_lexeme )
  {
    vostok::animation::mixing::addition_lexeme::addition_lexeme(&v10, left, right);
    v5 = v4 + 28;
    if ( *(_BYTE *)(v5 + 4) )
    {
      v6 = (vostok::animation::mixing::expression *)(v5 - 28);
    }
    else
    {
      v7 = *(vostok::animation::mixing::addition_lexeme ***)v5;
      v8 = **(vostok::animation::mixing::addition_lexeme ***)v5;
      --v7[1];
      *v7 = v8 + 1;
      if ( v8 )
        vostok::animation::mixing::addition_lexeme::addition_lexeme(
          v8,
          (const vostok::animation::mixing::addition_lexeme *)(v5 - 28));
      v8->m_cloned = 1;
      v6 = (vostok::animation::mixing::expression *)v8;
    }
    vostok::animation::mixing::expression::expression(v6, a3);
    if ( v10.m_right.m_object )
    {
      v9 = v10.m_right.m_object->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v10.m_right.m_object->~vostok::animation::mixing::binary_tree_base_node)(
          v10.m_right.m_object,
          0);
    }
    if ( v10.m_left.m_object )
    {
      v9 = v10.m_left.m_object->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v10.m_left.m_object->~vostok::animation::mixing::binary_tree_base_node)(
          v10.m_left.m_object,
          0);
    }
    return a3;
  }
  else
  {
    vostok::animation::mixing::expression::expression(
      a3,
      (vostok::animation::mixing::base_lexeme *)right,
      (vostok::animation::mixing::animation_lexeme *)left);
    return a3;
  }
}
