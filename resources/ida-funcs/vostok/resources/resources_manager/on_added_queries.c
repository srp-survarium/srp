void __usercall vostok::resources::resources_manager::on_added_queries(
        vostok::resources::resources_manager *this@<edx>,
        unsigned int num_queries@<eax>)
{
  volatile int *p_m_pending_queries_count; // ecx
  volatile int *p_m_uncooked_queries_count; // edx

  if ( num_queries )
  {
    p_m_pending_queries_count = &this->m_pending_queries_count;
    p_m_uncooked_queries_count = &this->m_uncooked_queries_count;
    do
    {
      _InterlockedExchangeAdd(p_m_pending_queries_count, 1u);
      _InterlockedExchangeAdd(p_m_uncooked_queries_count, 1u);
      --num_queries;
    }
    while ( num_queries );
  }
}
