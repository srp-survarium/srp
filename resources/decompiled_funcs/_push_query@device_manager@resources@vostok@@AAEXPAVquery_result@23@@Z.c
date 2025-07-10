void __fastcall vostok::resources::device_manager::push_query(
        vostok::resources::device_manager *this,
        vostok::resources::query_result *query)
{
  this->push_query_impl(this, query);
}
