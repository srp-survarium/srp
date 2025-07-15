void __usercall vostok::resources::query_result::finish_translated_query(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result *a2@<eax>)
{
  vostok::resources::query_result *v3; // ecx
  char v4; // [esp+Bh] [ebp-1h] BYREF

  vostok::resources::query_result::set_deleter_object_if_needed((vostok::resources::query_result *)&v4, a2);
  if ( a2->m_save_generated_data )
  {
    _InterlockedAnd(&a2->m_flags, 0xFFDFFFFF);
    vostok::resources::resources_manager::push_generated_resource_to_save(a2, (vostok::threading::mutex *)&a2->m_flags);
  }
  else
  {
    vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this(v3, (int)a2);
  }
}
