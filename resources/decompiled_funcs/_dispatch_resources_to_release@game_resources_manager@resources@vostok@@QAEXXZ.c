void __thiscall vostok::resources::game_resources_manager::dispatch_resources_to_release(
        vostok::resources::game_resources_manager *this,
        vostok::resources::game_resources_manager *thisa)
{
  vostok::resources::query_result *m_first; // edi
  vostok::resources::query_result *v3; // ebx
  vostok::resources::query_result *m_next_for_query_finished_callback; // edi
  vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *p_m_flags; // esi
  _DWORD *p_m_object; // eax
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int v9; // [esp+Ch] [ebp-23Ch]
  vostok::resources::resource_base *next; // [esp+10h] [ebp-238h]
  vostok::resources::releasing_functionality v11; // [esp+14h] [ebp-234h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-230h] BYREF
  const char *v13[131]; // [esp+3Ch] [ebp-20Ch] BYREF

  v9 = 0;
  if ( thisa->m_resources_to_release.m_first )
  {
    vostok::threading::mutex::lock(&thisa->m_resources_to_release.vostok::threading::mutex);
    m_first = (vostok::resources::query_result *)thisa->m_resources_to_release.m_first;
    thisa->m_resources_to_release.m_first = 0;
    thisa->m_resources_to_release.m_last = 0;
    thisa->m_resources_to_release.m_size = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&thisa->m_resources_to_release.vostok::threading::mutex);
    v3 = m_first;
    if ( m_first )
    {
      do
      {
        m_next_for_query_finished_callback = (vostok::resources::query_result *)v3->m_next_for_query_finished_callback;
        p_m_flags = &v3->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
        next = m_next_for_query_finished_callback;
        vostok::threading::interlocked_and(
          &v3->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
          0xFFFFFBFF);
        if ( (v3->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
            & 1) != 0 )
        {
          p_m_object = &v3->m_unmanaged_resource.m_object;
        }
        else if ( (p_m_flags->m_flags & 4) != 0 )
        {
          p_m_object = &v3->m_creation_data_from_user.m_data;
        }
        else
        {
          p_m_object = 0;
        }
        if ( (p_m_object[1] & 1) != 0 )
        {
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", info) )
          {
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
            v9 |= 1u;
            if ( (p_m_flags->m_flags & 2) != 0 )
              vostok::resources::logging_name_for_query(v3, (int)v13);
            else
              v3->log_string(v3, (vostok::fixed_string<512> *)v13);
            vostok::logging::append(
              &log_callback,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\game_resman.cpp",
              0xDDu,
              "void __thiscall vostok::resources::game_resources_manager::dispatch_resources_to_release(void)",
              "core:",
              info,
              "releasing resource from game resources manager: %s",
              v13[0]);
          }
          if ( (v9 & 1) != 0 )
          {
            v9 &= ~1u;
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
          v11.m_data = &thisa->m_data;
          vostok::resources::releasing_functionality::release_resource(&v11, v3);
          v3 = (vostok::resources::query_result *)next;
          m_next_for_query_finished_callback = (vostok::resources::query_result *)next;
        }
        else
        {
          v3 = m_next_for_query_finished_callback;
        }
      }
      while ( m_next_for_query_finished_callback );
    }
  }
}
