int dynamic_initializer_for__cfg_save_user_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v2; // [esp-8h] [ebp-38h]
  boost::function1<void,char const *> *v3; // [esp+Ch] [ebp-24h]
  boost::function4<void,unsigned int,float,float,char const *> v4; // [esp+10h] [ebp-20h] BYREF

  *(_DWORD *)&v2.l_ = v3;
  v2.f_ = cfg_save_user;
  v4.vtable = 0;
  boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
    v3,
    (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v4,
    v2);
  cfg_save_user_cc.m_next = 0;
  cfg_save_user_cc.m_prev = vostok::console_commands::s_console_command_root;
  cfg_save_user_cc.m_name = "cfg_save_user";
  cfg_save_user_cc.m_command_type = command_type_engine_internal;
  cfg_save_user_cc.m_execution_type = execution_filter_general;
  cfg_save_user_cc.m_need_args = 0;
  cfg_save_user_cc.m_serializable = 1;
  cfg_save_user_cc.m_on_change_event.vtable = 0;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &cfg_save_user_cc;
  vostok::console_commands::s_console_command_root = &cfg_save_user_cc;
  cfg_save_user_cc.__vftable = (vostok::console_commands::cc_delegate_vtbl *)&stru_95AF78.m_key_bindings[40];
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    &v4,
    (int)&cfg_save_user_cc.m_functor);
  cfg_save_user_cc.m_need_args = 0;
  if ( v4.vtable )
  {
    if ( ((int)v4.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v4.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&v4.functor, &v4.functor, 2);
    }
  }
  return atexit(dynamic_atexit_destructor_for__cfg_save_user_cc__);
}
