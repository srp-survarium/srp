void __usercall vostok::resources::resources_manager::on_dispatched_queries(
        vostok::resources::resources_manager *this@<ecx>,
        unsigned int num_queries@<eax>)
{
  volatile int *p_m_pending_queries_count; // ecx

  if ( num_queries )
  {
    p_m_pending_queries_count = &this->m_pending_queries_count;
    do
    {
      _InterlockedExchangeAdd(p_m_pending_queries_count, 0xFFFFFFFF);
      --num_queries;
    }
    while ( num_queries );
  }
}
