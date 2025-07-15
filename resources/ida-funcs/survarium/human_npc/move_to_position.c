void __thiscall survarium::human_npc::move_to_position(
        survarium::human_npc *this,
        const vostok::ai::movement_target *const target)
{
  char v3; // bl
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  const vostok::ai::movement_target *m_current_movement_target; // eax
  const char *v6; // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  double v8; // [esp+0h] [ebp-58h]
  double v9; // [esp+8h] [ebp-50h]
  double v10; // [esp+10h] [ebp-48h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-20h] BYREF

  this->m_current_movement_target = target;
  v3 = 0;
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
    m_current_movement_target = this->m_current_movement_target;
    v3 = 1;
    v6 = (const char *)((int (__thiscall *)(vostok::ai::game_object *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->get_name)(
                         &this->vostok::ai::game_object,
                         COERCE_UNSIGNED_INT64(m_current_movement_target->target_position.x),
                         HIDWORD(COERCE_UNSIGNED_INT64(m_current_movement_target->target_position.x)),
                         COERCE_UNSIGNED_INT64(m_current_movement_target->target_position.y),
                         HIDWORD(COERCE_UNSIGNED_INT64(m_current_movement_target->target_position.y)),
                         COERCE_UNSIGNED_INT64(m_current_movement_target->target_position.z),
                         HIDWORD(COERCE_UNSIGNED_INT64(m_current_movement_target->target_position.z)));
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\human_npc.cpp",
      0x1FDu,
      "void __thiscall survarium::human_npc::move_to_position(const struct vostok::ai::movement_target *const )",
      "game:",
      info,
      "%s: trying to move to point %.2f %.2f %.2f",
      v6,
      v8,
      v9,
      v10);
  }
  if ( (v3 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v7 )
          v7(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  survarium::animations_selector::set_target(this->m_animations_selector, this->m_current_movement_target);
}
