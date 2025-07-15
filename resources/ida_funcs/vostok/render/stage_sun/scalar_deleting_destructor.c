vostok::render::stage_sun *__thiscall vostok::render::stage_sun::`scalar deleting destructor'(
        vostok::render::stage_sun *this,
        char a2)
{
  vostok::render::stage_sun::~stage_sun(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
