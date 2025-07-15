void __thiscall vostok::particle::particle_action_source::init(
        vostok::particle::particle_action_source *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v4; // eax
  vostok::math::float3 pos; // [esp+14h] [ebp-Ch] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  vostok::particle::particle_domain_complex::generate(&this->m_domain, &pos);
  vostok::math::float3_pod::operator+=(&pos, &P->spawn_position);
  vostok::math::float3_pod::operator+=(&pos, &P->position);
  vostok::math::float3_pod::operator+=(&pos, &P->old_position);
}
