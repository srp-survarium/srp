void __userpurge vostok::resources::resources_manager::init_new_queries(
        vostok::resources::query_result *queries_with_unlocked_fat_it@<eax>,
        vostok::resources::resources_manager *a2@<ecx>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::query_result *v3; // edi
  vostok::resources::class_id_enum m_class_id; // eax
  vostok::resources::query_result *m_next_in_device_manager; // ebx
  vostok::resources::cook_base *cook; // eax
  vostok::threading::mutex *m_num_cook_registrators; // ecx
  vostok::resources::resources_manager *v8; // [esp-4h] [ebp-14h]

  v3 = queries_with_unlocked_fat_it;
  if ( queries_with_unlocked_fat_it )
  {
    do
    {
      m_class_id = v3->m_class_id;
      m_next_in_device_manager = v3->m_next_in_device_manager;
      if ( m_class_id == raw_data_class
        || m_class_id == raw_data_class_no_reuse
        || (cook = vostok::resources::resources_manager::find_cook(v3->m_class_id), a2 = v8, cook) )
      {
        vostok::resources::resources_manager::init_new_query(
          a2,
          this,
          (vostok::resources::query_result::only_try_to_get_associated_resource_bool)v3);
      }
      else
      {
        m_num_cook_registrators = (vostok::threading::mutex *)this->m_num_cook_registrators;
        if ( m_num_cook_registrators )
        {
          vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
            (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)((char *)&loc_20290 + (_DWORD)this),
            v3,
            m_num_cook_registrators);
        }
        else
        {
          v3->m_error_type = error_type_cook_not_registered;
          vostok::resources::query_result::end_query_might_destroy_this(0, (int)v3);
        }
      }
      v3 = m_next_in_device_manager;
    }
    while ( m_next_in_device_manager );
  }
}
