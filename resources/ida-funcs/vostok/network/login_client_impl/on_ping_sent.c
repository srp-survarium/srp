void __thiscall vostok::network::login_client_impl::on_ping_sent(
        vostok::network::login_client_impl *this,
        const unsigned int try_count,
        const boost::system::error_code *error_code,
        const unsigned int bytes_transferred)
{
  vostok::network::login_client_impl *v4; // edi
  bool has_passed_filters; // al
  const boost::system::error_category *m_cat; // ecx
  boost::system::error_category_vtbl *v7; // eax
  bool v8; // zf
  bool v9; // al
  vostok::network::login_client_impl *v10; // [esp-4h] [ebp-5Ch]
  int m_val; // [esp-4h] [ebp-5Ch]
  vostok::network::login_client_impl *v12; // [esp-4h] [ebp-5Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::login_client_impl,unsigned int>,boost::_bi::list2<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<enum vostok::network::login_client_impl::<unnamed_tag> > > > expiry_time; // [esp+10h] [ebp-48h] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v14; // [esp+20h] [ebp-38h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v15; // [esp+38h] [ebp-20h] BYREF

  expiry_time.f_.f_ = 0;
  v4 = this;
  if ( (error_code->m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    vostok::network::login_client_impl::ping(this, (vostok::network::login_client_impl *)(try_count - 1));
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.filter_stack,
                                 (const char *)2),
          this = v10,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v15);
      m_val = error_code->m_val;
      m_cat = error_code->m_cat;
      v7 = m_cat->__vftable;
      expiry_time.f_.f_ = (void (__thiscall *)(vostok::network::login_client_impl *, unsigned int))3;
      v7->message(
        m_cat,
        (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v14,
        m_val);
      vostok::logging::append(
        &v15,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\login_client_impl_ping.cpp",
        0x14u,
        "void __thiscall vostok::network::login_client_impl::on_ping_sent(const unsigned int,const class boost::system::e"
        "rror_code &,const unsigned int)",
        &initiator_raw.filter_stack.gap0,
        error,
        "[LOGIN] ping: error during writing to socket: %s\r\n",
        v14._M_start_of_storage._M_data);
    }
    if ( ((int)expiry_time.f_.f_ & 2) != 0 )
    {
      expiry_time.f_.f_ = (void (__thiscall *)(vostok::network::login_client_impl *, unsigned int))((int)expiry_time.f_.f_
                                                                                                  & ~2u);
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v14);
    }
    v8 = ((int)expiry_time.f_.f_ & 1) == 0;
  }
  else
  {
    if ( bytes_transferred )
    {
      expiry_time.l_.a1_.t_ = 0;
      expiry_time.f_.f_ = (void (__thiscall *)(vostok::network::login_client_impl *, unsigned int))&vostok::memory::s_CRT_arena[613496];
      boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::expires_from_now(
        (boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *)this,
        (int)&this->m_ping_timer,
        (boost::posix_time::time_duration *)&expiry_time);
      expiry_time.l_.a2_.t_ = ping_retry_count;
      expiry_time.f_.f_ = (void (__thiscall *)(vostok::network::login_client_impl *, unsigned int))vostok::network::login_client_impl::ping;
      expiry_time.l_.a1_.t_ = v4;
      boost::asio::basic_deadline_timer<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>,boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::async_wait<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::login_client_impl,unsigned int>,boost::_bi::list2<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<enum vostok::network::login_client_impl::_unnamed_tag_>>>>(
        &v4->m_ping_timer,
        &expiry_time);
      return;
    }
    if ( !vostok::core::g_log_filter_tree
      || (v9 = vostok::logging::has_passed_filters(
                 (vostok::logging::filter_tree *)&initiator_raw.filter_stack,
                 (const char *)2),
          this = v12,
          v9) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v15);
      expiry_time.f_.f_ = (void (__thiscall *)(vostok::network::login_client_impl *, unsigned int))4;
      vostok::logging::append(
        &v15,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\login_client_impl_ping.cpp",
        0x19u,
        "void __thiscall vostok::network::login_client_impl::on_ping_sent(const unsigned int,const class boost::system::e"
        "rror_code &,const unsigned int)",
        &initiator_raw.filter_stack.gap0,
        error,
        "[LOGIN] ping: unable to write to socket\r\n");
    }
    v8 = ((int)expiry_time.f_.f_ & 4) == 0;
  }
  if ( !v8 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v15);
}
