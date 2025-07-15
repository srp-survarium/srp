void __thiscall vostok::particle::particle_emitter::set_target_action(
        vostok::particle::particle_emitter *this,
        vostok::particle::particle_action_random_velocity *target_act)
{
  this->m_target_action.pointer = target_act;
}
