void __userpurge vostok::engine::engine_world::create_render(
        vostok::engine::engine_world *this@<ecx>,
        vostok::engine::engine_world *a2@<esi>,
        const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *in_config,
        bool is_editor)
{
  bool (__thiscall *command_line_editor)(vostok::engine_user::engine *); // edx
  vostok::memory::base_allocator *p_m_editor_allocator; // edi
  vostok::memory::base_allocator *v6; // eax

  command_line_editor = a2->command_line_editor;
  s_world_4 = a2;
  if ( command_line_editor(&a2->vostok::engine_user::engine) )
    p_m_editor_allocator = &a2->m_editor_allocator;
  else
    p_m_editor_allocator = 0;
  v6 = a2->m_engine_user_module_proxy->allocator(a2->m_engine_user_module_proxy);
  vostok::render::world::world((vostok::render::world *)&s_world_0, v6, p_m_editor_allocator, in_config, is_editor);
  _InterlockedExchange(&s_world_0.m_initialized, 1);
  a2->m_render_world = s_world_0.m_variable;
}
