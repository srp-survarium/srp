void __thiscall survarium::human_npc::on_animation_end(
        survarium::human_npc *this,
        const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *thisa)
{
  void (__cdecl *v2)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::configs::binary_config *m_object; // edx
  vostok::configs::binary_config_vtbl *v4; // eax
  const char *v5; // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v7[72]; // [esp-114h] [ebp-144h] BYREF
  int v8; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v8 = 0;
  if ( thisa[159].m_object )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
    {
      v2 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v2 )
      {
        log_callback.functor.obj_ptr = v2;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      m_object = thisa[1].m_object;
      qmemcpy(v7, &thisa[159].m_object->type, 0x114u);
      v4 = m_object->__vftable;
      v8 = 1;
      v5 = (const char *)((int (__thiscall *)(const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *))v4)(&thisa[1]);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\human_npc.cpp",
        0x208u,
        "void __thiscall survarium::human_npc::on_animation_end(void)",
        "game:",
        info,
        "%s: stop playing animation %s",
        v5,
        v7[0]);
    }
    if ( (v8 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v6 )
        v6(&log_callback.functor, &log_callback.functor, 2);
    }
    v7[68] = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v7[68],
      thisa + 85);
    ((void (__thiscall *)(vostok::configs::binary_config *, vostok::configs::binary_config *, const char *))thisa[81].m_object->__vftable[2].is_increasing_quality)(
      thisa[81].m_object,
      thisa[159].m_object,
      v7[68]);
    thisa[159].m_object = 0;
    v7[68] = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v7[68],
      thisa + 85);
    ((void (__thiscall *)(vostok::configs::binary_config *, const char *))thisa[81].m_object->__vftable[3].~vostok::resources::resource_base)(
      thisa[81].m_object,
      v7[68]);
  }
}
