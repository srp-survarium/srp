void __userpurge vostok::animation::bone_matrices_computer::compute_skeleton_branch(
        vostok::animation::bone_matrices_computer *this@<ecx>,
        float a2@<xmm4>,
        const vostok::animation::skeleton_bone *bone,
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *parent,
        unsigned int *bone_mask,
        const unsigned int *result_masks,
        unsigned __int8 calc_mask)
{
  unsigned int m_mask; // eax
  vostok::math::float4x4 *v10; // eax
  const vostok::animation::skeleton_bone *m_children_begin; // esi
  int v12; // edi
  unsigned int *v13; // eax
  vostok::math::float4x4 v14; // [esp+Ch] [ebp-84h] BYREF
  vostok::math::float4x4 v15; // [esp+4Ch] [ebp-44h] BYREF
  vostok::animation::bone_matrices_computer *v16; // [esp+8Ch] [ebp-4h]
  const vostok::animation::skeleton_bone *m_children_end; // [esp+98h] [ebp+8h]
  unsigned int *result_masksa; // [esp+A4h] [ebp+14h]

  v16 = this;
  if ( bone_mask )
    m_mask = *bone_mask;
  else
    m_mask = bone->m_mask;
  v10 = vostok::animation::bone_matrices_computer::computed_local_bone_matrix(
          this,
          (vostok::animation::bone_transform *)this,
          &v14,
          (unsigned int)bone,
          m_mask);
  vostok::math::mul4x3(parent, v10, &v15);
  qmemcpy(result, &v15, sizeof(vostok::math::float4x4));
  m_children_begin = bone->m_children_begin;
  m_children_end = bone->m_children_end;
  if ( m_children_begin != m_children_end )
  {
    v12 = (char *)m_children_begin - (char *)bone;
    do
    {
      if ( (calc_mask & m_children_begin->m_calc_mask) != 0 )
      {
        if ( result_masks )
          result_masksa = (unsigned int *)&result_masks[v12 / 28];
        else
          result_masksa = 0;
        v13 = 0;
        if ( result_masks )
          v13 = (unsigned int *)&result_masks[bone->m_children_begin - bone];
        vostok::animation::bone_matrices_computer::compute_skeleton_branch(
          v16,
          a2,
          m_children_begin,
          &result[v12 / 28],
          result,
          v13,
          result_masksa,
          calc_mask);
      }
      ++m_children_begin;
      v12 += 28;
    }
    while ( m_children_begin != m_children_end );
  }
}
