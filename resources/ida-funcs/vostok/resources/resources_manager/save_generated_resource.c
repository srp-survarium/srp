void __userpurge vostok::resources::resources_manager::save_generated_resource(
        const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *query@<eax>,
        vostok::resources::resources_manager *a2@<ecx>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::query_result_for_cook *v4; // ecx
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  vostok::resources::query_result *v8; // ecx
  vostok::resources::query_result *v9; // eax
  vostok::resources::query_result *v10; // esi
  vostok::resources::save_generated_data *pointer; // ebx
  vostok::resources::resources_manager *v12; // ecx
  const char *v13; // [esp+14h] [ebp-14h]
  const char *v14; // [esp+18h] [ebp-10h]
  unsigned int v15; // [esp+1Ch] [ebp-Ch]
  vostok::resources::device_manager *capable_device_manager; // [esp+24h] [ebp-4h]

  capable_device_manager = vostok::resources::resources_manager::find_capable_device_manager(
                             a2,
                             (const char *)this,
                             *(_DWORD *)&query[4].m_free_list_head.pointer->data[12]);
  if ( capable_device_manager )
  {
    v5 = type_info::raw_name(&vostok::resources::query_result `RTTI Type Descriptor');
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           v6,
           (int)&vostok::memory::g_resources_helper_allocator,
           0x2E0u,
           v5,
           v13,
           v14,
           v15);
    if ( v7 )
    {
      vostok::resources::query_result::query_result(
        v8,
        (int)v7,
        0,
        0,
        0,
        0,
        0.0,
        0,
        0,
        query_type_normal,
        autoselect_quality_false);
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    pointer = (vostok::resources::save_generated_data *)query[4].m_free_list_head.pointer;
    query[4].m_free_list_head.pointer = 0;
    v10->m_data_to_save_generator = (vostok::resources::query_result *)query;
    _InterlockedAnd(&v10->m_flags, 0xFFFFFFF9);
    _InterlockedOr(&v10->m_flags, 8u);
    vostok::strings::copy(v10->m_request_path, v10->m_request_path_max_size, pointer->m_virtual_path);
    v10->m_save_generated_data = pointer;
    capable_device_manager->push_query_impl(capable_device_manager, v10);
    vostok::resources::resources_manager::wakeup_resources_thread(v12, (int)this);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query(
      v4,
      query,
      (vostok::resources::cook_base::result_enum)query[5].m_on_out_of_memory.functor.vostok_pointer_size_alignment[3],
      assert_on_fail_true);
  }
}
