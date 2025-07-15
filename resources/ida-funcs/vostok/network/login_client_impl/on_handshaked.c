void __thiscall vostok::network::login_client_impl::on_handshaked(
        vostok::network::login_client_impl *this,
        const boost::system::error_code *error_code,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *functor,
        unsigned int retry_count,
        bool stop_timer)
{
  bool has_passed_filters; // al
  vostok::network::login_client_impl *v6; // [esp-4h] [ebp-54h]
  char v7; // [esp+10h] [ebp-40h]
  vostok::network::login_client_impl *v8; // [esp+14h] [ebp-3Ch]
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v9; // [esp+18h] [ebp-38h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+30h] [ebp-20h] BYREF

  v8 = this;
  v7 = 0;
  if ( (error_code->m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    this->m_connection_state = connected;
    if ( retry_count )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"login",
                                   (const char *)3),
            this = v6,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
          &v10);
        v7 = 3;
        error_code->m_cat->message(
          error_code->m_cat,
          (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v9,
          error_code->m_val);
        vostok::logging::append(
          &v10,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\login_client_impl_handshake.cpp",
          0x2Bu,
          "void __thiscall vostok::network::login_client_impl::on_handshaked(const class boost::system::error_code &,cons"
          "t class boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> &,unsigned int,bool)",
          "login",
          warning,
          "error during handshaking: %s\r\n",
          v9._M_start_of_storage._M_data);
      }
      if ( (v7 & 2) != 0 )
      {
        v7 &= ~2u;
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v9);
      }
      if ( (v7 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
          (int *)&v10);
      vostok::network::login_client_impl::handshake(
        v8,
        functor,
        (vostok::network::login_client_impl *)(retry_count - 1),
        (boost::arg<1>)stop_timer);
    }
    else
    {
      boost::function1<void,vostok::collision::object const &>::operator()(
        (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
        functor,
        (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)1);
    }
  }
  else
  {
    this->m_connection_state = handshaked;
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      functor,
      0);
  }
}
