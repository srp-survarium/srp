void __thiscall vostok::network::send_queued_order::execute(vostok::network::send_queued_order *this)
{
  boost::function0<void>::operator()((boost::function0<bool> *)this, &this->m_functor.vtable);
  qmemcpy(&this->m_copied_stats, (char *)&loc_55E22 + (unsigned int)*this->m_client + 2, sizeof(this->m_copied_stats));
}
