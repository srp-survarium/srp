void __userpurge vostok::resources::query_result_for_cook::finish_query(
        vostok::resources::query_result_for_cook *this@<ecx>,
        const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *a2@<edi>,
        vostok::resources::query_result_for_user::error_type_enum error_code,
        assert_on_fail_bool assert_on_cook_failure)
{
  vostok::resources::query_result_for_cook::finish_query_impl(
    this,
    a2,
    (vostok::resources::cook_base::result_enum)(2 * (error_code == error_type_unset) + 1),
    assert_on_cook_failure,
    (vostok::resources::cook_base::result_enum)error_code);
}


void __userpurge vostok::resources::query_result_for_cook::finish_query(
        vostok::resources::query_result_for_cook *this@<ecx>,
        const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *a2@<edi>,
        vostok::resources::cook_base::result_enum result,
        assert_on_fail_bool assert_on_cook_failure)
{
  vostok::resources::query_result_for_cook::finish_query_impl(
    this,
    a2,
    result,
    assert_on_cook_failure,
    result != result_success ? result_fail : result_out_of_memory|0x8);
}
