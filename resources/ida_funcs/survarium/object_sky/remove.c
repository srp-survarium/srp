void __thiscall survarium::object_sky::remove(survarium::object_sky *this)
{
  survarium::base_game_scene *m_game_scene; // eax
  vostok::render::game::renderer *m_renderer; // ecx
  vostok::render::scene_renderer *m_scene; // [esp-Ch] [ebp-10h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v4; // [esp+0h] [ebp-4h] BYREF

  m_game_scene = this->m_game_scene;
  m_renderer = m_game_scene->m_game->m_renderer;
  m_scene = m_renderer->m_scene;
  v4.m_object = 0;
  vostok::render::scene_renderer::set_sky_material(
    (vostok::render::scene_renderer *)m_renderer,
    m_scene,
    &m_game_scene->m_render_scene,
    &v4);
}
