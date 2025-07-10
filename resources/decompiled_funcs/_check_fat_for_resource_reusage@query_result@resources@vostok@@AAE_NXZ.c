bool __thiscall vostok::resources::query_result::check_fat_for_resource_reusage(
        vostok::resources::query_result *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> cached_resource)
{
  vostok::resources::query_result *m_object; // ebx
  vostok::resources::cook_base *cook; // eax
  vostok::resources::unmanaged_resource *v5; // esi
  vostok::resources::unmanaged_resource *v6; // eax
  vostok::resources::resource_base *v7; // edi
  vostok::resources::query_result *v8; // ecx
  vostok::vfs::vfs_iterator v9[2]; // [esp-10h] [ebp-28h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> cached_unmanaged_resource; // [esp+10h] [ebp-8h] BYREF
  vostok::resources::resource_base *associated; // [esp+14h] [ebp-4h]

  m_object = (vostok::resources::query_result *)cached_resource.m_object;
  cook = vostok::resources::resources_manager::find_cook((int)this, cached_resource.m_object->m_class_id);
  if ( cook && cook->m_reuse_type != reuse_true || !m_object->m_fat_it.m_node )
    return 0;
  associated = 0;
  vostok::vfs::vfs_iterator::vfs_iterator(v9, &m_object->m_fat_it);
  vostok::resources::get_associated_unmanaged_resource_ptr(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cached_unmanaged_resource,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v9[0].m_hashset);
  v5 = cached_unmanaged_resource.m_object;
  if ( cached_unmanaged_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    _InterlockedExchangeAdd(&cached_unmanaged_resource.m_object->m_reference_count, 1u);
    v6 = m_object->m_unmanaged_resource.m_object;
    m_object->m_unmanaged_resource.m_object = v5;
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    v7 = v5;
  }
  else
  {
    vostok::vfs::vfs_iterator::vfs_iterator(v9, &m_object->m_fat_it);
    vostok::resources::get_associated_managed_resource_ptr(
      &cached_resource,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v9[0].m_hashset);
    if ( cached_resource.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( (cached_resource.m_object->m_flags.m_flags & 0x10) == 0 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
          &m_object->m_managed_resource,
          &cached_resource);
        associated = cached_resource.m_object;
      }
      v5 = cached_unmanaged_resource.m_object;
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&cached_resource);
    v7 = associated;
  }
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  if ( v7 )
  {
    vostok::threading::interlocked_or(&m_object->m_flags, 0x40000u);
    if ( !_InterlockedExchangeAdd(&m_object->m_query_end_guard, 0xFFFFFFFF) )
      vostok::resources::query_result::end_query_might_destroy_this_impl(v8, m_object);
  }
  return v7 != 0;
}
