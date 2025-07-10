stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__cdecl vostok::network_core::get_ip_address(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result,
        boost::asio::io_service *io_service)
{
  survarium::game_options *v2; // eax
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v3; // eax
  survarium::game_options *v5; // eax
  _BYTE v6[85]; // [esp+4CFh] [ebp-11Dh] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v7; // [esp+524h] [ebp-C8h] BYREF
  survarium::game_camera v8; // [esp+53Fh] [ebp-ADh] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v9; // [esp+594h] [ebp-58h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v10; // [esp+5ACh] [ebp-40h] BYREF
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> end; // [esp+5C8h] [ebp-24h] BYREF
  boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > resolver; // [esp+5D4h] [ebp-18h] BYREF
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> iter; // [esp+5E0h] [ebp-Ch] BYREF

  boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(
    &resolver,
    io_service);
  v2 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v8);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v8.__vftable + 1),
    (char *)&buf,
    (const stlp_std::allocator<char> *)v2);
  v3 = boost::asio::ip::host_name(&v7);
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp>::basic_resolver_query<boost::asio::ip::tcp>(
    (boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *)((char *)&v8.m_inverted_view_matrix.lines[3].x + 1),
    v3,
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v8.__vftable
                                                                                                + 1),
    address_configured);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v7);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v8.__vftable + 1));
  survarium::weapon_user_dead_state::finalize(&v8);
  boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::resolve(
    &resolver,
    &iter,
    (const boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *)((char *)&v8.m_inverted_view_matrix.lines[3].x
                                                                        + 1));
  boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>((boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *)&end);
  end.index_ = 0;
  while ( !boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::equal(&iter, &end) )
  {
    qmemcpy(&v6[57], &iter.values_.px->_M_impl._M_start[iter.index_], 0x1Cu);
    boost::asio::ip::detail::endpoint::address(
      (boost::asio::ip::detail::endpoint *)&v6[57],
      (boost::asio::ip::address *)((char *)&v8.m_inverted_view_matrix.lines[1].elements[1] + 1));
    if ( !boost::asio::ip::address::is_loopback((boost::asio::ip::address *)((char *)&v8.m_inverted_view_matrix.lines[1].elements[1]
                                                                           + 1))
      && !*(_DWORD *)((char *)&v8.m_inverted_view_matrix.j.elements[1] + 1) )
    {
      qmemcpy(&v6[29], &iter.values_.px->_M_impl._M_start[iter.index_], 0x1Cu);
      boost::asio::ip::detail::endpoint::address(
        (boost::asio::ip::detail::endpoint *)&v6[29],
        (boost::asio::ip::address *)&v6[1]);
      if ( *(_DWORD *)&v6[1] == 1 )
        boost::asio::ip::address_v6::to_string((boost::asio::ip::address_v6 *)&v6[9], result);
      else
        boost::asio::ip::address_v4::to_string((boost::asio::ip::address_v4 *)&v6[5], result);
      if ( end.values_.pn.pi_ )
        boost::detail::sp_counted_base::release(end.values_.pn.pi_);
      if ( iter.values_.pn.pi_ )
        boost::detail::sp_counted_base::release(iter.values_.pn.pi_);
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v10);
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v9);
      boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>((boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp> > *)&resolver);
      return result;
    }
    boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::increment(&iter);
  }
  v5 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)v6);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    result,
    "unknown",
    (const stlp_std::allocator<char> *)v5);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v6);
  if ( end.values_.pn.pi_ )
    boost::detail::sp_counted_base::release(end.values_.pn.pi_);
  if ( iter.values_.pn.pi_ )
    boost::detail::sp_counted_base::release(iter.values_.pn.pi_);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v10);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v9);
  boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>((boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp> > *)&resolver);
  return result;
}
