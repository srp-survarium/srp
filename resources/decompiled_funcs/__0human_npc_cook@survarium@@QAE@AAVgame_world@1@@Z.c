void __thiscall survarium::human_npc_cook::human_npc_cook(
        survarium::human_npc_cook *this,
        survarium::game_world *world)
{
  s_human_npc_cook.__vftable = (survarium::human_npc_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_human_npc_cook.m_cook_users_count.m_count = 0;
  s_human_npc_cook.m_class_id = human_npc_class;
  s_human_npc_cook.m_reuse_type = reuse_true;
  s_human_npc_cook.m_creation_thread_id = -1;
  s_human_npc_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_human_npc_cook.m_game_world = world;
  s_human_npc_cook.m_flags.m_flags = 8;
  s_human_npc_cook.m_next = 0;
  s_human_npc_cook.__vftable = (survarium::human_npc_cook_vtbl *)&survarium::human_npc_cook::`vftable';
}
