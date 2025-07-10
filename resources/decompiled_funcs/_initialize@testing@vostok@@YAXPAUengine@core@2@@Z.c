void __thiscall vostok::testing::initialize(vostok::command_line::key *this)
{
  void (__cdecl *v1)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::threading *v2; // [esp+0h] [ebp-2Ch]
  void **predicate; // [esp+4h] [ebp-28h]
  boost::function<void __cdecl(void)> function_to_call; // [esp+8h] [ebp-24h] BYREF

  s_environment.engine = s_engine_0;
  if ( vostok::testing::run_tests_command_line(this) )
  {
    if ( vostok::testing::s_no_test_watch.m_type == type_unset )
    {
      LOBYTE(predicate) = 0;
      vostok::testing::s_no_test_watch.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( vostok::testing::s_no_test_watch.m_type == type_recursive )
    {
      function_to_call.vtable = 0;
      if ( `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable )
        `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable(
          &function_to_call.functor,
          &function_to_call.functor,
          destroy_functor_tag);
      if ( vostok::testing::test_watcher_thread_proc )
      {
        function_to_call.functor.obj_ptr = vostok::testing::test_watcher_thread_proc;
        function_to_call.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable
                                                                         + 1);
      }
      else
      {
        function_to_call.vtable = 0;
      }
      if ( !s_logical_core_count )
        vostok::threading::initialize_core_count(v2);
      vostok::threading::spawn(
        &function_to_call,
        "test watcher",
        "test-watcher",
        3 % s_logical_core_count,
        0,
        (vostok::threading::tasks_awareness)v2,
        predicate);
      if ( function_to_call.vtable && ((int)function_to_call.vtable & 1) == 0 )
      {
        v1 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
        if ( v1 )
          v1(&function_to_call.functor, &function_to_call.functor, 2);
      }
    }
  }
}
