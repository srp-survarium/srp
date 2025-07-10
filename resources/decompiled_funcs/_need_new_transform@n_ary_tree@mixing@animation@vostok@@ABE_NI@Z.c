bool __thiscall vostok::animation::mixing::n_ary_tree::need_new_transform(
        vostok::animation::mixing::n_ary_tree *this,
        const vostok::animation::mixing::n_ary_tree *target_time_in_ms,
        unsigned int target_time_in_msa)
{
  const vostok::animation::mixing::n_ary_tree *v3; // ebx
  _DWORD *v4; // ebp
  bool result; // al
  int v6; // ecx
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // ecx
  vostok::animation::mixing::animated_object_holder *v8; // esi

  v3 = target_time_in_ms;
  v4 = &target_time_in_ms->m_weight_root->__vftable;
  for ( result = 0; v4; v4 = (_DWORD *)v4[10] )
  {
    v6 = v4[7];
    if ( *(_DWORD *)(v6 + 164) == target_time_in_msa && (*(_WORD *)(v6 + 168) & 0x1DF) != 0 )
    {
      m_animated_objects = v3->m_animated_objects;
      v8 = &m_animated_objects[v3->m_animated_objects_count];
      target_time_in_ms = (const vostok::animation::mixing::n_ary_tree *)v4[9];
      stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
        m_animated_objects,
        v8,
        (const void *const *)&target_time_in_ms)->need_new_transform = 1;
      result = 1;
    }
  }
  return result;
}
