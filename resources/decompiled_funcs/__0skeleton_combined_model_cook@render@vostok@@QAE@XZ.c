void __thiscall vostok::render::skeleton_combined_model_cook::skeleton_combined_model_cook(
        vostok::render::skeleton_combined_model_cook *this)
{
  skeleton_combined_model_cooker.__vftable = (vostok::render::skeleton_combined_model_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  skeleton_combined_model_cooker.m_cook_users_count.m_count = 0;
  skeleton_combined_model_cooker.m_class_id = skeleton_combined_model_class;
  skeleton_combined_model_cooker.m_reuse_type = reuse_true;
  skeleton_combined_model_cooker.m_creation_thread_id = -1;
  skeleton_combined_model_cooker.m_allocate_thread_id = GetCurrentThreadId();
  skeleton_combined_model_cooker.m_flags.m_flags = 8;
  skeleton_combined_model_cooker.m_next = 0;
  skeleton_combined_model_cooker.__vftable = (vostok::render::skeleton_combined_model_cook_vtbl *)&vostok::render::skeleton_combined_model_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&skeleton_combined_model_cooker);
}
