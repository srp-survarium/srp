int __usercall mem_usage@<eax>(void *heap_handle@<eax>)
{
  char v1; // bl
  int v3; // edi
  int i; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v10; // ecx
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  _heapinfo hinfo; // [esp+14h] [ebp-6Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-60h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+40h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v15; // [esp+60h] [ebp-20h] BYREF

  v1 = 0;
  if ( vostok::debug::is_debugger_present() )
  {
    if ( s_no_memory_usage_stats.m_type == type_unset )
    {
      s_no_memory_usage_stats.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_memory_usage_stats.m_type == type_recursive )
    {
      hinfo._pentry = 0;
      v3 = 0;
      for ( i = heap_walk(heap_handle, &hinfo); i == -2; i = heap_walk(heap_handle, &hinfo) )
      {
        if ( hinfo._useflag == 1 )
          v3 += hinfo._size;
      }
      switch ( i )
      {
        case -6:
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", warning) )
          {
            v11 = vostok::core::g_log_callback;
            v15.vtable = 0;
            if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
              `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                &v15.functor,
                &v15.functor,
                destroy_functor_tag);
            if ( v11 )
            {
              v15.functor.obj_ptr = v11;
              v15.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                  + 1);
            }
            else
            {
              v15.vtable = 0;
            }
            v1 = 1;
            vostok::logging::append(
              &v15,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\memory_crt_allocator_win.cpp",
              0x91u,
              "unsigned int __cdecl mem_usage(void *,unsigned int *,unsigned int *)",
              "core:",
              warning,
              "bad pointer to heap");
          }
          if ( (v1 & 1) != 0 )
            boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
              v10,
              (int *)&v15);
          break;
        case -4:
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", warning) )
          {
            v9 = vostok::core::g_log_callback;
            v14.vtable = 0;
            if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
              `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                &v14.functor,
                &v14.functor,
                destroy_functor_tag);
            if ( v9 )
            {
              v14.functor.obj_ptr = v9;
              v14.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                  + 1);
            }
            else
            {
              v14.vtable = 0;
            }
            v1 = 4;
            vostok::logging::append(
              &v14,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\memory_crt_allocator_win.cpp",
              0x98u,
              "unsigned int __cdecl mem_usage(void *,unsigned int *,unsigned int *)",
              "core:",
              warning,
              "bad node in heap");
          }
          if ( (v1 & 4) != 0 )
          {
            boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
              v8,
              (int *)&v14);
            return 0;
          }
          break;
        case -3:
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", warning) )
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
            v1 = 2;
            vostok::logging::append(
              &log_callback,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\memory_crt_allocator_win.cpp",
              0x95u,
              "unsigned int __cdecl mem_usage(void *,unsigned int *,unsigned int *)",
              "core:",
              warning,
              "bad start of heap");
          }
          if ( (v1 & 2) != 0 )
          {
            boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
              v6,
              (int *)&log_callback);
            return 0;
          }
          break;
        default:
          return v3;
      }
    }
  }
  return 0;
}
