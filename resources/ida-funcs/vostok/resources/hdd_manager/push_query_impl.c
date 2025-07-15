void __thiscall vostok::resources::hdd_manager::push_query_impl(
        vostok::resources::hdd_manager *this,
        vostok::resources::query_result *res)
{
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &this->m_queries,
    res,
    (vostok::threading::mutex *)this);
}
