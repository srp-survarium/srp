void __thiscall vostok::render::shader_binary_source_cook::shader_binary_source_cook(
        vostok::render::shader_binary_source_cook *this)
{
  shader_binary_source_cooker.__vftable = (vostok::render::shader_binary_source_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  shader_binary_source_cooker.m_cook_users_count.m_count = 0;
  shader_binary_source_cooker.m_class_id = shader_binary_source_class;
  shader_binary_source_cooker.m_reuse_type = reuse_false;
  shader_binary_source_cooker.m_creation_thread_id = GetCurrentThreadId();
  shader_binary_source_cooker.m_allocate_thread_id = GetCurrentThreadId();
  shader_binary_source_cooker.m_flags.m_flags = 0;
  shader_binary_source_cooker.m_next = 0;
  shader_binary_source_cooker.__vftable = (vostok::render::shader_binary_source_cook_vtbl *)&stru_984D24.m_available_macros.m_buffer[12];
  shader_binary_source_cooker.m_tasks_type = vostok::tasks::create_new_task_type("compile_shader_task", 0);
  shader_binary_source_cooker.m_blob_creation_counter = 0;
}
