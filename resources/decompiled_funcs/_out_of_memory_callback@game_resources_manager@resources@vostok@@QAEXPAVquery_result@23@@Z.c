void __thiscall vostok::resources::game_resources_manager::out_of_memory_callback(
        vostok::resources::game_resources_manager *this,
        vostok::resources::query_result *query)
{
  void (__cdecl *v2)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  unsigned int size; // edx
  char *m_begin; // edi
  volatile int m_flags; // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const vostok::resources::memory_type *type; // edi
  bool v8; // zf
  vostok::intrusive_list<vostok::resources::unmanaged_resource_buffer,vostok::resources::unmanaged_resource_buffer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v9; // ecx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,600,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v10; // ecx
  bool *v11; // [esp+10h] [ebp-480h]
  char lpCriticalSection; // [esp+44h] [ebp-44Ch]
  _RTL_CRITICAL_SECTION *lpCriticalSectiona; // [esp+44h] [ebp-44Ch]
  vostok::resources::memory_usage_type required_memory; // [esp+48h] [ebp-448h] BYREF
  vostok::resources::game_resources_manager *v15; // [esp+50h] [ebp-440h]
  float m_target_satisfaction; // [esp+54h] [ebp-43Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+58h] [ebp-438h] BYREF
  const char *v18[131]; // [esp+78h] [ebp-418h] BYREF
  vostok::buffer_string v19[43]; // [esp+284h] [ebp-20Ch] BYREF

  v15 = this;
  lpCriticalSection = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "grm:", info) )
  {
    v2 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v2 )
    {
      log_callback.functor.obj_ptr = v2;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    size = query->m_out_of_memory.size;
    required_memory.type = query->m_out_of_memory.vostok::resources::query_result_for_cook::type;
    lpCriticalSection = 1;
    required_memory.size = size;
    m_begin = vostok::resources::memory_usage_type::log_string(&required_memory, v19)->m_begin;
    m_flags = query->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    m_target_satisfaction = query->m_target_satisfaction;
    if ( (m_flags & 2) != 0 )
      vostok::resources::logging_name_for_query(query, (int)v18);
    else
      query->log_string(query, (vostok::fixed_string<512> *)v18);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\game_resman_out_of_memory.cpp",
      0x61u,
      "void __thiscall vostok::resources::game_resources_manager::out_of_memory_callback(class vostok::resources::query_result *)",
      "grm:",
      info,
      "%s : out of memory (query satisfaction: %0.2f) [needed: %s]",
      v18[0],
      m_target_satisfaction,
      m_begin);
  }
  if ( (lpCriticalSection & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v6 )
          v6(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  if ( ((unsigned int)Scaleform::GFx::AS2::CreateShadow & query->m_flags) == 0 )
  {
    type = query->m_out_of_memory.vostok::resources::query_result_for_cook::type;
    v8 = !type->in_list;
    v9 = (vostok::intrusive_list<vostok::resources::unmanaged_resource_buffer,vostok::resources::unmanaged_resource_buffer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)query->m_out_of_memory.size;
    required_memory.size = (unsigned int)v9;
    if ( v8 )
    {
      vostok::intrusive_list<vostok::resources::memory_type,vostok::resources::memory_type *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        v9,
        (int)&v15->m_data.memory_types,
        (vostok::resources::unmanaged_resource_buffer *)type,
        v11);
      type->in_list = 1;
    }
    vostok::threading::interlocked_or(&query->m_flags, (unsigned int)Scaleform::GFx::AS2::CreateShadow);
    if ( type == (const vostok::resources::memory_type *)-40 )
    {
      lpCriticalSectiona = 0;
      vostok::threading::mutex::lock(0);
    }
    else
    {
      lpCriticalSectiona = (_RTL_CRITICAL_SECTION *)&type->queue.vostok::threading::mutex;
      vostok::threading::mutex::lock(&type->queue.vostok::threading::mutex);
    }
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,600,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v10,
      &type->queue.m_size,
      query,
      v11);
    type->listen_type = listen_none;
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable));
    LeaveCriticalSection(lpCriticalSectiona);
  }
}
