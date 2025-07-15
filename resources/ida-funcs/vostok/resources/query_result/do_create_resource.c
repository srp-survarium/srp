void __usercall vostok::resources::query_result::do_create_resource(
        vostok::resources::query_result *this@<eax>,
        bool *out_finished_create@<esi>)
{
  volatile int *p_m_query_end_guard; // ebx
  vostok::resources::query_result *v4; // ecx
  vostok::resources::cook_base::result_enum m_create_resource_result; // eax
  vostok::resources::query_result *v6; // ecx
  vostok::resources::query_result *v7; // ecx
  unsigned int v8; // eax
  bool do_debug_break; // [esp+Fh] [ebp-1h] BYREF

  p_m_query_end_guard = &this->m_query_end_guard;
  vostok::resources::query_result::do_create_resource_impl(
    (vostok::resources::query_result *)_InterlockedExchangeAdd(&this->m_query_end_guard, 1u),
    (int)this);
  if ( out_finished_create )
    *out_finished_create = this->m_error_type == error_type_unset;
  if ( this->m_save_generated_data )
  {
    _InterlockedAnd(&this->m_flags, 0xFFDFFFFF);
    _InterlockedExchangeAdd(p_m_query_end_guard, 0xFFFFFFFF);
    vostok::resources::resources_manager::push_generated_resource_to_save(
      this,
      (vostok::threading::mutex *)&this->m_flags);
  }
  else
  {
    m_create_resource_result = this->m_create_resource_result;
    if ( m_create_resource_result == result_need_async
      || m_create_resource_result == (result_cannot_lock|result_success) )
    {
      vostok::resources::query_result::end_query_might_destroy_this(v4, (int)this);
    }
    else
    {
      vostok::resources::query_result::do_create_resource_end_part(
        v4,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this);
      if ( !vostok::resources::query_result::end_query_might_destroy_this(v6, (int)this)
        || debug_macro_helper_ignore_always_31 )
      {
        vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this(v7, (int)this);
      }
      else
      {
        v8 = occurances_left_20;
        if ( occurances_left_20 == -1 )
          v8 = 10;
        occurances_left_20 = v8 - 1;
        if ( v8 )
        {
          do_debug_break = 0;
          vostok::debug::on_error(
            &do_debug_break,
            process_error_false,
            (bool *)"false",
            ".\\resources_query_result_cook.cpp",
            "vostok::resources::query_result::do_create_resource",
            (const char *)0xF5);
          if ( vostok::debug::is_debugger_present() || do_debug_break )
            __debugbreak();
        }
      }
    }
  }
}
