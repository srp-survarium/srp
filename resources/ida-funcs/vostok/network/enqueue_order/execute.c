void __thiscall vostok::network::enqueue_order::execute(vostok::network::enqueue_order *this)
{
  vostok::network_core::udp_match_packet *m_packet; // edi
  const std::exception *v3; // eax
  stlp_std::out_of_range v4; // [esp+10h] [ebp-110h] BYREF

  m_packet = this->m_packet;
  if ( !this->m_enqueuer.vtable )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v4);
    boost::throw_exception(v3);
    stlp_std::__Named_exception::~__Named_exception(&v4);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, vostok::network_core::udp_match_packet *))(((int)this->m_enqueuer.vtable & 0xFFFFFFFE) + 4))(
    &this->m_enqueuer.functor,
    m_packet);
  qmemcpy(&this->m_copied_stats, this->m_source_stats, sizeof(this->m_copied_stats));
}
