void __userpurge vostok::resources::query_result::add_referrer(
        vostok::resources::query_result *referer@<esi>,
        vostok::resources::query_result *a2@<ecx>,
        vostok::resources::query_result *this,
        bool log_that_referer_query_added)
{
  vostok::resources::query_result::free_unmanaged_buffer(a2, (int)referer);
  _InterlockedOr(&referer->m_flags, 0xC0u);
  referer->m_next_referer = this->m_next_referer;
  this->m_next_referer = referer;
}
