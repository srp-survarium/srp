void __thiscall survarium::game::unload(survarium::game *this, const char *__formal, bool a3)
{
  if ( this->m_game_world.m_game_project.m_object )
    survarium::game_world::unload(
      &this->m_game_world,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)&this->m_game_world);
}
