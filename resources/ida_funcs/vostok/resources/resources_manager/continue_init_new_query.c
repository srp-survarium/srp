void __userpurge vostok::resources::resources_manager::continue_init_new_query(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::resources_manager *this)
{
  int v3; // ecx
  vostok::resources::unmanaged_resource *m_object; // ebx
  vostok::resources::query_result *v5; // ecx
  vostok::resources::query_result *v6; // ecx
  vostok::resources::query_result *associated_query_result; // eax
  vostok::resources::allocate_functionality *v8; // ecx
  vostok::vfs::vfs_iterator v9; // [esp-10h] [ebp-158h] BYREF
  vostok::resources::allocate_functionality *v10; // [esp+0h] [ebp-148h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> cached_unmanaged; // [esp+10h] [ebp-138h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> cached_resource; // [esp+14h] [ebp-134h] BYREF
  vostok::vfs::vfs_iterator fat_it; // [esp+18h] [ebp-130h] BYREF
  vostok::const_buffer inline_data; // [esp+28h] [ebp-120h] BYREF
  vostok::fs_new::native_path_string file_path; // [esp+30h] [ebp-118h] BYREF

  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it, &query->m_fat_it);
  if ( !fat_it.m_node )
  {
    vostok::resources::resources_manager::init_query_with_no_fat_it(this, this, query);
    return;
  }
  vostok::vfs::vfs_iterator::get_physical_path(&fat_it, &file_path);
  vostok::resources::resources_manager::find_cook(v3, query->m_class_id);
  vostok::const_buffer::const_buffer((vostok::mutable_buffer *)&inline_data);
  vostok::vfs::vfs_iterator::vfs_iterator(&v9, &fat_it);
  vostok::resources::get_associated_unmanaged_resource_ptr(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cached_unmanaged,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v9.m_hashset);
  m_object = cached_unmanaged.m_object;
  if ( cached_unmanaged.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v9.m_type = type_unset;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v9.m_type,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cached_unmanaged);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      &m_object->m_memory_usage_self,
      query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v9.m_type);
    vostok::threading::interlocked_or(&query->m_flags, 0x40000u);
    if ( !_InterlockedExchangeAdd(&query->m_query_end_guard, 0xFFFFFFFF) )
      vostok::resources::query_result::end_query_might_destroy_this_impl(
        (vostok::resources::query_result *)&query->m_query_end_guard,
        query);
    goto LABEL_21;
  }
  vostok::vfs::vfs_iterator::vfs_iterator(&v9, &fat_it);
  vostok::resources::get_associated_managed_resource_ptr(
    &cached_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v9.m_hashset);
  if ( cached_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( (cached_resource.m_object->m_flags.m_flags & 0x10) != 0 )
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
        &query->m_raw_managed_resource,
        &cached_resource);
      vostok::threading::interlocked_or(&query->m_flags, 0x80000u);
      vostok::resources::query_result::on_file_operation_end(v5, query);
    }
    else
    {
      v9.m_type = (vostok::vfs::vfs_iterator::type_enum)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v9.m_type,
        &cached_resource);
      vostok::resources::query_result_for_cook::set_managed_resource(
        query,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v9.m_type);
      vostok::threading::interlocked_or(&query->m_flags, 0x40000u);
      vostok::resources::query_result::end_query_might_destroy_this(v6, (int)query);
    }
LABEL_19:
    m_object = cached_unmanaged.m_object;
    goto LABEL_20;
  }
  vostok::vfs::vfs_iterator::vfs_iterator(&v9, &fat_it);
  associated_query_result = vostok::resources::get_associated_query_result(v9);
  if ( !associated_query_result )
  {
    if ( (query->m_flags & 2) != 0
      && fat_it.m_node
      && vostok::resources::cook_base::reuse_type((int)v8, query->m_class_id) )
    {
      vostok::vfs::vfs_iterator::vfs_iterator(&v9, &fat_it);
      vostok::resources::set_associated(query, v9);
    }
    vostok::resources::allocate_functionality::prepare_raw_resource(query, 0, v8, v10);
    goto LABEL_19;
  }
  vostok::resources::query_result::add_referrer(
    query,
    (vostok::resources::query_result *)v8,
    associated_query_result,
    1);
LABEL_20:
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&cached_resource);
LABEL_21:
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
  }
}
