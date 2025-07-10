void __thiscall vostok::resources::hdd_manager::push_query_impl(
        vostok::resources::hdd_manager *this,
        vostok::resources::query_result *res)
{
  bool *v2; // [esp+0h] [ebp-4h]

  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
    &this->m_queries.m_size,
    res,
    v2);
}
