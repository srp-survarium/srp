void __userpurge vostok::engine::engine_world::initialize_render(
        vostok::engine::engine_world *this@<ecx>,
        int a2@<eax>,
        vostok::engine::engine_world *in_config,
        bool is_editor)
{
  vostok::render::logic::g_allocator = (vostok::memory::base_allocator *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 652) + 12))(*(_DWORD *)(a2 + 652));
  vostok::render::g_allocator.m_object = (vostok::render::grass_render_model *)(a2 + 544);
  vostok::render::editor::g_allocator = (vostok::memory::base_allocator *)(a2 + 588);
  vostok::engine::engine_world::create_render(
    in_config,
    (vostok::engine::engine_world *)a2,
    (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)in_config,
    is_editor);
}
