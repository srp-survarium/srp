void __thiscall vostok::resources::query_result_for_cook::finish_query(
        vostok::resources::query_result_for_cook *this,
        vostok::resources::query_result_for_cook *error_code,
        assert_on_fail_bool assert_on_cook_failure)
{
  vostok::resources::query_result_for_cook::finish_query_impl(
    this,
    (int)this,
    (vostok::resources::cook_base::result_enum)(2 * (error_code == 0) + 1),
    assert_on_cook_failure,
    error_code);
}


void __thiscall vostok::resources::query_result_for_cook::finish_query(
        vostok::resources::query_result_for_cook *this,
        vostok::resources::cook_base::result_enum result,
        assert_on_fail_bool assert_on_cook_failure)
{
  vostok::resources::query_result_for_cook::finish_query_impl(
    this,
    (int)this,
    result,
    assert_on_cook_failure,
    result != result_error ? 0 : (vostok::resources::query_result_for_cook *)11);
}
