void __userpurge vostok::animation::bone_matrices_computer::convert_to_object_matrices(
        vostok::math::float4x4 *begin@<eax>,
        vostok::animation::bone_matrices_computer *this,
        vostok::math::float4x4 *end)
{
  const vostok::animation::skeleton *m_flags; // edx
  const vostok::animation::bone_matrices_computer *p_m_flags; // eax
  const vostok::animation::skeleton_bone *m_skeleton; // ebx
  const vostok::animation::skeleton_bone *m_animated_object; // esi
  const vostok::math::float4x4 *v9; // eax
  const vostok::animation::skeleton_bone *roots_end; // [esp+14h] [ebp-44h]
  vostok::math::float4x4 v11; // [esp+18h] [ebp-40h] BYREF
  const vostok::animation::bone_matrices_computer *thisa; // [esp+5Ch] [ebp+4h]

  m_flags = (const vostok::animation::skeleton *)this->m_skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  roots_end = (const vostok::animation::skeleton_bone *)m_flags;
  if ( this->m_skeleton + 1 != m_flags )
  {
    p_m_flags = (const vostok::animation::bone_matrices_computer *)&this->m_skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    thisa = p_m_flags;
    do
    {
      m_skeleton = (const vostok::animation::skeleton_bone *)p_m_flags->m_skeleton;
      m_animated_object = (const vostok::animation::skeleton_bone *)p_m_flags->m_animated_object;
      if ( p_m_flags->m_animated_object != m_skeleton )
      {
        do
        {
          v9 = vostok::math::float4x4::identity(&v11);
          vostok::animation::bone_matrices_computer::convert_skeleton_branch(this, m_animated_object++, begin++, v9);
        }
        while ( m_animated_object != m_skeleton );
        p_m_flags = thisa;
        m_flags = (const vostok::animation::skeleton *)roots_end;
      }
      p_m_flags = (const vostok::animation::bone_matrices_computer *)((char *)p_m_flags + 20);
      thisa = p_m_flags;
    }
    while ( &p_m_flags[-1].m_layers_count != (unsigned int *)m_flags );
  }
}
