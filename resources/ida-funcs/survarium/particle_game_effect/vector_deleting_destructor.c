survarium::particle_game_effect *__thiscall survarium::particle_game_effect::`vector deleting destructor'(
        survarium::particle_game_effect *this,
        char a2)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_particle_system);
  survarium::game_effect::~game_effect(&this->survarium::single_game_effect);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
