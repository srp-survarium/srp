void __userpurge survarium::base_network_client::base_network_client(
        survarium::game *game@<eax>,
        survarium::base_network_client *this)
{
  vostok::memory::doug_lea_allocator *f; // ecx
  int *v4; // eax
  survarium::player_input_handler *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  int *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  int *v9; // eax
  bool v10; // zf
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::base_network_client,char const *>,boost::_bi::list2<boost::_bi::value<survarium::base_network_client *>,boost::arg<1> > > v12; // [esp-10h] [ebp-40h]
  int v13; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(char const *)> functor; // [esp+10h] [ebp-20h] BYREF

  f = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  this->m_current_player.m_object = 0;
  this->m_game = game;
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(f, 0x1A4u);
  if ( v4 )
    survarium::player_input_handler::player_input_handler(
      (survarium::player_input_handler *)&game->m_game_world,
      (int)v4);
  else
    v5 = 0;
  v6 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  this->m_input_handler = v5;
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, 0x28u);
  if ( v7 )
  {
    v7[2] = (int)clear_value;
    v7[3] = LODWORD(infinity_16);
    v7[4] = LODWORD(FLOAT_4_0);
    v7[5] = 1083179008;
    *v7 = 0;
    v7[1] = 0;
    v7[6] = 0;
    v7[8] = 0;
    v7[9] = -16711936;
  }
  else
  {
    v7 = 0;
  }
  v8 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  this->m_linear_speed_graph = (survarium::stats_graph *)v7;
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, 0x28u);
  if ( v9 )
  {
    v9[2] = (int)clear_value;
    v9[3] = LODWORD(infinity_16);
    v9[4] = 1084227584;
    v9[5] = LODWORD(FLOAT_10_0);
    *v9 = 0;
    v9[1] = 0;
    v9[6] = 0;
    v9[8] = 0;
    v9[9] = -16711936;
  }
  else
  {
    v9 = 0;
  }
  v10 = (_S6_7 & 1) == 0;
  this->m_angular_speed_graph = (survarium::stats_graph *)v9;
  if ( v10 )
  {
    _S6_7 |= 1u;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::base_network_client::use_physics_controller_for_current;
    (&functor.vtable)[1] = 0;
    v12.f_.f_ = (void (__thiscall *__ptr64)(survarium::base_network_client *, const char *))(unsigned int)survarium::base_network_client::use_physics_controller_for_current;
    functor.functor.obj_ptr = this;
    *(_QWORD *)&v12.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(0, (int)&functor, -16711936, v12, v13);
    vostok::console_commands::cc_delegate::cc_delegate(
      &s_use_physics_controller_for_current_command,
      "use_physics_controller_for_current",
      (boost::function4<void,unsigned int,float,float,char const *> *)&functor,
      1,
      command_type_engine_internal);
    if ( functor.vtable && ((int)functor.vtable & 1) == 0 )
    {
      v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
      if ( v11 )
        v11(&functor.functor, &functor.functor, 2);
    }
    atexit(survarium::base_network_client::base_network_client_::_2_::_dynamic_atexit_destructor_for__s_use_physics_controller_for_current_command__);
  }
}
