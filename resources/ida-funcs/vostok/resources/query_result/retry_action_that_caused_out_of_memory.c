bool __thiscall vostok::resources::query_result::retry_action_that_caused_out_of_memory(
        vostok::resources::query_result *this,
        vostok::resources::query_result *thisa)
{
  char v2; // bl
  vostok::resources::out_of_memory_type_enum m_out_of_memory_type; // eax
  vostok::resources::query_result *v4; // ecx
  vostok::resources::query_result *v5; // ecx
  const char *v6; // edi
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  bool v9; // bl
  vostok::resources::allocate_functionality *v11; // [esp+0h] [ebp-248h]
  bool out_finished_create[4]; // [esp+14h] [ebp-234h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-230h] BYREF
  int v14; // [esp+38h] [ebp-210h]
  const char *v15[131]; // [esp+3Ch] [ebp-20Ch] BYREF

  ++thisa->m_out_of_memory_reallocations_count;
  v2 = 0;
  thisa->m_out_of_memory.vostok::resources::query_result_for_cook::type = 0;
  m_out_of_memory_type = thisa->m_out_of_memory_type;
  thisa->m_out_of_memory.size = 0;
  thisa->m_out_of_memory_type = out_of_memory_type_unset;
  v14 = 0;
  thisa->m_error_type = error_type_unset;
  out_finished_create[3] = 1;
  _InterlockedExchangeAdd(&thisa->m_on_created_resource_guard, 1u);
  if ( m_out_of_memory_type == out_of_memory_on_translate_query )
  {
    vostok::threading::interlocked_and(&thisa->m_flags, 0xFFFFBFFF);
    vostok::resources::query_result::translate_query_if_needed(v4);
LABEL_8:
    out_finished_create[3] = thisa->m_out_of_memory_type == out_of_memory_type_unset;
    goto LABEL_9;
  }
  if ( m_out_of_memory_type != out_of_memory_on_create_resource )
  {
    if ( m_out_of_memory_type == out_of_memory_on_allocate_raw_resource )
      vostok::resources::allocate_functionality::prepare_raw_resource(v11, thisa, reallocating_true);
    else
      vostok::resources::query_result::prepare_final_resource(
        (vostok::resources::query_result *)&thisa->m_on_created_resource_guard,
        thisa);
    goto LABEL_8;
  }
  vostok::resources::query_result::do_create_resource(
    (vostok::resources::query_result *)&out_finished_create[3],
    &out_finished_create[3]);
LABEL_9:
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "grm:", info) )
  {
    v6 = "success";
    if ( !out_finished_create[3] )
      v6 = "failed";
    v7 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v7 )
    {
      log_callback.functor.obj_ptr = v7;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v2 = 1;
    if ( (thisa->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
        & 2) != 0 )
      vostok::resources::logging_name_for_query(thisa, (int)v15);
    else
      thisa->log_string(thisa, (vostok::fixed_string<512> *)v15);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\resources_query_result_allocation.cpp",
      0x1EEu,
      "bool __thiscall vostok::resources::query_result::retry_action_that_caused_out_of_memory(void)",
      "grm:",
      info,
      "%s : reallocation: %s",
      v15[0],
      v6);
  }
  if ( (v2 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v8 )
          v8(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  v9 = out_finished_create[3];
  if ( out_finished_create[3] )
    vostok::threading::interlocked_and(&thisa->m_flags, 0xFFBFFFFF);
  vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this(v5);
  return v9;
}
