void __thiscall survarium::object_ambient_volume::insert(survarium::object_ambient_volume *this)
{
  float m_ambient_multiplier; // xmm0_4
  survarium::base_game_scene *m_game_scene; // ecx
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *p_m_render_scene; // edx
  vostok::render::game::renderer *m_renderer; // ecx
  vostok::render::scene_renderer *m_scene; // [esp-10h] [ebp-60h]
  const vostok::render::ambient_volume_properties *m_id; // [esp-8h] [ebp-58h]
  vostok::render::ambient_volume_properties properties; // [esp+8h] [ebp-48h] BYREF

  if ( this->m_valid )
  {
    m_ambient_multiplier = this->m_ambient_multiplier;
    qmemcpy(&properties, &this->m_transform, 0x40u);
    properties.enabled = this->m_enabled;
    m_game_scene = this->m_game_scene;
    m_id = (const vostok::render::ambient_volume_properties *)this->m_id;
    p_m_render_scene = &m_game_scene->m_render_scene;
    m_renderer = m_game_scene->m_game->m_renderer;
    m_scene = m_renderer->m_scene;
    properties.ambient_multiplier = m_ambient_multiplier;
    vostok::render::scene_renderer::update_ambient_volume(
      (vostok::render::scene_renderer *)m_renderer,
      m_scene,
      p_m_render_scene,
      m_id,
      &properties);
  }
}
