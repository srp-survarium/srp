void __thiscall vostok::network::login_client::create_client(vostok::network::login_client *this)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  char *v5; // eax
  vostok::network::login_client_impl *v6; // eax
  const char *v7; // [esp+0h] [ebp-20h]
  const char *v8; // [esp+4h] [ebp-1Ch]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > result; // [esp+8h] [ebp-18h] BYREF

  v1 = vostok::network::g_allocator;
  v3 = type_info::raw_name(&vostok::network::login_client_impl `RTTI Type Descriptor');
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(
         v4,
         (int)v1,
         0x500u,
         v3,
         v7,
         v8,
         (const unsigned int)result._M_buffers._M_end_of_storage);
  if ( v5 )
    vostok::network::login_client_impl::login_client_impl(
      (vostok::network::login_client_impl *)this->m_world,
      (vostok::network::login_client_impl *)v5,
      this->m_world->m_io_service);
  else
    v6 = 0;
  this->m_client = v6;
  vostok::network_core::get_ip_address(&result, this->m_world->m_io_service);
  vostok::strings::copy<16>((char (*)[16])this->m_local_host_ip, result._M_start_of_storage._M_data);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&result);
}
