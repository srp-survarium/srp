void __thiscall survarium::human_npc::on_affect_event(
        survarium::human_npc *this,
        const char *body_part_name,
        survarium::hit_affects_type_enum affect_type,
        survarium::affect_event_type_enum event_type)
{
  char v4; // bl
  const char *v5; // edi
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  const char *v7; // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v9; // [esp-8h] [ebp-40h]
  const char *v10; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v4 = 0;
  v5 = "applied";
  if ( event_type )
    v5 = "recalled";
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
  {
    v6 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v6 )
    {
      log_callback.functor.obj_ptr = v6;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v4 = 1;
    v7 = (const char *)((int (__thiscall *)(vostok::ai::game_object *, const char *, const char *))this->get_name)(
                         &this->vostok::ai::game_object,
                         v5,
                         body_part_name);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\human_npc.cpp",
      0x268u,
      "void __thiscall survarium::human_npc::on_affect_event(const char *,const enum survarium::hit_affects_type_enum,con"
      "st enum survarium::affect_event_type_enum) const",
      "game:",
      info,
      "[%s] - death affect %s on body part %s",
      v7,
      v9,
      v10);
  }
  if ( (v4 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v8 )
      v8(&log_callback.functor, &log_callback.functor, 2);
  }
}
