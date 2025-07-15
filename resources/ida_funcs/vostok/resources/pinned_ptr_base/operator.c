const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > **__userpurge vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::operator=@<eax>(
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *this@<ecx>,
        const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > **a2@<esi>,
        const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *other)
{
  const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *v3; // ebx
  int p_m_size; // eax
  const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *v5; // eax
  unsigned int m_size; // eax
  const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *v7; // eax
  bool v8; // zf

  v3 = other;
  if ( *a2 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      p_m_size = (int)&a2[1][-5].m_size;
      _InterlockedExchangeAdd((volatile signed __int32 *)(p_m_size + 44), 0xFFFFFFFF);
      if ( *(_DWORD *)(p_m_size + 16) )
      {
        if ( !*(_DWORD *)(p_m_size + 44) )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)(p_m_size + 16) + 40), 1u);
          *(_DWORD *)(p_m_size + 16) = 0;
        }
      }
    }
  }
  other = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&other,
    &v3->m_resource);
  v5 = other;
  other = *a2;
  *a2 = v5;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&other);
  if ( *a2
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_size = (*a2)[17].m_size;
    _InterlockedExchangeAdd((volatile signed __int32 *)(m_size + 44), 1u);
    v7 = (const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *)(m_size + 52);
  }
  else
  {
    v7 = 0;
  }
  v8 = *a2 == 0;
  a2[1] = v7;
  if ( v8
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    a2[2] = 0;
    return a2;
  }
  else
  {
    a2[2] = (const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *)v3->m_size;
    return a2;
  }
}
