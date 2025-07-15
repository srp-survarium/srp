void __thiscall vostok::animation::bone_matrices_computer::compute_bones_matrices(
        vostok::animation::bone_matrices_computer *this,
        vostok::animation::bone_matrices_computer *begin,
        vostok::math::float4x4 *end,
        const unsigned int *bones_masks)
{
  int v5; // edx
  const vostok::animation::skeleton_bone *m_flags; // esi
  const unsigned int *v7; // eax
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  const unsigned int *v11; // ebx
  const unsigned int *v12; // eax
  const vostok::math::float4x4 *v13; // eax
  unsigned int *v14; // [esp-8h] [ebp-68h]
  int i; // [esp+10h] [ebp-50h]
  const vostok::animation::skeleton_bone *children_end; // [esp+14h] [ebp-4Ch]
  const vostok::animation::skeleton_bone *roots_begin; // [esp+18h] [ebp-48h]
  const vostok::animation::skeleton_bone *roots_end; // [esp+1Ch] [ebp-44h]
  vostok::math::float4x4 v19; // [esp+20h] [ebp-40h] BYREF
  const unsigned int *bones_masksa; // [esp+6Ch] [ebp+Ch]

  v5 = (int)&begin->m_skeleton[1];
  m_flags = (const vostok::animation::skeleton_bone *)begin->m_skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  roots_begin = (const vostok::animation::skeleton_bone *)v5;
  roots_end = m_flags;
  if ( (const vostok::animation::skeleton_bone *)v5 != m_flags )
  {
    v7 = (const unsigned int *)(&begin->m_skeleton[1].vostok::resources::resource_flags + 1);
    bones_masksa = v7;
    do
    {
      v8 = *(v7 - 1);
      children_end = (const vostok::animation::skeleton_bone *)*v7;
      if ( v8 != *v7 )
      {
        v9 = 0;
        v10 = v8 - v5;
        for ( i = v8 - v5; ; v10 = i )
        {
          if ( bones_masks )
          {
            v11 = &bones_masks[v9 / 20];
            v12 = &bones_masks[(v9 + v10) / 20];
          }
          else
          {
            v11 = 0;
            v12 = 0;
          }
          v14 = (unsigned int *)v12;
          v13 = vostok::math::float4x4::identity(&v19);
          vostok::animation::bone_matrices_computer::compute_skeleton_branch(
            begin,
            (vostok::animation::bone_matrices_computer *)(v9 + v8),
            &end[v9 / 20],
            v13,
            v14,
            v11);
          v9 += 20;
          if ( (const vostok::animation::skeleton_bone *)(v9 + v8) == children_end )
            break;
        }
        v5 = (int)roots_begin;
        m_flags = roots_end;
        v7 = bones_masksa;
      }
      v7 += 5;
      bones_masksa = v7;
    }
    while ( v7 - 3 != (const unsigned int *)m_flags );
  }
}
