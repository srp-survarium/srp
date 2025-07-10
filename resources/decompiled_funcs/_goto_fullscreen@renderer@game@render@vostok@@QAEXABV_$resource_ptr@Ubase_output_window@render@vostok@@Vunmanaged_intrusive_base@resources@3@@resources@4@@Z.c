void __usercall vostok::render::game::renderer::goto_fullscreen(
        const vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> *output_window@<eax>,
        vostok::render::game::renderer *this)
{
  vostok::render::res_render_output::goto_fullscreen(
    (vostok::render::res_render_output *)output_window->m_object,
    output_window->m_object[42].m_parent_resources.m_lock);
}
