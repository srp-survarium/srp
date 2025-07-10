void __userpurge vostok::engine::engine_world::initialize_terminate_on_timeout(
        vostok::engine::engine_world *this@<ecx>,
        unsigned int a2@<ebx>,
        int a3@<esi>,
        boost::function0<void> *thisa)
{
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,float>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<float> > > v5; // [esp-10h] [ebp-38h]
  int v6; // [esp+0h] [ebp-28h]
  unsigned int time_limit; // [esp+4h] [ebp-24h] BYREF
  boost::function<void __cdecl(void)> function_to_call; // [esp+8h] [ebp-20h] BYREF

  if ( vostok::command_line::key::is_set_as_number(&s_terminate_on_timeout_key, a2, (float *)&time_limit) )
  {
    function_to_call.vtable = (boost::detail::function::vtable_base *)vostok::engine::engine_world::terminate_on_timeout;
    (&function_to_call.vtable)[1] = 0;
    v5.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *, float))(unsigned int)vostok::engine::engine_world::terminate_on_timeout;
    *(_QWORD *)&function_to_call.functor.obj_ptr = __PAIR64__(time_limit, (unsigned int)thisa);
    v5.l_ = (boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<float> >)__PAIR64__(time_limit, (unsigned int)thisa);
    boost::function0<void>::function0<void>(thisa, (int)&function_to_call, a3, v5, v6);
    if ( !s_logical_core_count )
      vostok::threading::initialize_core_count();
    vostok::threading::spawn(
      &function_to_call,
      "process termination thread",
      "process termination",
      3 % s_logical_core_count,
      tasks_aware);
    if ( function_to_call.vtable && ((int)function_to_call.vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&function_to_call.functor, &function_to_call.functor, 2);
    }
  }
}
