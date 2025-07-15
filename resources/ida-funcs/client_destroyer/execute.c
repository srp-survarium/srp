void __thiscall client_destroyer::execute(client_destroyer *this)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  int *m_client; // edi
  char *v4; // ebx
  vostok::memory::doug_lea_allocator *v5; // ecx
  const char *v6; // [esp+0h] [ebp-10h]
  const char *v7; // [esp+4h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-8h]

  v1 = vostok::network::g_allocator;
  m_client = (int *)this->m_client;
  v4 = (char *)*m_client;
  if ( *m_client )
  {
    vostok::network::match_client_impl::~match_client_impl((vostok::network::match_client_impl *)this, *m_client);
    vostok::memory::doug_lea_allocator::free_impl(v5, (int)v1, v4, v6, v7, v8);
    *m_client = 0;
  }
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::operator=(
    &this->m_packets_allocator,
    0,
    (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)this);
}
