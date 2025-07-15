void __thiscall vostok::resources::unknown_data_class_cook::translate_query(
        vostok::resources::unknown_data_class_cook *this,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent)
{
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)this,
    parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
