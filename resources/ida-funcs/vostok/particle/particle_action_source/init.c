void __thiscall vostok::particle::particle_action_source::init(
        vostok::particle::particle_action_source *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  float v4; // [esp+4h] [ebp-Ch] BYREF
  float v5; // [esp+8h] [ebp-8h]
  float v6; // [esp+Ch] [ebp-4h]

  vostok::particle::particle_domain_complex::generate(&this->m_domain, &this->m_domain, &v4);
  P->spawn_position.x = P->spawn_position.x + v4;
  P->spawn_position.y = P->spawn_position.y + v5;
  P->spawn_position.z = P->spawn_position.z + v6;
  P->position.x = v4 + P->position.x;
  P->position.y = P->position.y + v5;
  P->position.z = P->position.z + v6;
  P->old_position.x = P->old_position.x + v4;
  P->old_position.y = P->old_position.y + v5;
  P->old_position.z = P->old_position.z + v6;
}
