char __cdecl vostok::core::initialize_console()
{
  char v0; // bl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  void (__cdecl *v3)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  HANDLE StdHandle; // eax
  int v5; // eax
  _iobuf *v6; // eax
  HANDLE v7; // eax
  int v8; // eax
  _iobuf *v9; // eax
  HANDLE v10; // eax
  int v11; // eax
  _iobuf *v12; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v0 = 0;
  if ( s_tried_to_initialize_console )
    return s_console_initialized;
  s_tried_to_initialize_console = 1;
  if ( GetConsoleWindow() )
    goto LABEL_22;
  if ( AttachConsole(0xFFFFFFFF) || AllocConsole() )
  {
    StdHandle = GetStdHandle(0xFFFFFFF6);
    v5 = _open_osfhandle(StdHandle, 0x4000);
    if ( v5 != -1 )
    {
      log_callback = *(boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)_fdopen(v5, "rt");
      __iob_func()[2] = (_iobuf)log_callback;
      v6 = __iob_func();
      setvbuf(v6, 0, 4, 0);
    }
    v7 = GetStdHandle(0xFFFFFFF5);
    v8 = _open_osfhandle(v7, 0x4000);
    log_callback = *(boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)_fdopen(v8, "wt");
    __iob_func()[1] = (_iobuf)log_callback;
    v9 = __iob_func();
    setvbuf(v9 + 1, 0, 4, 0);
    v10 = GetStdHandle(0xFFFFFFF4);
    v11 = _open_osfhandle(v10, 0x4000);
    if ( v11 != -1 )
    {
      log_callback = *(boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)_fdopen(v11, "wt");
      __iob_func()[2] = (_iobuf)log_callback;
      v12 = __iob_func();
      setvbuf(v12 + 2, 0, 4, 0);
    }
    stlp_std::ios_base::sync_with_stdio(1);
LABEL_22:
    s_console_initialized = 1;
    return 1;
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", warning) )
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
    v0 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\logging_extensions.cpp",
      0x12Du,
      "bool __cdecl vostok::core::initialize_console(void)",
      "core:",
      warning,
      "cannot neither attach parent console, nor create new");
  }
  if ( (v0 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v2,
      (int *)&log_callback);
  s_console_initialized = 0;
  return 0;
}
