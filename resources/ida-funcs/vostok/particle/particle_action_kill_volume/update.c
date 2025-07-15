void __thiscall vostok::particle::particle_action_kill_volume::update(
        vostok::particle::particle_action_kill_volume *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v4; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  if ( this->m_kill_inside )
  {
    if ( vostok::particle::particle_domain_complex::inside(&this->m_domain, &P->position) )
    {
      P->lifetime = 1000.0;
      P->duration = 100.0;
    }
  }
  else if ( !vostok::particle::particle_domain_complex::inside(&this->m_domain, &P->position) )
  {
    P->lifetime = 1000.0;
    P->duration = 100.0;
  }
}
