void __thiscall vostok::render::texture_options_binary_cooker::on_lua_options_loaded(
        vostok::render::texture_options_binary_cooker *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)this,
    result_requery,
    assert_on_fail_true,
    error_type_unset);
}
