vostok::render::render_particle_emitter_instance *__thiscall vostok::render::render_particle_emitter_instance::`scalar deleting destructor'(
        vostok::render::render_particle_emitter_instance *this,
        char a2)
{
  vostok::render::render_particle_emitter_instance::~render_particle_emitter_instance(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
