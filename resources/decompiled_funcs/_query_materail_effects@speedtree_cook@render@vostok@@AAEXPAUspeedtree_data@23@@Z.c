void __usercall vostok::render::speedtree_cook::query_materail_effects(
        vostok::render::speedtree_data *cook_data@<eax>,
        vostok::resources::query_result_for_cook *a2@<ecx>,
        vostok::render::speedtree_cook *this)
{
  vostok::resources::query_result_for_cook::finish_query_impl(
    a2,
    (int)cook_data->m_parent_query,
    result_error,
    assert_on_fail_true,
    (vostok::resources::query_result_for_cook *)0xB);
}
