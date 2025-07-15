void __usercall vostok::engine::engine_world::initialize_editor(
        vostok::engine::engine_world *this@<ecx>,
        _BYTE *a2@<esi>)
{
  bool v2; // zf
  const char *v3; // ebp
  const char *v4; // ebx
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v6; // [esp-10h] [ebp-54h]
  vostok::threading *v7; // [esp+0h] [ebp-44h]
  vostok::threading::tasks_awareness v8; // [esp+0h] [ebp-44h]
  void **v9; // [esp+4h] [ebp-40h]
  __int64 v10; // [esp+18h] [ebp-2Ch]
  boost::function<void __cdecl(void)> function_to_call; // [esp+20h] [ebp-24h] BYREF

  v2 = s_logical_core_count == 0;
  a2[710] = 0;
  if ( v2 )
    vostok::threading::initialize_core_count(v7);
  if ( s_logical_core_count != 1 )
  {
    g_threads.m_begin[2].m_thread_id = -1;
    v3 = "editor";
    if ( (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)a2 + 100))(a2) )
      v3 = "editor + logic";
    v4 = "editor";
    if ( (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)a2 + 100))(a2) )
      v4 = "editor + logic";
    v6.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::editor;
    LODWORD(v10) = a2;
    *(_QWORD *)&v6.l_.a1_.t_ = v10;
    boost::function0<void>::function0<void>(0, (int)&function_to_call, (int)a2, v6, (int)v7);
    vostok::threading::spawn(&function_to_call, v4, v3, 0, 0, v8, v9);
    if ( function_to_call.vtable && ((int)function_to_call.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&function_to_call.functor, &function_to_call.functor, 2);
    }
  }
}
