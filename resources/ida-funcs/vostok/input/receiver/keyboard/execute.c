void __usercall vostok::input::receiver::keyboard::execute(
        vostok::input::receiver::keyboard *this@<ecx>,
        _DWORD *a2@<eax>)
{
  char v3; // bl
  int v4; // eax
  int v5; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v10)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  int v12; // esi
  void (__cdecl *v13)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  unsigned int v14; // eax
  unsigned int v15; // ecx
  _DWORD *v16; // eax
  unsigned int events_count; // [esp+2Ch] [ebp-28h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+30h] [ebp-24h] BYREF

  v3 = 0;
  events_count = 0;
  v4 = a2[579];
  events_count = 64;
  v5 = (*(int (__stdcall **)(int, int, _DWORD *, unsigned int *, _DWORD))(*(_DWORD *)v4 + 40))(
         v4,
         20,
         a2 + 258,
         &events_count,
         0);
  if ( v5 < 0 )
  {
    if ( v5 == -2147024866 )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "input:", error) )
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
        v3 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\receiver_keyboard_win.cpp",
          0x63u,
          "void __thiscall vostok::input::receiver::keyboard::execute(void)",
          "input:",
          error,
          "DIERR_INPUTLOST");
      }
      if ( (v3 & 1) != 0 )
      {
        v3 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v6,
          (int *)&log_callback);
      }
      goto LABEL_48;
    }
    if ( v5 == -2147024809 )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "input:", error) )
      {
        v9 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          log_callback.functor.obj_ptr = v9;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v3 = 2;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\receiver_keyboard_win.cpp",
          0x67u,
          "void __thiscall vostok::input::receiver::keyboard::execute(void)",
          "input:",
          error,
          "DIERR_INVALIDPARAM");
      }
      if ( (v3 & 2) != 0 )
        goto LABEL_59;
      return;
    }
    if ( v5 != -2147024884 )
    {
      if ( v5 == -2147024875 )
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "input:", error) )
        {
          v10 = vostok::core::g_log_callback;
          log_callback.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &log_callback.functor,
              &log_callback.functor,
              destroy_functor_tag);
          if ( v10 )
          {
            log_callback.functor.obj_ptr = v10;
            log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                         + 1);
          }
          else
          {
            log_callback.vtable = 0;
          }
          v3 = 4;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\receiver_keyboard_win.cpp",
            0x6Fu,
            "void __thiscall vostok::input::receiver::keyboard::execute(void)",
            "input:",
            error,
            "DIERR_NOTINITIALIZED");
        }
        if ( (v3 & 4) != 0 )
          goto LABEL_59;
        return;
      }
      if ( v5 == -2147483638 )
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "input:", error) )
        {
          v11 = vostok::core::g_log_callback;
          log_callback.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &log_callback.functor,
              &log_callback.functor,
              destroy_functor_tag);
          if ( v11 )
          {
            log_callback.functor.obj_ptr = v11;
            log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                         + 1);
          }
          else
          {
            log_callback.vtable = 0;
          }
          v3 = 8;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\receiver_keyboard_win.cpp",
            0x73u,
            "void __thiscall vostok::input::receiver::keyboard::execute(void)",
            "input:",
            error,
            "E_PENDING");
        }
        if ( (v3 & 8) != 0 )
          goto LABEL_59;
        return;
      }
    }
  }
  if ( v5 != -2147024884 )
  {
    if ( v5 < 0 )
      return;
    goto LABEL_61;
  }
LABEL_48:
  v12 = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)a2[579] + 28))(a2[579]);
  memset((int)(a2 + 1), 0, 0x400u);
  if ( v12 < 0 )
    return;
  if ( (*(int (__stdcall **)(_DWORD, int, _DWORD *, unsigned int *, _DWORD))(*(_DWORD *)a2[579] + 40))(
         a2[579],
         20,
         a2 + 258,
         &events_count,
         0) >= 0 )
  {
LABEL_61:
    v14 = events_count;
    v15 = 0;
    a2[257] = events_count;
    if ( v14 )
    {
      v16 = a2 + 258;
      do
      {
        ++v15;
        a2[*v16 + 1] = v16[1] & 0x80;
        v16 += 5;
      }
      while ( v15 < a2[257] );
    }
    return;
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "input:", error) )
  {
    v13 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v13 )
    {
      log_callback.functor.obj_ptr = v13;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v3 |= 0x10u;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\receiver_keyboard_win.cpp",
      0x88u,
      "void __thiscall vostok::input::receiver::keyboard::execute(void)",
      "input:",
      error,
      "can't get mouse keyboard");
  }
  if ( (v3 & 0x10) != 0 )
LABEL_59:
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v8,
      (int *)&log_callback);
}
