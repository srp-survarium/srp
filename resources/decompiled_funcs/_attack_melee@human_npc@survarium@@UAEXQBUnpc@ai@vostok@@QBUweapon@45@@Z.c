void __thiscall survarium::human_npc::attack_melee(
        survarium::human_npc *this,
        const vostok::ai::npc *const target,
        const vostok::ai::weapon *const gun)
{
  char v3; // bl
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  const vostok::ai::game_object *v6; // edi
  const vostok::ai::game_object *v7; // ebp
  int v8; // eax
  int v9; // eax
  const char *v10; // eax
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v12; // [esp-8h] [ebp-40h]
  const char *v13; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v3 = 0;
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
    v3 = 1;
    v6 = this->m_current_weapon->cast_game_object(this->m_current_weapon);
    v7 = this->m_current_target->cast_game_object(this->m_current_target);
    v8 = v6->get_name((vostok::ai::game_object *)v6);
    v9 = ((int (__thiscall *)(const vostok::ai::game_object *, int))v7->get_name)(v7, v8);
    v10 = (const char *)((int (__thiscall *)(vostok::ai::game_object *, int))this->get_name)(
                          &this->vostok::ai::game_object,
                          v9);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\human_npc.cpp",
      0x192u,
      "void __thiscall survarium::human_npc::attack_melee(const struct vostok::ai::npc *const ,const struct vostok::ai::weapon *const )",
      "game:",
      info,
      "%s: melee attacking %s with %s",
      v10,
      v12,
      v13);
  }
  if ( (v3 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v11 )
      v11(&log_callback.functor, &log_callback.functor, 2);
  }
}
