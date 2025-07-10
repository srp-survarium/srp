stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall boost::asio::ip::address_v4::to_string(
        boost::asio::ip::address_v4 *this,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result,
        boost::system::error_code *ec)
{
  survarium::game_options *v4; // eax
  stlp_std::allocator<char> *__a; // [esp+Ch] [ebp-1D0h]
  survarium::game_camera v6[3]; // [esp+D6h] [ebp-106h] BYREF

  *(survarium::game_camera_vtbl **)((char *)&v6[0].__vftable + 2) = (survarium::game_camera_vtbl *)boost::asio::detail::socket_ops::inet_ntop(
                                                                                                     2,
                                                                                                     &this->addr_.S_un,
                                                                                                     (char *)&v6[0].m_inverted_view_matrix.elements[0][0] + 2,
                                                                                                     0x100u,
                                                                                                     0,
                                                                                                     ec);
  if ( *(survarium::game_camera_vtbl **)((char *)&v6[0].__vftable + 2) )
  {
    v4 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)v6);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      result,
      *(char **)((char *)&v6[0].__vftable + 2),
      (const stlp_std::allocator<char> *)v4);
    survarium::weapon_user_dead_state::finalize(v6);
  }
  else
  {
    __a = (stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)((char *)&v6[0].__vftable + 1));
    result->_M_finish = (char *)result;
    stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>(
      &result->_M_start_of_storage,
      __a,
      (char *)result);
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_allocate_block(result, 0x10u);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_terminate_string(result);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)((char *)&v6[0].__vftable + 1));
  }
  return result;
}
