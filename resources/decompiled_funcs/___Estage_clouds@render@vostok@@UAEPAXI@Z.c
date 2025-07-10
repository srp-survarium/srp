vostok::render::stage_clouds *__thiscall vostok::render::stage_clouds::`vector deleting destructor'(
        vostok::render::stage_clouds *this,
        char a2)
{
  vostok::render::stage_clouds::~stage_clouds(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
