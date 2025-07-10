void __usercall vostok::resources::query_result::on_load_operation_end(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::cook_base *cook; // eax
  vostok::resources::query_result *v4; // ecx
  bool v5; // zf
  vostok::resources::query_result *v6; // ecx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v7; // ecx
  vostok::resources::resources_manager *m_variable; // edi
  bool *v9; // [esp+0h] [ebp-124h]
  vostok::fs_new::native_path_string path; // [esp+Ch] [ebp-118h] BYREF

  if ( *(_DWORD *)(a2 + 256) )
  {
    cook = vostok::resources::resources_manager::find_cook((int)this, *(vostok::resources::class_id_enum *)(a2 + 132));
    if ( cook && vostok::resources::cook_base::does_create_resource_if_no_file(cook) )
    {
      vostok::resources::query_result::prepare_final_resource(v4, (vostok::resources::query_result *)a2);
      return;
    }
    v6 = (vostok::resources::query_result *)_InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 684), 0xFFFFFFFF);
    v5 = v6 == 0;
    goto LABEL_6;
  }
  if ( !vostok::resources::query_result::check_file_crc(this, (vostok::vfs::vfs_iterator *)a2) )
  {
    *(_DWORD *)(a2 + 256) = 9;
    v5 = _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 684), 0xFFFFFFFF) == 0;
LABEL_6:
    if ( v5 )
      vostok::resources::query_result::end_query_might_destroy_this_impl(v6, (vostok::resources::query_result *)a2);
    return;
  }
  if ( !vostok::vfs::vfs_iterator::is_replicated((vostok::vfs::vfs_iterator *)(a2 + 160)) )
    vostok::vfs::vfs_iterator::get_physical_path((vostok::vfs::vfs_iterator *)(a2 + 160), &path);
  if ( vostok::vfs::vfs_iterator::is_compressed((vostok::vfs::vfs_iterator *)(a2 + 160)) )
  {
    m_variable = vostok::resources::g_resources_manager.m_variable;
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v7,
      (char *)&loc_2047F + (unsigned int)vostok::resources::g_resources_manager.m_variable + 1,
      (vostok::resources::query_result *)a2,
      v9);
    SetEvent(*(HANDLE *)((char *)&dword_203E0 + (_DWORD)m_variable));
  }
  else
  {
    vostok::resources::query_result::on_decompressing_end((vostok::resources::query_result *)v7, a2);
  }
}
