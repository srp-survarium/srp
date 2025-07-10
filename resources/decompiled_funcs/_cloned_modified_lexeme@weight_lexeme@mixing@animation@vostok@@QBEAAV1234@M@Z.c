vostok::animation::mixing::weight_lexeme *__fastcall vostok::animation::mixing::weight_lexeme::cloned_modified_lexeme(
        vostok::animation::mixing::weight_lexeme *this,
        int a2,
        float new_weight)
{
  int v3; // eax
  vostok::animation::mixing::weight_lexeme *v4; // esi
  vostok::mutable_buffer *v5; // edi
  int v6; // eax
  vostok::animation::mixing::weight_lexeme *result; // eax

  v3 = *(_DWORD *)(a2 + 32);
  v4 = *(vostok::animation::mixing::weight_lexeme **)v3;
  *(_DWORD *)v3 += 40;
  *(_DWORD *)(v3 + 4) -= 40;
  if ( v4 )
  {
    v5 = *(vostok::mutable_buffer **)(a2 + 32);
    v6 = (*(int (__thiscall **)(_DWORD, vostok::mutable_buffer *))(**(_DWORD **)(a2 + 20) + 8))(
           *(_DWORD *)(a2 + 20),
           v5);
    v4->m_next_weight = 0;
    v4->m_same_weight = 0;
    v4->m_next_unique_interpolator = 0;
    v4->m_reference_count = 0;
    v4->m_interpolator = (const vostok::animation::base_interpolator *)v6;
    v4->m_weight = new_weight;
    v4->m_simplified_weight = new_weight;
    v4->m_buffer = v5;
    v4->__vftable = (vostok::animation::mixing::weight_lexeme_vtbl *)&vostok::animation::mixing::weight_lexeme::`vftable';
  }
  result = v4;
  v4->m_cloned = 1;
  return result;
}
