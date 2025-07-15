void __thiscall survarium::victory_item::on_culled_player_draw(survarium::victory_item *this)
{
  survarium::base_player *m_user; // esi
  vostok::render::scene_renderer *v3; // edi
  vostok::render::skeleton_model_instance *m_object; // ebx
  const vostok::math::float4x4 *v5; // eax
  const vostok::math::float4x4 *v6; // [esp-Ch] [ebp-18h]
  survarium::game_world **p_m_game_world; // [esp+4h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_skeleton_model.m_object->m_render_model.m_object->m_in_scene )
  {
    p_m_game_world = &this->m_game_world;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v8,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene);
    m_user = this->m_user;
    v3 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)(*p_m_game_world)->m_game->m_renderer);
    m_object = this->m_skeleton_model.m_object;
    m_user = (survarium::base_player *)((char *)m_user + 272);
    v6 = (const vostok::math::float4x4 *)((int (__thiscall *)(survarium::base_player *))m_user->log_string)(m_user);
    v5 = (const vostok::math::float4x4 *)((int (__thiscall *)(survarium::base_player *))m_user->log_string)(m_user);
    vostok::render::scene_renderer::update_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_render_model,
      v3,
      &v8,
      v5,
      v6);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
  }
}
