void __thiscall survarium::weapon::update_pfx_transform(survarium::weapon *this, survarium::weapon *thisa)
{
  vostok::render::light_props *m_weapon_fire_light_id; // eax
  unsigned __int8 i; // bl
  bool v4; // [esp+0h] [ebp-10h]
  bool v5; // [esp+4h] [ebp-Ch]

  if ( thisa->m_firing_light_added )
  {
    m_weapon_fire_light_id = (vostok::render::light_props *)thisa->m_weapon_fire_light_id;
    qmemcpy(&thisa->m_weapon_fire_light_props, &thisa->m_barrel_transform, 0x40u);
    vostok::render::scene_renderer::update_light(
      (vostok::render::scene_renderer *)thisa->m_game_scene->m_game->m_renderer,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)thisa->m_game_scene->m_game->m_renderer->m_scene,
      (unsigned int)&thisa->m_game_scene->m_render_scene,
      m_weapon_fire_light_id);
  }
  if ( thisa->m_fire_pfx_list )
  {
    for ( i = 0; i < thisa->m_fire_pfx_count; ++i )
      vostok::render::scene_renderer::update_particle_system_instance(
        (vostok::render::scene_renderer *)thisa->m_game_scene->m_game->m_renderer,
        &thisa->m_game_scene->m_render_scene,
        &thisa->m_fire_pfx_list[i],
        &thisa->m_barrel_transform,
        v4,
        v5);
  }
}
