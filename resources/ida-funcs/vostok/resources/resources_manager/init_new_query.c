void __usercall vostok::resources::resources_manager::init_new_query(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::query_result *query@<eax>)
{
  vostok::resources::cook_base *cook; // eax
  char *m_requery_path; // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  bool v7; // al
  vostok::resources::query_result::consider_with_name_registry_result_enum v8; // eax
  vostok::resources::query_result *v9; // ecx
  vostok::resources::allocate_functionality *m_size; // ecx
  vostok::resources::allocate_functionality *v11; // [esp+0h] [ebp-14Ch]
  char *other; // [esp+Ch] [ebp-140h] BYREF
  boost::function<void __cdecl(void)> dispatch_callback; // [esp+10h] [ebp-13Ch] BYREF
  vostok::fs_new::virtual_path_string virtual_path; // [esp+30h] [ebp-11Ch] BYREF

  cook = vostok::resources::resources_manager::find_cook((int)this, query->m_class_id);
  if ( cook && (cook->m_flags.m_flags & 8) != 0 )
  {
    if ( query->m_create_resource_result == result_requery )
    {
      m_requery_path = query->m_requery_path;
      if ( !m_requery_path )
        m_requery_path = query->m_request_path;
      other = m_requery_path;
      vostok::fs_new::virtual_path_string::virtual_path_string(&virtual_path, (const char **)&other);
      dispatch_callback.vtable = 0;
      vostok::vfs::query_hot_mount_and_wait(
        (vostok::vfs::virtual_file_system *)((char *)&loc_20600 + (_DWORD)this),
        &virtual_path,
        0,
        &vostok::memory::g_resources_helper_allocator,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&dispatch_callback);
      if ( dispatch_callback.vtable && ((int)dispatch_callback.vtable & 1) == 0 )
      {
        v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)dispatch_callback.vtable & 0xFFFFFFFE);
        if ( v6 )
          v6(&dispatch_callback.functor, &dispatch_callback.functor, 2);
      }
    }
    vostok::resources::resources_manager::push_to_translate_query(query, this);
  }
  else
  {
    v7 = query->m_creation_data_from_user.m_data || query->m_creation_data_from_user.m_size;
    v8 = vostok::resources::query_result::consider_with_name_registry(
           (vostok::resources::query_result *)!v7,
           (vostok::resources::query_result::only_try_to_get_associated_resource_bool)query);
    if ( v8 == consider_with_name_registry_result_error
      || v8 == consider_with_name_registry_result_got_associated_resource )
    {
      if ( !_InterlockedExchangeAdd(&query->m_query_end_guard, 0xFFFFFFFF) )
        vostok::resources::query_result::end_query_might_destroy_this_impl(v9, query);
    }
    else if ( v8 != consider_with_name_registry_result_added_as_referer )
    {
      m_size = (vostok::resources::allocate_functionality *)query->m_creation_data_from_user.m_size;
      if ( query->m_creation_data_from_user.m_data || m_size )
        vostok::resources::allocate_functionality::prepare_raw_resource(query, 0, m_size, v11);
      else
        vostok::resources::query_result::process_request_path(0, query, 0);
    }
  }
}
