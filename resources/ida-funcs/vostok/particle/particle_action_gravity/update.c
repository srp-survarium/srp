void __thiscall vostok::particle::particle_action_gravity::update(
        vostok::particle::particle_action_gravity *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v4; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  P->gravity = (float)((float)(this->m_force / *(float *)&clear_value) * time) + P->gravity;
}
