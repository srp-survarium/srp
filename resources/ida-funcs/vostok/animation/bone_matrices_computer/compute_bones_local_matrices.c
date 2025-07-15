void __userpurge vostok::animation::bone_matrices_computer::compute_bones_local_matrices(
        vostok::animation::bone_matrices_computer *this@<ecx>,
        float a2@<xmm4>,
        vostok::animation::bone_matrices_computer *begin,
        vostok::math::float4x4 *end,
        const unsigned int *bones_masks,
        const unsigned __int8 calc_mask)
{
  const vostok::animation::skeleton *m_skeleton; // eax
  volatile int m_flags; // ecx
  const vostok::animation::skeleton *v8; // eax
  const vostok::animation::skeleton_bone **v9; // esi
  const vostok::animation::skeleton_bone *v10; // edi
  int v11; // ebx
  const vostok::animation::skeleton_bone **v12; // [esp+Ch] [ebp-8h]
  const vostok::animation::skeleton_bone *v13; // [esp+10h] [ebp-4h]

  m_skeleton = begin->m_skeleton;
  m_flags = m_skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v8 = m_skeleton + 1;
  v12 = (const vostok::animation::skeleton_bone **)m_flags;
  if ( v8 != (const vostok::animation::skeleton *)m_flags )
  {
    v9 = (const vostok::animation::skeleton_bone **)(&v8->vostok::resources::resource_flags + 1);
    do
    {
      v10 = *(v9 - 1);
      v13 = *v9;
      if ( v10 != *v9 )
      {
        v11 = 0;
        do
        {
          if ( ((unsigned __int8)bones_masks & v10->m_calc_mask) != 0 )
            vostok::animation::bone_matrices_computer::compute_skeleton_branch_local(
              begin,
              a2,
              v10,
              &end[v11 / 28],
              0,
              0,
              (unsigned __int8)bones_masks);
          ++v10;
          v11 += 28;
        }
        while ( v10 != v13 );
      }
      v9 += 7;
    }
    while ( v9 - 3 != v12 );
  }
}
