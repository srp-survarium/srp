void __thiscall vostok::animation::bone_matrices_computer::compute_skeleton_branch_local(
        vostok::animation::bone_matrices_computer *this,
        vostok::animation::bone_matrices_computer *bone,
        vostok::math::float4x4 *result,
        const vostok::animation::skeleton_bone *bone_mask,
        const unsigned int *result_masks)
{
  unsigned int m_id; // eax
  const vostok::animation::skeleton_bone *m_animations; // esi
  int v7; // edi
  const unsigned int *v8; // ebp
  const unsigned int *v9; // eax
  vostok::math::float4x4 v11; // [esp+18h] [ebp-44h] BYREF
  const vostok::animation::skeleton_bone *e; // [esp+68h] [ebp+Ch]

  if ( bone_mask )
    m_id = (unsigned int)bone_mask->m_id;
  else
    m_id = bone->m_layers_count;
  qmemcpy(
    (void *)result,
    vostok::animation::bone_matrices_computer::computed_local_bone_matrix(
      this,
      (vostok::animation::bone_transform *)this,
      &v11,
      bone,
      m_id),
    sizeof(vostok::math::float4x4));
  m_animations = (const vostok::animation::skeleton_bone *)bone->m_animations;
  e = (const vostok::animation::skeleton_bone *)bone->m_animations_count;
  if ( m_animations != e )
  {
    v7 = (char *)m_animations - (char *)bone;
    do
    {
      if ( result_masks )
      {
        v8 = &result_masks[v7 / 20];
        v9 = &result_masks[((char *)bone->m_animations - (char *)bone) / 20];
      }
      else
      {
        v8 = 0;
        v9 = 0;
      }
      vostok::animation::bone_matrices_computer::compute_skeleton_branch_local(
        this,
        m_animations++,
        &result[v7 / 20],
        v9,
        v8);
      v7 += 20;
    }
    while ( m_animations != e );
  }
}
