void __thiscall client_destroyer::~client_destroyer(client_destroyer *this)
{
  vostok::memory::base_allocator *allocator; // ecx
  vostok::network::match_client_impl **m_client; // eax

  allocator = this->allocator;
  this->__vftable = (client_destroyer_vtbl *)&client_destroyer::`vftable';
  m_client = this->m_client;
  if ( m_client )
  {
    allocator->call_free(allocator, m_client, "client_destroyer::~client_destroyer", ".\\match_client.cpp", 120u);
    this->m_client = 0;
  }
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::dec(
    (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)allocator,
    (int **)&this->m_packets_allocator);
  this->__vftable = (client_destroyer_vtbl *)&vostok::network::order::`vftable';
}
