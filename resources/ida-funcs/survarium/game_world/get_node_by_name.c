unsigned int __thiscall survarium::game_world::get_node_by_name(survarium::game_world *this, const char *node_name)
{
  char v2; // bl
  void (__cdecl *v3)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v2 = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
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
      ".\\game_world_npc.cpp",
      0xB7u,
      "unsigned int __thiscall survarium::game_world::get_node_by_name(const char *) const",
      "game:",
      error,
      "node with name %s wasn't found",
      node_name);
  }
  if ( (v2 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v4 )
          v4(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  return -1;
}
