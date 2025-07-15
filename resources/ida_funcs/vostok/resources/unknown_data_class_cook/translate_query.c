void __thiscall vostok::resources::unknown_data_class_cook::translate_query(
        vostok::resources::unknown_data_class_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)this,
    result_success,
    assert_on_fail_true,
    error_type_unset);
}
