vostok::particle::particle_event_on_play *__thiscall vostok::particle::particle_event::`scalar deleting destructor'(
        vostok::particle::particle_event_on_play *this,
        char a2)
{
  this->__vftable = (vostok::particle::particle_event_on_play_vtbl *)&vostok::particle::particle_action::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
