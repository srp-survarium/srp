void __thiscall survarium::grenade::remove_physics(survarium::grenade *this)
{
  if ( this->m_physics_world )
  {
    this->m_physics_world->unsubscribe_from_contact(
      this->m_physics_world,
      this->m_rigid_body,
      &this->m_collide_callback);
    vostok::render::scene_renderer::remove_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model.m_object->m_render_model,
      *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene);
  }
  survarium::grenade_core::remove_physics(this);
}
