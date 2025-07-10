vostok::render::stage_particles *__thiscall vostok::render::stage_particles::`scalar deleting destructor'(
        vostok::render::stage_particles *this,
        char a2)
{
  vostok::render::stage_particles::~stage_particles(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
