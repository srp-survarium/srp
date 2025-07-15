void __thiscall vostok::render::user_mesh_cook::user_mesh_cook(vostok::render::user_mesh_cook *this)
{
  user_mesh_cooker.__vftable = (vostok::render::user_mesh_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  user_mesh_cooker.m_cook_users_count.m_count = 0;
  user_mesh_cooker.m_class_id = user_mesh_class;
  user_mesh_cooker.m_reuse_type = reuse_true;
  user_mesh_cooker.m_creation_thread_id = GetCurrentThreadId();
  user_mesh_cooker.m_allocate_thread_id = 0;
  user_mesh_cooker.m_flags.m_flags = 2;
  user_mesh_cooker.m_next = 0;
  user_mesh_cooker.__vftable = (vostok::render::user_mesh_cook_vtbl *)&vostok::render::user_mesh_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&user_mesh_cooker);
}
