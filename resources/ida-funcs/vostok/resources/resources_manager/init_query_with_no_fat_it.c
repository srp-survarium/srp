void __thiscall vostok::resources::resources_manager::init_query_with_no_fat_it(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *query,
        vostok::resources::query_result *querya)
{
  char v3; // bl
  vostok::resources::cook_base *cook; // eax
  vostok::resources::query_result *v5; // ecx
  int v6; // ecx
  vostok::resources::cook_base *v7; // eax
  _DWORD *v8; // edi
  const char *requested_path; // eax
  const char *v10; // edx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  void (__cdecl *v12)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v13; // ecx
  void (__cdecl *v14)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  int v15; // esi
  vostok::fixed_string<512> *v16; // eax
  vostok::resources::allocate_functionality *v17; // ecx
  vostok::resources::allocate_functionality *v18; // [esp+0h] [ebp-474h]
  _RTL_CRITICAL_SECTION *raii; // [esp+10h] [ebp-464h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v20; // [esp+18h] [ebp-45Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-43Ch] BYREF
  const char *v22[131]; // [esp+58h] [ebp-41Ch] BYREF
  vostok::fixed_string<512> v23; // [esp+264h] [ebp-210h] BYREF

  v3 = 0;
  cook = vostok::resources::resources_manager::find_cook((int)this, querya->m_class_id);
  if ( cook
    && vostok::resources::cook_base::does_create_resource_if_no_file(cook)
    && querya->m_create_resource_result != result_requery )
  {
    raii = (_RTL_CRITICAL_SECTION *)&byte_201E8[(_DWORD)query];
    vostok::threading::mutex::lock((vostok::threading::mutex *)&byte_201E8[(_DWORD)query]);
    v7 = vostok::resources::resources_manager::find_cook(v6, querya->m_class_id);
    if ( (!v7 || v7->m_reuse_type)
      && (v8 = *(_DWORD **)((char *)&query->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_201DA + 2)) != 0 )
    {
      while ( 1 )
      {
        requested_path = vostok::resources::query_result_for_user::get_requested_path(querya);
        if ( !strcmp(requested_path, v10) )
          break;
        v8 = (_DWORD *)v8[153];
        if ( !v8 )
          goto LABEL_9;
      }
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:manager:", info) )
      {
        v14 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v14 )
        {
          log_callback.functor.obj_ptr = v14;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v15 = v8[8];
        v3 = 1;
        v16 = vostok::resources::log_string(querya, &v23);
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resources_manager_new_queries.cpp",
          0x34u,
          "void __thiscall vostok::resources::resources_manager::init_query_with_no_fat_it(class vostok::resources::query_result &)",
          "resources:manager:",
          info,
          "no fat_it query %s added as refering to [quid %d]",
          v16->m_begin,
          v15);
      }
      if ( (v3 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v13,
          (int *)&log_callback);
      vostok::resources::query_result::free_unmanaged_buffer((vostok::resources::query_result *)v13, (int)querya);
      vostok::threading::interlocked_or(&querya->m_flags, 0xC0u);
      querya->m_next_referer = (vostok::resources::query_result *)v8[155];
      v8[155] = querya;
      LeaveCriticalSection(raii);
    }
    else
    {
LABEL_9:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:manager:", info) )
      {
        v12 = vostok::core::g_log_callback;
        v20.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v20.functor,
            &v20.functor,
            destroy_functor_tag);
        if ( v12 )
        {
          v20.functor.obj_ptr = v12;
          v20.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v20.vtable = 0;
        }
        v3 = 2;
        if ( (querya->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
            & 2) != 0 )
          vostok::resources::logging_name_for_query(querya, (int)v22);
        else
          querya->log_string(querya, (vostok::fixed_string<512> *)v22);
        vostok::logging::append(
          &v20,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resources_manager_new_queries.cpp",
          0x3Cu,
          "void __thiscall vostok::resources::resources_manager::init_query_with_no_fat_it(class vostok::resources::query_result &)",
          "resources:manager:",
          info,
          "no fat_it query '%s' added for generate_if_no_file cook",
          v22[0]);
      }
      if ( (v3 & 2) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v11,
          (int *)&v20);
      querya->m_error_type = error_type_file_not_found;
      vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::push_back(
        (vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *)((char *)query + (_DWORD)&loc_201D7 + 1),
        querya);
      vostok::threading::interlocked_or(&querya->m_flags, 0x20u);
      vostok::resources::allocate_functionality::prepare_raw_resource(querya, 0, v17, v18);
      LeaveCriticalSection(raii);
    }
  }
  else
  {
    querya->m_error_type = error_type_file_not_found;
    if ( !_InterlockedExchangeAdd(&querya->m_query_end_guard, 0xFFFFFFFF) )
      vostok::resources::query_result::end_query_might_destroy_this_impl(v5, querya);
  }
}
