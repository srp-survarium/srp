void __userpurge vostok::animation::bone_matrices_computer::convert_to_object_matrices(
        vostok::math::float4x4 *begin@<eax>,
        vostok::animation::bone_matrices_computer *this,
        vostok::math::float4x4 *end,
        const unsigned __int8 calc_mask)
{
  vostok::math::float4x4 *p_m_flags; // ecx
  float x; // ebx
  vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *v6; // edi
  const vostok::animation::skeleton_bone *m_flags; // esi
  vostok::math::float4x4 *v8; // eax
  vostok::math::float4x4 v9; // [esp+10h] [ebp-48h] BYREF
  const vostok::animation::skeleton_bone *i; // [esp+50h] [ebp-8h]
  vostok::math::float4x4 *v11; // [esp+54h] [ebp-4h]

  v11 = begin;
  p_m_flags = (vostok::math::float4x4 *)&this->m_skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  x = p_m_flags->i.x;
  if ( &this->m_skeleton[1] != (const vostok::animation::skeleton *)LODWORD(p_m_flags->i.x) )
  {
    v6 = &this->m_skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    do
    {
      m_flags = (const vostok::animation::skeleton_bone *)v6->m_flags;
      for ( i = (const vostok::animation::skeleton_bone *)v6[1].m_flags; m_flags != i; ++m_flags )
      {
        if ( ((unsigned __int8)end & m_flags->m_calc_mask) != 0 )
        {
          v8 = vostok::math::float4x4::identity(p_m_flags, &v9);
          vostok::animation::bone_matrices_computer::convert_skeleton_branch(
            this,
            m_flags,
            v11,
            v8,
            (unsigned __int8)end);
        }
        ++v11;
      }
      v6 += 7;
    }
    while ( &v6[-2] != (vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *)LODWORD(x) );
  }
}
