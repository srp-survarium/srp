void __usercall vostok::render::set_memory_allocator(
        vostok::render::grass_render_model *render_allocator@<eax>,
        vostok::memory::base_allocator *logic_allocator@<ecx>,
        vostok::memory::base_allocator *editor_allocator)
{
  vostok::render::g_allocator.m_object = render_allocator;
  vostok::render::logic::g_allocator = logic_allocator;
  vostok::render::editor::g_allocator = editor_allocator;
}
