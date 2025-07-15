void __usercall vostok::resources::query_result::requery_on_out_of_memory(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result *a2@<esi>)
{
  char v2; // bl
  void (__cdecl *v3)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  const char **v4; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-234h] BYREF
  int v7; // [esp+30h] [ebp-214h]
  vostok::fixed_string<512> v8; // [esp+34h] [ebp-210h] BYREF

  v2 = 0;
  v7 = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "grm:", info) )
  {
    v3 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v3 )
    {
      log_callback.functor.obj_ptr = v3;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v2 = 1;
    v4 = (const char **)a2->log_string(a2, &v8);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\resources_query_result_requery.cpp",
      0x16u,
      "void __thiscall vostok::resources::query_result::requery_on_out_of_memory(void)",
      "grm:",
      info,
      "requerying out of memory query: %s",
      *v4);
  }
  if ( (v2 & 1) != 0 && log_callback.vtable )
  {
    if ( ((int)log_callback.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&log_callback.functor, &log_callback.functor, 2);
    }
    log_callback.vtable = 0;
  }
  a2->m_error_type = error_type_unset;
  _InterlockedExchange(&a2->m_on_created_resource_guard, 1);
  vostok::threading::interlocked_and(&a2->m_flags, 0xFFFFBEFF);
  a2->m_out_of_memory_sub_queries = 0;
  _InterlockedExchange(&a2->m_query_end_guard, 1);
  vostok::resources::resources_manager::push_new_query(vostok::resources::g_resources_manager.m_variable, a2);
}
