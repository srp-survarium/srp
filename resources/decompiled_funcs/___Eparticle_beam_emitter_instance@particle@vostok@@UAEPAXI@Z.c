vostok::particle::particle_beam_emitter_instance *__thiscall vostok::particle::particle_beam_emitter_instance::`vector deleting destructor'(
        vostok::particle::particle_beam_emitter_instance *this,
        char a2)
{
  vostok::particle::particle_beam_emitter_instance::~particle_beam_emitter_instance(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
