void __userpurge vostok::resources::query_result::observe_resource_destruction(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result *a2@<eax>,
        vostok::resources::resource_base *resource)
{
  _InterlockedExchangeAdd(&a2->m_observed_resource_destructions_left, 1u);
  resource->m_destruction_observer = a2;
}
