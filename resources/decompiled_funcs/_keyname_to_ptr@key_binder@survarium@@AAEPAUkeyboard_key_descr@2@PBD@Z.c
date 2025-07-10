survarium::keyboard_key_descr *__usercall survarium::key_binder::keyname_to_ptr@<eax>(
        const char *_name@<edi>,
        survarium::key_binder *this)
{
  char v2; // bl
  int v3; // esi
  survarium::keyboard_key_descr *v4; // eax
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-24h] BYREF

  v2 = 0;
  v3 = 0;
  if ( survarium::keyboards[0].key_name )
  {
    v4 = survarium::keyboards;
    while ( _stricmp(_name, v4->key_name) )
    {
      v4 = &survarium::keyboards[++v3];
      if ( !v4->key_name )
        goto LABEL_5;
    }
    return &survarium::keyboards[v3];
  }
  else
  {
LABEL_5:
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
    {
      v5 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v5 )
      {
        log_callback.functor.obj_ptr = v5;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v2 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\key_binder.cpp",
        0x159u,
        "struct survarium::keyboard_key_descr *__thiscall survarium::key_binder::keyname_to_ptr(const char *)",
        "game:",
        info,
        "! cant find corresponding [keyboard_key_descr*] for keyname %s",
        _name);
    }
    if ( (v2 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&log_callback.functor, &log_callback.functor, 2);
    }
    return 0;
  }
}
