vostok::particle::particle_action_data_type *__thiscall vostok::particle::particle_action_decal::`scalar deleting destructor'(
        vostok::particle::particle_action_data_type *this,
        char a2)
{
  this->__vftable = (vostok::particle::particle_action_data_type_vtbl *)&vostok::particle::particle_action_data_type::`vftable';
  this->__vftable = (vostok::particle::particle_action_data_type_vtbl *)&vostok::particle::particle_action::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
