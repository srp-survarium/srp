char __usercall vostok::resources::query_result::try_synchronous_cook_from_inline_data@<al>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<eax>)
{
  int v4; // edx
  int v5; // eax
  vostok::resources::cook_base *cook; // eax
  vostok::resources::cook_base *v7; // eax
  DWORD CurrentThreadId; // edi
  vostok::resources::query_result *v9; // ecx
  vostok::resources::query_result *v10; // ecx
  vostok::resources::query_result *v11; // ecx
  vostok::resources::query_result *v12; // ecx

  if ( !a2[10].m_node || vostok::vfs::vfs_iterator::is_compressed(a2 + 10) )
    return 0;
  v5 = *(_DWORD *)(v4 + 8);
  if ( !v5 )
    v5 = *(_DWORD *)(v4 + 4);
  if ( (*(_BYTE *)(v5 + 48) & 0x40) == 0 )
    return 0;
  cook = vostok::resources::resources_manager::find_cook((vostok::resources::class_id_enum)a2[8].m_node);
  if ( !cook )
    return 0;
  if ( !cook->allow_sync_load_from_inline(cook) )
    return 0;
  v7 = vostok::resources::resources_manager::find_cook((vostok::resources::class_id_enum)a2[8].m_node);
  if ( !v7 )
    return 0;
  if ( (v7->m_flags.m_flags & 0x20) == 0x20 )
    return 0;
  CurrentThreadId = GetCurrentThreadId();
  if ( vostok::resources::query_result::allocate_thread_id(v9, (int)a2) != CurrentThreadId )
    return 0;
  if ( a2[40].m_type )
    vostok::resources::query_result::copy_inline_data_to_resource_if_needed(v10, a2);
  if ( vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data(v10, (int)a2) )
    vostok::resources::query_result::bind_unmanaged_resource_buffer_to_creation_or_inline_data(v11, (int)a2);
  else
    vostok::resources::query_result::allocate_final_unmanaged_resource_if_needed(v11, (int)a2);
  vostok::resources::query_result::do_create_resource_impl(
    (vostok::resources::query_result *)_InterlockedExchangeAdd((volatile signed __int32 *)&a2[43].m_type, 1u),
    (int)a2);
  if ( !vostok::resources::query_result::end_query_might_destroy_this(v12, (int)a2) )
    vostok::resources::query_result::on_create_resource_end((vostok::resources::query_result *)a2);
  return 1;
}
