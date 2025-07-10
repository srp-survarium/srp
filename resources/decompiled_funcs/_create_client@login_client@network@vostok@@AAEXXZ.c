void __thiscall vostok::network::login_client::create_client(vostok::network::login_client *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::network::login_client_impl *v3; // eax
  vostok::network::login_client_impl *v4; // [esp+4h] [ebp-44h]
  void *_Where; // [esp+20h] [ebp-28h]
  vostok::network::login_client_impl *v7; // [esp+28h] [ebp-20h]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > ip_address; // [esp+30h] [ebp-18h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 0x4A0u);
  v7 = (vostok::network::login_client_impl *)operator new(0x4A0u, _Where);
  if ( v7 )
  {
    vostok::network::login_client_impl::login_client_impl(v7, this->m_world->m_io_service);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  this->m_client = v4;
  vostok::network_core::get_ip_address(&ip_address, this->m_world->m_io_service);
  vostok::strings::copy(this->m_local_host_ip, 0x10u, ip_address._M_start_of_storage._M_data);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&ip_address);
}
