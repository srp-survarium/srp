vostok::math::float4x4 *__userpurge vostok::animation::bone_matrices_computer::computed_bone_matrix@<eax>(
        vostok::animation::bone_matrices_computer *this@<ecx>,
        float a2@<xmm4>,
        vostok::math::float4x4 *result,
        const vostok::animation::skeleton_bone *bone,
        unsigned int *bone_mask)
{
  unsigned int m_mask; // eax
  const vostok::animation::skeleton_bone *m_parent; // eax
  vostok::math::float4x4 *v8; // eax
  vostok::math::float4x4 *v9; // eax
  vostok::math::float4x4 resulta; // [esp+10h] [ebp-84h] BYREF
  vostok::math::float4x4 v11; // [esp+50h] [ebp-44h] BYREF

  if ( bone_mask )
    m_mask = *bone_mask;
  else
    m_mask = bone->m_mask;
  vostok::animation::bone_matrices_computer::computed_local_bone_matrix(
    this,
    (vostok::animation::bone_transform *)this,
    &v11,
    (unsigned int)bone,
    m_mask);
  m_parent = bone->m_parent;
  if ( m_parent->m_parent )
  {
    v8 = vostok::animation::bone_matrices_computer::computed_bone_matrix(this, a2, &resulta, m_parent, bone_mask);
    vostok::math::mul4x3(v8, &v11, result);
    return result;
  }
  else
  {
    v9 = result;
    qmemcpy(result, &v11, sizeof(vostok::math::float4x4));
  }
  return v9;
}
