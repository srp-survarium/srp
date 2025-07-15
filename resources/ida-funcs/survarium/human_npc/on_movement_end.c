void __usercall survarium::human_npc::on_movement_end(survarium::human_npc *this@<ecx>, int a2@<edi>)
{
  char v2; // bl
  void (__cdecl *v3)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  __int64 v5; // [esp+10h] [ebp-48h] BYREF
  int v6; // [esp+34h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-20h] BYREF

  v2 = 0;
  v6 = 0;
  if ( *(_DWORD *)(a2 + 640) )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
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
      v2 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\human_npc.cpp",
        0x235u,
        "void __thiscall survarium::human_npc::on_movement_end(void)",
        "game:",
        info,
        "target reached: [%.2f][%.2f][%.2f]",
        **(float **)(a2 + 640),
        *(float *)(*(_DWORD *)(a2 + 640) + 4),
        *(float *)(*(_DWORD *)(a2 + 640) + 8));
    }
    if ( (v2 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&log_callback.functor, &log_callback.functor, 2);
    }
    *(_DWORD *)(a2 + 640) = 0;
    v5 = (unsigned int)(a2 + 340);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v5
    + 1,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v5);
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 324) + 84))(*(_DWORD *)(a2 + 324), HIDWORD(v5));
  }
}
