void __usercall vostok::resources::query_result::on_load_operation_end(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  bool v3; // zf
  vostok::resources::query_result *v4; // ecx
  vostok::resources::query_result *v5; // eax
  vostok::resources::query_result *v6; // [esp-4h] [ebp-128h]
  vostok::fs_new::native_path_string v7; // [esp+Ch] [ebp-118h] BYREF

  if ( *(_DWORD *)(a2 + 256) )
  {
    v3 = !vostok::resources::cook_base::does_create_resource_if_no_file(*(vostok::resources::class_id_enum *)(a2 + 132));
    v4 = v6;
    v5 = (vostok::resources::query_result *)a2;
    if ( !v3 )
    {
LABEL_3:
      vostok::resources::query_result::prepare_final_resource(v4, v5);
      return;
    }
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(a2 + 164) + 48) & 0x20) == 0 )
      vostok::vfs::vfs_iterator::get_physical_path((vostok::vfs::vfs_iterator *)this, a2 + 160, &v7);
    if ( vostok::vfs::vfs_iterator::is_compressed((vostok::vfs::vfs_iterator *)(a2 + 160)) )
    {
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        &s_resources_manager_buffer.m_resources_to_decompress,
        (vostok::resources::query_result *)a2,
        (vostok::threading::mutex *)v4);
      SetEvent(*(HANDLE *)s_resources_manager_buffer.m_cooker_wakeup_event.m_event.m_event);
      return;
    }
    v5 = (vostok::resources::query_result *)a2;
    if ( !*(_DWORD *)(a2 + 256) )
      goto LABEL_3;
  }
  vostok::resources::query_result::end_query_might_destroy_this(v4, (int)v5);
}
