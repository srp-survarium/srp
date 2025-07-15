void __userpurge vostok::animation::bone_matrices_computer::compute_skeleton_branch_local(
        vostok::animation::bone_matrices_computer *this@<ecx>,
        float a2@<xmm4>,
        const vostok::animation::skeleton_bone *bone,
        vostok::math::float4x4 *result,
        unsigned int *bone_mask,
        const unsigned int *result_masks,
        unsigned __int8 calc_mask)
{
  unsigned int m_mask; // eax
  const vostok::animation::skeleton_bone *m_children_begin; // esi
  int v10; // edi
  unsigned int *v11; // eax
  vostok::math::float4x4 v12; // [esp+Ch] [ebp-48h] BYREF
  vostok::animation::bone_matrices_computer *v13; // [esp+4Ch] [ebp-8h]
  const vostok::animation::skeleton_bone *m_children_end; // [esp+5Ch] [ebp+8h]
  unsigned int *result_masksa; // [esp+64h] [ebp+10h]

  v13 = this;
  if ( bone_mask )
    m_mask = *bone_mask;
  else
    m_mask = bone->m_mask;
  qmemcpy(
    result,
    vostok::animation::bone_matrices_computer::computed_local_bone_matrix(
      this,
      (vostok::animation::bone_transform *)this,
      &v12,
      (unsigned int)bone,
      m_mask),
    sizeof(vostok::math::float4x4));
  m_children_begin = bone->m_children_begin;
  m_children_end = bone->m_children_end;
  if ( m_children_begin != m_children_end )
  {
    v10 = (char *)m_children_begin - (char *)bone;
    do
    {
      if ( (calc_mask & m_children_begin->m_calc_mask) != 0 )
      {
        if ( result_masks )
          result_masksa = (unsigned int *)&result_masks[v10 / 28];
        else
          result_masksa = 0;
        v11 = 0;
        if ( result_masks )
          v11 = (unsigned int *)&result_masks[bone->m_children_begin - bone];
        vostok::animation::bone_matrices_computer::compute_skeleton_branch_local(
          v13,
          a2,
          m_children_begin,
          &result[v10 / 28],
          v11,
          result_masksa,
          calc_mask);
      }
      ++m_children_begin;
      v10 += 28;
    }
    while ( m_children_begin != m_children_end );
  }
}
