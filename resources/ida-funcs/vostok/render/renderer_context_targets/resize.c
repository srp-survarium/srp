void __userpurge vostok::render::renderer_context_targets::resize(
        vostok::render::renderer_context_targets *this@<ecx>,
        vostok::render::enum_render_target_index a2@<edi>,
        vostok::math::uint2 size,
        vostok::render::renderer_context_targets *force_resize)
{
  vostok::render::renderer_context_targets::create_targets(force_resize, a2, size, (unsigned int)force_resize);
}
