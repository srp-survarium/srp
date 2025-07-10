void __thiscall vostok::render::grass_cook::grass_cook(vostok::render::grass_cook *this)
{
  int v1; // ecx

  grass_cooker.__vftable = (vostok::render::grass_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  grass_cooker.m_cook_users_count.m_count = 0;
  grass_cooker.m_class_id = grass_world_class;
  grass_cooker.m_reuse_type = reuse_false;
  grass_cooker.m_creation_thread_id = -1;
  grass_cooker.m_allocate_thread_id = GetCurrentThreadId();
  grass_cooker.m_flags.m_flags = 8;
  grass_cooker.m_next = 0;
  grass_cooker.__vftable = (vostok::render::grass_cook_vtbl *)&vostok::render::grass_cook::`vftable';
  vostok::resources::resources_manager::register_cook(v1, &grass_cooker);
}
