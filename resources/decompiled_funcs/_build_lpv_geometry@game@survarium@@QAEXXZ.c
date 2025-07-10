void __thiscall survarium::game::build_lpv_geometry(survarium::game *this)
{
  vostok::render::scene_renderer::build_lpv_geometry(
    (vostok::render::scene_renderer *)this->m_renderer,
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)this->m_renderer->m_scene);
}
