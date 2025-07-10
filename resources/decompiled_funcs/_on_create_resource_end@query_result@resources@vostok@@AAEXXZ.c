void __thiscall vostok::resources::query_result::on_create_resource_end(vostok::resources::query_result *this)
{
  vostok::resources::query_result *v1; // ebx
  vostok::resources::cook_base *cook; // eax
  vostok::resources::cook_base *v3; // eax
  vostok::resources::query_result *m_flags; // ecx
  vostok::resources::resources_manager *m_variable; // esi
  vostok::resources::query_result *m_next_referer; // eax
  vostok::resources::query_result *v7; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v8; // [esp+14h] [ebp-4h] BYREF

  v1 = this;
  if ( this->m_error_type == error_type_unset )
  {
    cook = vostok::resources::resources_manager::find_cook(this->m_class_id);
    if ( cook )
    {
      if ( (cook->m_flags.m_flags & 8) == 0 )
      {
        if ( v1->m_managed_resource.m_object )
        {
          if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            v3 = vostok::resources::resources_manager::find_cook(v1->m_class_id);
            if ( !v3
              || (this = (vostok::resources::query_result *)v3->m_flags.m_flags,
                  LOBYTE(this) = (unsigned __int8)this & 0x10,
                  (_BYTE)this == 16) )
            {
              vostok::memory::managed_node_owner::resize_down(
                &v1->m_managed_resource.m_object->vostok::memory::managed_node_owner,
                v1->m_final_resource_size);
            }
          }
        }
      }
    }
  }
  if ( v1->m_error_type == error_type_unset )
    vostok::resources::query_result::associate_created_resource_with_fat_or_name_registry(this);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
    &v1->m_managed_resource,
    v1);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
    &v1->m_raw_managed_resource,
    v1);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
    &v1->m_compressed_resource,
    v1);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    &v1->m_unmanaged_resource,
    v1);
  m_flags = (vostok::resources::query_result *)v1->m_flags;
  if ( ((unsigned __int8)m_flags & 0x20) != 0 )
  {
    m_variable = vostok::resources::g_resources_manager.m_variable;
    vostok::threading::interlocked_and(&v1->m_flags, 0xFFFFFFDF);
    vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::erase(
      (vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *)((char *)m_variable + (_DWORD)&loc_201D7 + 1),
      v1);
  }
  if ( (v1->m_flags & 0x40) == 0 )
  {
    m_next_referer = v1->m_next_referer;
    if ( m_next_referer != v1 )
    {
      do
      {
        v7 = m_next_referer->m_next_referer;
        vostok::resources::query_result::on_refered_query_ended(m_flags, v1);
        m_next_referer = v7;
      }
      while ( v7 != v1 );
    }
  }
  if ( v1->m_error_type )
  {
    v8.m_object = v1->m_raw_managed_resource.m_object;
    v1->m_raw_managed_resource.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v8);
  }
  if ( !_InterlockedExchangeAdd(&v1->m_query_end_guard, 0xFFFFFFFF) )
    vostok::resources::query_result::end_query_might_destroy_this_impl((vostok::resources::query_result *)&v1->m_query_end_guard);
}
