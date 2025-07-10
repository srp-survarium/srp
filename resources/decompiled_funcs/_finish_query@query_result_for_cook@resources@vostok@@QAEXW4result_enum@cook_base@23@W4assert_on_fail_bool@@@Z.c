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
