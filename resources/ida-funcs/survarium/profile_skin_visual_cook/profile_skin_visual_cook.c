void __thiscall survarium::profile_skin_visual_cook::profile_skin_visual_cook(
        survarium::profile_skin_visual_cook *this,
        survarium::game *g)
{
  s_profile_skin_visual_cook.__vftable = (survarium::profile_skin_visual_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_profile_skin_visual_cook.m_cook_users_count.m_count = 0;
  s_profile_skin_visual_cook.m_class_id = player_skin_visual_class;
  s_profile_skin_visual_cook.m_reuse_type = reuse_false;
  s_profile_skin_visual_cook.m_creation_thread_id = -1;
  s_profile_skin_visual_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_profile_skin_visual_cook.m_flags.m_flags = 8;
  s_profile_skin_visual_cook.m_next = 0;
  s_profile_skin_visual_cook.__vftable = (survarium::profile_skin_visual_cook_vtbl *)&survarium::profile_skin_visual_cook::`vftable';
  s_profile_skin_visual_cook.m_game = g;
  vostok::resources::resources_manager::register_cook(&s_profile_skin_visual_cook);
}
