void __thiscall survarium::victory_item::draw(
        survarium::victory_item *this,
        const vostok::math::float4x4 *transform,
        const vostok::math::float4x4 *shadow_transform,
        const vostok::math::float4x4 *const matrices,
        const vostok::math::float4x4 *const shadow_matrices,
        unsigned int matrices_count,
        survarium::hud_object_state *hud)
{
  survarium::hud_object_state *v7; // eax
  vostok::render::game::renderer *m_renderer; // esi

  v7 = hud;
  if ( hud )
  {
    hud->show_ammo_indicator = 0;
    v7->show_crosshair = 0;
  }
  if ( this->m_skeleton_model.m_object->m_render_model.m_object->m_in_scene )
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&hud,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene);
    m_renderer = this->m_game_world->m_game->m_renderer;
    vostok::render::scene_renderer::update_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_skeleton_model.m_object->m_render_model,
      *(vostok::render::scene_renderer **)((char *)&dword_200060 + (_DWORD)m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&hud,
      transform,
      shadow_transform);
    vostok::render::scene_renderer::update_skeleton(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_skeleton_model.m_object->m_render_model,
      *(vostok::memory::base_allocator **)((char *)&dword_200060 + (_DWORD)m_renderer),
      matrices,
      shadow_matrices,
      matrices_count);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&hud);
  }
}
