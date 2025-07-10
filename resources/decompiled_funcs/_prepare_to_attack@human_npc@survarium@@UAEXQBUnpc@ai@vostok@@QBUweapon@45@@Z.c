void __thiscall survarium::human_npc::prepare_to_attack(
        survarium::human_npc *this,
        const vostok::ai::npc *const target,
        const vostok::ai::weapon *const gun)
{
  survarium::human_npc *v3; // ebx
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  int (__thiscall ***v5)(_DWORD); // esi
  const vostok::ai::game_object *v6; // edi
  int v7; // eax
  int v8; // eax
  const char *v9; // eax
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v11; // [esp-8h] [ebp-40h]
  const char *v12; // [esp-4h] [ebp-3Ch]
  char v13; // [esp+10h] [ebp-28h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v3 = this;
  v13 = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
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
    v13 = 1;
    v5 = (int (__thiscall ***)(_DWORD))gun->cast_game_object(gun);
    v6 = target->cast_game_object(target);
    v7 = (**v5)(v5);
    v8 = ((int (__thiscall *)(const vostok::ai::game_object *, int))v6->get_name)(v6, v7);
    v9 = (const char *)((int (__thiscall *)(vostok::ai::game_object *, int))v3->get_name)(
                         &v3->vostok::ai::game_object,
                         v8);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\human_npc.cpp",
      0x184u,
      "void __thiscall survarium::human_npc::prepare_to_attack(const struct vostok::ai::npc *const ,const struct vostok::"
      "ai::weapon *const )",
      "game:",
      info,
      "%s: prepare to attack %s with %s",
      v9,
      v11,
      v12);
    v3 = this;
  }
  if ( (v13 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v10 )
          v10(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  v3->m_current_target = target;
  v3->m_current_weapon = gun;
}
