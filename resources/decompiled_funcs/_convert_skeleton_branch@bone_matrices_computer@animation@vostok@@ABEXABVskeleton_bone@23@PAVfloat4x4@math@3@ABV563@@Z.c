void __thiscall vostok::animation::bone_matrices_computer::convert_skeleton_branch(
        vostok::animation::bone_matrices_computer *this,
        const vostok::animation::skeleton_bone *bone,
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *parent)
{
  const vostok::animation::skeleton_bone *m_children_begin; // esi
  const vostok::animation::skeleton_bone *m_children_end; // ebp
  int v6; // edi
  vostok::math::float4x4 v8; // [esp+18h] [ebp-40h] BYREF

  vostok::math::mul4x3(&v8, result, parent);
  qmemcpy((void *)result, &v8, sizeof(vostok::math::float4x4));
  m_children_begin = bone->m_children_begin;
  m_children_end = bone->m_children_end;
  if ( m_children_begin != m_children_end )
  {
    v6 = (char *)m_children_begin - (char *)bone;
    do
    {
      vostok::animation::bone_matrices_computer::convert_skeleton_branch(
        this,
        m_children_begin++,
        &result[v6 / 20],
        result);
      v6 += 20;
    }
    while ( m_children_begin != m_children_end );
  }
}
