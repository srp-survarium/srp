void __userpurge vostok::resources::query_result::finish_normal_query(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result *a2@<eax>,
        vostok::resources::cook_base::result_enum create_resource_result)
{
  volatile int m_flags; // ecx
  vostok::resources::query_result *v5; // ecx

  if ( create_resource_result != result_need_async )
    _InterlockedOr(&a2->m_flags, (unsigned int)&loc_200000);
  vostok::resources::query_result::set_deleter_object_if_needed(0, a2);
  m_flags = a2->m_flags;
  if ( ((unsigned int)&loc_100000 & m_flags) == 0 )
  {
    if ( a2->m_save_generated_data )
    {
      _InterlockedAnd(&a2->m_flags, 0xFFDFFFFF);
      vostok::resources::resources_manager::push_generated_resource_to_save(a2, (vostok::threading::mutex *)0xFFDFFFFF);
    }
    else
    {
      vostok::resources::query_result::do_create_resource_end_part(
        (vostok::resources::query_result *)m_flags,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)a2);
      vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this(v5, (int)a2);
    }
  }
}
