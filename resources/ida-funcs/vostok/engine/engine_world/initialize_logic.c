void __usercall vostok::engine::engine_world::initialize_logic(
        vostok::engine::engine_world *this@<ecx>,
        _DWORD *a2@<esi>)
{
  HWND__ *v2; // eax
  bool v3; // zf
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v5; // [esp-10h] [ebp-3Ch]
  vostok::threading *v6; // [esp+0h] [ebp-2Ch]
  vostok::threading *v7; // [esp+0h] [ebp-2Ch]
  void **v8; // [esp+4h] [ebp-28h]
  boost::function<void __cdecl(void)> function_to_call; // [esp+8h] [ebp-24h] BYREF

  vostok::apc::wait(editor);
  if ( !a2[159] )
  {
    v2 = new_window();
    a2[168] = v2;
    a2[169] = v2;
  }
  v3 = s_logical_core_count == 0;
  a2[170] = 0;
  if ( v3 )
    vostok::threading::initialize_core_count(v6);
  if ( s_logical_core_count != 1 && (!a2[159] || !(*(unsigned __int8 (__thiscall **)(_DWORD *))(*a2 + 100))(a2)) )
  {
    g_threads.m_begin[1].m_thread_id = -1;
    function_to_call.vtable = (boost::detail::function::vtable_base *)vostok::engine::engine_world::logic;
    (&function_to_call.vtable)[1] = 0;
    v5.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::logic;
    function_to_call.functor.obj_ptr = a2;
    *(_QWORD *)&v5.l_.a1_.t_ = *(_QWORD *)&function_to_call.functor.obj_ptr;
    boost::function0<void>::function0<void>(0, (int)&function_to_call, (int)a2, v5, (int)v6);
    if ( !s_logical_core_count )
      vostok::threading::initialize_core_count(v7);
    vostok::threading::spawn(
      &function_to_call,
      "logic",
      "logic",
      1 % s_logical_core_count,
      0,
      (vostok::threading::tasks_awareness)v7,
      v8);
    if ( function_to_call.vtable && ((int)function_to_call.vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&function_to_call.functor, &function_to_call.functor, 2);
    }
  }
}
