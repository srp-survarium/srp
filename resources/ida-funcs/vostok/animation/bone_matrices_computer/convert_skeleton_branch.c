void __thiscall vostok::animation::bone_matrices_computer::convert_skeleton_branch(
        vostok::animation::bone_matrices_computer *this,
        const vostok::animation::skeleton_bone *bone,
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *parent,
        unsigned __int8 calc_mask)
{
  const vostok::animation::skeleton_bone *m_children_begin; // esi
  int v6; // edi
  vostok::math::float4x4 v7; // [esp+Ch] [ebp-44h] BYREF
  vostok::animation::bone_matrices_computer *v8; // [esp+4Ch] [ebp-4h]
  const vostok::animation::skeleton_bone *m_children_end; // [esp+60h] [ebp+10h]

  v8 = this;
  vostok::math::mul4x3(parent, result, &v7);
  qmemcpy(result, &v7, sizeof(vostok::math::float4x4));
  m_children_begin = bone->m_children_begin;
  m_children_end = bone->m_children_end;
  if ( m_children_begin != m_children_end )
  {
    v6 = (char *)m_children_begin - (char *)bone;
    do
    {
      if ( (calc_mask & m_children_begin->m_calc_mask) != 0 )
        vostok::animation::bone_matrices_computer::convert_skeleton_branch(
          v8,
          m_children_begin,
          &result[v6 / 28],
          result,
          calc_mask);
      ++m_children_begin;
      v6 += 28;
    }
    while ( m_children_begin != m_children_end );
  }
}
