void __thiscall vostok::resources::query_result::on_allocated_final_resource(vostok::resources::query_result *this)
{
  vostok::resources::query_result::send_to_create_resource(this);
}
