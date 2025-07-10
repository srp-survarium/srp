void __usercall vostok::resources::query_result_for_cook::update_quality_levels_count(
        vostok::resources::query_result_for_cook *this@<ecx>,
        const vostok::resources::query_result_for_cook *a2@<esi>)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(a2->m_class_id);
  a2->m_quality_levels_count = cook->calculate_quality_levels_count(cook, a2);
}
