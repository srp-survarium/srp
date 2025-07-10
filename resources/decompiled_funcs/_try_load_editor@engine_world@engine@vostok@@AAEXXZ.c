void __thiscall vostok::engine::engine_world::try_load_editor(vostok::engine::engine_world *this)
{
  char v1; // bl
  HMODULE LibraryA; // eax
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  DWORD CurrentThreadId; // eax
  const char *Value; // eax
  vostok::editor::engine *v8; // eax
  vostok::editor::world *world; // eax
  HWND__ *v10; // eax
  vostok::editor::world *m_editor; // ecx
  HWND__ *v12; // eax
  vostok::editor::world *v13; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v1 = 0;
  CoInitializeEx(0, 2u);
  LibraryA = LoadLibraryA("vostok_editor-static-gold.dll");
  s_editor_module = LibraryA;
  if ( LibraryA )
  {
    s_create_world = (vostok::editor::world *(__cdecl *)(vostok::editor::engine *))GetProcAddress(
                                                                                     LibraryA,
                                                                                     "create_world");
    s_destroy_world = (void (__cdecl *)(vostok::editor::world **))GetProcAddress(s_editor_module, "destroy_world");
    s_memory_allocator = (void (__cdecl *)(vostok::memory::doug_lea_allocator *))GetProcAddress(
                                                                                   s_editor_module,
                                                                                   "set_memory_allocator");
    CurrentThreadId = GetCurrentThreadId();
    if ( this->m_editor_allocator.m_user_thread_id != CurrentThreadId )
    {
      _InterlockedExchange((volatile __int32 *)&this->m_editor_allocator.m_user_thread_id, CurrentThreadId);
      if ( this->m_editor_allocator.m_thread_id_const )
        this->m_editor_allocator.m_user_thread_id_called = 1;
    }
    Value = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
    if ( !Value )
      Value = "undefined";
    this->m_editor_allocator.m_user_thread_logging_name = Value;
    s_memory_allocator(&this->m_editor_allocator);
    vostok::debug::change_bugtrap_usage(error_mode_verbose, managed_bugtrap);
    if ( this )
      v8 = &this->vostok::editor::engine;
    else
      v8 = 0;
    world = s_create_world(v8);
    this->m_editor = world;
    v10 = world->view_handle(world);
    m_editor = this->m_editor;
    this->m_render_window_handle = v10;
    v12 = m_editor->main_handle(m_editor);
    v13 = this->m_editor;
    this->m_main_window_handle = v12;
    v13->load(v13);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "engine:", warning) )
    {
      v4 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v4 )
      {
        log_callback.functor.obj_ptr = v4;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v1 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\engine_world_editor.cpp",
        0x33u,
        "void __thiscall vostok::engine::engine_world::try_load_editor(void)",
        "engine:",
        warning,
        "cannot load library \"%s\"",
        "vostok_editor-static-gold.dll");
    }
    if ( (v1 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v5 )
            v5(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
    if ( !s_editor_module )
      vostok::debug::terminate("Cannot load editor library - exiting.\r\nSee log file for details.");
  }
}
