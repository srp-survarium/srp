void __thiscall vostok::render::engine::world::resize_render_output_window(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> *output_window,
        unsigned int width,
        vostok::render::renderer_context_targets *height,
        bool fullscreen)
{
  vostok::render::render_output_window::set_size(
    width,
    height,
    (vostok::render::render_output_window *)output_window->m_object,
    fullscreen,
    0);
}
