void __thiscall vostok::particle::particle_action_gravity::update(
        vostok::particle::particle_action_gravity *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  P->gravity = (float)(this->m_force * time) + P->gravity;
}
