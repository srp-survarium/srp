void __userpurge vostok::resources::resources_manager::init_new_queries(
        vostok::resources::query_result *queries_with_unlocked_fat_it@<eax>,
        vostok::resources::query_result *p_m_query_end_guard@<ecx>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::query_result *v3; // esi
  vostok::resources::class_id_enum m_class_id; // edx
  vostok::resources::query_result *m_next_in_device_manager; // edi
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v6; // ecx
  bool *v7; // [esp+0h] [ebp-10h]

  v3 = queries_with_unlocked_fat_it;
  if ( queries_with_unlocked_fat_it )
  {
    do
    {
      m_class_id = v3->m_class_id;
      m_next_in_device_manager = v3->m_next_in_device_manager;
      if ( m_class_id == raw_data_class
        || m_class_id == raw_data_class_no_reuse
        || vostok::resources::resources_manager::find_cook((int)p_m_query_end_guard, m_class_id) )
      {
        vostok::resources::resources_manager::init_new_query(this, v3);
      }
      else if ( this->m_num_cook_registrators )
      {
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
          v6,
          (char *)&loc_20288 + (_DWORD)this,
          v3,
          v7);
      }
      else
      {
        v3->m_error_type = error_type_cook_not_registered;
        p_m_query_end_guard = (vostok::resources::query_result *)&v3->m_query_end_guard;
        if ( !_InterlockedExchangeAdd(&v3->m_query_end_guard, 0xFFFFFFFF) )
          vostok::resources::query_result::end_query_might_destroy_this_impl(p_m_query_end_guard, v3);
      }
      v3 = m_next_in_device_manager;
    }
    while ( m_next_in_device_manager );
  }
}
