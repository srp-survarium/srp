void __userpurge vostok::resources::resources_manager::save_generated_resource(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::resources_manager *a2@<ecx>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::device_manager *capable_device_manager; // ebx
  vostok::resources::query_result *v5; // esi
  vostok::resources::query_result *v6; // eax
  vostok::resources::query_result *v7; // esi
  vostok::resources::query_result_for_cook *v8; // [esp+10h] [ebp-14h]
  vostok::resources::save_generated_data *m_save_generated_data; // [esp+10h] [ebp-14h]

  capable_device_manager = vostok::resources::resources_manager::find_capable_device_manager(
                             a2,
                             this,
                             query->m_save_generated_data->m_physical_path);
  if ( capable_device_manager )
  {
    v5 = (vostok::resources::query_result *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              &vostok::memory::g_resources_helper_allocator,
                                              0x2D0u);
    if ( v5 )
    {
      vostok::resources::query_result::query_result(
        v5,
        0,
        0,
        0,
        0,
        0.0,
        0,
        0,
        query_type_normal,
        autoselect_quality_false);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    m_save_generated_data = query->m_save_generated_data;
    query->m_save_generated_data = 0;
    vostok::resources::query_result::init_save(v7, m_save_generated_data, query);
    capable_device_manager->push_query_impl(capable_device_manager, v7);
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
  }
  else
  {
    v8 = query->m_create_resource_result != result_error ? 0 : (vostok::resources::query_result_for_cook *)11;
    vostok::resources::query_result_for_cook::finish_query_impl(
      v8,
      query->m_create_resource_result,
      assert_on_fail_true,
      (vostok::resources::query_result_for_user::error_type_enum)v8);
  }
}
