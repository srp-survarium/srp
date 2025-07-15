void __usercall vostok::input::receiver::mouse::execute(vostok::input::receiver::mouse *this@<ecx>, int a2@<eax>)
{
  vostok::input::mouse::state *v3; // edi
  char v4; // bl
  int v5; // eax
  int v6; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  _DIMOUSESTATE2 state; // [esp+10h] [ebp-38h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+24h] [ebp-24h] BYREF

  v3 = (vostok::input::mouse::state *)(a2 + 4);
  *(_QWORD *)(a2 + 20) = *(_QWORD *)(a2 + 4);
  *(_QWORD *)(a2 + 28) = *(_QWORD *)(a2 + 12);
  v4 = 0;
  v5 = (*(int (__stdcall **)(_DWORD, int, _DIMOUSESTATE2 *))(**(_DWORD **)(a2 + 40) + 36))(
         *(_DWORD *)(a2 + 40),
         20,
         &state);
  if ( v5 >= 0 )
    goto LABEL_2;
  if ( (v5 == -2147024884 || v5 == -2147024866)
    && (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(a2 + 40) + 28))(*(_DWORD *)(a2 + 40)) >= 0 )
  {
    v6 = (*(int (__stdcall **)(_DWORD, int, _DIMOUSESTATE2 *))(**(_DWORD **)(a2 + 40) + 36))(
           *(_DWORD *)(a2 + 40),
           20,
           &state);
    if ( v6 >= 0 )
    {
LABEL_2:
      fill_state(v3, &state);
      return;
    }
    if ( v6 == -2147024884 || v6 == -2147024866 )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "input:", info) )
      {
        v8 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v8 )
        {
          log_callback.functor.obj_ptr = v8;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v4 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\receiver_mouse_win.cpp",
          0x6Fu,
          "void __thiscall vostok::input::receiver::mouse::execute(void)",
          "input:",
          info,
          "mouse device is lost");
      }
      if ( (v4 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v7,
          (int *)&log_callback);
    }
  }
}
