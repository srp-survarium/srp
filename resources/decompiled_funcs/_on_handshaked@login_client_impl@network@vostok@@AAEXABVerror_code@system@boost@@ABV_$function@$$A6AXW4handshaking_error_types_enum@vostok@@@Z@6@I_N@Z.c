void __thiscall vostok::network::login_client_impl::on_handshaked(
        vostok::network::login_client_impl *this,
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *error_code,
        boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> *functor,
        unsigned int retry_count,
        bool stop_timer)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool has_passed_filters; // al
  char v8; // [esp+268h] [ebp-84h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v9; // [esp+26Ch] [ebp-80h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+28Ch] [ebp-60h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v11; // [esp+2ACh] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+2C4h] [ebp-28h] BYREF
  char v13; // [esp+2EBh] [ebp-1h]

  v8 = 0;
  v13 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v5 = error_code;
  if ( (error_code->vtable != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    this->m_connection_state = 4;
    if ( retry_count )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network:", info) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v5);
        v8 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\login_client_impl_handshake.cpp",
          0x2Au,
          "void __thiscall vostok::network::login_client_impl::on_handshaked(const class boost::system::error_code &,cons"
          "t class boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> &,unsigned int,bool)",
          "network:",
          info,
          "[LOGIN] NOT handshaked!\r\n");
      }
      if ( (v8 & 1) != 0 )
      {
        v8 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
          (int *)&log_callback);
      }
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network:", error),
            (v5 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)has_passed_filters) != 0) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v5);
        v8 |= 6u;
        (*((void (__thiscall **)(boost::detail::function::vtable_base *, stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *, boost::detail::function::vtable_base *))(&error_code->vtable)[1]->manager
         + 2))(
          (&error_code->vtable)[1],
          &v11,
          error_code->vtable);
        vostok::logging::append(
          &v10,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\login_client_impl_handshake.cpp",
          0x2Bu,
          "void __thiscall vostok::network::login_client_impl::on_handshaked(const class boost::system::error_code &,cons"
          "t class boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> &,unsigned int,bool)",
          "network:",
          error,
          "[LOGIN] error during handshaking: %s\r\n",
          v11._M_start_of_storage._M_data);
      }
      if ( (v8 & 4) != 0 )
      {
        v8 &= ~4u;
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v11);
      }
      if ( (v8 & 2) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
          (int *)&v10);
      vostok::network::login_client_impl::handshake(this, functor, retry_count - 1, stop_timer);
    }
    else
    {
      boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
        (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)functor,
        (const vostok::ai::sensors::sensed_object *)1);
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network:", info) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v5);
      v8 = 8;
      vostok::logging::append(
        &v9,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\login_client_impl_handshake.cpp",
        0x34u,
        "void __thiscall vostok::network::login_client_impl::on_handshaked(const class boost::system::error_code &,const "
        "class boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> &,unsigned int,bool)",
        "network:",
        info,
        "[LOGIN] handshaked!\r\n");
    }
    if ( (v8 & 8) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
        (int *)&v9);
    this->m_connection_state = 6;
    boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
      (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)functor,
      0);
  }
}
