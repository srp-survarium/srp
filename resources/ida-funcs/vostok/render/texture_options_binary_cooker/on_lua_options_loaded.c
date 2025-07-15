void __thiscall vostok::render::texture_options_binary_cooker::on_lua_options_loaded(
        vostok::render::texture_options_binary_cooker *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)this,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)result->m_parent_query,
    result_cannot_lock,
    assert_on_fail_true,
    result_fail);
}
