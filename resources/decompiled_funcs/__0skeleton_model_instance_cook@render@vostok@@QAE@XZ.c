void __thiscall vostok::render::skeleton_model_instance_cook::skeleton_model_instance_cook(
        vostok::render::skeleton_model_instance_cook *this)
{
  int v1; // ecx

  skeleton_model_instance_cooker.__vftable = (vostok::render::skeleton_model_instance_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  skeleton_model_instance_cooker.m_cook_users_count.m_count = 0;
  skeleton_model_instance_cooker.m_class_id = skeleton_model_instance_class;
  skeleton_model_instance_cooker.m_reuse_type = reuse_false;
  skeleton_model_instance_cooker.m_creation_thread_id = -1;
  skeleton_model_instance_cooker.m_allocate_thread_id = GetCurrentThreadId();
  skeleton_model_instance_cooker.m_flags.m_flags = 8;
  skeleton_model_instance_cooker.m_next = 0;
  skeleton_model_instance_cooker.__vftable = (vostok::render::skeleton_model_instance_cook_vtbl *)&vostok::render::skeleton_model_instance_cook::`vftable';
  vostok::resources::resources_manager::register_cook(v1, &skeleton_model_instance_cooker);
}
