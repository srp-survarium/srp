void __thiscall vostok::render::static_render_model_instance_cook::static_render_model_instance_cook(
        vostok::render::static_render_model_instance_cook *this)
{
  static_render_model_instance_cooker.__vftable = (vostok::render::static_render_model_instance_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  static_render_model_instance_cooker.m_cook_users_count.m_count = 0;
  static_render_model_instance_cooker.m_class_id = static_render_model_instance_class;
  static_render_model_instance_cooker.m_reuse_type = reuse_false;
  static_render_model_instance_cooker.m_creation_thread_id = -1;
  static_render_model_instance_cooker.m_allocate_thread_id = GetCurrentThreadId();
  static_render_model_instance_cooker.m_flags.m_flags = 8;
  static_render_model_instance_cooker.m_next = 0;
  static_render_model_instance_cooker.__vftable = (vostok::render::static_render_model_instance_cook_vtbl *)&vostok::render::static_render_model_instance_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&static_render_model_instance_cooker);
}
