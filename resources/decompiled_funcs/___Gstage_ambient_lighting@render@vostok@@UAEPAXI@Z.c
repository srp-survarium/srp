vostok::render::stage_ambient_lighting *__thiscall vostok::render::stage_ambient_lighting::`scalar deleting destructor'(
        vostok::render::stage_ambient_lighting *this,
        char a2)
{
  vostok::render::stage_ambient_lighting::~stage_ambient_lighting(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
