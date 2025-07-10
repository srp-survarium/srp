void __thiscall survarium::animation_space_graph_cook::animation_space_graph_cook(
        survarium::animation_space_graph_cook *this,
        vostok::ai::navigation::world *navigation_world)
{
  s_animation_space_graph_cook.__vftable = (survarium::animation_space_graph_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_animation_space_graph_cook.m_cook_users_count.m_count = 0;
  s_animation_space_graph_cook.m_class_id = animation_space_graph_class;
  s_animation_space_graph_cook.m_reuse_type = reuse_true;
  s_animation_space_graph_cook.m_creation_thread_id = -1;
  s_animation_space_graph_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_animation_space_graph_cook.m_navigation_world = navigation_world;
  s_animation_space_graph_cook.m_flags.m_flags = 8;
  s_animation_space_graph_cook.m_next = 0;
  s_animation_space_graph_cook.__vftable = (survarium::animation_space_graph_cook_vtbl *)&survarium::animation_space_graph_cook::`vftable';
}
