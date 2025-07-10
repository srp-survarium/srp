void __thiscall vostok::network_core::async_connector::connect(
        vostok::network_core::async_connector *this,
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *iterator)
{
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> v2; // [esp-10h] [ebp-118h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *v3; // [esp-4h] [ebp-10Ch]
  vostok::network_core::async_connector *thisa; // [esp+0h] [ebp-108h]
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *v5; // [esp+F0h] [ebp-18h]
  boost::detail::shared_count *p_pn; // [esp+F4h] [ebp-14h]
  boost::detail::sp_counted_base *pi; // [esp+F8h] [ebp-10h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+100h] [ebp-8h] BYREF

  thisa = this;
  this->m_connection_state = connection_is_being_established;
  v2.index_ = (unsigned __int8)1_278;
  v3 = boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
         (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
         (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::async_connector::on_connected,
         (vostok::sound::sound_debug_stats *)thisa);
  v5 = &v2;
  v2.values_.px = iterator->values_.px;
  p_pn = &v2.values_.pn;
  v2.values_.pn.pi_ = iterator->values_.pn.pi_;
  if ( v2.values_.pn.pi_ )
  {
    pi = p_pn->pi_;
    _InterlockedExchangeAdd(&pi->use_count_, 1u);
  }
  v5->index_ = iterator->index_;
  boost::asio::async_connect<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::async_connector,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list3<boost::_bi::value<vostok::network_core::async_connector *>,boost::arg<1>,boost::arg<2>>>>(
    thisa->m_socket,
    v2,
    (const boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::async_connector,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::async_connector *>,boost::arg<1>,boost::arg<2> > > *)v3);
}
