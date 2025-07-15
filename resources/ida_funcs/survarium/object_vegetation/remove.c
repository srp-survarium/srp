void __thiscall survarium::object_vegetation::remove(survarium::object_vegetation *this)
{
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v2; // [esp-8h] [ebp-Ch] BYREF
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *p_m_render_scene; // [esp-4h] [ebp-8h]

  p_m_render_scene = &this->m_game_scene->m_render_scene;
  v2.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v2,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_grass);
  vostok::render::scene_renderer::reset_grass(
    (vostok::render::scene_renderer *)this->m_game_scene,
    this->m_game_scene->m_game->m_renderer->m_scene,
    v2.m_object,
    p_m_render_scene);
}
