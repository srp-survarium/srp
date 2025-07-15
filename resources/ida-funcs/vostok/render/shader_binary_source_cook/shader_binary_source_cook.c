void __thiscall vostok::render::shader_binary_source_cook::shader_binary_source_cook(
        vostok::render::shader_binary_source_cook *this)
{
  vostok::tasks::task *v1; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp+0h] [ebp-4h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0xC,
    &shader_binary_source_cooker,
    reuse_true,
    0xFFFFFFFD,
    0,
    v2);
  shader_binary_source_cooker.__vftable = (vostok::render::shader_binary_source_cook_vtbl *)&vostok::render::shader_binary_source_cook::`vftable';
  vostok::tasks::task::task(v1, &shader_binary_source_cooker.m_parent_task.m_next_task_in_child_queue);
  shader_binary_source_cooker.m_tasks_type = vostok::tasks::create_new_task_type("compile_shader_task", 0);
  shader_binary_source_cooker.m_blob_creation_counter = 0;
}
