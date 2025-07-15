void __thiscall vostok::resources::query_result_for_cook::increase_quality_to_target(
        vostok::resources::query_result_for_cook *this,
        vostok::resources::query_result_for_cook *parent_query)
{
  vostok::resources::quality_increase_functionality *v3; // ecx
  vostok::resources::resources_manager *v4; // [esp+0h] [ebp-Ch]
  vostok::resources::quality_increase_functionality v5; // [esp+8h] [ebp-4h] BYREF

  vostok::resources::quality_increase_functionality::quality_increase_functionality(
    &v5,
    &vostok::resources::g_game_resources_manager.m_variable->m_data);
  vostok::resources::quality_increase_functionality::erase_from_increase_quality_tree(v3, &v5, this);
  _InterlockedOr((volatile signed __int32 *)&this[1].m_memory_usage_self, 0x2000000u);
  vostok::resources::resources_manager::push_new_query(
    (vostok::resources::query_result *)this,
    (vostok::threading::mutex *)&this[1].m_memory_usage_self,
    v4);
}
