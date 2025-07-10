void __thiscall vostok::render::renderer_cook::renderer_cook(vostok::render::renderer_cook *this)
{
  renderer_cooker.__vftable = (vostok::render::renderer_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  renderer_cooker.m_cook_users_count.m_count = 0;
  renderer_cooker.m_class_id = renderer_class;
  renderer_cooker.m_reuse_type = reuse_false;
  renderer_cooker.m_creation_thread_id = GetCurrentThreadId();
  renderer_cooker.m_allocate_thread_id = GetCurrentThreadId();
  renderer_cooker.m_flags.m_flags = 0;
  renderer_cooker.m_next = 0;
  renderer_cooker.__vftable = (vostok::render::renderer_cook_vtbl *)&vostok::render::renderer_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&renderer_cooker);
}
