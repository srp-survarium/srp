void __usercall survarium::game::register_console_commands(survarium::game *this@<ecx>, void *a2@<esi>)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,char const *>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v6; // [esp-10h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game,char const *,bool>,boost::_bi::list3<boost::_bi::value<survarium::game *>,boost::arg<1>,boost::_bi::value<bool> > > v7; // [esp-10h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,char const *>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v8; // [esp-10h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,char const *>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v9; // [esp-10h] [ebp-44h]
  int v10; // [esp+0h] [ebp-34h]
  unsigned int v11; // [esp+Ch] [ebp-28h]
  boost::function<void __cdecl(char const *)> functor; // [esp+10h] [ebp-24h] BYREF

  if ( (_S9_0 & 1) == 0 )
  {
    _S9_0 |= 1u;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game::exit;
    (&functor.vtable)[1] = 0;
    v6.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *, const char *))(unsigned int)survarium::game::exit;
    functor.functor.obj_ptr = a2;
    *(_QWORD *)&v6.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(0, (int)&functor, (int)a2, v6, v10);
    vostok::console_commands::cc_delegate::cc_delegate(&game_exit_cc, "quit", &functor, 0, command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v2 )
          v2(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game::register_console_commands_::_2_::_dynamic_atexit_destructor_for__game_exit_cc__);
  }
  if ( (_S9_0 & 2) == 0 )
  {
    _S9_0 |= 2u;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game::load_config_query;
    LOBYTE(v11) = 0;
    (&functor.vtable)[1] = 0;
    v7.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *, const char *, bool))(unsigned int)survarium::game::load_config_query;
    *(_QWORD *)&functor.functor.obj_ptr = __PAIR64__(v11, (unsigned int)a2);
    v7.l_ = (boost::_bi::list3<boost::_bi::value<survarium::game *>,boost::arg<1>,boost::_bi::value<bool> >)__PAIR64__(v11, (unsigned int)a2);
    boost::function1<void,char const *>::function1<void,char const *>(0, (int)&functor, (int)a2, v7, v10);
    vostok::console_commands::cc_delegate::cc_delegate(
      &cfg_load_cc,
      "cfg_load",
      &functor,
      1,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v3 )
          v3(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game::register_console_commands_::_2_::_dynamic_atexit_destructor_for__cfg_load_cc__);
  }
  if ( (_S9_0 & 4) == 0 )
  {
    _S9_0 |= 4u;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game::load_cmd;
    (&functor.vtable)[1] = 0;
    v8.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *, const char *))(unsigned int)survarium::game::load_cmd;
    functor.functor.obj_ptr = a2;
    *(_QWORD *)&v8.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(0, (int)&functor, (int)a2, v8, v10);
    vostok::console_commands::cc_delegate::cc_delegate(
      &cfg_load_level,
      "level_load",
      &functor,
      1,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v4 )
          v4(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game::register_console_commands_::_2_::_dynamic_atexit_destructor_for__cfg_load_level__);
  }
  if ( (_S9_0 & 8) == 0 )
  {
    _S9_0 |= 8u;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game::unload_cmd;
    (&functor.vtable)[1] = 0;
    v9.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *, const char *))(unsigned int)survarium::game::unload_cmd;
    functor.functor.obj_ptr = a2;
    *(_QWORD *)&v9.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(0, (int)&functor, (int)a2, v9, v10);
    vostok::console_commands::cc_delegate::cc_delegate(
      &cfg_unload_level,
      "level_unload",
      &functor,
      0,
      command_type_engine_internal);
    if ( functor.vtable && ((int)functor.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&functor.functor, &functor.functor, 2);
    }
    atexit(survarium::game::register_console_commands_::_2_::_dynamic_atexit_destructor_for__cfg_unload_level__);
  }
}
