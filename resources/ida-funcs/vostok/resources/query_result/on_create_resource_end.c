void __thiscall vostok::resources::query_result::on_create_resource_end(vostok::resources::query_result *this)
{
  vostok::resources::query_result *v1; // ebx
  bool resource; // al
  bool v3; // al
  int v4; // esi
  vostok::resources::unmanaged_resource *v5; // ecx
  int m_object; // edi
  vostok::resources::query_result *m_next_referer; // eax
  vostok::resources::query_result *v8; // esi
  vostok::resources::query_result *v9; // [esp-4h] [ebp-14h]
  vostok::resources::query_result *v10; // [esp-4h] [ebp-14h]

  v1 = this;
  if ( this->m_error_type == error_type_unset )
  {
    resource = vostok::resources::cook_base::does_create_resource(this->m_class_id);
    this = v9;
    if ( resource )
    {
      if ( v1->m_managed_resource.m_object )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          v3 = vostok::resources::cook_base::cooks_inplace(v1->m_class_id);
          this = v10;
          if ( v3 )
          {
            v4 = (int)&v1->m_managed_resource.m_object->vostok::memory::managed_node_owner;
            (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 4))(v4, v1->m_final_resource_size);
            vostok::memory::managed_allocator_base::resize_down(
              *(vostok::memory::managed_node **)(v4 + 4),
              (vostok::memory::managed_allocator_base *)(*(_DWORD *)(v4 + 8) + 20));
          }
        }
      }
    }
  }
  if ( v1->m_error_type == error_type_unset )
    vostok::resources::query_result::associate_created_resource_with_fat_or_name_registry(this, (int)v1);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
    (vostok::resources::query_result *)&v1->m_managed_resource,
    (int)v1);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
    (vostok::resources::query_result *)&v1->m_raw_managed_resource,
    (int)v1);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
    (vostok::resources::query_result *)&v1->m_compressed_resource,
    (int)v1);
  m_object = (int)v1->m_unmanaged_resource.m_object;
  if ( m_object && *(vostok::vfs::base_node<1> **)(m_object + 164) == v1->m_fat_it.m_node )
    vostok::resources::unmanaged_resource::set_sub_fat_resource(v5, m_object, v1->m_sub_fat.m_object);
  if ( (v1->m_flags & 0x20) != 0 )
    vostok::resources::resources_manager::remove_from_generate_if_no_file_queue(v1);
  if ( (v1->m_flags & 0x40) == 0 )
  {
    m_next_referer = v1->m_next_referer;
    if ( m_next_referer != v1 )
    {
      do
      {
        v8 = m_next_referer->m_next_referer;
        vostok::resources::query_result::on_refered_query_ended(v1, m_next_referer);
        m_next_referer = v8;
      }
      while ( v8 != v1 );
    }
  }
  if ( v1->m_error_type )
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
      &v1->m_raw_managed_resource,
      0);
  vostok::resources::query_result::end_query_might_destroy_this((vostok::resources::query_result *)v5, (int)v1);
}
