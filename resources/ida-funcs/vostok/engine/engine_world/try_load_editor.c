void __thiscall vostok::engine::engine_world::try_load_editor(vostok::engine::engine_world *this)
{
  HMODULE LibraryA; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool has_passed_filters; // al
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::editor::engine *v6; // eax
  vostok::editor::world *world; // eax
  HWND__ *v8; // eax
  vostok::editor::world *m_editor; // ecx
  HWND__ *v10; // eax
  vostok::editor::world *v11; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp-4h] [ebp-3Ch]
  char v13; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v13 = 0;
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
    vostok::memory::doug_lea_allocator::user_current_thread_id(v5, (int)&this->m_editor_allocator);
    s_memory_allocator(&this->m_editor_allocator);
    s_bugtrap_usage = managed_bugtrap;
    s_error_mode_0 = error_mode_verbose;
    s_error_mode = error_mode_verbose;
    vostok::debug::bugtrap::initialize((const char *)this);
    if ( this )
      v6 = &this->vostok::editor::engine;
    else
      v6 = 0;
    world = s_create_world(v6);
    this->m_editor = world;
    v8 = world->view_handle(world);
    m_editor = this->m_editor;
    this->m_render_window_handle = v8;
    v10 = m_editor->main_handle(m_editor);
    v11 = this->m_editor;
    this->m_main_window_handle = v10;
    v11->load(v11);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw,
                                 (const char *)3),
          v3 = v12,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v3,
        &log_callback);
      v13 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\engine_world_editor.cpp",
        0x33u,
        "void __thiscall vostok::engine::engine_world::try_load_editor(void)",
        (char *)&initiator_raw,
        warning,
        "cannot load library \"%s\"",
        "vostok_editor-static-gold.dll");
    }
    if ( (v13 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&log_callback);
    if ( !s_editor_module )
      vostok::debug::terminate("Cannot load editor library - exiting.\r\nSee log file for details.");
  }
}
