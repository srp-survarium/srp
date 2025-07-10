void __userpurge vostok::engine::engine_world::initialize_sound(
        vostok::engine::engine_world *this@<ecx>,
        int a2@<esi>,
        vostok::engine::engine_world *thisa)
{
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v4; // [esp-10h] [ebp-38h]
  int v5; // [esp+0h] [ebp-28h]
  boost::function<void __cdecl(void)> function_to_call; // [esp+8h] [ebp-20h] BYREF

  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type == type_recursive )
  {
    g_threads.m_begin[4].m_thread_id = -1;
    function_to_call.vtable = (boost::detail::function::vtable_base *)vostok::engine::engine_world::sound;
    (&function_to_call.vtable)[1] = 0;
    v4.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::sound;
    function_to_call.functor.obj_ptr = thisa;
    *(_QWORD *)&v4.l_.a1_.t_ = *(_QWORD *)&function_to_call.functor.obj_ptr;
    boost::function0<void>::function0<void>(0, (int)&function_to_call, a2, v4, v5);
    if ( !s_logical_core_count )
      vostok::threading::initialize_core_count();
    vostok::threading::spawn(&function_to_call, "sound", "sound", 5 % s_logical_core_count, tasks_aware);
    if ( function_to_call.vtable && ((int)function_to_call.vtable & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
      if ( v3 )
        v3(&function_to_call.functor, &function_to_call.functor, 2);
    }
  }
}
