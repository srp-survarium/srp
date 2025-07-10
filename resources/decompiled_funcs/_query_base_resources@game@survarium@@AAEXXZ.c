void __usercall survarium::game::query_base_resources(survarium::game *this@<ecx>, void *a2@<eax>)
{
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v4; // [esp-10h] [ebp-4Ch]
  int v5; // [esp+0h] [ebp-3Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+8h] [ebp-34h] BYREF
  vostok::resources::request requests[2]; // [esp+28h] [ebp-14h] BYREF

  survarium::game::register_console_commands(this, a2);
  requests[0].id = raw_data_class;
  requests[1].id = raw_data_class;
  callback.vtable = (boost::detail::function::vtable_base *)survarium::game::on_configs_loaded;
  (&callback.vtable)[1] = 0;
  v4.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *, vostok::resources::queries_result *))(unsigned int)survarium::game::on_configs_loaded;
  callback.functor.obj_ptr = a2;
  requests[0].path = "resources/startup.cfg";
  requests[1].path = "user_data/user.cfg";
  *(_QWORD *)&v4.l_.a1_.t_ = *(_QWORD *)&callback.functor.obj_ptr;
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    0,
    (int)&callback,
    (int)a2,
    v4,
    v5);
  vostok::resources::query_resources(
    requests,
    2u,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0,
    0,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v3 )
      v3(&callback.functor, &callback.functor, 2);
  }
}
