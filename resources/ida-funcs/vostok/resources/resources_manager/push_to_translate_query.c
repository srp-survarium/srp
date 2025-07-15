void __userpurge vostok::resources::resources_manager::push_to_translate_query(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::resources_manager *thread_id; // ebx
  vostok::resources::query_result *v4; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::threading::mutex *v6; // ecx
  vostok::resources::resources_manager *v7; // ecx
  vostok::resources::query_result *v8; // [esp-4h] [ebp-14h]

  vostok::resources::cook_base::find_translate_query_cook(query->m_class_id);
  thread_id = (vostok::resources::resources_manager *)vostok::resources::query_result::allocate_thread_id(
                                                        v8,
                                                        (int)query);
  if ( thread_id == (vostok::resources::resources_manager *)GetCurrentThreadId() )
  {
    vostok::resources::query_result::translate_query_if_needed(v4, (int)query);
  }
  else
  {
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          (vostok::resources::resources_manager *)v4,
                          (unsigned int)this,
                          (unsigned int)thread_id,
                          1);
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &thread_local_data->to_translate_query,
      query,
      v6);
    vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(v7, (int)this, thread_id);
  }
}
