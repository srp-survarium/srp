vostok::animation::mixing::addition_lexeme *__usercall vostok::animation::mixing::operator+<vostok::animation::mixing::multiplication_lexeme,vostok::animation::mixing::multiplication_lexeme>@<eax>(
        vostok::animation::mixing::multiplication_lexeme *left@<eax>,
        vostok::animation::mixing::multiplication_lexeme *right)
{
  int v2; // eax
  int v3; // eax
  vostok::animation::mixing::addition_lexeme *v4; // esi
  vostok::animation::mixing::addition_lexeme **v5; // ecx
  bool v6; // zf
  vostok::animation::mixing::addition_lexeme v8; // [esp+8h] [ebp-24h] BYREF

  vostok::animation::mixing::addition_lexeme::addition_lexeme(&v8, left, right);
  v3 = v2 + 28;
  if ( *(_BYTE *)(v3 + 4) )
  {
    v4 = (vostok::animation::mixing::addition_lexeme *)(v3 - 28);
  }
  else
  {
    v5 = *(vostok::animation::mixing::addition_lexeme ***)v3;
    v4 = **(vostok::animation::mixing::addition_lexeme ***)v3;
    --v5[1];
    *v5 = v4 + 1;
    if ( v4 )
      vostok::animation::mixing::addition_lexeme::addition_lexeme(
        v4,
        (const vostok::animation::mixing::addition_lexeme *)(v3 - 28));
    v4->m_cloned = 1;
  }
  if ( v8.m_right.m_object )
  {
    v6 = v8.m_right.m_object->m_reference_count-- == 1;
    if ( v6 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v8.m_right.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v8.m_right.m_object,
        0);
  }
  if ( v8.m_left.m_object )
  {
    v6 = v8.m_left.m_object->m_reference_count-- == 1;
    if ( v6 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v8.m_left.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v8.m_left.m_object,
        0);
  }
  return v4;
}
