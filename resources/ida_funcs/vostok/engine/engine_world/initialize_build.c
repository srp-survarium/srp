void __userpurge vostok::engine::engine_world::initialize_build(
        vostok::engine::engine_world *this@<ecx>,
        int a2@<esi>,
        vostok::engine::engine_world *project_id,
        const char *project_ida)
{
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<char const *> > > v5; // [esp-10h] [ebp-3Ch]
  int v6; // [esp+0h] [ebp-2Ch]
  boost::function<void __cdecl(void)> function_to_call; // [esp+8h] [ebp-24h] BYREF

  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type == type_recursive )
  {
    function_to_call.vtable = (boost::detail::function::vtable_base *)vostok::engine::engine_world::build;
    g_threads.m_begin[5].m_thread_id = -1;
    (&function_to_call.vtable)[1] = 0;
    v5.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *, const char *))(unsigned int)function_to_call.vtable;
    *(_QWORD *)&function_to_call.functor.obj_ptr = __PAIR64__((unsigned int)project_ida, (unsigned int)project_id);
    v5.l_ = (boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<char const *> >)__PAIR64__((unsigned int)project_ida, (unsigned int)project_id);
    boost::function0<void>::function0<void>(0, (int)&function_to_call, a2, v5, v6);
    if ( !s_logical_core_count )
      vostok::threading::initialize_core_count();
    vostok::threading::spawn(
      &function_to_call,
      "build resources",
      "build resources",
      7 % s_logical_core_count,
      tasks_aware);
    if ( function_to_call.vtable && ((int)function_to_call.vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&function_to_call.functor, &function_to_call.functor, 2);
    }
  }
}
