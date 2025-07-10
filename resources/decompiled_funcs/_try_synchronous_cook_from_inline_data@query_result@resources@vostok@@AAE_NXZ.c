char __usercall vostok::resources::query_result::try_synchronous_cook_from_inline_data@<al>(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result *a2@<eax>)
{
  vostok::vfs::base_node<1> *v4; // eax
  vostok::resources::cook_base *cook; // eax
  vostok::resources::cook_base *v6; // eax
  DWORD CurrentThreadId; // edi
  vostok::resources::query_result *v8; // ecx
  vostok::resources::query_result *v9; // ecx
  vostok::resources::query_result *v10; // ecx
  vostok::resources::query_result *v11; // ecx
  vostok::resources::query_result *v12; // ecx

  if ( !a2->m_fat_it.m_node )
    return 0;
  if ( vostok::vfs::vfs_iterator::is_compressed(&a2->m_fat_it) )
    return 0;
  v4 = vostok::vfs::vfs_iterator::data_node(&a2->m_fat_it);
  if ( !vostok::vfs::base_node<1>::is_inlined(v4) )
    return 0;
  cook = vostok::resources::resources_manager::find_cook(a2->m_class_id);
  if ( !cook )
    return 0;
  if ( !cook->allow_sync_load_from_inline(cook) )
    return 0;
  v6 = vostok::resources::resources_manager::find_cook(a2->m_class_id);
  if ( !v6 )
    return 0;
  if ( (v6->m_flags.m_flags & 0x20) == 0x20 )
    return 0;
  CurrentThreadId = GetCurrentThreadId();
  if ( vostok::resources::query_result::allocate_thread_id(v8, (int)a2) != CurrentThreadId )
    return 0;
  if ( vostok::mutable_buffer::operator bool(&a2->m_raw_unmanaged_buffer) )
    vostok::resources::query_result::copy_inline_data_to_resource_if_needed(v9, (vostok::vfs::vfs_iterator *)a2);
  if ( vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data(v9, (int)a2) )
    vostok::resources::query_result::bind_unmanaged_resource_buffer_to_creation_or_inline_data(v10, (int)a2);
  else
    vostok::resources::query_result::allocate_final_unmanaged_resource_if_needed(v10, (int)a2);
  _InterlockedExchangeAdd(&a2->m_query_end_guard, 1u);
  vostok::resources::query_result::do_create_resource_impl(v11);
  if ( !vostok::resources::query_result::end_query_might_destroy_this(v12) )
    vostok::resources::query_result::on_create_resource_end(a2);
  return 1;
}
