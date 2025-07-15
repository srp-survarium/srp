void __thiscall survarium::damage_zone_cook::damage_zone_cook(
        survarium::damage_zone_cook *this,
        survarium::game_world *game_world)
{
  s_damage_zone_cook.__vftable = (survarium::damage_zone_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_damage_zone_cook.m_cook_users_count.m_count = 0;
  s_damage_zone_cook.m_class_id = damage_zone_class;
  s_damage_zone_cook.m_reuse_type = reuse_false;
  s_damage_zone_cook.m_creation_thread_id = -1;
  s_damage_zone_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_damage_zone_cook.m_flags.m_flags = 8;
  s_damage_zone_cook.m_next = 0;
  s_damage_zone_cook.__vftable = (survarium::damage_zone_cook_vtbl *)&survarium::damage_zone_cook::`vftable';
  s_damage_zone_cook.m_game_world = game_world;
  vostok::resources::resources_manager::register_cook(&s_damage_zone_cook);
}
