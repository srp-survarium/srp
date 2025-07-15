void __usercall vostok::animation::bone_matrices_computer::~bone_matrices_computer(
        vostok::animation::bone_matrices_computer *this@<ecx>,
        int a2@<eax>)
{
  int v2; // edi
  int v3; // ebx
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *v4; // ecx
  const unsigned __int8 *m_data; // eax
  const unsigned __int8 *v6; // ecx
  const unsigned __int8 *v7; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v8; // [esp+Ch] [ebp-10h] BYREF
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > other; // [esp+10h] [ebp-Ch] BYREF

  v2 = *(_DWORD *)(a2 + 8);
  v3 = v2 + 180 * *(_DWORD *)(a2 + 12);
  if ( v2 != v3 )
  {
    v8.m_object = 0;
    do
    {
      vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
        (vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)this,
        &other.m_resource,
        0);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v8);
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::operator=(
        v4,
        (const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > **)(v2 + 80),
        &other);
      if ( other.m_resource.m_object )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          m_data = other.m_data;
          v6 = other.m_data - 8;
          _InterlockedExchangeAdd((volatile signed __int32 *)other.m_data - 2, 0xFFFFFFFF);
          v7 = m_data - 36;
          if ( *(_DWORD *)v7 )
          {
            if ( !*(_DWORD *)v6 )
            {
              _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v7 + 40), 1u);
              *(_DWORD *)v7 = 0;
            }
          }
        }
      }
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&other.m_resource);
      v2 += 180;
    }
    while ( v2 != v3 );
  }
}
