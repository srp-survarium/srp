void __thiscall vostok::animation::bone_matrices_computer::compute_skeleton_branch(
        vostok::animation::bone_matrices_computer *this,
        vostok::animation::bone_matrices_computer *bone,
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *parent,
        unsigned int *bone_mask,
        const unsigned int *result_masks)
{
  unsigned int m_layers_count; // eax
  vostok::math::float4x4 *v7; // eax
  const vostok::animation::skeleton_bone *m_animations; // esi
  int v9; // edi
  const unsigned int *v10; // eax
  const unsigned int *v11; // ecx
  const vostok::animation::skeleton_bone *e; // [esp+14h] [ebp-8Ch]
  vostok::math::float4x4 v14; // [esp+20h] [ebp-80h] BYREF
  vostok::math::float4x4 v15; // [esp+60h] [ebp-40h] BYREF

  if ( bone_mask )
    m_layers_count = *bone_mask;
  else
    m_layers_count = bone->m_layers_count;
  v7 = vostok::animation::bone_matrices_computer::computed_local_bone_matrix(
         this,
         (vostok::animation::bone_transform *)this,
         &v15,
         bone,
         m_layers_count);
  vostok::math::mul4x3(&v14, v7, parent);
  qmemcpy((void *)result, &v14, sizeof(vostok::math::float4x4));
  m_animations = (const vostok::animation::skeleton_bone *)bone->m_animations;
  e = (const vostok::animation::skeleton_bone *)bone->m_animations_count;
  if ( m_animations != e )
  {
    v9 = (char *)m_animations - (char *)bone;
    do
    {
      if ( result_masks )
      {
        v10 = &result_masks[((char *)bone->m_animations - (char *)bone) / 20];
        v11 = &result_masks[v9 / 20];
      }
      else
      {
        v11 = 0;
        v10 = 0;
      }
      vostok::animation::bone_matrices_computer::compute_skeleton_branch(
        this,
        m_animations++,
        &result[v9 / 20],
        result,
        v10,
        v11);
      v9 += 20;
    }
    while ( m_animations != e );
  }
}
