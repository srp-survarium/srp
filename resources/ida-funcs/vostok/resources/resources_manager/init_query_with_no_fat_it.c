void __usercall vostok::resources::resources_manager::init_query_with_no_fat_it(
        vostok::resources::query_result *query@<eax>)
{
  vostok::resources::cook_base::reuse_enum v2; // eax
  vostok::resources::query_result *v3; // ecx
  vostok::resources::query_result *i; // edi
  const char *requested_path; // eax
  const char *v6; // edx
  vostok::resources::query_result *v7; // [esp-4h] [ebp-10h]
  vostok::resources::query_result *v8; // [esp-4h] [ebp-10h]
  vostok::resources::reallocating_bool v9; // [esp+0h] [ebp-Ch]

  if ( !vostok::resources::cook_base::does_create_resource_if_no_file(query->m_class_id)
    || query->m_create_resource_result == result_cannot_lock )
  {
    query->m_error_type = error_type_file_not_found;
    vostok::resources::query_result::end_query_might_destroy_this(v7, (int)query);
  }
  else
  {
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)v7,
      (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_generate_if_no_file_queue.m_policy);
    v2 = vostok::resources::cook_base::reuse_type(query->m_class_id);
    v3 = v8;
    if ( v2 )
    {
      for ( i = s_resources_manager_buffer.m_generate_if_no_file_queue.m_first;
            i;
            i = i->m_next_in_generate_if_no_file_queue )
      {
        vostok::resources::query_result_for_user::get_requested_path(i);
        requested_path = vostok::resources::query_result_for_user::get_requested_path(query);
        if ( !vostok::strings::compare(requested_path, v6) )
        {
          vostok::resources::query_result::add_referrer(query, v3, i, v9);
          goto LABEL_10;
        }
      }
    }
    query->m_error_type = error_type_file_not_found;
    vostok::resources::resources_manager::add_to_generate_if_no_file_queue(query, (vostok::threading::mutex *)v3);
    vostok::resources::allocate_functionality::prepare_raw_resource(query, 0, v9);
LABEL_10:
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_generate_if_no_file_queue.m_policy);
  }
}
