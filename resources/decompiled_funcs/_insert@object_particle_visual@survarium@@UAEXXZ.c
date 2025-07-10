void __thiscall survarium::object_particle_visual::insert(survarium::object_particle_visual *this)
{
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v2; // [esp-8h] [ebp-Ch] BYREF
  const vostok::math::float4x4 *p_m_transform; // [esp-4h] [ebp-8h]

  p_m_transform = &this->m_transform;
  v2.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v2,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_particle_system_instance_ptr);
  vostok::render::scene_renderer::play_particle_system(
    (vostok::render::scene_renderer *)&this->m_game_scene->m_render_scene,
    (int)this->m_game_scene->m_game->m_renderer->m_scene,
    &this->m_game_scene->m_render_scene,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v2.m_object,
    p_m_transform);
}
