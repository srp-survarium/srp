void __thiscall vostok::network::connect_order::execute(vostok::network::connect_order *this)
{
  const vostok::network_core::udp_match_packet *m_packet; // ebx
  const std::exception *v3; // eax
  char *m_host; // [esp+Ch] [ebp-114h]
  stlp_std::out_of_range v5; // [esp+10h] [ebp-110h] BYREF

  m_packet = this->m_packet;
  m_host = this->m_host;
  if ( !this->m_connector.vtable )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v5);
    boost::throw_exception(v3);
    stlp_std::__Named_exception::~__Named_exception(&v5);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, char *, const vostok::network_core::udp_match_packet *))(((int)this->m_connector.vtable & 0xFFFFFFFE) + 4))(
    &this->m_connector.functor,
    m_host,
    m_packet);
}
