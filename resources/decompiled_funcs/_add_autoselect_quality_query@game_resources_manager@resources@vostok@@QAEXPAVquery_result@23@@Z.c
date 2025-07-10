void __usercall vostok::resources::game_resources_manager::add_autoselect_quality_query(
        vostok::resources::game_resources_manager *this@<edi>,
        vostok::resources::query_result *query@<esi>,
        int a3@<ecx>,
        double a4@<st0>)
{
  vostok::resources::cook_base *cook; // eax
  vostok::resources::game_resources_manager *v5; // ecx

  cook = vostok::resources::resources_manager::find_cook(a3, query->m_class_id);
  query->m_quality_levels_count = cook->calculate_quality_levels_count(cook, query);
  vostok::resources::resource_quality::update_satisfaction(query, a4, this->m_data.current_increase_quality_tick);
  vostok::resources::game_resources_manager::add_new_resource_to_increase_quality_tree(
    v5,
    this,
    (vostok::resources::quality_increase_functionality)query);
}
