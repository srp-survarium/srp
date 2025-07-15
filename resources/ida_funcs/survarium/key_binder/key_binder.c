void __usercall survarium::key_binder::key_binder(survarium::key_binder *this@<esi>, survarium::game *g@<eax>)
{
  survarium::game_action_descr *v2; // eax
  survarium::console_command_bind *v3; // ecx
  boost::detail::function::vtable_base *v4; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::detail::function::vtable_base *v6; // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  __int64 v8; // [esp+Ch] [ebp-30h]
  int v9; // [esp+14h] [ebp-28h]
  boost::detail::function::vtable_base *v10; // [esp+18h] [ebp-24h]
  boost::detail::function::function_buffer v11; // [esp+20h] [ebp-1Ch] BYREF

  this->m_game = g;
  memset((int)this, 0, 0x300u);
  v2 = actions_;
  do
  {
    v3 = (survarium::console_command_bind *)(3 * v2->id);
    this->m_key_bindings[v2->id].m_action = v2;
    ++v2;
  }
  while ( v2 != (survarium::game_action_descr *)survarium::keyboards );
  if ( (_S6_6 & 1) == 0 )
  {
    _S6_6 |= 1u;
    survarium::console_command_bind::console_command_bind(v3, (int)&s_bind_key_command, this, 0);
    atexit(survarium::key_binder::key_binder_::_8_::_dynamic_atexit_destructor_for__s_bind_key_command__);
  }
  if ( (_S6_6 & 2) == 0 )
  {
    _S6_6 |= 2u;
    survarium::console_command_bind::console_command_bind(v3, (int)&s_bind_sec_key_command, this, 1u);
    atexit(survarium::key_binder::key_binder_::_8_::_dynamic_atexit_destructor_for__s_bind_sec_key_command__);
  }
  if ( (_S6_6 & 4) == 0 )
  {
    _S6_6 |= 4u;
    LODWORD(v8) = survarium::key_binder::unbind_key;
    HIDWORD(v8) = this;
    v9 = 0;
    if ( survarium::generate_shaders_world::is_loading() )
    {
      v4 = 0;
    }
    else
    {
      v11.vostok_pointer_size_alignment[2] = (void *)v9;
      *(_QWORD *)&v11.obj_ptr = v8;
      v4 = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::key_binder,char const *,int>,boost::_bi::list3<boost::_bi::value<survarium::key_binder *>,boost::arg<1>,boost::_bi::value<int>>>>'::`2'::stored_vtable
                                                  + 1);
    }
    v10 = v4;
    s_unbind_key_command.m_next = 0;
    s_unbind_key_command.m_prev = vostok::console_commands::s_console_command_root;
    s_unbind_key_command.m_name = "unbind";
    s_unbind_key_command.m_command_type = command_type_user_specific;
    s_unbind_key_command.m_execution_type = execution_filter_general;
    s_unbind_key_command.m_need_args = 0;
    s_unbind_key_command.m_serializable = 1;
    s_unbind_key_command.m_on_change_event.vtable = 0;
    if ( vostok::console_commands::s_console_command_root )
    {
      vostok::console_commands::s_console_command_root->m_next = &s_unbind_key_command;
      v4 = v10;
    }
    vostok::console_commands::s_console_command_root = &s_unbind_key_command;
    s_unbind_key_command.__vftable = (vostok::console_commands::cc_delegate_vtbl *)&stru_95AF78.m_key_bindings[40];
    s_unbind_key_command.m_functor.vtable = 0;
    if ( v4 )
    {
      s_unbind_key_command.m_functor.vtable = v4;
      if ( ((unsigned __int8)v10 & 1) != 0 )
      {
        s_unbind_key_command.m_functor.functor = v11;
      }
      else
      {
        (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)v4 & 0xFFFFFFFE))(
          &v11,
          &s_unbind_key_command.m_functor.functor,
          0);
        v4 = v10;
      }
    }
    s_unbind_key_command.m_need_args = 1;
    if ( v4 )
    {
      if ( ((unsigned __int8)v10 & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)v4 & 0xFFFFFFFE);
        if ( v5 )
          v5(&v11, &v11, 2);
      }
    }
    atexit(survarium::key_binder::key_binder_::_8_::_dynamic_atexit_destructor_for__s_unbind_key_command__);
  }
  if ( (_S6_6 & 8) == 0 )
  {
    _S6_6 |= 8u;
    v9 = 1;
    LODWORD(v8) = survarium::key_binder::unbind_key;
    HIDWORD(v8) = this;
    if ( survarium::generate_shaders_world::is_loading() )
    {
      v6 = 0;
    }
    else
    {
      *(_QWORD *)&v11.obj_ptr = v8;
      v11.vostok_pointer_size_alignment[2] = (void *)v9;
      v6 = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::key_binder,char const *,int>,boost::_bi::list3<boost::_bi::value<survarium::key_binder *>,boost::arg<1>,boost::_bi::value<int>>>>'::`2'::stored_vtable
                                                  + 1);
    }
    v10 = v6;
    s_unbind_second_key_command.m_next = 0;
    s_unbind_second_key_command.m_prev = vostok::console_commands::s_console_command_root;
    s_unbind_second_key_command.m_name = "unbind_sec";
    s_unbind_second_key_command.m_command_type = command_type_user_specific;
    s_unbind_second_key_command.m_execution_type = execution_filter_general;
    s_unbind_second_key_command.m_need_args = 0;
    s_unbind_second_key_command.m_serializable = 1;
    s_unbind_second_key_command.m_on_change_event.vtable = 0;
    if ( vostok::console_commands::s_console_command_root )
    {
      vostok::console_commands::s_console_command_root->m_next = &s_unbind_second_key_command;
      v6 = v10;
    }
    vostok::console_commands::s_console_command_root = &s_unbind_second_key_command;
    s_unbind_second_key_command.__vftable = (vostok::console_commands::cc_delegate_vtbl *)&stru_95AF78.m_key_bindings[40];
    s_unbind_second_key_command.m_functor.vtable = 0;
    if ( v6 )
    {
      s_unbind_second_key_command.m_functor.vtable = v6;
      if ( ((unsigned __int8)v10 & 1) != 0 )
      {
        s_unbind_second_key_command.m_functor.functor = v11;
      }
      else
      {
        (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)v6 & 0xFFFFFFFE))(
          &v11,
          &s_unbind_second_key_command.m_functor.functor,
          0);
        v6 = v10;
      }
    }
    s_unbind_second_key_command.m_need_args = 1;
    if ( v6 )
    {
      if ( ((unsigned __int8)v10 & 1) == 0 )
      {
        v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)v6 & 0xFFFFFFFE);
        if ( v7 )
          v7(&v11, &v11, 2);
      }
    }
    atexit(survarium::key_binder::key_binder_::_8_::_dynamic_atexit_destructor_for__s_unbind_second_key_command__);
  }
  survarium::key_binder::set_default_controls((survarium::key_binder *)v3, this);
}
