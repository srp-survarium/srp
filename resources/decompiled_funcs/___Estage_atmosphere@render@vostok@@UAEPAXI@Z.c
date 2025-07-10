vostok::render::stage_atmosphere *__thiscall vostok::render::stage_atmosphere::`vector deleting destructor'(
        vostok::render::stage_atmosphere *this,
        char a2)
{
  vostok::render::stage_atmosphere::~stage_atmosphere(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
