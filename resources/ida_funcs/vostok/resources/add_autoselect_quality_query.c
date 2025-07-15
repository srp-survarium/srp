void __usercall vostok::resources::add_autoselect_quality_query(
        vostok::resources::query_result *query@<esi>,
        int a2@<ecx>,
        double a3@<st0>)
{
  vostok::resources::game_resources_manager *m_variable; // edi
  vostok::resources::cook_base *cook; // eax
  vostok::resources::game_resources_manager *v5; // ecx

  m_variable = vostok::resources::g_game_resources_manager.m_variable;
  cook = vostok::resources::resources_manager::find_cook(a2, query->m_class_id);
  query->m_quality_levels_count = cook->calculate_quality_levels_count(cook, query);
  vostok::resources::resource_quality::update_satisfaction(query, a3, m_variable->m_data.current_increase_quality_tick);
  vostok::resources::game_resources_manager::add_new_resource_to_increase_quality_tree(
    v5,
    m_variable,
    (vostok::resources::quality_increase_functionality)query);
}
