stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__cdecl boost::asio::ip::host_name(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result)
{
  survarium::game_options *v1; // eax
  survarium::game_options *v3; // eax
  survarium::game_camera v4[12]; // [esp+166h] [ebp-40Ah] BYREF
  boost::system::error_code ec; // [esp+568h] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  if ( boost::asio::detail::socket_ops::gethostname((char *)&v4[0].__vftable + 2, 1024, &ec) )
  {
    if ( (ec.m_val != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
      boost::asio::detail::do_throw_error(&ec);
    v1 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)((char *)&v4[0].__vftable + 1));
    result->_M_finish = (char *)result;
    stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>(
      &result->_M_start_of_storage,
      (const stlp_std::allocator<char> *)v1,
      (char *)result);
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_allocate_block(result, 0x10u);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_terminate_string(result);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)((char *)&v4[0].__vftable + 1));
    return result;
  }
  else
  {
    v3 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)v4);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      result,
      (char *)&v4[0].__vftable + 2,
      (const stlp_std::allocator<char> *)v3);
    survarium::weapon_user_dead_state::finalize(v4);
    return result;
  }
}
