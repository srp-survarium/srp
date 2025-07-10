void __thiscall survarium::object_light::insert(survarium::object_light *this)
{
  vostok::render::scene_renderer::add_light(
    (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)this->m_game_scene->m_game->m_renderer->m_scene,
    (unsigned int)&this->m_game_scene->m_render_scene,
    (vostok::render::light_props *)this->m_light_id);
}
