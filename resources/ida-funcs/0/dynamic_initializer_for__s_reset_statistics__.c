int dynamic_initializer_for__s_reset_statistics__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function4<void,unsigned int,float,float,char const *> v2; // [esp+8h] [ebp-20h] BYREF

  v2.vtable = 0;
  if ( `boost::function1<void,char const *>::assign_to<void (__cdecl *)(char const *)>'::`2'::stored_vtable )
    `boost::function1<void,char const *>::assign_to<void (__cdecl *)(char const *)>'::`2'::stored_vtable(
      &v2.functor,
      &v2.functor,
      destroy_functor_tag);
  if ( reset_physics_profiler )
  {
    v2.functor.obj_ptr = reset_physics_profiler;
    v2.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,char const *>::assign_to<void (__cdecl *)(char const *)>'::`2'::stored_vtable
                                                       + 1);
  }
  else
  {
    v2.vtable = 0;
  }
  s_reset_statistics.m_next = 0;
  s_reset_statistics.m_prev = vostok::console_commands::s_console_command_root;
  s_reset_statistics.m_name = "reset_physics_profiler";
  s_reset_statistics.m_command_type = command_type_engine_internal;
  s_reset_statistics.m_execution_type = execution_filter_general;
  s_reset_statistics.m_need_args = 0;
  s_reset_statistics.m_serializable = 1;
  s_reset_statistics.m_on_change_event.vtable = 0;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_reset_statistics;
  vostok::console_commands::s_console_command_root = &s_reset_statistics;
  s_reset_statistics.__vftable = (vostok::console_commands::cc_delegate_vtbl *)&stru_95AF78.m_key_bindings[40];
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    &v2,
    (int)&s_reset_statistics.m_functor);
  s_reset_statistics.m_need_args = 0;
  if ( v2.vtable )
  {
    if ( ((int)v2.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v2.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&v2.functor, &v2.functor, 2);
    }
  }
  return atexit(dynamic_atexit_destructor_for__s_reset_statistics__);
}
