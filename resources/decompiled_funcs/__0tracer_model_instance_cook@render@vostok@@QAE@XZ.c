void __thiscall vostok::render::tracer_model_instance_cook::tracer_model_instance_cook(
        vostok::render::tracer_model_instance_cook *this)
{
  int v1; // ecx

  tracer_model_instance_cooker.__vftable = (vostok::render::tracer_model_instance_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  tracer_model_instance_cooker.m_cook_users_count.m_count = 0;
  tracer_model_instance_cooker.m_class_id = tracer_model_instance_class;
  tracer_model_instance_cooker.m_reuse_type = reuse_false;
  tracer_model_instance_cooker.m_creation_thread_id = -1;
  tracer_model_instance_cooker.m_allocate_thread_id = GetCurrentThreadId();
  tracer_model_instance_cooker.m_flags.m_flags = 8;
  tracer_model_instance_cooker.m_next = 0;
  tracer_model_instance_cooker.__vftable = (vostok::render::tracer_model_instance_cook_vtbl *)&vostok::render::tracer_model_instance_cook::`vftable';
  vostok::resources::resources_manager::register_cook(v1, &tracer_model_instance_cooker);
}
