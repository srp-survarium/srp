void __userpurge vostok::resources::game_resources_manager::tick_memory_type(
        vostok::resources::memory_type *info@<edi>,
        double elapsed_sec@<st0>,
        vostok::resources::game_resources_manager *this)
{
  vostok::threading::mutex *v3; // ebp
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v4; // ecx
  vostok::resources::query_result *m_first; // ebx
  vostok::resources::memory_type::listen_enum listen_type; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  vostok::resources::game_resources_manager_data *v8; // esi
  vostok::fixed_string<512> *v9; // eax
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v10; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  vostok::resources::game_resources_manager_data *v12; // esi
  vostok::fixed_string<512> *v13; // eax
  vostok::resources::game_resources_manager *v14; // [esp+0h] [ebp-248h]
  char v15; // [esp+Ch] [ebp-23Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+10h] [ebp-238h] BYREF
  vostok::resources::sorting_functionality sorting; // [esp+18h] [ebp-230h] BYREF
  vostok::fixed_string<512> v18; // [esp+3Ch] [ebp-20Ch] BYREF

  v15 = 0;
  if ( info->queue.m_first && info->listen_type != listen_freed )
  {
    if ( info == (vostok::resources::memory_type *)-40 )
      v3 = 0;
    else
      v3 = &info->queue.vostok::threading::mutex;
    raii.m_lock = v3;
    vostok::threading::mutex::lock(v3);
    raii.m_locked = 1;
    if ( !info->queue.m_first )
      goto LABEL_7;
    if ( info->listen_type != listen_all
      || (elapsed_sec = vostok::timing::timer::get_elapsed_sec(&info->listen_all_timer), elapsed_sec >= 10.0) )
    {
      sorting.m_sort_actuality_tick = 1;
      sorting.m_data = &this->m_data;
      vostok::resources::sorting_functionality::sort_resources_if_needed(info, &sorting);
      m_first = info->queue.m_first;
      listen_type = info->listen_type;
      info->listen_type = listen_freed;
      if ( vostok::resources::game_resources_manager::try_free_or_decrease_quality(m_first, info, elapsed_sec, this) )
      {
LABEL_7:
        LeaveCriticalSection((LPCRITICAL_SECTION)v3);
        return;
      }
      info->listen_type = listen_type;
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "grm:", info) )
      {
        v8 = (vostok::resources::game_resources_manager_data *)vostok::core::g_log_callback;
        LODWORD(sorting.m_sort_actuality_tick) = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            (const boost::detail::function::function_buffer *)&sorting.m_data,
            (boost::detail::function::function_buffer *)&sorting.m_data,
            destroy_functor_tag);
        if ( v8 )
        {
          sorting.m_data = v8;
          LODWORD(sorting.m_sort_actuality_tick) = (char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                 + 1;
        }
        else
        {
          LODWORD(sorting.m_sort_actuality_tick) = 0;
        }
        v15 = 1;
        v9 = vostok::resources::log_string(m_first, &v18);
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&sorting,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_resman_out_of_memory.cpp",
          0x9Du,
          "void __thiscall vostok::resources::game_resources_manager::tick_memory_type(class vostok::resources::memory_type *)",
          "grm:",
          info,
          "couldn't free anything for %s",
          v9->m_begin);
      }
      if ( (v15 & 1) != 0 )
      {
        v15 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v7,
          (int *)&sorting);
      }
      if ( info->listen_type )
      {
        if ( (info == &vostok::resources::managed_memory || info == &vostok::resources::unmanaged_memory)
          && vostok::resources::game_resources_manager::try_reallocate_queue(info, v14) )
        {
          info->listen_type = listen_none;
          SetEvent(*(HANDLE *)((char *)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable));
          vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
            v10,
            (int)&raii);
          return;
        }
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,600,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(
          (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,600,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v7,
          (int)&info->queue);
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "grm:", info) )
        {
          v12 = (vostok::resources::game_resources_manager_data *)vostok::core::g_log_callback;
          LODWORD(sorting.m_sort_actuality_tick) = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              (const boost::detail::function::function_buffer *)&sorting.m_data,
              (boost::detail::function::function_buffer *)&sorting.m_data,
              destroy_functor_tag);
          if ( v12 )
          {
            sorting.m_data = v12;
            LODWORD(sorting.m_sort_actuality_tick) = (char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                   + 1;
          }
          else
          {
            LODWORD(sorting.m_sort_actuality_tick) = 0;
          }
          v15 |= 2u;
          v13 = vostok::resources::log_string(m_first, &v18);
          vostok::logging::append(
            (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&sorting,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_resman_out_of_memory.cpp",
            0xB0u,
            "void __thiscall vostok::resources::game_resources_manager::tick_memory_type(class vostok::resources::memory_type *)",
            "grm:",
            info,
            "%d sec passed and no deallocation - failing query %s",
            10,
            v13->m_begin);
        }
        if ( (v15 & 2) != 0 )
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            v11,
            (int *)&sorting);
        vostok::resources::query_result::end_query_might_destroy_this(
          (vostok::resources::query_result *)v11,
          (int)m_first);
        if ( !info->queue.m_first )
        {
          info->listen_type = listen_none;
          vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
            (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)v7,
            (int)&raii);
          return;
        }
      }
      info->listen_type = listen_all;
      vostok::timing::timer::start((vostok::timing::timer *)v7, (LARGE_INTEGER *)&info->listen_all_timer);
    }
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v4,
      (int)&raii);
  }
}
