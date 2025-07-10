void __thiscall survarium::object_lpv_occluder::insert(survarium::object_lpv_occluder *this)
{
  vostok::render::scene_renderer::update_lpv_occluder(
    (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
    this->m_game_scene->m_game->m_renderer->m_scene,
    &this->m_game_scene->m_render_scene,
    (const vostok::math::float4x4 *)this->m_occluder_id,
    &this->m_transform);
}
